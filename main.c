#include"pwm.h"
int main()
{
    /* HF CLOCK divider init*/
    hfclksel(); // 0 - No Divider, 1 - DIV by 2, 2 = DIV by 4, 3 = DIV by 8
    /* Peripheral clock initialization*/
    init_peri_Clock_Config();
    /* LED GPIO initialization*/
    led_init();
    /* PWM initialization*/
    pwm_init();
    /* Brightness control function*/
    while(1)
    {
        brightness_control();
    }
    return 0;
}
