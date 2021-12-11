/* Copyright 2019 Thomas Baart <thomas@splitkb.com>
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
#include QMK_KEYBOARD_H
#define NUMLAYERS 10
enum layers {
    _COLEMAK=0,
    _NUMBERS,
    _MOVEMENT,
    _GAMES,
    _FUNCTION,
    _SYMBOLS,
    _BRACKETS,
    _PRIMARY2,
    _MOUSE,
    _PASS,
    //_GOTO,
    // _QWERTY,
    //_APPS
    //_ADJUST,
};
const char string_0[] PROGMEM = "Colemak";
const char string_1[] PROGMEM = "Number";
const char string_2[] PROGMEM = "Cursor";
const char string_3[] PROGMEM = "Game"; 
const char string_4[] PROGMEM = "Func"; 
const char string_5[] PROGMEM = "Symbol";
const char string_6[] PROGMEM = "Bracket";
const char string_7[] PROGMEM = "Prim2";
const char string_8[] PROGMEM = "Mouse";
const char string_9[] PROGMEM = "Pass";
//const char string_10[] PROGMEM = "Goto";
//const char string_11[] PROGMEM = "QWERTY";
//const char string_12[] PROGMEM = "App";
const char* const layerNames[] PROGMEM   = {
    string_0,string_1,string_2,string_3,string_4,string_5,string_6,
    string_7, string_8, string_9};

// Aliases for readability
// #define COLEMAK  DF(_COLEMAK)

// #define SYM      MO(_SYM)
// #define MOVEMENT MO(_MOVEMENT)
// #define NUMBERS  MO(_NUMBERS)
// #define FKEYS    MO(_FUNCTION)
// #define ADJUST   MO(_ADJUST)

#define LSYM(kc) LT(_SYMBOLS,kc)
#define LNUM(kc) LT(_NUMBERS,kc)
#define LMOV(kc) LT(_MOVEMENT,kc)
#define LBRACK(kc) LT(_BRACKETS,kc)
#define LFUN(kc) LT(_FUNCTION,kc)
#define LMOUSE(kc) LT(_MOUSE,kc)
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
#define RDIAL_CLK KC_AUDIO_MUTE
#define LDIAL_CLK TO(0)
#define KC_MISSING KC_TRANSPARENT

// Note: LAlt/Enter (ALT_ENT) is not the same thing as the keyboard shortcut Alt+Enter.
// The notation `mod/tap` denotes a key that activates the modifier `mod` when held down, and
// produces the key `tap` when tapped (i.e. pressed and released).

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/*
 * Base Layer: Colemak
 *
 * ,-------------------------------------------.                              ,--------------------------------------------.
 * |  Undo  |   Q  |W(win)|   F  |P(app)|G(goto)|                              |   J  |   L   |   U  |   Y  | ;  : |  REDO  |
 * |--------+------+------+------+------+-------|                              |------+-------+------+------+------+--------|
 * |  Tab   |A(lsh)|R(brk)|S(mov)|T(num)|   D   |                              |   H  |   N   |   E  |   I  |O(Rsh)|Ctrl/' "|
 * |--------+------+------+------+------+-------+-------------.  ,-------------+------+-------+------+------+------+--------|
 * | LClick |   Z  |   X  |   C  |   V  |   B   |      |      |  |      |      |   K  |M(mous)| ,(Sh)|.(Alt)|/(Ctr)| RClick |
 * `----------------------+------+------+-------+------+------|  |------+------+------+-------+------+----------------------'
 *                        |Copy  | Paste| Cut   |BSpace| Esc  |  | Enter| Space| Del  | Left  | Right|
 *                        |      |      |       |      |      |  |      |(Sym) |      |       |      |
 *                        `-----------------------------------'  `-----------------------------------'
 */
    [_COLEMAK] = LAYOUT(
     KC_PC_UNDO, KC_Q        ,LGUI_T(KC_W), KC_F        , KC_P, KC_G,                                        KC_J,   KC_L      ,  KC_U          ,   KC_Y       ,KC_SCLN           , KC_UP,
     KC_TAB    , LSFT_T(KC_A),LBRACK(KC_R), LMOV(KC_S)  , LNUM(KC_T), KC_D      ,                                         KC_H,   KC_N      ,  KC_E          ,   KC_I       ,RSFT_T(KC_O)      , KC_DOWN,
     LDIAL_CLK , LCTL_T(KC_Z),LALT_T(KC_X), LSFT_T(KC_C), LFUN(KC_V), KC_B      ,KC_MISSING, KC_MISSING , KC_MISSING, KC_MISSING, KC_K,LMOUSE(KC_M) ,RSFT_T(KC_COMMA),RALT_T(KC_DOT), RCTL_T(KC_BSLASH), RDIAL_CLK,
                                            KC_PC_COPY  ,KC_PC_PASTE,KC_PC_CUT  ,KC_BSPACE ,KC_ESCAPE ,KC_ENTER, LSYM(KC_SPACE),KC_DELETE, KC_LEFT, KC_RIGHT
    ),

