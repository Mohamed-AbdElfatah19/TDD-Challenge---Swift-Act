#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../source/switch/switch.h"
#include  "../../source/speedControl/speedControl.h"
#include "../unity/unity_fixture.h"

/*************************************************************** Summary Of Speed Control Module - Test File **************************************************************
* NAME : SpeedControl_Test.C
* NAME OF TEST GROUP : SpeedControl
* NUMBER OF VALID TEST CASES :   - 1 for SpeedControl_Init()
*                                - 3 for SpeedControl_SetSpeed()
*                                - 4 for SpeedControl_Update()
*
* NUMBER OF INVALID TEST CASES : - 2 for SpeedControl_SetSpeed()
***************************************************************************************************************************************************************************/

TEST_GROUP(SpeedControl)  ;

TEST_SETUP(SpeedControl)
{

}

TEST_TEAR_DOWN(SpeedControl)
{

}

/******************************************************************** Valid Test Cases ************************************************************************************************/
        /********************************************************* Initialization Function - Test Cases     ****************************************************************/
/**
		  * @par Given : Speed is in unknown state
		  * @par When  : SpeedControl_Init() is called
		  * @par Then  : SpeedControl is in medium state
		  * Testing Technique : EP
  */
TEST( SpeedControl , SpeedIsMedAfterInit)
{

   SpeedControl_Init() ;

   LONGS_EQUAL( MED_SPEED , SpeedControl_GetSpeed() )  ;
}
       /*************************************************************  Setter Function - Test Cases *************************************************************************/

 /**
		  * @par Given : Speed is initialized with medium state
		  * @par When  : SpeedControl_SetSpeed() is called and is set to max speed
		  * @par Then  : SpeedControl is in maximum state
		  * Testing Technique : EP
  */
TEST(SpeedControl , SetSpeedWithMaxSpeed)
{
   SpeedControl_Init();

   SpeedControl_SetSpeed( MAX_SPEED)    ;

   LONGS_EQUAL( MAX_SPEED , SpeedControl_GetSpeed()) ;
}


 /**
		  * @par Given : Speed is initialized with medium state
		  * @par When  : SpeedControl_SetSpeed() is called and is set to min speed
		  * @par Then  : SpeedControl is in minimum state
		  * Testing Technique : EP
  */
TEST(SpeedControl , SetSpeedWithMinSpeed)
{
    SpeedControl_Init();

   SpeedControl_SetSpeed( MIN_SPEED)    ;

   LONGS_EQUAL( MIN_SPEED , SpeedControl_GetSpeed() ) ;
}

/**
		  * @par Given : Speed is in unknown state
		  * @par When  : SpeedControl_SetSpeed() is called and is set to med speed
		  * @par Then  : SpeedControl is in meduim state
		  * Testing Technique : EP
  */
TEST(SpeedControl , SetSpeedWithMedSpeed)
{
   SpeedControl_SetSpeed( MED_SPEED)    ;

   LONGS_EQUAL( MED_SPEED , SpeedControl_GetSpeed() ) ;
}

       /******************************************************* Update Function - Test Cases   *******************************************************************************/

 /**
		  * @par Given : Speed is initialized with medium state
		  * @par When  : 1-Switch transition coverage : First Case ==> ( MED -> MIN -> MED -> MIN )
		  * @par Then  : SpeedControl is in minimum state
		  * Testing Technique : State Transition 1-switch coverage
  */

TEST(SpeedControl , FirstCaseTestInSM)
{
    SpeedControl_Init() ;

    SW_SetState(SW_P , SW_PRESSED ) ;
    SpeedControl_Update() ;
    SW_SetState(SW_PLUS , SW_PRE_PRESSED) ;
    SpeedControl_Update() ;
    SW_SetState(SW_MINUS, SW_PRE_PRESSED) ;
    SpeedControl_Update() ;

    LONGS_EQUAL( MIN_SPEED , SpeedControl_GetSpeed() ) ;

}

/**
		  * @par Given : Speed is initialized with medium state
		  * @par When  : 1-Switch transition coverage : Second Case ==> ( MED -> MIN -> MED -> MAX )
		  * @par Then  : SpeedControl is in maximum state
		  * Testing Technique : State Transition 1-switch coverage
  */
TEST(SpeedControl , SecondCaseTestInSM)
{
    SpeedControl_Init() ;

    SW_SetState(SW_P , SW_PRESSED ) ;
    SpeedControl_Update() ;
    SW_SetState(SW_PLUS , SW_PRE_PRESSED) ;
    SpeedControl_Update() ;
    SW_SetState(SW_PLUS, SW_PRE_PRESSED) ;
    SpeedControl_Update() ;

    LONGS_EQUAL( MAX_SPEED , SpeedControl_GetSpeed() ) ;

}

