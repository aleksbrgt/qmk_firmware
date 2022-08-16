#include QMK_KEYBOARD_H
#include <stdio.h>

enum custom_layers {
    BSE,
    NUM,
    NAV,
    MSE,
    MED,
    SYS,
    FUN
};

enum custom_keycodes {
    OLED_BR_UP = SAFE_RANGE,
    OLED_BR_DN,
    OLED_SC_UP,
    OLED_SC_DN,
    OLED_TOGGLE,
    NOTHING,
    KC_COIN_TOSS,
    KC_GAME_OF_LIFE,
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
    NOTHING, KC_Q,              KC_W,              KC_E,              KC_R,              KC_T,              KC_Y,              KC_U,              KC_I,              KC_O,              KC_P,                 XXXXXXX,
    KC_CAPS, LGUI_T(KC_A),      LALT_T(KC_S),      LCTL_T(KC_D),      LSFT_T(KC_F),      KC_G,              KC_H,              LSFT_T(KC_J),      LCTL_T(KC_K),      LALT_T(KC_L),      LGUI_T(KC_QUOT),      KC_RCTL,
    XXXXXXX, KC_Z,              KC_X,              KC_C,              KC_V,              KC_B,              KC_N,              KC_M,              KC_COMM,           KC_DOT,            KC_SLSH,              XXXXXXX,
                                                   LT(MSE, KC_ESC),   LT(NUM, KC_SPC),   LT(NAV, KC_TAB),   LT(FUN, KC_ENT),   KC_BSPC,           KC_DEL
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
  //  |       |       |       |       |       |       |                    |       |   ⇐   |   ⇓   |   ⇑   |   ⇒   |       |
  //   -------+-------+-------+-------+-------+-------+-------     --------+-------+-------+-------+-------+-------+-------
  //                                  |       |       |       |   |  entr  |  bsp  |  dlt  |
  //                                   -------+-------+-------     --------+-------+-------
    XXXXXXX, XXXXXXX,           XXXXXXX,           XXXXXXX,           XXXXXXX,              XXXXXXX,         XXXXXXX,          XXXXXXX,           XXXXXXX,           XXXXXXX,           XXXXXXX,              XXXXXXX,
    XXXXXXX, KC_LGUI,           KC_LALT,           KC_LCTL,           KC_LSFT,              XXXXXXX,         XXXXXXX,          KC_LEFT,           KC_DOWN,           KC_UP,             KC_RGHT,              XXXXXXX,
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
  //                                   -------+-------+-------     --------+-------+-------
    XXXXXXX, XXXXXXX,           XXXXXXX,           XXXXXXX,           XXXXXXX,              XXXXXXX,         XXXXXXX,          XXXXXXX,           XXXXXXX,           XXXXXXX,           XXXXXXX,              XXXXXXX,
    XXXXXXX, KC_LGUI,           KC_LALT,           KC_LCTL,           KC_LSFT,              XXXXXXX,         XXXXXXX,          KC_MS_L,           KC_MS_D,           KC_MS_U,           KC_MS_R,              XXXXXXX,
    XXXXXXX, XXXXXXX,           XXXXXXX,           XXXXXXX,           XXXXXXX,              XXXXXXX,         XXXXXXX,          KC_WH_L,           KC_WH_D,           KC_WH_U,           KC_WH_R,              XXXXXXX,
                                                   KC_ESC,            KC_SPC,               KC_TAB,          KC_BTN1,          KC_BTN2,           KC_BTN3
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
  //  |       |       |       |       |       |       |                    |       |       | OLD - | OLD + |       |       |
  //  |-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------|
  //  |       |       |       |       |       |       |                    |       |       |       |       |       |       |
  //   -------+-------+-------+-------+-------+-------+-------     --------+-------+-------+-------+-------+-------+-------
  //                                  |       |       |       |   |        |OLD TOG|       |
  //                                   -------+-------+-------     --------+-------+-------
    XXXXXXX, XXXXXXX,           XXXXXXX,           XXXXXXX,           XXXXXXX,              XXXXXXX,         XXXXXXX,          XXXXXXX,           XXXXXXX,           XXXXXXX,           EEP_RST,              RESET,
    XXXXXXX, XXXXXXX,           XXXXXXX,           XXXXXXX,           XXXXXXX,              XXXXXXX,         XXXXXXX,          XXXXXXX,           OLED_BR_DN,        OLED_BR_UP,        XXXXXXX,              XXXXXXX,
    XXXXXXX, XXXXXXX,           XXXXXXX,           XXXXXXX,           XXXXXXX,              XXXXXXX,         XXXXXXX,          XXXXXXX,           XXXXXXX,           XXXXXXX,           XXXXXXX,              XXXXXXX,
                                                   XXXXXXX,           XXXXXXX,              XXXXXXX,         KC_COIN_TOSS,     OLED_TOGGLE,       XXXXXXX
  ),
  [FUN] = LAYOUT_split_3x6_3(
  //   -----------------------------------------------                      -----------------------------------------------
  //  |       |       |       |       |       |       |                    |  F12  |  F13  |  F14  |  F15  |  F16  |       |
  //  |-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------|
  //  |       |  gui  |  ctl  |  alt  |  sht  |       |                    |  F 6  |  F 7  |  F 8  |  F 9  |  F10  |       |
  //  |-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------|
  //  |       |       |       |       |       |       |                    |  F 1  |  F 2  |  F 3  |  F 4  |  F 5  |       |
  //   -------+-------+-------+-------+-------+-------+-------      -------+-------+-------+-------+-------+-------+-------
  //                                  |  esc  |  spc  |  tab  |    |       |       |       |
  //                                   -------+-------+-------      -------+-------+-------
    XXXXXXX, XXXXXXX,           XXXXXXX,           XXXXXXX,           XXXXXXX,           XXXXXXX,           KC_F12,            XXXXXXX,           XXXXXXX,           XXXXXXX,           XXXXXXX,             XXXXXXX,
    XXXXXXX, KC_LGUI,           KC_LALT,           KC_LCTL,           KC_LSFT,           XXXXXXX,           KC_F6,             KC_F7,             KC_8,              KC_9,              KC_F10,              XXXXXXX,
    XXXXXXX, XXXXXXX,           XXXXXXX,           XXXXXXX,           XXXXXXX,           XXXXXXX,           KC_F1,             KC_F2,             KC_F3,             KC_F4,             KC_F5,               XXXXXXX,
                                                   KC_ESC,            KC_SPC,            XXXXXXX,           XXXXXXX,           KC_0,              XXXXXXX
  )
};

