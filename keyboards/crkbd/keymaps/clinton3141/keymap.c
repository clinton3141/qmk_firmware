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
};

#define MOD_ACTIVE_COLOUR 0x16, 0x16, 0x00

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_ESC,    KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                         KC_J,    KC_L,    KC_U,    KC_Y,KC_SCLN,  KC_BSLS,
//|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
         KC_TAB, LSFT_T(KC_A), LCTL_T(KC_R), LALT_T(KC_S), LGUI_T(KC_T),    KC_G,                         KC_M, RGUI_T(KC_N), RALT_T(KC_E), RCTL_T(KC_I), RSFT_T(KC_O),  KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     KC_GRAVE,    KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,                         KC_K,    KC_H, KC_COMM,  KC_DOT, KC_SLSH,  KC_BSLS,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                        MO(_MEDIA), KC_SPC, MO(_MODS_NAV),     LT(_NUMS, KC_ENT), KC_LSFT, XXXXXXX
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
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BACKSPACE,
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
        _______, XXXXXXX, XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
//|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        _______, XXXXXXX, XXXXXXX, KC_VOLD, KC_MUTE, KC_VOLU,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
//|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                                                                _______, _______, _______,     _______, _______, _______
                                                                        //`--------------------------'  `--------------------------'
)
};

#ifdef RGB_MATRIX_ENABLE

bool is_ctrl_held(void) { return (get_oneshot_mods() | get_mods()) & MOD_MASK_CTRL; }
bool is_alt_held(void) { return (get_oneshot_mods() | get_mods()) & MOD_MASK_ALT; }
bool is_gui_held(void) { return (get_oneshot_mods() | get_mods()) & MOD_MASK_GUI; }
bool is_shift_held(void) { return (get_oneshot_mods() | get_mods()) & MOD_MASK_SHIFT; }


bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
        rgb_matrix_set_color(11, RGB_BLACK);
        rgb_matrix_set_color(16, RGB_BLACK);
        rgb_matrix_set_color(17, RGB_BLACK);
        rgb_matrix_set_color(19, RGB_BLACK);
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
