#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _COLEMAK 1
#define _GAME 2
#define _LOWER 3
#define _RAISE 4
#define _FN 15
#define _ADJUST 16

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  GAME,
  LOWER,
  RAISE,
  FUNCTION,
  ADJUST,
};

// Defines for task manager and such
#define CALTDEL LCTL(LALT(KC_DEL))
#define TSKMGR LCTL(LSFT(KC_ESC))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------. ,-----------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  | |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  | |   H  |   J  |   K  |   L  |   ;  | Enter|
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  | |   N  |   M  |   ,  |   .  |   /  |  '   |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * | Ctrl | Func | GUI  | Alt  |Lower |Space | |Space |Raise | Left | Down |  Up  | Right|
 * `-----------------------------------------' '-----------------------------------------'
 */
[_QWERTY] = LAYOUT( \
  KC_TAB,   KC_Q,     KC_W,    KC_E,    KC_R,  KC_T,   KC_Y,   KC_U,  KC_I,    KC_O,    KC_P,    KC_BSPC, \
  KC_ESC,   KC_A,     KC_S,    KC_D,    KC_F,  KC_G,   KC_H,   KC_J,  KC_K,    KC_L,    KC_SCLN, KC_ENT,  \
  KC_LSFT,  KC_Z,     KC_X,    KC_C,    KC_V,  KC_B,   KC_N,   KC_M,  KC_COMM, KC_DOT,  KC_SLSH, KC_QUOT, \
  KC_LCTL,  MO(_FN),  KC_LGUI, KC_LALT, LOWER, KC_SPC, KC_SPC, RAISE, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT  \
),

/* Colemak
 * ,-----------------------------------------. ,-----------------------------------------.
 * | Tab  |   Q  |   W  |   F  |   P  |   G  | |   J  |   L  |   U  |   Y  |   ;  | Bksp |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * | Esc  |   A  |   R  |   S  |   T  |   D  | |   H  |   N  |   E  |   I  |   O  | Enter|
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  | |   K  |   M  |   ,  |   .  |   /  |  "   |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * | Ctrl | Func | Alt  | GUI  |Lower |Space | |Space |Raise | Left | Down |  Up  | Right|
 * `-----------------------------------------' `-----------------------------------------'
 */
[_COLEMAK] = LAYOUT( \
  KC_TAB,  KC_Q,      KC_W,    KC_F,    KC_P,    KC_G,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSPC, \
  KC_ESC,  KC_A,      KC_R,    KC_S,    KC_T,    KC_D,    KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_ENT,  \
  KC_LSFT, KC_Z,      KC_X,    KC_C,    KC_V,    KC_B,    KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_QUOT, \
  KC_LCTL, MO(_FN),   KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT  \
),

/* Game
 * ,-----------------------------------------. ,-----------------------------------------.
 * | Esc  |   Q  |   W  |   E  |   R  |   T  | |      |      |  Up  |      |      |      |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * | Caps |   A  |   S  |   D  |      |      | |      | Left | Down | Right|      | Enter|
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |      |      | |      |      |      |      |      |      |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * | Ctrl | Alt  | Tab  | Enter|      |Space | |Space |      |      |      |      |      |
 * `-----------------------------------------' '-----------------------------------------'
 */
[_GAME] = LAYOUT( \
  KC_ESC,  KC_Q,    KC_W,   KC_E,     KC_R,    KC_T,    _______, _______, KC_UP,   _______, _______, _______, \
  KC_CAPS, KC_A,    KC_S,   KC_D,     _______, _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, KC_ENTER, \
  KC_LSFT, KC_Z,    KC_X,   KC_C,     _______, _______, _______, _______, _______, _______, _______, _______, \
  KC_LCTL, KC_LALT, KC_TAB, KC_ENTER, _______, KC_SPC,  KC_SPC, _______, _______, _______, _______, _______  \
),

/* Lower
 * ,-----------------------------------------. ,-----------------------------------------.
 * | Esc  |   !  |   @  |   #  |   $  |   %  | |   ^  |   &  |   *  |   (  |   )  | Del  |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  | |      |   _  |   +  |   {  |   }  |Enter |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 | |      |      |   `  |   ,  |   .  |  |   |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * | Ctrl | Shift| Alt  |      |      | Bksp | | Bksp |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------' `-----------------------------------------'
 */
