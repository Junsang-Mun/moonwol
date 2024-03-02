#include QMK_KEYBOARD_H

enum layers {
    BASE = 0,
    MO1,
    MO2,
    MO3,
    MO4,
};

enum custom_keycodes {
    KC_WON = SAFE_RANGE,
    MA_LANG,
    MA_SPOT,
    DS_LEFT,
    MISSION,
    DS_RGHT,
    TAB_L,
    TAB_R,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case KC_WON:
        if (record->event.pressed) {
            SEND_STRING("₩");
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
    case MISSION:
        if (record->event.pressed) {
            send_string(SS_LCTL(SS_TAP(X_UP)));
        }
        break;
    case DS_RGHT:
        if (record->event.pressed) {
            send_string(SS_LCTL(SS_TAP(X_RGHT)));
        }
        break;
    case TAB_L:
        if (record->event.pressed) {
            send_string(SS_LCTL(SS_TAP(X_TAB)));
        }
        break;
    case TAB_R:
        if (record->event.pressed) {
            send_string(SS_LSFT(SS_LCTL(SS_TAP(X_TAB))));
        }
        break;
    }
    return true;
};

// Custom Keycodes
#define KC_MZ LSFT_T(KC_Z)
#define KC_MSLSH LSFT_T(KC_SLSH)
#define KC_MA LCTL_T(KC_A)
#define KC_MSCLN LCTL_T(KC_SCLN)

#define MS_LCLK KC_MS_BTN1
#define MS_RCLK KC_MS_BTN2
#define MS_W_UP KC_MS_WH_UP
#define MS_W_DN KC_MS_WH_DOWN

#define TC_1 LT(MO1, KC_TAB)
#define TC_2 LT(MO2, KC_SPC)
#define TC_3 LT(MO3, KC_ENT)
#define TC_4 LT(MO4, KC_BSPC)


// Combo keys
const uint16_t PROGMEM c_esc[] = {KC_W, KC_E, COMBO_END};
const uint16_t PROGMEM c_lcmd[] = {KC_S, KC_D, COMBO_END};
const uint16_t PROGMEM c_rcmd[] = {KC_K, KC_L, COMBO_END};
const uint16_t PROGMEM c_lalt[] = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM c_ralt[] = {KC_COMM, KC_DOT, COMBO_END};
const uint16_t PROGMEM c_bsp[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM c_del[] = {KC_I, KC_O, COMBO_END};

const uint16_t PROGMEM c_lang[] = {KC_MA, TC_2, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    COMBO(c_esc, KC_ESC),
    COMBO(c_lcmd, KC_LGUI),
    COMBO(c_rcmd, KC_LGUI),
    COMBO(c_lalt, KC_LALT),
    COMBO(c_ralt, KC_LALT),
    COMBO(c_bsp, KC_BSPC),
    COMBO(c_del, KC_DEL),
    COMBO(c_lang, MA_LANG),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[BASE] = LAYOUT(
// |--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------|
    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
// |--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------|
    KC_MA,   KC_S,    KC_D,    KC_F,    KC_G,       KC_H,    KC_J,    KC_K,    KC_L,    KC_MSCLN,
// |--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------|
    KC_MZ,   KC_X,    KC_C,    KC_V,    KC_B,       KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_MSLSH,
// |--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------|
                               TC_1,    TC_2,       TC_3,    TC_4
),

[MO1] = LAYOUT(
// |--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------|
    _______, _______, _______, _______, _______,    _______, _______, KC_MINS, KC_EQL,  KC_BSLS,
// |--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------|
    _______, _______, _______, _______, _______,    _______, _______, _______, KC_LBRC, KC_RBRC,
// |--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------|
    KC_LSFT, _______, _______, _______, _______,    _______, _______, _______, _______, KC_RSFT,
// |--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------|
                               _______, _______,    _______, _______
),

[MO2] = LAYOUT(
// |--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------|
    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,       KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
// |--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------|
    KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,    KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,
// |--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------|
    KC_LSFT, _______, _______, _______, _______,    _______, _______, _______, _______, KC_RSFT,
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
    _______, _______, KC_UP,   _______, DT_UP,      MS_W_UP, MS_LCLK, KC_MS_U, MS_RCLK, MS_W_UP,
// |--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------|
    _______, KC_LEFT, KC_DOWN, KC_RGHT, DT_PRNT,    MS_W_DN, KC_MS_L, KC_MS_D, KC_MS_R, MS_W_DN,
// |--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------|
    _______, DS_LEFT, MISSION, DS_RGHT, DT_DOWN,    _______, TAB_R,   _______, TAB_L,   _______,
// |--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------|
                               _______, _______,    _______, _______
),

};
