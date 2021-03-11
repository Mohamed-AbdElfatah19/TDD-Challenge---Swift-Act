#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../source/switch/switch.h"
#include "../unity/unity_fixture.h"

/*************************************************************** Summary Of Switch Module - Test File **************************************************************
* NAME : SW_Test.C
* NAME OF TEST GROUP : SwitchState
* NUMBER OF VALID TEST CASES :   - 3 for SW_Init()
*                                - 4 for SW_SetState()
*
* NUMBER OF INVALID TEST CASES : - 2 for SW_Init()
*                                - 2 for SW_SetState()
*******************************************************************************************************************************************************************/

TEST_GROUP(SwitchState) ;

TEST_SETUP(SwitchState)
{

}

TEST_TEAR_DOWN(SwitchState)
{

}
/*************************************************** Valid Test Cases *****************************************************************/
        /********************************** Initialization Function - Test Cases     **************************************/

 /**
		  * @par Given : Plus switch is in unknown state
		  * @par When  : SW_Init() is called
		  * @par Then  : Plus switch is in released state
		  * Testing Technique : EP
  */
TEST( SwitchState , Plus_SwitchIsReleasedAfterInit)
{
    SW_Init(SW_PLUS)  ;

    LONGS_EQUAL( SW_RELEASED , SW_GetState(SW_PLUS) ) ;

}

/**
		  * @par Given : Minus switch is in unknown state
		  * @par When  : SW_Init() is called
		  * @par Then  : Minus switch is in released state
		  * * Testing Technique : EP
  */

TEST( SwitchState , Minus_SwitchIsReleasedAfterInit)
{
    SW_Init(SW_MINUS)  ;

    LONGS_EQUAL( SW_RELEASED , SW_GetState(SW_MINUS) ) ;

}

/**
		  * @par Given : P switch is in unknown state
		  * @par When  : SW_Init() is called
		  * @par Then  : P switch is in released state
		  * Testing Technique : EP
  */
TEST( SwitchState , P_SwitchIsReleasedAfterInit)
{
    SW_Init(SW_P)  ;

    LONGS_EQUAL( SW_RELEASED , SW_GetState(SW_P) ) ;

}

          /*********************************  Setter Function - Test Cases *******************************************/

 /**
		  * @par Given : Plus switch released state
		  * @par When  : SW_SetState() is called
		  * @par Then  : Plus switch is in state that are selected in set fn
		  * Testing Technique : EP
  */
TEST(SwitchState , SetPlusSwitchState)
{
    SW_Init(SW_PLUS)  ;

    SW_SetState( SW_PLUS , SW_PRE_PRESSED) ;

    LONGS_EQUAL( SW_PRE_PRESSED , SW_GetState(SW_PLUS) ) ;
}

/**
		  * @par Given : Minus switch released state
		  * @par When  : SW_SetState() is called
		  * @par Then  : Minus switch is in state that are selected in set fn
		  * Testing Technique : EP
  */
TEST(SwitchState , SetMinusSwitchState)
{
    SW_Init(SW_MINUS)  ;

    SW_SetState( SW_MINUS , SW_PRE_PRESSED) ;

    LONGS_EQUAL( SW_PRE_PRESSED , SW_GetState(SW_MINUS) ) ;
}

/**
		  * @par Given : P switch released state
		  * @par When  : SW_SetState() is called
		  * @par Then  : P switch is in state that are selected in set fn
		  * Testing Technique : EP
  */
TEST(SwitchState , SetPSwitchState)
{
    SW_Init(SW_P)  ;

    SW_SetState( SW_P , SW_PRE_PRESSED) ;

    LONGS_EQUAL( SW_PRE_PRESSED , SW_GetState(SW_P) ) ;
}

/**
		  * @par Given : Plus switch released state
		  * @par When  : SW_SetState() is called and it's state is PreReleased
		  * @par Then  : Plus switch is in PreReleased state
		  * Testing Technique : EP
  */
