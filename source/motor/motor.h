/* ////////////////////////////////////////////////////////////////////////////////////////////////////
Name: Mohamed Abd Elfatah
File: motor.h
//////////////////////////////////////////////////////////////////////////////////////////////////// */
/**
 * @file motor.h
 * @author Mohamed Abd Elfatah
 * @brief File containing on defined types and prototypes for functions of Motor Module
 *
 */
#ifndef MOTOR_H_INCLUDED
#define MOTOR_H_INCLUDED


#define N_MOTORS  1  ///<  number of motors in system

#define MOTOR_PERIOD_MS               (10) ///< Define Motor's update function period as 10 ms
#define N_MOTORS_ANGLES               (3)  ///< Define number of Motor's angles
#define MAX_DEFINED_ANGLE_VALUE       (140) ///< Define max value of angle for motor


/// Define Type for motor
typedef enum{
  MOTOR_1
}tMotor ;

/// Define Type for motor states
typedef enum
{
    MOTOR_OFF =0 ,
    MOTOR_ON
}tMotor_State ;

/// Define Type for motor angles
typedef enum
{
 ANGLE_MIN = 140 ,
 ANGLE_MED = 90 ,
 ANGLE_MAX = 10
}tMotor_Angle ;


/**
 * Initialize motor with off state and medium angle.
 * @param[in] motor type
 * @param[out] void
 */
void Motor_Init(tMotor Motor)   ;

/**
 * Set motor state ( off, on ).
 * @param[in] motor , state
 * @param[out] void
 */
void Motor_SetState(tMotor Motor , tMotor_State State);

/**
 * Set motor angle ( med , min , max).
 * @param[in] motor , angle
 * @param[out] void
 */
void Motor_SetAngle(tMotor motor , tMotor_Angle Angle) ;

/**
 * Get motor state.
 * @param[in] motor
 * @param[out] state
 */
tMotor_State Motor_GetState(tMotor Motor) ;

/**
 * Get motor angle.
 * @param[in] motor
 * @param[out] angle
 */
tMotor_Angle Motor_GetAngle(tMotor Motor) ;

/**
 * Update motor state.
 * @param[in] void
 * @param[out] void
 */
void Motor_Update() ;


#endif // MOTOR_H_INCLUDED
