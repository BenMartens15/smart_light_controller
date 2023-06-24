
/* INCLUDES *******************************************************************/
#include <stdio.h>
#include "driver/ledc.h"
#include "esp_err.h"
#include "esp_log.h"
#include "rgb_control.h"
/******************************************************************************/

/* PROTOTYPES *****************************************************************/
/******************************************************************************/


/* GLOBALS ********************************************************************/
/******************************************************************************/


/* PRIVATE FUNCTIONS **********************************************************/
/******************************************************************************/


/* PUBLIC FUNCTIONS ***********************************************************/
void rgb_control_pwm_init()
{
    ESP_LOGI(PWM_TAG, "Create timer");
    // Prepare and then apply the LEDC PWM timer configuration
    ledc_timer_config_t ledc_timer = {
        .speed_mode       = LEDC_MODE,
        .timer_num        = LEDC_TIMER,
        .duty_resolution  = LEDC_DUTY_RES,
        .freq_hz          = LEDC_FREQUENCY,  // Set output frequency at 5 kHz
        .clk_cfg          = LEDC_AUTO_CLK
    };
    ESP_ERROR_CHECK(ledc_timer_config(&ledc_timer));

    ESP_LOGI(PWM_TAG, "Configure channels");
    // Prepare and then apply the LEDC PWM channel configuration
    ledc_channel_config_t red_pwm = {
        .speed_mode     = LEDC_MODE,
        .channel        = LEDC_CHANNEL_0,
        .timer_sel      = LEDC_TIMER,
        .intr_type      = LEDC_INTR_DISABLE,
        .gpio_num       = RED_CTRL_PIN,
        .duty           = 0, // Set duty to 0%
        .hpoint         = 0
    };

    ledc_channel_config_t green_pwm = {
        .speed_mode     = LEDC_MODE,
        .channel        = LEDC_CHANNEL_1,
        .timer_sel      = LEDC_TIMER,
        .intr_type      = LEDC_INTR_DISABLE,
        .gpio_num       = GREEN_CTRL_PIN,
        .duty           = 0, // Set duty to 0%
        .hpoint         = 0
    };

    ledc_channel_config_t blue_pwm = {
        .speed_mode     = LEDC_MODE,
        .channel        = LEDC_CHANNEL_2,
        .timer_sel      = LEDC_TIMER,
        .intr_type      = LEDC_INTR_DISABLE,
        .gpio_num       = BLUE_CTRL_PIN,
        .duty           = 0, // Set duty to 0%
        .hpoint         = 0
    };
    ESP_ERROR_CHECK(ledc_channel_config(&red_pwm));
    ESP_ERROR_CHECK(ledc_channel_config(&green_pwm));
    ESP_ERROR_CHECK(ledc_channel_config(&blue_pwm));
}

void rgb_control_set_colour(uint8_t * value)
{
    ledc_set_duty(LEDC_MODE, LEDC_CHANNEL_0, value[0]);
    ledc_update_duty(LEDC_MODE, LEDC_CHANNEL_0);

    ledc_set_duty(LEDC_MODE, LEDC_CHANNEL_1, value[1]);
    ledc_update_duty(LEDC_MODE, LEDC_CHANNEL_1);

    ledc_set_duty(LEDC_MODE, LEDC_CHANNEL_2, value[2]);
    ledc_update_duty(LEDC_MODE, LEDC_CHANNEL_2);
}
/******************************************************************************/ 