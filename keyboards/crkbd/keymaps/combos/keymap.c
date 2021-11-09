/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H
#include <stdio.h>

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_split_3x6_3(
  //  /------------------------------------------                     /------------------------------------------ 
  //  |      |   Q  |   W  |   E  |   R  |   T   |                    |   Y  |   U  |   I  |   O  |   P   |  ~`  |
  //  |------+------+------+------+------+-------+                    +------+------+------+------+-------+------|
  //  |      |A SHFT|   S  |   D  |   F  |   G   |                    |   H  |   J  |   K  |   L  |SHFT ;:|  '"  |
  //  |------+------+------+------+------+-------+                    +------+------+------+------+-------+------|
  //  |      |Z CTRL|   X  |   C  |   V  |   B   |                    |   N  |   M  |  ,<  |  .>  |CTRL /?|      |
  //  \------+------+------+------+------+-------+-------\   /--------+------+------+------+------+-------+------/
  //                              | Ctrl |  OS   |M1 Alt |   |   M2   | Spc  |      |
  //                              \------+-------+-------/   \--------+------+------/

    XXXXXXX, KC_BSPACE,               KC_W, KC_E, KC_R,    KC_T,                               KC_Y, KC_U,    KC_I,    KC_O,   KC_P,                  XXXXXXX,
    XXXXXXX, MT(MOD_LCTL, KC_A), KC_S, KC_D, KC_F,    KC_G,                               KC_H, KC_J,    KC_K,    KC_L,   MT(MOD_LCTL, KC_SCLN), XXXXXXX,
    XXXXXXX, MT(MOD_RSFT, KC_Z), KC_X, KC_C, KC_V,    KC_B,                               KC_N, KC_M,    KC_COMM, KC_DOT, MT(MOD_RSFT, KC_SLSH), XXXXXXX,
                                      XXXXXXX, KC_LGUI, LT(1, KC_LALT),     MO(2), LT(3, KC_SPC), XXXXXXX
  ),
  [1] = LAYOUT_split_3x6_3(
  //  /-----------------------------------                 ------------------------------------ 
  //  |     |     |     |     |     |PG UP|               |     |     |     |     |     |     |
  //  |-----+-----+-----+-----+-----+-----+               +-----+-----+-----+-----+-----+-----|
  //  |     |     |     |     |     |     |               | HME |  ←  |  ↓  |  ↑  |  →  | END |
  //  |-----+-----+-----+-----+-----+-----+               +-----+-----+-----+-----+-----+-----|
  //  |     |     |     |     |     |PG DN|               |     |     |     |     |     |     |
  //  \-----+-----+-----+-----+-----+-----+-----\   /-----+-----+-----+-----+-----+-----+-----/
  //                          |     |     |     |   |     |     |     |
  //                          \-----+-----+-----/   \-----+-----+-----/
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, KC_P1,   KC_P8,   XXXXXXX,  XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   KC_HOME, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, KC_END,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,
                                        _______, _______, _______, _______, _______, _______
  ),
  [2] = LAYOUT_split_3x6_3(
    //  /------------------------------------               /----------------------------------- 
    //  |     |     |     |     |     |     |               |     |  7  |  8  |  9  |     |     |
    //  |-----+-----+-----+-----+-----+-----+               +-----+-----+-----+-----+-----+-----|
    //  |     | PRV | VL- | VL+ | NXT |PAUSE|               |     |  4  |  5  |  6  |     |     |
    //  |-----+-----+-----+-----+-----+-----+               +-----+-----+-----+-----+-----+-----|
    //  |     |     |     |     |     |     |               |     |  1  |  2  |  3  |     |     |
    //  \-----+-----+-----+-----+-----+-----+-----\   /-----+-----+-----+-----+-----+-----+-----/
    //                          |     |     |     |   |     |     |  0  |
    //                          \-----+-----+-----/   \-----+-----+-----/
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, KC_P7, KC_P8, KC_P9, XXXXXXX, XXXXXXX,
    XXXXXXX, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, KC_MPLY,                      XXXXXXX, KC_P4, KC_P5, KC_P6, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, KC_P1, KC_P2, KC_P3, XXXXXXX, XXXXXXX,
                                        _______, _______, _______,    _______, _______, KC_P0
  ),
  [3] = LAYOUT_split_3x6_3(
    //  /------------------------------------               /----------------------------------- 
    //  |     |     |  !  |  @  |  #  |  %  |               |  ^  |  &  |  *  |  '  |  "  |     |
    //  |-----+-----+-----+-----+-----+-----+               +-----+-----+-----+-----+-----+-----|
    //  |     |  ~  |  `  |  {  |  [  |  (  |               |  )  |  ]  |  }  |  $  |  ;  |     |
    //  |-----+-----+-----+-----+-----+-----+               +-----+-----+-----+-----+-----+-----|
    //  |     |     |  \  |  -  |  =  |  <  |               |  >  |  +  |  _  |  /  |  |  |     |
    //  \-----+-----+-----+-----+-----+-----+-----\   /-----+-----+-----+-----+-----+-----+-----/
    //                          |     |     |     |   |     |     |     |
    //                          \-----+-----+-----/   \-----+-----+-----/
    XXXXXXX, XXXXXXX, KC_EXLM, KC_AT,   KC_HASH, KC_PERC,                   KC_CIRC, KC_AMPR, KC_ASTR, KC_QUOT, KC_DQT, XXXXXXX,
    XXXXXXX, KC_TILD, XXXXXXX, KC_LCBR, KC_LBRC, KC_LPRN,                   KC_RPRN, KC_RBRC, KC_RCBR, KC_DLR,  KC_SCLN,  XXXXXXX,
    XXXXXXX, XXXXXXX, KC_BSLS, KC_PMNS, KC_PEQL, XXXXXXX,                   KC_UNDS, KC_PLUS, KC_UNDS, KC_SLSH, KC_PIPE, XXXXXXX,
                                        _______, _______, _______, _______, _______, _______
  )
};

const uint16_t PROGMEM combo_esc[] = {KC_W, KC_E, COMBO_END};
const uint16_t PROGMEM combo_tab[] = {KC_S, KC_D, COMBO_END};
const uint16_t PROGMEM combo_bspc1[] = {KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM combo_bspc2[] = {KC_ASTR, KC_QUOT, COMBO_END};
const uint16_t PROGMEM combo_ent[] = {KC_K, KC_L, COMBO_END};
const uint16_t PROGMEM combo_del[] = {KC_P1, KC_P8, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  COMBO(combo_esc, KC_ESC),
  COMBO(combo_tab, KC_TAB),
  COMBO(combo_bspc1, KC_BSPC),
  COMBO(combo_bspc2, KC_BSPC),
  COMBO(combo_ent, KC_ENT),
  COMBO(combo_del, KC_DEL),
};
