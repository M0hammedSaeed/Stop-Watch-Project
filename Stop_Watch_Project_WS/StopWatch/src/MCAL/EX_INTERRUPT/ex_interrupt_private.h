/*******************************************************************************
 * [   Module  ]: External Interrupts Register Modules
 *
 * [ File Name ]: ex_interrupt_private.h
 *
 * [Description]: Header File for ATmega32 External Interrupts Register.
 *
 * [   Author  ]: Mohamed Saeed
 *
 *******************************************************************************/

#ifndef SRC_MCAL_EX_INTERRUPT_EX_INTERRUPT_PRIVATE_H_
#define SRC_MCAL_EX_INTERRUPT_EX_INTERRUPT_PRIVATE_H_

/*------------------------------------------------------------------------------
 *                                  INCLUDES
 *------------------------------------------------------------------------------*/

#include "../../utils/std_types.h"

/*------------------------------------------------------------------------------
 *                                 DEFINITIONS
 *------------------------------------------------------------------------------*/

/* Definition for GICR (General Interrupt Control Register) */
#define GICR_REG	(*(volatile uint8 *)0x5B)

/* Definition for MCUCR (MCU Control Register) */
#define MCUCR_REG	(*(volatile uint8 *)0x55)

/* Definition for MCUCSR (MCU Control and status Register) */
#define MCUCSR_REG	(*(volatile uint8 *)0x54)

/* Definition for GIFR (General Interrupt Flag Register) */
#define GIFR_REG	(*(volatile uint8 *)0x5A)

/* Interrupt vectors */

/* External Interrupt Request 0 */
#define INT0_vect			_VECTOR(1)
/* External Interrupt Request 1 */
#define INT1_vect			_VECTOR(2)
/* External Interrupt Request 2 */
#define INT2_vect			_VECTOR(3)

/* Bit numbers */

/* GICR */
#define GICR_INT1		7
#define GICR_INT0    	6
#define GICR_INT2    	5

/* MCUCR */
#define MCUCR_ISC11  	3
#define MCUCR_ISC10   	2
#define MCUCR_ISC01   	1
#define MCUCR_ISC00   	0

/* MCUCSR */
#define MCUCSR_ISC2   	6

/* GIFR */
#define GIFR_INTF1  	7
#define GIFR_INTF0   	6
#define GIFR_INTF2   	5

/* Interrupt Handler (ISR) */
#define _VECTOR(N) 			__vector_ ## N
#define ISR(vector) \
	void vector (void) __attribute__ ((signal)); \
	void vector (void)

/*******************************************************************************
 *                                    MASK's
 *******************************************************************************/

/*------------------------------------------------------------------------------
 *                      [Masks For External Interrupt sense]
 * -----------------------------------------------------------------------------*/

/*INT0 Mask's*/
#define INT0_SENSE_CLR_MASK                0xFC
#define INT0_SENSE_LOW_LEVEL_MASK          0x00
#define INT0_SENSE_ANY_LOGICAL_CHANGE_MASK 0x01
#define INT0_SENSE_FALLING_EDGE_MASK       0x02
#define INT0_SENSE_RISING_EDGE_MASK        0x03

/*INT1 Mask's*/
#define INT1_SENSE_CLR_MASK                0xF3
#define INT1_SENSE_LOW_LEVEL_MASK          0x00
#define INT1_SENSE_ANY_LOGICAL_CHANGE_MASK 0x04
#define INT1_SENSE_FALLING_EDGE_MASK       0x08
#define INT1_SENSE_RISING_EDGE_MASK        0x0C

/*INT2 Mask's*/
#define INT2_SENSE_CLR_MASK                0xBF
#define INT2_SENSE_FALLING_EDGE_MASK       0x00
#define INT2_SENSE_RISING_EDGE_MASK        0x40

#endif /* SRC_MCAL_EX_INTERRUPT_EX_INTERRUPT_PRIVATE_H_ */
