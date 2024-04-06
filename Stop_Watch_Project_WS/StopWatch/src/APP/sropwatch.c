/*******************************************************************************
* [File Name]:    stopwatch.c
*
* [Description]:  Source file for implementing the StopWatch Functionality.
*
* [Author]:       Mohamed Saeed
*
********************************************************************************/

/*------------------------------------------------------------------------------
 *                                 INCLUDES
 *------------------------------------------------------------------------------*/

#include "stopwatch.h"
#include "../utils/std_types.h"
#include "util/delay.h"

/*------------------------------------------------------------------------------
 *                          Definitions & Global Variable
 *------------------------------------------------------------------------------*/

extern volatile uint8 interruptSecondFlag;

volatile uint8 secondsCount = 0;
volatile uint8 minutesCount = 0;
volatile uint8 hoursCount = 0;

/*------------------------------------------------------------------------------
 *                              Private Function's
 *------------------------------------------------------------------------------*/

static void sevenSegmentOnesNum(uint8 num);
static void sevenSegmentTensNum(uint8 num);

/*------------------------------------------------------------------------------
 *                             Functions Definitions
 *------------------------------------------------------------------------------*/


/*--------------------------------------------------------------------------------------
 [Function Name]: stopWatchInit
 [Description]:	This function is responsible to Initialize the StopWatch Application
 [Args]:   void
 [Return]: Void
 ---------------------------------------------------------------------------------------*/
void stopWatchInit(void)
{
	sevenSegmentInit();
	GI_Enable();
	TIMER_Init();
	Ex_INT_Init();
	Ex_INT0_SetCallBack(sevenSegmentResetDisplay);
	Ex_INT1_SetCallBack(sevenSegmentPauseDisplay);
	Ex_INT2_SetCallBack(sevenSegmentResumeDisplay);
}

/*--------------------------------------------------------------------------------------
 [Function Name]: stopWatchStart
 [Description]:	This function is responsible to Start the StopWatch Application
 [Args]:   void
 [Return]: Void
 ---------------------------------------------------------------------------------------*/
void stopWatchStart(void)
{
	sevenSegmentSecondsDisplay();
	sevenSegmentMinutsDisplay();
	sevenSegmentHoursDisplay();
}

/*--------------------------------------------------------------------------------------
 [Function Name]: sevenSegmentSecondsDisplay
 [Description]:	This function is responsible to count and display the second's on 7-Segment's
 [Args]:   void
 [Return]: EN_StopWatch_Error_t
 ---------------------------------------------------------------------------------------*/
EN_StopWatch_Error_t sevenSegmentSecondsDisplay(void)
{
	if(interruptSecondFlag == TRUE)
	{
		//Flag true mean that timer count 1ms
		interruptSecondFlag = FALSE;

		secondsCount++;
		if(secondsCount == 60)
		{
			minutesCount++;
			secondsCount = 0;
		}
		if(secondsCount > 60)
		{
			return STOP_WATCH_ERROR;
		}
	}

	/* Display The Seconds on 7segment */
	sevenSegmentD1_EN();
	sevenSegmentOnesNum(secondsCount);
	_delay_us(2);	// delay to changes in the 7-segment

	sevenSegmentD2_EN();
	sevenSegmentTensNum(secondsCount);
	_delay_us(2);	// delay to changes in the 7-segment

	return STOP_WATCH_DONE;
}

/*--------------------------------------------------------------------------------------
 [Function Name]: sevenSegmentMinutsDisplay
 [Description]:	This function is responsible to count and display the minut's on 7-Segment's
 [Args]:   void
 [Return]: EN_StopWatch_Error_t
 ---------------------------------------------------------------------------------------*/