/*
 * Sym Layer: Symbols
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |NumLck|  ?   |  /   |  %   |(TO0) |                              |CapLck|  ~   |  +   |  &   |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |  @   |  *   |  !   |  "   |  $   |                              |   #  |  =   |  _   |  :   |      |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * | Click  | LCtrl|\(alt)|  ^   |  |   |  `   |      |      |  |      |      |   ]  |  _   |  ,   |  .   |  /   | Click  |
 * `----------------------+------+------+------+      |      |  |      |      |------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_SYMBOLS] = LAYOUT(
      _______,  KC_NUMLOCK, KC_QUES          , KC_SLASH,KC_PERC, TO(0),                                         KC_CAPSLOCK, KC_TILD,  KC_PLUS, KC_AMPR, XXXXXXX, XXXXXXX,
      _______,  KC_AT     , KC_ASTR          , KC_EXLM, KC_DQUO, KC_DLR,                                        KC_HASH,  KC_SCOLON  , KC_EQUAL, KC_UNDS, KC_COLN, KC_DQUO,
      LDIAL_CLK,KC_LCTRL  , LALT_T(KC_BSLASH), KC_CIRC, KC_PIPE, KC_GRAVE,  KC_MISSING, KC_MISSING, KC_MISSING, KC_MISSING, KC_SPACE, KC_MINUS   , KC_QUOTE, KC_LABK, KC_RABK, RDIAL_CLK,
                                               _______, _______, _______,  _______, _______, _______, _______,   _______, _______    , _______
    ),

/*
 * Numbers Layer
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |NumLck|  ?   |  /   |  %   |(TO0) |                              |CapLck|  ~   |  +   |  &   |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |  @   |  *   |  !   |  "   |  $   |                              |   #  |  =   |  _   |  :   |      |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * | Click  | LCtrl|\(alt)|  ^   |  |   |  `   |      |      |  |      |      |   ]  |  _   |  ,   |  .   |  /   | Click  |
 * `----------------------+------+------+------+      |      |  |      |      |------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_NUMBERS] = LAYOUT(
      KC_NUMLOCK,  KC_NO,          KC_LGUI,        KC_NO,          KC_NO,          TO(0),                       KC_KP_SLASH,    KC_7,           KC_8,           KC_9,           KC_KP_ASTERISK, TO(9),
      _______,  KC_LCTRL,       KC_LALT,        KC_LSHIFT,      KC_TRANSPARENT, KC_NO,                          KC_DOT,      KC_4,           KC_5,           KC_6,           KC_KP_PLUS,     KC_BSPACE,
      LDIAL_CLK,KC_LCTRL  , LALT_T(KC_BSLASH), KC_CIRC, KC_PIPE, KC_GRAVE,  KC_MISSING, KC_MISSING, KC_MISSING, KC_MISSING, KC_COMMA,       KC_1,           KC_2,           KC_3, _______, RDIAL_CLK,
                                               _______, _______, _______,  _______, _______, _______, _______,   _______,     KC_0,      KC_KP_MINUS 
    ),

/*
 * Movement Layer
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |NumLck|  ?   |  /   |  %   |(TO0) |                              |CapLck|  ~   |  +   |  &   |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |  @   |  *   |  !   |  "   |  $   |                              |   #  |  =   |  _   |  :   |      |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * | Click  | LCtrl|\(alt)|  ^   |  |   |  `   |      |      |  |      |      |   ]  |  _   |  ,   |  .   |  /   | Click  |
 * `----------------------+------+------+------+      |      |  |      |      |------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_MOVEMENT] = LAYOUT(
      _______,  KC_NO,          KC_LGUI,        KC_NO,          KC_NO,          TO(0),                                                  LCTL(KC_HOME),  KC_HOME,        KC_UP,          KC_PGUP,        KC_INSERT, DYN_REC_START1,
      _______,  KC_LCTRL,       KC_LALT,        _______,      KC_LSHIFT, KC_NO,                                       LCTL(KC_LEFT),  KC_LEFT,        KC_DOWN,        KC_RIGHT,       LCTL(KC_RIGHT), LCTL(KC_GRAVE),
      LDIAL_CLK,KC_NO,          KC_NO,          KC_NO,          KC_LCTRL,       LCTL(KC_GRAVE),  KC_MISSING, KC_MISSING, KC_MISSING, KC_MISSING, LCTL(KC_END),   KC_END,         KC_TAB,         KC_PGDOWN,      KC_SCROLLLOCK, RDIAL_CLK,
                                               _______, _______, _______,  KC_PC_UNDO, KC_PC_REDO, KC_PC_COPY, KC_PC_PASTE,   KC_DELETE,      KC_INSERT   , KC_WWW_BACK
    ),

/*
 * Bracket Layer
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |NumLck|  ?   |  /   |  %   |(TO0) |                              |CapLck|  ~   |  +   |  &   |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |  @   |  *   |  !   |  "   |  $   |                              |   #  |  =   |  _   |  :   |      |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * | Click  | LCtrl|\(alt)|  ^   |  |   |  `   |      |      |  |      |      |   ]  |  _   |  ,   |  .   |  /   | Click  |
 * `----------------------+------+------+------+      |      |  |      |      |------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_BRACKETS] = LAYOUT(
      _______,  KC_NO,          KC_LGUI,        KC_NO,          KC_NO,          TO(0),                           KC_TRANSPARENT, LCTL(KC_GRAVE), LCTL(KC_SLASH), LALT(LSFT(KC_A)),LCTL(LSFT(KC_BSLASH)),_______,
      _______,  KC_LCTRL,      _______, KC_LALT,        KC_LSHIFT, KC_NO,                                       LCTL(LSFT(KC_BSLASH)),KC_LPRN,        KC_LCBR,        KC_LBRACKET,    KC_LABK, _______,
      LDIAL_CLK,KC_NO,          KC_NO,          KC_NO,          KC_NO,      KC_NO,  KC_MISSING, KC_MISSING, KC_MISSING, KC_MISSING, KC_TRANSPARENT, KC_RPRN,        KC_RCBR,        KC_RBRACKET,    KC_RABK,  RDIAL_CLK,
                                               _______, _______, _______,  _______, _______, _______, _______,   _______,      _______   , _______
    ),



/*
 * Function Layer: Function keys
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |  F9  | F10  | F11  | F12  |      |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |  F5  |  F6  |  F7  |  F8  |      |                              |      | Shift| Ctrl |  Alt |  GUI |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |  F1  |  F2  |  F3  |  F4  |      |      |      |  |      |      |      |      |      |      |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_FUNCTION] = LAYOUT(
      _______,  KC_NO,          KC_LGUI,        KC_NO,          KC_NO,          TO(0),                           _______, KC_F7,          KC_F8,          KC_F9,_______,RESET,
      _______,  KC_NO,  KC_NO,    _______, KC_LALT,        KC_NO,                                        _______,KC_F4,          KC_F5,          KC_F6,    _______, _______,
      LDIAL_CLK,KC_LCTRL,       KC_LALT,        KC_LSHIFT,          _______,      KC_NO,  KC_MISSING, KC_MISSING, KC_MISSING, KC_MISSING, _______, KC_F1,          KC_F2,          KC_F3,    _______,  RDIAL_CLK,
                                               _______, _______, _______,  _______, KC_SYSTEM_SLEEP, _______, _______,   KC_F10,         KC_F11,         KC_F12
    ),

/*
* Primary layer v2
*
* ,-------------------------------------------.                              ,--------------------------------------------.
 * |  Undo  |   Q  |W(win)|   F  |P(app)|G(goto)|                              |   J  |   L   |   U  |   Y  | ;  : |  REDO  |
 * |--------+------+------+------+------+-------|                              |------+-------+------+------+------+--------|
 * |  Tab   |A(lsh)|R(brk)|S(mov)|T(num)|   D   |                              |   H  |   N   |   E  |   I  |O(Rsh)|Ctrl/' "|
 * |--------+------+------+------+------+-------+-------------.  ,-------------+------+-------+------+------+------+--------|
 * | LClick |   Z  |   X  |   C  |   V  |   B   |      |      |  |      |      |   K  |M(mous)| ,(Sh)|.(Alt)|/(Ctr)| RClick |
 * `----------------------+------+------+-------+------+------|  |------+------+------+-------+------+----------------------'
 *                        |Copy  | Paste| Cut   |BSpace| Esc  |  | Enter| Space| Del  | Left  | Right|
 *                        |      |      |       |      |      |  |      |(Sym) |      |       |      |
 *                        `-----------------------------------'  `-----------------------------------'
 */
    [_PRIMARY2] = LAYOUT(
     KC_PC_UNDO, KC_Q        ,LGUI_T(KC_W), KC_F        , KC_P, KC_G,                                        KC_J,   KC_L      ,  KC_U          ,   KC_Y       ,KC_SCLN           , KC_PC_REDO,
     KC_TAB    , LSFT_T(KC_A),LBRACK(KC_R), LMOV(KC_S)  , LNUM(KC_T), KC_D      ,                                         KC_H,   KC_N      ,  KC_E          ,   KC_I       ,RSFT_T(KC_O)      , CTL_QUOT,
     LDIAL_CLK , LCTL_T(KC_Z),LALT_T(KC_X), LSFT_T(KC_C), LFUN(KC_V), KC_B      ,KC_MISSING,KC_MISSING,KC_MISSING, KC_MISSING, KC_K,LMOUSE(KC_M) ,RSFT_T(KC_COMMA),RALT_T(KC_DOT), RCTL_T(KC_BSLASH), RDIAL_CLK,
                                            KC_PC_COPY  ,KC_PC_PASTE,KC_PC_CUT  ,KC_BSPACE ,KC_ESCAPE ,KC_ENTER  , LSYM(KC_SPACE),KC_DELETE, KC_LEFT, KC_RIGHT
    ),

