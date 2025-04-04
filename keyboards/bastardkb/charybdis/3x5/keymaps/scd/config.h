#pragma once

// Pick good defaults for enabling homerow modifiers
#define COMBO_COUNT 10
#define COMBO_TERM 75


// Define default 3 layers
#define TRI_LAYER_LOWER_LAYER 1
#define TRI_LAYER_UPPER_LAYER 2
#define TRI_LAYER_ADJUST_LAYER 3

// Define a hook function to activate mouse layer when moving trackball
// #define idMovementHook idMouseMovement
#define POINTING_DEVICE_AUTO_MOUSE_ENABLE
#define AUTO_MOUSE_DEFAULT_LAYER 4
#define CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE
#define CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS 1000



// Enable bilateral combinations to make homerow modifers more usable (https://sunaku.github.io/home-row-mods.html)
/* QMK */
#define TAPPING_TERM 200
// #define IGNORE_MOD_TAP_INTERRUPT /* for rolling on mod-tap keys */

/* Miryoku */
#define BILATERAL_COMBINATIONS
#define BILATERAL_COMBINATIONS_LIMIT_CHORD_TO_N_KEYS 4 /* GUI, Alt, Ctrl, Shift */
// #define BILATERAL_COMBINATIONS_DELAY_MODS_THAT_MATCH MOD_MASK_GUI
// #define BILATERAL_COMBINATIONS_DELAY_MATCHED_MODS_BY 120  /* ms */
#define BILATERAL_COMBINATIONS_ALLOW_CROSSOVER_AFTER 80   /* ms */
#define BILATERAL_COMBINATIONS_ALLOW_SAMESIDED_AFTER 3000 /* ms */
#define BILATERAL_COMBINATIONS_TYPING_STREAK_TIMEOUT 160  /* ms */
#define BILATERAL_COMBINATIONS_TYPING_STREAK_MODMASK (~MOD_MASK_SHIFT)