#include QMK_KEYBOARD_H

#ifdef DEFERRED_EXEC_ENABLE
#    include "deferred_exec.h"
#endif

enum charybdis_keymap_layers {
    LAYER_BASE = 0,
    LAYER_NUMBER,
    LAYER_SYMBOL,
    LAYER_CURSOR,
    LAYER_GAME,
    LAYER_SYSTEM,
    LAYER_POINTER,
};

/** \brief Automatically enable sniping-mode on the pointer layer. */
#define CHARYBDIS_AUTO_SNIPING_ON_LAYER LAYER_POINTER

#ifdef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE
static uint16_t auto_pointer_layer_timer = 0;

#    ifndef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS
#        define CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS 1000
#    endif // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS

#    ifndef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD
#        define CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD 8
#    endif // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD
#endif     // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE

// Layer Tap
#define DEL_CUR LT(LAYER_CURSOR, KC_DEL)
#define BSPC_NUM LT(LAYER_NUMBER, KC_BSPC)
#define RET_SYM LT(LAYER_SYMBOL, KC_ENT)
#define ESC_NUM LT(LAYER_NUMBER, KC_ESC)
#define MINS_SYS LT(LAYER_SYSTEM, KC_MINS)
#define Z_PTR LT(LAYER_POINTER, KC_Z)
#define SLSH_PTR LT(LAYER_POINTER, KC_SLSH)

// Homerow Mods
#define HRM_A MT(MOD_LSFT, KC_A)
#define HRM_S MT(MOD_LCTL, KC_S)
#define HRM_D MT(MOD_LALT, KC_D)
#define HRM_F MT(MOD_LGUI, KC_F)
#define HRM_J MT(MOD_LGUI, KC_J)
#define HRM_K MT(MOD_RALT, KC_K)
#define HRM_L MT(MOD_RCTL, KC_L)
#define HRM_SCLN MT(MOD_RSFT, KC_SCLN)

