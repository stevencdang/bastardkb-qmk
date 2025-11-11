/**
 * Copyright 2021 Charly Delay <charly@codesink.dev> (@0xcharly)
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

#include "pointing_device.h"
#include QMK_KEYBOARD_H


enum charybdis_keymap_layers {
    LAYER_BASE = 0,
    LAYER_NUM,
    LAYER_NAV,
    LAYER_MOUSE,
    LAYER_FUNC,
};

// Define 
#define KC_CTSC RCTL_T(KC_SCLN)
#define KC_CTLA LCTL_T(KC_A)
#define KC_LSHZ LSFT_T(KC_Z)
#define KC_RLSH RSFT_T(KC_SLSH)
#define KC_SPM2 LT(2, KC_SPC)
#define KC_BSM1 LT(1, KC_BSPC)
#define KC_GUTA GUI_T(KC_TAB)
#define KC_CLGV CTL_T(KC_GRV)


// Setup Tapdance
enum {
    TD_MOUSE = 0
};

// Define custom keycode
// enum custom_keycodes {
//     KC_DRGSCRL = SAFE_RANGE,
//     KC_SNIPING,
// };


// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [LAYER_BASE] = LAYOUT(
  // ╭─────────────────────────────────────────────────────────────────╮ ╭─────────────────────────────────────────────────────────────────────────────────╮
          KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                                  KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
  // ╭─────────────────────────────────────────────────────────────────╮ ╭─────────────────────────────────────────────────────────────────────────────────╮
          LALT_T(KC_A), LCTL_T(KC_S), LSFT_T(KC_D), LGUI_T(KC_F), KC_G,              KC_H, 	RGUI_T(KC_J), RSFT_T(KC_K), RCTL_T(KC_L), RALT_T(KC_QUOT),
  // ╭─────────────────────────────────────────────────────────────────╮ ╭─────────────────────────────────────────────────────────────────────────────────╮
          LT(LAYER_MOUSE, KC_Z),    KC_X,    KC_C,    KC_V,    KC_B,                 KC_N,    KC_M, KC_COMM,  KC_DOT, LT(LAYER_MOUSE, KC_SLSH),
  // ╰─────────────────────────────────────────────────────────────────╯ ╰─────────────────────────────────────────────────────────────────────────────────╯
            LT(LAYER_MOUSE, KC_ENT), KC_BSPC,   LT(LAYER_NAV, KC_ESC),               LT(LAYER_NUM, KC_TAB), KC_SPC
  //       ╰───────────────────────────────────────────────────────────╯ ╰───────────────────────────────────────────────────────────╯
  ),

  [LAYER_NUM] = LAYOUT(
  // ╭─────────────────────────────────────────────────────────────────╮ ╭─────────────────────────────────────────────────────────────────────────────────╮
  
       XXXXXXX, KC_7,    KC_8,    KC_9,    KC_MINS,                                 KC_NO,      KC_NO,   KC_SPC,  KC_BSPC, KC_NO,       
  // ╭─────────────────────────────────────────────────────────────────╮ ╭─────────────────────────────────────────────────────────────────────────────────╮
  
       LALT_T(KC_SCLN), LCTL_T(KC_4), LSFT_T(KC_5), LGUI_T(KC_6), KC_EQL,  	        KC_NO, KC_LGUI, KC_LSFT, KC_LCTL, KC_LALT,
  // ╭─────────────────────────────────────────────────────────────────╮ ╭─────────────────────────────────────────────────────────────────────────────────╮
  
       KC_GRV,  KC_1,    KC_2,     KC_3,   KC_BSLS,                                 KC_DOT,     KC_LBRC, KC_RBRC, LSFT(KC_LBRC), LSFT(KC_RBRC),
  // ╰─────────────────────────────────────────────────────────────────╯ ╰─────────────────────────────────────────────────────────────────────────────────╯
  
      			 KC_MS_BTN1, KC_0,  MO(LAYER_FUNC),                                 KC_NO,   KC_NO
  //       ╰───────────────────────────────────────────────────────────╯ ╰───────────────────────────────────────────────────────────╯
  ),

  [LAYER_NAV] = LAYOUT(
  // ╭─────────────────────────────────────────────────────────────────╮ ╭─────────────────────────────────────────────────────────────────────────────────╮
       MO(LAYER_FUNC), KC_KB_MUTE, KC_KB_VOLUME_DOWN, KC_KB_VOLUME_UP, KC_MEDIA_PLAY_PAUSE,           KC_NO, KC_TAB, KC_SPC, KC_BSPC, KC_NO,
  // ╭─────────────────────────────────────────────────────────────────╮ ╭─────────────────────────────────────────────────────────────────────────────────╮
       KC_LALT, KC_LCTL, KC_LSFT, KC_LGUI, KC_NO,                                           KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_NO,
  // ╭─────────────────────────────────────────────────────────────────╮ ╭─────────────────────────────────────────────────────────────────────────────────╮
       G(KC_Z), G(KC_X), G(KC_C),  G(KC_V), KC_NO,                                          KC_HOME,  KC_PGDN, KC_PGUP, KC_END, KC_NO,
  // ╰─────────────────────────────────────────────────────────────────╯ ╰─────────────────────────────────────────────────────────────────────────────────╯
                         KC_NO,   KC_NO,   KC_NO,                                           MO(LAYER_FUNC), KC_NO
  //       ╰───────────────────────────────────────────────────────────╯ ╰───────────────────────────────────────────────────────────╯
  ),

  [LAYER_MOUSE] = LAYOUT(
  // ╭─────────────────────────────────────────────────────────────────╮ ╭────────────────────────────────────────────────────────────────────────────────╮
       KC_NO, POINTER_DEFAULT_DPI_FORWARD,      POINTER_DEFAULT_DPI_REVERSE,  POINTER_SNIPING_DPI_FORWARD,     POINTER_SNIPING_DPI_REVERSE,	        KC_NO, KC_NO, KC_NO, KC_NO, TO(LAYER_BASE),   		                  
  // ╭─────────────────────────────────────────────────────────────────╮ ╭─────────────────────────────────────────────────────────────────────────────────╮
      KC_LALT, KC_LCTL, KC_LSFT, KC_LGUI,      SNIPING_MODE_TOGGLE,        	   		         KC_NO, KC_LGUI, KC_LSFT, KC_LCTL, KC_LALT,          
  // ╭─────────────────────────────────────────────────────────────────╮ ╭─────────────────────────────────────────────────────────────────────────────────╮
    KC_MS_BTN3,   KC_NO,      KC_A,      KC_MS_BTN2,   KC_MS_BTN1,        	   		  KC_MS_BTN1, KC_MS_BTN2, DRGSCRL, SNIPING,   KC_NO,
  // ╰─────────────────────────────────────────────────────────────────╯ ╰─────────────────────────────────────────────────────────────────────────────────╯
                                        KC_NO, KC_NO, KC_NO,                   DRAGSCROLL_MODE_TOGGLE, SNIPING_MODE_TOGGLE
  //       ╰───────────────────────────────────────────────────────────╯ ╰───────────────────────────────────────────────────────────╯
  ),


  [LAYER_FUNC] = LAYOUT(
  // ╭─────────────────────────────────────────────────────────────────╮ ╭─────────────────────────────────────────────────────────────────────────────────╮
      KC_F9,      KC_F10,     KC_F11,	  KC_F12,   KC_NO,	                        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,   		                  
  // ╭─────────────────────────────────────────────────────────────────╮ ╭─────────────────────────────────────────────────────────────────────────────────╮
      KC_F5,      KC_F6,      KC_F7,      KC_F8,    KC_NO,        	   		         KC_NO, KC_LGUI, KC_LSFT, KC_LCTL, KC_LALT,          
  // ╭─────────────────────────────────────────────────────────────────╮ ╭─────────────────────────────────────────────────────────────────────────────────╮
      KC_F1,      KC_F2,      KC_F3,      KC_F4,     KC_MS_BTN1,        	   		        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,   		                  
  // ╰─────────────────────────────────────────────────────────────────╯ ╰─────────────────────────────────────────────────────────────────────────────────╯
                                        KC_NO, KC_NO, KC_NO,                   KC_NO, KC_NO
  //       ╰───────────────────────────────────────────────────────────╯ ╰───────────────────────────────────────────────────────────╯
  ),
};
// clang-format on
//////////// Test zone///////////





///////////////////////////////

// Declare combos
enum combos {
    ZX_Q,
    DTSL_P,
    XC_ESC,
    CMDT_TAB,
    CV_MINS,
    QT_BOOT,
    YP_BOOT,
    GH_COMBO
    // ZC_SCROLL,
    // XV_SNIPE
};

// Define combos
const uint16_t PROGMEM zx_combo[] = {KC_Z, KC_X, COMBO_END};
const uint16_t PROGMEM dtsl_combo[] = {KC_DOT, KC_SLSH, COMBO_END};
// const uint16_t PROGMEM we_combo[] = {KC_W, KC_E, COMBO_END};
const uint16_t PROGMEM xc_combo[] = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM cmdt_combo[] = {KC_COMM, KC_DOT, COMBO_END};
const uint16_t PROGMEM cv_combo[] = {KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM qt_combo[] = {KC_Q, KC_T, COMBO_END};
const uint16_t PROGMEM yp_combo[] = {KC_Y, KC_P, COMBO_END};
const uint16_t PROGMEM gh_combo[] = {KC_G, KC_H, COMBO_END};
// const uint16_t PROGMEM zc_combo[] = {KC_Z, KC_C, COMBO_END};
// const uint16_t PROGMEM xv_combo[] = {KC_X, KC_V, COMBO_END};

// Associate combos with values to send
// Removed from list [WE_ENT] = COMBO(we_combo, KC_ENT),
combo_t key_combos[COMBO_COUNT] = {
    [ZX_Q] = COMBO(zx_combo, KC_Q),
    [DTSL_P] = COMBO(dtsl_combo, KC_P),
    [XC_ESC] = COMBO(xc_combo, KC_ESC),
    [CMDT_TAB] = COMBO(cmdt_combo, KC_TAB),
    [CV_MINS] = COMBO(cv_combo, KC_MINS),
    [QT_BOOT] = COMBO(qt_combo, QK_BOOT),
    [YP_BOOT] = COMBO(yp_combo, QK_BOOT),
    [GH_COMBO] = COMBO(gh_combo, CW_TOGG),
    // [ZC_SCROLL] = COMBO(zc_combo, DRAGSCROLL_MODE_TOGGLE),
    // [XV_SNIPE] = COMBO(xv_combo, SNIPING_MODE_TOGGLE),
};



void matrix_scan_user(void) {
    // if (trackball_moved) {
    //     // Toggle the special layer
    //     layer_on(LAYER_FUNC);
    //     trackball_moved = false;
    // }
}

// Setup Tapdance
// void td_mouse_finished(tap_dance_state_t *state, void *user_data) {
//     if (state->count == 1) {
//         if (state->pressed) {
//             layer_on(LAYER_MOUSE); // Hold: activate layer
//         } else {
//             tap_code(KC_SLSH); // Single tap: send '/'
//         }
//     } else if (state->count == 2) {
//         layer_invert(LAYER_MOUSE); // Double tap: toggle layer
//     }
// };

// void td_mouse_reset(tap_dance_state_t *state, void *user_data) {
//     if (state->count == 1 && state->pressed) {
//         layer_off(LAYER_MOUSE); // Release hold
//     }
// };
// tap_dance_action_t tap_dance_actions[] = {
//     [TD_MOUSE] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_mouse_finished, td_mouse_reset),
// };

// Function to be called when custom keycode is pressed
// void toggle_dragscroll(void) {
//     // Your custom function code here
//     // For example, send a string
//     bool dragscroll_enabled = charybdis_get_pointer_dragscroll_enabled();
//     charybdis_set_pointer_dragscroll_enabled(dragscroll_enabled);
// }



// Process custom keycode
// bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//     switch (keycode) {
//         // case KC_DRGSCRL:
//         //     if (record->event.pressed) {
//         //         // toggle_dragscroll();
//         //         // set_scrolling = !set_scrolling;
//         //     }
//         //     return false; // Skip all further processing of this key
//         case KC_SNIPING:
//             if (record->event.pressed) {
//                 charybdis_set_pointer_sniping_enabled(!charybdis_get_pointer_sniping_enabled());
//             }
//             return false; // Skip all further processing of this key
//         default:
//             return true; // Process all other keycodes normally
//     }
// }
void pointing_device_init_user(void) {
    set_auto_mouse_layer(LAYER_MOUSE);
    set_auto_mouse_enable(true);
}

