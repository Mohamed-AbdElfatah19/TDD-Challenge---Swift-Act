/* ////////////////////////////////////////////////////////////////////////////////////////////////////
Name: Mohamed Abd Elfatah
File: SW.h
//////////////////////////////////////////////////////////////////////////////////////////////////// */

/**
 * @file switch.h
 * @author Mohamed Abd Elfatah
 * @brief File containing on defined types and prototypes for functions of switch Module
 *
 */
#ifndef SWITCH_H_INCLUDED
#define SWITCH_H_INCLUDED

#define SW_PERIOD_MS            (20)  ///< Define switch's update function period as 20 ms

#define N_SWITCHES               (3) ///< Number of switches in system
#define N_SWITCHES_STATES        (4) ///< Number of switch states

/// Define Type for switch
typedef enum
{
    SW_PLUS=0,
    SW_MINUS,
    SW_P
}tSW;

/// Define Type for switch states
typedef enum
{
    SW_RELEASED,
    SW_PRE_PRESSED,
    SW_PRESSED,
    SW_PRE_RELEASED
}tSW_State;

/**
 * Initialize switch with Released state.
 * @param[in] switch
 * @param[out] void
 */
void SW_Init(tSW sw)                       ;

/**
 * Get switch state.
 * @param[in] switch
 * @param[out] state
 */
extern tSW_State SW_GetState(tSW sw)       ;

/**
 * Update switch state.
 * @param[in] void
 * @param[out] void
 */
void SW_Update(void)                       ;

/**
 * Set switch state  ( simulate H.W ).
 * @param[in] switch
 * @param[out] state
 */
void SW_SetState(tSW sw , tSW_State state) ;

#endif // SWITCH_H_INCLUDED
