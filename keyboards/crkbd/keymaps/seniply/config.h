#pragma once

#define MASTER_LEFT
// #define MASTER_RIGHT

#define USE_SERIAL
// #define USE_I2C

#define TAPPING_TERM 200
#define ONESHOT_TAP_TOGGLE 2
#define ONESHOT_TIMEOUT 5000

#ifdef RGB_MATRIX_ENABLE
#   define RGB_MATRIX_KEYPRESSES // reacts to keypresses
// #   define RGB_MATRIX_KEYRELEASES // reacts to keyreleases (instead of keypresses)
#   define RGB_MATRIX_FRAMEBUFFER_EFFECTS
#   define RGB_DISABLE_AFTER_TIMEOUT 0 // number of ticks to wait until disabling effects
#   define RGB_DISABLE_WHEN_USB_SUSPENDED // turn off effects when suspended
#   define RGB_MATRIX_HUE_STEP 8
#   define RGB_MATRIX_SAT_STEP 8
#   define RGB_MATRIX_VAL_STEP 8
#   define RGB_MATRIX_SPD_STEP 10
#endif
