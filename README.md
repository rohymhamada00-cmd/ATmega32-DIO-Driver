# ATmega32 DIO (GPIO) Driver

A fully modular and highly configurable **MCAL (Microcontroller Abstraction Layer)** Digital Input/Output (DIO) Driver written in C for the **ATmega32** microcontroller. 

Designed following Layered Architecture principles for Embedded Systems to ensure code reusability, safety, and readability.

---

## 🛠️ Features & Highlights

* **Layered Architecture:** Clear separation between Application, MCAL, and Hardware layers.
* **Robust Error Handling:** Functions utilize `DIO_ErrorStatus` enum (`DIO_OK`, `DIO_NOK`) to handle invalid inputs safely.
* **Pointer Safety:** Includes `NULL` pointer checks to prevent crashes when reading pin or port values.
* **Full Bitwise Control:** Comprehensive APIs for setting pin/port directions, setting pin/port states, reading values, and toggling pin states.

---

## 📁 Directory Structure

```text
├── MCAL/
│   └── DIO_1/
│       ├── DIO_configure.h   # Driver configurations
│       ├── DIO_interface.h   # Public APIs & type declarations
│       ├── DIO_private.h     # Register memory maps
│       └── DIO_programe.c    # API Implementations
├── LIB/
│   ├── BIT_MATH.h            # Bit-manipulation macros
│   └── STD_TYPES.h           # Standard type definitions (u8, etc.)
├── APPLICATIONS/
│   └── LED.c                 # Application test cases
└── README.md

```
### 🔌 API Overview

```c
/* Pin Control APIs */
DIO_ErrorStatus DIO_enumSetPinDirection(u8 Copy_u8PORT, u8 Copy_u8PIN, u8 Copy_u8Direction);
DIO_ErrorStatus DIO_enumSetPinValue(u8 Copy_u8PORT, u8 Copy_u8PIN, u8 Copy_u8Value);
DIO_ErrorStatus DIO_enumGetPinValue(u8 Copy_u8PORT, u8 Copy_u8PIN, u8* Copy_pu8Value);
DIO_ErrorStatus DIO_enumTogglePinValue(u8 Copy_u8PORT, u8 Copy_u8PIN);

/* Port Control APIs */
DIO_ErrorStatus DIO_enumSetPortDirection(u8 Copy_u8PORT, u8 Copy_u8Direction);
DIO_ErrorStatus DIO_enumSetPortValue(u8 Copy_u8PORT, u8 Copy_u8Value);
DIO_ErrorStatus DIO_enumGetPortValue(u8 Copy_u8PORT, u8* Copy_pu8Value);
DIO_ErrorStatus DIO_enumTogglePortValue(u8 Copy_u8PORT);
```


```
### 💻 Tech Stack

Language: Embedded C

Target Controller: Microchip ATmega32

Toolchain: AVR-GCC / Eclipse IDE
```
