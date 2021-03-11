/* ////////////////////////////////////////////////////////////////////////////////////////////////////
Name: Mohamed Abd Elfatah
File: speedcontrol.h
//////////////////////////////////////////////////////////////////////////////////////////////////// */

/**
 * @file  speedControl.h
 * @author Mohamed Abd Elfatah
 * @brief File containing on defined types and prototypes for functions of speedControl Module
 *
 */
#ifndef SPEEDCONTROL_H_INCLUDED
#define SPEEDCONTROL_H_INCLUDED

#define N_SPEED_STATES 3 ///< States of speed control

#define SpeedControl_PERIOD_MS           (20)    ///<  Define speed control's update function period as 20 ms
#define P_PRESS_TIME_MS                  (30000) ///<  Define press time of P switch as 30 second

#define MAX_SPEED_ANGLE                  (10)  ///< Define angle of maximum speed state as 10 degree
#define MIN_SPEED_ANGLE                  (140) ///< Define angle of minimum speed state as 140 degree
#define MED_SPEED_ANGLE                  (90)  ///< Define angle of medium speed state as 90 degree

/// Define Type for speed control states
typedef enum
{
    MIN_SPEED = 0,
    MED_SPEED,
    MAX_SPEED
}tSpeedControl_Speed ;


/*Function Prototypes*/
/**
 * Initialize speed control with default speed as medium.
 * @param[in] void
 * @param[out] void
 */
void SpeedControl_Init(void)                           ;

/**
 * Get speed control state.
 * @param[in] void
 * @param[out] state of speed control
 */
tSpeedControl_Speed SpeedControl_GetSpeed(void)        ;

/**
 * Set speed control state.
 * @param[in] state of speed control
 * @param[out] void
 */
void SpeedControl_SetSpeed(tSpeedControl_Speed speed)  ;

/**
 * Update speed control.
 * @param[in] void
 * @param[out] void
 */

void SpeedControl_Update(void)                         ;

#endif // SPEEDCONTROL_H_INCLUDED


