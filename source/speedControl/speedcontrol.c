#include "SpeedControl.h"
#include "../switch/switch.h"
#include "../../Std_Types.h"

static tSpeedControl_Speed currentSpeed ;



/**
 * Initialize speed control with default speed as medium.
 * @param[in] void
 * @param[out] void
 */
void SpeedControl_Init(void)
{
 /* initialize Speed Control */
   currentSpeed  = MED_SPEED ;
}

/**
 * Get speed control state.
 * @param[in] void
 * @param[out] state of speed control
 */
tSpeedControl_Speed SpeedControl_GetSpeed(void)
{
    return currentSpeed   ;
}


/**
 * Set speed control state.
 * @param[in] state of speed control
 * @param[out] void
 */
void SpeedControl_SetSpeed(tSpeedControl_Speed speed)
{
    if( (speed <0) || (speed >= N_SPEED_STATES) )
      {
          return ;
      }

    currentSpeed = speed   ;

}

//check the switches states
//update the speed ,based on the state machine concept
//apply a switch case control flow
        /*
     * If (+) is pre=pressed & speed is not max, speed increases by 1 step
     * If (-) is pre=pressed & speed is not min, speed decreases by 1 step
     * If(P) is pressed & press time == 30 seconds & speed is not min, speed decreases by 1 step.
     */

 /**
 * Update speed control.
 * @param[in] void
 * @param[out] void
 */
void SpeedControl_Update(void)
{
     /*update the target speed , based on the switches states*/
     for( tByte Index = SW_PLUS ; Index < N_SWITCHES ; Index++ )
     {

         switch( Index )
         {
         case SW_PLUS:
            if( SW_GetState(SW_PLUS) == SW_PRE_PRESSED)
            {
                SW_SetState(SW_PLUS , SW_RELEASED ) ;
                if( currentSpeed == MAX_SPEED )
                {
                    continue ;
                }
                currentSpeed = MAX_SPEED  ;

            }
            break   ;

         case SW_MINUS:
            if( SW_GetState(SW_MINUS) == SW_PRE_PRESSED)
            {
                SW_SetState(SW_MINUS , SW_RELEASED ) ;
                if( currentSpeed == MIN_SPEED)
                {
                    continue ;
                }
                currentSpeed = MIN_SPEED ;
            }
            break ;

         case SW_P:
            if(SW_GetState(SW_P) == SW_PRESSED)
            {
                 //SW_PSetPressTime(30)             ;
                 SW_SetState(SW_P , SW_RELEASED ) ;
                if( SW_PGetPressTime() != P_PRESS_TIME_MS)
                {
                    return ;
                }

                if( currentSpeed == MIN_SPEED)
                {
                   return ;
                }
                currentSpeed = MED_SPEED ;
            }
            break ;

         default:

            break ;
         }
     }
}
