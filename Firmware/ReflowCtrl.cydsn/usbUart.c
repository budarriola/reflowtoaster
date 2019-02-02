/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/

#include "usbUart.h"
#include <stdio.h>
#include <string.h>
#include "circular_buffer.h"

#define USBFS_DEVICE    (0u)

#define C_BUFFER_SIZE (1024u)

//dont send any data untill the usb uart has receved atleast one chariter
uint8 bootLock = 1;

//this string is to be used by other files to work with sprintf
char temp_string[128] = {'\0'};

volatile uint8 fromHostLock = 0;
cbuf_handle_t fromHost_Buffer_cbuf;
// "data from the uart host will automaticly be placed here"
volatile uint8 fromHost_Buffer[C_BUFFER_SIZE]={0};

//this buffer is only for direct usb transfers, not to be used by the user
//temporary buffer to hold data before it is moved into usb
volatile uint8 usb_fromHost_Buffer[USB_BUFFER_SIZE]={0};


volatile uint8 toHostLock = 0;
cbuf_handle_t toHost_Buffer_cbuf;
// "place data to send to the host in this buffer"
volatile uint8 toHost_Buffer[C_BUFFER_SIZE]={0};

//this buffer is only for direct usb transfers, not to be used by the user
//temporary buffer to hold data before it is moved into usb
volatile uint8 usb_toHost_Buffer[USB_BUFFER_SIZE]={0};


//returns 1 if data was read, otherwise the buffer is known to be empty
uint8 getByteFromHost(uint8* byte){
    if (circular_buf_get(fromHost_Buffer_cbuf,byte)==0){
        
        return 1;
    }else{
        return 0;   
    }
}




void usbUart_Start(){
    /* Start USBFS operation with 5-V operation. */
    USB_Start(USBFS_DEVICE, USB_5V_OPERATION);
    
    //setup circular buffers
    fromHost_Buffer_cbuf = circular_buf_init((uint8*)fromHost_Buffer, C_BUFFER_SIZE);
    toHost_Buffer_cbuf = circular_buf_init((uint8*)toHost_Buffer, C_BUFFER_SIZE);
    
}

uint8_t usb_Ready(){
    if (bootLock == 0){
        
        return 1;
    }
    return 0;
}

void serviceUsb(){
    uint16 cnt,i;
    static uint8 sendZeroLenPacket = 0;
    
     /* Host can send double SET_INTERFACE request. */
        if (0u != USB_IsConfigurationChanged())
        {
            /* Initialize IN endpoints when device is configured. */
            if (0u != USB_GetConfiguration())
            {
                /* Enumeration is done, enable OUT endpoint to receive data 
                 * from host. */
                USB_CDC_Init();
                
            }
        }
 
        
        
        
               /* Service USB CDC when device is configured. */
        if (0u != USB_GetConfiguration())
        {
            /* Check for input data from host. */
            if (0u != USB_DataIsReady())
            {
                if (fromHostLock == 0)
                {
                    fromHostLock = 1;
                    bootLock = 0;
                    /* Read received data and re-enable OUT endpoint. */
                    //put data into a temp buffer then move it into a circular buffer
                    cnt = USB_GetAll((uint8*)usb_fromHost_Buffer);
                    for (i=0;i<cnt;i++){
                        circular_buf_put(fromHost_Buffer_cbuf,usb_fromHost_Buffer[i]);
                    }
                    fromHostLock = 0;
                }
                else{
                    fromHostLock=0x10;
                }
            }
            
            
            if (sendZeroLenPacket){
                if (1u == USB_CDCIsReady()){
                    /* Send zero-length packet to PC. */
                    USB_PutData(NULL, 0u);
                    sendZeroLenPacket = 0;
                }
                
            }else{
                if (!bootLock)
                {
                                                    
                    /* Wait until component is ready to send data to host and there is data to send. */
                    if (circular_buf_size(toHost_Buffer_cbuf) && (1u == USB_CDCIsReady()))
                    {
                        if (toHostLock == 0)
                        {
                            toHostLock = 1;
                            /* Send data back to host. */
                            cnt = circular_buf_size(toHost_Buffer_cbuf);
                            if (cnt >=USB_BUFFER_SIZE)
                            {
                                cnt = USB_BUFFER_SIZE-1;
                            }
                            for (i=0;i<cnt;i++){
                                circular_buf_get(toHost_Buffer_cbuf,(uint8*)(&usb_toHost_Buffer[i]));
                            }
                            
                            USB_PutData((uint8*)usb_toHost_Buffer, cnt);
                            
                            /* If the last sent packet is exactly the maximum packet 
                            *  size, it is followed by a zero-length packet to assure
                            *  that the end of the segment is properly identified by 
                            *  the terminal.
                            */
                            if (USB_BUFFER_SIZE == cnt)
                            {
                                sendZeroLenPacket = 1;
                            }
                            toHostLock = 0;
                        }
                    }
                }
            }   //if (sendZeroLenPacket)
        }
}


//returns 0 on fail and returns a count on pass
uint8 writeStringToHost(char* string){
    uint8 cnt = 0;
    uint16 i;
    cnt = strlen(string);
    if (cnt >0){
        if (toHostLock == 0)
        {
            
            toHostLock = 1;
            if(circular_buf_capacity(toHost_Buffer_cbuf)-circular_buf_size(toHost_Buffer_cbuf) > cnt ){
                //if there is space in the c buffer
                for (i=0;i<cnt;i++){
                    circular_buf_put(toHost_Buffer_cbuf,(uint8)string[i]);
                }
                
            }

            
            toHostLock = 0;
            
            return cnt;
        }
    }
    
    return 0;
    
}



//returns 0 on fail and returns a count on pass
uint8 writeByteToHost(uint8 byte){
    uint8 cnt = 0;
    if (cnt >0){
        if (toHostLock == 0)
        {
            
            toHostLock = 1;
            if(circular_buf_capacity(toHost_Buffer_cbuf)-circular_buf_size(toHost_Buffer_cbuf) > 1 ){
                //if there is space in the c buffer
                circular_buf_put(toHost_Buffer_cbuf,byte);
                         
            }

            toHostLock = 0;
            return 1;
        }
    }
    
    return 0;
    
}










/* [] END OF FILE */
