/* ////////////////////////////////////////////////////////////////////////////////////////////////////
Name: Mohamed Abd Elfatah
File: SW.c
//////////////////////////////////////////////////////////////////////////////////////////////////// */

#include "Switch.h"
#include "../../Std_Types.h"



/// Define structure for grouping any info about switches.
typedef struct
{
    tSW_State sw_state;
}tSW_Info;

/* Switches info */
static tSW_Info SWs_Info[N_SWITCHES]     ;
tWord P_PressTime = 0                    ;

tSW_State SwitchState                    ;

/// pointer to switch get state fn , can be point to real get state or fake get state.
tSW_State (*SW_PointerToGetState) (tSW sw) ;



/**
 * Initialize switch with Released state.
 * @param[in] switch
 * @param[out] void
 */

void SW_Init(tSW sw)
{
    if( (sw > N_SWITCHES) && (sw < 0) )
    {
        return ;
    }
    switch(sw)
    {
     case SW_PLUS:
         SWs_Info[SW_PLUS].sw_state = SW_RELEASED  ;
         break ;
     case SW_MINUS :
         SWs_Info[SW_MINUS].sw_state = SW_RELEASED ;
         break ;
     case SW_P:
         SWs_Info[SW_P].sw_state = SW_RELEASED     ;
    default :
         break ;
    }
}

/**
 * Get switch state.
 * @param[in] switch
 * @param[out] state
 */

tSW_State SW_GetState(tSW sw)
{
    /* return sw state */
    if( (0 <= sw)  && (sw <= 2) )
    {
    return  SWs_Info[sw].sw_state ;
    }
    else
    {
       // Do nothing
    }
}


/**
 * Set switch state ( simulate H.W ).
 * @paramp[in] switch
 * @param [out] state
 */
void SW_SetState(tSW sw , tSW_State state)
{
    if( (sw > N_SWITCHES) && (sw < 0) && (state < 0) && (state > N_SWITCHES_STATES ) )
    {
        return ;
    }
      SWs_Info[sw].sw_state = state  ;
}


/**
 * Update switch state.
 * @param[in] void
 * @param[out] void
 */
void SW_Update(void)
{
           if( SW_GetState(SW_PLUS) == SW_PRE_PRESSED)
           {
               SWs_Info[SW_PLUS].sw_state = SW_PRE_PRESSED ;
           }

           if( SW_GetState(SW_MINUS) == SW_PRE_PRESSED)
           {
               SWs_Info[SW_MINUS].sw_state = SW_PRE_PRESSED ;
           }

           if( SW_GetState(SW_P) == SW_PRESSED)
           {
               SWs_Info[SW_P].sw_state = SW_PRESSED;
           }
           else{
            //do nothing
           }
}


/**
 * Set press time for P switch ( simulate H.W ) .
 * param[in] time
 * param [out] void
 */
void SW_PSetPressTime(tWord time)
{
    P_PressTime =  time*1000 ;
}

/**
 * Get press time for P switch .
 * @param[in] void
 * @param[out] void
 */
 tWord SW_PGetPressTime()
{
    return P_PressTime ;
}

