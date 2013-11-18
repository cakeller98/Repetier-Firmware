#ifndef PINS_H
#define PINS_H

/*
The board assignment defines the capabilities of the motherboard and the used pins.
Each board definition follows the following scheme:

CPU_ARCH
  ARCH_AVR for AVR based boards
  ARCH_ARM for all arm based boards

STEPPER_CURRENT_CONTROL
  CURRENT_CONTROL_MANUAL  1  // mechanical poti, default if not defined
  CURRENT_CONTROL_DIGIPOT 2  // Use a digipot like RAMBO does
  CURRENT_CONTROL_LTC2600 3  // Use LTC2600 like Foltyn 3D Master

*/


#define ARCH_AVR 1
#define ARCH_ARM 2

#define CURRENT_CONTROL_MANUAL  1  // mechanical poti, default if not defined
#define CURRENT_CONTROL_DIGIPOT 2  // Use a digipot like RAMBO does
#define CURRENT_CONTROL_LTC2600 3  // Use LTC2600 like Foltyn 3D Master

/****************************************************************************************
* Arduino Mega pin assignment
*
****************************************************************************************/

#if MOTHERBOARD == 33
#define MOTHERBOARD 3
#define RAMPS_V_1_3
#elif MOTHERBOARD == 34
#define MOTHERBOARD 3
#define RAMPS_V_1_3
#define AZTEEG_X3
#endif
#if MOTHERBOARD == 3
#define KNOWN_BOARD 1

//////////////////FIX THIS//////////////
#ifndef __AVR_ATmega1280__
#ifndef __AVR_ATmega2560__
#error Oops!  Make sure you have 'Arduino Mega' selected from the 'Tools -> Boards' menu.
#endif
#endif

// uncomment one of the following lines for RAMPS v1.3 or v1.0, comment both for v1.2 or 1.1
#define RAMPS_V_1_3

// RAMPS_V_1_3
#ifdef RAMPS_V_1_3

#define X_STEP_PIN         54
#define X_DIR_PIN          55
#define X_ENABLE_PIN       38
#define X_MIN_PIN          -1 // 3
#define X_MAX_PIN          3  // 2

#define Y_STEP_PIN         60
#define Y_DIR_PIN          61
#define Y_ENABLE_PIN       56
#define Y_MIN_PIN          -1 // ck 14
#define Y_MAX_PIN          14 // ck 15

#define Z_STEP_PIN         46
#define Z_DIR_PIN          48
#define Z_ENABLE_PIN       62
#define Z_MIN_PIN          -1 // ck 18
#define Z_MAX_PIN          18 // ck 19

#define E0_STEP_PIN         26
#define E0_DIR_PIN          28
#define E0_ENABLE_PIN       24

#define E1_STEP_PIN         36
#define E1_DIR_PIN          34
#define E1_ENABLE_PIN       30

// ck #define E2_STEP_PIN         27  // Only available with X3 shield
// ck #define E2_DIR_PIN          29  // Only available with X3 shield
// ck #define E2_ENABLE_PIN       41  // Only available with X3 shield

// ck //#define E3_STEP_PIN         23  // Only available with X3 shield
// ck //#define E3_DIR_PIN          25  // Only available with X3 shield
// ck //#define E3_ENABLE_PIN       40  // Only available with X3 shield

#define SDPOWER            -1
#define SDSS               53
#define SDCARDDETECT 	   -1 // ck 49

#define LED_PIN            6 // ck 13
#define FAN_PIN            4 // ck 9
#define PS_ON_PIN          12
#define KILL_PIN           -1

#define HEATER_0_PIN       10 // ck EXT0
#define HEATER_1_PIN       8  // ck Bed
#define HEATER_2_PIN       9  // ck EXT1

#define TEMP_0_PIN         13   // ck EXT0 ANALOG NUMBERING
#define TEMP_1_PIN         14   // ck Bed ANALOG NUMBERING
#define TEMP_2_PIN         15   // ck EXT1

#define E0_PINS E0_STEP_PIN,E0_DIR_PIN,E0_ENABLE_PIN,
#define E1_PINS E1_STEP_PIN,E1_DIR_PIN,E1_ENABLE_PIN,

#endif // RAMPS_V_1_3

// SPI for Max6675 Thermocouple

// these pins are defined in the SD library if building with SD support
#define SCK_PIN          52
#define MISO_PIN         50
#define MOSI_PIN         51
#define MAX6675_SS       53

#ifdef AZTEEG_X3
#define SDSUPPORT true
#define SDCARDDETECTINVERTED false
#define SDCARDDETECT -1
#define FAN_PIN           4
#define FAN2_PIN          5
#define LIGHT_PIN         6
#define BEEPER_PIN        33  // Activate beeper on extension shield
#define BEEPER_TYPE        1

#define E2_STEP_PIN         27  // Only available with X3 shield
#define E2_DIR_PIN          29  // Only available with X3 shield
#define E2_ENABLE_PIN       41  // Only available with X3 shield
#define E3_STEP_PIN         23  // Only available with X3 shield
#define E3_DIR_PIN          25  // Only available with X3 shield
#define E3_ENABLE_PIN       40  // Only available with X3 shield
#define HEATER_3_PIN        16  // ck 17 Only available with X3 shield
#define TEMP_3_PIN          5   // ck 12 Only available with X3 shield
// #define HEATER_4_PIN        17 // ck 16 Only available with X3 shield
// #define TEMP_4_PIN          12 // ck 5 // Only available with X3 shield


#define E1_PINS E1_STEP_PIN,E1_DIR_PIN,E1_ENABLE_PIN,
#define E2_PINS E2_STEP_PIN,E2_DIR_PIN,E2_ENABLE_PIN,
#define E3_PINS E3_STEP_PIN,E3_DIR_PIN,E3_ENABLE_PIN,

#endif // AZTEEG_X3
#endif // Arduino Mega pin assignment

/* END Arduino Mega pin assignment */

#ifndef CPU_ARCH  // Set default architecture
#define CPU_ARCH ARCH_AVR
#endif

#ifndef SDSSORIG
#define SDSSORIG -1
#endif

#ifndef STEPPER_CURRENT_CONTROL // Set default stepper current control if not set yet.
#define STEPPER_CURRENT_CONTROL  CURRENT_CONTROL_MANUAL
#endif

#ifndef FAN_BOARD_PIN
#define FAN_BOARD_PIN -1
#endif

#if NUM_EXTRUDER==1
#define E1_PINS
#endif

#if NUM_EXTRUDER<3
#define E2_PINS
#endif
#define SENSITIVE_PINS {0, 1, X_STEP_PIN, X_DIR_PIN, X_ENABLE_PIN, X_MIN_PIN, X_MAX_PIN, Y_STEP_PIN, Y_DIR_PIN, Y_ENABLE_PIN, Y_MIN_PIN, Y_MAX_PIN, Z_STEP_PIN, Z_DIR_PIN, Z_ENABLE_PIN, Z_MIN_PIN, Z_MAX_PIN, LED_PIN, PS_ON_PIN, \
                        HEATER_0_PIN, HEATER_1_PIN, FAN_PIN, E0_PINS E1_PINS E2_PINS TEMP_0_PIN, TEMP_1_PIN,SDSS }
#endif

