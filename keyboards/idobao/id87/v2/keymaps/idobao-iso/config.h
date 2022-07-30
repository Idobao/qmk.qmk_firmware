// Copyright 2022 Vino Rodrigues (@vinorodrigues)
// SPDX-License-Identifier: GPL-2.0-or-later

#define DYNAMIC_KEYMAP_LAYER_COUNT 3

#ifndef ID87_IS_ISO
    #error Please define `OPT_DEFS += -DID87_IS_ISO` in rules.mk
#endif

#define VIA_EEPROM_LAYOUT_OPTIONS_DEFAULT 0x03  // override of the layout options default value.
