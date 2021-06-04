/* Copyright 2017 Biacco42
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

// make meishi:soul:avrdude
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[0] = LAYOUT( /* Base */
 //  M(0),  M(1),  M(2), MEH(KC_F1)
 MEH(KC_1), MEH(KC_2), MEH(KC_3), MEH(KC_4) \
),
};

const uint16_t PROGMEM fn_actions[] = {

};

void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  return true;
}

void led_set_user(uint8_t usb_led) {

}

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
    switch(id) {
    case 0: // id=0のマクロ定義
        if (record->event.pressed) {
            // 三連お辞儀エモーティコン + 日本語入力のときに英字に変換するF10
            // FIXME: そもそもIMEのの状態によらず英数字で入力できる方法を探す
            SEND_STRING("(bow)" SS_TAP(X_F10));
            // MEH(KC_F2);
        }
        break;
    case 1: // id=0のマクロ定義
        if (record->event.pressed) {
            SEND_STRING("(roger)" SS_TAP(X_F10));
            // MEH(KC_F3);
        }
        break;
    case 2: // id=0のマクロ定義
        if (record->event.pressed) {
            // MEH(KC_F4);
            SEND_STRING("(cracker)" SS_TAP(X_F10));
        }
        break;
    case 3: // id=0のマクロ定義
        if (record->event.pressed) {
            SEND_STRING("Hello");
        }
        break;
    }
    return MACRO_NONE;
}
