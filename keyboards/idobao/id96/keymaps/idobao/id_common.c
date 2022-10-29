// Copyright 2022 Vino Rodrigues (@vinorodrigues)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "id_common.h"
#include "version.h"

bool __k_consumer(keyrecord_t *record, uint16_t data) {
    if (record->event.pressed) {
        host_consumer_send(data);
    } else {
        host_consumer_send(0);
    }
    return false;  // Skip all further processing of this key
}

bool __2k_code(keyrecord_t *record, uint16_t data1, uint16_t data2) {
    if (record->event.pressed) {
        register_code(data1);
        register_code(data2);
    } else {
        unregister_code(data2);
        unregister_code(data1);
    }
    return false;  // Skip all further processing of this key
}

bool __3k_code(keyrecord_t *record, uint16_t data1, uint16_t data2, uint16_t data3) {
    if (record->event.pressed) {
        register_code(data1);
        register_code(data2);
        register_code(data3);
    } else {
        unregister_code(data3);
        unregister_code(data2);
        unregister_code(data1);
    }
    return false;  // Skip all further processing of this key
}

bool process_record_idobao(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        // macOS keys
        case KC_MISSION_CONTROL: return __k_consumer(record, _AC_SHOW_ALL_WINDOWS); break;
        case KC_LAUNCHPAD: return __k_consumer(record, _AC_SHOW_ALL_APPS); break;
        case KC_SIRI: return __2k_code(record, KC_LOPT, KC_SPACE); break;
        case KC_SCREEN_SHOT: return __3k_code(record, KC_LSFT, KC_LCMD, KC_4); break;

        // Windows keys
        case KC_TASK_VIEW: return __2k_code(record, KC_LWIN, KC_TAB); break;
        case KC_FILE_EXPLORER: return __2k_code(record, KC_LWIN, KC_E); break;
        case KC_CORTANA: return __2k_code(record, KC_LWIN, KC_C); break;

        // proprietary keys
        case KC_CLEAR_EEPROM:
            eeconfig_init_quantum();
            soft_reset_keyboard();
            return false;
            break;

        case KC_SHOW_VERSION:
            if (!get_mods()) {
                if (!record->event.pressed) {
                    SEND_STRING(QMK_KEYBOARD ":" QMK_KEYMAP " (v" QMK_VERSION ")");

                    #ifdef VIA_ENABLE
                    /* show the Layout Options stored in VIA */
                    char str[9];
                    itoa(via_get_layout_options(), str, 16);
                    SEND_STRING(" [0x");
                    send_string_with_delay(str, 0);
                    SEND_STRING("]");
                    #endif
                } else {
                    host_consumer_send(0);
                }
            }
            return false;
            break;

        // Default
        default:
            return true;   // Process all other keycodes normally
    }
}
