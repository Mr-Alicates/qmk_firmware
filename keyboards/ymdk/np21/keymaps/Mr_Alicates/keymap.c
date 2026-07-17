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
    _CURSOR,
    _LIGHTS
};

enum my_keycodes {
  BUILD = SAFE_RANGE,
  CLEAN,
  GOOGLE_MEET_MUTE,
  GOOGLE_MEET_CAM,
  GOOGLE_MEET_HAND,
  HTTP_1,
  HTTP_2,
  HTTP_3,
  HTTP_4,
  HTTP_5  
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

//On this keymap, usb is on the right side
//First row is right column

    [_BASE] = LAYOUT_ortho_4x6(
        KC_NO,               KC_NO,              KC_NO,               KC_NO,        KC_NO,     DF(_LIGHTS),
        HTTP_1,              HTTP_2,             HTTP_3,              HTTP_4,       HTTP_5,    DF(_CURSOR),
        GOOGLE_MEET_MUTE,    GOOGLE_MEET_CAM,    GOOGLE_MEET_HAND,    KC_F11,       KC_NO,     DF(_MOUSE),
        BUILD,               CLEAN,              KC_NO,               KC_NO,        KC_NO,     DF(_BASE)
    ),

    [_MOUSE] = LAYOUT_ortho_4x6(
        MS_BTN1,             MS_UP  ,            MS_BTN2,             MS_WHLU,      KC_NO,     DF(_LIGHTS),
        MS_LEFT,             MS_DOWN,            MS_RGHT,             MS_BTN3,      KC_NO,     DF(_CURSOR),
        KC_NO,               KC_NO,              KC_NO,               MS_WHLD,      KC_NO,     DF(_MOUSE),
        KC_NO,               KC_NO,              KC_NO,               KC_NO,        KC_NO,     DF(_BASE)
    ),

    [_CURSOR] = LAYOUT_ortho_4x6(
        KC_NO,               KC_UP,              KC_NO,               KC_PGUP,      KC_NO,     DF(_LIGHTS),
        KC_LEFT,             KC_DOWN,            KC_RGHT,             KC_NO,        KC_NO,     DF(_CURSOR),
        KC_NO,               KC_NO,              KC_NO,               KC_PGDN,      KC_NO,     DF(_MOUSE),
        KC_NO,               KC_NO,              KC_NO,               KC_NO,        KC_NO,     DF(_BASE)
    ),

    [_LIGHTS] = LAYOUT_ortho_4x6(
        BL_ON,               KC_NO,              BL_OFF,              BL_UP  ,      KC_NO,     DF(_LIGHTS),
        KC_NO,               KC_NO,              KC_NO,               KC_NO,        KC_NO,     DF(_CURSOR),
        KC_NO,               KC_NO,              KC_NO,               BL_DOWN,      KC_NO,     DF(_MOUSE),
        QK_BOOTLOADER,       KC_NO,              KC_NO,               KC_NO,        KC_NO,     DF(_BASE)
    )
};


#define LED D0
#define WAIT 100

void blink(int blinks){

	for(int i=0;i<= blinks; i++){
		gpio_toggle_pin(LED);
		wait_ms(WAIT);
		gpio_toggle_pin(LED);
		wait_ms(WAIT);
	}
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
		if (record->event.pressed)
		{
			return true;
		}
		
		switch (keycode) {
		case DF(_BASE):
			blink(_BASE);
			break;
		
		case DF(_MOUSE):
			blink(_MOUSE);
			break;
		
		case DF(_CURSOR):
			blink(_CURSOR);
			break;
		
		case DF(_LIGHTS):
			blink(_LIGHTS);
			break;
		
		case BUILD:
			SEND_STRING(SS_DOWN(X_LCTL)SS_DOWN(X_LSFT)"b"SS_UP(X_LCTL)SS_UP(X_LSFT));
			break;
		
		case CLEAN:
			SEND_STRING(SS_DOWN(X_LSFT)SS_DOWN(X_LALT)"b"SS_UP(X_LSFT)SS_UP(X_LALT));
			break;
		
		case GOOGLE_MEET_MUTE:
			SEND_STRING(SS_DOWN(X_LCTL)"d"SS_UP(X_LCTL));
			break;
		
		case GOOGLE_MEET_CAM:
			SEND_STRING(SS_DOWN(X_LCTL)"e"SS_UP(X_LCTL));
			break;
		
		case GOOGLE_MEET_HAND:
			SEND_STRING(SS_DOWN(X_LCTL)SS_DOWN(X_LALT)"h"SS_UP(X_LCTL)SS_UP(X_LALT));
			break;
			
		case HTTP_1:
			SEND_STRING(HTTP_1_STR);
			break;
			
		case HTTP_2:
			SEND_STRING(HTTP_2_STR);
			break;
			
		case HTTP_3:
			SEND_STRING(HTTP_3_STR);
			break;
			
		case HTTP_4:
			SEND_STRING(HTTP_4_STR);
			break;
			
		case HTTP_5:
			SEND_STRING(HTTP_5_STR);
			break;
		
		
		default:
			break;
  }
		
	return true; // Process all other keycodes normally
}
