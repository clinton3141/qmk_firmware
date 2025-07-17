/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

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

#include QMK_KEYBOARD_H

enum layers {
    _BASE,
    _NUMS,
    _MODS_NAV,
    _MEDIA,
    _FNS
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_ESC,           KC_Q,             KC_W,             KC_F,             KC_P,             KC_B,                         KC_J,             KC_L,             KC_U,             KC_Y,             KC_SCLN,          KC_BSLS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TAB,           LSFT_T(KC_A),     LCTL_T(KC_R),     LALT_T(KC_S),     LGUI_T(KC_T),     KC_G,                         KC_M,             RGUI_T(KC_N),     RALT_T(KC_E),     RCTL_T(KC_I),     RSFT_T(KC_O),     KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_GRAVE,         KC_Z,             KC_X,             KC_C,             KC_D,             KC_V,                         KC_K,             KC_H,             KC_COMM,          KC_DOT,           KC_SLSH,          KC_BSLS,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                                          MO(_MEDIA),       KC_SPC,           MO(_MODS_NAV),    LT(_NUMS, KC_ENT), KC_LSFT,          KC_BSPC
                                                      //`--------------------------'  `--------------------------'
    ),

    [_NUMS] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______,          KC_EXLM,          KC_AT,            KC_HASH,          KC_DLR,           KC_PERC,                      KC_CIRC,          KC_AMPR,          KC_ASTR,          KC_LPRN,          KC_RPRN,          _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______,          KC_1,             KC_2,             KC_3,             KC_4,             KC_5,                         KC_6,             KC_7,             KC_8,             KC_9,             KC_0,             KC_GT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______,          KC_UNDS,          KC_MINS,          KC_PLUS,          KC_EQL,           XXXXXXX,                      TO(_FNS),         KC_LCBR,          KC_RCBR,          KC_LBRC,          KC_RBRC,          KC_LT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                                          _______,          _______,          _______,          _______,          _______,          _______
                                                      //`--------------------------'  `--------------------------'
    ),

    [_MODS_NAV] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______,          XXXXXXX,          LCMD(KC_MINUS),   LCMD(KC_KP_0),    LCMD(KC_EQUAL),   XXXXXXX,                      XXXXXXX,          LCTL(KC_MINUS),   KC_UP,            LCTL(LSFT(KC_MINUS)),KC_PAGE_UP,       XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______,          OSM(MOD_LSFT),    OSM(MOD_LCTL),    OSM(MOD_LALT),    OSM(MOD_LGUI),    XXXXXXX,                      KC_TAB,           KC_LEFT,          KC_DOWN,          KC_RIGHT,            KC_PAGE_DOWN,     XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______,          LCMD(KC_Z),       LCMD(KC_X),       LCMD(KC_C),       XXXXXXX,          LCMD(KC_V),                   KC_GRAVE,         KC_LCBR,          KC_RCBR,          KC_LBRC,             KC_RBRC,          XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                                          _______,          _______,          _______,          _______,          _______,          _______
                                                      //`--------------------------'  `--------------------------'
    ),

    [_MEDIA] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,                      XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,                      KC_MPRV,          KC_MPLY,          KC_MNXT,          XXXXXXX,          XXXXXXX,          XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,                      KC_VOLD,          KC_MUTE,          KC_VOLU,          XXXXXXX,          XXXXXXX,          XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                                          _______,          _______,          _______,          _______,          _______,          _______
                                                      //`--------------------------'  `--------------------------'
    ),

    [_FNS] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      TO(_BASE),        KC_F9,            KC_F10,           KC_F11,           KC_F12,           XXXXXXX,                      QK_RGB_MATRIX_TOGGLE, QK_RGB_MATRIX_VALUE_DOWN, QK_RGB_MATRIX_VALUE_UP, XXXXXXX, XXXXXXX,          XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX,          KC_F5,            KC_F6,            KC_F7,            KC_F8,            XXXXXXX,                      XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX,          KC_F1,            KC_F2,            KC_F3,            KC_F4,            XXXXXXX,                      XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                                          _______,          _______,          _______,          _______,          _______,          _______
                                                      //`--------------------------'  `--------------------------'
    )
};

