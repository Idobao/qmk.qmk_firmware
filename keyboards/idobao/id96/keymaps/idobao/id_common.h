// Copyright 2022 Vino Rodrigues (@vinorodrigues)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include "stdint.h"
#include "quantum_keycodes.h"

#ifndef VIA_ENABLE
    #warning Expecting VIA to be enabled
#endif

enum custom_keycodes {
    KC_MISSION_CONTROL = USER00,
    KC_LAUNCHPAD,
    KC_SIRI,
    KC_TASK_VIEW,
    KC_FILE_EXPLORER,
    KC_SCREEN_SHOT,
    KC_CORTANA,
    KC_USER08,
    KC_CLEAR_EEPROM,
    KC_SHOW_VERSION
};

#define IK_MCTL KC_MISSION_CONTROL
#define IK_LPAD KC_LAUNCHPAD
#define IK_SIRI KC_SIRI
#define IK_TASK KC_TASK_VIEW
#define IK_FLXP KC_FILE_EXPLORER
#define IK_SNAP KC_SCREEN_SHOT
#define IK_CRTA KC_CORTANA
#define IK_CEEP KC_CLEAR_EEPROM
#define IK_VRSN KC_SHOW_VERSION

enum my_consumer_usages {
    _AC_SHOW_ALL_WINDOWS = 0x29F,  // mapped to IK_MCTL
    _AC_SHOW_ALL_APPS    = 0x2A0   // mapped to IK_LPAD
};

bool process_record_idobao(uint16_t keycode, keyrecord_t *record);
