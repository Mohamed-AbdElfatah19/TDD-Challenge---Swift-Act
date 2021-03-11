/* ////////////////////////////////////////////////////////////////////////////////////////////////////
Name: Mohamed Abd Elfatah
File: main.c
//////////////////////////////////////////////////////////////////////////////////////////////////// */

#include <stdio.h>
#include <stdlib.h>

#include "source/switch/switch.h"
#include "source/speedControl/speedcontrol.h"
#include "source/motor/motor.h"

#include "test/unity/unity_fixture.h"
#define MAKE_UNITY_VERBOSE	argc = 2; argv[1] = "-v"

#define N_INPUT_TEST_CASES 5       ///< number of input test cases

void GetTestData(void)             ;
void SystemInit()                  ;
void SystemUpdate(void)            ;




/* Test Groups Runner */
 void RunAllTests(void)
{
    RUN_TEST_GROUP(SwitchState)    ;
    RUN_TEST_GROUP(SpeedControl)   ;
    RUN_TEST_GROUP(Motor)          ;
}

/***************************************************************************** main function ***************************************************************************************************/
/**********************************************************************************************************************************************************************************************
************************************************************************************************************************************************************************************************/
/*
 * 1- call unity main to run all test cases
 * 2- initialize system
 * 3- get test data ( switches states )
 */
int main(int argc, char * argv[])
{



    /* Manipulate argc & argv to make unity verbose*/
    /* You can use CodeBlocks Command Line inputs to do the same */
    MAKE_UNITY_VERBOSE;

    /* Call Unity Main */
    UnityMain(argc, argv, RunAllTests);

    GetTestData() ;

    printf("\n...... TDD Challenge ......\n");
    return 0;
}
/**********************************************************************************************************************************************************************************************
************************************************************************************************************************************************************************************************/
/*************************************************************************** Initialization Modules ******************************************************************************************/
void SystemInit()
{
    SW_Init(SW_PLUS) ;
    SW_Init(SW_MINUS) ;
    SW_Init(SW_P) ;

    SpeedControl_Init() ;
    Motor_Init(MOTOR_1)   ;
}
/**********************************************************************************************************************************************************************************************
************************************************************************************************************************************************************************************************/
/**************************************************************************  Update Modules *************************************************************************************************/
void SystemUpdate(void)
{
    SW_Update() ;
    SpeedControl_Update() ;
    Motor_Update() ;
}
/**********************************************************************************************************************************************************************************************
************************************************************************************************************************************************************************************************/
/********************************************************************** Get Test Data Function **********************************************************************************************/
void GetTestData()
{
    FILE *fSwitches = fopen("Switches.txt","r+")    ;
    FILE *fMotor = fopen("Motor.txt","w")           ;

    char strs[3][20] ;
    int P_time ;

    if(fSwitches)
    {

            for(int i=0 ; i < N_INPUT_TEST_CASES ; i++ )
            {
            memset(strs[0],0,20);
            memset(strs[1],0,20);
            memset(strs[2],0,20);
            fscanf(fSwitches, "%s\t%s\t%s\t%d\n",strs[0], strs[1], strs[2],&P_time);
            SystemInit();
            for(int idx=0 ; idx < 3 ; idx++)
            {
                if(idx == 0)
                {
                    if( !strcmp(strs[0] , "SW_RELEASED") )
                    {
                        SW_SetState(SW_PLUS,SW_RELEASED)      ;
                    }
                    else if( !strcmp(strs[0] , "SW_PREPRESSED") )
                    {
                        SW_SetState(SW_PLUS,SW_PRE_PRESSED)   ;
                    }
                    else if( !strcmp(strs[0] , "SW_PRESSED"))
                    {
                        SW_SetState(SW_PLUS,SW_PRESSED)       ;
                    }
                    else if (!strcmp(strs[0] , "SW_PREPRESSED"))
                    {
                        SW_SetState(SW_PLUS,SW_PRE_PRESSED)   ;
                    }
                    continue ;
                }
                if(idx == 1)
                {

                    if( !strcmp(strs[1] , "SW_RELEASED"))
                    {
                        SW_SetState(SW_MINUS,SW_RELEASED)      ;
                    }
                    else if( !strcmp(strs[1] , "SW_PREPRESSED"))
                    {
                        SW_SetState(SW_MINUS,SW_PRE_PRESSED)   ;
                    }
                    else if( !strcmp(strs[1] , "SW_PRESSED"))
                    {
                        SW_SetState(SW_MINUS,SW_PRESSED)       ;
                    }
                    else if (!strcmp(strs[1] , "SW_PREPRESSED"))
                    {
                        SW_SetState(SW_PLUS,SW_PRE_PRESSED)   ;
                    }
                    continue ;
                }
                if(idx == 2)
                {
                    if(!strcmp(strs[2] , "SW_RELEASED"))
                    {
                        SW_SetState(SW_P,SW_RELEASED)      ;
                    }
                    else if( !strcmp(strs[2], "SW_PREPRESSED"))
                    {
                        SW_SetState(SW_P,SW_PRE_PRESSED)   ;
                    }
                    else if( !strcmp(strs[2] , "SW_PRESSED"))
                    {
                        SW_SetState(SW_P,SW_PRESSED)       ;
                    }
                    else if (!strcmp(strs[2] , "SW_PREPRESSED"))
                    {
                        SW_SetState(SW_P,SW_PRE_PRESSED)   ;
                    }
                    continue ;
                }
            }
            SW_PSetPressTime(P_time)              ;
            SystemUpdate()                        ;

            fprintf(fMotor  ," Motor Angle = %d\n" , Motor_GetAngle(MOTOR_1))  ;
             //printf("%d\t",Motor_GetAngle(MOTOR_1))  ;
        }
    }
   //printf("%d\n",P_time) ;
   //printf("\n%s\n",strs[0]);
  // printf("%s\n",strs[1]);
  // printf("%s\n",strs[2]);

    fclose(fSwitches) ;
    fclose(fMotor) ;

}