// Chordal Hold: Define handedness for opposite-hands rule
const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM =
    LAYOUT_split_3x6_3(
        'L', 'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R', 'R',
        'L', 'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R', 'R',
        'L', 'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R', 'R',
                   'L', 'L', 'L',      'R', 'R', 'R'
    );

#ifdef RGB_MATRIX_ENABLE

static uint8_t global_brightness = 128;

bool is_gui_held(void) {
    return (get_oneshot_mods() | get_mods()) & MOD_MASK_GUI;
}

bool is_shift_held(void) {
    return (get_oneshot_mods() | get_mods()) & MOD_MASK_SHIFT;
}

bool is_ctrl_held(void) {
    return (get_oneshot_mods() | get_mods()) & MOD_MASK_CTRL;
}

bool is_alt_held(void) {
    return (get_oneshot_mods() | get_mods()) & MOD_MASK_ALT;
}

void set_led_with_brightness(uint8_t led_min, uint8_t led_max, uint8_t led, uint8_t r, uint8_t g, uint8_t b) {
    // TODO: this only affects the master side of the board
    RGB_MATRIX_INDICATOR_SET_COLOR(led,
        (r * global_brightness) / 255,
        (g * global_brightness) / 255,
        (b * global_brightness) / 255);
}

void keyboard_post_init_user(void) {
    rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
    rgb_matrix_sethsv_noeeprom(HSV_OFF);
}

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    uint8_t layer_r = 0, layer_g = 0, layer_b = 0;

    if (layer_state_is(_BASE)) {
        layer_r = 0x20; layer_g = 0x20; layer_b = 0x40; // Dim blue
    } else if (layer_state_is(_NUMS)) {
        layer_r = 0x20; layer_g = 0x40; layer_b = 0x20; // Dim green
    } else if (layer_state_is(_MODS_NAV)) {
        layer_r = 0x40; layer_g = 0x20; layer_b = 0x20; // Dim red
    } else if (layer_state_is(_MEDIA)) {
        layer_r = 0x40; layer_g = 0x20; layer_b = 0x40; // Dim magenta
    } else if (layer_state_is(_FNS)) {
        layer_r = 0x40; layer_g = 0x40; layer_b = 0x20; // Dim yellow
    }

    for (uint8_t i = 0; i < RGB_MATRIX_LED_COUNT; i++) {
        set_led_with_brightness(led_min, led_max, i, layer_r, layer_g, layer_b);
    }

    if (is_shift_held()) {
        set_led_with_brightness(led_min, led_max, 22, 0xFF, 0x00, 0x00);
        set_led_with_brightness(led_min, led_max, 49, 0xFF, 0x00, 0x00);
        set_led_with_brightness(led_min, led_max, 40, 0xFF, 0x00, 0x00);
    }

    if (is_ctrl_held()) {
        set_led_with_brightness(led_min, led_max, 19, 0xFF, 0x00, 0x00);
        set_led_with_brightness(led_min, led_max, 46, 0xFF, 0x00, 0x00);
    }

    if (is_alt_held()) {
        set_led_with_brightness(led_min, led_max, 16, 0xFF, 0x00, 0x00);
        set_led_with_brightness(led_min, led_max, 43, 0xFF, 0x00, 0x00);
    }

    if (is_gui_held()) {
        set_led_with_brightness(led_min, led_max, 11, 0xFF, 0x00, 0x00);
        set_led_with_brightness(led_min, led_max, 38, 0xFF, 0x00, 0x00);
    }

    // Apply custom layer-specific colors (overrides default colors)
    if (layer_state_is(_NUMS)) {
        // Parentheses - Orange
        set_led_with_brightness(led_min, led_max, 45, 0xFF, 0xA5, 0x00);
        set_led_with_brightness(led_min, led_max, 50, 0xFF, 0xA5, 0x00);
        // FNS layer toggle - Purple
        set_led_with_brightness(led_min, led_max, 34, 0x80, 0x00, 0x80);

        // Number keys - Green
        set_led_with_brightness(led_min, led_max, 22, 0x00, 0xFF, 0x00); // 1
        set_led_with_brightness(led_min, led_max, 19, 0x00, 0xFF, 0x00); // 2
        set_led_with_brightness(led_min, led_max, 16, 0x00, 0xFF, 0x00); // 3
        set_led_with_brightness(led_min, led_max, 11, 0x00, 0xFF, 0x00); // 4
        set_led_with_brightness(led_min, led_max, 8, 0x00, 0xFF, 0x00);  // 5
        set_led_with_brightness(led_min, led_max, 35, 0x00, 0xFF, 0x00); // 6
        set_led_with_brightness(led_min, led_max, 38, 0x00, 0xFF, 0x00); // 7
        set_led_with_brightness(led_min, led_max, 43, 0x00, 0xFF, 0x00); // 8
        set_led_with_brightness(led_min, led_max, 46, 0x00, 0xFF, 0x00); // 9
        set_led_with_brightness(led_min, led_max, 49, 0x00, 0xFF, 0x00); // 0
    }

    // Curly braces - Yellow
    if (layer_state_is(_NUMS) || layer_state_is(_MODS_NAV)) {
        set_led_with_brightness(led_min, led_max, 39, 0xFF, 0xFF, 0x00);
        set_led_with_brightness(led_min, led_max, 42, 0xFF, 0xFF, 0x00);
    }

    // Square brackets - Cyan
    if (layer_state_is(_NUMS) || layer_state_is(_MODS_NAV)) {
        set_led_with_brightness(led_min, led_max, 47, 0x00, 0xFF, 0xFF);
        set_led_with_brightness(led_min, led_max, 48, 0x00, 0xFF, 0xFF);
    }

    if (layer_state_is(_MODS_NAV)) {
        // Zoom controls on MODS_NAV layer - Green/Spring Green
        set_led_with_brightness(led_min, led_max, 10, 0x00, 0xFF, 0x7F);
        set_led_with_brightness(led_min, led_max, 17, 0x00, 0x80, 0x00);
        set_led_with_brightness(led_min, led_max, 18, 0x00, 0xFF, 0x7F);

        // Arrow keys on MODS_NAV layer - Red
        set_led_with_brightness(led_min, led_max, 44, 0xFF, 0x00, 0x00);
        set_led_with_brightness(led_min, led_max, 38, 0xFF, 0x00, 0x00);
        set_led_with_brightness(led_min, led_max, 43, 0xFF, 0x00, 0x00);
        set_led_with_brightness(led_min, led_max, 46, 0xFF, 0x00, 0x00);

        // Page Up/Down on MODS_NAV layer - Blue
        set_led_with_brightness(led_min, led_max, 49, 0x00, 0x00, 0xFF);
        set_led_with_brightness(led_min, led_max, 50, 0x00, 0x00, 0xFF);

        // IDE forward/backward on MODS_NAV layer - Purple
        set_led_with_brightness(led_min, led_max, 37, 0x80, 0x00, 0x80);
        set_led_with_brightness(led_min, led_max, 45, 0x80, 0x00, 0x80);
    }

    // Media controls on MEDIA layer
    if (layer_state_is(_MEDIA)) {
        set_led_with_brightness(led_min, led_max, 34, 0xFF, 0xC0, 0xCB);
        set_led_with_brightness(led_min, led_max, 39, 0xFF, 0x00, 0x00);
        set_led_with_brightness(led_min, led_max, 42, 0x00, 0xFF, 0x00);
        set_led_with_brightness(led_min, led_max, 35, 0xFF, 0xFF, 0x00);
        set_led_with_brightness(led_min, led_max, 38, 0x00, 0xFF, 0x00);
        set_led_with_brightness(led_min, led_max, 43, 0xFF, 0xFF, 0x00);
    }

    if (layer_state_is(_FNS)) {
        // Bottom row F keys (F1, F2, F3, F4) - Yellow
        set_led_with_brightness(led_min, led_max, 21, 0xFF, 0xFF, 0x00);
        set_led_with_brightness(led_min, led_max, 20, 0xFF, 0xFF, 0x00);
        set_led_with_brightness(led_min, led_max, 15, 0xFF, 0xFF, 0x00);
        set_led_with_brightness(led_min, led_max, 12, 0xFF, 0xFF, 0x00);

        // Middle row F keys (F5, F6, F7, F8) - F5=Red, F6-F8=Yellow
        set_led_with_brightness(led_min, led_max, 22, 0xFF, 0x00, 0x00);
        set_led_with_brightness(led_min, led_max, 19, 0xFF, 0xFF, 0x00);
        set_led_with_brightness(led_min, led_max, 16, 0xFF, 0xFF, 0x00);
        set_led_with_brightness(led_min, led_max, 11, 0xFF, 0xFF, 0x00);

        // Top row F keys (F9, F10, F11, F12) - F9=Yellow, F10-F12=Red
        set_led_with_brightness(led_min, led_max, 23, 0xFF, 0xFF, 0x00);
        set_led_with_brightness(led_min, led_max, 18, 0xFF, 0x00, 0x00);
        set_led_with_brightness(led_min, led_max, 17, 0xFF, 0x00, 0x00);
        set_led_with_brightness(led_min, led_max, 10, 0xFF, 0x00, 0x00);

        // RGB lighting controls - Right side
        set_led_with_brightness(led_min, led_max, 36, 0xFF, 0x00, 0x00);
        set_led_with_brightness(led_min, led_max, 37, 0x80, 0x80, 0x80);
        set_led_with_brightness(led_min, led_max, 44, 0xFF, 0xFF, 0xFF);

        // BASE layer toggle - Right side
        set_led_with_brightness(led_min, led_max, 24, 0x80, 0x00, 0x80);
    }

    return true;
}

