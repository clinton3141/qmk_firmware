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
       KC_ESC,    KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                         KC_J,    KC_L,    KC_U,    KC_Y,KC_SCLN,  KC_BSLS,
//|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
         KC_TAB, LSFT_T(KC_A), LCTL_T(KC_R), LALT_T(KC_S), LGUI_T(KC_T),    KC_G,                         KC_M, RGUI_T(KC_N), RALT_T(KC_E), RCTL_T(KC_I), RSFT_T(KC_O),  KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     KC_GRAVE,    KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,                         KC_K,    KC_H, KC_COMM,  KC_DOT, KC_SLSH,  KC_BSLS,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                        MO(_MEDIA), KC_SPC, MO(_MODS_NAV),     LT(_NUMS, KC_ENT), KC_LSFT, LT(_FNS, KC_BSPC)
                                      //`--------------------------'  `--------------------------'

  ),

    [_NUMS] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,   KC_GT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_UNDS, KC_MINS, KC_PLUS,  KC_EQL,  XXXXXXX,                      XXXXXXX, KC_LCBR, KC_RCBR, KC_LBRC, KC_RBRC,   KC_LT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,     _______,   _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

    [_MODS_NAV] = LAYOUT_split_3x6_3(
//,-----------------------------------------------------.                    ,-----------------------------------------------------.
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, KC_UP, XXXXXXX, XXXXXXX, KC_BACKSPACE,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    _______,OSM(MOD_LSFT),OSM(MOD_LCTL),OSM(MOD_LALT),OSM(MOD_LGUI),XXXXXXX,           KC_TAB, KC_LEFT, KC_DOWN, KC_RIGHT,    KC_0,  KC_EQL,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    XXXXXXX,LCMD(KC_Z),LCMD(KC_X),LCMD(KC_C),XXXXXXX,LCMD(KC_V),                KC_GRAVE, KC_LCBR, KC_RCBR, KC_LBRC, KC_RBRC, KC_MINS,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,     _______,   _______, _______
                                      //`--------------------------'  `--------------------------'
  )
,
    [_MEDIA] = LAYOUT_split_3x6_3(
//,-----------------------------------------------------.                    ,-----------------------------------------------------.
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
//|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, XXXXXXX, _______,
//|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_VOLD, KC_MUTE, KC_VOLU, XXXXXXX, XXXXXXX, _______,
//|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                                                                _______, _______, _______,     _______, _______, _______
                                                                        //`--------------------------'  `--------------------------'
),
    [_FNS] = LAYOUT_split_3x6_3(
//,-----------------------------------------------------.                    ,-----------------------------------------------------.
    _______, KC_F9,   KC_F10,  KC_F11,  KC_F12,  XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
//|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    _______, KC_F5,   KC_F6,   KC_F7,   KC_F8,   XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
//|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
//|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                                                                _______, _______, _______,     _______, _______, _______
                                                                        //`--------------------------'  `--------------------------'
)
};

#ifdef RGB_MATRIX_ENABLE

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

