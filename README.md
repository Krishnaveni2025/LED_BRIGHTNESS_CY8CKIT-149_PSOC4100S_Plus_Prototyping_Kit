# LED_BRIGHTNESS_CY8CKIT-149_PSOC4100S_Plus_Prototyping_Kit


# LED Brightness Control on CY8CKIT-149 PSoC 4100S Plus Prototyping Kit

## Description
This project demonstrates how to control the brightness of an LED using Pulse Width Modulation (PWM) on the CY8CKIT-149 PSoC 4100S Plus Prototyping Kit. The application is written in bare-metal C, utilizing direct register access to configure the device's resources.

The program creates a "breathing" or fading effect where the LED gradually brightens and then dims in a continuous loop.

## Functionality
- **PWM Generation**: Uses the PSoC 4 TCPWM (Timer, Counter, PWM) block (specifically Timer 3) to generate a PWM signal.
- **Clocking**: Configures the high-frequency clock (HFCLK) and a peripheral clock divider to drive the PWM block.
- **GPIO**: Configures Pin **P1.2** (connected to a user LED on the kit) as the PWM output.
- **Control Loop**: Continuously updates the PWM compare value in a loop to change the duty cycle, creating the fading effect.

## Hardware Requirements
- **CY8CKIT-149 PSoC 4100S Plus Prototyping Kit**
- Micro-USB cable for power and programming.

## Software Prerequisites
- **Arm GNU Toolchain**: `arm-none-eabi-gcc` and related tools must be in your PATH.
- **OpenOCD**: For flashing the firmware to the device.
- **Make**: For running the build scripts.
- **Visual Studio Code** (Optional): A recommended editor for viewing and editing the code.

## Environment Setup
Ensure you have the `path_name` environment variable set, pointing to your course or tools directory if your setup relies on it (specifically for locating OpenOCD).

## Project Structure
- `main.c`: Main entry point. Initializes clocks, GPIO, and PWM, then enters the brightness control loop.
- `pwm.c`: Contains the implementation for:
  - `led_init()`: Configures P1.2 as a digital output driven by the TCPWM block.
  - `init_peri_Clock_Config()`: Sets up the peripheral clock divider for the PWM.
  - `pwm_init()`: Configures TCPWM3 for PWM mode.
  - `brightness_control()`: Updates the PWM duty cycle to simulate brightness changes.
- `pwm.h`: Header file for PWM functions and definitions.
- `psoc_startup.c`: Startup code and interrupt vector table.
- `psoclinker.ld`: Linker script defining memory layout.
- `Makefile`: Directives for compiling, linking, and flashing the project.

## Build Instructions
To build the project, open a terminal in the project directory and run:

```bash
make
```

This will compile the source files and generate the following artifacts:
- `brightness_control.elf`: The executable linkable format file.
- `brightness_control.hex`: The hex file used for flashing.

To clean the build artifacts:

```bash
make clean
```

## Flashing Instructions
To flash the compiled firmware onto the PSoC 4100S Plus kit, ensure the board is connected via USB and run:

```bash
make program
```

This command uses OpenOCD to program the `.hex` file onto the device.

To perform a mass erase of the device:

```bash
make erase
```

## How It Works
1.  **Clock Setup**: The system clock is configured, and a peripheral clock divider is set up to provide a clock source to the TCPWM block.
2.  **GPIO Routing**: Pin P1.2 is configured to be driven by the TCPWM block via the High-Speed I/O Matrix (HSIOM).
3.  **PWM Configuration**: Timer 3 is configured in PWM mode with a specific period.
4.  **Main Loop**:
    - The `brightness` variable determines the PWM compare value (duty cycle).
    - In each iteration, `brightness` is incremented or decremented by a fixed step.
    - When `brightness` reaches the maximum (10000) or minimum (0), the direction changes.
    - A simple software delay (loop) controls the speed of the fading effect.

https://github.com/user-attachments/assets/5a41c17e-0822-4a1c-9189-5eb2eeea05ab



https://github.com/user-attachments/assets/2f4ab491-74e6-4e53-916a-97ff0569ac39


      
