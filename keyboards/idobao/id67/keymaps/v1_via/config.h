/* Copyright 2021 Tybera
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

/* ========================================
 * This keymap reverts to the RGB Lighting
 * library that was used in the V1 code
 * ===================================== */

#pragma once

#ifdef RGB_MATRIX_ENABLE
    #error 'Oops 1'
    #undef RGB_MATRIX_ENABLE
#endif

#ifndef RGBLIGHT_ENABLE
    #error 'Oops 2'
    #define RGBLIGHT_ENABLE
#endif

#ifdef RGB_DI_PIN
    #define RGBLED_NUM 77
    #define RGBLIGHT_HUE_STEP 8
    #define RGBLIGHT_SAT_STEP 8
    #define RGBLIGHT_VAL_STEP 8
    #define RGBLIGHT_LIMIT_VAL 150  // The maximum brightness level
    #define RGBLIGHT_SLEEP          // If defined, the RGB lighting will be switched off when the host goes to sleep
    /*== all animations enable ==*/
    // #define RGBLIGHT_ANIMATIONS
    /*== or choose animations ==*/
    #define RGBLIGHT_EFFECT_BREATHING
    #define RGBLIGHT_EFFECT_RAINBOW_MOOD
    #define RGBLIGHT_EFFECT_RAINBOW_SWIRL
    #define RGBLIGHT_EFFECT_SNAKE
    #define RGBLIGHT_EFFECT_KNIGHT
    #define RGBLIGHT_EFFECT_CHRISTMAS
    #define RGBLIGHT_EFFECT_STATIC_GRADIENT
    #define RGBLIGHT_EFFECT_RGB_TEST
    #define RGBLIGHT_EFFECT_ALTERNATING
#endif
