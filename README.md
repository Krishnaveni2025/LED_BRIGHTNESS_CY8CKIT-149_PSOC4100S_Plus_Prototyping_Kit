# LED_BRIGHTNESS_CY8CKIT-149_PSOC4100S_Plus_Prototyping_Kit

# LED Brightness Control on CY8CKIT‑149 (PSoC 4100S Plus)

This project demonstrates how to control the brightness of an LED using **Pulse Width Modulation (PWM)** on the **CY8CKIT‑149 PSoC 4100S Plus Prototyping Kit**.  
The application is written in **bare‑metal C**, using **direct register access** to configure clocks, GPIO, and the TCPWM block.

The result is a smooth **breathing / fading LED effect**, where the LED gradually brightens and dims in a continuous loop.

---

## ✨ Features

### ✅ PWM Generation  
Uses the **TCPWM block (Timer 3)** to generate a PWM waveform.

### ✅ Clock Configuration  
Configures HFCLK and a **peripheral clock divider** to drive the PWM block.

### ✅ GPIO Routing  
Pin **P1.2** is configured as the PWM output using the **HSIOM** multiplexer.

### ✅ Brightness Control Loop  
The duty cycle is updated in software to create a smooth fade‑in / fade‑out effect.

---

## 🧰 Hardware Requirements
- CY8CKIT‑149 PSoC 4100S Plus Prototyping Kit  
- Micro‑USB cable  

---

## 🛠️ Software Requirements
- **Arm GNU Toolchain** (`arm-none-eabi-gcc`)  
- **OpenOCD** (for flashing)  
- **Make**  
- **VS Code** (optional but recommended)

Ensure the `path_name` environment variable is set correctly if your setup depends on it for locating OpenOCD.

---

## 📁 Project Structure

| File | Description |
|------|-------------|
| **main.c** | Initializes clocks, GPIO, PWM, and runs the brightness loop |
| **pwm.c** | Contains `led_init()`, `init_peri_Clock_Config()`, `pwm_init()`, `brightness_control()` |
| **pwm.h** | Function prototypes and PWM definitions |
| **psoc_startup.c** | Startup code + vector table |
| **psoclinker.ld** | Linker script defining memory layout |
| **Makefile** | Build, clean, flash, and erase commands |

---

## 🏗️ Build Instructions

### Build:
```
make all
```

Artifacts generated:
- `brightness_control.elf`
- `brightness_control.hex`
- object files of c source files

### Clean:
```
make clean
```

---

## 🔥 Flashing Instructions

Flash firmware:
```
make program
```

Mass erase:
```
make erase
```

---

## ⚙️ How It Works

### 1. **Clock Setup**
- HFCLK configured  
- Peripheral divider provides clock to TCPWM3  

### 2. **GPIO Routing**
- P1.2 is mapped to TCPWM3 output via HSIOM  

### 3. **PWM Configuration**
- Timer 3 configured in PWM mode  
- Period register defines PWM frequency  
- Compare register defines duty cycle  

### 4. **Brightness Loop**
- Duty cycle increases from 0 → 100  
- Then decreases from 100 → 0  
- Direction flips at boundaries  
- Software delay controls fade speed  

---

## 🎥 Demo Videos

- **led_brightness_controll.mp4** – Execution video (flashing + output)

  
https://github.com/user-attachments/assets/5a41c17e-0822-4a1c-9189-5eb2eeea05ab 
- **led_brightness.mp4** – Hardware breathing LED demo
https://github.com/user-attachments/assets/2f4ab491-74e6-4e53-916a-97ff0569ac39
---

## ✅ GitHub Repository  
https://github.com/Krishnaveni2025/LED_BRIGHTNESS_CY8CKIT-149_PSOC4100S_Plus_Prototyping_Kit

---







      
