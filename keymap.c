#include QMK_KEYBOARD_H
#include "password.h"

enum layers {
    BASE = 0,
    MO1,
    MO2,
    MO3,
    MO4,
};

enum custom_keycodes {
    MA_PASS,
    MA_LANG,
    MA_SPOT,
    DS_LEFT,
    DS_RGHT,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case MA_PASS:
        if (record->event.pressed) {
            SEND_STRING(_PASSWORD);
        }
        break;
    case MA_LANG:
        if (record->event.pressed) {
            SEND_STRING(SS_LCTL(" "));
        }
        break;
    case MA_SPOT:
        if (record->event.pressed) {
            SEND_STRING(SS_LGUI(" "));
        }
        break;
    case DS_LEFT:
        if (record->event.pressed) {
            send_string(SS_LCTL(SS_TAP(X_LEFT)));
        }
        break;
    case DS_RGHT:
        if (record->event.pressed) {
            send_string(SS_LCTL(SS_TAP(X_RGHT)));
        }
        break;
    }
    return true;
};

// Custom Keycodes

// Shift
#define KC_MZ LSFT_T(KC_Z)
#define KC_MSLSH LSFT_T(KC_SLSH)
// GUI
#define KC_MC LGUI_T(KC_C)
#define KC_MCOMM LGUI_T(KC_COMM)
// ALT
#define KC_MX LALT_T(KC_X)
#define KC_MDOT LGUI_T(KC_DOT)
// Control
#define KC_MA LCTL_T(KC_A)
#define KC_MSCLN LCTL_T(KC_SCLN)

// Mouse Keys
#define MS_LCLK KC_MS_BTN1
#define MS_RCLK KC_MS_BTN2
#define MS_W_UP KC_MS_WH_UP
#define MS_W_DN KC_MS_WH_DOWN

// Thumb Clusters
#define TC_1 LT(MO1, KC_TAB)
#define TC_2 LT(MO2, KC_SPC)
#define TC_3 LT(MO3, KC_ENT)
#define TC_4 LT(MO4, KC_BSPC)


// Combo keys
const uint16_t PROGMEM c_esc[] = {KC_W, KC_E, COMBO_END};
const uint16_t PROGMEM c_lang[] = {KC_MA, TC_2, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    COMBO(c_esc, KC_ESC),
    COMBO(c_lang, MA_LANG),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[BASE] = LAYOUT(
// |--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------|
    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
// |--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------|
    KC_MA,   KC_S,    KC_D,    KC_F,    KC_G,       KC_H,    KC_J,    KC_K,    KC_L,    KC_MSCLN,
// |--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------|
    KC_MZ,   KC_MX,   KC_MC,   KC_V,    KC_B,       KC_N,    KC_M,    KC_MCOMM,KC_MDOT, KC_MSLSH,
// |--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------|
                               TC_1,    TC_2,       TC_3,    TC_4
),

[MO1] = LAYOUT(
// |--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------|
    MA_PASS, _______, KC_UP,   _______, DT_UP,      _______, _______, _______, _______, _______,
// |--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------|
    KC_LCTL, KC_LEFT, KC_DOWN, KC_RGHT, DT_PRNT,    _______, KC_MPRV, KC_MPLY, KC_MNXT, _______,
// |--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------|
    _______, DS_LEFT, _______, DS_RGHT, DT_DOWN,    KC_VOLD, KC_VOLU, KC_BRID, KC_BRIU, _______,
// |--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------|
                               _______, _______,    _______, _______
),

[MO2] = LAYOUT(
// |--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------|
    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,       KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
// |--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------|
    KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,    KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,
// |--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------|
    KC_EXLM, KC_HASH, KC_LCBR, KC_RCBR, KC_TILD,    KC_AMPR, KC_UNDS, KC_EQL,  KC_PERC, KC_CIRC,
// |--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------|
                               _______, _______,    KC_DQT,  KC_QUOT
),

[MO3] = LAYOUT(
// |--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------|
    _______, KC_F9,   KC_F10,  KC_F11,  KC_F12,     _______, _______, _______, _______, _______,
// |--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------|
    _______, KC_F5,   KC_F6,   KC_F7,   KC_F8,      _______, KC_MPRV, KC_MPLY, KC_MNXT, _______,
// |--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------|
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,      KC_VOLD, KC_VOLU, KC_BRID, KC_BRIU, _______,
// |--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------|
                               _______, _______,    _______, _______
),

[MO4] = LAYOUT(
// |--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------|
    KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,    KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,
// |--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------|
    KC_DLR,  KC_PLUS, KC_LPRN, KC_RPRN, KC_AT,      KC_PIPE, KC_UNDS, KC_EQL,  KC_DQT,  KC_QUOT,
// |--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------|
    KC_EXLM, KC_HASH, KC_LCBR, KC_RCBR, KC_TILD,    KC_AMPR, KC_LBRC, KC_RBRC, KC_PERC, KC_CIRC,
// |--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------|
                               _______, _______,    _______, _______
),
};
