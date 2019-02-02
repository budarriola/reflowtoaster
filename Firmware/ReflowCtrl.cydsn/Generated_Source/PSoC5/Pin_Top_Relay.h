/*******************************************************************************
* File Name: Pin_Top_Relay.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_Pin_Top_Relay_H) /* Pins Pin_Top_Relay_H */
#define CY_PINS_Pin_Top_Relay_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Pin_Top_Relay_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Pin_Top_Relay__PORT == 15 && ((Pin_Top_Relay__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    Pin_Top_Relay_Write(uint8 value);
void    Pin_Top_Relay_SetDriveMode(uint8 mode);
uint8   Pin_Top_Relay_ReadDataReg(void);
uint8   Pin_Top_Relay_Read(void);
void    Pin_Top_Relay_SetInterruptMode(uint16 position, uint16 mode);
uint8   Pin_Top_Relay_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the Pin_Top_Relay_SetDriveMode() function.
     *  @{
     */
        #define Pin_Top_Relay_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define Pin_Top_Relay_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define Pin_Top_Relay_DM_RES_UP          PIN_DM_RES_UP
        #define Pin_Top_Relay_DM_RES_DWN         PIN_DM_RES_DWN
        #define Pin_Top_Relay_DM_OD_LO           PIN_DM_OD_LO
        #define Pin_Top_Relay_DM_OD_HI           PIN_DM_OD_HI
        #define Pin_Top_Relay_DM_STRONG          PIN_DM_STRONG
        #define Pin_Top_Relay_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define Pin_Top_Relay_MASK               Pin_Top_Relay__MASK
#define Pin_Top_Relay_SHIFT              Pin_Top_Relay__SHIFT
#define Pin_Top_Relay_WIDTH              1u

/* Interrupt constants */
#if defined(Pin_Top_Relay__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Pin_Top_Relay_SetInterruptMode() function.
     *  @{
     */
        #define Pin_Top_Relay_INTR_NONE      (uint16)(0x0000u)
        #define Pin_Top_Relay_INTR_RISING    (uint16)(0x0001u)
        #define Pin_Top_Relay_INTR_FALLING   (uint16)(0x0002u)
        #define Pin_Top_Relay_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define Pin_Top_Relay_INTR_MASK      (0x01u) 
#endif /* (Pin_Top_Relay__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Pin_Top_Relay_PS                     (* (reg8 *) Pin_Top_Relay__PS)
/* Data Register */
#define Pin_Top_Relay_DR                     (* (reg8 *) Pin_Top_Relay__DR)
/* Port Number */
#define Pin_Top_Relay_PRT_NUM                (* (reg8 *) Pin_Top_Relay__PRT) 
/* Connect to Analog Globals */                                                  
#define Pin_Top_Relay_AG                     (* (reg8 *) Pin_Top_Relay__AG)                       
/* Analog MUX bux enable */
#define Pin_Top_Relay_AMUX                   (* (reg8 *) Pin_Top_Relay__AMUX) 
/* Bidirectional Enable */                                                        
#define Pin_Top_Relay_BIE                    (* (reg8 *) Pin_Top_Relay__BIE)
/* Bit-mask for Aliased Register Access */
#define Pin_Top_Relay_BIT_MASK               (* (reg8 *) Pin_Top_Relay__BIT_MASK)
/* Bypass Enable */
#define Pin_Top_Relay_BYP                    (* (reg8 *) Pin_Top_Relay__BYP)
/* Port wide control signals */                                                   
#define Pin_Top_Relay_CTL                    (* (reg8 *) Pin_Top_Relay__CTL)
/* Drive Modes */
#define Pin_Top_Relay_DM0                    (* (reg8 *) Pin_Top_Relay__DM0) 
#define Pin_Top_Relay_DM1                    (* (reg8 *) Pin_Top_Relay__DM1)
#define Pin_Top_Relay_DM2                    (* (reg8 *) Pin_Top_Relay__DM2) 
/* Input Buffer Disable Override */
#define Pin_Top_Relay_INP_DIS                (* (reg8 *) Pin_Top_Relay__INP_DIS)
/* LCD Common or Segment Drive */
#define Pin_Top_Relay_LCD_COM_SEG            (* (reg8 *) Pin_Top_Relay__LCD_COM_SEG)
/* Enable Segment LCD */
#define Pin_Top_Relay_LCD_EN                 (* (reg8 *) Pin_Top_Relay__LCD_EN)
/* Slew Rate Control */
#define Pin_Top_Relay_SLW                    (* (reg8 *) Pin_Top_Relay__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Pin_Top_Relay_PRTDSI__CAPS_SEL       (* (reg8 *) Pin_Top_Relay__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Pin_Top_Relay_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Pin_Top_Relay__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Pin_Top_Relay_PRTDSI__OE_SEL0        (* (reg8 *) Pin_Top_Relay__PRTDSI__OE_SEL0) 
#define Pin_Top_Relay_PRTDSI__OE_SEL1        (* (reg8 *) Pin_Top_Relay__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Pin_Top_Relay_PRTDSI__OUT_SEL0       (* (reg8 *) Pin_Top_Relay__PRTDSI__OUT_SEL0) 
#define Pin_Top_Relay_PRTDSI__OUT_SEL1       (* (reg8 *) Pin_Top_Relay__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Pin_Top_Relay_PRTDSI__SYNC_OUT       (* (reg8 *) Pin_Top_Relay__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(Pin_Top_Relay__SIO_CFG)
    #define Pin_Top_Relay_SIO_HYST_EN        (* (reg8 *) Pin_Top_Relay__SIO_HYST_EN)
    #define Pin_Top_Relay_SIO_REG_HIFREQ     (* (reg8 *) Pin_Top_Relay__SIO_REG_HIFREQ)
    #define Pin_Top_Relay_SIO_CFG            (* (reg8 *) Pin_Top_Relay__SIO_CFG)
    #define Pin_Top_Relay_SIO_DIFF           (* (reg8 *) Pin_Top_Relay__SIO_DIFF)
#endif /* (Pin_Top_Relay__SIO_CFG) */

/* Interrupt Registers */
#if defined(Pin_Top_Relay__INTSTAT)
    #define Pin_Top_Relay_INTSTAT            (* (reg8 *) Pin_Top_Relay__INTSTAT)
    #define Pin_Top_Relay_SNAP               (* (reg8 *) Pin_Top_Relay__SNAP)
    
	#define Pin_Top_Relay_0_INTTYPE_REG 		(* (reg8 *) Pin_Top_Relay__0__INTTYPE)
#endif /* (Pin_Top_Relay__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Pin_Top_Relay_H */


/* [] END OF FILE */
