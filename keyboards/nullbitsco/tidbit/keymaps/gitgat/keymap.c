/* Copyright 2020 Jay Greco
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H

#include "bitc_led.h"

#define _BASE     0
#define _VIA1     1
#define _VIA2     2
#define _VIA3     3

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT(
        JS_BUTTON0,   JS_BUTTON0, JS_BUTTON0, \
  JS_BUTTON0, JS_BUTTON0,     JS_BUTTON0, JS_BUTTON0, \
  JS_BUTTON0, JS_BUTTON0,     JS_BUTTON0, JS_BUTTON0, \
  JS_BUTTON0, JS_BUTTON0,     JS_BUTTON0, JS_BUTTON0, \
  JS_BUTTON0, JS_BUTTON0, JS_BUTTON0, JS_BUTTON0  \
  ),

  [_VIA1] = LAYOUT(
           KC_TRNS, KC_TRNS, KC_TRNS, \
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS  \
  ),

  [_VIA2] = LAYOUT(
           KC_TRNS, KC_TRNS, KC_TRNS, \
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS  \
  ),

  [_VIA3] = LAYOUT(
           KC_TRNS, KC_TRNS, KC_TRNS, \
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS  \
  ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  process_record_remote_kb(keycode, record);
  return true;
}

void matrix_init_user(void) {
  matrix_init_remote_kb();
  set_bitc_LED(LED_OFF);
}

void matrix_scan_user(void) {
  matrix_scan_remote_kb();
}

bool encoder_update_user(uint8_t index, bool clockwise) {

  /* With an if statement we can check which encoder was turned. */
  if (index == 0) { /* First encoder */
    if (clockwise) {
      tap_code16(JS_BUTTON0);
    } else {
      tap_code16(JS_BUTTON0);
    }
  } else if (index == 1) { /* Second encoder */
    if (clockwise) {
      tap_code16(JS_BUTTON0);
    } else {
      tap_code16(JS_BUTTON0);
    }
  } else if (index == 2) { /* Thrid encoder */
    if (clockwise) {
      tap_code16(JS_BUTTON0);
    } else {
      tap_code16(JS_BUTTON0);
    }
  } else if (index == 3) { /* Forth encoder */
    if (clockwise) {
      tap_code16(JS_BUTTON0);
    } else {
      tap_code16(JS_BUTTON0);
    }
  }
  return true;
}

void led_set_kb(uint8_t usb_led) {
  if (usb_led & (1<<USB_LED_NUM_LOCK))
    set_bitc_LED(LED_DIM);
  else
    set_bitc_LED(LED_OFF);
}
