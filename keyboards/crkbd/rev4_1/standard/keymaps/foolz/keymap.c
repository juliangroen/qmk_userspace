/* blah */

#include QMK_KEYBOARD_H

// =============================================================================
// Home Row Mods — SACG order (⇧⎇⎈◆) — Shift on pinky, GUI on index
// =============================================================================

// Left hand
#define HM_A LSFT_T(KC_A)
#define HM_S LALT_T(KC_S)
#define HM_D LCTL_T(KC_D)
#define HM_F LGUI_T(KC_F)

// Right hand
#define HM_J RGUI_T(KC_J)
#define HM_K RCTL_T(KC_K)
#define HM_L RALT_T(KC_L)
#define HM_SCLN RSFT_T(KC_SCLN)

// Left outer column
#define CT_ESC LCTL_T(KC_ESC)

// Thumb layer-taps
#define LO_SPC LT(_LOWER, KC_SPC)
#define RA_SPC LT(_RAISE, KC_SPC)

// =============================================================================
// Layers
// =============================================================================
enum layers {
    _BASE = 0,
    _LOWER,
    _RAISE,
    _ADJUST,
    _BOOT,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_BASE] = LAYOUT_split_3x6_3_ex2(
  //┌────────┬────────┬────────┬────────┬────────┬────────┬────────┐          ┌────────┬────────┬────────┬────────┬────────┬────────┬────────┐
      KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_GRV,             KC_EQL,  KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_MINS,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤          ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
      CT_ESC,  HM_A,    HM_S,    HM_D,    HM_F,    KC_G,    CW_TOGG,           KC_DEL,  KC_H,    HM_J,    HM_K,    HM_L,    HM_SCLN, KC_QUOT,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                             ├────────┼────────┼────────┼────────┼────────┼────────┤
      KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                                 KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
  //└────────┴────────┴────────┼────────┼────────┼────────┤                             ├────────┼────────┼────────┼────────┴────────┴────────┘
                                 KC_LGUI, LO_SPC,  KC_ENT,                                KC_BSPC, RA_SPC,  KC_RGUI
  //                           └────────┴────────┴────────┘                             └────────┴────────┴────────┘
    ),

    [_LOWER] = LAYOUT_split_3x6_3_ex2(
  //┌────────┬────────┬────────┬────────┬────────┬────────┬────────┐          ┌────────┬────────┬────────┬────────┬────────┬────────┬────────┐
      KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    TG(_BOOT),          _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_RBRC,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤          ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
      _______, KC_MPRV, KC_MPLY, KC_MNXT, KC_BRID, KC_BRIU, _______,           _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX, XXXXXXX,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                             ├────────┼────────┼────────┼────────┼────────┼────────┤
      _______, KC_VOLD, KC_MUTE, KC_VOLU, XXXXXXX, XXXXXXX,                              XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
  //└────────┴────────┴────────┼────────┼────────┼────────┤                             ├────────┼────────┼────────┼────────┴────────┴────────┘
                                 KC_LGUI, _______, _______,                               _______, MO(_ADJUST), KC_RGUI
  //                           └────────┴────────┴────────┘                             └────────┴────────┴────────┘
    ),

    [_RAISE] = LAYOUT_split_3x6_3_ex2(
  //┌────────┬────────┬────────┬────────┬────────┬────────┬────────┐          ┌────────┬────────┬────────┬────────┬────────┬────────┬────────┐
      KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    _______,            TG(_BOOT), KC_6,  KC_7,    KC_8,    KC_9,    KC_0,    KC_RBRC,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤          ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,           _______, _______, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                             ├────────┼────────┼────────┼────────┼────────┼────────┤
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                              XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
  //└────────┴────────┴────────┼────────┼────────┼────────┤                             ├────────┼────────┼────────┼────────┴────────┴────────┘
                                 KC_LGUI, MO(_ADJUST), _______,                           _______, _______, KC_RGUI
  //                           └────────┴────────┴────────┘                             └────────┴────────┴────────┘
    ),

    [_ADJUST] = LAYOUT_split_3x6_3_ex2(
  //┌────────┬────────┬────────┬────────┬────────┬────────┬────────┐          ┌────────┬────────┬────────┬────────┬────────┬────────┬────────┐
      RM_TOGG, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   XXXXXXX,           XXXXXXX, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤          ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
      XXXXXXX, RM_NEXT, RM_VALU, RM_HUEU, RM_SATU, RM_SPDU, XXXXXXX,           XXXXXXX, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  XXXXXXX, KC_F12,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                             ├────────┼────────┼────────┼────────┼────────┼────────┤
      _______, RM_PREV, RM_VALD, RM_HUED, RM_SATD, RM_SPDD,                              XXXXXXX, XXXXXXX, XXXXXXX, DT_DOWN, DT_UP,   DT_PRNT,
  //└────────┴────────┴────────┼────────┼────────┼────────┤                             ├────────┼────────┼────────┼────────┴────────┴────────┘
                                 _______, _______, XXXXXXX,                               _______, _______, _______
  //                           └────────┴────────┴────────┘                             └────────┴────────┴────────┘
    ),

    [_BOOT] = LAYOUT_split_3x6_3_ex2(
  //┌────────┬────────┬────────┬────────┬────────┬────────┬────────┐          ┌────────┬────────┬────────┬────────┬────────┬────────┬────────┐
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOT,           QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤          ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, TG(_BOOT),        TG(_BOOT),XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                             ├────────┼────────┼────────┼────────┼────────┼────────┤
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                              XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //└────────┴────────┴────────┼────────┼────────┼────────┤                             ├────────┼────────┼────────┼────────┴────────┴────────┘
                                 XXXXXXX, XXXXXXX, XXXXXXX,                               XXXXXXX, XXXXXXX, XXXXXXX
  //                           └────────┴────────┴────────┘                             └────────┴────────┴────────┘
    ),
};

// =============================================================================
// Per-key tapping term
// =============================================================================
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case HM_A:
        case HM_SCLN:
            return TAPPING_TERM + 40;
        case HM_S:
        case HM_L:
            return TAPPING_TERM + 20;
        case LO_SPC:
        case RA_SPC:
            return TAPPING_TERM - 20;
        default:
            return TAPPING_TERM;
    }
}

// =============================================================================
// Per-key permissive hold — only for thumb layer-taps
//
// Activates hold when another key is pressed AND released while held.
// Less aggressive than HOLD_ON_OTHER_KEY_PRESS — won't misfire on overlaps.
// =============================================================================
bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LO_SPC:
        case RA_SPC:
            return true;
        default:
            return false;
    }
}

// =============================================================================
// Key Overrides
// =============================================================================

const key_override_t command_q_override = ko_make_basic(MOD_BIT(KC_LGUI), KC_Q, KC_NO);
const key_override_t command_w_override = ko_make_basic(MOD_BIT(KC_LGUI), KC_W, KC_NO);

const key_override_t *key_overrides[] = {
	&command_q_override,
	&command_w_override,
	NULL
};
