#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../source/motor/motor.h"
#include "../../source/speedControl/speedcontrol.h"
#include "../../source/switch/switch.h"
#include "../unity/unity_fixture.h"

/*************************************************************** Summary Of Motor Module - Test File **************************************************************
* NAME : Motor_Test.C
* NAME OF TEST GROUP : Motor
* NUMBER OF VALID TEST CASES :   - 1 for Motor_Init()
*                                - 2 for Motor_SetState()
*                                - 3 for Motor_SetAngle()
*                                - 4 for Motor_Update()
*
* NUMBER OF INVALID TEST CASES : - 2 for Motor_Init()
*                                - 2 for Motor_SetState()
*                                - 2 for Motor_SetAngle()
***************************************************************************************************************************************************************************/

TEST_GROUP(Motor);

TEST_SETUP(Motor)
{

}

TEST_TEAR_DOWN(Motor)
{

}
/*************************************************** Valid Test Cases *****************************************************************/
        /********************************** Initialization Function - Test Cases     **************************************/

 /**
		  * @par Given : Motor is in unknown state
		  * @par When  : Motor_Init() is called
		  * @par Then  : Motor is in off state
		  * Testing Technique : EP
  */
TEST( Motor , MotorStateIsOffAfterInit)
{
    Motor_Init(MOTOR_1)  ;

    LONGS_EQUAL( MOTOR_OFF , Motor_GetState(MOTOR_1)) ;
}
          /*************************************************  Setter Function - Test Cases **************************************************************/
  /**
		  * @par Given : Motor is in unknown state
		  * @par When  : Motor_SetState() is called
		  * @par Then  : Motor is in off state
		  * Testing Technique : EP
  */
TEST( Motor , SetMotorStateWithOff)
{

    Motor_SetState(MOTOR_1,MOTOR_OFF) ;

    LONGS_EQUAL( MOTOR_OFF , Motor_GetState(MOTOR_1)) ;
}

 /**
		  * @par Given : Motor is in unknown state
		  * @par When  : Motor_SetState() is called
		  * @par Then  : Motor is in on state
		  * Testing Technique : EP
  */
TEST( Motor , SetMotorStateWithON)
{

    Motor_SetState(MOTOR_1,MOTOR_ON) ;

    LONGS_EQUAL( MOTOR_ON , Motor_GetState(MOTOR_1)) ;
}

 /**
		  * @par Given : Motor is in unknown angle
		  * @par When  : Motor_SetAngle() is called
		  * @par Then  : Motor is in minimum angle
		  * Testing Technique : EP
  */
TEST(Motor , SetMotorAngleWithMinAngle)
{
    Motor_SetAngle(MOTOR_1, ANGLE_MIN) ;
    LONGS_EQUAL(ANGLE_MIN ,Motor_GetAngle(MOTOR_1)) ;
}

/**
		  * @par Given : Motor is in unknown angle
		  * @par When  : Motor_SetAngle() is called
		  * @par Then  : Motor is in meduim angle
		  * Testing Technique : EP
  */
TEST(Motor , SetMotorAngleWithMedAngle)
{
    Motor_SetAngle(MOTOR_1, ANGLE_MED) ;
    LONGS_EQUAL(ANGLE_MED ,Motor_GetAngle(MOTOR_1)) ;
}

/**
		  * @par Given : Motor is in unknown angle
		  * @par When  : Motor_SetAngle() is called
		  * @par Then  : Motor is in maximum angle
		  * Testing Technique : EP
  */
TEST(Motor , SetMotorAngleWithMaxAngle)
{
    Motor_SetAngle(MOTOR_1, ANGLE_MAX) ;

    LONGS_EQUAL(ANGLE_MAX ,Motor_GetAngle(MOTOR_1)) ;
}

/********************************* Update Function - Test Cases ***********************************************/

/**
		  * @par Given : Motor is initialized with off state
		  * @par When  : 1-Switch transition coverage : First Case ==> ( MED -> MIN -> MED -> MIN )
		  * @par Then  : Motor angle is in minimum angle
		  * Testing Technique : State Transition 1-switch coverage
  */
