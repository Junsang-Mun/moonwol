// moonwol 42-key - corne(crkbd)

#include QMK_KEYBOARD_H

enum layers { _BASE, _SYM, _NUM, _NAV, _FN };

#define TAB_SYM LT(_SYM, KC_TAB)
#define SPC_NUM LT(_NUM, KC_SPC)
#define BSP_NAV LT(_NAV, KC_BSPC)
#define ENT_FN  LT(_FN,  KC_ENT)

#define UNDO    G(KC_Z)
#define CUT     G(KC_X)
#define COPY    G(KC_C)
#define PASTE   G(KC_V)
#define REDO    SGUI(KC_Z)          // Cmd+Shift+Z
#define SCRSHOT SGUI(KC_4)          // Cmd+Shift+4
#define LOCKSCR C(G(KC_Q))          // Ctrl+Cmd+Q
#define DSK_L   C(KC_LEFT)
#define DSK_R   C(KC_RGHT)
#define MSN_CTL C(KC_UP)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_split_3x6_3(
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,       KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,    KC_BSPC,
        KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,       KC_H,    KC_J,    KC_K,    KC_L,   KC_SCLN, KC_QUOT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,       KC_N,    KC_M,    KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,
                                   KC_ESC,  TAB_SYM, SPC_NUM,    BSP_NAV, ENT_FN,  KC_CAPS
    ),
    [_SYM] = LAYOUT_split_3x6_3(
        KC_TAB,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    KC_LCBR, KC_EXLM, KC_AT,   KC_HASH, KC_RCBR, KC_BSPC,
        KC_LCTL, KC_LSFT, KC_LALT, KC_LCTL, KC_LGUI, XXXXXXX,    KC_GRV,  KC_DLR,  KC_PERC, KC_CIRC, KC_EQL,  XXXXXXX,
        KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    KC_SCLN, KC_AMPR, KC_ASTR, KC_LPRN, KC_QUOT, KC_RSFT,
                                   KC_ESC,  _______, KC_SPC,     KC_MINS, KC_UNDS, KC_RPRN
    ),
    [_NUM] = LAYOUT_split_3x6_3(
        KC_TAB,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    KC_LBRC, KC_1,    KC_2,    KC_3,    KC_RBRC, KC_BSPC,
        KC_LCTL, KC_LSFT, KC_LALT, KC_LCTL, KC_LGUI, XXXXXXX,    KC_SCLN, KC_4,    KC_5,    KC_6,    KC_EQL,  XXXXXXX,
        KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    KC_GRV,  KC_7,    KC_8,    KC_9,    KC_BSLS, KC_RSFT,
                                   KC_ESC,  KC_TAB,  _______,    KC_BSPC, KC_ENT,  KC_0
    ),
    [_NAV] = LAYOUT_split_3x6_3(
        KC_TAB,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    KC_HOME, KC_PGDN, KC_PGUP, KC_END,  XXXXXXX, KC_BSPC,
        KC_LCTL, KC_LSFT, KC_LALT, KC_LCTL, KC_LGUI, XXXXXXX,    KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX, XXXXXXX,
        KC_LSFT, UNDO,    CUT,     COPY,    PASTE,   REDO,       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_RSFT,
                                   KC_ESC,  KC_TAB,  KC_SPC,     _______, KC_ENT,  KC_CAPS
    ),
    [_FN] = LAYOUT_split_3x6_3(
        KC_TAB,  KC_F10,  KC_F1,   KC_F2,   KC_F3,   SCRSHOT,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOT, KC_BSPC,
        KC_LCTL, KC_F11,  KC_F4,   KC_F5,   KC_F6,   LOCKSCR,    XXXXXXX, KC_LGUI, KC_LCTL, KC_LALT, KC_LSFT, XXXXXXX,
        KC_LSFT, KC_F12,  KC_F7,   KC_F8,   KC_F9,   XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_RSFT,
                                   DSK_L,   MSN_CTL, DSK_R,      KC_BSPC, _______, KC_CAPS
    ),
};

const uint16_t PROGMEM we_combo[]  = {KC_W,    KC_E,    COMBO_END};
const uint16_t PROGMEM sd_combo[]  = {KC_S,    KC_D,    COMBO_END};
const uint16_t PROGMEM xc_combo[]  = {KC_X,    KC_C,    COMBO_END};
const uint16_t PROGMEM io_combo[]  = {KC_I,    KC_O,    COMBO_END};
const uint16_t PROGMEM jk_combo[]  = {KC_J,    KC_K,    COMBO_END};
const uint16_t PROGMEM kl_combo[]  = {KC_K,    KC_L,    COMBO_END};
const uint16_t PROGMEM cd_combo[]  = {KC_COMM, KC_DOT,  COMBO_END};
const uint16_t PROGMEM dp_combo[]  = {KC_DLR,  KC_PERC, COMBO_END};  // SYM: $ + %
const uint16_t PROGMEM n45_combo[] = {KC_4,    KC_5,    COMBO_END};  // NUM: 4 + 5

combo_t key_combos[] = {
    COMBO(we_combo,  KC_ESC),
    COMBO(sd_combo,  KC_LGUI),
    COMBO(xc_combo,  KC_LALT),
    COMBO(io_combo,  KC_ESC),
    COMBO(jk_combo,  KC_BSPC),
    COMBO(kl_combo,  KC_RGUI),
    COMBO(cd_combo,  KC_RALT),
    COMBO(dp_combo,  KC_BSPC),
    COMBO(n45_combo, KC_BSPC),
};