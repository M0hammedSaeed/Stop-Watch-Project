/*******************************************************************************
 * [ File Name ]: seven_segment.h
 *
 * [Description]:  Header file for Declaration and config the seven_segment Functionality.
 *
 * [   Author  ]: Mohamed Saeed
 *
 *******************************************************************************/

#ifndef SRC_EHAL_7_SEGMENT_SEVEN_SEGMENT_H_
#define SRC_EHAL_7_SEGMENT_SEVEN_SEGMENT_H_

/*------------------------------------------------------------------------------
 *                                 INCLUDES
 *------------------------------------------------------------------------------*/

#include "../../utils/std_types.h"
#include "../../MCAL/GPIO/gpio.h"

/*------------------------------------------------------------------------------
 *                         DEFINITIONS AND CONFIGURATION
 *------------------------------------------------------------------------------*/

#define COMMON_CATHODE         		DISABLE
#define COMMON_ANODE           		ENABLE
/* BCD => Binary Coded Decimal */
#define HARDWARE_BCD           		ENABLE
/* DP => Decimal Point */
#define DP_EN                  		DISABLE

#define MULTIPLEXED_SEVEN_SEGMENTS	ENABLE

#define SevenSegment_PORT	   		PORTC_ID

#define SevenSegment_PIN0	   		PIN0_ID
#define SevenSegment_PIN1	  		PIN1_ID
#define SevenSegment_PIN2	   		PIN2_ID
#define SevenSegment_PIN3	   		PIN3_ID

#define D_PORT				   		PORTA_ID

#define D1_Pin				   		PIN0_ID
#define D2_Pin				   		PIN1_ID
#define D3_Pin				   		PIN2_ID
#define D4_Pin				   		PIN3_ID
#define D5_Pin				   		PIN4_ID
#define D6_Pin				   		PIN5_ID

typedef enum
{
	DONE,
	ERROR
}EN_7Segment_Error_t;

/*------------------------------------------------------------------------------
 *                             Function Prototype
 -------------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------------------
 [FUNCTION NAME]:sevenSegmentInit
 [DISCRIPTION]:	This function is responsible to Initialized the 7-Segment pins.
 [Args]: void
 [RUTURN]: EN_7Segment_Error_t
 ---------------------------------------------------------------------------------------*/
EN_7Segment_Error_t sevenSegmentInit(void);

/*--------------------------------------------------------------------------------------
 [FUNCTION NAME]:sevenSegmenDisplay
 [DISCRIPTION]:	This function is responsible to display number on the 7-Segment
 [Args]: uint8
 [RUTURN]: EN_7Segment_Error_t
 ---------------------------------------------------------------------------------------*/
EN_7Segment_Error_t sevenSegmenDisplay(uint8 Num);

/*--------------------------------------------------------------------------------------
 [FUNCTION NAME]:sevenSegmenDn_EN
 [DISCRIPTION]:	This function's is responsible to Enable the specific 7-Segment
 [Args]: Void
 [RUTURN]: Void
 ---------------------------------------------------------------------------------------*/
void sevenSegmentD1_EN(void);

void sevenSegmentD2_EN(void);

void sevenSegmentD3_EN(void);

void sevenSegmentD4_EN(void);

void sevenSegmentD5_EN(void);

void sevenSegmentD6_EN(void);

#endif /* SRC_EHAL_7_SEGMENT_SEVEN_SEGMENT_H_ */
