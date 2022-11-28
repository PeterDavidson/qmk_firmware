#include QMK_KEYBOARD_H


#define _COLEMAK 0
#define _SYMBOLS 1
#define _NUMBERS 2
#define _MOVEMENT 3
#define _BRACKETS 4
#define _FUNCTIONS 5
#define _LAYER6 6
#define _MOUSE 7
#define _GAME 8
#define _PASSWORD 9
#define _LAYER10 10
#define _LAYER11 11

enum custom_keycodes {
    LAYER0 = SAFE_RANGE,
    LAYER1,
    LAYER2,
    LAYER3,
    LAYER4,
    LAYER5,
    LAYER6,
    LAYER7,
    LAYER8,
    LAYER9,
    LAYER10,
    LAYER11,
};

 const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_COLEMAK] = LAYOUT(\
    KC_Q, LGUI_T(KC_W), KC_F, KC_P, LT(10,KC_G),                  KC_J, KC_L, KC_U, KC_Y, TO(3),\
    LSFT_T(KC_A), LT(4,KC_R), LT(3,KC_S), LT(2,KC_T), KC_D,       KC_H, KC_N, KC_E, KC_I, LSFT_T(KC_O),\
    LCTL_T(KC_Z), LALT_T(KC_X), LSFT_T(KC_C), LT(5,KC_V), KC_B,   KC_K, LT(7,KC_M), RSFT_T(KC_COMM), RALT_T(KC_DOT), RCTL_T(KC_QUOT),\
                           LCTL(KC_X), KC_BSPC, LCTL_T(KC_ESC),   LT(3,KC_ENT), LT(1,KC_SPC), KC_DEL),

[_SYMBOLS] = LAYOUT(\
    KC_ESC, KC_QUES, KC_SLSH, KC_PERC, TO(0),       KC_CAPS, KC_TILD, KC_PLUS, KC_AMPR, KC_NO, \
    KC_AT, KC_ASTR, KC_EXLM, KC_DQUO, KC_DLR,       KC_HASH, KC_SCLN, KC_EQL, KC_UNDS, KC_COLN,\
    KC_CAPS, KC_BSLS, KC_CIRC, KC_PIPE, KC_GRV,     KC_SPC, KC_MINS, KC_QUOT, KC_LT, KC_TRNS, \
                    KC_LALT, KC_LCTL, KC_LSFT,      KC_TRNS, KC_TRNS, KC_TRNS),

[_NUMBERS] = LAYOUT(\
    KC_NO, KC_NO, KC_NO, KC_NO, TO(0),           KC_PAST, KC_7, KC_8, KC_9, KC_TRNS, \
    KC_LCTL, KC_LALT, KC_LSFT, KC_NO, KC_NO,     KC_DOT, KC_4, KC_5, KC_6, KC_PMNS, \
    KC_LCTL, KC_LALT, KC_LCTL, KC_NO, KC_NO,     KC_COMM, KC_1, KC_2, KC_3, KC_PSLS, \
                 KC_TRNS, KC_TRNS,  KC_TRNS,     KC_TRNS, KC_TRNS, KC_0),

[_MOVEMENT] = LAYOUT(\
    KC_NO, KC_LGUI, KC_NO, KC_NO, TO(0),         LCTL(KC_HOME), KC_HOME, KC_UP, KC_PGUP, KC_TRNS, \
    KC_LCTL, KC_LALT, KC_NO, KC_LSFT, KC_NO,     LCTL(KC_LEFT), KC_LEFT, KC_DOWN, KC_RGHT, LCTL(KC_RGHT), \
    KC_NO, LALT(KC_LGUI), KC_NO, KC_LCTL, KC_NO, LCTL(KC_END), KC_END, KC_TAB, KC_PGDN, TG(11), \
                KC_TRNS, LCTL(KC_Z), LCTL(KC_Y), LCTL(KC_C), LCTL(KC_V), KC_TRNS),

[_BRACKETS] = LAYOUT(\
     KC_NO, KC_NO, KC_NO, KC_NO, TO(0),          KC_NO, LCTL(KC_GRV), LCTL(KC_PSLS), KC_NO, KC_NO, \
     KC_LCTL, KC_NO, KC_LALT, KC_LSFT, KC_NO,    KC_NO, KC_LPRN, KC_LCBR, KC_LBRC, KC_LT, \
     KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,          KC_NO, KC_RPRN, KC_RCBR, KC_RBRC, KC_GT, \
               KC_TRNS, KC_TRNS, KC_TRNS,        KC_TRNS, KC_TRNS, KC_TRNS),

