/*******************************************************************************
 * [ File Name ]: seven_segment.c
 *
 * [Description]: Source file for implementing the seven_segment Functionality.
 *
 * [   Author  ]: Mohamed Saeed
 *
 *******************************************************************************/

/*------------------------------------------------------------------------------
 *                                 INCLUDES
 *------------------------------------------------------------------------------*/

#include "seven_segment.h"

/*------------------------------------------------------------------------------
 *                               Private Definitions
 *------------------------------------------------------------------------------*/

/* Display Number In Configuration COMMON_CATHODE mode */
#if (COMMON_CATHODE == ENABLE)
#if (DP_EN == ENABLE)

#define ZERO     0xBF
#define ONE      0x86
#define TWO      0xDB
#define THREE    0xCF
#define FOUR     0xE6
#define FIVE     0xED
#define SIX      0xFD
#define SEVEN    0x87
#define EIGHT    0xFF
#define NINE     0xEF

#elif (DP_EN == DISABLE)

#define ZERO     0x3F
#define ONE      0x06
#define TWO      0x5B
#define THREE    0x4F
#define FOUR     0x66
#define FIVE     0x6D
#define SIX      0x7D
#define SEVEN    0x07
#define EIGHT    0x7F
#define NINE     0x6F

#endif
#endif

/* Display Number In Configuration COMMON_ANODE mode */
#if (COMMON_ANODE == ENABLE)
#if (DP_EN == ENABLE)

#define ZERO     0x40
#define ONE      0x79
#define TWO      0x24
#define THREE    0x30
#define FOUR     0x19
#define FIVE     0x12
#define SIX      0x02
#define SEVEN    0x78
#define EIGHT    0x00
#define NINE     0x10

#elif (DP_EN == DISABLE)

#define ZERO     0xC0
#define ONE      0xF9
#define TWO      0xA4
#define THREE    0xB0
#define FOUR     0x99
#define FIVE     0x92
#define SIX      0x82
#define SEVEN    0xF8
#define EIGHT    0x80
#define NINE     0x90

#endif
#endif

#if MULTIPLEXED_SEVEN_SEGMENTS == ENABLE
#if COMMON_CATHODE == ENABLE
#define  D1_EN   0xFE
#define  D2_EN   0xFD
#define  D3_EN   0xFB
#define  D4_EN   0xF7
#define  D5_EN   0xEF
#define  D6_EN   0xDF

#elif  COMMON_ANODE == ENABLE

#define  D1_EN   0xC1
#define  D2_EN   0xC2
#define  D3_EN   0xC4
#define  D4_EN   0xC8
#define  D5_EN   0xD0
#define  D6_EN   0xE0

#endif
#endif

/*------------------------------------------------------------------------------
 *                               Private Array
 *------------------------------------------------------------------------------*/
#if (HARDWARE_BCD == DISABLE)
/* I create this mapping array to Write on specific pins on port */
static const uint8 NumMap[10] = {ZERO, ONE, TWO, THREE, FOUR,
								 FIVE, SIX, SEVEN, EIGHT, NINE};
#endif

/*------------------------------------------------------------------------------
 *                               FUNCTIONS IMPLEMENTATION
 *------------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------------------
 [FUNCTION NAME]:sevenSegmentInit
 [DISCRIPTION]:	This function is responsible to Initialized the 7-Segment pins.
 [Args]: void
 [RUTURN]: EN_7Segment_Error_t
 ---------------------------------------------------------------------------------------*/
