#include <stdio.h>
#include <string.h>
#include "motor.h"
#include "../speedControl/speedControl.h"
#include "../../Std_Types.h"




/// Define structure for grouping any info about motors ( state , angle ).
typedef struct
{
 tMotor_State Motor_State ;
 tMotor_Angle Motor_Angle ;
}tMotor_Info ;

/// array of defined structure of number of motors.
static tMotor_Info Motors_Info[N_MOTORS]  ;


/**
 * Initialize motor with off state and medium angle.
 * @param[in] motor type
 * @param[out] void
 */
void Motor_Init(tMotor Motor)
{
     if( (Motor > N_MOTORS) || (Motor < 0) )
     {
         return ;
     }
     Motors_Info[Motor].Motor_State = MOTOR_OFF  ;
     Motors_Info[Motor].Motor_Angle = ANGLE_MED  ;
}


/**
 * Set motor state ( off, on ).
 * @param[in] motor , state
 * @param[out] void
 */
void Motor_SetState(tMotor Motor , tMotor_State State)
{
    if( (Motor > N_MOTORS) || (State > 1) || (State < 0) )
    {
        return ;
    }
    Motors_Info[Motor].Motor_State = State  ;
}


/**
 * Set motor angle ( med , min , max).
 * @param[in] motor , angle
 * @param[out] void
 */
void Motor_SetAngle(tMotor Motor , tMotor_Angle Angle)
{
    if( (Motor > N_MOTORS) || (Angle < 0) || (Angle > MAX_DEFINED_ANGLE_VALUE))
    {
        return ;
    }
    Motors_Info[Motor].Motor_Angle = Angle ;
}

/**
 * Update motor state.
 * @param[in] void
 * @param[out] void
 */
void Motor_Update()
{
    tByte Motor_idx=0                ;


        /* update motor angel based on speed control module output */
       for( Motor_idx=0 ; Motor_idx < N_MOTORS ; Motor_idx++)
       {
            if( SpeedControl_GetSpeed() == MED_SPEED )
            {
                  Motor_SetAngle( Motor_idx , ANGLE_MED );
            }
            else if( SpeedControl_GetSpeed() == MIN_SPEED )
            {
                Motor_SetAngle( Motor_idx , ANGLE_MIN );
            }
            else if( SpeedControl_GetSpeed() == MAX_SPEED )
            {
               Motor_SetAngle( Motor_idx , ANGLE_MAX );
            }
            else{
                /* Do nothing*/
            }

        }



}


/**
 * Get motor state.
 * @param[in] motor
 * @param[out] state
 */
tMotor_State Motor_GetState(tMotor Motor)
{
    return Motors_Info[Motor].Motor_State ;
}


/**
 * Get motor angle.
 * @param[in] motor
 * @param[out] angle
 */
tMotor_Angle Motor_GetAngle(tMotor Motor)
{
    return Motors_Info[Motor].Motor_Angle ;
}

