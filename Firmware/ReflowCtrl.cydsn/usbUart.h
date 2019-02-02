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
#ifndef USBUART_H
#define USBUART_H
    #include "project.h"
    
    #define USB_BUFFER_SIZE (64u)
    
    
    #if defined (__GNUC__)
        /* Add an explicit reference to the floating point printf library */
        /* to allow usage of the floating point conversion specifiers. */
        /* This is not linked in by default with the newlib-nano library. */
        asm (".global _printf_float");
    #endif
    
    
    
    //this string is to be used by other files to work with sprintf
    extern char temp_string[128];


    
    void usbUart_Start();
    void serviceUsb();
    
    //this returns 1 when the device has receved at least one chariter
    uint8_t usb_Ready();
    
    //returns 0 on fail and returns a count on pass
    uint8 writeStringToHost(char* string);
    //returns 0 on fail and returns a 1 on pass
    uint8 writeByteToHost(uint8 byte);
    
    //returns 1 if data was read, otherwise the buffer is known to be empty
    uint8 getByteFromHost(uint8* byte);
    
#endif
/* [] END OF FILE */
