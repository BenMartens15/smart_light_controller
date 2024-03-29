
#ifndef PWM_H
#define PWM_H

/* INCLUDES *******************************************************************/
#include <stdint.h>
/******************************************************************************/

/* DEFINES ********************************************************************/
#define DEVICE_TYPE_RGB_CONTROLLER 0
/******************************************************************************/

/* ENUMS **********************************************************************/
/******************************************************************************/

/* STRUCTURES *****************************************************************/
/******************************************************************************/

/* GLOBALS ********************************************************************/
/******************************************************************************/

/* PROTOTYPES *****************************************************************/
#if (CONFIG_DEVICE_TYPE == DEVICE_TYPE_RGB_CONTROLLER)
    void rgb_control_pwm_init();
    void rgb_control_set_colour(uint8_t * value);
#else
    static inline void rgb_control_pwm_init() { return; };
    static inline void rgb_control_set_colour(uint8_t * value) { return; };
#endif
/******************************************************************************/

#endif /* #ifndef PWM_H */
