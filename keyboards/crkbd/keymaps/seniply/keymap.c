#include "hal_files.h"
#include "modifiers.h"
#include "quantum_keycodes.h"
#include QMK_KEYBOARD_H

// Layer definitions
enum layers {
    _BASE,
    _QWERTY,
    _SYMBOLS,
    _NUMBERS,
    _EXTEND,
    _FUNCTION
};

// Aliases for readability
#define EXT_PLV  KC_MPRV // Previous
#define EXT_NXT  KC_MNXT // Next
#define EXT_PLY  KC_MPLY // Play/Pause
#define EXT_STP  KC_MSTP // Stop
#define EXT_BRI  KC_BRIU // Brightness Up
#define EXT_BRD  KC_BRID // Brightness Down

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_split_3x6_3(
        KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                      KC_J,    KC_L,    KC_U,    KC_Y,    KC_QUOT, KC_BSPC,
        KC_ESC,  KC_A,    KC_R,    KC_S,    KC_T,    KC_G,                      KC_M,    KC_N,    KC_E,    KC_I,    KC_O,    KC_SCLN,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,                      KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
                                   MO(_NUMBERS), MO(_EXTEND), KC_LSFT,      KC_SPC,  OSL(_SYMBOLS), MO(_FUNCTION)
    ),

    [_QWERTY] = LAYOUT_split_3x6_3(
        KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
        KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                      KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
                                   KC_TRNS, KC_TRNS, KC_TRNS,               KC_TRNS, KC_TRNS, KC_TRNS
    ),

    [_SYMBOLS] = LAYOUT_split_3x6_3(
        KC_TRNS, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                   KC_EQL,  KC_GRV,  KC_COLN, KC_SCLN, KC_PLUS, KC_TRNS,
        KC_TRNS, OSM(MOD_LSFT), OSM(MOD_LCTL), OSM(MOD_LALT), OSM(MOD_LGUI), KC_CIRC,   KC_ASTR, KC_LPRN, KC_LCBR, KC_LBRC, KC_MINS, KC_TRNS,
        KC_TRNS, KC_NUBS, LSFT(KC_NUBS), KC_NUHS, LSFT(KC_NUHS), KC_AMPR,       KC_TILD, KC_RPRN, KC_RCBR, KC_RBRC, KC_UNDS, KC_TRNS,
                                   KC_TRNS, KC_TRNS, KC_TRNS,               KC_TRNS, KC_TRNS, KC_TRNS
    ),

    [_NUMBERS] = LAYOUT_split_3x6_3(
        KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                     KC_EQL,  KC_7,    KC_8,    KC_9,    KC_PLUS, KC_TRNS,
        KC_TRNS, OSM(MOD_LSFT), OSM(MOD_LCTL), OSM(MOD_LALT), OSM(MOD_LGUI), OSM(MOD_RALT), KC_ASTR, KC_4,    KC_5,    KC_6,    KC_MINS, KC_TRNS,
        KC_TRNS, KC_NO,   KC_APP,  KC_TAB,  KC_BSPC, KC_ENT,                    KC_0,    KC_1,    KC_2,    KC_3,    KC_SLSH, KC_TRNS,
                                   KC_TRNS, KC_TRNS, KC_TRNS,               KC_TRNS, KC_TRNS, KC_TRNS
    ),

    [_EXTEND] = LAYOUT_split_3x6_3(
        KC_TRNS, KC_ESC,  LALT(KC_LEFT), LGUI(KC_F), LALT(KC_RGHT), KC_INS,     KC_PGUP, KC_HOME, KC_UP,   KC_END,  KC_CAPS, KC_TRNS,
        KC_TRNS, OSM(MOD_LSFT), OSM(MOD_LCTL), OSM(MOD_LALT), OSM(MOD_LGUI), OSM(MOD_RALT), KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_DEL,  KC_TRNS,
        KC_TRNS, LGUI(KC_Z), LGUI(KC_X), LGUI(KC_C), KC_LGUI, LGUI(KC_V),       KC_ENT,  KC_BSPC, KC_TAB,  KC_APP,  KC_PSCR, KC_TRNS,
                                       KC_TRNS, KC_TRNS, KC_TRNS,               KC_TRNS, KC_TRNS, KC_TRNS
    ),

    [_FUNCTION] = LAYOUT_split_3x6_3(
        KC_TRNS, EXT_STP, EXT_PLV, EXT_PLY, EXT_NXT, EXT_BRI,                   KC_F12,  KC_F7,   KC_F8,   KC_F9,   KC_SCRL, KC_TRNS,
        KC_TRNS, OSM(MOD_LSFT), OSM(MOD_LCTL), OSM(MOD_LALT), OSM(MOD_LGUI), EXT_BRD,   KC_F11,  KC_F4,   KC_F5,   KC_F6,   DF(_BASE), KC_TRNS,
        KC_TRNS, KC_MUTE, KC_VOLD, LGUI(LSFT(KC_C)), KC_VOLU, LGUI(LSFT(KC_V)), KC_F10,  KC_F1,   KC_F2,   KC_F3,   DF(_QWERTY), KC_TRNS,
                                   KC_TRNS, KC_TRNS, KC_TRNS,               KC_TRNS, KC_TRNS, KC_TRNS
    )
};

#ifdef OLED_ENABLE
bool oled_task_user(void) {
    oled_clear();

    if (layer_state_is(_FUNCTION)) {
        oled_write_P(PSTR("FUNCTION\n"), false);
    } else if (layer_state_is(_EXTEND)) {
        oled_write_P(PSTR("EXTEND\n"), false);
    } else if (layer_state_is(_NUMBERS)) {
        oled_write_P(PSTR("NUMBERS\n"), false);
    } else if (layer_state_is(_SYMBOLS)) {
        oled_write_P(PSTR("SYMBOLS\n"), false);
    } else if (layer_state_is(_QWERTY)) {
        oled_write_P(PSTR("QWERTY\n"), false);
    } else {
        oled_write_P(PSTR("BASE\n"), false);
    }

    return false;
}
#endif