const uint16_t PROGMEM combo_media[] = {NOTHING, KC_Q, COMBO_END};
const uint16_t PROGMEM combo_sys[] = {NOTHING, KC_T, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  COMBO(combo_media, MO(MED)),
  COMBO(combo_sys, MO(SYS)),
};

uint32_t type_count = 0;
uint16_t scroll_resume_timer;

bool oled_should_increase_brightness = false;
bool oled_should_decrease_brightness = false;
bool oled_show = true;

bool capslock = false;

char keylog_str[24] = "CxR: 00x00  000:    ";

const char code_to_name[60] = {
  ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
  'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
  'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
  '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
  'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
  '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '
};

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (is_keyboard_master()) {
    return OLED_ROTATION_180;
  }

  oled_scroll_right();

  return rotation;
}

uint16_t toss_timer;
bool toss_trigger = false;
bool toss_show_result = false;
bool toss_heads = false;
bool toss_result = false;
uint8_t toss_frame = 0;
char toss_throw_chars[4] = {'|', '/', '-', '\\'};

void toss_handle(void) {
  if (!toss_trigger) {
    return;
  }

  if (timer_elapsed(toss_timer) < 2000) {
    char str[3];
    sprintf(str, "  %c  ", toss_throw_chars[toss_frame]);
    oled_write(str, false);

    toss_frame++;
    if (toss_frame == 4) {
      toss_frame = 0;
    }

    return;
  }

  if (timer_elapsed(toss_timer) < 3000) {
    oled_write("  =  ", false);

    return;
  }

  if (!toss_show_result) {
    toss_result = rand() % 2;
    toss_show_result = true;
  }

  if (timer_elapsed(toss_timer) < 7000) {
    oled_write(toss_result ? "heads" : "tails", false);

    return;
  }

  toss_trigger = false;
  toss_show_result = false;
}

