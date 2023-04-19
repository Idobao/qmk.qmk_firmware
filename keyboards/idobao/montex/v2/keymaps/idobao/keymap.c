// Copyright 2022 idobaokb (@idobaokb)
// SPDX-License-Identifier: GPL-2.0-or-later

/* ------------------------------------------------------------------
 * This is the IDOBAO factory default keymap ;)
 * ------------------------------------------------------------------ */

#include QMK_KEYBOARD_H
#include "version.h"

#ifdef RGB_MATRIX_ENABLE
typedef union {
    uint32_t raw;
    struct {
        bool led_disable_numlock:1;  // set true to disable num-lock LED
        bool rgb_disable_perkey:1;
        #ifndef ID27_DISABLE_UNDERGLOW
        bool rgb_disable_underglow:1;
        #endif  // ID27_DISABLE_UNDERGLOW
    };
} user_config_t;
#endif  // RGB_MATRIX_ENABLE

enum montex_layers {
    _BASE,
    _FN,
    _EMPTY2,  // Just to initialize dynamic layers in VIA
    _EMPTY3,
    _EMPTY4,
    _EMPTY5
};

enum {
    #ifdef RGB_MATRIX_ENABLE
    RGB_TPK = USER02,  // Toggle Per-Key
    #ifndef ID27_DISABLE_UNDERGLOW
    RGB_TUG,           // Toggle Underglow
    #endif  // ID27_DISABLE_UNDERGLOW
    KB_NLED = USER08,  // disable num-lock led
    #endif  // RGB_MATRIX_ENABLE
    KB_VRSN = USER09   // debug, type version
};

#ifndef RGB_MATRIX_ENABLE
    #define RGB_TPK _______
    #define RGB_TUG _______
    #define KB_NLED _______
#else
    #ifdef ID27_DISABLE_UNDERGLOW
        #define RGB_TUG _______
    #endif  // ID27_DISABLE_UNDERGLOW
#endif  // RGB_MATRIX_ENABLE

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┬───┬───┬───┬───┐
     * │Esc│Mut│Vl-│Vl+│Bsp│
     * ├───┼───┼───┼───┼───┤
     * │Ctr│Num│ / │ * │ - │
     * ├───┼───┼───┼───┼───┤
     * │Gui│ 7 │ 8 │ 9 │   │
     * ├───┼───┼───┼───┤ + │
     * │Alt│ 4 │ 5 │ 6 │   │
     * ├───┼───┼───┼───┼───┤
     * │Shi│ 1 │ 2 │ 3 │   │
     * ├───┼───┴───┼───┤Ent│
     * │MO1│ 0     │ . │   │
     * └───┴───────┴───┴───┘
     */
    [_BASE] = LAYOUT_numpad_6x5(
        KC_GESC,   KC_MUTE,  KC_VOLD, KC_VOLU, KC_BSPC,
        KC_LCTRL,  KC_NLCK,  KC_PSLS, KC_PAST, KC_PMNS,
        KC_LGUI,   KC_P7,    KC_P8,   KC_P9,   KC_PPLS,
        KC_LALT,   KC_P4,    KC_P5,   KC_P6,
        KC_LSHIFT, KC_P1,    KC_P2,   KC_P3,   KC_PENT,
        MO(1),     KC_P0,             KC_PDOT
    ),

    /*
     * ┌───┬───┬───┬───┬───┐
     * │Rst│TOG│MOD│TPK│TUG│
     * ├───┼───┼───┼───┼───┤
     * │Hu+│TNL│Sp-│Sp+│Br-│
     * ├───┼───┼───┼───┼───┤
     * │Hu-│Hom│ ↑ │PgU│   │
     * ├───┼───┼───┼───┤Br+│
     * │St+│ ← │ × │ → │   │
     * ├───┼───┼───┼───┤───┤
     * │St-│End│ ↓ │PgD│   │
     * ├───┼───┴───┼───┤Ent│
     * │mo1│Insert │Del│   │
     * └───┴───────┴───┴───┘
     */
    [_FN] = LAYOUT_numpad_6x5(
        QK_BOOT, RGB_TOG, RGB_MOD, RGB_TPK, RGB_TUG,
        RGB_HUI, KB_NLED, RGB_SPD, RGB_SPI, RGB_VAD,
        RGB_HUD, KC_HOME, KC_UP,   KC_PGUP, RGB_VAI,
        RGB_SAI, KC_LEFT, XXXXXXX, KC_RGHT,
        RGB_SAD, KC_END,  KC_DOWN, KC_PGDN, KC_ENT,
        _______, KC_INS,           KC_DEL
    ),

    /*  4 extra layers incase you want to map the top row to layer buttons
     * ┌───┬───┬───┬───┬───┐
     * │   │   │   │   │   │
     * ├───┼───┼───┼───┼───┤
     * │   │   │   │   │   │
     * ├───┼───┼───┼───┼───┤
     * │   │   │   │   │   │
     * ├───┼───┼───┼───┤   │
     * │   │   │   │   │   │
     * ├───┼───┼───┼───┤───┤
     * │   │   │   │   │   │
     * ├───┼───┴───┼───┤   │
     * │   │       │   │   │
     * └───┴───────┴───┴───┘
     */
    [_EMPTY2] = LAYOUT_numpad_6x5(
        _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,
        _______, _______, _______, _______,
        _______, _______, _______, _______, _______,
        _______, _______,          _______
    ),

    [_EMPTY3] = LAYOUT_numpad_6x5(
        _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,
        _______, _______, _______, _______,
        _______, _______, _______, _______, _______,
        _______, _______,          _______
    ),

    [_EMPTY4] = LAYOUT_numpad_6x5(
        _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,
        _______, _______, _______, _______,
        _______, _______, _______, _______, _______,
        _______, _______,          _______
    ),

    [_EMPTY5] = LAYOUT_numpad_6x5(
        _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,
        _______, _______, _______, _______,
        _______, _______, _______, _______, _______,
        _______, _______,          _______
    )
};