/*
 * Mouse Layer
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |NumLck|  ?   |  /   |  %   |(TO0) |                              |CapLck|  ~   |  +   |  &   |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |  @   |  *   |  !   |  "   |  $   |                              |   #  |  =   |  _   |  :   |      |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * | Click  | LCtrl|\(alt)|  ^   |  |   |  `   |      |      |  |      |      |   ]  |  _   |  ,   |  .   |  /   | Click  |
 * `----------------------+------+------+------+      |      |  |      |      |------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_MOUSE] = LAYOUT(
      _______,  KC_NO,         _______, KC_MS_UP,       KC_MS_WH_UP,         _______,                                                  _______, KC_NO,          KC_AUDIO_MUTE,  KC_AUDIO_VOL_DOWN,KC_AUDIO_VOL_UP,_______,
      _______,  KC_MS_WH_LEFT,  KC_MS_LEFT,     KC_MS_DOWN,     KC_MS_RIGHT,    KC_MS_WH_RIGHT,                                       _______, KC_MEDIA_REWIND,KC_MEDIA_PLAY_PAUSE,KC_MEDIA_STOP,  KC_MEDIA_FAST_FORWARD,KC_MEDIA_PLAY_PAUSE,
      LDIAL_CLK,_______, _______, _______, KC_MS_WH_DOWN,  _______,   KC_MISSING, KC_MISSING, KC_MISSING, KC_MISSING, _______, _______, KC_MEDIA_PREV_TRACK,KC_MEDIA_NEXT_TRACK, _______, RDIAL_CLK,
                                               _______, _______, KC_MS_BTN3,  KC_MS_BTN1,     KC_MS_BTN2, _______, _______,   _______,      KC_AUDIO_VOL_DOWN,KC_AUDIO_MUTE
    ),


/*
 * Games Layer
 *
 * ,-------------------------------------------.                                               ,-------------------------------------------.
 * |   T    | TAB  |  Q   |  W   |  E   |  R   |                                               |      |  7   |  8   |  9   |      |        |
 * |--------+------+------+------+------+------|                                               |------+------+------+------+------+--------|
 * |   G    |LShft |  A   |  S   |  D   |  F   |                                               |      |  4   |  5   |  6   |      |        |
 * |--------+------+------+------+------+------+                                               +------+------+------+------+------+--------|
 * | Click  | LCtrl|  Z   |  X   |  C   |  V   |                                               |   B  |  1   |  2   |  3   |      | Click  |
 * `----------------------+------+------+------+------+------|                   |------+------+------+------+------+----------------------'
 *                        |   1  |  2   |  Alt |  Spc |  Esc |                   |      |      |      |  0   |      |
 *                        `----------------------------------'                   `----------------------------------'
 */
    [_GAMES] = LAYOUT(
      KC_T     ,  KC_TAB   , KC_Q, KC_W, KC_E, KC_R,                                                     _______,  KC_7, KC_8, KC_9, _______, _______,
      KC_G     ,  KC_LSHIFT, KC_A, KC_S, KC_D, KC_F,                                                     _______,  KC_4, KC_5, KC_6, _______, _______,
      LDIAL_CLK,KC_LCTRL   , KC_Z, KC_X, KC_C, KC_V, KC_MISSING, KC_MISSING    , KC_MISSING, KC_MISSING, KC_B   ,  KC_1, KC_2, KC_3, _______, RDIAL_CLK,
                                  KC_1, KC_2, KC_LALT, KC_SPACE, KC_ESCAPE     , _______   , _______   , _______,  KC_0, _______
    ),    

    /*
 * Pass Layer
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |NumLck|  ?   |  /   |  %   |(TO0) |                              |CapLck|  ~   |  +   |  &   |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |  @   |  *   |  !   |  "   |  $   |                              |   #  |  =   |  _   |  :   |      |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * | Click  | LCtrl|\(alt)|  ^   |  |   |  `   |      |      |  |      |      |   ]  |  _   |  ,   |  .   |  /   | Click  |
 * `----------------------+------+------+------+      |      |  |      |      |------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_PASS] = LAYOUT(
      _______  , KC_1        , KC_2,    KC_R,    KC_0,    KC_T,                                                    KC_U   , KC_O   , KC_7   , KC_6   , _______     , _______  ,
      _______  , LSFT_T(KC_Q), KC_4,    KC_W,    KC_5,    KC_E,                                                    KC_Y   , KC_H   , KC_3   , KC_8   , RSFT_T(KC_9), _______  ,
      LDIAL_CLK,KC_A         , KC_S,    KC_D,    KC_F,    KC_G   , KC_MISSING, KC_MISSING, KC_MISSING, KC_MISSING, KC_I   , KC_J   , _______, _______, _______     , RDIAL_CLK,
                               _______, _______, _______, _______, _______   , _______   , _______   , _______   , _______, _______
    ),

    /*
 * Goto Layer
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |NumLck|  ?   |  /   |  %   |(TO0) |                              |CapLck|  ~   |  +   |  &   |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |  @   |  *   |  !   |  "   |  $   |                              |   #  |  =   |  _   |  :   |      |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * | Click  | LCtrl|\(alt)|  ^   |  |   |  `   |      |      |  |      |      |   ]  |  _   |  ,   |  .   |  /   | Click  |
 * `----------------------+------+------+------+      |      |  |      |      |------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    // [_GOTO] = LAYOUT(
    //   _______,  _______, _______, _______, _______,   TO(0),                                                 _______,  _______, _______, _______, _______, _______,
    //   _______,  _______, _______, _______, _______, _______,                                                 _______,  _______, _______, _______, _______, _______,
    //   LDIAL_CLK,_______, _______, _______, _______, _______, KC_MISSING, KC_MISSING, KC_MISSING, KC_MISSING, _______,  _______, _______, _______, _______, RDIAL_CLK,
    //                               _______, _______, _______, _______   , _______   , _______   , _______   , _______,  _______, _______
    // ),

/*
 * Base Layer: QWERTY
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |  Tab   |   Q  |   W  |   E  |   R  |   T  |                              |   Y  |   U  |   I  |   O  |   P  |  Bksp  |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |Ctrl/Esc|   A  |   S  |   D  |   F  |   G  |                              |   H  |   J  |   K  |   L  | ;  : |Ctrl/' "|
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  | [ {  |CapsLk|  |F-keys|  ] } |   N  |   M  | ,  < | . >  | /  ? | RShift |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |Adjust| LGUI | LAlt/| Space| Nav  |  | Sym  | Space| AltGr| RGUI | Menu |
 *                        |      |      | Enter|      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    // [_QWERTY] = LAYOUT(
    //  KC_TAB  , KC_Q ,  KC_W   ,  KC_E  ,   KC_R ,   KC_T ,                                             KC_Y,   KC_U ,  KC_I ,   KC_O ,  KC_P , KC_BSPC,
    //  CTL_ESC , KC_A ,  KC_S   ,  KC_D  ,   KC_F ,   KC_G ,                                             KC_H,   KC_J ,  KC_K ,   KC_L ,KC_SCLN,CTL_QUOT,
    //  KC_LSFT , KC_Z ,  KC_X   ,  KC_C  ,   KC_V ,   KC_B , KC_MISSING,KC_MISSING,KC_MISSING,KC_MISSING,KC_N,   KC_M ,KC_COMM, KC_DOT ,KC_SLSH, KC_RSFT,
    //                             TO(0)  , KC_LGUI, ALT_ENT, KC_BSPACE ,KC_ESC    ,KC_ENTER  ,KC_SPC    ,KC_RALT, KC_RGUI, KC_APP
    // ),
/*
 * Apps Layer
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |NumLck|  ?   |  /   |  %   |(TO0) |                              |CapLck|  ~   |  +   |  &   |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |  @   |  *   |  !   |  "   |  $   |                              |   #  |  =   |  _   |  :   |      |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * | Click  | LCtrl|\(alt)|  ^   |  |   |  `   |      |      |  |      |      |   ]  |  _   |  ,   |  .   |  /   | Click  |
 * `----------------------+------+------+------+      |      |  |      |      |------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    // [_APPS] = LAYOUT(
    //   _______,  _______, _______, _______, _______,   TO(0),                                                 _______,  _______, _______, _______, _______, _______,
    //   _______,  _______, _______, _______, _______, _______,                                                 _______,  _______, _______, _______, _______, _______,
    //   LDIAL_CLK,_______, _______, _______, _______, _______, KC_MISSING, KC_MISSING, KC_MISSING, KC_MISSING, _______,  _______, _______, _______, _______, RDIAL_CLK,
    //                               _______, _______, _______, _______   , _______   , _______   , _______   , _______,  _______, _______
    // ),    
};

/* The default OLED and rotary encoder code can be found at the bottom of qmk_firmware/keyboards/splitkb/kyria/rev1/rev1.c
 * These default settings can be overriden by your own settings in your keymap.c
 * For your convenience, here's a copy of those settings so that you can uncomment them if you wish to apply your own modifications.
 * DO NOT edit the rev1.c file; instead override the weakly defined default functions by your own.
 */

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) { return OLED_ROTATION_180; }

