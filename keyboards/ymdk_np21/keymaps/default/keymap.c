#include QMK_KEYBOARD_H

#define _LAYER_0 0
#define _LAYER_1 1
#define _LAYER_2 2
#define _LAYER_3 3

enum custom_keycodes {
  
  //Jumping between layers
  GOTO_LAYER_0,
  GOTO_LAYER_1,
  GOTO_LAYER_2,
  GOTO_LAYER_3,
  
  //Shortcuts
  SHORTCUT1 = SAFE_RANGE,
  SHORTCUT2,
  SHORTCUT3,
  SHORTCUT4,
  SHORTCUT5,
  SHORTCUT6,
  SHORTCUT7,
  SHORTCUT8,
  
  //R# shortcuts
  TestCop,
  SearchType,
  CleanupCodeFile,
  Refactor,
  ExtractVariable,
  
  FindUsages,
  GoToImplementation,
  GoToDeclaration,
  Hierarchy,
  RunAllTestsInCurrentClass,
  RunAllTestsInSolution
  //Run all tests in current class Ctrl G Ctrl X chord (via testcop)
  //Run all tests in solution Ctrl T ,L chord
  
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  
  //Shortcut layer
  [_LAYER_0] = LAYOUT_ortho_6x4(
    GOTO_LAYER_1, _______, _______, _______,
	
    SHORTCUT1, SHORTCUT2, SHORTCUT3, SHORTCUT4,
    SHORTCUT5, SHORTCUT6, SHORTCUT7, SHORTCUT8,	
    _______, _______, _______, _______,
    LCTL(KC_Z), LCTL(KC_Y), _______, _______,
    LCTL(KC_C), LCTL(KC_X), LCTL(KC_V), _______
  ),

	//R# Layer
  [_LAYER_1] = LAYOUT_ortho_6x4(
    GOTO_LAYER_2, _______, _______, _______,
	
    TestCop, SearchType, _______, _______,
    CleanupCodeFile, _______, _______, _______,
    RunAllTestsInCurrentClass, RunAllTestsInSolution, _______, _______,
    FindUsages, GoToImplementation, GoToDeclaration , Hierarchy,
    Refactor, ExtractVariable, _______, _______
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
    GOTO_LAYER_0, _______, _______, RESET,
	
    _______, _______, _______, BL_ON,
    _______, _______, _______, BL_OFF,
    _______, _______, _______, BL_INC,
    _______, _______, _______, BL_DEC,
    _______, _______, _______, BL_BRTG
  )
};

void GoToLayer(int layerNumber){
				
	int times = 1 + layerNumber;	
	int layer = _LAYER_0 + layerNumber;
	
	int currentBacklightLevel = get_backlight_level();
	int blinkBacklightLevel = 0;
	
	//This ensures there is blinking even if the backlight is disabled
	if(currentBacklightLevel == blinkBacklightLevel){
		blinkBacklightLevel = 3;
	}

	//Go to the target layer
	layer_move(layer);		
	
	//Blink to inform the user that we are in the right layer
	for(int i = 0; i < times; i++){
		
		backlight_level(blinkBacklightLevel);
		SEND_STRING(SS_DELAY(100));
		backlight_level(currentBacklightLevel);
		SEND_STRING(SS_DELAY(100));	
	}
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
		case SHORTCUT6:
			SEND_STRING(SS_RWIN("6"));
			break;
		case SHORTCUT7:
			SEND_STRING(SS_RWIN("7"));
			break;
		case SHORTCUT8:
			SEND_STRING(SS_RWIN("8"));
			break;
		case TestCop:
			SEND_STRING(SS_LCTL("gt"));		
			break;
		case SearchType:
			SEND_STRING(SS_LCTL("n"));		
			break;
		case CleanupCodeFile:
			SEND_STRING(SS_DOWN(X_LCTRL)SS_DOWN(X_LALT)SS_TAP(X_F)SS_UP(X_LALT)SS_UP(X_LCTRL)SS_TAP(X_ENTER));		
			break;
		case Refactor:
			SEND_STRING(SS_DOWN(X_LCTRL)SS_DOWN(X_LSHIFT)SS_TAP(X_R)SS_UP(X_LSHIFT)SS_UP(X_LCTRL));		
			break;
		case ExtractVariable:
			SEND_STRING(SS_DOWN(X_LCTRL)SS_DOWN(X_LALT)SS_TAP(X_V)SS_UP(X_LALT)SS_UP(X_LCTRL));		
			break;
		case FindUsages:
			SEND_STRING(SS_DOWN(X_LALT)SS_TAP(X_F7)SS_UP(X_LALT));		
			break;
		case GoToImplementation:
			SEND_STRING(SS_DOWN(X_LCTRL)SS_DOWN(X_LSHIFT)SS_DOWN(X_LALT)SS_TAP(X_B)SS_UP(X_LALT)SS_UP(X_LSHIFT)SS_UP(X_LCTRL));		
			break;
		case GoToDeclaration:
			SEND_STRING(SS_DOWN(X_LCTRL)SS_TAP(X_B)SS_UP(X_LCTRL));		
			break;
		case Hierarchy:
			SEND_STRING(SS_DOWN(X_LCTRL)SS_DOWN(X_LALT)SS_TAP(X_H)SS_UP(X_LALT)SS_UP(X_LCTRL));		
			break;
		case RunAllTestsInCurrentClass:
			SEND_STRING(SS_LCTL("gx"));		
			break;
		case RunAllTestsInSolution:
			SEND_STRING(SS_LCTL("t")"l");		
			break;
	}
  return true;
}

void matrix_init_kb(void) {
    //    place your keyboard startup
    //    code here
	
	backlight_level(3);
	GoToLayer(0);
    matrix_init_user();
}
