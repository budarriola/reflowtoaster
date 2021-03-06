/*******************************************************************************
* File Name: cyfittergnu.inc
* 
* PSoC Creator  4.2
*
* Description:
* 
* This file is automatically generated by PSoC Creator.
*
********************************************************************************
* Copyright (c) 2007-2018 Cypress Semiconductor.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
********************************************************************************/

.ifndef INCLUDED_CYFITTERGNU_INC
.set INCLUDED_CYFITTERGNU_INC, 1
.include "cydevicegnu.inc"
.include "cydevicegnu_trm.inc"

/* ADC */
.set ADC_Bypass_P32__0__INTTYPE, CYREG_PICU3_INTTYPE2
.set ADC_Bypass_P32__0__MASK, 0x04
.set ADC_Bypass_P32__0__PC, CYREG_PRT3_PC2
.set ADC_Bypass_P32__0__PORT, 3
.set ADC_Bypass_P32__0__SHIFT, 2
.set ADC_Bypass_P32__AG, CYREG_PRT3_AG
.set ADC_Bypass_P32__AMUX, CYREG_PRT3_AMUX
.set ADC_Bypass_P32__BIE, CYREG_PRT3_BIE
.set ADC_Bypass_P32__BIT_MASK, CYREG_PRT3_BIT_MASK
.set ADC_Bypass_P32__BYP, CYREG_PRT3_BYP
.set ADC_Bypass_P32__CTL, CYREG_PRT3_CTL
.set ADC_Bypass_P32__DM0, CYREG_PRT3_DM0
.set ADC_Bypass_P32__DM1, CYREG_PRT3_DM1
.set ADC_Bypass_P32__DM2, CYREG_PRT3_DM2
.set ADC_Bypass_P32__DR, CYREG_PRT3_DR
.set ADC_Bypass_P32__INP_DIS, CYREG_PRT3_INP_DIS
.set ADC_Bypass_P32__INTTYPE_BASE, CYDEV_PICU_INTTYPE_PICU3_BASE
.set ADC_Bypass_P32__LCD_COM_SEG, CYREG_PRT3_LCD_COM_SEG
.set ADC_Bypass_P32__LCD_EN, CYREG_PRT3_LCD_EN
.set ADC_Bypass_P32__MASK, 0x04
.set ADC_Bypass_P32__PORT, 3
.set ADC_Bypass_P32__PRT, CYREG_PRT3_PRT
.set ADC_Bypass_P32__PRTDSI__CAPS_SEL, CYREG_PRT3_CAPS_SEL
.set ADC_Bypass_P32__PRTDSI__DBL_SYNC_IN, CYREG_PRT3_DBL_SYNC_IN
.set ADC_Bypass_P32__PRTDSI__OE_SEL0, CYREG_PRT3_OE_SEL0
.set ADC_Bypass_P32__PRTDSI__OE_SEL1, CYREG_PRT3_OE_SEL1
.set ADC_Bypass_P32__PRTDSI__OUT_SEL0, CYREG_PRT3_OUT_SEL0
.set ADC_Bypass_P32__PRTDSI__OUT_SEL1, CYREG_PRT3_OUT_SEL1
.set ADC_Bypass_P32__PRTDSI__SYNC_OUT, CYREG_PRT3_SYNC_OUT
.set ADC_Bypass_P32__PS, CYREG_PRT3_PS
.set ADC_Bypass_P32__SHIFT, 2
.set ADC_Bypass_P32__SLW, CYREG_PRT3_SLW
.set ADC_DEC__COHER, CYREG_DEC_COHER
.set ADC_DEC__CR, CYREG_DEC_CR
.set ADC_DEC__DR1, CYREG_DEC_DR1
.set ADC_DEC__DR2, CYREG_DEC_DR2
.set ADC_DEC__DR2H, CYREG_DEC_DR2H
.set ADC_DEC__GCOR, CYREG_DEC_GCOR
.set ADC_DEC__GCORH, CYREG_DEC_GCORH
.set ADC_DEC__GVAL, CYREG_DEC_GVAL
.set ADC_DEC__OCOR, CYREG_DEC_OCOR
.set ADC_DEC__OCORH, CYREG_DEC_OCORH
.set ADC_DEC__OCORM, CYREG_DEC_OCORM
.set ADC_DEC__OUTSAMP, CYREG_DEC_OUTSAMP
.set ADC_DEC__OUTSAMPH, CYREG_DEC_OUTSAMPH
.set ADC_DEC__OUTSAMPM, CYREG_DEC_OUTSAMPM
.set ADC_DEC__OUTSAMPS, CYREG_DEC_OUTSAMPS
.set ADC_DEC__PM_ACT_CFG, CYREG_PM_ACT_CFG10
.set ADC_DEC__PM_ACT_MSK, 0x01
.set ADC_DEC__PM_STBY_CFG, CYREG_PM_STBY_CFG10
.set ADC_DEC__PM_STBY_MSK, 0x01
.set ADC_DEC__SHIFT1, CYREG_DEC_SHIFT1
.set ADC_DEC__SHIFT2, CYREG_DEC_SHIFT2
.set ADC_DEC__SR, CYREG_DEC_SR
.set ADC_DEC__TRIM__M1, CYREG_FLSHID_CUST_TABLES_DEC_M1
.set ADC_DEC__TRIM__M2, CYREG_FLSHID_CUST_TABLES_DEC_M2
.set ADC_DEC__TRIM__M3, CYREG_FLSHID_CUST_TABLES_DEC_M3
.set ADC_DEC__TRIM__M4, CYREG_FLSHID_CUST_TABLES_DEC_M4
.set ADC_DEC__TRIM__M5, CYREG_FLSHID_CUST_TABLES_DEC_M5
.set ADC_DEC__TRIM__M6, CYREG_FLSHID_CUST_TABLES_DEC_M6
.set ADC_DEC__TRIM__M7, CYREG_FLSHID_CUST_TABLES_DEC_M7
.set ADC_DEC__TRIM__M8, CYREG_FLSHID_CUST_TABLES_DEC_M8
.set ADC_DSM__BUF0, CYREG_DSM0_BUF0
.set ADC_DSM__BUF1, CYREG_DSM0_BUF1
.set ADC_DSM__BUF2, CYREG_DSM0_BUF2
.set ADC_DSM__BUF3, CYREG_DSM0_BUF3
.set ADC_DSM__CLK, CYREG_DSM0_CLK
.set ADC_DSM__CR0, CYREG_DSM0_CR0
.set ADC_DSM__CR1, CYREG_DSM0_CR1
.set ADC_DSM__CR10, CYREG_DSM0_CR10
.set ADC_DSM__CR11, CYREG_DSM0_CR11
.set ADC_DSM__CR12, CYREG_DSM0_CR12
.set ADC_DSM__CR13, CYREG_DSM0_CR13
.set ADC_DSM__CR14, CYREG_DSM0_CR14
.set ADC_DSM__CR15, CYREG_DSM0_CR15
.set ADC_DSM__CR16, CYREG_DSM0_CR16
.set ADC_DSM__CR17, CYREG_DSM0_CR17
.set ADC_DSM__CR2, CYREG_DSM0_CR2
.set ADC_DSM__CR3, CYREG_DSM0_CR3
.set ADC_DSM__CR4, CYREG_DSM0_CR4
.set ADC_DSM__CR5, CYREG_DSM0_CR5
.set ADC_DSM__CR6, CYREG_DSM0_CR6
.set ADC_DSM__CR7, CYREG_DSM0_CR7
.set ADC_DSM__CR8, CYREG_DSM0_CR8
.set ADC_DSM__CR9, CYREG_DSM0_CR9
.set ADC_DSM__DEM0, CYREG_DSM0_DEM0
.set ADC_DSM__DEM1, CYREG_DSM0_DEM1
.set ADC_DSM__MISC, CYREG_DSM0_MISC
.set ADC_DSM__OUT0, CYREG_DSM0_OUT0
.set ADC_DSM__OUT1, CYREG_DSM0_OUT1
.set ADC_DSM__REF0, CYREG_DSM0_REF0
.set ADC_DSM__REF1, CYREG_DSM0_REF1
.set ADC_DSM__REF2, CYREG_DSM0_REF2
.set ADC_DSM__REF3, CYREG_DSM0_REF3
.set ADC_DSM__RSVD1, CYREG_DSM0_RSVD1
.set ADC_DSM__SW0, CYREG_DSM0_SW0
.set ADC_DSM__SW2, CYREG_DSM0_SW2
.set ADC_DSM__SW3, CYREG_DSM0_SW3
.set ADC_DSM__SW4, CYREG_DSM0_SW4
.set ADC_DSM__SW6, CYREG_DSM0_SW6
.set ADC_DSM__TR0, CYREG_NPUMP_DSM_TR0
.set ADC_DSM__TST0, CYREG_DSM0_TST0
.set ADC_DSM__TST1, CYREG_DSM0_TST1
.set ADC_Ext_CP_Clk__CFG0, CYREG_CLKDIST_DCFG0_CFG0
.set ADC_Ext_CP_Clk__CFG1, CYREG_CLKDIST_DCFG0_CFG1
.set ADC_Ext_CP_Clk__CFG2, CYREG_CLKDIST_DCFG0_CFG2
.set ADC_Ext_CP_Clk__CFG2_SRC_SEL_MASK, 0x07
.set ADC_Ext_CP_Clk__INDEX, 0x00
.set ADC_Ext_CP_Clk__PM_ACT_CFG, CYREG_PM_ACT_CFG2
.set ADC_Ext_CP_Clk__PM_ACT_MSK, 0x01
.set ADC_Ext_CP_Clk__PM_STBY_CFG, CYREG_PM_STBY_CFG2
.set ADC_Ext_CP_Clk__PM_STBY_MSK, 0x01
.set ADC_IRQ__INTC_CLR_EN_REG, CYREG_NVIC_CLRENA0
.set ADC_IRQ__INTC_CLR_PD_REG, CYREG_NVIC_CLRPEND0
.set ADC_IRQ__INTC_MASK, 0x20000000
.set ADC_IRQ__INTC_NUMBER, 29
.set ADC_IRQ__INTC_PRIOR_NUM, 7
.set ADC_IRQ__INTC_PRIOR_REG, CYREG_NVIC_PRI_29
.set ADC_IRQ__INTC_SET_EN_REG, CYREG_NVIC_SETENA0
.set ADC_IRQ__INTC_SET_PD_REG, CYREG_NVIC_SETPEND0
.set ADC_theACLK__CFG0, CYREG_CLKDIST_ACFG0_CFG0
.set ADC_theACLK__CFG1, CYREG_CLKDIST_ACFG0_CFG1
.set ADC_theACLK__CFG2, CYREG_CLKDIST_ACFG0_CFG2
.set ADC_theACLK__CFG2_SRC_SEL_MASK, 0x07
.set ADC_theACLK__CFG3, CYREG_CLKDIST_ACFG0_CFG3
.set ADC_theACLK__CFG3_PHASE_DLY_MASK, 0x0F
.set ADC_theACLK__INDEX, 0x00
.set ADC_theACLK__PM_ACT_CFG, CYREG_PM_ACT_CFG1
.set ADC_theACLK__PM_ACT_MSK, 0x01
.set ADC_theACLK__PM_STBY_CFG, CYREG_PM_STBY_CFG1
.set ADC_theACLK__PM_STBY_MSK, 0x01

