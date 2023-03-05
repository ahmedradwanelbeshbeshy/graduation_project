/* 
 * File:   mcal_external_interrupt.h
 * Author: ahmed Odb
 *
 * Created on August 4, 2022, 10:47 AM
 */

#ifndef MCAL_EXTERNAL_INTERRUPTS_H
#define	MCAL_EXTERNAL_INTERRUPTS_H


/* Includes */
#include "./mcal_interrupt_config.h"
#include "../GPIO/hal_gpio.h"

#define INT_INT0_PORT   PORTB_INDEX
#define INT_INT0_PIN    GPIO_PIN0

#define INT_INT1_PORT   PORTB_INDEX
#define INT_INT1_PIN    GPIO_PIN1

#define INT_INT2_PORT   PORTB_INDEX
#define INT_INT2_PIN    GPIO_PIN2


#define INT_KBI0_PORT   PORTB_INDEX
#define INT_KBI0_PIN    GPIO_PIN4

#define INT_KBI1_PORT   PORTB_INDEX
#define INT_KBI1_PIN    GPIO_PIN5

#define INT_KBI2_PORT   PORTB_INDEX
#define INT_KBI2_PIN    GPIO_PIN6

#define INT_KBI3_PORT   PORTB_INDEX
#define INT_KBI3_PIN    GPIO_PIN7

/* Macro Functions */



#define INT_SET_INT0_INPUT()                    (TRISBbits.RB0 = 1)
#define INT_SET_INT1_INPUT()                    (TRISBbits.RB1 = 1)
#define INT_SET_INT2_INPUT()                    (TRISBbits.RB2 = 1)

#define INT_SET_KBI0_INPUT()                    (TRISBbits.RB4 = 1)
#define INT_SET_KBI1_INPUT()                    (TRISBbits.RB5 = 1)
#define INT_SET_KBI2_INPUT()                    (TRISBbits.RB6 = 1)
#define INT_SET_KBI3_INPUT()                    (TRISBbits.RB6 = 1)

#if INT_EXTERNAL_INTx_FEATURE_ENABLE==FEATURE_ENABLE
/*_____________________________________ INTx external interrupts ___________________________________  */
/****************************************** INT0 external interrupt  **********************************/
/* Clear INT0 Interrupt Flag */
#define INT_INT0_CLEAR_FLAG()                   (INTCONbits.INT0IF = 0  )

/* INT0 Trigger Config ( Rising or Falling edge ) */
#define INT_INT0_RISING_EDGE()                  (INTCON2bits.INTEDG0 = 1)
#define INT_INT0_FALLING_EDGE()                 (INTCON2bits.INTEDG0 = 0)

/* INT0 Interrupt Enable and Disable */
#define INT_INT0_ENABLE()                       (INTCONbits.INT0IE = 1  )
#define INT_INT0_DISABLE()                      (INTCONbits.INT0IE = 0  )

/* INT0 Priority is FIXED ( HIGH PRIORITY ) */

/****************************************** INT1 external interrupt  **********************************/
/* Clear INT0 Interrupt Flag */
#define INT_INT1_CLEAR_FLAG()                   (INTCON3bits.INT1IF = 0 )

/* INT1 Trigger Config ( Rising or Falling edge ) */
#define INT_INT1_RISING_EDGE()                   (INTCON2bits.INTEDG1 = 1)
#define INT_INT1_FALLING_EDGE()                  (INTCON2bits.INTEDG1 = 0)

/* INT1 Interrupt Enable and Disable */
#define INT_INT1_ENABLE()                        (INTCON3bits.INT1IE = 1 )
#define INT_INT1_DISABLE()                       (INTCON3bits.INT1IE = 0 )

/* INT1 Priority Setting  */
#if INT_PRI_LEVELS_ENABLE==FEATURE_ENABLE 
#define INT_INT1_PRI_HIGH()                      (INTCON3bits.INT1IP = 1 )
#define INT_INT1_PRI_LOW()                       (INTCON3bits.INT1IP = 0 )
#endif

/****************************************** INT2 external interrupt  **********************************/
/* Clear INT0 Interrupt Flag */
#define INT_INT2_CLEAR_FLAG()                    (INTCON3bits.INT2IF = 0)

/* INT2 Trigger Config ( Rising or Falling edge ) */
#define INT_INT2_RISING_EDGE()                   (INTCON2bits.INTEDG2 = 1)
#define INT_INT2_FALLING_EDGE()                  (INTCON2bits.INTEDG2 = 0)

/* INT2 Interrupt Enable and Disable */
#define INT_INT2_ENABLE()                        (INTCON3bits.INT2IE = 1)
#define INT_INT2_DISABLE()                       (INTCON3bits.INT2IE = 0)

/* INT2 Priority Setting  */
#if INT_PRI_LEVELS_ENABLE==FEATURE_ENABLE 
#define INT_INT2_PRI_HIGH()                      (INTCON3bits.INT2IP = 1)
#define INT_INT2_PRI_LOW()                       (INTCON3bits.INT2IP = 0)
#endif
#endif /*  */
/*_____________________________________ PORTB Interrupt On-Change ___________________________________  */
#if INT_EXTERNAL_ON_CHANGE_FEATURE_ENABLE==FEATURE_ENABLE

#define INT_RBx_ENABLE()                          (INTCONbits.RBIE = 1 )
#define INT_RBx_DISABLE()                         (INTCONbits.RBIE = 0 )

#define INT_RBx_CLEAR_FLAG()                      (INTCONbits.RBIF = 0 )

#if INT_PRI_LEVELS_ENABLE==FEATURE_ENABLE 
#define INT_RBx_PRI_HIGH()                        (INTCON2bits.RBIP = 1)
#define INT_RBx_PRI_LOW()                         (INTCON2bits.RBIP = 0)
#endif
#endif
/* User-Defined Data Type Declaration */


typedef enum {
    INTERRUPT_INT0,
    INTERRUPT_INT1,
    INTERRUPT_INT2
}interrupt_INTx_src_et;


typedef enum {
    INT_FALLING_EDGE,
    INT_RISING_EDGE

}interrupt_INTx_edge_et;



typedef struct {
    void (* Ext_Interrupt_Handler ) (void);
    interrupt_INTx_edge_et edge ;
    interrupt_INTx_src_et src ;
    interrupt_pri_et priority ;
} Interrupt_INTx_st;

typedef struct {
        void (* Ext_Interrupt_Handler_High ) (void);
        void (* Ext_Interrupt_Handler_Low ) (void);
        interrupt_pri_et priority ;
        pin_config_st pin ;
} Interrupt_RBx_st;


/* Software Interfaces (Prototypes) */

Std_ReturnType Interrupt_INTx_INIT(const Interrupt_INTx_st *int_obj);
Std_ReturnType Interrupt_INTx_DeINIT(const Interrupt_INTx_st *int_obj);

Std_ReturnType Interrupt_RBx_INIT(const Interrupt_RBx_st *int_obj);
Std_ReturnType Interrupt_RBx_DeINIT(const Interrupt_RBx_st *int_obj);

/* Global Shared Variables */


#endif	/* MCAL_EXTERNAL_INTERRUPTS_H */

