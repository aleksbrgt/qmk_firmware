#include QMK_KEYBOARD_H
#include <stdio.h>

enum custom_layers {
    BSE,
    NUM,
    NAV,
    MED,
    SYS,
    FUN,
    OTH,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BSE] = LAYOUT_split_3x6_3(
  //   -----------------------------------------------                      -----------------------------------------------
  //  |       |   q   |   w   |   e   |   r   |   t   |                    |   y   |   u   |   i   |   o   |   p   |       |
  //  |-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------|
  //  |       |   a   |   s   |   d   |   f   |   g   |                    |   h   |   j   |   k   |   l   |   '   |       |
  //  |-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------|
  //  |       |   z   |   x   |   c   |   v   |   b   |                    |   n   |   m   |   ,   |   .   |   /   |       |
  //   -------+-------+-------+-------+-------+-------+-------      -------+-------+-------+-------+-------+-------+-------
  //                                  |  esc  |  spc  |  tab  |    |  ent  |  bsp  |  del  |
  //                                   -------+-------+-------      -------+-------+-------
    XXXXXXX, KC_Q,              KC_W,              KC_E,              KC_R,              KC_T,              KC_Y,              KC_U,              KC_I,              KC_O,              KC_P,                 XXXXXXX,
    XXXXXXX, LGUI_T(KC_A),      LALT_T(KC_S),      LCTL_T(KC_D),      LSFT_T(KC_F),      KC_G,              KC_H,              LSFT_T(KC_J),      LCTL_T(KC_K),      LALT_T(KC_L),      LGUI_T(KC_QUOT),      XXXXXXX,
    XXXXXXX, KC_Z,              KC_X,              KC_C,              KC_V,              KC_B,              KC_N,              KC_M,              KC_COMM,           KC_DOT,            KC_SLSH,              XXXXXXX,
                                                   LT(OTH, KC_ESC),   LT(NUM, KC_SPC),   LT(NAV, KC_TAB),   LT(FUN, KC_ENT),   KC_BSPC,           KC_DEL
  ),
  [NUM] = LAYOUT_split_3x6_3(
  //   -----------------------------------------------                      -----------------------------------------------
  //  |       |       |       |   (   |   )   |       |                    |  [ {  |  7 &  |  8 *  |  9 (  |  ] }  |       |
  //  |-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------|
  //  |       |  gui  |  ctl  |  alt  |  sht  |   -   |                    |  = +  |  4 $  |  5 %  |  6 ^  |   ;   |       |
  //  |-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------|
  //  |       |       |       |       |       |   _   |                    |  \ |  |  1 !  |  2 @  |  3 #  |   `   |       |
  //   -------+-------+-------+-------+-------+-------+-------      -------+-------+-------+-------+-------+-------+-------
  //                                  |  esc  |  spc  |  tab  |    |       |  0 )  |       |
  //                                   -------+-------+-------      -------+-------+-------
    XXXXXXX, XXXXXXX,           XXXXXXX,           KC_LPRN,           KC_RPRN,           XXXXXXX,           KC_LBRC,           KC_7,              KC_8,              KC_9,              KC_RBRC,              XXXXXXX,
    XXXXXXX, KC_LGUI,           KC_LALT,           KC_LCTL,           KC_LSFT,           KC_MINS,           KC_EQL,            KC_4,              KC_5,              KC_6,              KC_SCLN,              XXXXXXX,
    XXXXXXX, XXXXXXX,           XXXXXXX,           XXXXXXX,           XXXXXXX,           KC_UNDS,           KC_BSLS,           KC_1,              KC_2,              KC_3,              KC_GRV,               XXXXXXX,
                                                   KC_ESC,            KC_SPC,            KC_TAB,            XXXXXXX,           KC_0,              XXXXXXX
  ),
  [NAV] = LAYOUT_split_3x6_3(
  //   -----------------------------------------------                      -----------------------------------------------
  //  |       |       |       |       |       |       |                    |       |       |       |       |       |       |
  //  |-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------|
  //  |       |  gui  |  ctl  |  alt  |  sht  |       |                    |  cps  |   ←   |   ↓   |   ↑   |   →   |       |
  //  |-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------|
  //  |       |       |       |       |       |       |                    |       |   ⇐   |   ⇓   |  ⇑   |  ⇒   |       |
  //   -------+-------+-------+-------+-------+-------+-------     --------+-------+-------+-------+-------+-------+-------
  //                                  |       |       |       |   |  entr  |  bsp  |  dlt  |
  //                                   -------+-------+-------     --------+-------+-------
    XXXXXXX, XXXXXXX,           XXXXXXX,           XXXXXXX,           XXXXXXX,              XXXXXXX,         XXXXXXX,          XXXXXXX,           XXXXXXX,           XXXXXXX,           XXXXXXX,              XXXXXXX,
    XXXXXXX, KC_LGUI,           KC_LALT,           KC_LCTL,           KC_LSFT,              XXXXXXX,         XXXXXXX,          KC_LEFT,           KC_DOWN,           KC_UP,             KC_RGHT,              XXXXXXX,
    XXXXXXX, XXXXXXX,           XXXXXXX,           XXXXXXX,           XXXXXXX,              XXXXXXX,         XXXXXXX,          KC_HOME,           KC_PGDN,           KC_PGUP,           KC_END,               XXXXXXX,
                                                   KC_ESC,            KC_SPC,               KC_TAB,          KC_ENT,           KC_BSPC,           KC_DEL
  ),
  [MED] = LAYOUT_split_3x6_3(
  //   -----------------------------------------------                      -----------------------------------------------
  //  |       |       |       |       |       |       |                    |       |       |       |       |       |       |
  //  |-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------|
  //  |       |  gui  |  ctl  |  alt  |  sht  |       |                    |       |  prev | vol - | vol + |  next |       |
  //  |-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------|
  //  |       |       |       |       |       |       |                    |       |       |       |       |       |       |
  //   -------+-------+-------+-------+-------+-------+-------     --------+-------+-------+-------+-------+-------+-------
  //                                  |       |       |       |   |        | pause |  mute |
  //                                   -------+-------+-------     --------+-------+-------
    XXXXXXX, XXXXXXX,           XXXXXXX,           XXXXXXX,           XXXXXXX,              XXXXXXX,         XXXXXXX,          XXXXXXX,           XXXXXXX,           XXXXXXX,           XXXXXXX,              XXXXXXX,
    XXXXXXX, KC_LGUI,           KC_LALT,           KC_LCTL,           KC_LSFT,              XXXXXXX,         XXXXXXX,          KC_MPRV,           KC_VOLD,           KC_VOLU,           KC_MNXT,              XXXXXXX,
    XXXXXXX, XXXXXXX,           XXXXXXX,           XXXXXXX,           XXXXXXX,              XXXXXXX,         XXXXXXX,          XXXXXXX,           XXXXXXX,           XXXXXXX,           XXXXXXX,              XXXXXXX,
                                                   KC_ESC,            KC_SPC,               KC_TAB,          XXXXXXX,          KC_MPLY,           KC_MUTE
  ),
  [SYS] = LAYOUT_split_3x6_3(
  //   -----------------------------------------------                      -----------------------------------------------
  //  |       |       |       |       |       |       |                    |       |       |       |       |       | RESET |
  //  |-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------|
  //  |       |       |       |       |       |       |                    |       |       |       |       |       |       |
  //  |-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------|
  //  |       |       |       |       |       |       |                    |       |       |       |       |       |       |
  //   -------+-------+-------+-------+-------+-------+-------     --------+-------+-------+-------+-------+-------+-------
  //                                  |       |       |       |   |        |       |       |
  //                                   -------+-------+-------     --------+-------+-------
    XXXXXXX, XXXXXXX,           XXXXXXX,           XXXXXXX,           XXXXXXX,              XXXXXXX,         XXXXXXX,          XXXXXXX,           XXXXXXX,           XXXXXXX,           RESET,                XXXXXXX,
    XXXXXXX, XXXXXXX,           XXXXXXX,           XXXXXXX,           XXXXXXX,              XXXXXXX,         XXXXXXX,          XXXXXXX,           XXXXXXX,           XXXXXXX,           XXXXXXX,              XXXXXXX,
    XXXXXXX, XXXXXXX,           XXXXXXX,           XXXXXXX,           XXXXXXX,              XXXXXXX,         XXXXXXX,          XXXXXXX,           XXXXXXX,           XXXXXXX,           XXXXXXX,              XXXXXXX,
                                                   XXXXXXX,           XXXXXXX,              XXXXXXX,         XXXXXXX,          XXXXXXX,           XXXXXXX
  ),
  [FUN] = LAYOUT_split_3x6_3(
  //   -----------------------------------------------                      -----------------------------------------------
  //  |       |       |       |       |       |       |                    |       |  F 9  |  F10  |  F11  |  F12  |       |
  //  |-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------|
  //  |       |  gui  |  ctl  |  alt  |  sht  |       |                    |       |  F 5  |  F 6  |  F 7  |  F 8  |       |
  //  |-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------|
  //  |       |       |       |       |       |       |                    |       |  F 1  |  F 2  |  F 3  |  F 4  |       |
  //   -------+-------+-------+-------+-------+-------+-------      -------+-------+-------+-------+-------+-------+-------
  //                                  |  esc  |  spc  |  tab  |    |       |       |       |
  //                                   -------+-------+-------      -------+-------+-------
    XXXXXXX, XXXXXXX,           XXXXXXX,           XXXXXXX,           XXXXXXX,           XXXXXXX,           XXXXXXX,           KC_F9,             KC_F10,            KC_F11,          KC_F12,            XXXXXXX,
    XXXXXXX, KC_LGUI,           KC_LALT,           KC_LCTL,           KC_LSFT,           XXXXXXX,           XXXXXXX,           KC_F5,             KC_6,              KC_7,            KC_F8,             XXXXXXX,
    XXXXXXX, XXXXXXX,           XXXXXXX,           XXXXXXX,           XXXXXXX,           XXXXXXX,           XXXXXXX,           KC_F1,             KC_F2,             KC_F3,           KC_F4,             XXXXXXX,
                                                   KC_ESC,            KC_SPC,            XXXXXXX,           XXXXXXX,           KC_0,              XXXXXXX
  ),
  [OTH] = LAYOUT_split_3x6_3(
  //   -----------------------------------------------                      -----------------------------------------------
  //  |       |       |       |       |       |       |                    |       |       |       |       |       |       |
  //  |-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------|
  //  |       |  cps  |       |       |       |       |                    |       |       |       |       | rctl  |       |
  //  |-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------|
  //  |       |       |       |       |       |       |                    |       |       |       |       |       |       |
  //   -------+-------+-------+-------+-------+-------+-------      -------+-------+-------+-------+-------+-------+-------
  //                                  |  esc  |  spc  |  tab  |    |       |       |       |
  //                                   -------+-------+-------      -------+-------+-------
    XXXXXXX, XXXXXXX,           XXXXXXX,           XXXXXXX,           XXXXXXX,           XXXXXXX,           XXXXXXX,           XXXXXXX,             XXXXXXX,            XXXXXXX,          XXXXXXX,            XXXXXXX,
    XXXXXXX, KC_CAPS,           XXXXXXX,           XXXXXXX,           XXXXXXX,           XXXXXXX,           XXXXXXX,           XXXXXXX,             XXXXXXX,            XXXXXXX,          KC_RCTL,            XXXXXXX,
    XXXXXXX, XXXXXXX,           XXXXXXX,           XXXXXXX,           XXXXXXX,           XXXXXXX,           XXXXXXX,           XXXXXXX,             XXXXXXX,            XXXXXXX,          XXXXXXX,            XXXXXXX,
                                                   XXXXXXX,           XXXXXXX,           XXXXXXX,           XXXXXXX,           XXXXXXX,             XXXXXXX
  )
};

const uint16_t PROGMEM combo_media[] = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM combo_sys[] = {KC_Q, KC_T, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  COMBO(combo_media, MO(MED)),
  COMBO(combo_sys, MO(SYS)),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

  return true;
}