/* USB */
.set USB_arb_int__INTC_CLR_EN_REG, CYREG_NVIC_CLRENA0
.set USB_arb_int__INTC_CLR_PD_REG, CYREG_NVIC_CLRPEND0
.set USB_arb_int__INTC_MASK, 0x400000
.set USB_arb_int__INTC_NUMBER, 22
.set USB_arb_int__INTC_PRIOR_NUM, 7
.set USB_arb_int__INTC_PRIOR_REG, CYREG_NVIC_PRI_22
.set USB_arb_int__INTC_SET_EN_REG, CYREG_NVIC_SETENA0
.set USB_arb_int__INTC_SET_PD_REG, CYREG_NVIC_SETPEND0
.set USB_bus_reset__INTC_CLR_EN_REG, CYREG_NVIC_CLRENA0
.set USB_bus_reset__INTC_CLR_PD_REG, CYREG_NVIC_CLRPEND0
.set USB_bus_reset__INTC_MASK, 0x800000
.set USB_bus_reset__INTC_NUMBER, 23
.set USB_bus_reset__INTC_PRIOR_NUM, 7
.set USB_bus_reset__INTC_PRIOR_REG, CYREG_NVIC_PRI_23
.set USB_bus_reset__INTC_SET_EN_REG, CYREG_NVIC_SETENA0
.set USB_bus_reset__INTC_SET_PD_REG, CYREG_NVIC_SETPEND0
.set USB_Dm__0__INTTYPE, CYREG_PICU15_INTTYPE7
.set USB_Dm__0__MASK, 0x80
.set USB_Dm__0__PC, CYREG_IO_PC_PRT15_7_6_PC1
.set USB_Dm__0__PORT, 15
.set USB_Dm__0__SHIFT, 7
.set USB_Dm__AG, CYREG_PRT15_AG
.set USB_Dm__AMUX, CYREG_PRT15_AMUX
.set USB_Dm__BIE, CYREG_PRT15_BIE
.set USB_Dm__BIT_MASK, CYREG_PRT15_BIT_MASK
.set USB_Dm__BYP, CYREG_PRT15_BYP
.set USB_Dm__CTL, CYREG_PRT15_CTL
.set USB_Dm__DM0, CYREG_PRT15_DM0
.set USB_Dm__DM1, CYREG_PRT15_DM1
.set USB_Dm__DM2, CYREG_PRT15_DM2
.set USB_Dm__DR, CYREG_PRT15_DR
.set USB_Dm__INP_DIS, CYREG_PRT15_INP_DIS
.set USB_Dm__INTTYPE_BASE, CYDEV_PICU_INTTYPE_PICU15_BASE
.set USB_Dm__LCD_COM_SEG, CYREG_PRT15_LCD_COM_SEG
.set USB_Dm__LCD_EN, CYREG_PRT15_LCD_EN
.set USB_Dm__MASK, 0x80
.set USB_Dm__PORT, 15
.set USB_Dm__PRT, CYREG_PRT15_PRT
.set USB_Dm__PRTDSI__CAPS_SEL, CYREG_PRT15_CAPS_SEL
.set USB_Dm__PRTDSI__DBL_SYNC_IN, CYREG_PRT15_DBL_SYNC_IN
.set USB_Dm__PRTDSI__OE_SEL0, CYREG_PRT15_OE_SEL0
.set USB_Dm__PRTDSI__OE_SEL1, CYREG_PRT15_OE_SEL1
.set USB_Dm__PRTDSI__OUT_SEL0, CYREG_PRT15_OUT_SEL0
.set USB_Dm__PRTDSI__OUT_SEL1, CYREG_PRT15_OUT_SEL1
.set USB_Dm__PRTDSI__SYNC_OUT, CYREG_PRT15_SYNC_OUT
.set USB_Dm__PS, CYREG_PRT15_PS
.set USB_Dm__SHIFT, 7
.set USB_Dm__SLW, CYREG_PRT15_SLW
.set USB_Dp__0__INTTYPE, CYREG_PICU15_INTTYPE6
.set USB_Dp__0__MASK, 0x40
.set USB_Dp__0__PC, CYREG_IO_PC_PRT15_7_6_PC0
.set USB_Dp__0__PORT, 15
.set USB_Dp__0__SHIFT, 6
.set USB_Dp__AG, CYREG_PRT15_AG
.set USB_Dp__AMUX, CYREG_PRT15_AMUX
.set USB_Dp__BIE, CYREG_PRT15_BIE
.set USB_Dp__BIT_MASK, CYREG_PRT15_BIT_MASK
.set USB_Dp__BYP, CYREG_PRT15_BYP
.set USB_Dp__CTL, CYREG_PRT15_CTL
.set USB_Dp__DM0, CYREG_PRT15_DM0
.set USB_Dp__DM1, CYREG_PRT15_DM1
.set USB_Dp__DM2, CYREG_PRT15_DM2
.set USB_Dp__DR, CYREG_PRT15_DR
.set USB_Dp__INP_DIS, CYREG_PRT15_INP_DIS
.set USB_Dp__INTSTAT, CYREG_PICU15_INTSTAT
.set USB_Dp__INTTYPE_BASE, CYDEV_PICU_INTTYPE_PICU15_BASE
.set USB_Dp__LCD_COM_SEG, CYREG_PRT15_LCD_COM_SEG
.set USB_Dp__LCD_EN, CYREG_PRT15_LCD_EN
.set USB_Dp__MASK, 0x40
.set USB_Dp__PORT, 15
.set USB_Dp__PRT, CYREG_PRT15_PRT
.set USB_Dp__PRTDSI__CAPS_SEL, CYREG_PRT15_CAPS_SEL
.set USB_Dp__PRTDSI__DBL_SYNC_IN, CYREG_PRT15_DBL_SYNC_IN
.set USB_Dp__PRTDSI__OE_SEL0, CYREG_PRT15_OE_SEL0
.set USB_Dp__PRTDSI__OE_SEL1, CYREG_PRT15_OE_SEL1
.set USB_Dp__PRTDSI__OUT_SEL0, CYREG_PRT15_OUT_SEL0
.set USB_Dp__PRTDSI__OUT_SEL1, CYREG_PRT15_OUT_SEL1
.set USB_Dp__PRTDSI__SYNC_OUT, CYREG_PRT15_SYNC_OUT
.set USB_Dp__PS, CYREG_PRT15_PS
.set USB_Dp__SHIFT, 6
.set USB_Dp__SLW, CYREG_PRT15_SLW
.set USB_Dp__SNAP, CYREG_PICU_15_SNAP_15
.set USB_dp_int__INTC_CLR_EN_REG, CYREG_NVIC_CLRENA0
.set USB_dp_int__INTC_CLR_PD_REG, CYREG_NVIC_CLRPEND0
.set USB_dp_int__INTC_MASK, 0x1000
.set USB_dp_int__INTC_NUMBER, 12
.set USB_dp_int__INTC_PRIOR_NUM, 7
.set USB_dp_int__INTC_PRIOR_REG, CYREG_NVIC_PRI_12
.set USB_dp_int__INTC_SET_EN_REG, CYREG_NVIC_SETENA0
.set USB_dp_int__INTC_SET_PD_REG, CYREG_NVIC_SETPEND0
.set USB_ep_0__INTC_CLR_EN_REG, CYREG_NVIC_CLRENA0
.set USB_ep_0__INTC_CLR_PD_REG, CYREG_NVIC_CLRPEND0
.set USB_ep_0__INTC_MASK, 0x1000000
.set USB_ep_0__INTC_NUMBER, 24
.set USB_ep_0__INTC_PRIOR_NUM, 7
.set USB_ep_0__INTC_PRIOR_REG, CYREG_NVIC_PRI_24
.set USB_ep_0__INTC_SET_EN_REG, CYREG_NVIC_SETENA0
.set USB_ep_0__INTC_SET_PD_REG, CYREG_NVIC_SETPEND0
.set USB_ep_1__INTC_CLR_EN_REG, CYREG_NVIC_CLRENA0
.set USB_ep_1__INTC_CLR_PD_REG, CYREG_NVIC_CLRPEND0
.set USB_ep_1__INTC_MASK, 0x01
.set USB_ep_1__INTC_NUMBER, 0
.set USB_ep_1__INTC_PRIOR_NUM, 7
.set USB_ep_1__INTC_PRIOR_REG, CYREG_NVIC_PRI_0
.set USB_ep_1__INTC_SET_EN_REG, CYREG_NVIC_SETENA0
.set USB_ep_1__INTC_SET_PD_REG, CYREG_NVIC_SETPEND0
.set USB_ep_2__INTC_CLR_EN_REG, CYREG_NVIC_CLRENA0
.set USB_ep_2__INTC_CLR_PD_REG, CYREG_NVIC_CLRPEND0
.set USB_ep_2__INTC_MASK, 0x02
.set USB_ep_2__INTC_NUMBER, 1
.set USB_ep_2__INTC_PRIOR_NUM, 7
.set USB_ep_2__INTC_PRIOR_REG, CYREG_NVIC_PRI_1
.set USB_ep_2__INTC_SET_EN_REG, CYREG_NVIC_SETENA0
.set USB_ep_2__INTC_SET_PD_REG, CYREG_NVIC_SETPEND0
.set USB_ep_3__INTC_CLR_EN_REG, CYREG_NVIC_CLRENA0
.set USB_ep_3__INTC_CLR_PD_REG, CYREG_NVIC_CLRPEND0
.set USB_ep_3__INTC_MASK, 0x04
.set USB_ep_3__INTC_NUMBER, 2
.set USB_ep_3__INTC_PRIOR_NUM, 7
.set USB_ep_3__INTC_PRIOR_REG, CYREG_NVIC_PRI_2
.set USB_ep_3__INTC_SET_EN_REG, CYREG_NVIC_SETENA0
.set USB_ep_3__INTC_SET_PD_REG, CYREG_NVIC_SETPEND0
.set USB_ord_int__INTC_CLR_EN_REG, CYREG_NVIC_CLRENA0
.set USB_ord_int__INTC_CLR_PD_REG, CYREG_NVIC_CLRPEND0
.set USB_ord_int__INTC_MASK, 0x2000000
.set USB_ord_int__INTC_NUMBER, 25
.set USB_ord_int__INTC_PRIOR_NUM, 7
.set USB_ord_int__INTC_PRIOR_REG, CYREG_NVIC_PRI_25
.set USB_ord_int__INTC_SET_EN_REG, CYREG_NVIC_SETENA0
.set USB_ord_int__INTC_SET_PD_REG, CYREG_NVIC_SETPEND0
.set USB_sof_int__INTC_CLR_EN_REG, CYREG_NVIC_CLRENA0
.set USB_sof_int__INTC_CLR_PD_REG, CYREG_NVIC_CLRPEND0
.set USB_sof_int__INTC_MASK, 0x200000
.set USB_sof_int__INTC_NUMBER, 21
.set USB_sof_int__INTC_PRIOR_NUM, 7
.set USB_sof_int__INTC_PRIOR_REG, CYREG_NVIC_PRI_21
.set USB_sof_int__INTC_SET_EN_REG, CYREG_NVIC_SETENA0
.set USB_sof_int__INTC_SET_PD_REG, CYREG_NVIC_SETPEND0
.set USB_USB__ARB_CFG, CYREG_USB_ARB_CFG
.set USB_USB__ARB_EP1_CFG, CYREG_USB_ARB_EP1_CFG
.set USB_USB__ARB_EP1_INT_EN, CYREG_USB_ARB_EP1_INT_EN
.set USB_USB__ARB_EP1_SR, CYREG_USB_ARB_EP1_SR
.set USB_USB__ARB_EP2_CFG, CYREG_USB_ARB_EP2_CFG
.set USB_USB__ARB_EP2_INT_EN, CYREG_USB_ARB_EP2_INT_EN
.set USB_USB__ARB_EP2_SR, CYREG_USB_ARB_EP2_SR
.set USB_USB__ARB_EP3_CFG, CYREG_USB_ARB_EP3_CFG
.set USB_USB__ARB_EP3_INT_EN, CYREG_USB_ARB_EP3_INT_EN
.set USB_USB__ARB_EP3_SR, CYREG_USB_ARB_EP3_SR
.set USB_USB__ARB_EP4_CFG, CYREG_USB_ARB_EP4_CFG
.set USB_USB__ARB_EP4_INT_EN, CYREG_USB_ARB_EP4_INT_EN
.set USB_USB__ARB_EP4_SR, CYREG_USB_ARB_EP4_SR
.set USB_USB__ARB_EP5_CFG, CYREG_USB_ARB_EP5_CFG
.set USB_USB__ARB_EP5_INT_EN, CYREG_USB_ARB_EP5_INT_EN
.set USB_USB__ARB_EP5_SR, CYREG_USB_ARB_EP5_SR
.set USB_USB__ARB_EP6_CFG, CYREG_USB_ARB_EP6_CFG
.set USB_USB__ARB_EP6_INT_EN, CYREG_USB_ARB_EP6_INT_EN
.set USB_USB__ARB_EP6_SR, CYREG_USB_ARB_EP6_SR
.set USB_USB__ARB_EP7_CFG, CYREG_USB_ARB_EP7_CFG
.set USB_USB__ARB_EP7_INT_EN, CYREG_USB_ARB_EP7_INT_EN
.set USB_USB__ARB_EP7_SR, CYREG_USB_ARB_EP7_SR
.set USB_USB__ARB_EP8_CFG, CYREG_USB_ARB_EP8_CFG
.set USB_USB__ARB_EP8_INT_EN, CYREG_USB_ARB_EP8_INT_EN
.set USB_USB__ARB_EP8_SR, CYREG_USB_ARB_EP8_SR
.set USB_USB__ARB_INT_EN, CYREG_USB_ARB_INT_EN
.set USB_USB__ARB_INT_SR, CYREG_USB_ARB_INT_SR
.set USB_USB__ARB_RW1_DR, CYREG_USB_ARB_RW1_DR
.set USB_USB__ARB_RW1_RA, CYREG_USB_ARB_RW1_RA
.set USB_USB__ARB_RW1_RA_MSB, CYREG_USB_ARB_RW1_RA_MSB
.set USB_USB__ARB_RW1_WA, CYREG_USB_ARB_RW1_WA
.set USB_USB__ARB_RW1_WA_MSB, CYREG_USB_ARB_RW1_WA_MSB
.set USB_USB__ARB_RW2_DR, CYREG_USB_ARB_RW2_DR
.set USB_USB__ARB_RW2_RA, CYREG_USB_ARB_RW2_RA
.set USB_USB__ARB_RW2_RA_MSB, CYREG_USB_ARB_RW2_RA_MSB
.set USB_USB__ARB_RW2_WA, CYREG_USB_ARB_RW2_WA
.set USB_USB__ARB_RW2_WA_MSB, CYREG_USB_ARB_RW2_WA_MSB
.set USB_USB__ARB_RW3_DR, CYREG_USB_ARB_RW3_DR
.set USB_USB__ARB_RW3_RA, CYREG_USB_ARB_RW3_RA
.set USB_USB__ARB_RW3_RA_MSB, CYREG_USB_ARB_RW3_RA_MSB
.set USB_USB__ARB_RW3_WA, CYREG_USB_ARB_RW3_WA
.set USB_USB__ARB_RW3_WA_MSB, CYREG_USB_ARB_RW3_WA_MSB
.set USB_USB__ARB_RW4_DR, CYREG_USB_ARB_RW4_DR
.set USB_USB__ARB_RW4_RA, CYREG_USB_ARB_RW4_RA
.set USB_USB__ARB_RW4_RA_MSB, CYREG_USB_ARB_RW4_RA_MSB
.set USB_USB__ARB_RW4_WA, CYREG_USB_ARB_RW4_WA
.set USB_USB__ARB_RW4_WA_MSB, CYREG_USB_ARB_RW4_WA_MSB
.set USB_USB__ARB_RW5_DR, CYREG_USB_ARB_RW5_DR
.set USB_USB__ARB_RW5_RA, CYREG_USB_ARB_RW5_RA
.set USB_USB__ARB_RW5_RA_MSB, CYREG_USB_ARB_RW5_RA_MSB
.set USB_USB__ARB_RW5_WA, CYREG_USB_ARB_RW5_WA
.set USB_USB__ARB_RW5_WA_MSB, CYREG_USB_ARB_RW5_WA_MSB
.set USB_USB__ARB_RW6_DR, CYREG_USB_ARB_RW6_DR
.set USB_USB__ARB_RW6_RA, CYREG_USB_ARB_RW6_RA
.set USB_USB__ARB_RW6_RA_MSB, CYREG_USB_ARB_RW6_RA_MSB
.set USB_USB__ARB_RW6_WA, CYREG_USB_ARB_RW6_WA
.set USB_USB__ARB_RW6_WA_MSB, CYREG_USB_ARB_RW6_WA_MSB
.set USB_USB__ARB_RW7_DR, CYREG_USB_ARB_RW7_DR
.set USB_USB__ARB_RW7_RA, CYREG_USB_ARB_RW7_RA
.set USB_USB__ARB_RW7_RA_MSB, CYREG_USB_ARB_RW7_RA_MSB
.set USB_USB__ARB_RW7_WA, CYREG_USB_ARB_RW7_WA
.set USB_USB__ARB_RW7_WA_MSB, CYREG_USB_ARB_RW7_WA_MSB
.set USB_USB__ARB_RW8_DR, CYREG_USB_ARB_RW8_DR
.set USB_USB__ARB_RW8_RA, CYREG_USB_ARB_RW8_RA
.set USB_USB__ARB_RW8_RA_MSB, CYREG_USB_ARB_RW8_RA_MSB
.set USB_USB__ARB_RW8_WA, CYREG_USB_ARB_RW8_WA
.set USB_USB__ARB_RW8_WA_MSB, CYREG_USB_ARB_RW8_WA_MSB
.set USB_USB__BUF_SIZE, CYREG_USB_BUF_SIZE
.set USB_USB__BUS_RST_CNT, CYREG_USB_BUS_RST_CNT
.set USB_USB__CR0, CYREG_USB_CR0
.set USB_USB__CR1, CYREG_USB_CR1
.set USB_USB__CWA, CYREG_USB_CWA
.set USB_USB__CWA_MSB, CYREG_USB_CWA_MSB
.set USB_USB__DMA_THRES, CYREG_USB_DMA_THRES
.set USB_USB__DMA_THRES_MSB, CYREG_USB_DMA_THRES_MSB
.set USB_USB__DYN_RECONFIG, CYREG_USB_DYN_RECONFIG
.set USB_USB__EP_ACTIVE, CYREG_USB_EP_ACTIVE
.set USB_USB__EP_TYPE, CYREG_USB_EP_TYPE
.set USB_USB__EP0_CNT, CYREG_USB_EP0_CNT
.set USB_USB__EP0_CR, CYREG_USB_EP0_CR
.set USB_USB__EP0_DR0, CYREG_USB_EP0_DR0
.set USB_USB__EP0_DR1, CYREG_USB_EP0_DR1
.set USB_USB__EP0_DR2, CYREG_USB_EP0_DR2
.set USB_USB__EP0_DR3, CYREG_USB_EP0_DR3
.set USB_USB__EP0_DR4, CYREG_USB_EP0_DR4
.set USB_USB__EP0_DR5, CYREG_USB_EP0_DR5
.set USB_USB__EP0_DR6, CYREG_USB_EP0_DR6
.set USB_USB__EP0_DR7, CYREG_USB_EP0_DR7
.set USB_USB__MEM_DATA, CYREG_USB_MEM_DATA_MBASE
.set USB_USB__PM_ACT_CFG, CYREG_PM_ACT_CFG5
.set USB_USB__PM_ACT_MSK, 0x01
.set USB_USB__PM_STBY_CFG, CYREG_PM_STBY_CFG5
.set USB_USB__PM_STBY_MSK, 0x01
.set USB_USB__SIE_EP_INT_EN, CYREG_USB_SIE_EP_INT_EN
.set USB_USB__SIE_EP_INT_SR, CYREG_USB_SIE_EP_INT_SR
.set USB_USB__SIE_EP1_CNT0, CYREG_USB_SIE_EP1_CNT0
.set USB_USB__SIE_EP1_CNT1, CYREG_USB_SIE_EP1_CNT1
.set USB_USB__SIE_EP1_CR0, CYREG_USB_SIE_EP1_CR0
.set USB_USB__SIE_EP2_CNT0, CYREG_USB_SIE_EP2_CNT0
.set USB_USB__SIE_EP2_CNT1, CYREG_USB_SIE_EP2_CNT1
.set USB_USB__SIE_EP2_CR0, CYREG_USB_SIE_EP2_CR0
.set USB_USB__SIE_EP3_CNT0, CYREG_USB_SIE_EP3_CNT0
.set USB_USB__SIE_EP3_CNT1, CYREG_USB_SIE_EP3_CNT1
.set USB_USB__SIE_EP3_CR0, CYREG_USB_SIE_EP3_CR0
.set USB_USB__SIE_EP4_CNT0, CYREG_USB_SIE_EP4_CNT0
.set USB_USB__SIE_EP4_CNT1, CYREG_USB_SIE_EP4_CNT1
.set USB_USB__SIE_EP4_CR0, CYREG_USB_SIE_EP4_CR0
.set USB_USB__SIE_EP5_CNT0, CYREG_USB_SIE_EP5_CNT0
.set USB_USB__SIE_EP5_CNT1, CYREG_USB_SIE_EP5_CNT1
.set USB_USB__SIE_EP5_CR0, CYREG_USB_SIE_EP5_CR0
.set USB_USB__SIE_EP6_CNT0, CYREG_USB_SIE_EP6_CNT0
.set USB_USB__SIE_EP6_CNT1, CYREG_USB_SIE_EP6_CNT1
.set USB_USB__SIE_EP6_CR0, CYREG_USB_SIE_EP6_CR0
.set USB_USB__SIE_EP7_CNT0, CYREG_USB_SIE_EP7_CNT0
.set USB_USB__SIE_EP7_CNT1, CYREG_USB_SIE_EP7_CNT1
.set USB_USB__SIE_EP7_CR0, CYREG_USB_SIE_EP7_CR0
.set USB_USB__SIE_EP8_CNT0, CYREG_USB_SIE_EP8_CNT0
.set USB_USB__SIE_EP8_CNT1, CYREG_USB_SIE_EP8_CNT1
.set USB_USB__SIE_EP8_CR0, CYREG_USB_SIE_EP8_CR0
.set USB_USB__SOF0, CYREG_USB_SOF0
.set USB_USB__SOF1, CYREG_USB_SOF1
.set USB_USB__USB_CLK_EN, CYREG_USB_USB_CLK_EN
.set USB_USB__USBIO_CR0, CYREG_USB_USBIO_CR0
.set USB_USB__USBIO_CR1, CYREG_USB_USBIO_CR1

