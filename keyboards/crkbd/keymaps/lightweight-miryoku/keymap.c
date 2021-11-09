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

enum custom_layers {
    BSE,
    NUM,
    SYM,
    NAV,
    MSE,
    MED,
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
    XXXXXXX, LGUI_T(KC_A),      LALT_T(KC_S),      LCTL_T(KC_D),      LSFT_T(KC_F),      KC_G,              KC_H,              LSFT_T(KC_J),      LCTL_T(KC_K),      LALT_T(KC_L),      LGUI_T(KC_QUOT),      KC_RCTL,
    XXXXXXX, KC_Z,              KC_X,              KC_C,              KC_V,              KC_B,              KC_N,              KC_M,              KC_COMM,           KC_DOT,            KC_SLSH,              XXXXXXX,
                                                   LT(MED, KC_ESC),   LT(NAV, KC_SPC),   LT(MSE, KC_TAB),   LT(SYM, KC_ENT),   LT(NUM, KC_BSPC),  KC_DEL
  ),
  [NUM] = LAYOUT_split_3x6_3(
  //   -----------------------------------------------                      ----------------------------------------------- 
  //  |       |   [   |   7   |   8   |   9   |   ]   |                    |       |       |       |       |       |       |
  //  |-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------|
  //  |       |   ;   |   4   |   5   |   6   |   =   |                    |       |  sht  |  ctl  |  alt  |  gui  |       |
  //  |-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------|
  //  |       |   `   |   1   |   2   |   3   |   \   |                    |       |       |       |       |       |       |
  //   -------+-------+-------+-------+-------+-------+-------     --------+-------+-------+-------+-------+-------+------- 
  //                                  |   .   |   0   |   -   |   |  entr  |  bsp  |  dlt  |
  //                                   -------+-------+-------     --------+-------+-------/
    XXXXXXX, KC_RBRC,           KC_7,              KC_8,              KC_9,              KC_LBRC,           XXXXXXX,           XXXXXXX,           XXXXXXX,           XXXXXXX,           XXXXXXX,              XXXXXXX,
    XXXXXXX, KC_SCLN,           KC_4,              KC_5,              KC_6,              KC_EQL,            XXXXXXX,           KC_LSFT,           KC_LCTL,           KC_LALT,           KC_LGUI,              XXXXXXX,
    XXXXXXX, KC_GRV,            KC_1,              KC_2,              KC_3,              KC_BSLS,           XXXXXXX,           XXXXXXX,           XXXXXXX,           XXXXXXX,           XXXXXXX,              XXXXXXX,
                                                   KC_DOT,            KC_0,              KC_MINS,           KC_ENT,            KC_BSPC,           KC_DEL
  ),
  [SYM] = LAYOUT_split_3x6_3(
  //   -----------------------------------------------                      ----------------------------------------------- 
  //  |       |   {   |   &   |   *   |   (   |   }   |                    |       |       |       |       |       |       |
  //  |-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------|
  //  |       |   :   |   $   |   %   |   &   |   +   |                    |       |  sht  |  ctl  |  alt  |  gui  |       |
  //  |-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------|
  //  |       |   ~   |   !   |   @   |   #   |   |   |                    |       |       |       |       |       |       |
  //   -------+-------+-------+-------+-------+-------+-------     --------+-------+-------+-------+-------+-------+------- 
  //                                  |   (   |   )   |   _   |   |  entr  |  bsp  |  dlt  |
  //                                   -------+-------+-------     --------+-------+-------/
    XXXXXXX, KC_LCBR,           KC_AMPR,           KC_ASTR,           KC_LPRN,              KC_RCBR,        XXXXXXX,           XXXXXXX,           XXXXXXX,           XXXXXXX,           XXXXXXX,              XXXXXXX,
    XXXXXXX, KC_SCLN,           KC_DLR,            KC_PERC,           KC_CIRC,              KC_PLUS,        XXXXXXX,           KC_LSFT,           KC_LCTL,           KC_LALT,           KC_LGUI,              XXXXXXX,
    XXXXXXX, KC_TILD,           KC_EXLM,           KC_AT,             KC_HASH,              KC_PIPE,        XXXXXXX,           XXXXXXX,           XXXXXXX,           XXXXXXX,           XXXXXXX,              XXXXXXX,
                                                   KC_LPRN,           KC_RPRN,              KC_UNDS,        KC_ENT,            KC_BSPC,           KC_DEL
  ),
  [NAV] = LAYOUT_split_3x6_3(
  //   -----------------------------------------------                      ----------------------------------------------- 
  //  |       |       |       |       |       |       |                    |       |       |       |       |       |       |
  //  |-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------|
  //  |       |  gui  |  ctl  |  alt  |  sht  |       |                    |  cps  |   ←   |   ↓   |   ↑   |   →   |       |
  //  |-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------|
  //  |       |       |       |       |       |       |                    |       |   ⇐   |   ⇓   |   ⇑   |   ⇒   |       |
  //   -------+-------+-------+-------+-------+-------+-------     --------+-------+-------+-------+-------+-------+------- 
  //                                  |       |       |       |   |  entr  |  bsp  |  dlt  |
  //                                   -------+-------+-------     --------+-------+-------/
    XXXXXXX, XXXXXXX,           XXXXXXX,           XXXXXXX,           XXXXXXX,              XXXXXXX,         XXXXXXX,          XXXXXXX,           XXXXXXX,           XXXXXXX,           XXXXXXX,              XXXXXXX,
    XXXXXXX, KC_LGUI,           KC_LALT,           KC_LCTL,           KC_LSFT,              XXXXXXX,         KC_CAPS,          KC_LEFT,           KC_DOWN,           KC_UP,             KC_RGHT,              XXXXXXX,             
    XXXXXXX, XXXXXXX,           XXXXXXX,           XXXXXXX,           XXXXXXX,              XXXXXXX,         XXXXXXX,          KC_HOME,           KC_PGDN,           KC_PGUP,           KC_END,               XXXXXXX,
                                                   KC_ESC,            KC_SPC,               KC_TAB,          KC_ENT,           KC_BSPC,           KC_DEL
  ),
  [MSE] = LAYOUT_split_3x6_3(
  //   -----------------------------------------------                      ----------------------------------------------- 
  //  |       |       |       |       |       |       |                    |       |       |       |       |       |       |
  //  |-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------|
  //  |       |  gui  |  ctl  |  alt  |  sht  |       |                    |       |   ↞   |   ↡   |   ↟   |   ↠   |       |
  //  |-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------|
  //  |       |       |       |       |       |       |                    |       |   ⇇   |   ⇊   |   ⇈   |   ⇉   |       |
  //   -------+-------+-------+-------+-------+-------+-------     --------+-------+-------+-------+-------+-------+------- 
  //                                  |       |       |       |   |  entr  |  bsp  |  dlt  |
  //                                   -------+-------+-------     --------+-------+-------/
    XXXXXXX, XXXXXXX,           XXXXXXX,           XXXXXXX,           XXXXXXX,              XXXXXXX,         XXXXXXX,          XXXXXXX,           XXXXXXX,           XXXXXXX,           XXXXXXX,              XXXXXXX,
    XXXXXXX, KC_LGUI,           KC_LALT,           KC_LCTL,           KC_LSFT,              XXXXXXX,         XXXXXXX,          KC_MS_L,           KC_MS_D,           KC_MS_U,           KC_MS_R,              XXXXXXX,             
    XXXXXXX, XXXXXXX,           XXXXXXX,           XXXXXXX,           XXXXXXX,              XXXXXXX,         XXXXXXX,          KC_WH_L,           KC_WH_D,           KC_WH_U,           KC_WH_R,              XXXXXXX,
                                                   KC_ESC,            KC_SPC,               KC_TAB,          KC_BTN1,          KC_BTN2,           KC_BTN3   
  ),
  [MED] = LAYOUT_split_3x6_3(
  //   -----------------------------------------------                      ----------------------------------------------- 
  //  |       |       |       |       |       |       |                    |       |       |       |       |       |       |
  //  |-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------|
  //  |       |  gui  |  ctl  |  alt  |  sht  |       |                    |       |   ↞   |   ↡   |   ↟   |   ↠   |       |
  //  |-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------|
  //  |       |       |       |       |       |       |                    |       |   ⇇   |   ⇊   |   ⇈   |   ⇉   |       |
  //   -------+-------+-------+-------+-------+-------+-------     --------+-------+-------+-------+-------+-------+------- 
  //                                  |       |       |       |   |  entr  |  bsp  |  dlt  |
  //                                   -------+-------+-------     --------+-------+-------/
    XXXXXXX, XXXXXXX,           XXXXXXX,           XXXXXXX,           XXXXXXX,              XXXXXXX,         XXXXXXX,          XXXXXXX,           XXXXXXX,           XXXXXXX,           XXXXXXX,              XXXXXXX,
    XXXXXXX, KC_LGUI,           KC_LALT,           KC_LCTL,           KC_LSFT,              XXXXXXX,         XXXXXXX,          KC_MPRV,           KC_VOLD,           KC_VOLU,           KC_MNXT,              XXXXXXX,             
    XXXXXXX, XXXXXXX,           XXXXXXX,           XXXXXXX,           XXXXXXX,              XXXXXXX,         XXXXXXX,          XXXXXXX,           XXXXXXX,           XXXXXXX,           XXXXXXX,              XXXXXXX,
                                                   KC_ESC,            KC_SPC,               KC_TAB,          XXXXXXX,          KC_MPLY,           KC_MUTE   
  ),
};

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (is_keyboard_master()) {
    return OLED_ROTATION_180;
  }

  return rotation;
}

