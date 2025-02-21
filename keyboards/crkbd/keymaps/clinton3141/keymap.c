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

enum custom_keycodes {
    CM_ARR = SAFE_RANGE,
    CM_SHFT_MOUSE,
};

enum layers {
    _BASE,
    _NUMS,
    _MODS_NAV,
    _MOUSE,
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
                                        KC_LCTL, KC_SPC, MO(_MODS_NAV),     MO(_NUMS), CM_SHFT_MOUSE, KC_ENT
                                      //`--------------------------'  `--------------------------'

  ),

    [_NUMS] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,   KC_GT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_UNDS, KC_MINS, KC_PLUS,  KC_EQL,  CM_ARR,                      XXXXXXX, KC_LCBR, KC_RCBR, KC_LBRC, KC_RBRC,   KC_LT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,     _______,   _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

    [_MODS_NAV] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
    _______,KC_KB_MUTE,KC_KB_VOLUME_DOWN,KC_KB_VOLUME_UP,KC_MEDIA_PLAY_PAUSE,XXXXXXX,   KC_ESC,KC_MEDIA_PREV_TRACK,KC_UP,KC_MEDIA_NEXT_TRACK,XXXXXXX,_______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    _______,OSM(MOD_LSFT),OSM(MOD_LCTL),OSM(MOD_LALT),OSM(MOD_LGUI),XXXXXXX,           KC_TAB, KC_LEFT, KC_DOWN, KC_RIGHT,    KC_0,  KC_EQL,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    XXXXXXX,LCMD(KC_Z),LCMD(KC_X),LCMD(KC_C),XXXXXXX,LCMD(KC_V),                KC_GRAVE, KC_LCBR, KC_RCBR, KC_LBRC, KC_RBRC, KC_MINS,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,     _______,   _______, _______
                                      //`--------------------------'  `--------------------------'
  ),
    [_MOUSE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, XXXXXXX, XXXXXXX,   MS_UP, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, MS_LEFT, MS_DOWN, MS_RGHT, MS_BTN1,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, MS_BTN2,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,     _______,   _______, _______
                                      //`--------------------------'  `--------------------------'
  )
};

#ifdef RGB_MATRIX_ENABLE

bool is_ctrl_held(void) { return (get_oneshot_mods() | get_mods()) & MOD_MASK_CTRL; }
bool is_alt_held(void) { return (get_oneshot_mods() | get_mods()) & MOD_MASK_ALT; }
bool is_gui_held(void) { return (get_oneshot_mods() | get_mods()) & MOD_MASK_GUI; }
bool is_shift_held(void) { return (get_oneshot_mods() | get_mods()) & MOD_MASK_SHIFT; }

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static uint16_t last_tap_time = 0;
    static bool is_shift_held = false;

    switch (keycode) {
        case CM_ARR:
            if (record->event.pressed) {
                SEND_STRING("->");
            }
            break;
        case CM_SHFT_MOUSE:
            if (record->event.pressed) {
                if (timer_elapsed(last_tap_time) < TAPPING_TERM) {
                    layer_on(_MOUSE);
                } else {
                    register_code(KC_LSFT);
                    is_shift_held = true;
                }
                last_tap_time = timer_read();
            } else {
                if (is_shift_held) {
                    unregister_code(KC_LSFT);
                    is_shift_held = false;
                } else {
                    layer_off(_MOUSE);
                }
            }
            return false;
    }
    return true;
}

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    if (layer_state_is(_MOUSE)) {
        rgb_matrix_set_color(11, RGB_CYAN);
        rgb_matrix_set_color(16, RGB_CYAN);
        rgb_matrix_set_color(17, RGB_CYAN);
        rgb_matrix_set_color(19, RGB_CYAN);
        return false;
    } else {
        rgb_matrix_set_color(11, RGB_BLACK);
        rgb_matrix_set_color(16, RGB_BLACK);
        rgb_matrix_set_color(17, RGB_BLACK);
        rgb_matrix_set_color(19, RGB_BLACK);
    }
    if (is_gui_held()) {
        rgb_matrix_set_color(11, RGB_WHITE);
    } else {
        rgb_matrix_set_color(11, RGB_BLACK);
    }
    if (is_alt_held()) {
        rgb_matrix_set_color(16, RGB_WHITE);
    } else {
        rgb_matrix_set_color(16, RGB_BLACK);
    }
    if (is_ctrl_held()) {
        rgb_matrix_set_color(19, RGB_WHITE);
    } else {
        rgb_matrix_set_color(19, RGB_BLACK);
    }
    if (is_shift_held()) {
        rgb_matrix_set_color(22, RGB_WHITE);
    } else {
        rgb_matrix_set_color(22, RGB_BLACK);
    }
    return false;
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
    bool mouse_active = layer_state_is(_MOUSE);
    bool any_active = gui_active || alt_active || ctrl_active || shift_active || mouse_active;

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

    // TODO: this overwrites CTL. Ideally it should go somewhere else.
    if (layer_state_is(_MOUSE)) {
        oled_write_P(PSTR("MOUSE\n"), false);
    }
    return false;
}
#endif
