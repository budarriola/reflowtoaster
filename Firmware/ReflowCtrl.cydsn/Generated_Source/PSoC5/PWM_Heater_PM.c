/*******************************************************************************
* File Name: PWM_Heater_PM.c
* Version 3.30
*
* Description:
*  This file provides the power management source code to API for the
*  PWM.
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "PWM_Heater.h"

static PWM_Heater_backupStruct PWM_Heater_backup;


/*******************************************************************************
* Function Name: PWM_Heater_SaveConfig
********************************************************************************
*
* Summary:
*  Saves the current user configuration of the component.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  PWM_Heater_backup:  Variables of this global structure are modified to
*  store the values of non retention configuration registers when Sleep() API is
*  called.
*
*******************************************************************************/
void PWM_Heater_SaveConfig(void) 
{

    #if(!PWM_Heater_UsingFixedFunction)
        #if(!PWM_Heater_PWMModeIsCenterAligned)
            PWM_Heater_backup.PWMPeriod = PWM_Heater_ReadPeriod();
        #endif /* (!PWM_Heater_PWMModeIsCenterAligned) */
        PWM_Heater_backup.PWMUdb = PWM_Heater_ReadCounter();
        #if (PWM_Heater_UseStatus)
            PWM_Heater_backup.InterruptMaskValue = PWM_Heater_STATUS_MASK;
        #endif /* (PWM_Heater_UseStatus) */

        #if(PWM_Heater_DeadBandMode == PWM_Heater__B_PWM__DBM_256_CLOCKS || \
            PWM_Heater_DeadBandMode == PWM_Heater__B_PWM__DBM_2_4_CLOCKS)
            PWM_Heater_backup.PWMdeadBandValue = PWM_Heater_ReadDeadTime();
        #endif /*  deadband count is either 2-4 clocks or 256 clocks */

        #if(PWM_Heater_KillModeMinTime)
             PWM_Heater_backup.PWMKillCounterPeriod = PWM_Heater_ReadKillTime();
        #endif /* (PWM_Heater_KillModeMinTime) */

        #if(PWM_Heater_UseControl)
            PWM_Heater_backup.PWMControlRegister = PWM_Heater_ReadControlRegister();
        #endif /* (PWM_Heater_UseControl) */
    #endif  /* (!PWM_Heater_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: PWM_Heater_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the current user configuration of the component.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  PWM_Heater_backup:  Variables of this global structure are used to
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void PWM_Heater_RestoreConfig(void) 
{
        #if(!PWM_Heater_UsingFixedFunction)
            #if(!PWM_Heater_PWMModeIsCenterAligned)
                PWM_Heater_WritePeriod(PWM_Heater_backup.PWMPeriod);
            #endif /* (!PWM_Heater_PWMModeIsCenterAligned) */

            PWM_Heater_WriteCounter(PWM_Heater_backup.PWMUdb);

            #if (PWM_Heater_UseStatus)
                PWM_Heater_STATUS_MASK = PWM_Heater_backup.InterruptMaskValue;
            #endif /* (PWM_Heater_UseStatus) */

            #if(PWM_Heater_DeadBandMode == PWM_Heater__B_PWM__DBM_256_CLOCKS || \
                PWM_Heater_DeadBandMode == PWM_Heater__B_PWM__DBM_2_4_CLOCKS)
                PWM_Heater_WriteDeadTime(PWM_Heater_backup.PWMdeadBandValue);
            #endif /* deadband count is either 2-4 clocks or 256 clocks */

            #if(PWM_Heater_KillModeMinTime)
                PWM_Heater_WriteKillTime(PWM_Heater_backup.PWMKillCounterPeriod);
            #endif /* (PWM_Heater_KillModeMinTime) */

            #if(PWM_Heater_UseControl)
                PWM_Heater_WriteControlRegister(PWM_Heater_backup.PWMControlRegister);
            #endif /* (PWM_Heater_UseControl) */
        #endif  /* (!PWM_Heater_UsingFixedFunction) */
    }


/*******************************************************************************
* Function Name: PWM_Heater_Sleep
********************************************************************************
*
* Summary:
*  Disables block's operation and saves the user configuration. Should be called
*  just prior to entering sleep.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  PWM_Heater_backup.PWMEnableState:  Is modified depending on the enable
*  state of the block before entering sleep mode.
*
*******************************************************************************/
void PWM_Heater_Sleep(void) 
{
    #if(PWM_Heater_UseControl)
        if(PWM_Heater_CTRL_ENABLE == (PWM_Heater_CONTROL & PWM_Heater_CTRL_ENABLE))
        {
            /*Component is enabled */
            PWM_Heater_backup.PWMEnableState = 1u;
        }
        else
        {
            /* Component is disabled */
            PWM_Heater_backup.PWMEnableState = 0u;
        }
    #endif /* (PWM_Heater_UseControl) */

    /* Stop component */
    PWM_Heater_Stop();

    /* Save registers configuration */
    PWM_Heater_SaveConfig();
}


/*******************************************************************************
* Function Name: PWM_Heater_Wakeup
********************************************************************************
*
* Summary:
*  Restores and enables the user configuration. Should be called just after
*  awaking from sleep.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  PWM_Heater_backup.pwmEnable:  Is used to restore the enable state of
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void PWM_Heater_Wakeup(void) 
{
     /* Restore registers values */
    PWM_Heater_RestoreConfig();

    if(PWM_Heater_backup.PWMEnableState != 0u)
    {
        /* Enable component's operation */
        PWM_Heater_Enable();
    } /* Do nothing if component's block was disabled before */

}


/* [] END OF FILE */
