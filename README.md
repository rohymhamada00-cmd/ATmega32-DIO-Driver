# ATmega32 Drivers & Embedded Systems Projects (MCAL & HAL Layers)

A comprehensive, modular, and scalable collection of microcontroller drivers built for the **ATmega32** (AVR architecture), written in standard Embedded C following professional architectural standards like Layered Architecture.

---

## 🚀 Features & Highlights

* **Layered Architecture:** Strict separation between Application layer, Hardware Abstraction Layer (HAL), and Microcontroller Abstraction Layer (MCAL).
* **Robust Error Handling:** MCAL and HAL APIs utilize error status enums (`DIO_OK`, `DIO_NOK`) to handle invalid inputs safely.
* **NULL Pointer Checks:** Validates output pointers before dereferencing to prevent memory faults.
* **Configurable Hardware:** Dynamic struct-based configurations for hardware peripherals like 7-Segment displays.
* **Full Bitwise Control:** Comprehensive low-level and high-level control for digital I/O, LEDs, and multiplexed displays.

---

## 📁 Directory Structure

```text
├── APPLICATIONS/
│   ├── LED.c                   # LED application test cases
│   ├── LED_TEST.c              # LED test implementation
│   └── SSD_TEST.c              # 00-99 Multiplexing 7-Segment counter test
├── HAL/
│   ├── LED_driver/
│   │   ├── LED_configuration.h # LED pre-build configurations
│   │   ├── LED_interface.h     # LED public APIs & types
│   │   ├── LED_private.h       # LED private definitions
│   │   └── LED_programe.c      # LED implementation logic
│   └── SSD_driver/
│       ├── SSD_configuration.h # SSD configurations
│       ├── SSD_interface.h     # SSD public APIs & structs
│       ├── SSD_private.h       # SSD look-up tables & private logic
│       └── SSD_programe.c      # SSD implementation logic
├── LIB/
│   ├── BIT_MATH.h              # Bit-manipulation macros
│   └── STD_TYPES.h             # Standard type definitions (U8, etc.)
├── MCAL/
│   └── DIO_1/
│       ├── DIO_configure.h     # DIO pin configurations
│       ├── DIO_interface.h     # DIO public APIs & declarations
│       ├── DIO_private.h       # ATmega32 Register memory maps
│       └── DIO_programe.c      # DIO API implementations
├── Simulation/
│   ├── LED_TEST.pdsprj         # Proteus simulation for LED
│   └── SSD_TEST.pdsprj         # Proteus simulation for 7-Segment Multiplexing
├── Snapshots/
│   ├── LED_driver_snapshot.jpg # LED simulation preview
│   ├── SSD_snapshot.jpg        # 7-Segment simulation preview
│   └── circuit_simulation.png  # General circuit overview
└── README.md

```
## 🔌 API Overview

```c
/* Pin Control APIs */
DIO_ErrorStatus DIO_voidSetPinDirection (U8 Copy_U8PORT, U8 Copy_U8PIN, U8 Copy_U8Direction);
DIO_ErrorStatus DIO_voidSetvalue        (U8 Copy_U8PORT, U8 Copy_U8PIN, U8 Copy_U8Value);
DIO_ErrorStatus DIO_voidTogglePinValue  (U8 Copy_U8PORT, U8 Copy_U8PIN);
DIO_ErrorStatus DIO_GetValue            (U8 Copy_U8PORT, U8 Copy_U8PIN, U8* Copy_U8Value);

/* Port Control APIs */
DIO_ErrorStatus DIO_voidSetPortDirection(U8 Copy_U8PORT, U8 Copy_U8Direction);
DIO_ErrorStatus DIO_voidSetPortValue    (U8 Copy_U8PORT, U8 Copy_U8Value);
DIO_ErrorStatus DIO_enumTogglePortValue (U8 Copy_u8PORT);
DIO_ErrorStatus DIO_GetPortValue        (U8 Copy_U8PORT, U8* Copy_u8Value);

```
### 💻 Tech Stack
Language: Embedded C
Target Controller: Microchip ATmega32 (AVR)
Toolchain: AVR-GCC / Eclipse IDE / Proteus Simulation

👨‍💻 Author
Eng. Mohamed Elnashar