/* Clock_2 */
.set Clock_2__CFG0, CYREG_CLKDIST_DCFG1_CFG0
.set Clock_2__CFG1, CYREG_CLKDIST_DCFG1_CFG1
.set Clock_2__CFG2, CYREG_CLKDIST_DCFG1_CFG2
.set Clock_2__CFG2_SRC_SEL_MASK, 0x07
.set Clock_2__INDEX, 0x01
.set Clock_2__PM_ACT_CFG, CYREG_PM_ACT_CFG2
.set Clock_2__PM_ACT_MSK, 0x02
.set Clock_2__PM_STBY_CFG, CYREG_PM_STBY_CFG2
.set Clock_2__PM_STBY_MSK, 0x02

/* Opamp_1 */
.set Opamp_1_ABuf__CR, CYREG_OPAMP3_CR
.set Opamp_1_ABuf__MX, CYREG_OPAMP3_MX
.set Opamp_1_ABuf__NPUMP_OPAMP_TR0, CYREG_NPUMP_OPAMP_TR0
.set Opamp_1_ABuf__PM_ACT_CFG, CYREG_PM_ACT_CFG4
.set Opamp_1_ABuf__PM_ACT_MSK, 0x08
.set Opamp_1_ABuf__PM_STBY_CFG, CYREG_PM_STBY_CFG4
.set Opamp_1_ABuf__PM_STBY_MSK, 0x08
.set Opamp_1_ABuf__RSVD, CYREG_OPAMP3_RSVD
.set Opamp_1_ABuf__SW, CYREG_OPAMP3_SW
.set Opamp_1_ABuf__TR0, CYREG_OPAMP3_TR0
.set Opamp_1_ABuf__TR1, CYREG_OPAMP3_TR1

