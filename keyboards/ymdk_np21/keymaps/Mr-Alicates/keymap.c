#include QMK_KEYBOARD_H

enum layer_names {
    _LAYER_0,
	_LAYER_1
};

enum custom_keycodes {  
  GOTO_LAYER_0 = SAFE_RANGE,
  GOTO_LAYER_1
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_LAYER_0] = LAYOUT_ortho_6x4(
        GOTO_LAYER_0,	GOTO_LAYER_1,	BL_DEC,			BL_INC,
        KC_NUMLOCK,		KC_PSLS,		KC_PAST,		KC_PMNS,
        KC_P7,			KC_P8,			KC_P9,			KC_PPLS,
        KC_P4,			KC_P5,			KC_P6,			KC_PPLS,
        KC_P1,			KC_P2,			KC_P3,			KC_PENT,
        KC_P0,			KC_P0,			KC_PDOT,		KC_PENT
    ),

	[_LAYER_1] = LAYOUT_ortho_6x4(
        _______,		_______,		_______,		_______,
        KC_NUMLOCK,		XXXXXXX,		XXXXXXX,		KC_MS_WH_UP,
        XXXXXXX,		KC_MS_UP,		XXXXXXX,		KC_MS_BTN3,
        KC_MS_LEFT,		XXXXXXX,		KC_MS_RIGHT,	KC_MS_WH_DOWN,
        XXXXXXX,		KC_MS_DOWN,		XXXXXXX,		XXXXXXX,
        XXXXXXX,		XXXXXXX,		KC_MS_BTN2,		KC_MS_BTN1
    )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    
	switch (keycode) 
	{
		case GOTO_LAYER_0:
			if(record->event.pressed)
				layer_move(_LAYER_0);	
			break;
		case GOTO_LAYER_1:
			if(record->event.pressed)
				layer_move(_LAYER_1);	
			break;
    }
    return true;
};

void matrix_init_kb(void) {
	
	layer_move(_LAYER_0);	
	matrix_init_user();
}