#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case QK_RGB_MATRIX_VALUE_DOWN:
            if (record->event.pressed) {
                if (global_brightness > 16) {
                    global_brightness -= 16;
                } else {
                    global_brightness = 0;
                }
            }
            return false;

        case QK_RGB_MATRIX_VALUE_UP:
            if (record->event.pressed) {
                if (global_brightness < 239) {
                    global_brightness += 16;
                } else {
                    global_brightness = 255;
                }
            }
            return false;
    }
    return true;
}

#ifdef OLED_ENABLE

bool oled_task_user(void) {
    uint8_t mods = get_mods();
    uint8_t oneshot = get_oneshot_mods();

    bool gui_active = (mods | oneshot) & MOD_MASK_GUI;
    bool alt_active = (mods | oneshot) & MOD_MASK_ALT;
    bool ctrl_active = (mods | oneshot) & MOD_MASK_CTRL;
    bool shift_active = (mods | oneshot) & MOD_MASK_SHIFT;
    bool any_active = gui_active || alt_active || ctrl_active || shift_active;

    oled_clear();

    if (layer_state_is(_FNS)) {
        // Display function key layout (accounting for 90° rotation)
        oled_write_P(PSTR("F1 "), false);
        oled_write_P(PSTR("F5"), true);  // Inverted
        oled_write_P(PSTR(" F9        \n"), false);
        oled_write_P(PSTR("F2 F6 "), false);
        oled_write_P(PSTR("F10"), true);  // Inverted
        oled_write_P(PSTR("       \n"), false);
        oled_write_P(PSTR("F3 F7 "), false);
        oled_write_P(PSTR("F11"), true);  // Inverted
        oled_write_P(PSTR("       \n"), false);
        oled_write_P(PSTR("F4 F8 "), false);
        oled_write_P(PSTR("F12"), true);  // Inverted
        oled_write_P(PSTR("       \n"), false);
    } else if (layer_state_is(_NUMS)) {
        oled_write_P(PSTR("       NUMS     \n"), false);
        oled_write_P(PSTR("                \n"), false);
        oled_write_P(PSTR("                \n"), false);
        oled_write_P(PSTR("                \n"), false);
    } else if (layer_state_is(_MODS_NAV)) {
        oled_write_P(PSTR("    MODS/NAV    \n"), false);
        oled_write_P(PSTR("                \n"), false);
        oled_write_P(PSTR("                \n"), false);
        oled_write_P(PSTR("                \n"), false);
    } else if (layer_state_is(_MEDIA)) {
        oled_write_P(PSTR("      MEDIA     \n"), false);
        oled_write_P(PSTR("                \n"), false);
        oled_write_P(PSTR("                \n"), false);
        oled_write_P(PSTR("                \n"), false);
    } else if (layer_state_is(_BASE) && any_active) {
        // Display modifier keys if no layer is active
        // make these only display
        oled_write_P(PSTR(" CTL             \n"), ctrl_active);
        oled_write_P(PSTR("     OPT         \n"), alt_active);
        oled_write_P(PSTR("         CMD     \n"), gui_active);
        oled_write_P(PSTR("             SFT \n"), shift_active);
    }

    return false;
}
#endif