/* Pin_Gnd */
.set Pin_Gnd__0__INTTYPE, CYREG_PICU3_INTTYPE0
.set Pin_Gnd__0__MASK, 0x01
.set Pin_Gnd__0__PC, CYREG_PRT3_PC0
.set Pin_Gnd__0__PORT, 3
.set Pin_Gnd__0__SHIFT, 0
.set Pin_Gnd__AG, CYREG_PRT3_AG
.set Pin_Gnd__AMUX, CYREG_PRT3_AMUX
.set Pin_Gnd__BIE, CYREG_PRT3_BIE
.set Pin_Gnd__BIT_MASK, CYREG_PRT3_BIT_MASK
.set Pin_Gnd__BYP, CYREG_PRT3_BYP
.set Pin_Gnd__CTL, CYREG_PRT3_CTL
.set Pin_Gnd__DM0, CYREG_PRT3_DM0
.set Pin_Gnd__DM1, CYREG_PRT3_DM1
.set Pin_Gnd__DM2, CYREG_PRT3_DM2
.set Pin_Gnd__DR, CYREG_PRT3_DR
.set Pin_Gnd__INP_DIS, CYREG_PRT3_INP_DIS
.set Pin_Gnd__INTTYPE_BASE, CYDEV_PICU_INTTYPE_PICU3_BASE
.set Pin_Gnd__LCD_COM_SEG, CYREG_PRT3_LCD_COM_SEG
.set Pin_Gnd__LCD_EN, CYREG_PRT3_LCD_EN
.set Pin_Gnd__MASK, 0x01
.set Pin_Gnd__PORT, 3
.set Pin_Gnd__PRT, CYREG_PRT3_PRT
.set Pin_Gnd__PRTDSI__CAPS_SEL, CYREG_PRT3_CAPS_SEL
.set Pin_Gnd__PRTDSI__DBL_SYNC_IN, CYREG_PRT3_DBL_SYNC_IN
.set Pin_Gnd__PRTDSI__OE_SEL0, CYREG_PRT3_OE_SEL0
.set Pin_Gnd__PRTDSI__OE_SEL1, CYREG_PRT3_OE_SEL1
.set Pin_Gnd__PRTDSI__OUT_SEL0, CYREG_PRT3_OUT_SEL0
.set Pin_Gnd__PRTDSI__OUT_SEL1, CYREG_PRT3_OUT_SEL1
.set Pin_Gnd__PRTDSI__SYNC_OUT, CYREG_PRT3_SYNC_OUT
.set Pin_Gnd__PS, CYREG_PRT3_PS
.set Pin_Gnd__SHIFT, 0
.set Pin_Gnd__SLW, CYREG_PRT3_SLW