EN_StopWatch_Error_t sevenSegmentMinutsDisplay(void)
{
	if(minutesCount == 60)
	{
		hoursCount++;
		minutesCount = 0;
	}

	/* Display The Minutes on 7segment */
	sevenSegmentD3_EN();
	sevenSegmentOnesNum(minutesCount);
	_delay_us(2);	// delay to changes in the 7-segment

	sevenSegmentD4_EN();
	sevenSegmentTensNum(minutesCount);
	_delay_us(2);	// delay to changes in the 7-segment

	return STOP_WATCH_DONE;
}

/*--------------------------------------------------------------------------------------
 [Function Name]: sevenSegmentHoursDisplay
 [Description]:	This function is responsible to count and display the hours on 7-Segment's
 [Args]:   void
 [Return]: EN_StopWatch_Error_t
 ---------------------------------------------------------------------------------------*/
EN_StopWatch_Error_t sevenSegmentHoursDisplay(void)
{
	if(hoursCount == 12)
	{
		hoursCount = 0;
	}

	/* Display The Hours on 7segment */
	sevenSegmentD5_EN();
	sevenSegmentOnesNum(hoursCount);
	_delay_us(2);	// delay to changes in the 7-segment

	sevenSegmentD6_EN();
	sevenSegmentTensNum(hoursCount);
	_delay_us(2);	// delay to changes in the 7-segment

	return STOP_WATCH_DONE;
}



/*-------------------------------Private Functions Definitions--------------------------------*/
	void sevenSegmentOnesNum(uint8 num)
{
	switch((num%10))
	{
	case 0:
		sevenSegmenDisplay(0);
		break;
	case 1:
		sevenSegmenDisplay(1);
		break;
	case 2:
		sevenSegmenDisplay(2);
		break;
	case 3:
		sevenSegmenDisplay(3);
		break;
	case 4:
		sevenSegmenDisplay(4);
		break;
	case 5:
		sevenSegmenDisplay(5);
		break;
	case 6:
		sevenSegmenDisplay(6);
		break;
	case 7:
		sevenSegmenDisplay(7);
		break;
	case 8:
		sevenSegmenDisplay(8);
		break;
	case 9:
		sevenSegmenDisplay(9);
		break;
	}

}


void sevenSegmentTensNum(uint8 num)
{
	switch((num/10))
	{
	case 0:
		sevenSegmenDisplay(0);
		break;
	case 1:
		sevenSegmenDisplay(1);
		break;
	case 2:
		sevenSegmenDisplay(2);
		break;
	case 3:
		sevenSegmenDisplay(3);
		break;
	case 4:
		sevenSegmenDisplay(4);
		break;
	case 5:
		sevenSegmenDisplay(5);
		break;
	case 6:
		sevenSegmenDisplay(6);
		break;
	case 7:
		sevenSegmenDisplay(7);
		break;
	case 8:
		sevenSegmenDisplay(8);
		break;
	case 9:
		sevenSegmenDisplay(9);
		break;
	}
}

/*--------------------------------------------------------------------------------------
 [Function Name]: sevenSegmentResetDisplay
 [Description]:	This function is responsible to Reset stopwatch on 7-Segment's
 [Args]:   void
 [Return]: EN_StopWatch_Error_t
 ---------------------------------------------------------------------------------------*/
void sevenSegmentResetDisplay(void)
{
	secondsCount = 0;
	minutesCount = 0;
	hoursCount = 0;
}

/*--------------------------------------------------------------------------------------
 [Function Name]: sevenSegmentPauseDisplay
 [Description]:	This function is responsible to Pause stopwatch on 7-Segment's
 [Args]:   void
 [Return]: EN_StopWatch_Error_t
 ---------------------------------------------------------------------------------------*/
void sevenSegmentPauseDisplay(void)
{
	TIMER_DeInit();
}

/*--------------------------------------------------------------------------------------
 [Function Name]: sevenSegmentResumeDisplay
 [Description]:	This function is responsible to Resume stopwatch on 7-Segment's
 [Args]:   void
 [Return]: EN_StopWatch_Error_t
 ---------------------------------------------------------------------------------------*/
void sevenSegmentResumeDisplay(void)
{
	TIMER_Init();
}