EN_7Segment_Error_t sevenSegmentInit(void)
{
#if (COMMON_CATHODE == ENABLE)
#if (HARDWARE_BCD == DISABLE)
	/* I use 8*1 7segment so i set the direction for all PORT for it */
	GPIO_SetPortDir(SevenSegment_PORT, port_output);
	/* output 0 to OFF All 8 (7-Segments) */
	GPIO_WritePort(SevenSegment_PORT, 0x00);

#elif (HARDWARE_BCD == ENABLE)
#if (MULTIPLEXED_SEVEN_SEGMENTS == ENABLE)
	//6 pins for display Specific 7segment from 6 (7-segments).
	//I use 6*1 7segment so i set the direction for 7 pins for it.
	GPIO_SetPinDir(D_PORT, D1_Pin, pin_output);
	GPIO_SetPinDir(D_PORT, D2_Pin, pin_output);
	GPIO_SetPinDir(D_PORT, D3_Pin, pin_output);
	GPIO_SetPinDir(D_PORT, D4_Pin, pin_output);
	GPIO_SetPinDir(D_PORT, D5_Pin, pin_output);
	GPIO_SetPinDir(D_PORT, D6_Pin, pin_output);
	// output 1 to ON All 6 (7-Segments)
	GPIO_WritePin(D_PORT, D1_Pin, LOGIC_HIGH);
	GPIO_WritePin(D_PORT, D2_Pin, LOGIC_HIGH);
	GPIO_WritePin(D_PORT, D3_Pin, LOGIC_HIGH);
	GPIO_WritePin(D_PORT, D4_Pin, LOGIC_HIGH);
	GPIO_WritePin(D_PORT, D5_Pin, LOGIC_HIGH);
	GPIO_WritePin(D_PORT, D6_Pin, LOGIC_HIGH);
#endif
	/* Set direction of BCD pins and output LOW to display ZERO on 7segments */
	GPIO_SetPinDir(SevenSegment_PORT, SevenSegment_PIN0, pin_output);
	GPIO_WritePin(SevenSegment_PORT, SevenSegment_PIN0, LOGIC_LOW);

	GPIO_SetPinDir(SevenSegment_PORT, SevenSegment_PIN1, pin_output);
	GPIO_WritePin(SevenSegment_PORT, SevenSegment_PIN1, LOGIC_LOW);

	GPIO_SetPinDir(SevenSegment_PORT, SevenSegment_PIN2, pin_output);
	GPIO_WritePin(SevenSegment_PORT, SevenSegment_PIN2, LOGIC_LOW);

	GPIO_SetPinDir(SevenSegment_PORT, SevenSegment_PIN3, pin_output);
	GPIO_WritePin(SevenSegment_PORT, SevenSegment_PIN3, LOGIC_LOW);

#endif
	return DONE;
#endif

#if (COMMON_ANODE == ENABLE)
#if (HARDWARE_BCD == DISABLE)
	/* I use 8*1 7segment so i set the direction for all PORT for it */
	GPIO_SetPortDir(SevenSegment_PORT, port_output);
	/* output 1 to OFF All 8 (7-Segments) */
	GPIO_WritePort(SevenSegment_PORT, 0xFF);

#elif (HARDWARE_BCD == ENABLE)
#if (MULTIPLEXED_SEVEN_SEGMENTS == ENABLE)
	//6 pins for display Specific 7segment from 6 (7-segments).
	//I use 6*1 7segment so i set the direction for 7 pins for it.
	GPIO_SetPinDir(D_PORT, D1_Pin, pin_output);
	GPIO_SetPinDir(D_PORT, D2_Pin, pin_output);
	GPIO_SetPinDir(D_PORT, D3_Pin, pin_output);
	GPIO_SetPinDir(D_PORT, D4_Pin, pin_output);
	GPIO_SetPinDir(D_PORT, D5_Pin, pin_output);
	GPIO_SetPinDir(D_PORT, D6_Pin, pin_output);
	// output 1 to ON All 6 (7-Segments)
	GPIO_WritePin(D_PORT, D1_Pin, LOGIC_HIGH);
	GPIO_WritePin(D_PORT, D2_Pin, LOGIC_HIGH);
	GPIO_WritePin(D_PORT, D3_Pin, LOGIC_HIGH);
	GPIO_WritePin(D_PORT, D4_Pin, LOGIC_HIGH);
	GPIO_WritePin(D_PORT, D5_Pin, LOGIC_HIGH);
	GPIO_WritePin(D_PORT, D6_Pin, LOGIC_HIGH);
#endif
	/* Set direction of BCD pins and output HIGH to display ZERO on 7segments */
	GPIO_SetPinDir(SevenSegment_PORT, SevenSegment_PIN0, pin_output);
	GPIO_WritePin(SevenSegment_PORT, SevenSegment_PIN0, LOGIC_LOW);

	GPIO_SetPinDir(SevenSegment_PORT, SevenSegment_PIN1, pin_output);
	GPIO_WritePin(SevenSegment_PORT, SevenSegment_PIN1, LOGIC_LOW);

	GPIO_SetPinDir(SevenSegment_PORT, SevenSegment_PIN2, pin_output);
	GPIO_WritePin(SevenSegment_PORT, SevenSegment_PIN2, LOGIC_LOW);

	GPIO_SetPinDir(SevenSegment_PORT, SevenSegment_PIN3, pin_output);
	GPIO_WritePin(SevenSegment_PORT, SevenSegment_PIN3, LOGIC_LOW);

#endif
	return DONE;
#endif
	return ERROR;
}

