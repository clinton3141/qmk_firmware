/*
This is the c configuration file for the keymap

Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#ifdef OLED_ENABLE
    #define OLED_BRIGHTNESS .3
#endif

#define MOUSEKEY_MAX_SPEED 2
#define MOUSEKEY_TIME_TO_MAX 20

#define RGB_MATRIX_TIMEOUT 10000

//#define USE_MATRIX_I2C

#define TAPPING_TERM 200
#define PERMISSIVE_HOLD
#define QUICK_TAP_TERM 120

#ifdef RGB_MATRIX_ENABLE
#   define RGB_MATRIX_SLEEP // turn off effects when suspended
#   define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_SOLID_COLOR
#   define RGB_MATRIX_DEFAULT_HUE 0
#   define RGB_MATRIX_DEFAULT_SAT 0
#   define RGB_MATRIX_DEFAULT_VAL 0
#   define RGB_DISABLE_WHEN_USB_SUSPENDED
#   undef RGB_MATRIX_ALPHAS_MODS
#   undef RGB_MATRIX_GRADIENT_UP_DOWN
#   undef RGB_MATRIX_GRADIENT_LEFT_RIGHT
#   undef RGB_MATRIX_BREATHING
#   undef RGB_MATRIX_BAND_SAT
#   undef RGB_MATRIX_BAND_VAL
#   undef RGB_MATRIX_BAND_PINWHEEL_SAT
#   undef RGB_MATRIX_BAND_PINWHEEL_VAL
#   undef RGB_MATRIX_BAND_SPIRAL_SAT
#   undef RGB_MATRIX_BAND_SPIRAL_VAL
#   undef RGB_MATRIX_CYCLE_ALL
#   undef RGB_MATRIX_CYCLE_LEFT_RIGHT
#   undef RGB_MATRIX_CYCLE_UP_DOWN
#   undef RGB_MATRIX_RAINBOW_MOVING_CHEVRON
#   undef RGB_MATRIX_CYCLE_OUT_IN
#   undef RGB_MATRIX_CYCLE_OUT_IN_DUAL
#   undef RGB_MATRIX_CYCLE_PINWHEEL
#   undef RGB_MATRIX_CYCLE_SPIRAL
#   undef RGB_MATRIX_DUAL_BEACON
#   undef RGB_MATRIX_RAINBOW_BEACON
#   undef RGB_MATRIX_RAINBOW_PINWHEELS
#   undef RGB_MATRIX_RAINDROPS
#   undef RGB_MATRIX_JELLYBEAN_RAINDROPS
#   undef RGB_MATRIX_SOLID_REACTIVE_SIMPLE
#   undef RGB_MATRIX_SOLID_REACTIVE
#   undef RGB_MATRIX_SOLID_REACTIVE_WIDE
#   undef RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE
#   undef RGB_MATRIX_SOLID_REACTIVE_CROSS
#   undef RGB_MATRIX_SOLID_REACTIVE_MULTICROSS
#   undef RGB_MATRIX_SOLID_REACTIVE_NEXUS
#   undef RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS
#   undef RGB_MATRIX_SPLASH
#   undef RGB_MATRIX_MULTISPLASH
#   undef RGB_MATRIX_SOLID_SPLASH
#   undef RGB_MATRIX_SOLID_MULTISPLASH
#   undef RGB_MATRIX_TYPING_HEATMAP
#   undef RGB_MATRIX_DIGITAL_RAIN
#   undef RGB_MATRIX_SOLID_REACTIVE_SIMPLE
#   undef RGB_MATRIX_SOLID_REACTIVE_WIDE
#   undef RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE
#   undef RGB_MATRIX_SOLID_REACTIVE_CROSS
#   undef RGB_MATRIX_SOLID_REACTIVE_MULTICROSS
#   undef RGB_MATRIX_SOLID_REACTIVE_NEXUS
#   undef RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS
#   undef RGB_MATRIX_HUE_BREATHING
#   undef RGB_MATRIX_HUE_PENDULUM
#   undef RGB_MATRIX_HUE_WAVE
#   undef RGB_MATRIX_PIXEL_FRACTAL
#   undef RGB_MATRIX_PIXEL_FLOW
#   undef RGB_MATRIX_PIXEL_RAIN
#endif

// Enable split transport syncing for RGB matrix, modifiers, and layer state
#define SPLIT_RGB_MATRIX_ENABLE
#define SPLIT_MODS_ENABLE
#define SPLIT_LAYER_STATE_ENABLE
