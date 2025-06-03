#include QMK_KEYBOARD_H
#include "version.h"

// Left-hand home row mods
#define HOME_A LCTL_T(KC_A)
#define HOME_S LALT_T(KC_S)
#define HOME_D LGUI_T(KC_D)
#define HOME_F LSFT_T(KC_F)

// Right-hand home row mods
#define HOME_J RSFT_T(KC_J)
#define HOME_K RGUI_T(KC_K)
#define HOME_L LALT_T(KC_L)
#define HOME_SCLN RCTL_T(KC_SCLN)

enum custom_layers {
    BASE,   // default layer
    SYMB,   // symbols
    MDIA,   // media keys
    RESET,  // reset layer
};

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  VRSN,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |   1  |   2  |   3  |   4  |   5  |      |           |      |   6  |   7  |   8  |   9  |   0  |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |QK_GESC |   Q  |   W  |   E  |   R  |   T  | MO(2)|           | MO(2)|   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | Tab    |HOME_A|HOME_S|HOME_D|HOME_F|   G  |------|           |------|   H  |HOME_J|HOME_K|HOME_L|H_SCLN|   '    |
 * |--------+------+------+------+------+------| MO(1)|           | MO(1)|------+------+------+------+------+--------|
 * |    [   |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |   /  |   ]    |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | MO(1)| MO(2)|       | MO(2)| MO(1)|
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |BkSp  |Esc   |------|       |------|Enter |Space |
 *                                 |      |      | MO(3)|       | MO(3)|      |      |
 *                                 `--------------------'       `--------------------'
 */
[BASE] = LAYOUT_ergodox(
    // left hand
      KC_NO,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_NO,
    QK_GESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    MO(2),
     KC_TAB,HOME_A,  HOME_S,  HOME_D,  HOME_F,    KC_G,
    KC_LBRC,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    MO(1),
      KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,
                                         MO(1),    MO(2),
                                                   KC_NO,
                                KC_BSPC,  KC_ESC,  MO(3),
    // right hand
    KC_NO,    KC_6,  KC_7,   KC_8,  KC_9,      KC_0,    KC_NO,
    MO(2),    KC_Y,  KC_U,   KC_I,  KC_O,      KC_P,  KC_BSLS,
              KC_H,HOME_J, HOME_K, HOME_L,HOME_SCLN,  KC_QUOT,
    MO(1),    KC_N,  KC_M,KC_COMM, KC_DOT,  KC_SLSH,  KC_RBRC,
                    KC_NO,  KC_NO,  KC_NO,    KC_NO,    KC_NO,
    MO(2),    MO(1),
    KC_NO,
    MO(3),   KC_ENT,  KC_SPC
),

/* Keymap 1: Symbol Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   !  |   @  |   #  |   $  |   %  |      |           |      |   ^  |   &  |   *  |   (  |   )  |   \     |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   1  |   2  |   3  |   4  |   5  |------|           |------|   -  |   =  |   `  |   [  |   ]  |   |    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   6  |   7  |   8  |   9  |   0  |      |           |      |   _  |   +  |   ~  |   {  |   }  |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[SYMB] = LAYOUT_ergodox(
    // left hand
    KC_NO,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_NO,
    KC_TRNS, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC, KC_TRNS,
    KC_TRNS,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,
    KC_TRNS,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_TRNS,
    KC_NO,     KC_NO,   KC_NO,   KC_NO,   KC_NO,
                                        KC_TRNS,  KC_TRNS,
                                                  KC_TRNS,
                                KC_TRNS,KC_TRNS,  KC_TRNS,
    // right hand
      KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_NO,
    KC_TRNS, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSLS,
             KC_MINS, KC_EQL,   KC_GRV, KC_LBRC, KC_RBRC, KC_PIPE,
    KC_TRNS, KC_UNDS,KC_PLUS,  KC_TILD, KC_LCBR, KC_RCBR, KC_TRNS,
                       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
    KC_TRNS, KC_TRNS,
    KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS
),

/* Keymap 2: Media and Function Keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  | F10  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        | Prev | Next | Vol+ | Vol- | Play |------|           |------| Left | Down |  Up  |Right |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[MDIA] = LAYOUT_ergodox(
    // left hand
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,   KC_NO,
    KC_NO,   KC_F1,   KC_F2,   KC_F3,   KC_F4,    KC_F5,   KC_TRNS,
    KC_NO, KC_MPRV, KC_MNXT, KC_VOLU, KC_VOLD,  KC_MPLY,
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,   KC_TRNS,
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                                        KC_TRNS,KC_TRNS,
                                                KC_TRNS,
                                KC_TRNS,KC_TRNS,KC_TRNS,
    // right hand
      KC_NO,  KC_NO,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
    KC_TRNS,  KC_F6,  KC_F7,   KC_F8,   KC_F9,  KC_F10,   KC_NO,
            KC_LEFT,KC_DOWN,   KC_UP, KC_RGHT,   KC_NO,   KC_NO,
    KC_TRNS,  KC_NO,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
    KC_TRNS,KC_TRNS,
    KC_TRNS,
    KC_TRNS, KC_TRNS,KC_TRNS
),

/* Keymap 3: Reset Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | RESET  |      |      |      |      |      |      |           | RESET|      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |TRNS  |       |TRNS  |      |      |
 *                                 `--------------------'       `--------------------'
 */
[RESET] = LAYOUT_ergodox(
    // left hand
    QK_BOOT, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                                        KC_NO,   KC_NO,
                                                 KC_NO,
                                KC_NO,   KC_NO,KC_TRNS,
    // right hand
    QK_BOOT, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
             KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
    KC_NO,   KC_NO,
    KC_NO,
    KC_TRNS, KC_NO,   KC_NO
)
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case VRSN:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      return false;
      break;
  }
  return true;
}

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {
    uint8_t layer = get_highest_layer(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
        case 1:
            ergodox_right_led_1_on();
            break;
        case 2:
            ergodox_right_led_2_on();
            break;
        case 3:
            ergodox_right_led_3_on();
            break;
        default:
            break;
    }
}