/**
		  * @par Given : Speed is initialized with medium state
		  * @par When  : 1-Switch transition coverage : Third Case ==> ( MED -> MAX -> MED -> MIN )
		  * @par Then  : SpeedControl is in minimum state
		  * Testing Technique : State Transition 1-switch coverage
  */

TEST(SpeedControl , ThirdCaseTestInSM)
{
    SpeedControl_Init() ;

    SW_SetState(SW_PLUS , SW_PRESSED ) ;
    SpeedControl_Update() ;
    SW_SetState(SW_MINUS, SW_PRE_PRESSED) ;
    SpeedControl_Update() ;
    SW_SetState(SW_MINUS, SW_PRE_PRESSED) ;
    SpeedControl_Update() ;

    LONGS_EQUAL( MIN_SPEED , SpeedControl_GetSpeed() ) ;
}

/**
		  * @par Given : Speed is initialized with medium state
		  * @par When  : 1-Switch transition coverage : Fourth Case ==> ( MED -> MAX -> MED -> MAX )
		  * @par Then  : SpeedControl is in maximum state
		  * Testing Technique : State Transition 1-switch coverage
  */
TEST( SpeedControl , FourthCaseTestInSM)
{
    SpeedControl_Init() ;

    SW_SetState(SW_PLUS , SW_PRE_PRESSED ) ;
    SpeedControl_Update() ;

    SW_SetState(SW_MINUS, SW_PRE_PRESSED) ;
    SpeedControl_Update() ;

    SW_SetState(SW_PLUS , SW_PRE_PRESSED) ;
    SpeedControl_Update() ;

    LONGS_EQUAL( MAX_SPEED , SpeedControl_GetSpeed() ) ;

}

/***************************************************************** Invalid Test Cases *****************************************************************************/

/**
		  * @par Given : Undefined Speed State with value -1
		  * @par When  : SpeedControl_SetSpeed() is called
		  * @par Then  : system ignore this case and don't set speed state
		  * Testing Technique : EP
  */
TEST( SpeedControl , SetSpeedWithUndefinedState)
{
    SpeedControl_SetSpeed(-1) ;

    //LONGS_EQUAL( -1 , SpeedControl_GetSpeed()) ;
    TEST_IGNORE_MESSAGE("This is undefined switch number (-1) is entered to Set fn") ;
}

/**
		  * @par Given : Undefined Speed State with value 3
		  * @par When  : SpeedControl_SetSpeed() is called
		  * @par Then  : system ignore this case and don't set speed state
		  * Testing Technique : EP
  */
TEST( SpeedControl , SetSpeedWithUndefinedStateWithValue3)
{
    SpeedControl_SetSpeed(3) ;

    // LONGS_EQUAL( 3 , SpeedControl_GetSpeed()) ;
    TEST_IGNORE_MESSAGE("This is undefined switch number (3) is entered to Set fn") ;
}



TEST_GROUP_RUNNER(SpeedControl)
{
        printf("\n\n/************************************************** Speed Control - Module - Test Cases Result **********************************************************/\n") ;

    printf("\n............................................................Valid test cases for Init....................................................................\n")                         ;
    RUN_TEST_CASE( SpeedControl , SpeedIsMedAfterInit)                         ;

    printf("\n............................................................Valid test cases for Set.....................................................................\n")                       ;
    RUN_TEST_CASE(SpeedControl , SetSpeedWithMaxSpeed)                         ;
    RUN_TEST_CASE(SpeedControl , SetSpeedWithMinSpeed)                         ;
    RUN_TEST_CASE(SpeedControl , SetSpeedWithMedSpeed)                         ;

    printf("\n...............................................................Valid test cases for Update...............................................................\n")                           ;
    RUN_TEST_CASE(SpeedControl , FirstCaseTestInSM)                            ;
    RUN_TEST_CASE(SpeedControl , SecondCaseTestInSM)                           ;
    RUN_TEST_CASE(SpeedControl , ThirdCaseTestInSM)                            ;
    RUN_TEST_CASE( SpeedControl , FourthCaseTestInSM)                          ;

    printf("\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> Invalid test cases for Set <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");
    RUN_TEST_CASE( SpeedControl , SetSpeedWithUndefinedState)                     ;
    RUN_TEST_CASE( SpeedControl , SetSpeedWithUndefinedStateWithValue3)           ;
}