void oled_task_user(void) {
    if (is_keyboard_master()) {
        // QMK Logo and version information
        // clang-format off
        // static const char PROGMEM qmk_logo[] = {
        //     0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
        //     0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
        //     0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0};
        // // clang-format on

        // oled_write_P(qmk_logo, false);
        oled_write_P(PSTR("Peter Davidson\n\n"), false);

        // Host Keyboard Layer Status
        oled_write_P(PSTR("Layer: "), false);
        char buffer[40];
        strcpy_P(buffer, (PGM_P)pgm_read_word(&(layerNames[get_highest_layer(layer_state|default_layer_state)])));        
        oled_write_ln(buffer,false);
        oled_advance_page(true);
    
        //oled_write(layerNames[get_highest_layer(layer_state|default_layer_state)],false);
        // switch (get_highest_layer(layer_state|default_layer_state)) {
        //     case _QWERTY:
        //         oled_write_P(PSTR("QWERTY\n"), false);
        //         break;
        //     case _DVORAK:
        //         oled_write_P(PSTR("Dvorak\n"), false);
        //         break;
        //     case _COLEMAK_DH:
        //         oled_write_P(PSTR("Colemak-DH\n"), false);
        //         break;
        //     case _NAV:
        //         oled_write_P(PSTR("Nav\n"), false);
        //         break;
        //     case _SYM:
        //         oled_write_P(PSTR("Sym\n"), false);
        //         break;
        //     case _FUNCTION:
        //         oled_write_P(PSTR("Function\n"), false);
        //         break;
        //     case _ADJUST:
        //         oled_write_P(PSTR("Adjust\n"), false);
        //         break;
        //     default:
        //         oled_write_P(PSTR("Undefined\n"), false);
        // }

        // Write host Keyboard LED Status to OLEDs
        led_t led_usb_state = host_keyboard_led_state();
        oled_write_P(led_usb_state.num_lock    ? PSTR("NUMLCK ") : PSTR("       "), false);
        oled_write_P(led_usb_state.caps_lock   ? PSTR("CAPLCK ") : PSTR("       "), false);
        oled_write_P(led_usb_state.scroll_lock ? PSTR("SCRLCK ") : PSTR("       "), false);
    } else {
        oled_clear();
        oled_write_P(PSTR("Peter was here\n"), false);
        
        // clang-format off    
        // static const char PROGMEM kyria_logo[] = {
        //     0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,128,192,224,240,112,120, 56, 60, 28, 30, 14, 14, 14,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7, 14, 14, 14, 30, 28, 60, 56,120,112,240,224,192,128,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        //     0,  0,  0,  0,  0,  0,  0,192,224,240,124, 62, 31, 15,  7,  3,  1,128,192,224,240,120, 56, 60, 28, 30, 14, 14,  7,  7,135,231,127, 31,255,255, 31,127,231,135,  7,  7, 14, 14, 30, 28, 60, 56,120,240,224,192,128,  1,  3,  7, 15, 31, 62,124,240,224,192,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        //     0,  0,  0,  0,240,252,255, 31,  7,  1,  0,  0,192,240,252,254,255,247,243,177,176, 48, 48, 48, 48, 48, 48, 48,120,254,135,  1,  0,  0,255,255,  0,  0,  1,135,254,120, 48, 48, 48, 48, 48, 48, 48,176,177,243,247,255,254,252,240,192,  0,  0,  1,  7, 31,255,252,240,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        //     0,  0,  0,255,255,255,  0,  0,  0,  0,  0,254,255,255,  1,  1,  7, 30,120,225,129,131,131,134,134,140,140,152,152,177,183,254,248,224,255,255,224,248,254,183,177,152,152,140,140,134,134,131,131,129,225,120, 30,  7,  1,  1,255,255,254,  0,  0,  0,  0,  0,255,255,255,  0,  0,  0,  0,255,255,  0,  0,192,192, 48, 48,  0,  0,240,240,  0,  0,  0,  0,  0,  0,240,240,  0,  0,240,240,192,192, 48, 48, 48, 48,192,192,  0,  0, 48, 48,243,243,  0,  0,  0,  0,  0,  0, 48, 48, 48, 48, 48, 48,192,192,  0,  0,  0,  0,  0,
        //     0,  0,  0,255,255,255,  0,  0,  0,  0,  0,127,255,255,128,128,224,120, 30,135,129,193,193, 97, 97, 49, 49, 25, 25,141,237,127, 31,  7,255,255,  7, 31,127,237,141, 25, 25, 49, 49, 97, 97,193,193,129,135, 30,120,224,128,128,255,255,127,  0,  0,  0,  0,  0,255,255,255,  0,  0,  0,  0, 63, 63,  3,  3, 12, 12, 48, 48,  0,  0,  0,  0, 51, 51, 51, 51, 51, 51, 15, 15,  0,  0, 63, 63,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 48, 48, 63, 63, 48, 48,  0,  0, 12, 12, 51, 51, 51, 51, 51, 51, 63, 63,  0,  0,  0,  0,  0,
        //     0,  0,  0,  0, 15, 63,255,248,224,128,  0,  0,  3, 15, 63,127,255,239,207,141, 13, 12, 12, 12, 12, 12, 12, 12, 30,127,225,128,  0,  0,255,255,  0,  0,128,225,127, 30, 12, 12, 12, 12, 12, 12, 12, 13,141,207,239,255,127, 63, 15,  3,  0,  0,128,224,248,255, 63, 15,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        //     0,  0,  0,  0,  0,  0,  0,  3,  7, 15, 62,124,248,240,224,192,128,  1,  3,  7, 15, 30, 28, 60, 56,120,112,112,224,224,225,231,254,248,255,255,248,254,231,225,224,224,112,112,120, 56, 60, 28, 30, 15,  7,  3,  1,128,192,224,240,248,124, 62, 15,  7,  3,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        //     0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  3,  7, 15, 14, 30, 28, 60, 56,120,112,112,112,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,112,112,112,120, 56, 60, 28, 30, 14, 15,  7,  3,  1,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0
        // };
        // // clang-format on
        // oled_write_raw_P(kyria_logo, sizeof(kyria_logo));
    }
}
#endif