[_LOWER] = LAYOUT( \
  KC_ESC,  KC_EXLM,  KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL,  \
  KC_F1,   KC_F2,    KC_F3,   KC_F4,   KC_F5,   KC_F6,   _______, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, _______, \
  KC_F7,   KC_F8,    KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______, KC_GRV,  KC_COMM, KC_DOT,  KC_PIPE, \
  KC_LCTL, KC_LSFT,  KC_LALT, _______, _______, KC_BSPC, KC_BSPC, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY  \
),

/* Raise
 * ,-----------------------------------------. ,-----------------------------------------.
 * | Esc  |   1  |   2  |   3  |   4  |   5  | |   6  |   7  |   8  |   9  |   0  | Del  |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |   4  |   5  |   6  |   +  |  F5  | |  F6  |   -  |   =  |   [  |   ]  |Enter |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |Enter |   7  |   8  |   9  |   -  |  F11 | |  F12 |ISO # |ISO / | Vol- | Vol+ |   \  |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |   ,  |   0  |  .   |Lower | Bksp | | Bksp |Raise | Prev | Next | Mute | Play |
 * `-----------------------------------------' `-----------------------------------------'
 */
[_RAISE] = LAYOUT( \
  KC_ESC,  KC_1,    KC_2,  KC_3,   KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,  \
  _______, KC_4,    KC_5,  KC_6,   KC_PLUS, KC_F5,   KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, _______, \
  KC_ENT,  KC_7,    KC_8,  KC_9,   KC_MINS, KC_F11,  KC_F12,  KC_NUHS, KC_NUBS, KC_VOLD, KC_VOLU, KC_BSLS, \
  _______, KC_COMM, KC_0,  KC_DOT, _______, KC_BSPC, KC_BSPC, _______, KC_MPRV, KC_MNXT, KC_VOLD, KC_MPLY  \
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------. ,-----------------------------------------.
 * |Taskmg|      |      |Qwerty|      |      | |      |      |RGBVAI|RGBSAI|RGBHUI|caltde|
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |      |      |Colemk|      |      | |      |      |RGBVAD|RGBSAD|RGBHUD|RGBTOG|
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |      |      |      |      |      | |      |      |      |      |      |BLSTEP|
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |      |      |      |      |      | |      |      |      |      |      | RESET|
 * `-----------------------------------------' `-----------------------------------------'
 */
[_ADJUST] = LAYOUT( \
  TSKMGR,  _______, _______, COLEMAK, _______, _______, _______, _______, RGB_VAI, RGB_SAI, RGB_HUI, CALTDEL, \
  _______, _______, _______, QWERTY,  _______, _______, _______, _______, RGB_VAD, RGB_SAD, RGB_HUD, RGB_TOG, \
  _______, _______, _______, GAME,    _______, _______, _______, _______, _______, _______, _______, BL_STEP, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RESET    \
),


/* Function
 * ,-----------------------------------------. ,-----------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  | |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |      |      |      |      |      | |      |      |      |      |      |      |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * | Caps |      |      |      |      |      | |      |      |PrScrn|Scrn- |Scrn+ |Insert|
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |      |      |      |      |      | |      |      | Home |PgDown| PgUp | End  |
 * `-----------------------------------------' `-----------------------------------------'
 */
[_FN] = LAYOUT( \
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,      KC_F10,    KC_F11,  KC_F12, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______,    _______,   _______, _______, \
  KC_CAPS, _______, _______, _______, _______, _______, _______, _______, KC_PSCREEN, KC_BRID,   KC_BRIU, KC_INSERT, \
  _______, _______, _______, _______, _______, _______, _______, _______, KC_HOME,    KC_PGDOWN, KC_PGUP, KC_END   \
)

};

//void persistent_default_layer_set(uint16_t default_layer) {
//  eeconfig_update_default_layer(default_layer);
//  default_layer_set(default_layer);
//}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
//        persistent_default_layer_set(1UL<<_QWERTY);
      }
      return false;
      break;
    case COLEMAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_COLEMAK);
//        persistent_default_layer_set(1UL<<_COLEMAK);
      }
      return false;
      break;
    case GAME:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_GAME);
//        persistent_default_layer_set(1UL<<_COLEMAK);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
  }

  return true;
}
