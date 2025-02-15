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

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [LAYER_BASE] = LAYOUT(
  // ╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
          KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
          LALT_T(KC_A), LCTL_T(KC_S), LSFT_T(KC_D), LGUI_T(KC_F), KC_G,              KC_H, 	RGUI_T(KC_J), RSFT_T(KC_K), RCTL_T(KC_L), RALT_T(KC_QUOT),
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,       KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,
  // ╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
                         KC_ENT, KC_BSPC,   TL_UPPR,      TL_LOWR, KC_SPC
  //                   ╰───────────────────────────╯ ╰──────────────────╯
  ),

  [LAYER_NUM] = LAYOUT(
  // ╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
       XXXXXXX, KC_7,    KC_8,    KC_9,    KC_MINS,    KC_NO,      KC_NO,   KC_SPC,  KC_BSPC, KC_NO,       
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       LALT_T(KC_SCLN), LCTL_T(KC_4), LSFT_T(KC_5), LGUI_T(KC_6), KC_EQL,  	        KC_NO, KC_LGUI, KC_LSFT, KC_LCTL, KC_LALT,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       KC_GRV,  KC_1,    KC_2,     KC_3,   KC_BSLS,    KC_DOT,     KC_LBRC, KC_RBRC, LSFT(KC_LBRC), LSFT(KC_RBRC),
  // ╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
      			 XXXXXXX, KC_0,	  MO(LAYER_FUNC),   KC_NO,   KC_NO
  //                   ╰───────────────────────────╯ ╰──────────────────╯
  ),

  [LAYER_NAV] = LAYOUT(
  // ╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
       XXXXXXX, KC_KB_MUTE, KC_KB_VOLUME_DOWN, KC_KB_VOLUME_UP, KC_MEDIA_PLAY_PAUSE,           KC_NO, KC_TAB, KC_SPC, KC_BSPC, KC_NO,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       KC_TRNS,   KC_LALT, KC_LCTL, KC_LSFT, KC_LGUI,  KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_NO,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       G(KC_Z), G(KC_X), G(KC_C),  G(KC_V), KC_NO,     KC_HOME,  KC_PGDN, KC_PGUP, KC_END, KC_NO,
  // ╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
                         KC_NO,   KC_NO,   KC_NO,      MO(LAYER_FUNC), KC_NO
  //                   ╰───────────────────────────╯ ╰──────────────────╯
  ),

  [LAYER_FUNC] = LAYOUT(
  // ╭───────────────────-----------──────────────────────────────────────────╮           ╭───────────────────────────────────────────────────────────────----------─╮
       KC_NO, KC_F9,      KC_F10,     KC_F11,	  KC_F12,	           		   KC_NO,       KC_NO,        KC_MS_U,       KC_BSPC, KC_NO,
  // ├─────────────────────────────────-----------────────────────────────────┤           ├──────────────────────────────────────────────────────────----------──────┤
      MS_BTN1,      KC_F5,      KC_F6,      KC_F7,      KC_F8,        	   		   KC_MS_BTN2,	KC_MS_L,      KC_MS_D,      KC_MS_R,        KC_MS_R,
  // ├─────────────────────────────────-----------────────────────────────────┤           ├──────────────────────────────────────────────────────────----------──────┤
      KC_MS_BTN3,   KC_F1,      KC_F2,      KC_F3,      KC_F4,        	   		   KC_MS_BTN1,	KC_LGUI,      KC_LSFT,      KC_LCTL,        KC_LALT,
  // ╰─-----------────────────────────────────────────────────────────────────╯           ╰──----------──────────────────────────────────────────────────────────────╯
                       KC_NO, KC_NO, KC_NO,             KC_NO, KC_NO
  //                   ╰───────────────────────────╯ ╰──────────────────╯
  ),
};
// clang-format on


// Declare combos
enum combos {
    ZX_Q,
    DTSL_P,
    WE_ENT,
    XC_ESC,
    CMDT_TAB,
    CV_MINS,
    QT_BOOT,
    GH_COMBO
};

// Define combos
const uint16_t PROGMEM zx_combo[] = {KC_Z, KC_X, COMBO_END};
const uint16_t PROGMEM dtsl_combo[] = {KC_DOT, KC_SLSH, COMBO_END};
const uint16_t PROGMEM we_combo[] = {KC_W, KC_E, COMBO_END};
const uint16_t PROGMEM xc_combo[] = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM cmdt_combo[] = {KC_COMM, KC_DOT, COMBO_END};
const uint16_t PROGMEM cv_combo[] = {KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM qt_combo[] = {KC_Q, KC_T, COMBO_END};
const uint16_t PROGMEM gh_combo[] = {KC_G, KC_H, COMBO_END};

// Associate combos with values to send
combo_t key_combos[COMBO_COUNT] = {
    [ZX_Q] = COMBO(zx_combo, KC_Q),
    [DTSL_P] = COMBO(dtsl_combo, KC_P),
    [WE_ENT] = COMBO(we_combo, KC_ENT),
    [XC_ESC] = COMBO(xc_combo, KC_ESC),
    [CMDT_TAB] = COMBO(cmdt_combo, KC_TAB),
    [CV_MINS] = COMBO(cv_combo, KC_MINS),
    [QT_BOOT] = COMBO(qt_combo, QK_BOOT),
    [GH_COMBO] = COMBO(gh_combo, CW_TOGG)
};


// Setup trackball movement settings
bool trackball_moved = false;

void trackball_handler(uint8_t layer) {
    trackball_moved = true;
}

void matrix_scan_user(void) {
    if (trackball_moved) {
        // Toggle the special layer
        layer_on(LAYER_FUNC);
        trackball_moved = false;
    }
}


