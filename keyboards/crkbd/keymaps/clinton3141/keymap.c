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
    _MODS_NAV
};

#define MOD_ACTIVE_COLOUR 0x16, 0x16, 0x00

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_ESC,    KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                         KC_J,    KC_L,    KC_U,    KC_Y,KC_SCLN,  KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       KC_TAB,    KC_A,    KC_R,    KC_S,    KC_T,    KC_G,                         KC_M,    KC_N,    KC_E,    KC_I,   KC_O,  KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_GRAVE,    KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,                         KC_K,    KC_H, KC_COMM,  KC_DOT, KC_SLSH,  KC_BSLS,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                        LCTL(KC_S), KC_SPC, MO(_MODS_NAV),     MO(_NUMS), KC_RSFT, KC_ENT
                                      //`--------------------------'  `--------------------------'

  ),

    [_NUMS] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, XXXXXXX, KC_LBRC, KC_RBRC, KC_MINS,                       KC_EQL, KC_LCBR, KC_RCBR, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,     _______,   _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

    [_MODS_NAV] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX,   KC_UP, XXXXXXX, XXXXXXX, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    _______,XXXXXXX,OSM(MOD_LCTL),OSM(MOD_LALT),OSM(MOD_LGUI),XXXXXXX,           XXXXXXX, KC_LEFT, KC_DOWN,KC_RIGHT, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    XXXXXXX,LCMD(KC_Z),LCMD(KC_X),LCMD(KC_C),XXXXXXX,LCMD(KC_V),                 XXXXXXX, KC_LCBR, KC_RCBR, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,     _______,   _______, _______
                                      //`--------------------------'  `--------------------------'
  )
};

#ifdef RGB_MATRIX_ENABLE

#define NUM_LEDS_PER_SIDE 24

#define NUM_LEDS_PER_SIDE_ON_NORMAL_CORNE 27

bool is_shift_held(void) { return (get_oneshot_mods() & MOD_BIT(KC_LSFT)) || (get_oneshot_mods() & MOD_BIT(KC_RSFT)); }
bool is_ctrl_held(void) { return (get_oneshot_mods() & MOD_BIT(KC_LCTL)) || (get_oneshot_mods() & MOD_BIT(KC_RCTL)); }
bool is_gui_held(void) { return (get_oneshot_mods() & MOD_BIT(KC_LGUI)) || (get_oneshot_mods() & MOD_BIT(KC_RGUI)); }
bool is_alt_held(void) { return (get_oneshot_mods() & MOD_BIT(KC_LALT)) || (get_oneshot_mods() & MOD_BIT(KC_RALT)); }

// inspired/lifted from https://github.com/Adam13531/qmk_firmware/blob/master/keyboards/crkbd/keymaps/adam/keymap.c#L171
void set_colour_split(uint8_t key_code, uint8_t r, uint8_t g, uint8_t b) {
    bool is_left = is_keyboard_left();
    bool left_is_master = (is_keyboard_master() && is_left) || (!is_keyboard_master() && !is_left);

    if ((is_left && key_code >= NUM_LEDS_PER_SIDE) || (!is_left && key_code < NUM_LEDS_PER_SIDE)) {
        return;
    }

    if (left_is_master && key_code >= NUM_LEDS_PER_SIDE)
        key_code -= NUM_LEDS_PER_SIDE_ON_NORMAL_CORNE;
    else if (!left_is_master && key_code < NUM_LEDS_PER_SIDE)
        key_code += NUM_LEDS_PER_SIDE_ON_NORMAL_CORNE;
    rgb_matrix_set_color(key_code, r, g, b);
}

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    if (is_gui_held()) {
        rgb_matrix_set_color(11, RGB_WHITE);
        rgb_matrix_set_color(38, RGB_WHITE);
    } else {
        rgb_matrix_set_color(11, RGB_BLACK);
        rgb_matrix_set_color(38, RGB_BLACK);
    }
    if (is_alt_held()) {
        rgb_matrix_set_color(16, RGB_WHITE);
        rgb_matrix_set_color(43, RGB_WHITE);
    } else {
        rgb_matrix_set_color(16, RGB_BLACK);
        rgb_matrix_set_color(43, RGB_BLACK);
    }
    if (is_ctrl_held()) {
        rgb_matrix_set_color(19, RGB_WHITE);
        rgb_matrix_set_color(46, RGB_WHITE);
    } else {
        rgb_matrix_set_color(19, RGB_BLACK);
        rgb_matrix_set_color(46, RGB_BLACK);
    }
    return false;
}
#endif