// Miscellaneous
#define CUT LCTL(KC_X)
#define COPY LCTL(KC_C)
#define PSTE LCTL(KC_V)
#define FIND LCTL(KC_F)
#define UNDO LCTL(KC_Z)
#define REDO LCTL(KC_Y)
#define SSFT OSM(MOD_LSFT)
#define SCRN LSFT(LGUI(KC_S))
#define STAB LSFT(KC_TAB)
#define GTAB LGUI(KC_TAB)
#define SEL_ALL LCTL(KC_A)
#define CSESC LCTL(LSFT(KC_ESC))
#define CADEL LCTL(LALT(KC_DEL))
#define PRINT LCTL(KC_P)
#define LOCK LGUI(KC_L)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [LAYER_BASE] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
       KC_ESC,     KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,     KC_Y,    KC_U,    KC_I,    KC_O,  KC_P,    MINS_SYS,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       KC_TAB,     HRM_A,   HRM_S,   HRM_D,   HRM_F,   KC_G,     KC_H,    HRM_J,   HRM_K,   HRM_L, HRM_SCLN,KC_QUOT,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
     LSFT(KC_TAB), Z_PTR,   KC_X,    KC_C,    KC_V,    KC_B,     KC_N,    KC_M,    KC_COMM, KC_DOT,SLSH_PTR,KC_BSLS,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                 DEL_CUR, BSPC_NUM, KC_LSFT,     KC_SPC,    RET_SYM
  //                           ╰────────────────────────────╯ ╰──────────────────────╯
  ),

  [LAYER_NUMBER] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
       KC_TRNS,   SSFT,     REDO,    UNDO,    FIND,    CUT,     KC_ASTR,  KC_7,    KC_8,    KC_9,  KC_SLSH, KC_PERC,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       KC_TRNS,   KC_LSFT,  KC_LCTL, KC_LALT, KC_LGUI, COPY,    KC_PLUS,  KC_4,    KC_5,    KC_6,  KC_MINS, KC_CIRC,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       KC_TRNS,   GTAB,     STAB,    KC_ENT,  SCRN,    PSTE,    KC_DLR,   KC_1,    KC_2,    KC_3,  KC_DOT,  KC_HASH,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                              S(KC_COMM), KC_EQL, S(KC_DOT),    TO(LAYER_BASE), KC_UNDS
  //                        ╰───────────────────────────────╯ ╰─────────────────────────╯
  ),

  [LAYER_SYMBOL] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
       KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,    KC_SCLN,  KC_NO,   KC_NO,   KC_NO, KC_COLN, KC_CLR,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       KC_LBRC, KC_LCBR, KC_LPRN, KC_RPRN, KC_RCBR, KC_RBRC,    KC_PLUS,  KC_NO,   KC_NO,   KC_NO, KC_MINS, KC_APP,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       KC_GRV,  KC_CIRC, KC_AMPR, KC_ASTR, KC_PIPE, KC_BSLS,    KC_QUOT,  KC_CALC, KC_NO,   KC_NO, KC_DQUO, KC_SLCT,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                              S(KC_COMM), KC_EQL, S(KC_DOT),    TO(LAYER_BASE), KC_UNDS
  //                        ╰───────────────────────────────╯ ╰─────────────────────────╯
  ),

  [LAYER_CURSOR] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
      KC_CAPS,  SSFT,    REDO,    UNDO,    FIND,    CUT,        KC_HOME,  KC_PGDN, KC_PGUP, KC_END,  KC_INS,  KC_DEL,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
      KC_TRNS,  KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, COPY,       KC_LEFT,  KC_DOWN, KC_UP,   KC_RGHT, PRINT,   KC_NUM,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
      KC_TRNS,  KC_MSTP, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT,    KC_NO,    KC_NO,   KC_NO,   KC_NO,   SEL_ALL, KC_SCRL,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                           TO(LAYER_BASE), KC_MUTE, KC_MPLY,    TO(LAYER_BASE), KC_TRNS
  //                     ╰──────────────────────────────────╯ ╰─────────────────────────╯
  ),

  [LAYER_GAME] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
       KC_T,     KC_TAB,    KC_Q,    KC_W,    KC_E,   KC_R,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       KC_G,     KC_LSFT,   KC_A,    KC_S,    KC_D,   KC_F,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       KC_B,     KC_LCTL,   KC_Z,    KC_X,    KC_C,   KC_V,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                 KC_ENT,  ESC_NUM,  KC_SPC,     TO(LAYER_BASE), KC_BSPC
  //                           ╰────────────────────────────╯ ╰─────────────────────────╯
  ),

  [LAYER_SYSTEM] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
       CSESC,    KC_NO,     LOCK,    KC_SLEP, KC_PWR, CADEL,    KC_F18,   KC_F7,   KC_F8,   KC_F9,  KC_F12,  KC_TRNS,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       LOCK,     KC_NO,     KC_BRID, KC_BRIU, KC_NO,  KC_NO,    KC_F17,   KC_F4,   KC_F5,   KC_F6,  KC_F11,  KC_F14,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       KC_NO,    KC_NO,     KC_NO,   KC_NO,   KC_NO,  KC_NO,    KC_F16,   KC_F1,   KC_F2,   KC_F3,  KC_F10,  KC_F13,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
           TO(LAYER_CURSOR),TO(LAYER_NUMBER),TO(LAYER_GAME),    TO(LAYER_BASE), KC_NO
  //     ╰──────────────────────────────────────────────────╯ ╰───────────────────────╯
  ),

  [LAYER_POINTER] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
       QK_BOOT,  EE_CLR, XXXXXXX, XXXXXXX, DPI_MOD, S_D_MOD,    S_D_MOD, DPI_MOD, XXXXXXX, XXXXXXX,  EE_CLR, QK_BOOT,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,    XXXXXXX, KC_RSFT, KC_RCTL, KC_RALT, KC_RGUI, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX, _______, DRGSCRL, SNIPING, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, SNIPING, DRGSCRL, _______, XXXXXXX,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                  MS_BTN2, MS_BTN1, MS_BTN3,    MS_BTN3, MS_BTN1
  //                            ╰───────────────────────────╯ ╰──────────────────╯
  ),
};
// clang-format on

// Hold-Tap Tuning
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    if (IS_QK_MOD_TAP(keycode)) {
        return 280;
    }
    return TAPPING_TERM;
}

uint16_t get_quick_tap_term(uint16_t keycode, keyrecord_t *record) {
    if (IS_QK_MOD_TAP(keycode)) {
        return 175;
    }
    return 0;
}

bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    return IS_QK_MOD_TAP(keycode);
}

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    return IS_QK_LAYER_TAP(keycode);
}

// Chordal Hold
#ifdef CHORDAL_HOLD
const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM = LAYOUT('L', 'L', 'L', 'L', 'L', 'L', 'R', 'R', 'R', 'R', 'R', 'R', 'L', 'L', 'L', 'L', 'L', 'L', 'R', 'R', 'R', 'R', 'R', 'R', 'L', 'L', 'L', 'L', 'L', 'L', 'R', 'R', 'R', 'R', 'R', 'R', '*', '*', '*', '*', '*');
#endif // CHORDAL_HOLD