/* isr_eoc */
.set isr_eoc__INTC_CLR_EN_REG, CYREG_NVIC_CLRENA0
.set isr_eoc__INTC_CLR_PD_REG, CYREG_NVIC_CLRPEND0
.set isr_eoc__INTC_MASK, 0x10
.set isr_eoc__INTC_NUMBER, 4
.set isr_eoc__INTC_PRIOR_NUM, 7
.set isr_eoc__INTC_PRIOR_REG, CYREG_NVIC_PRI_4
.set isr_eoc__INTC_SET_EN_REG, CYREG_NVIC_SETENA0
.set isr_eoc__INTC_SET_PD_REG, CYREG_NVIC_SETPEND0

/* Pin_Vreff */
.set Pin_Vreff__0__INTTYPE, CYREG_PICU3_INTTYPE3
.set Pin_Vreff__0__MASK, 0x08
.set Pin_Vreff__0__PC, CYREG_PRT3_PC3
.set Pin_Vreff__0__PORT, 3
.set Pin_Vreff__0__SHIFT, 3
.set Pin_Vreff__AG, CYREG_PRT3_AG
.set Pin_Vreff__AMUX, CYREG_PRT3_AMUX
.set Pin_Vreff__BIE, CYREG_PRT3_BIE
.set Pin_Vreff__BIT_MASK, CYREG_PRT3_BIT_MASK
.set Pin_Vreff__BYP, CYREG_PRT3_BYP
.set Pin_Vreff__CTL, CYREG_PRT3_CTL
.set Pin_Vreff__DM0, CYREG_PRT3_DM0
.set Pin_Vreff__DM1, CYREG_PRT3_DM1
.set Pin_Vreff__DM2, CYREG_PRT3_DM2
.set Pin_Vreff__DR, CYREG_PRT3_DR
.set Pin_Vreff__INP_DIS, CYREG_PRT3_INP_DIS
.set Pin_Vreff__INTTYPE_BASE, CYDEV_PICU_INTTYPE_PICU3_BASE
.set Pin_Vreff__LCD_COM_SEG, CYREG_PRT3_LCD_COM_SEG
.set Pin_Vreff__LCD_EN, CYREG_PRT3_LCD_EN
.set Pin_Vreff__MASK, 0x08
.set Pin_Vreff__PORT, 3
.set Pin_Vreff__PRT, CYREG_PRT3_PRT
.set Pin_Vreff__PRTDSI__CAPS_SEL, CYREG_PRT3_CAPS_SEL
.set Pin_Vreff__PRTDSI__DBL_SYNC_IN, CYREG_PRT3_DBL_SYNC_IN
.set Pin_Vreff__PRTDSI__OE_SEL0, CYREG_PRT3_OE_SEL0
.set Pin_Vreff__PRTDSI__OE_SEL1, CYREG_PRT3_OE_SEL1
.set Pin_Vreff__PRTDSI__OUT_SEL0, CYREG_PRT3_OUT_SEL0
.set Pin_Vreff__PRTDSI__OUT_SEL1, CYREG_PRT3_OUT_SEL1
.set Pin_Vreff__PRTDSI__SYNC_OUT, CYREG_PRT3_SYNC_OUT
.set Pin_Vreff__PS, CYREG_PRT3_PS
.set Pin_Vreff__SHIFT, 3
.set Pin_Vreff__SLW, CYREG_PRT3_SLW

/* isr_500ms */
.set isr_500ms__INTC_CLR_EN_REG, CYREG_NVIC_CLRENA0
.set isr_500ms__INTC_CLR_PD_REG, CYREG_NVIC_CLRPEND0
.set isr_500ms__INTC_MASK, 0x08
.set isr_500ms__INTC_NUMBER, 3
.set isr_500ms__INTC_PRIOR_NUM, 7
.set isr_500ms__INTC_PRIOR_REG, CYREG_NVIC_PRI_3
.set isr_500ms__INTC_SET_EN_REG, CYREG_NVIC_SETENA0
.set isr_500ms__INTC_SET_PD_REG, CYREG_NVIC_SETPEND0

/* isr_reset */
.set isr_reset__INTC_CLR_EN_REG, CYREG_NVIC_CLRENA0
.set isr_reset__INTC_CLR_PD_REG, CYREG_NVIC_CLRPEND0
.set isr_reset__INTC_MASK, 0x20
.set isr_reset__INTC_NUMBER, 5
.set isr_reset__INTC_PRIOR_NUM, 7
.set isr_reset__INTC_PRIOR_REG, CYREG_NVIC_PRI_5
.set isr_reset__INTC_SET_EN_REG, CYREG_NVIC_SETENA0
.set isr_reset__INTC_SET_PD_REG, CYREG_NVIC_SETPEND0

/* PWM_Heater */
.set PWM_Heater_PWMHW__CAP0, CYREG_TMR0_CAP0
.set PWM_Heater_PWMHW__CAP1, CYREG_TMR0_CAP1
.set PWM_Heater_PWMHW__CFG0, CYREG_TMR0_CFG0
.set PWM_Heater_PWMHW__CFG1, CYREG_TMR0_CFG1
.set PWM_Heater_PWMHW__CFG2, CYREG_TMR0_CFG2
.set PWM_Heater_PWMHW__CNT_CMP0, CYREG_TMR0_CNT_CMP0
.set PWM_Heater_PWMHW__CNT_CMP1, CYREG_TMR0_CNT_CMP1
.set PWM_Heater_PWMHW__PER0, CYREG_TMR0_PER0
.set PWM_Heater_PWMHW__PER1, CYREG_TMR0_PER1
.set PWM_Heater_PWMHW__PM_ACT_CFG, CYREG_PM_ACT_CFG3
.set PWM_Heater_PWMHW__PM_ACT_MSK, 0x01
.set PWM_Heater_PWMHW__PM_STBY_CFG, CYREG_PM_STBY_CFG3
.set PWM_Heater_PWMHW__PM_STBY_MSK, 0x01
.set PWM_Heater_PWMHW__RT0, CYREG_TMR0_RT0
.set PWM_Heater_PWMHW__RT1, CYREG_TMR0_RT1
.set PWM_Heater_PWMHW__SR0, CYREG_TMR0_SR0

