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

//On this keymap, usb is on the right side
//First row is right column

    [_BASE] = LAYOUT_ortho_4x6(
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, DF(_BASE),
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, DF(_MOUSE),
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, DF(_LIGHTS),
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO
    ),

    [_MOUSE] = LAYOUT_ortho_4x6(
        MS_BTN1, MS_UP  , MS_BTN2, MS_WHLU, KC_NO, DF(_BASE),
        MS_LEFT, MS_DOWN, MS_RGHT, MS_WHLD, KC_NO, DF(_MOUSE),
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, DF(_LIGHTS),
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO
    ),

    [_LIGHTS] = LAYOUT_ortho_4x6(
        BL_ON, KC_NO, BL_OFF, BL_UP  , KC_NO, DF(_BASE),
        KC_NO, KC_NO, KC_NO,  BL_DOWN, KC_NO, DF(_MOUSE),
        KC_NO, KC_NO, KC_NO,  KC_NO,   KC_NO, DF(_LIGHTS),
        KC_NO, KC_NO, KC_NO,  KC_NO,   KC_NO, KC_NO
    )
};

#define LED D0
#define WAIT 100

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
		if (record->event.pressed)
		{
			return true;
		}
		
		switch (keycode) {
		case DF(_BASE):
			gpio_toggle_pin(LED);
			wait_ms(WAIT);
			gpio_toggle_pin(LED);
			return true;
		
		case DF(_MOUSE):
			gpio_toggle_pin(LED);
			wait_ms(WAIT);
			gpio_toggle_pin(LED);
			wait_ms(WAIT);
			gpio_toggle_pin(LED);
			wait_ms(WAIT);
			gpio_toggle_pin(LED);
			return true;
		
		case DF(_LIGHTS):
			gpio_toggle_pin(LED);
			wait_ms(WAIT);
			gpio_toggle_pin(LED);
			wait_ms(WAIT);
			gpio_toggle_pin(LED);
			wait_ms(WAIT);
			gpio_toggle_pin(LED);
			wait_ms(WAIT);
			gpio_toggle_pin(LED);
			wait_ms(WAIT);
			gpio_toggle_pin(LED);
			return true;
		
		default:
			return true; // Process all other keycodes normally
  }
}