/*******************************************************************************
* [File Name]:   stopwatch.h
*
* [Description]: Header file for Declaration and configuration the StopWatch Functionality.
*
* [Author]:      Mohamed Saeed
*
********************************************************************************/

#ifndef SRC_APP_STOPWATCH_H_
#define SRC_APP_STOPWATCH_H_

/*------------------------------------------------------------------------------
 *                                 INCLUDES
 *------------------------------------------------------------------------------*/

#include "../EHAL/7_SEGMENT/seven_segment.h"
#include "../MCAL/TIMER/timer.h"
#include "../MCAL/EX_INTERRUPT/ex_interrupt.h"
#include "../MCAL/G_INTERRUPT/g_interrupt.h"

/*------------------------------------------------------------------------------
 *                                Error Type's
 *------------------------------------------------------------------------------*/

typedef enum
{
	STOP_WATCH_DONE,
	STOP_WATCH_ERROR
}EN_StopWatch_Error_t;

/*------------------------------------------------------------------------------
 *                             Functions Declaration
 *------------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------------------
 [Function Name]: stopWatchInit
 [Description]:	This function is responsible to Initialize the StopWatch Application
 [Args]:   void
 [Return]: Void
 ---------------------------------------------------------------------------------------*/
void stopWatchInit(void);

/*--------------------------------------------------------------------------------------
 [Function Name]: stopWatchStart
 [Description]:	This function is responsible to Start the StopWatch Application
 [Args]:   void
 [Return]: Void
 ---------------------------------------------------------------------------------------*/
void stopWatchStart(void);

/*--------------------------------------------------------------------------------------
 [Function Name]: sevenSegmentSecondsDisplay
 [Description]:	This function is responsible to count and display the second's on 7-Segment's
 [Args]:   void
 [Return]: EN_StopWatch_Error_t
 ---------------------------------------------------------------------------------------*/
EN_StopWatch_Error_t sevenSegmentSecondsDisplay(void);

/*--------------------------------------------------------------------------------------
 [Function Name]: sevenSegmentMinutsDisplay
 [Description]:	This function is responsible to count and display the minut's on 7-Segment's
 [Args]:   void
 [Return]: EN_StopWatch_Error_t
 ---------------------------------------------------------------------------------------*/
EN_StopWatch_Error_t sevenSegmentMinutsDisplay(void);

/*--------------------------------------------------------------------------------------
 [Function Name]: sevenSegmentHoursDisplay
 [Description]:	This function is responsible to count and display the hours on 7-Segment's
 [Args]:   void
 [Return]: EN_StopWatch_Error_t
 ---------------------------------------------------------------------------------------*/
EN_StopWatch_Error_t sevenSegmentHoursDisplay(void);

/*--------------------------------------------------------------------------------------
 [Function Name]: sevenSegmentResetDisplay
 [Description]:	This function is responsible to Reset stopwatch on 7-Segment's
 [Args]:   void
 [Return]: void
 ---------------------------------------------------------------------------------------*/
void sevenSegmentResetDisplay(void);

/*--------------------------------------------------------------------------------------
 [Function Name]: sevenSegmentPauseDisplay
 [Description]:	This function is responsible to Pause stopwatch on 7-Segment's
 [Args]:   void
 [Return]: void
 ---------------------------------------------------------------------------------------*/
void sevenSegmentPauseDisplay(void);

/*--------------------------------------------------------------------------------------
 [Function Name]: sevenSegmentResumeDisplay
 [Description]:	This function is responsible to Resume stopwatch on 7-Segment's
 [Args]:   void
 [Return]: EN_StopWatch_Error_t
 ---------------------------------------------------------------------------------------*/
void sevenSegmentResumeDisplay(void);

#endif /* SRC_APP_STOPWATCH_H_ */
