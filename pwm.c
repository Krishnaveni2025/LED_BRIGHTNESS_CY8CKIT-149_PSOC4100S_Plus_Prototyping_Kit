#include "pwm.h"

volatile uint32_t *cs_register = (volatile uint32_t *)CLK_SELECT;

void brightness_control(void)
{
    static int16_t brightness = 0;
    static int16_t step = 20;
    volatile int32_t i;


    brightness += step;

    if (brightness >= 10000)
    {
        brightness = 10000;
        step = -20; // Start decrementing
    }
    else if (brightness <= 0)
    {
        brightness = 0;
        step = 20; // Start incrementing
    }

    *((uint32_t *)0x402001CC) = brightness; // Update Compare Register

    /* Simple delay loop */
    for (i = 0; i < 5000; i++);
}
void led_init(void)
{
    /*GPIO pin init*/
    *((uint32_t *)0x40040100) = (1 << 2); // Set default output value of P1.2 to 1 GPIO_PRT1_DR
    *((uint32_t *)0x40040108) = (6 << 6); // Set drive mode of P1.2 to Digital OP Push Pull GPIO_PRT1_PC
    *((uint32_t *)0x40020100) = (8 << 8); // Assign GPIO to PWM output by selecting the MUX in HSIOM_PORT_SEL1 Register
}
/*Peripheral clock initilizations*/
void init_peri_Clock_Config()
{
    // TIMER 3 PWM- CLOCK
    *((uint32_t *)0x40010000) = (1 << 30) | (1 << 6) | (0 << 0); // Disable the Divider 0 using PERI_DIV_CMD

    *((uint32_t *)0x40010300) = (24 - 1) << 8; // Set the divider value in PERI_DIV_16_CTL0, We are configuring Divider 0

    *((uint32_t *)0x40010000) |= (1 << 31) | (3 << 14) | (63 << 8) | (1 << 6) | (0 << 0); // PERI_DIV_CMD
    // Enable the divder 31:bit, Keep 3 at 15:14 and 63 13:8 this selects the HFCLK as reference , Select 16 bit divider 7:6, and Select the divider number 0 using 5:0

    *((uint32_t *)0x40010124) = (1 << 6) | (0 << 0); // Specify Divider type 7:6 and Selected Divider 3:0 (Divider 0) in register PERI_PCLK_CTL9 TCPWM3 is PERIPHERAL 9
}
void pwm_init(void)
{
    /*TIMER 3 - PWM - INIT*/
    *((uint32_t *)0x40200000) &= ~(1 << 3); // Disable Timer 3  in TCPWM_CTRL Register

    *((uint32_t *)0x402001C8) = 0; // Clear the counter register of  TCPWM3 TCPWM_CNT3_COUNTER Register

    *((uint32_t *)0x402001E8) = 0x31; // Setting Line out behaviour in CC_MATCH_MODE and OVERFLOW_MODE in  TCPWM3 TCPWM_CNT3_TR_CTRL2 Register

    *((uint32_t *)0x402001D4) = (TIMER_PERIOD - 1); // Set the Period Register of TCPWM3 TCPWM_CNT3_PERIOD Register

    *((uint32_t *)0x402001CC) = 0; // Compare register TCPWM3, TCPWM_CNT3_CC Regsiter set to 0 initially

    *((uint32_t *)0x402001C0) |= (4 << 24) | (1 << 3); // Mode (PWM Mode) configuration,Continuous mode by default Bit position 18, and PWM_STOP_ON_KILL of for TCPWM3, TCPWM_CNT3_CTRL Regsiter

    *((uint32_t *)0x40200000) |= (1 << 3); // Enable Timer 3  in TCPWM_CTRL Register

    *((uint32_t *)0x40200008) |= (1 << 11); // Reload trigger in TCPWM_CMD Register
}
void hfclksel(void)
{
    // Set the clock select register to use the high-frequency clock
    *cs_register = 0 << 3; //[3:2] 0 - no divider ; 1- divide by 2; 2- divide by 4(default); 3- divide by 8; source selection[1:0]0-IMO(default); 1-EXTCLK; 2-ECO
}