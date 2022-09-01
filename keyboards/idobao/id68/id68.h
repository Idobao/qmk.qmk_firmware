// Copyright 2022 Vino Rodrigues (@vinorodrigues)
// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#include "quantum.h"

#ifdef VIA_PROTOCOL_VERSION
    // Allow VIA 1.3.1 to work on QMK >= 0.18.2
    #undef VIA_PROTOCOL_VERSION
    #define VIA_PROTOCOL_VERSION 0x0009
#endif