/* Pin_Therm_1 */
.set Pin_Therm_1__0__INTTYPE, CYREG_PICU1_INTTYPE7
.set Pin_Therm_1__0__MASK, 0x80
.set Pin_Therm_1__0__PC, CYREG_PRT1_PC7
.set Pin_Therm_1__0__PORT, 1
.set Pin_Therm_1__0__SHIFT, 7
.set Pin_Therm_1__AG, CYREG_PRT1_AG
.set Pin_Therm_1__AMUX, CYREG_PRT1_AMUX
.set Pin_Therm_1__BIE, CYREG_PRT1_BIE
.set Pin_Therm_1__BIT_MASK, CYREG_PRT1_BIT_MASK
.set Pin_Therm_1__BYP, CYREG_PRT1_BYP
.set Pin_Therm_1__CTL, CYREG_PRT1_CTL
.set Pin_Therm_1__DM0, CYREG_PRT1_DM0
.set Pin_Therm_1__DM1, CYREG_PRT1_DM1
.set Pin_Therm_1__DM2, CYREG_PRT1_DM2
.set Pin_Therm_1__DR, CYREG_PRT1_DR
.set Pin_Therm_1__INP_DIS, CYREG_PRT1_INP_DIS
.set Pin_Therm_1__INTTYPE_BASE, CYDEV_PICU_INTTYPE_PICU1_BASE
.set Pin_Therm_1__LCD_COM_SEG, CYREG_PRT1_LCD_COM_SEG
.set Pin_Therm_1__LCD_EN, CYREG_PRT1_LCD_EN
.set Pin_Therm_1__MASK, 0x80
.set Pin_Therm_1__PORT, 1
.set Pin_Therm_1__PRT, CYREG_PRT1_PRT
.set Pin_Therm_1__PRTDSI__CAPS_SEL, CYREG_PRT1_CAPS_SEL
.set Pin_Therm_1__PRTDSI__DBL_SYNC_IN, CYREG_PRT1_DBL_SYNC_IN
.set Pin_Therm_1__PRTDSI__OE_SEL0, CYREG_PRT1_OE_SEL0
.set Pin_Therm_1__PRTDSI__OE_SEL1, CYREG_PRT1_OE_SEL1
.set Pin_Therm_1__PRTDSI__OUT_SEL0, CYREG_PRT1_OUT_SEL0
.set Pin_Therm_1__PRTDSI__OUT_SEL1, CYREG_PRT1_OUT_SEL1
.set Pin_Therm_1__PRTDSI__SYNC_OUT, CYREG_PRT1_SYNC_OUT
.set Pin_Therm_1__PS, CYREG_PRT1_PS
.set Pin_Therm_1__SHIFT, 7
.set Pin_Therm_1__SLW, CYREG_PRT1_SLW

/* Pin_Therm_2 */
.set Pin_Therm_2__0__INTTYPE, CYREG_PICU0_INTTYPE3
.set Pin_Therm_2__0__MASK, 0x08
.set Pin_Therm_2__0__PC, CYREG_PRT0_PC3
.set Pin_Therm_2__0__PORT, 0
.set Pin_Therm_2__0__SHIFT, 3
.set Pin_Therm_2__AG, CYREG_PRT0_AG
.set Pin_Therm_2__AMUX, CYREG_PRT0_AMUX
.set Pin_Therm_2__BIE, CYREG_PRT0_BIE
.set Pin_Therm_2__BIT_MASK, CYREG_PRT0_BIT_MASK
.set Pin_Therm_2__BYP, CYREG_PRT0_BYP
.set Pin_Therm_2__CTL, CYREG_PRT0_CTL
.set Pin_Therm_2__DM0, CYREG_PRT0_DM0
.set Pin_Therm_2__DM1, CYREG_PRT0_DM1
.set Pin_Therm_2__DM2, CYREG_PRT0_DM2
.set Pin_Therm_2__DR, CYREG_PRT0_DR
.set Pin_Therm_2__INP_DIS, CYREG_PRT0_INP_DIS
.set Pin_Therm_2__INTTYPE_BASE, CYDEV_PICU_INTTYPE_PICU0_BASE
.set Pin_Therm_2__LCD_COM_SEG, CYREG_PRT0_LCD_COM_SEG
.set Pin_Therm_2__LCD_EN, CYREG_PRT0_LCD_EN
.set Pin_Therm_2__MASK, 0x08
.set Pin_Therm_2__PORT, 0
.set Pin_Therm_2__PRT, CYREG_PRT0_PRT
.set Pin_Therm_2__PRTDSI__CAPS_SEL, CYREG_PRT0_CAPS_SEL
.set Pin_Therm_2__PRTDSI__DBL_SYNC_IN, CYREG_PRT0_DBL_SYNC_IN
.set Pin_Therm_2__PRTDSI__OE_SEL0, CYREG_PRT0_OE_SEL0
.set Pin_Therm_2__PRTDSI__OE_SEL1, CYREG_PRT0_OE_SEL1
.set Pin_Therm_2__PRTDSI__OUT_SEL0, CYREG_PRT0_OUT_SEL0
.set Pin_Therm_2__PRTDSI__OUT_SEL1, CYREG_PRT0_OUT_SEL1
.set Pin_Therm_2__PRTDSI__SYNC_OUT, CYREG_PRT0_SYNC_OUT
.set Pin_Therm_2__PS, CYREG_PRT0_PS
.set Pin_Therm_2__SHIFT, 3
.set Pin_Therm_2__SLW, CYREG_PRT0_SLW

/* Pin_button1 */
.set Pin_button1__0__INTTYPE, CYREG_PICU2_INTTYPE2
.set Pin_button1__0__MASK, 0x04
.set Pin_button1__0__PC, CYREG_PRT2_PC2
.set Pin_button1__0__PORT, 2
.set Pin_button1__0__SHIFT, 2
.set Pin_button1__AG, CYREG_PRT2_AG
.set Pin_button1__AMUX, CYREG_PRT2_AMUX
.set Pin_button1__BIE, CYREG_PRT2_BIE
.set Pin_button1__BIT_MASK, CYREG_PRT2_BIT_MASK
.set Pin_button1__BYP, CYREG_PRT2_BYP
.set Pin_button1__CTL, CYREG_PRT2_CTL
.set Pin_button1__DM0, CYREG_PRT2_DM0
.set Pin_button1__DM1, CYREG_PRT2_DM1
.set Pin_button1__DM2, CYREG_PRT2_DM2
.set Pin_button1__DR, CYREG_PRT2_DR
.set Pin_button1__INP_DIS, CYREG_PRT2_INP_DIS
.set Pin_button1__INTTYPE_BASE, CYDEV_PICU_INTTYPE_PICU2_BASE
.set Pin_button1__LCD_COM_SEG, CYREG_PRT2_LCD_COM_SEG
.set Pin_button1__LCD_EN, CYREG_PRT2_LCD_EN
.set Pin_button1__MASK, 0x04
.set Pin_button1__PORT, 2
.set Pin_button1__PRT, CYREG_PRT2_PRT
.set Pin_button1__PRTDSI__CAPS_SEL, CYREG_PRT2_CAPS_SEL
.set Pin_button1__PRTDSI__DBL_SYNC_IN, CYREG_PRT2_DBL_SYNC_IN
.set Pin_button1__PRTDSI__OE_SEL0, CYREG_PRT2_OE_SEL0
.set Pin_button1__PRTDSI__OE_SEL1, CYREG_PRT2_OE_SEL1
.set Pin_button1__PRTDSI__OUT_SEL0, CYREG_PRT2_OUT_SEL0
.set Pin_button1__PRTDSI__OUT_SEL1, CYREG_PRT2_OUT_SEL1
.set Pin_button1__PRTDSI__SYNC_OUT, CYREG_PRT2_SYNC_OUT
.set Pin_button1__PS, CYREG_PRT2_PS
.set Pin_button1__SHIFT, 2
.set Pin_button1__SLW, CYREG_PRT2_SLW

