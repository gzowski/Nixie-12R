// Copyright 2023 James Gzowski
// SPDX-License-Identifier: GPL-2.0-or-later
#include QMK_KEYBOARD_H

enum custom_layer {
    _LAYERQ,
    _LAYERN,
    _LAYERF
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_LAYERQ] = LAYOUT_2x6(
        KC_Q , KC_W  ,KC_E   ,KC_R   , KC_T  , KC_MUTE,
        KC_A  , KC_S , KC_D , KC_F, KC_G, KC_H
),
    [_LAYERN] = LAYOUT_2x6(
        KC_1 , KC_2  ,KC_3   ,KC_4   , KC_5  , KC_MUTE,
        KC_6  , KC_7 , KC_8 , KC_9, KC_0, KC_MINUS
),
    [_LAYERF] = LAYOUT_2x6(
        KC_F1 , KC_F2  ,KC_F3   ,KC_F4   , KC_F5  , KC_MUTE,
        KC_F6  , KC_F7 , KC_F8 , KC_F9, KC_F10, KC_F11
)
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_LAYERQ] = { ENCODER_CCW_CW(TO(_LAYERF), TO(_LAYERN))},
    [_LAYERN] =  { ENCODER_CCW_CW(TO(_LAYERQ), TO(_LAYERF))},
    [_LAYERF] =  { ENCODER_CCW_CW(TO(_LAYERN), TO(_LAYERQ))}
};
#endif

#ifdef OLED_ENABLE

layer_state_t layer_state_set_user(layer_state_t state) {
    return state;
}

static void render_logo(void) {
    static const char PROGMEM my_logo[] = {
       0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,254,254,254,140, 24, 48, 96,254,254,254,  0, 14, 14, 14,250,242,250, 14, 14, 14,  0,  6, 30,250,242,254, 48, 48,254,242,250, 30,  6,  0, 14, 14, 14,250,242,250, 14, 14, 14,  0,254,254,242,250,254,206,206,206,206, 14,  0,224, 32, 32, 32, 32,224,  0, 14, 14, 14,250,242,254,  0,  0,  0,  0,142,202,202,238,238,254,254,254,124, 56,  0,254, 50,122,254,206,206,206,254,124, 56,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
       0,  0,  0,  0,  0,  0,  0,  0,  0, 31, 17, 17, 17, 31,  0,  0,  0, 31, 31, 31,  1,  3,  6, 12, 31, 31, 31,  0, 28, 28, 28, 23, 19, 23, 28, 28, 28,  0, 24, 30, 23, 19, 31,  3,  3, 31, 19, 23, 30, 24,  0, 28, 28, 28, 23, 19, 23, 28, 28, 28,  0, 31, 31, 19, 23, 31, 28, 28, 28, 28, 28,  0,  1,  1,  1,  1,  1,  1,  0, 28, 28, 28, 23, 19, 23, 28, 28, 28,  0, 31, 19, 23, 31, 29, 29, 20, 20, 28, 24,  0, 31, 30, 31, 31,  1,  1,  1, 31, 23, 19, 30,  0,  0, 31, 17, 17, 17, 31,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    };
oled_write_raw_P(my_logo, sizeof(my_logo));
}

bool oled_task_user(void) {
	switch (get_highest_layer(layer_state)) {
	case _LAYERQ:
	oled_write_ln_P(PSTR("Layout: QWERTY\n"), false);
	break;
        case _LAYERN:
 	oled_write_ln_P(PSTR("Layout: Numbers\n"), false);
	break;
	case _LAYERF:
    	oled_write_ln_P(PSTR("Layout: F1-F11 Keys\n"), false);
	break;
	default:
    	oled_write_ln_P(PSTR("Layout: UNDEF\n"), false);
	break;
	}
	render_logo();
    	return true;
}

#endif
void keyboard_post_init_user(void) {
setPinInput(B0);
writePinLow(B0);
setPinInput(D5);
writePinLow(D5);
};
