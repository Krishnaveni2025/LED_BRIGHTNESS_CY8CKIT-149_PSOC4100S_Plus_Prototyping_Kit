#include <stdint.h>
/* Timer period */
#define TIMER_PERIOD 10000U
void init_peri_Clock_Config(void);
#define CLK_SELECT 0x40030028

void hfclksel(void);
void led_init(void);
void pwm_init(void);
void brightness_control(void);