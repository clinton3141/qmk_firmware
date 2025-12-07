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
    } else if (layer_state_is(_QWERTY)) {
        layer_r = 0x40; layer_g = 0x20; layer_b = 0x40; // Dim purple
    } else if (layer_state_is(_SYMBOLS)) {
        layer_r = 0x40; layer_g = 0x40; layer_b = 0x20; // Dim yellow/amber
    } else if (layer_state_is(_NUMBERS)) {
        layer_r = 0x20; layer_g = 0x40; layer_b = 0x20; // Dim green
    } else if (layer_state_is(_EXTEND)) {
        layer_r = 0x40; layer_g = 0x20; layer_b = 0x20; // Dim red
    } else if (layer_state_is(_FUNCTION)) {
        layer_r = 0x40; layer_g = 0x20; layer_b = 0x40; // Dim magenta
    }

    for (uint8_t i = 0; i < RGB_MATRIX_LED_COUNT; i++) {
        set_led_with_brightness(led_min, led_max, i, layer_r, layer_g, layer_b);
    }

    // Modifiers
    if (is_shift_held()) {
        // Highlight Shift keys (approximate positions)
        set_led_with_brightness(led_min, led_max, 21, 0xFF, 0xFF, 0xFF); // Left Shift pos
        set_led_with_brightness(led_min, led_max, 44, 0xFF, 0xFF, 0xFF); // Right Shift pos
    }
    if (is_ctrl_held()) {
        set_led_with_brightness(led_min, led_max, 22, 0x00, 0x00, 0xFF); // Left Ctrl pos
    }
    if (is_alt_held()) {
        set_led_with_brightness(led_min, led_max, 23, 0xFF, 0xFF, 0x00); // Left Alt pos
    }
    if (is_gui_held()) {
        set_led_with_brightness(led_min, led_max, 24, 0x80, 0x00, 0x80); // Left GUI pos
    }

    if (layer_state_is(_NUMBERS)) {
        // Numpad on Right Hand
        // 7 8 9 (Top)
        set_led_with_brightness(led_min, led_max, 38, 0x00, 0xFF, 0x00); // 7
        set_led_with_brightness(led_min, led_max, 43, 0x00, 0xFF, 0x00); // 8
        set_led_with_brightness(led_min, led_max, 46, 0x00, 0xFF, 0x00); // 9
        // 4 5 6 (Mid)
        set_led_with_brightness(led_min, led_max, 39, 0x00, 0xFF, 0x00); // 4
        set_led_with_brightness(led_min, led_max, 42, 0x00, 0xFF, 0x00); // 5
        set_led_with_brightness(led_min, led_max, 45, 0x00, 0xFF, 0x00); // 6
        // 1 2 3 (Bot)
        set_led_with_brightness(led_min, led_max, 40, 0x00, 0xFF, 0x00); // 1
        set_led_with_brightness(led_min, led_max, 41, 0x00, 0xFF, 0x00); // 2
        set_led_with_brightness(led_min, led_max, 44, 0x00, 0xFF, 0x00); // 3
        // 0 (Bot Inner)
        set_led_with_brightness(led_min, led_max, 33, 0x00, 0xFF, 0x00); // 0
        
        // Operators
        set_led_with_brightness(led_min, led_max, 49, 0xFF, 0xA5, 0x00); // + (Top Pinky)
        set_led_with_brightness(led_min, led_max, 48, 0xFF, 0xA5, 0x00); // - (Mid Pinky)
        set_led_with_brightness(led_min, led_max, 47, 0xFF, 0xA5, 0x00); // / (Bot Pinky)
    }

    if (layer_state_is(_EXTEND)) {
        // Arrow Keys (Right Hand)
        set_led_with_brightness(led_min, led_max, 43, 0xFF, 0x00, 0x00); // Up (Top Middle)
        set_led_with_brightness(led_min, led_max, 39, 0xFF, 0x00, 0x00); // Left (Mid Index)
        set_led_with_brightness(led_min, led_max, 42, 0xFF, 0x00, 0x00); // Down (Mid Middle)
        set_led_with_brightness(led_min, led_max, 45, 0xFF, 0x00, 0x00); // Right (Mid Ring)
        
        // Home/End/PgUp/PgDn
        set_led_with_brightness(led_min, led_max, 38, 0x00, 0x00, 0xFF); // PgUp (Top Index)
        set_led_with_brightness(led_min, led_max, 46, 0x00, 0x00, 0xFF); // End (Top Ring)
        set_led_with_brightness(led_min, led_max, 40, 0x00, 0x00, 0xFF); // PgDn (Bot Index)
        set_led_with_brightness(led_min, led_max, 41, 0x00, 0x00, 0xFF); // Home (Bot Middle - wait, Home is Top Middle in layout?)
    }

    if (layer_state_is(_FUNCTION)) {
        // F-Keys (Right Hand in Seniply layout)
        // F7 F8 F9 (Top)
        set_led_with_brightness(led_min, led_max, 38, 0xFF, 0x00, 0x00); // F7
        set_led_with_brightness(led_min, led_max, 43, 0xFF, 0xFF, 0x00); // F8
        set_led_with_brightness(led_min, led_max, 46, 0xFF, 0xFF, 0x00); // F9
        // F4 F5 F6 (Mid)
        set_led_with_brightness(led_min, led_max, 39, 0xFF, 0xFF, 0x00); // F4
        set_led_with_brightness(led_min, led_max, 42, 0xFF, 0x00, 0x00); // F5
        set_led_with_brightness(led_min, led_max, 45, 0xFF, 0xFF, 0x00); // F6
        // F1 F2 F3 (Bot)
        set_led_with_brightness(led_min, led_max, 40, 0xFF, 0xFF, 0x00); // F1
        set_led_with_brightness(led_min, led_max, 41, 0xFF, 0xFF, 0x00); // F2
        set_led_with_brightness(led_min, led_max, 44, 0xFF, 0xFF, 0x00); // F3
        // F10 F11 F12 (Inner)
        set_led_with_brightness(led_min, led_max, 33, 0xFF, 0x00, 0x00); // F10
        set_led_with_brightness(led_min, led_max, 34, 0xFF, 0x00, 0x00); // F11
        set_led_with_brightness(led_min, led_max, 35, 0xFF, 0x00, 0x00); // F12
    }

    return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case EXT_BRI:
            if (record->event.pressed) {
                if (global_brightness < 239) {
                    global_brightness += 16;
                } else {
                    global_brightness = 255;
                }
            }
            return false;

        case EXT_BRD:
            if (record->event.pressed) {
                if (global_brightness > 16) {
                    global_brightness -= 16;
                } else {
                    global_brightness = 0;
                }
            }
            return false;
    }
    return true;
}

#endif

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
