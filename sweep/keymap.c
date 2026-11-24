//moonwol 34-key — Ferris Sweep

#include QMK_KEYBOARD_H

enum layers { _BASE, _SYM, _NUM, _NAV, _FN };

#define CTL_A   LCTL_T(KC_A)
#define SFT_Z   LSFT_T(KC_Z)
#define CTL_SCL RCTL_T(KC_SCLN)
#define SFT_SLS RSFT_T(KC_SLSH)

#define SYM_TAB LT(_SYM, KC_TAB)
#define NUM_SPC LT(_NUM, KC_SPC)
#define NAV_BSP LT(_NAV, KC_BSPC)
#define FN_ENT  LT(_FN, KC_ENT)

#define SFT_QUO RSFT_T(KC_QUOT)
#define SFT_BSL RSFT_T(KC_BSLS)

// macOS 단축키
#define M_UNDO  G(KC_Z)
#define M_CUT   G(KC_X)
#define M_COPY  G(KC_C)
#define M_PSTE  G(KC_V)
#define M_REDO  SGUI(KC_Z)
#define M_SHOT  SGUI(KC_4)     // 영역 스크린샷
#define M_LOCK  C(G(KC_Q))     // 화면 잠금
#define M_DSKL  C(KC_LEFT)     // 왼쪽 데스크탑
#define M_DSKR  C(KC_RGHT)     // 오른쪽 데스크탑

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_BASE] = LAYOUT_split_3x5_2(
        KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
        CTL_A,   KC_S,    KC_D,    KC_F,    KC_G,         KC_H,    KC_J,    KC_K,    KC_L,    CTL_SCL,
        SFT_Z,   KC_X,    KC_C,    KC_V,    KC_B,         KC_N,    KC_M,    KC_COMM, KC_DOT,  SFT_SLS,
                                   SYM_TAB, NUM_SPC,      NAV_BSP, FN_ENT
    ),

    [_SYM] = LAYOUT_split_3x5_2(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      KC_LCBR, KC_EXLM, KC_AT,   KC_HASH, KC_RCBR,
        KC_LSFT, KC_LALT, KC_LCTL, KC_LGUI, XXXXXXX,      KC_GRV,  KC_DLR,  KC_PERC, KC_CIRC, KC_EQL,
        KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      KC_UNDS, KC_AMPR, KC_ASTR, KC_LPRN, SFT_QUO,
                                   _______, KC_SPC,       KC_MINS, KC_RPRN
    ),

    [_NUM] = LAYOUT_split_3x5_2(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      KC_LBRC, KC_1,    KC_2,    KC_3,    KC_RBRC,
        KC_LSFT, KC_LALT, KC_LCTL, KC_LGUI, XXXXXXX,      KC_SCLN, KC_4,    KC_5,    KC_6,    KC_EQL,
        KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      KC_GRV,  KC_7,    KC_8,    KC_9,    SFT_BSL,
                                   KC_TAB,  _______,      KC_BSPC, KC_0
    ),

    [_NAV] = LAYOUT_split_3x5_2(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      KC_HOME, KC_PGDN, KC_PGUP, KC_END,  XXXXXXX,
        KC_LSFT, KC_LALT, KC_LCTL, KC_LGUI, XXXXXXX,      KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX,
        M_UNDO,  M_CUT,   M_COPY,  M_PSTE,  M_REDO,       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                   KC_TAB,  KC_SPC,       _______, KC_ENT
    ),

    [_FN] = LAYOUT_split_3x5_2(
        KC_F10,  KC_F1,   KC_F2,   KC_F3,   M_SHOT,       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        KC_F11,  KC_F4,   KC_F5,   KC_F6,   M_LOCK,       XXXXXXX, KC_RGUI, KC_RCTL, KC_RALT, KC_RSFT,
        KC_F12,  KC_F7,   KC_F8,   KC_F9,   XXXXXXX,      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                   M_DSKL,  M_DSKR,       KC_BSPC, _______
    ),
};

// ---- 콤보 ----
const uint16_t PROGMEM esc_l[]   = {KC_W,    KC_E,    COMBO_END};
const uint16_t PROGMEM gui_l[]   = {KC_S,    KC_D,    COMBO_END};
const uint16_t PROGMEM alt_l[]   = {KC_X,    KC_C,    COMBO_END};
const uint16_t PROGMEM esc_r[]   = {KC_I,    KC_O,    COMBO_END};
const uint16_t PROGMEM bsp_r[]   = {KC_J,    KC_K,    COMBO_END};
const uint16_t PROGMEM gui_r[]   = {KC_K,    KC_L,    COMBO_END};
const uint16_t PROGMEM alt_r[]   = {KC_COMM, KC_DOT,  COMBO_END};
const uint16_t PROGMEM bsp_sym[] = {KC_DLR,  KC_PERC, COMBO_END};
const uint16_t PROGMEM bsp_num[] = {KC_4,    KC_5,    COMBO_END};

combo_t key_combos[] = {
    COMBO(esc_l,   KC_ESC),
    COMBO(gui_l,   KC_LGUI),
    COMBO(alt_l,   KC_LALT),
    COMBO(esc_r,   KC_ESC),
    COMBO(bsp_r,   KC_BSPC),
    COMBO(gui_r,   KC_RGUI),
    COMBO(alt_r,   KC_RALT),
    COMBO(bsp_sym, KC_BSPC),
    COMBO(bsp_num, KC_BSPC),
};