void keyboard_post_init_user(void) {
    rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
    rgb_matrix_sethsv_noeeprom(HSV_OFF);
}

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    // Turn off all LEDs first
    for (uint8_t i = 0; i < RGB_MATRIX_LED_COUNT; i++) {
        rgb_matrix_set_color(i, RGB_BLACK);
    }

    if (is_shift_held()) {
        rgb_matrix_set_color(22, RGB_WHITE);   // Left Shift (LSFT_T(KC_A))
        rgb_matrix_set_color(49, RGB_WHITE);   // Right Shift (RSFT_T(KC_O))
        rgb_matrix_set_color(40, RGB_WHITE);   // Thumb Shift (KC_LSFT)
    }

    if (is_ctrl_held()) {
        rgb_matrix_set_color(19, RGB_WHITE);   // Left Ctrl (LCTL_T(KC_R))
        rgb_matrix_set_color(46, RGB_WHITE);   // Right Ctrl (RCTL_T(KC_I))
    }

    if (is_alt_held()) {
        rgb_matrix_set_color(16, RGB_WHITE);   // Left Alt (LALT_T(KC_S))
        rgb_matrix_set_color(43, RGB_WHITE);   // Right Alt (RALT_T(KC_E))
    }

    if (is_gui_held()) {
        rgb_matrix_set_color(11, RGB_WHITE); // Left CMD (LGUI_T(KC_T))
        rgb_matrix_set_color(38, RGB_WHITE); // Right CMD (RGUI_T(KC_N))
    }

    if (layer_state_is(_NUMS)) {
        // Top row symbols - Orange
        rgb_matrix_set_color(23, RGB_ORANGE);  // KC_EXLM (Q position)
        rgb_matrix_set_color(18, RGB_ORANGE);  // KC_AT (W position)
        rgb_matrix_set_color(17, RGB_ORANGE);  // KC_HASH (F position)
        rgb_matrix_set_color(10, RGB_ORANGE);  // KC_DLR (P position)
        rgb_matrix_set_color(9, RGB_ORANGE);   // KC_PERC (B position)
        rgb_matrix_set_color(36, RGB_ORANGE);  // KC_CIRC (J position)
        rgb_matrix_set_color(35, RGB_ORANGE);  // KC_AMPR (L position)
        rgb_matrix_set_color(44, RGB_ORANGE);  // KC_ASTR (U position)
        rgb_matrix_set_color(45, RGB_ORANGE);  // KC_LPRN (Y position)
        rgb_matrix_set_color(50, RGB_ORANGE);  // KC_RPRN (SCLN position)

        // Number row - Yellow
        rgb_matrix_set_color(22, RGB_YELLOW);  // KC_1 (A position)
        rgb_matrix_set_color(19, RGB_YELLOW);  // KC_2 (R position)
        rgb_matrix_set_color(16, RGB_YELLOW);  // KC_3 (S position)
        rgb_matrix_set_color(11, RGB_YELLOW);  // KC_4 (T position)
        rgb_matrix_set_color(8, RGB_YELLOW);   // KC_5 (G position)
        rgb_matrix_set_color(34, RGB_YELLOW);  // KC_6 (M position)
        rgb_matrix_set_color(38, RGB_YELLOW);  // KC_7 (N position)
        rgb_matrix_set_color(43, RGB_YELLOW);  // KC_8 (E position)
        rgb_matrix_set_color(46, RGB_YELLOW);  // KC_9 (I position)
        rgb_matrix_set_color(49, RGB_YELLOW);  // KC_0 (O position)

        // Other explicitly set keys - Pink
        rgb_matrix_set_color(52, RGB_PINK);    // KC_GT (QUOT position)
        rgb_matrix_set_color(21, RGB_PINK);    // KC_UNDS (Z position)
        rgb_matrix_set_color(20, RGB_PINK);    // KC_MINS (X position)
        rgb_matrix_set_color(15, RGB_PINK);    // KC_PLUS (C position)
        rgb_matrix_set_color(12, RGB_PINK);    // KC_EQL (D position)
        rgb_matrix_set_color(39, RGB_PINK);    // KC_LCBR (H position)
        rgb_matrix_set_color(42, RGB_PINK);    // KC_RCBR (COMM position)
        rgb_matrix_set_color(47, RGB_PINK);    // KC_LBRC (DOT position)
        rgb_matrix_set_color(48, RGB_PINK);    // KC_RBRC (SLSH position)
        rgb_matrix_set_color(51, RGB_PINK);    // KC_LT (BSLS position)
    }

    return true;
}

#endif

#ifdef OLED_ENABLE

bool oled_task_user(void) {
    uint8_t mods = get_mods();
    uint8_t oneshot = get_oneshot_mods();

    bool gui_active = (mods | oneshot) & MOD_MASK_GUI;
    bool alt_active = (mods | oneshot) & MOD_MASK_ALT;
    bool ctrl_active = (mods | oneshot) & MOD_MASK_CTRL;
    bool shift_active = (mods | oneshot) & MOD_MASK_SHIFT;
    bool any_active = gui_active || alt_active || ctrl_active || shift_active;

    if (!any_active) {
        oled_off();
        return false;
    }

    oled_on();
    oled_clear();

    // TODO: use pictures instead of text.
    // @see https://joric.github.io/qle/
    oled_write_P(PSTR(" CTL             \n"), ctrl_active);
    oled_write_P(PSTR("     OPT         \n"), alt_active);
    oled_write_P(PSTR("         CMD     \n"), gui_active);
    oled_write_P(PSTR("             SFT \n"), shift_active);

    return false;
}
#endif