/* Pin_Top_Relay */
.set Pin_Top_Relay__0__INTTYPE, CYREG_PICU12_INTTYPE1
.set Pin_Top_Relay__0__MASK, 0x02
.set Pin_Top_Relay__0__PC, CYREG_PRT12_PC1
.set Pin_Top_Relay__0__PORT, 12
.set Pin_Top_Relay__0__SHIFT, 1
.set Pin_Top_Relay__AG, CYREG_PRT12_AG
.set Pin_Top_Relay__BIE, CYREG_PRT12_BIE
.set Pin_Top_Relay__BIT_MASK, CYREG_PRT12_BIT_MASK
.set Pin_Top_Relay__BYP, CYREG_PRT12_BYP
.set Pin_Top_Relay__DM0, CYREG_PRT12_DM0
.set Pin_Top_Relay__DM1, CYREG_PRT12_DM1
.set Pin_Top_Relay__DM2, CYREG_PRT12_DM2
.set Pin_Top_Relay__DR, CYREG_PRT12_DR
.set Pin_Top_Relay__INP_DIS, CYREG_PRT12_INP_DIS
.set Pin_Top_Relay__INTTYPE_BASE, CYDEV_PICU_INTTYPE_PICU12_BASE
.set Pin_Top_Relay__MASK, 0x02
.set Pin_Top_Relay__PORT, 12
.set Pin_Top_Relay__PRT, CYREG_PRT12_PRT
.set Pin_Top_Relay__PRTDSI__DBL_SYNC_IN, CYREG_PRT12_DBL_SYNC_IN
.set Pin_Top_Relay__PRTDSI__OE_SEL0, CYREG_PRT12_OE_SEL0
.set Pin_Top_Relay__PRTDSI__OE_SEL1, CYREG_PRT12_OE_SEL1
.set Pin_Top_Relay__PRTDSI__OUT_SEL0, CYREG_PRT12_OUT_SEL0
.set Pin_Top_Relay__PRTDSI__OUT_SEL1, CYREG_PRT12_OUT_SEL1
.set Pin_Top_Relay__PRTDSI__SYNC_OUT, CYREG_PRT12_SYNC_OUT
.set Pin_Top_Relay__PS, CYREG_PRT12_PS
.set Pin_Top_Relay__SHIFT, 1
.set Pin_Top_Relay__SIO_CFG, CYREG_PRT12_SIO_CFG
.set Pin_Top_Relay__SIO_DIFF, CYREG_PRT12_SIO_DIFF
.set Pin_Top_Relay__SIO_HYST_EN, CYREG_PRT12_SIO_HYST_EN
.set Pin_Top_Relay__SIO_REG_HIFREQ, CYREG_PRT12_SIO_REG_HIFREQ
.set Pin_Top_Relay__SLW, CYREG_PRT12_SLW

/* Pin_Botom_Relay */
.set Pin_Botom_Relay__0__INTTYPE, CYREG_PICU12_INTTYPE0
.set Pin_Botom_Relay__0__MASK, 0x01
.set Pin_Botom_Relay__0__PC, CYREG_PRT12_PC0
.set Pin_Botom_Relay__0__PORT, 12
.set Pin_Botom_Relay__0__SHIFT, 0
.set Pin_Botom_Relay__AG, CYREG_PRT12_AG
.set Pin_Botom_Relay__BIE, CYREG_PRT12_BIE
.set Pin_Botom_Relay__BIT_MASK, CYREG_PRT12_BIT_MASK
.set Pin_Botom_Relay__BYP, CYREG_PRT12_BYP
.set Pin_Botom_Relay__DM0, CYREG_PRT12_DM0
.set Pin_Botom_Relay__DM1, CYREG_PRT12_DM1
.set Pin_Botom_Relay__DM2, CYREG_PRT12_DM2
.set Pin_Botom_Relay__DR, CYREG_PRT12_DR
.set Pin_Botom_Relay__INP_DIS, CYREG_PRT12_INP_DIS
.set Pin_Botom_Relay__INTTYPE_BASE, CYDEV_PICU_INTTYPE_PICU12_BASE
.set Pin_Botom_Relay__MASK, 0x01
.set Pin_Botom_Relay__PORT, 12
.set Pin_Botom_Relay__PRT, CYREG_PRT12_PRT
.set Pin_Botom_Relay__PRTDSI__DBL_SYNC_IN, CYREG_PRT12_DBL_SYNC_IN
.set Pin_Botom_Relay__PRTDSI__OE_SEL0, CYREG_PRT12_OE_SEL0
.set Pin_Botom_Relay__PRTDSI__OE_SEL1, CYREG_PRT12_OE_SEL1
.set Pin_Botom_Relay__PRTDSI__OUT_SEL0, CYREG_PRT12_OUT_SEL0
.set Pin_Botom_Relay__PRTDSI__OUT_SEL1, CYREG_PRT12_OUT_SEL1
.set Pin_Botom_Relay__PRTDSI__SYNC_OUT, CYREG_PRT12_SYNC_OUT
.set Pin_Botom_Relay__PS, CYREG_PRT12_PS
.set Pin_Botom_Relay__SHIFT, 0
.set Pin_Botom_Relay__SIO_CFG, CYREG_PRT12_SIO_CFG
.set Pin_Botom_Relay__SIO_DIFF, CYREG_PRT12_SIO_DIFF
.set Pin_Botom_Relay__SIO_HYST_EN, CYREG_PRT12_SIO_HYST_EN
.set Pin_Botom_Relay__SIO_REG_HIFREQ, CYREG_PRT12_SIO_REG_HIFREQ
.set Pin_Botom_Relay__SLW, CYREG_PRT12_SLW

