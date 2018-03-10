#include "org60.h"
#include "action_layer.h"

//#define RGB_DI_PIN F6
//#define RGBLED_NUM 20   
//#define RGBLIGHT_HUE_STEP 10
//#define RGBLIGHT_SAT_STEP 17
//#define RGBLIGHT_VAL_STEP 17

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  // 0: Base Layer
  KEYMAP(
      KC_GESC,  KC_1,    KC_2,    KC_3,    KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,    KC_0,    KC_MINS,  KC_EQL,  KC_BSPC  ,  KC_NO,    \
      KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,    KC_P,    KC_LBRC,  KC_RBRC,           KC_BSLS,   \
      TO(1),   KC_A,    KC_S,    KC_D,    KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,    KC_SCLN, KC_QUOT,  KC_NO,             KC_ENT,    \
      KC_LSFT, KC_NO,   KC_Z,    KC_X,    KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM, KC_DOT,  KC_SLASH,  KC_NO  ,KC_RSHIFT,    KC_NO,      \
      KC_LCTL, KC_LGUI, KC_LALT,                          KC_SPC,                          KC_RALT, KC_CAPS,     KC_NO, RGB_TOG,  KC_RCTL),

  // 1: Function Layer
  KEYMAP(
      KC_GRV,   KC_F1,   KC_F2,   KC_F3,   KC_F4,    KC_F5,  KC_F6,  KC_F7,  KC_F8,  KC_F9,   KC_F10,  KC_F11,   KC_F12,  KC_BSPC,   KC_NO,    \
      RGB_TOG,   RGB_MOD, KC_UP,   RGB_RMOD, RGB_M_B,  RGB_M_R,KC_KP_7,KC_KP_8,  KC_KP_9, KC_KP_PLUS,   KC_KP_MINUS, KC_SLCK,  KC_PAUS,           KC_BSLS,    \
      TO(0),   KC_LEFT, KC_DOWN, KC_RIGHT, RGB_M_SW, RGB_M_SN, KC_KP_4,KC_KP_5,  KC_KP_6, KC_KP_ASTERISK,   KC_KP_SLASH, KC_PGUP,  KC_NO,             KC_ENT,    \
      RGB_VAI, KC_NO, RGB_HUI, RGB_HUD,  BL_STEP, KC_NO ,KC_KP_0,KC_KP_1,  KC_KP_2, KC_KP_3, KC_KP_EQUAL,  KC_RSFT,  KC_NO  ,KC_NUMLOCK,  KC_NO,      \
      RGB_VAD, RGB_SAI, RGB_SAD,                          KC_SPC,                          KC_VOLU, KC_VOLD,     KC_NO, KC_MUTE,KC_NO),

};

// Custom Actions
const uint16_t PROGMEM fn_actions[] = {
    [0] = ACTION_LAYER_MOMENTARY(1),  // to Fn overlay
};

// Macros
const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {

  // MACRODOWN only works in this function
  switch(id) {
    case 0:
      if (record->event.pressed) { register_code(KC_RSFT); }
      else { unregister_code(KC_RSFT); }
      break;
  }

  return MACRO_NONE;
};

// Loop
void matrix_scan_user(void) {
  // Empty
};
