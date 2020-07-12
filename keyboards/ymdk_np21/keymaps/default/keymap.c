#include QMK_KEYBOARD_H

#define _LAYER_0 0
#define _LAYER_1 1
#define _LAYER_2 2
#define _LAYER_3 3

enum custom_keycodes {
  SHORTCUT1 = SAFE_RANGE,
  SHORTCUT2,
  SHORTCUT3,
  SHORTCUT4,
  SHORTCUT5,
  GOTO_LAYER_0,
  GOTO_LAYER_1,
  GOTO_LAYER_2,
  GOTO_LAYER_3
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Qwerty */

  [_LAYER_0] = LAYOUT_ortho_6x4(
    GOTO_LAYER_1, _______, _______, _______,
    LCTL(KC_Z), _______, _______, SHORTCUT1,
    LCTL(KC_Y), _______, _______, SHORTCUT2,
    LCTL(KC_C), _______, _______, SHORTCUT3,
    LCTL(KC_X), _______, _______, SHORTCUT4,
    LCTL(KC_V), _______, _______, SHORTCUT5
  ),

  [_LAYER_1] = LAYOUT_ortho_6x4(
    GOTO_LAYER_2, _______, _______, _______,
    _______, _______, _______, _______,
    _______, _______, _______, _______,
    _______, _______, _______, _______,
    _______, _______, _______, _______,
    _______, _______, _______, _______
  ),

  [_LAYER_2] = LAYOUT_ortho_6x4(
    GOTO_LAYER_3, _______, _______, _______,
    _______, _______, _______, _______,
    _______, _______, _______, _______,
    _______, _______, _______, _______,
    _______, _______, _______, _______,
    _______, _______, _______, _______
  ),


  [_LAYER_3] = LAYOUT_ortho_6x4(
    GOTO_LAYER_0, _______, _______, _______,
    _______, _______, _______, BL_ON,
    _______, _______, _______, BL_OFF,
    _______, _______, _______, BL_INC,
    _______, _______, _______, BL_DEC,
    RESET, _______, _______, BL_BRTG
  )
};

void GoToLayer(int layerNumber){
				
	int times = 1 + layerNumber;	
	int layer = _LAYER_0 + layerNumber;	
	int backlightLevel = 3 + 2 * layerNumber;

	//Go to the target layer
	layer_move(layer);		
	
	//Blink to inform the user that we are in the right layer
	for(int i = 0; i < times; i++){
		
		backlight_enable();
		SEND_STRING(SS_DELAY(100));
		backlight_disable();
		SEND_STRING(SS_DELAY(100));	
	}	
	
	//Set a specific backlight level to inform the user in which layer we are
	backlight_level(backlightLevel);
}


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	
	if(!record->event.pressed)
		return true;
	
	switch (keycode) {
		case GOTO_LAYER_0:
			GoToLayer(0);
			break;
		case GOTO_LAYER_1:
			GoToLayer(1);	
			break;
		case GOTO_LAYER_2:
			GoToLayer(2);	
			break;
		case GOTO_LAYER_3:
			GoToLayer(3);	
			break;
		case SHORTCUT1: 
			SEND_STRING(SS_RWIN("1"));
			break;
		case SHORTCUT2:
			SEND_STRING(SS_RWIN("2"));
			break;
		case SHORTCUT3:
			SEND_STRING(SS_RWIN("3"));
			break;
		case SHORTCUT4:
			SEND_STRING(SS_RWIN("4"));
			break;
		case SHORTCUT5:
			SEND_STRING(SS_RWIN("5"));
			break;
	}
  return true;
}

void matrix_init_kb(void) {
    //    place your keyboard startup
    //    code here
	
	GoToLayer(0);
    matrix_init_user();
}