TEST( Motor , FirstCaseTestInSmBasedOnSmOfSpeedControl)
{
    Motor_Init(MOTOR_1);

    SpeedControl_SetSpeed(MIN_SPEED) ;
    Motor_Update() ;
    SpeedControl_SetSpeed(MED_SPEED) ;
    Motor_Update() ;
    SpeedControl_SetSpeed(MIN_SPEED) ;
    Motor_Update() ;

    LONGS_EQUAL(ANGLE_MIN , Motor_GetAngle(MOTOR_1)) ;
}

/**
		  * @par Given : Motor is initialized with off state
		  * @par When  : 1-Switch transition coverage : Second Case ==> ( MED -> MIN -> MED -> MAX )
		  * @par Then  : Motor angle is in maximum angle
		  * Testing Technique : State Transition 1-switch coverage
  */
TEST(Motor , SecondCaseTestInSmBasedOnSmOfSpeedControl)
{
    Motor_Init(MOTOR_1);

    SpeedControl_SetSpeed(MIN_SPEED) ;
    Motor_Update() ;
    SpeedControl_SetSpeed(MED_SPEED) ;
    Motor_Update() ;
    SpeedControl_SetSpeed(MAX_SPEED) ;
    Motor_Update() ;

    LONGS_EQUAL(ANGLE_MAX , Motor_GetAngle(MOTOR_1)) ;

}

/**
		  * @par Given : Motor is initialized with off state
		  * @par When  : 1-Switch transition coverage : Third Case ==> ( MED -> MAX -> MED -> MIN )
		  * @par Then  : Motor angle is in minimum angle
		  * Testing Technique : State Transition 1-switch coverage
  */
TEST(Motor , ThirdCaseTestInSmBasedOnSmOfSpeedControl)
{
    Motor_Init(MOTOR_1);

    SpeedControl_SetSpeed(MAX_SPEED) ;
    Motor_Update() ;
    SpeedControl_SetSpeed(MED_SPEED) ;
    Motor_Update() ;
    SpeedControl_SetSpeed(MIN_SPEED) ;
    Motor_Update() ;

    LONGS_EQUAL(ANGLE_MIN , Motor_GetAngle(MOTOR_1)) ;

}

/**
		  * @par Given : Motor is initialized with off state
		  * @par When  : 1-Switch transition coverage : Fourth Case ==> ( MED -> MAX -> MED -> MAX )
		  * @par Then  : Motor angle is in maximum angle
		  * Testing Technique : State Transition 1-switch coverage
  */
TEST(Motor , FourthCaseTestInSmBasedOnSmOfSpeedControl)
{
    Motor_Init(MOTOR_1);

    SpeedControl_SetSpeed(MAX_SPEED) ;
    Motor_Update() ;
    SpeedControl_SetSpeed(MED_SPEED) ;
    Motor_Update() ;
    SpeedControl_SetSpeed(MAX_SPEED) ;
    Motor_Update() ;

    LONGS_EQUAL(ANGLE_MAX , Motor_GetAngle(MOTOR_1)) ;

}

/******************************************************************** Invalid Test Cases ***************************************************************************************/
/**
		  * @par Given : Undefined motor type with value -1
		  * @par When  : Motor_Init() is called
		  * @par Then  : system ignore this case and don't initialize motor
		  * Testing Technique : EP
  */
TEST(Motor , UndefinedMotorNumberEnteredForInit)
{
    Motor_Init(-1);

    //LONGS_EQUAL(MOTOR_OFF , Motor_GetState) ;
    TEST_IGNORE_MESSAGE("This is undefined motor number (-1) is entered to Init fn") ;
}

/**
		  * @par Given : Undefined motor type with value 3
		  * @par When  : Motor_Init() is called
		  * @par Then  : system ignore this case and don't initialize motor
		  * Testing Technique : EP
  */
TEST(Motor , UndefinedMotorNumber3EnteredForInit)
{
    Motor_Init(3);

    //LONGS_EQUAL(MOTOR_OFF , Motor_GetState) ;
    TEST_IGNORE_MESSAGE("This is undefined motor number (3) is entered to Init fn") ;
}

/**
		  * @par Given : Undefined Motor State with value 2
		  * @par When  : Motor_SetState() is called
		  * @par Then  : system ignore this case and don't set motor  state
		  * Testing Technique : EP
  */