#ifdef ENCODER_ENABLE
uint8_t selected_layer = 0;

bool encoder_update_user(uint8_t index, bool clockwise) {

    if (index == 0) {
      clockwise= !clockwise; // since the board is inverted 
      selected_layer+=clockwise?1:-1;
      selected_layer=(selected_layer+NUMLAYERS)%NUMLAYERS;
      layer_clear();
      layer_on(selected_layer);
        // // Page up/Page down
        // if (clockwise) {
        //     tap_code(KC_PGUP);
        // } else {
        //     tap_code(KC_PGDN);
        // }

    } else if (index == 1) {
        //var layer=get_highest_layer(layer_state|default_layer_state);
        if(layer_state_is(_MOVEMENT)){
            if(clockwise){
                tap_code(KC_MS_WH_DOWN);
            } else {
                tap_code(KC_MS_WH_UP);
            }
            return false;
        }

        // Default is Volume control
        if (clockwise) {
            tap_code(KC_VOLD);tap_code(KC_VOLD);
        } else {
            tap_code(KC_VOLU);tap_code(KC_VOLU);
        }
    }
    return false;
}
#endif

const rgblight_segment_t PROGMEM my_capslock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {6, 4, HSV_RED},       // Light 4 LEDs, starting with LED 6
    {12, 4, HSV_RED}       // Light 4 LEDs, starting with LED 12
);
// Light LEDs 9 & 10 in cyan when keyboard layer 1 is active
const rgblight_segment_t PROGMEM my_layer1_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {9, 2, HSV_CYAN}
);
// Light LEDs 11 & 12 in purple when keyboard layer 2 is active
const rgblight_segment_t PROGMEM my_layer2_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {11, 2, HSV_PURPLE}
);
// Light LEDs 13 & 14 in green when keyboard layer 3 is active
const rgblight_segment_t PROGMEM my_layer3_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {13, 2, HSV_GREEN}
);

// Now define the array of layers. Later layers take precedence
const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    my_capslock_layer,
    my_layer1_layer,    // Overrides caps lock layer
    my_layer2_layer,    // Overrides other layers
    my_layer3_layer     // Overrides other layers
);

void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;
}

bool led_update_user(led_t led_state) {
    rgblight_set_layer_state(0, led_state.caps_lock);
    return true;
}

layer_state_t default_layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(1, layer_state_cmp(state, _COLEMAK));
    return state;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(2, layer_state_cmp(state, _NUMBERS));
    rgblight_set_layer_state(3, layer_state_cmp(state, _SYMBOLS));
    return state;
}