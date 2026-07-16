/* Copyright 2026 QMK
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

#include QMK_KEYBOARD_H

enum layer_names {
    _BASE,
    _MOUSE,
    _LIGHTS
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

// Default keymap
//    [_BASE] = LAYOUT_ortho_6x4(
//        KC_ESC,  KC_TAB,  KC_BSPC, MO(_LIGHTS),
//        KC_NUM,  KC_PSLS, KC_PAST, KC_PMNS,
//        KC_P7,   KC_P8,   KC_P9,   KC_PPLS,
//        KC_P4,   KC_P5,   KC_P6,   KC_PPLS,
//        KC_P1,   KC_P2,   KC_P3,   KC_PENT,
//        KC_P0,   KC_DOT,  KC_PDOT, KC_PENT
//    ),
//
//    [_LIGHTS] = LAYOUT_ortho_6x4(
//        _______, _______, _______, _______,
//        _______, _______, _______, _______,
//        _______, BL_ON,   _______, BL_UP, 
//        _______, BL_TOGG, _______, BL_UP, 
//        _______, BL_OFF,  _______, BL_DOWN,
//        _______, _______, _______, BL_DOWN
//    )

//On this keymap, usb is on the right side
//First row is right column

    [_BASE] = LAYOUT_ortho_4x6(
        _______, _______, _______, _______,_______, TO(_BASE),
        _______, _______, _______, _______,_______, TO(_MOUSE),
        _______, _______, _______, _______,_______, TO(_LIGHTS),
        _______, _______, _______, _______,_______, _______
    ),

    [_MOUSE] = LAYOUT_ortho_4x6(
        MS_BTN1, MS_UP  , MS_BTN2, MS_WHLU,_______, TO(_BASE),
        MS_LEFT, MS_DOWN, MS_RGHT, MS_WHLD,_______, TO(_MOUSE),
        _______, _______, _______, _______,_______, TO(_LIGHTS),
        _______, _______, _______, _______,_______, _______
    ),

    [_LIGHTS] = LAYOUT_ortho_4x6(
        BL_ON  , _______, BL_OFF , BL_UP  ,_______, TO(_BASE),
        _______, _______, _______, BL_DOWN,_______, TO(_MOUSE),
        _______, _______, _______, _______,_______, TO(_LIGHTS),
        _______, _______, _______, _______,_______, _______
    )
};