void oled_render_layer_state(void) {
  oled_write_P(PSTR("| layer : "), false);
  switch (layer_state) {
    case 0:
      oled_write_ln_P(PSTR("Base  |"), false);
      break;
    case 2:
      oled_write_ln_P(PSTR("Num   |"), false);
      break;
    case 4:
      oled_write_ln_P(PSTR("Symbol|"), false);
      break;
    case 8:
      oled_write_ln_P(PSTR("Nav   |"), false);
      break;
    case 16:
      oled_write_ln_P(PSTR("Mouse |"), false);
      break;
    case 32:
      oled_write_ln_P(PSTR("Media |"), false);
      break;
  }
}

int type_count = 0;
static uint16_t scroll_resume_timer;

char keylog_str[24] = "|       :       |";

const char code_to_name[60] = {
  ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
  'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
  'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
  '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
  'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
  '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '
};

void set_keylog(uint16_t keycode, keyrecord_t *record) {
  char name = ' ';
  if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX)
    || (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)
  ) {
      keycode = keycode & 0xFF;
  }

  if (keycode < 60) {
    name = code_to_name[keycode];
  }

  if (keycode > 99) {
    keycode = 99;
    name = '?';
  }

  int16_t row = record->event.key.row;
  int16_t col = record->event.key.col;

  if (9 < row) {
    row = 0;
  }

  if (9 < col) {
    col = 0;
  }

  snprintf(
    keylog_str,
    sizeof(keylog_str),
    "| %dx%d   : k %3d |  %c",
    row, 
    col,
    keycode, 
    name
  );
}

void oled_render_keylog(void) {
  oled_write_ln(keylog_str, false);
}

void oled_render_count(void) {
  char str[128];

  sprintf(str, "| count : %5d |\n|_______________|", type_count);
  oled_write_ln(str, false);
}

void oled_render_logo(void) {
      static const char PROGMEM crkbd_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
        0};
    oled_write_P(crkbd_logo, false);
}

void oled_resume_scroll(void) {
  if (timer_elapsed(scroll_resume_timer) < 10000) {
    return;
  }

 if (is_keyboard_master()) {

  oled_scroll_left();

  return;
 }

  oled_scroll_right();
}

void oled_task_user(void) {
  oled_set_brightness(0);

    oled_render_layer_state();
    oled_render_keylog();
    oled_render_count();
    oled_resume_scroll();
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  scroll_resume_timer = timer_read();

  if (record->event.pressed) {
    oled_scroll_off();
    set_keylog(keycode, record);
  }

  type_count++;

  return true;
}