void oled_render_line_1(void) {
  oled_write_P(PSTR("Lay: "), false);
  switch (layer_state) {
    case 0:
      oled_write_P(PSTR(" bse "), false);
      break;
    case 2:
      oled_write_P(PSTR(" num "), false);
    break;
    case 4:
      oled_write_P(PSTR(" nav "), false);
      break;
    case 8:
      oled_write_P(PSTR(" mse "), false);
      break;
    case 16:
      oled_write_P(PSTR(" med "), false);
      break;
    case 32:
      oled_write_P(PSTR(" sys "), false);
      break;
    case 64:
      oled_write_P(PSTR(" fun "), false);
      break;
  }

  oled_write("  H/T:", false);

  toss_handle();

  if (!toss_trigger) {
    oled_write(" --- ", false);

    return;
  }
}

void oled_render_line_2(void) {
  oled_write_ln(keylog_str, false);
}

void oled_render_line_3(void) {
  char str[128];

  sprintf(str, "Tap: %05ld  Cps: %s ", type_count, capslock ? "yes" : "no ");
  oled_write(str, false);
}

void oled_render_line_4(void) {
  char str[128];

  sprintf(str, "Old:  %03d   WPM: %03d ", oled_get_brightness(), get_current_wpm());
  oled_write(str, false);
}

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

  if (keycode > 99 && keycode != 0) {
    keycode = 999;
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
    "CxR: %02dx%02d  %03d:  %c ",
    row,
    col,
    keycode,
    name
  );
}

void oled_snow(uint8_t quantity) {
  for (size_t i = 0; i < quantity; i++)
  {
    oled_write_pixel(rand() % 129, rand() % 33, (rand() % 2) == 1);
  }
}

void oled_task_user(void) {
  if (!is_keyboard_master()) {
    oled_snow(50);

    return;
  }

  if (!oled_show) {
    oled_clear();
    oled_off();

    return;
  }

  if (timer_elapsed(scroll_resume_timer) > 10000) {
    oled_snow(50);

    return;
  }

  oled_render_line_1();
  oled_render_line_2();
  oled_render_line_3();
  oled_render_line_4();

  if (oled_should_increase_brightness && 255 != oled_get_brightness()) {
    oled_set_brightness(oled_get_brightness() + 5);
  }

  if (oled_should_decrease_brightness && 0 != oled_get_brightness()) {
    oled_set_brightness(oled_get_brightness() - 5);
  }
}

void oled_update_settings(uint16_t keycode) {
  switch (keycode)
  {
    case OLED_TOGGLE:
      oled_show = !oled_show;

      break;
    case OLED_BR_UP:
      oled_should_increase_brightness = true;

      break;
    case OLED_BR_DN:
      oled_should_decrease_brightness = true;

      break;
  }
}

void update_status(uint16_t keycode) {
  switch (keycode)
  {
    case KC_CAPS:
      capslock = !capslock;

      break;
  }
}

void handle_toss(uint16_t keycode) {
  if (KC_COIN_TOSS == keycode && !toss_trigger) {
    toss_trigger = true;
    toss_show_result = false;
    toss_timer = timer_read();

    return;
  }
}

bool run_game_of_life = false;
bool current_grid [128][32];
bool next_grid [128][32];
uint16_t generation = 0;

void draw_grid(void) {
  char frame[512];
  uint8_t bit_count = 0;
  uint16_t byte_count = 0;

  for (size_t x = 0; x < 128; x++)
  {
    for (size_t y = 0; y < 32; y++)
    {
      if (bit_count == 8) {
        byte_count++;
        bit_count = 0;
      }

      frame[byte_count] |= (next_grid[x][y]) << bit_count;

      bit_count++;
    }
  }

  oled_write_raw_P(PSTR(frame), 512);
}

void seed_grid(void)
{
  for (size_t x = 0; x < 128; x++)
  {
    for (size_t y = 0; y < 32; y++)
    {
      next_grid[x][y] = 1 == rand() % 10;
    }
  }
}

void step(void)
{
  strncpy(next_grid, current_grid, 128);
}

void game_of_life(void)
{
  if (generation == 0) {
    seed_grid();
    draw_grid();

    return;
  }

  step();
  draw_grid();
}

void handle_game_of_life(uint16_t keycode) {
  if (KC_GAME_OF_LIFE == keycode) {
    run_game_of_life = !run_game_of_life;

    return;
  }

  if (run_game_of_life) {
    game_of_life();
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  scroll_resume_timer = timer_read();

  if (record->event.pressed) {
    type_count++;
    set_keylog(keycode, record);
    oled_update_settings(keycode);
    update_status(keycode);
    handle_toss(keycode);

    return true;
  }

  oled_should_increase_brightness = false;
  oled_should_decrease_brightness = false;

  set_keylog(0, record);

  return true;
}