/*--------------------------------------------------------------------------------------
 [FUNCTION NAME]:sevenSegmenDisplay
 [DISCRIPTION]:	This function is responsible to display number on the 7-Segment
 [Args]: uint8
 [RUTURN]: EN_7Segment_Error_t
 ---------------------------------------------------------------------------------------*/
EN_7Segment_Error_t sevenSegmenDisplay(uint8 Num)
{
#if HARDWARE_BCD == ENABLE
	/*
	 * because we use BCD so just you need to write only One to display one on 7_Segment
	 * Convert the number to binary EX:4 -> 0100 to write it to BCD IC
	 */
	GPIO_WriteLowNibble(SevenSegment_PORT, Num);

	return DONE;
#elif (HARDWARE_BCD == DISABLE)
	/* because we NOT use BCD so we need to mapping the number to display on 7Segment */
	GPIO_WritePin(SevenSegment_PORT, SevenSegment_PIN0, GET_BIT(NumMap[Num],0));
	GPIO_WritePin(SevenSegment_PORT, SevenSegment_PIN1, GET_BIT(NumMap[Num],1));
	GPIO_WritePin(SevenSegment_PORT, SevenSegment_PIN2, GET_BIT(NumMap[Num],2));
	GPIO_WritePin(SevenSegment_PORT, SevenSegment_PIN3, GET_BIT(NumMap[Num],3));
	GPIO_WritePin(SevenSegment_PORT, SevenSegment1_PIN4, GET_BIT(NumMap[Num],4));
	GPIO_WritePin(SevenSegment_PORT, SevenSegment1_PIN5, GET_BIT(NumMap[Num],5));
	GPIO_WritePin(SevenSegment_PORT, SevenSegment1_PIN6, GET_BIT(NumMap[Num],6));
	GPIO_WritePin(SevenSegment_PORT, SevenSegment1_PIN7, GET_BIT(NumMap[Num],7));
	return DONE;
#endif
	return ERROR;
}


/*--------------------------------------------------------------------------------------
 [FUNCTION NAME]:sevenSegmenDn_EN
 [DISCRIPTION]:	This function's is responsible to Enable the specific 7-Segment
 [Args]:void
 [RUTURN]: Void
 ---------------------------------------------------------------------------------------*/
void sevenSegmentD1_EN(void)
{
	GPIO_WritePort(D_PORT, D1_EN);
}

void sevenSegmentD2_EN(void)
{
	GPIO_WritePort(D_PORT, D2_EN);
}

void sevenSegmentD3_EN(void)
{
	GPIO_WritePort(D_PORT, D3_EN);
}

void sevenSegmentD4_EN(void)
{
	GPIO_WritePort(D_PORT, D4_EN);
}

void sevenSegmentD5_EN(void)
{
	GPIO_WritePort(D_PORT, D5_EN);
}

void sevenSegmentD6_EN(void)
{
	GPIO_WritePort(D_PORT, D6_EN);
}
