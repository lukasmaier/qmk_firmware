#include QMK_KEYBOARD_H

enum myKeycodes {
    KC_ASDF = SAFE_RANGE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_ortho_4x4(
        KC_F13,              KC_F14,                KC_F15,                 TO(0),
        KC_F16,              KC_F17,                KC_F18,                 TO(1),
        KC_F19,              KC_AUDIO_VOL_DOWN,     KC_AUDIO_VOL_UP,        TO(2),
        KC_MEDIA_PREV_TRACK, KC_MEDIA_PLAY_PAUSE,   KC_MEDIA_NEXT_TRACK,    TO(3)
    ),
    [1] = LAYOUT_ortho_4x4(
        KC_1, KC_2,   KC_3,   TO(0),
        KC_4, KC_5,   KC_6,   TO(1),
        KC_7, KC_8,   KC_9,   TO(2),
        KC_ENT, KC_0, KC_DOT, TO(3)
    ),
    [2] = LAYOUT_ortho_4x4(
        KC_1,       KC_1,       KC_1,           KC_TRNS,
        KC_1,       KC_MS_UP,   KC_1,           KC_TRNS,
        KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT,    KC_TRNS,
        KC_MS_BTN1, KC_MS_BTN3, KC_MS_BTN2,     KC_TRNS
    ),
    [3] = LAYOUT_ortho_4x4(
        KC_1, KC_1,   KC_1,   KC_TRNS,
        KC_1, KC_1,   KC_1,   KC_TRNS,
        KC_1, KC_1,   KC_1,   KC_TRNS,
        KC_ASDF, KC_1,   KC_1,   KC_TRNS
    )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_ASDF:
            if (record->event.pressed) {
               register_code16(0xE8);
            } else{
               unregister_code16(0xE8);
            }
            return false;
            break;
    }
    return true;
}
