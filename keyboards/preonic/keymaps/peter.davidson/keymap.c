/* Copyright 2015-2021 Jack Humbert
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

// qmk compile -kb preonic/rev3_drop -km peter.davidson

#include QMK_KEYBOARD_H
//#include "muse.h"
enum layers {
    _COLEMAK=0,
    _GAMES,
    _NUMBERS,
    _NUMPAD,
    _MOVEMENT,
    _FUNCTION,
    _SYMBOLS,
    _BRACKETS,
    _PRIMARY2,
    _MOUSE,
    _PASS,
    _LAYERCHG
    //_GOTO,
    // _QWERTY,
    //_APPS
    //_ADJUST,
};

enum preonic_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  DVORAK,
  LOWER,
  RAISE,
  BACKLIT
};

#define LSYM(kc) LT(_SYMBOLS,kc)
#define LNUM(kc) LT(_NUMBERS,kc)
#define LMOV(kc) LT(_MOVEMENT,kc)
#define LBRACK(kc) LT(_BRACKETS,kc)
#define LFUN(kc) LT(_FUNCTION,kc)
#define LMOUSE(kc) LT(_MOUSE,kc)
#define LNUMPAD(kc) LT(_NUMPAD,kc)
#define LLAYER(kc) LT(_LAYERCHG,kc)
// #define LAPP(kc) LT(_APPS,kc)
// #define LGOTO(kc) LT(_GOTO,kc)
#define TODEFAULT TO(0)

#define CTL_ESC  MT(MOD_LCTL, KC_ESC)
#define CTL_QUOT MT(MOD_RCTL, KC_QUOTE)
#define CTL_MINS MT(MOD_RCTL, KC_MINUS)
#define ALT_ENT  MT(MOD_LALT, KC_ENT)
#define LSA_T(kc) MT(MOD_LSFT | MOD_LALT, kc)
#define KC_PC_UNDO LCTL(KC_Z)
#define KC_PC_REDO LCTL(KC_Y)
#define KC_PC_CUT LCTL(KC_X)
#define KC_PC_COPY LCTL(KC_C)
#define KC_PC_PASTE LCTL(KC_V)
#define KC_MISSING KC_TRANSPARENT

// enum custom_keycodes {
//     LAYER0 = SAFE_RANGE,
//     LAYER1,
//     LAYER2,
//     LAYER3,
//     LAYER4,
//     LAYER5,
//     LAYER6,
//     LAYER7,
//     LAYER8,
//     LAYER9,
//     LAYER10,
//     LAYER11,
//     LAYER12,
// };

 const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Colemak
 * ,-----------------------------------------------------------------------------------.
 * |  Esc |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   F  |   P  |   G  |   J  |   L  |   U  |   Y  |   ;  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   R  |   S  |   T  |   D  |   H  |   N  |   E  |   I  |   O  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   K  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Brite| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_COLEMAK] = LAYOUT_preonic_grid(
  KC_ESC,  KC_1,         KC_2,          KC_3,         KC_4,            KC_5,         KC_6,   KC_7,         KC_8,            KC_9,           KC_0,          KC_DEL, 
  KC_NO,   KC_Q,         LGUI_T(KC_W),  KC_F,         LNUMPAD(KC_P),   LLAYER(KC_G), KC_J,   KC_L,         KC_U,            KC_Y,           KC_SCLN,       TO(_LAYERCHG), 
  KC_TAB,  LSFT_T(KC_A), LBRACK(KC_R),  LMOV(KC_S),   LNUM(KC_T),      KC_D,         KC_H,   KC_N,         KC_E,            KC_I,           RSFT_T(KC_O),  KC_QUOT, 
  KC_LSFT, LCTL_T(KC_Z), LALT_T(KC_X),  LSFT_T(KC_C), LFUN(KC_V),      KC_B,         KC_K,   LMOUSE(KC_M), RSFT_T(KC_COMM), RALT_T(KC_DOT), RCTL_T(KC_UP), KC_RSFT, 
  KC_LGUI, KC_PC_COPY    ,KC_PC_PASTE   ,KC_PC_CUT,   LSFT_T(KC_BSPC), KC_ESC,       KC_ENT, LSYM(KC_SPC), KC_DEL,          KC_LEFT,        KC_DOWN,       KC_RGHT
),

/* Symbols
 * ,-----------------------------------------------------------------------------------.
 * |  Esc |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |NumLck|   ?  |   /  |   %  | (Def)| Caps |   ~  |   +  |   &  |      | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |   @  |   *  |   !  |   "  |   $  |   #  |   ;  |   =  |   _  |   :  |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      | LCtr |\(alt)|   ^  |   |  |   `  | spc  |   -  |   '  |   <  |  >   |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Brite| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_SYMBOLS] = LAYOUT_preonic_grid(
  KC_TRNS, KC_TRNS, KC_TRNS        , KC_TRNS, KC_TRNS, KC_TRNS  , KC_TRNS, KC_TRNS , KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
  KC_NO  , KC_NUM , KC_QUES        , KC_SLSH, KC_PERC, TODEFAULT, KC_CAPS, KC_TILD , KC_PLUS, KC_AMPR, KC_NO  , KC_TRNS, 
  KC_NO  , KC_AT  , KC_ASTR        , KC_EXLM, KC_DQUO, KC_DLR   , KC_HASH, KC_SCLN , KC_EQL , KC_UNDS, KC_COLN, KC_TRNS, 
  KC_NO  , KC_LCTL, LALT_T(KC_BSLS), KC_CIRC, KC_PIPE, KC_GRV   , KC_SPC , KC_MINUS, KC_QUOT, KC_LABK, KC_RABK, KC_TRNS, 
  KC_NO  , KC_NO  , KC_NO          , KC_NO  , KC_NO  , KC_NO    , KC_NO  , KC_NO   , KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
),

[_NUMBERS] = LAYOUT_preonic_grid(
  KC_NO,   KC_NO,   KC_NO,           KC_NO,   KC_NO,   KC_NO,     KC_NO,               KC_NO,   KC_NO, KC_NO,   KC_NO,   KC_NO, 
  KC_NO,   KC_NO,   KC_NO,           KC_NO,   KC_NO,   TODEFAULT, KC_PAST,             KC_7,    KC_8,  KC_9,    KC_PPLS, TO(_PASS), 
  KC_NO,   KC_LCTL, KC_LALT,         KC_LSFT, KC_NO,   KC_NO,     KC_PDOT,             KC_4,    KC_5,  KC_6,    KC_PMNS, KC_BSPC, 
  KC_NO,   KC_LCTL, LALT_T(KC_BSLS), KC_LCTL, KC_NO,   KC_NO,     KC_PCMM,             KC_1,    KC_2,  KC_3,    KC_UP,   KC_NO, 
  KC_TRNS, KC_TRNS, KC_TRNS,         KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS,             KC_TRNS, KC_0,  KC_LEFT, KC_DOWN, KC_RGHT
),

[_NUMPAD] = LAYOUT_preonic_grid(
  KC_NO,   KC_NO,   KC_NO,           KC_NO,   KC_NO,   KC_NO,     KC_NO,   KC_NO,   KC_NO, KC_NO,   KC_NO,   KC_NO, 
  KC_NO,   KC_NO,   KC_NO,           KC_NO,   KC_NO,   TODEFAULT, KC_PAST, KC_P7,   KC_P8, KC_P9,   KC_PPLS, TO(_PASS), 
  KC_NO,   KC_LCTL, KC_LALT,         KC_LSFT, KC_NO,   KC_NO,     KC_PDOT, KC_P4,   KC_P5, KC_P6,   KC_PMNS, KC_BSPC, 
  KC_NO,   KC_LCTL, LALT_T(KC_BSLS), KC_LCTL, KC_NO,   KC_NO,     KC_PCMM, KC_P1,   KC_P2, KC_P3,   KC_UP,   KC_NO, 
  KC_TRNS, KC_TRNS, KC_TRNS,         KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS, KC_P0, KC_LEFT, KC_DOWN, KC_RGHT
),

[_MOVEMENT] = LAYOUT_preonic_grid(
  KC_NO, KC_NO,   KC_NO,   KC_NO, KC_NO,      KC_NO,      KC_NO,         KC_NO,         KC_NO,          KC_NO,      KC_NO,         KC_NO, 
  KC_NO, KC_NO,   KC_NO,   KC_NO, KC_NO,      TODEFAULT,  LCTL(KC_HOME), KC_HOME,       KC_UP,          KC_PGUP,    KC_INS,        KC_NO, 
  KC_NO, KC_LCTL, KC_LALT, KC_NO, KC_LSFT,    KC_NO,      LCTL(KC_LEFT), KC_LEFT,       KC_DOWN,        KC_RGHT,    LCTL(KC_RGHT), KC_NO, 
  KC_NO, KC_NO,   KC_NO,   KC_NO, KC_LCTL,    KC_NO,      LCTL(KC_END),  KC_END,        KC_TAB,         KC_PGDN,    KC_SCRL,       KC_NO, 
  KC_NO, KC_NO,   KC_NO,   KC_NO, KC_PC_UNDO, KC_PC_REDO, KC_PC_COPY,    KC_PC_PASTE,   KC_DELETE,      KC_INSERT,  KC_WWW_BACK, KC_NO
),

[_BRACKETS] = LAYOUT_preonic_grid(
  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, 
  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, TODEFAULT, KC_NO, LCTL(KC_GRV), LCTL(KC_SLASH), LALT(LSFT(KC_A)),LCTL(LSFT(KC_BSLS)), KC_NO, 
  KC_NO, KC_LCTL, KC_NO, KC_LALT, KC_LSFT, KC_NO, LCTL(LSFT(KC_BSLS)),KC_LPRN,        KC_LCBR,        KC_LBRC,    KC_LABK, KC_NO, 
  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_RPRN, KC_RCBR, KC_RBRC, KC_RABK, KC_NO, 
  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO),

[_FUNCTION] = LAYOUT_preonic_grid(
  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, QK_BOOT, 
  KC_NO, KC_NO, KC_LGUI, KC_NO, KC_NO, TODEFAULT, KC_NO, KC_NO,    KC_F7, KC_F8, KC_F9, KC_NO, 
  KC_NO, KC_NO, KC_NO, KC_LCTL, KC_NO, KC_NO, KC_NO, KC_NO,        KC_F4, KC_F5, KC_F6, KC_NO, 
  KC_NO, KC_LCTL, KC_LALT, KC_LSFT, KC_NO, KC_NO, KC_NO, KC_NO,    KC_F1, KC_F2, KC_F3, KC_NO, 
  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_SYSTEM_SLEEP, KC_NO, KC_NO,KC_F10, KC_F11, KC_F12, KC_NO),

[_PRIMARY2] = LAYOUT_preonic_grid(
  KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_DEL, 
  KC_NO, KC_Q, LGUI_T(KC_W), KC_F, KC_P, KC_G, KC_J, KC_L, KC_U, KC_Y, KC_SCLN, TO(_LAYERCHG), 
  KC_TAB, LSFT_T(KC_A), LBRACK(KC_R), LMOV(KC_S), LNUM(KC_T), KC_D, KC_H, KC_N, KC_E, KC_I, RSFT_T(KC_O), KC_QUOT, 
  KC_LSFT, LCTL_T(KC_Z), LALT_T(KC_X), LSFT_T(KC_C), LFUN(KC_V), KC_B, KC_K, LMOUSE(KC_M), RSFT_T(KC_COMM), RALT_T(KC_DOT), RCTL_T(KC_UP), KC_RSFT, 
  KC_LGUI, KC_PC_COPY  ,KC_PC_PASTE   ,KC_PC_CUT, LSFT_T(KC_BSPC), KC_ESC, KC_ENT, LSYM(KC_SPC), KC_DEL, KC_LEFT, KC_DOWN, KC_RGHT),

[_MOUSE] = LAYOUT_preonic_grid(
  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, TODEFAULT, KC_NO, KC_NO, KC_NO, KC_NO),

[_GAMES] = LAYOUT_preonic_grid(
  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, TODEFAULT, KC_NO, KC_NO, KC_NO, KC_NO),

[_LAYERCHG] = LAYOUT_preonic_grid(
  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, TO(_BRACKETS), TO(_PRIMARY2), TO(_MOUSE), KC_NO, KC_NO,
  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, TO(_MOVEMENT), TO(_FUNCTION), TO(_SYMBOLS), KC_NO, KC_NO,
  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, TO(_GAMES), TO(_NUMBERS), TO(_NUMPAD), KC_NO, KC_NO,
  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, TODEFAULT, TO(_LAYERCHG), TO(_PASS), KC_NO, KC_NO),

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Brite| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_PASS] = LAYOUT_preonic_grid(
  QK_GESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_BSPC, 
  KC_SLSH, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, TODEFAULT, 
  KC_TAB, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_ENT,
  SC_LSPO, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_UP, SC_RSPC, 
  KC_LGUI, KC_LCTL, KC_LALT, KC_APP, LT(5,KC_BSPC), LT(2,KC_SPC), KC_SPC, LT(1,KC_SPC), KC_TRNS, KC_LEFT, KC_DOWN, KC_RGHT),

};



// bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//   switch (keycode) {
//         case QWERTY:
//           if (record->event.pressed) {
//             set_single_persistent_default_layer(_QWERTY);
//           }
//           return false;
//           break;
//         case COLEMAK:
//           if (record->event.pressed) {
//             set_single_persistent_default_layer(_COLEMAK);
//           }
//           return false;
//           break;
//         case DVORAK:
//           if (record->event.pressed) {
//             set_single_persistent_default_layer(_DVORAK);
//           }
//           return false;
//           break;
//         case LOWER:
//           if (record->event.pressed) {
//             layer_on(_LOWER);
//             update_tri_layer(_LOWER, _RAISE, _ADJUST);
//           } else {
//             layer_off(_LOWER);
//             update_tri_layer(_LOWER, _RAISE, _ADJUST);
//           }
//           return false;
//           break;
//         case RAISE:
//           if (record->event.pressed) {
//             layer_on(_RAISE);
//             update_tri_layer(_LOWER, _RAISE, _ADJUST);
//           } else {
//             layer_off(_RAISE);
//             update_tri_layer(_LOWER, _RAISE, _ADJUST);
//           }
//           return false;
//           break;
//         case BACKLIT:
//           if (record->event.pressed) {
//             register_code(KC_RSFT);
//             #ifdef BACKLIGHT_ENABLE
//               backlight_step();
//             #endif
//             #ifdef RGBLIGHT_ENABLE
//               rgblight_step();
//             #endif
//             #ifdef __AVR__
//             writePinLow(E6);
//             #endif
//           } else {
//             unregister_code(KC_RSFT);
//             #ifdef __AVR__
//             writePinHigh(E6);
//             #endif
//           }
//           return false;
//           break;
//       }
//     return true;
// };

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

// bool encoder_update_user(uint8_t index, bool clockwise) {
//   if (muse_mode) {
//     if (IS_LAYER_ON(_RAISE)) {
//       if (clockwise) {
//         muse_offset++;
//       } else {
//         muse_offset--;
//       }
//     } else {
//       if (clockwise) {
//         muse_tempo+=1;
//       } else {
//         muse_tempo-=1;
//       }
//     }
//   } else {
//     if (clockwise) {
//       register_code(KC_PGDN);
//       unregister_code(KC_PGDN);
//     } else {
//       register_code(KC_PGUP);
//       unregister_code(KC_PGUP);
//     }
//   }
//     return true;
// }

// bool dip_switch_update_user(uint8_t index, bool active) {
//     switch (index) {
//         case 0:
//             if (active) {
//                 layer_on(_ADJUST);
//             } else {
//                 layer_off(_ADJUST);
//             }
//             break;
//         case 1:
//             if (active) {
//                 muse_mode = true;
//             } else {
//                 muse_mode = false;
//             }
//     }
//     return true;
// }


// void matrix_scan_user(void) {
// #ifdef AUDIO_ENABLE
//     if (muse_mode) {
//         if (muse_counter == 0) {
//             uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
//             if (muse_note != last_muse_note) {
//                 stop_note(compute_freq_for_midi_note(last_muse_note));
//                 play_note(compute_freq_for_midi_note(muse_note), 0xF);
//                 last_muse_note = muse_note;
//             }
//         }
//         muse_counter = (muse_counter + 1) % muse_tempo;
//     } else {
//         if (muse_counter) {
//             stop_all_notes();
//             muse_counter = 0;
//         }
//     }
// #endif
// }

// bool music_mask_user(uint16_t keycode) {
//   switch (keycode) {
//     case RAISE:
//     case LOWER:
//       return false;
//     default:
//       return true;
//   }
// }