TEST( SwitchState , SetPlusSwitchStateWithPreReleased)
{
    SW_Init(SW_PLUS)  ;

    SW_SetState( SW_PLUS , SW_PRE_RELEASED) ;

    LONGS_EQUAL( SW_PRE_RELEASED , SW_GetState(SW_PLUS) ) ;


}
/*  Note : Get Function is already Tested successfully during running another test cases for init , set , update functions  */


/*************************************************** Invalid Test Cases *****************************************************************/

/**
		  * @par Given : undefined switch number with value = 3
		  * @par When  : SW_Init() is called
		  * @par Then  : uninitialized this switch and system ignore this case
		  * Testing Technique : EP
  */
TEST( SwitchState , UndefinedSwitchNumberEquals3IsEnteredForInit)
{
    SW_Init(3);

    //LONGS_EQUAL( SW_RELEASED , SW_GetState(3));
    TEST_IGNORE_MESSAGE("This is undefined switch number (3) is entered to Init fn") ;
}

/**
		  * @par Given : undefined switch number with value = -1
		  * @par When  : SW_Init() is called
		  * @par Then  : uninitialized this switch and system ignore this case
		  * Testing Technique : EP
  */
TEST( SwitchState , UndefinedSwitchNumberEnteredForInit)
{
    SW_Init(-1);

    //LONGS_EQUAL( SW_RELEASED , SW_GetState(-1));
    TEST_IGNORE_MESSAGE("This is undefined switch number (-1) is entered to Init fn") ;
}

/**
		  * @par Given : undefined switch number with value = 3
		  * @par When  : SW_SetState() is called
		  * @par Then  : system ignore this case and don't set switch
		  * Testing Technique : EP
  */
TEST( SwitchState , UndefinedSwitchNumberEquals3IsEnteredForSet)
{
    SW_SetState(3,SW_PRESSED);

    //LONGS_EQUAL( SW_PRESSED , SW_GetState(3));
    TEST_IGNORE_MESSAGE("This is undefined switch number (3) is entered to Set fn") ;
}

/**
		  * @par Given : undefined switch number with value = -1
		  * @par When  : SW_SetState() is called
		  * @par Then  : system ignore this case and don't set switch \
		  * Testing Technique : EP
  */
TEST( SwitchState , UndefinedSwitchNumberEnteredForSet)
{
    SW_SetState(-1,SW_PRESSED);

    //LONGS_EQUAL( SW_PRESSED , SW_GetState(-1));
    TEST_IGNORE_MESSAGE("This is undefined switch number (-1) is entered to Set fn") ;
}




TEST_GROUP_RUNNER(SwitchState)
{
    printf("\n\n/*********************************************************** Switch - Module - Test Cases Result ***********************************************************/\n") ;
    printf("\n.........................................................Valid test cases for Init .........................................................................\n")    ;                        ;
    RUN_TEST_CASE(  SwitchState , Plus_SwitchIsReleasedAfterInit )      ;
    RUN_TEST_CASE(  SwitchState , Minus_SwitchIsReleasedAfterInit )     ;
    RUN_TEST_CASE(  SwitchState , P_SwitchIsReleasedAfterInit )         ;

    printf("\n......................................................... Valid test cases for Set...........................................................................\n")  ;
    RUN_TEST_CASE(  SwitchState , SetPlusSwitchState )                  ;
    RUN_TEST_CASE(  SwitchState , SetMinusSwitchState )                 ;
    RUN_TEST_CASE(  SwitchState , SetPSwitchState )                     ;
    RUN_TEST_CASE(  SwitchState , SetPlusSwitchStateWithPreReleased) ;

     printf("\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> Invalid test cases for Set <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");
    RUN_TEST_CASE( SwitchState , UndefinedSwitchNumberEquals3IsEnteredForInit)   ;
    RUN_TEST_CASE( SwitchState , UndefinedSwitchNumberEnteredForInit)   ;
    RUN_TEST_CASE( SwitchState , UndefinedSwitchNumberEquals3IsEnteredForSet);
    RUN_TEST_CASE( SwitchState , UndefinedSwitchNumberEnteredForSet) ;
}