[_FUNCTIONS] = LAYOUT(\
    KC_NO, KC_NO, KC_NO, KC_NO, TO(0),           KC_CAPS, KC_F7, KC_F8, KC_F9, RESET, 
    KC_NO, KC_NO, KC_LCTL, KC_NO, KC_NO,         KC_NLCK, KC_F4, KC_F5, KC_F6, KC_NO, 
    KC_LCTL, KC_LALT, KC_LSFT, KC_NO, KC_NO,     KC_SLCK, KC_F1, KC_F2, KC_F3, KC_NO, 
            KC_TRNS, KC_TRNS, KC_TRNS,           KC_TRNS, KC_TRNS, KC_TRNS),

[_LAYER6] = LAYOUT(
    KC_NO, KC_NO, KC_NO, KC_NO, TO(0),           KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, 
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,           KC_NO, KC_NO, KC_NO, KC_TRNS, KC_NO, 
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,           KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, 
                 KC_NO, KC_NO, KC_NO,            KC_NO, KC_NO, KC_NO),

[_MOUSE] = LAYOUT(
    KC_NO, KC_NO, KC_MS_U, KC_WH_U, TO(0),       KC_NO, KC_MUTE, KC_VOLD, KC_VOLU, KC_NO, 
    KC_WH_L, KC_MS_L, KC_MS_D, KC_MS_R, KC_NO,   KC_NO, KC_MPRV, KC_MPLY, KC_MSTP, KC_MNXT, 
    KC_NO, KC_NO, KC_NO, KC_WH_D, KC_NO,         KC_NO, KC_NO, KC_MRWD, KC_MFFD, KC_NO, 
                    KC_BTN3, KC_BTN1, KC_BTN2,   KC_NO, KC_WBAK, TO(0)),

[_GAME] = LAYOUT(
    KC_NO, KC_Q, KC_W, KC_E, KC_T,               KC_NO, KC_NO, KC_TRNS, KC_NO, KC_NO, 
    LSFT_T(KC_O), KC_A, KC_S, KC_D, KC_F,        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, 
    LCTL_T(KC_P1), KC_P2, KC_P3, KC_P4, KC_P5,   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, 
                    KC_NO, KC_SPC, KC_ESC,       KC_TRNS, KC_TRNS, TO(0)),

[_PASSWORD] = LAYOUT(
    KC_1, KC_2, KC_R, KC_0, KC_T,                KC_U, KC_O, KC_7, KC_6, KC_TRNS, 
    LSFT_T(KC_Q), KC_4, KC_W, KC_5, KC_E,        KC_Y, KC_H, KC_3, KC_8, RSFT_T(KC_9), 
    KC_A, KC_S, KC_D, KC_F, KC_G,                KC_I, KC_J, KC_TRNS, KC_TRNS, KC_TRNS, 
              KC_TRNS, KC_TRNS, KC_TRNS,         KC_TRNS, KC_TRNS, TO(0)),

[_LAYER10] = LAYOUT(
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,           KC_NO, TO(7), TO(8), TO(9), KC_NO, 
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,           KC_NO, TO(4), TO(5), TO(6), KC_NO, 
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,           KC_NO, TO(1), TO(2), TO(3), KC_TRNS, 
             KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, TO(0), TO(0)),

[_LAYER11] = LAYOUT(
    KC_NO, KC_NO, KC_NO, KC_NO, TO(0),           LCTL(LSFT(KC_HOME)), LSFT(KC_HOME), LSFT(KC_UP), LSFT(KC_PGUP), TO(3), 
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,           LCTL(LSFT(KC_LEFT)), LSFT(KC_LEFT), LSFT(KC_DOWN), LSFT(KC_RGHT), LCTL(LSFT(KC_RIGHT)), 
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,           LCTL(LSFT(KC_END)), LSFT(KC_END), LSFT(KC_TAB), LSFT(KC_PGDN), KC_TRNS, 
            LCTL(KC_X), LCTL(KC_Z), LCTL(KC_Y),  LCTL(KC_C), LCTL(KC_V), KC_DEL) 

};