/* Miscellaneous */
.set BCLK__BUS_CLK__HZ, 76000000
.set BCLK__BUS_CLK__KHZ, 76000
.set BCLK__BUS_CLK__MHZ, 76
.set CYDEV_CHIP_DIE_LEOPARD, 1
.set CYDEV_CHIP_DIE_PSOC4A, 21
.set CYDEV_CHIP_DIE_PSOC5LP, 2
.set CYDEV_CHIP_DIE_PSOC5TM, 3
.set CYDEV_CHIP_DIE_TMA4, 4
.set CYDEV_CHIP_DIE_UNKNOWN, 0
.set CYDEV_CHIP_FAMILY_FM0P, 5
.set CYDEV_CHIP_FAMILY_FM3, 6
.set CYDEV_CHIP_FAMILY_FM4, 7
.set CYDEV_CHIP_FAMILY_PSOC3, 1
.set CYDEV_CHIP_FAMILY_PSOC4, 2
.set CYDEV_CHIP_FAMILY_PSOC5, 3
.set CYDEV_CHIP_FAMILY_PSOC6, 4
.set CYDEV_CHIP_FAMILY_UNKNOWN, 0
.set CYDEV_CHIP_FAMILY_USED, CYDEV_CHIP_FAMILY_PSOC5
.set CYDEV_CHIP_JTAG_ID, 0x2E161069
.set CYDEV_CHIP_MEMBER_3A, 1
.set CYDEV_CHIP_MEMBER_4A, 21
.set CYDEV_CHIP_MEMBER_4D, 16
.set CYDEV_CHIP_MEMBER_4E, 6
.set CYDEV_CHIP_MEMBER_4F, 22
.set CYDEV_CHIP_MEMBER_4G, 4
.set CYDEV_CHIP_MEMBER_4H, 20
.set CYDEV_CHIP_MEMBER_4I, 26
.set CYDEV_CHIP_MEMBER_4J, 17
.set CYDEV_CHIP_MEMBER_4K, 18
.set CYDEV_CHIP_MEMBER_4L, 25
.set CYDEV_CHIP_MEMBER_4M, 24
.set CYDEV_CHIP_MEMBER_4N, 11
.set CYDEV_CHIP_MEMBER_4O, 8
.set CYDEV_CHIP_MEMBER_4P, 23
.set CYDEV_CHIP_MEMBER_4Q, 14
.set CYDEV_CHIP_MEMBER_4R, 9
.set CYDEV_CHIP_MEMBER_4S, 12
.set CYDEV_CHIP_MEMBER_4T, 10
.set CYDEV_CHIP_MEMBER_4U, 5
.set CYDEV_CHIP_MEMBER_4V, 19
.set CYDEV_CHIP_MEMBER_4W, 13
.set CYDEV_CHIP_MEMBER_4X, 7
.set CYDEV_CHIP_MEMBER_4Y, 15
.set CYDEV_CHIP_MEMBER_5A, 3
.set CYDEV_CHIP_MEMBER_5B, 2
.set CYDEV_CHIP_MEMBER_6A, 27
.set CYDEV_CHIP_MEMBER_FM3, 31
.set CYDEV_CHIP_MEMBER_FM4, 32
.set CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE1, 28
.set CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE2, 29
.set CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE3, 30
.set CYDEV_CHIP_MEMBER_UNKNOWN, 0
.set CYDEV_CHIP_MEMBER_USED, CYDEV_CHIP_MEMBER_5B
.set CYDEV_CHIP_DIE_EXPECT, CYDEV_CHIP_MEMBER_USED
.set CYDEV_CHIP_DIE_ACTUAL, CYDEV_CHIP_DIE_EXPECT
.set CYDEV_CHIP_REV_LEOPARD_ES1, 0
.set CYDEV_CHIP_REV_LEOPARD_ES2, 1
.set CYDEV_CHIP_REV_LEOPARD_ES3, 3
.set CYDEV_CHIP_REV_LEOPARD_PRODUCTION, 3
.set CYDEV_CHIP_REV_PSOC4A_ES0, 17
.set CYDEV_CHIP_REV_PSOC4A_PRODUCTION, 17
.set CYDEV_CHIP_REV_PSOC5LP_ES0, 0
.set CYDEV_CHIP_REV_PSOC5LP_PRODUCTION, 0
.set CYDEV_CHIP_REV_PSOC5TM_ES0, 0
.set CYDEV_CHIP_REV_PSOC5TM_ES1, 1
.set CYDEV_CHIP_REV_PSOC5TM_PRODUCTION, 1
.set CYDEV_CHIP_REV_TMA4_ES, 17
.set CYDEV_CHIP_REV_TMA4_ES2, 33
.set CYDEV_CHIP_REV_TMA4_PRODUCTION, 17
.set CYDEV_CHIP_REVISION_3A_ES1, 0
.set CYDEV_CHIP_REVISION_3A_ES2, 1
.set CYDEV_CHIP_REVISION_3A_ES3, 3
.set CYDEV_CHIP_REVISION_3A_PRODUCTION, 3
.set CYDEV_CHIP_REVISION_4A_ES0, 17
.set CYDEV_CHIP_REVISION_4A_PRODUCTION, 17
.set CYDEV_CHIP_REVISION_4D_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4E_CCG2_NO_USBPD, 0
.set CYDEV_CHIP_REVISION_4E_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4F_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4F_PRODUCTION_256DMA, 0
.set CYDEV_CHIP_REVISION_4F_PRODUCTION_256K, 0
.set CYDEV_CHIP_REVISION_4G_ES, 17
.set CYDEV_CHIP_REVISION_4G_ES2, 33
.set CYDEV_CHIP_REVISION_4G_PRODUCTION, 17
.set CYDEV_CHIP_REVISION_4H_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4I_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4J_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4K_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4L_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4M_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4N_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4O_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4P_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4Q_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4R_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4S_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4T_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4U_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4V_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4W_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4X_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4Y_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_5A_ES0, 0
.set CYDEV_CHIP_REVISION_5A_ES1, 1
.set CYDEV_CHIP_REVISION_5A_PRODUCTION, 1
.set CYDEV_CHIP_REVISION_5B_ES0, 0
.set CYDEV_CHIP_REVISION_5B_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_6A_ES, 17
.set CYDEV_CHIP_REVISION_6A_NO_UDB, 33
.set CYDEV_CHIP_REVISION_6A_PRODUCTION, 33
.set CYDEV_CHIP_REVISION_FM3_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_FM4_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_PDL_FM0P_TYPE1_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_PDL_FM0P_TYPE2_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_PDL_FM0P_TYPE3_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_USED, CYDEV_CHIP_REVISION_5B_PRODUCTION
.set CYDEV_CHIP_REV_EXPECT, CYDEV_CHIP_REVISION_USED
.set CYDEV_CONFIG_FASTBOOT_ENABLED, 1
.set CYDEV_CONFIG_UNUSED_IO_AllowButWarn, 0
.set CYDEV_CONFIG_UNUSED_IO, CYDEV_CONFIG_UNUSED_IO_AllowButWarn
.set CYDEV_CONFIG_UNUSED_IO_AllowWithInfo, 1
.set CYDEV_CONFIG_UNUSED_IO_Disallowed, 2
.set CYDEV_CONFIGURATION_COMPRESSED, 1
.set CYDEV_CONFIGURATION_DMA, 0
.set CYDEV_CONFIGURATION_ECC, 1
.set CYDEV_CONFIGURATION_IMOENABLED, CYDEV_CONFIG_FASTBOOT_ENABLED
.set CYDEV_CONFIGURATION_MODE_COMPRESSED, 0
.set CYDEV_CONFIGURATION_MODE, CYDEV_CONFIGURATION_MODE_COMPRESSED
.set CYDEV_CONFIGURATION_MODE_DMA, 2
.set CYDEV_CONFIGURATION_MODE_UNCOMPRESSED, 1
.set CYDEV_DEBUG_ENABLE_MASK, 0x20
.set CYDEV_DEBUG_ENABLE_REGISTER, CYREG_MLOGIC_DEBUG
.set CYDEV_DEBUGGING_DPS_Disable, 3
.set CYDEV_DEBUGGING_DPS_JTAG_4, 1
.set CYDEV_DEBUGGING_DPS_JTAG_5, 0
.set CYDEV_DEBUGGING_DPS_SWD, 2
.set CYDEV_DEBUGGING_DPS, CYDEV_DEBUGGING_DPS_SWD
.set CYDEV_DEBUGGING_DPS_SWD_SWV, 6
.set CYDEV_DEBUGGING_ENABLE, 1
.set CYDEV_DEBUGGING_XRES, 1
.set CYDEV_DMA_CHANNELS_AVAILABLE, 24
.set CYDEV_ECC_ENABLE, 1
.set CYDEV_HEAP_SIZE, 0x200
.set CYDEV_INSTRUCT_CACHE_ENABLED, 1
.set CYDEV_INTR_RISING, 0x00000028
.set CYDEV_IS_EXPORTING_CODE, 0
.set CYDEV_IS_IMPORTING_CODE, 0
.set CYDEV_PROJ_TYPE, 0
.set CYDEV_PROJ_TYPE_BOOTLOADER, 1
.set CYDEV_PROJ_TYPE_LAUNCHER, 5
.set CYDEV_PROJ_TYPE_LOADABLE, 2
.set CYDEV_PROJ_TYPE_LOADABLEANDBOOTLOADER, 4
.set CYDEV_PROJ_TYPE_MULTIAPPBOOTLOADER, 3
.set CYDEV_PROJ_TYPE_STANDARD, 0
.set CYDEV_PROTECTION_ENABLE, 0
.set CYDEV_STACK_SIZE, 0x800
.set CYDEV_USB_CLK_OSC_LOCKING_ENABLED_AT_PWR_UP, 1
.set CYDEV_USE_BUNDLED_CMSIS, 1
.set CYDEV_VARIABLE_VDDA, 0
.set CYDEV_VDDA_MV, 5000
.set CYDEV_VDDD_MV, 5000
.set CYDEV_VDDIO0_MV, 5000
.set CYDEV_VDDIO1_MV, 5000
.set CYDEV_VDDIO2_MV, 5000
.set CYDEV_VDDIO3_MV, 5000
.set CYDEV_VIO0_MV, 5000
.set CYDEV_VIO1_MV, 5000
.set CYDEV_VIO2_MV, 5000
.set CYDEV_VIO3_MV, 5000
.set CYIPBLOCK_ARM_CM3_VERSION, 0
.set CYIPBLOCK_P3_ANAIF_VERSION, 0
.set CYIPBLOCK_P3_CAN_VERSION, 0
.set CYIPBLOCK_P3_CAPSENSE_VERSION, 0
.set CYIPBLOCK_P3_COMP_VERSION, 0
.set CYIPBLOCK_P3_DECIMATOR_VERSION, 0
.set CYIPBLOCK_P3_DFB_VERSION, 0
.set CYIPBLOCK_P3_DMA_VERSION, 0
.set CYIPBLOCK_P3_DRQ_VERSION, 0
.set CYIPBLOCK_P3_DSM_VERSION, 0
.set CYIPBLOCK_P3_EMIF_VERSION, 0
.set CYIPBLOCK_P3_I2C_VERSION, 0
.set CYIPBLOCK_P3_LCD_VERSION, 0
.set CYIPBLOCK_P3_LPF_VERSION, 0
.set CYIPBLOCK_P3_OPAMP_VERSION, 0
.set CYIPBLOCK_P3_PM_VERSION, 0
.set CYIPBLOCK_P3_SCCT_VERSION, 0
.set CYIPBLOCK_P3_TIMER_VERSION, 0
.set CYIPBLOCK_P3_USB_VERSION, 0
.set CYIPBLOCK_P3_VIDAC_VERSION, 0
.set CYIPBLOCK_P3_VREF_VERSION, 0
.set CYIPBLOCK_S8_GPIO_VERSION, 0
.set CYIPBLOCK_S8_IRQ_VERSION, 0
.set CYIPBLOCK_S8_SAR_VERSION, 0
.set CYIPBLOCK_S8_SIO_VERSION, 0
.set CYIPBLOCK_S8_UDB_VERSION, 0
.set Dedicated_Output__INTTYPE, CYREG_PICU3_INTTYPE7
.set Dedicated_Output__MASK, 0x80
.set Dedicated_Output__PC, CYREG_PRT3_PC7
.set Dedicated_Output__PORT, 3
.set Dedicated_Output__SHIFT, 7
.set DMA_CHANNELS_USED__MASK0, 0x00000000
.set CYDEV_BOOTLOADER_ENABLE, 0
.endif