#ifdef RGB_MATRIX_ENABLE

/*
 * RGB Stuff
 */

#define ID27_NUM_LOCK_KEY_INDEX 6  // position of Num Lock key

#define ID27_NUM_LOCK_MAX_BRIGHTNESS 0xFF
#ifdef RGB_MATRIX_MAXIMUM_BRIGHTNESS
    #undef ID27_NUM_LOCK_MAX_BRIGHTNESS
    #define ID27_NUM_LOCK_MAX_BRIGHTNESS RGB_MATRIX_MAXIMUM_BRIGHTNESS
#endif

#define ID27_NUM_LOCK_VAL_STEP 8
#ifdef RGB_MATRIX_VAL_STEP
    #undef ID27_NUM_LOCK_VAL_STEP
    #define ID27_NUM_LOCK_VAL_STEP RGB_MATRIX_VAL_STEP
#endif

user_config_t user_config;

void id27_update_rgb_mode(void) {
    uint8_t flags = LED_FLAG_ALL;

    if (user_config.rgb_disable_perkey
        #ifndef ID27_DISABLE_UNDERGLOW
        && user_config.rgb_disable_underglow
        #endif  // ID27_DISABLE_UNDERGLOW
        ) {
        flags = 0;  // All OFF Condition
    } else {
        if (user_config.rgb_disable_perkey) {
            #ifndef ID27_DISABLE_UNDERGLOW
            flags = LED_FLAG_UNDERGLOW | 0xF0;
            #else
            flags = 0xF0;
            #endif  // ID27_DISABLE_UNDERGLOW
        }
        #ifndef ID27_DISABLE_UNDERGLOW
        if (user_config.rgb_disable_underglow) {
            flags = LED_FLAG_MODIFIER | LED_FLAG_KEYLIGHT | LED_FLAG_INDICATOR | 0xF0;
        }
        #endif  // ID27_DISABLE_UNDERGLOW
    }

    if (flags == 0) {
        rgb_matrix_set_flags(0);
        rgb_matrix_set_color_all(HSV_OFF);
    } else {
        rgb_matrix_set_flags(flags);
        rgb_matrix_enable_noeeprom();
    }

    eeconfig_update_kb(user_config.raw);  // write back to EEPROM
}

void id27_get_rgb_mode(void) {
    user_config.raw = eeconfig_read_kb();  // read config from EEPROM
    id27_update_rgb_mode();
}

void keyboard_post_init_user(void) {
    id27_get_rgb_mode();
}

void eeconfig_init_user(void) {
    // EEPROM is getting reset!
    user_config.raw = 0;
    id27_update_rgb_mode();
}

void rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    // Num-Lock key stuff
    if (!user_config.led_disable_numlock) {

        if (host_keyboard_led_state().num_lock) {
            uint8_t v = rgb_matrix_get_val();
            if (v < ID27_NUM_LOCK_VAL_STEP) {
                v = ID27_NUM_LOCK_VAL_STEP;
            } else if (v < (ID27_NUM_LOCK_MAX_BRIGHTNESS - ID27_NUM_LOCK_VAL_STEP)) {
                if (!user_config.rgb_disable_perkey) {
                    v += ID27_NUM_LOCK_VAL_STEP;  // inc. by one more step than current brightness
                }  // else leave as current brightness
            } else {
                v = ID27_NUM_LOCK_MAX_BRIGHTNESS;
            }
            rgb_matrix_set_color(ID27_NUM_LOCK_KEY_INDEX, v, v, v);  // white, brightness adjusted
        } else if (user_config.rgb_disable_perkey) {
            rgb_matrix_set_color(ID27_NUM_LOCK_KEY_INDEX, HSV_OFF);  // off
        }

    }
}

#endif  // RGB_MATRIX_ENABLE

/*
 * Extra keys and RGB Toggle handler
 */

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

    switch (keycode) {

        // handle RGB toggle key - this ensures num lock always works
        #ifdef RGB_MATRIX_ENABLE

        case QK_BOOT:
            if (record->event.pressed) {
                rgb_matrix_set_color_all(RGB_MATRIX_MAXIMUM_BRIGHTNESS, 0, 0);  // All red
                rgb_matrix_driver.flush();
            }
            return true;

        case RGB_TOG:
            /* roll through the LED modes
             * |    Level   | Per-key | Underglow |
             * |------------|---------|-----------|
             * | 0 (defalt) |   on    |    on     |
             * |     1      |   OFF   |    on     |
             * |     2      |   on    |    OFF    |
             * |     3      |   OFF   |    OFF    |
             *
             * for ID27_DISABLE_UNDERGLOW
             * |    Level   | Per-key |
             * |------------|---------|
             * | 0 (defalt) |   on    |
             * |     1      |   OFF   |
             */
            if (record->event.pressed) {
                if ( (!user_config.rgb_disable_perkey)
                    #ifndef ID27_DISABLE_UNDERGLOW
                    && (!user_config.rgb_disable_underglow)
                    #endif
                    ) {
                    user_config.rgb_disable_perkey = 1;

                #ifndef ID27_DISABLE_UNDERGLOW

                } else if ( user_config.rgb_disable_perkey && (!user_config.rgb_disable_underglow) ) {
                    user_config.rgb_disable_perkey = 0;
                    user_config.rgb_disable_underglow = 1;
                } else if ( (!user_config.rgb_disable_perkey) && user_config.rgb_disable_underglow ) {
                    user_config.rgb_disable_perkey = 1;

                #endif

                } else {
                    user_config.rgb_disable_perkey = 0;
                    #ifndef ID27_DISABLE_UNDERGLOW
                    user_config.rgb_disable_underglow = 0;
                    #endif
                }
                id27_update_rgb_mode();
            }
            return false;

        case RGB_TPK:
            if (record->event.pressed) {
                user_config.rgb_disable_perkey ^= 1;
                id27_update_rgb_mode();
            }
            return false;

        #ifndef ID27_DISABLE_UNDERGLOW
        case RGB_TUG:
            if (record->event.pressed) {
                user_config.rgb_disable_underglow ^= 1;
                id27_update_rgb_mode();
            }
            return false;
        #endif  // ID27_DISABLE_UNDERGLOW

        case KB_NLED:
            if (record->event.pressed) {
                user_config.led_disable_numlock ^= 1;
                if (!user_config.led_disable_numlock) {
                    rgb_matrix_indicators_advanced_user(ID27_NUM_LOCK_KEY_INDEX, ID27_NUM_LOCK_KEY_INDEX);
                } else if (user_config.rgb_disable_perkey) {
                    rgb_matrix_set_color(ID27_NUM_LOCK_KEY_INDEX, HSV_OFF);  // off
                }
            }
            return false;

        case EE_CLR:
            if (!record->event.pressed) {  // on release
                id27_get_rgb_mode();
            }
            return true;  // let this one pass on

        #endif  // RGB_MATRIX_ENABLE

        // print firmware version
        case KB_VRSN:
            if (!get_mods()) {
                if (!record->event.pressed) {
                    SEND_STRING(QMK_KEYBOARD ":" QMK_KEYMAP " (v" QMK_VERSION ")");
                }
            }
            return false;

        default:
            return true; /* Process all other keycodes normally */
    }
}