TEST( Motor , SetMotorStateWithUndefinedValue2)
{
    Motor_SetState(MOTOR_1,2) ;
    //LONGS_EQUAL( 2 , Motor_GetState(MOTOR_1)) ;
    TEST_IGNORE_MESSAGE(" This is undefined state for motor") ;

}

/**
		  * @par Given : Undefined Motor State with value -1
		  * @par When  : Motor_SetState() is called
		  * @par Then  : system ignore this case and don't set motor  state
		  * Testing Technique : EP
  */
TEST( Motor , SetMotorStateWithUndefinedValue)
{
    Motor_SetState(MOTOR_1,-1) ;
    //LONGS_EQUAL( -1 , Motor_GetState(MOTOR_1)) ;
    TEST_IGNORE_MESSAGE(" This is undefined state for motor") ;

}

/**
		  * @par Given : Undefined Motor Angle with value -10
		  * @par When  : Motor_Setangle() is called
		  * @par Then  : system ignore this case and don't set motor  angle
		  * Testing Technique : EP
  */
TEST(Motor , SetMotorAngleWithUndefinedAngleUnderZero)
{
    Motor_SetAngle(MOTOR_1,-10) ;

   // LONGS_EQUAL( -10, Motor_GetAngle(MOTOR_1)) ;

    TEST_IGNORE_MESSAGE("This is undefined angle (-10)")  ;
}

/**
		  * @par Given : Undefined Motor Angle with value 150
		  * @par When  : Motor_Setangle() is called
		  * @par Then  : system ignore this case and don't set motor  angle
		  * Testing Technique : EP
  */
TEST(Motor , SetMotorAngleWithUndefinedAngleGraeterThanMaxValue)
{
    Motor_SetAngle(MOTOR_1,150) ;

    //LONGS_EQUAL( 150, Motor_GetAngle(MOTOR_1)) ;

     TEST_IGNORE_MESSAGE("This is undefined angle (150) greater than defined max angle (140)")  ;
}



TEST_GROUP_RUNNER(Motor)
{
    printf("\n\n/*************************************************************** Motor - Module - Test Cases Result ***************************************************************/\n")    ;
    printf("\n...................................................................... Valid test cases for Init...................................................................\n")                    ;
    RUN_TEST_CASE( Motor , MotorStateIsOffAfterInit)                                                                        ;

     printf("\n.....................................................................Valid test cases for Set....................................................................\n");
    RUN_TEST_CASE( Motor , SetMotorStateWithOff)                     ;
    RUN_TEST_CASE( Motor , SetMotorStateWithON)                      ;
    RUN_TEST_CASE(Motor , SetMotorAngleWithMinAngle)                 ;
    RUN_TEST_CASE(Motor , SetMotorAngleWithMedAngle)                 ;
    RUN_TEST_CASE(Motor , SetMotorAngleWithMaxAngle)                 ;

    printf("\n.............................. Valid test cases for Update.......................................\n")              ;
    RUN_TEST_CASE( Motor , FirstCaseTestInSmBasedOnSmOfSpeedControl) ;
    RUN_TEST_CASE(Motor , SecondCaseTestInSmBasedOnSmOfSpeedControl) ;
    RUN_TEST_CASE(Motor , ThirdCaseTestInSmBasedOnSmOfSpeedControl)  ;
    RUN_TEST_CASE(Motor , FourthCaseTestInSmBasedOnSmOfSpeedControl) ;

         printf("\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> Invalid test cases for Set <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");
     RUN_TEST_CASE(Motor , UndefinedMotorNumberEnteredForInit) ;
     RUN_TEST_CASE(Motor , UndefinedMotorNumber3EnteredForInit);
     RUN_TEST_CASE( Motor , SetMotorStateWithUndefinedValue2)  ;
     RUN_TEST_CASE( Motor , SetMotorStateWithUndefinedValue);
     RUN_TEST_CASE(Motor , SetMotorAngleWithUndefinedAngleUnderZero);
     RUN_TEST_CASE(Motor , SetMotorAngleWithUndefinedAngleGraeterThanMaxValue);
}
