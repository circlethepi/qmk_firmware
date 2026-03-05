/**
 * Utilities for RGB lighting
 * Copyright (c) MNZK 2026
 * MIT License
 */

// from descync corne 
//  ,-----------------------,           ,-----------------------,
//    24, 23, 18, 17, 10, 09,             36, 37, 44, 45, 50, 51,
//  |---+---+---+---+---+---|           |---+---+---+---+---+---|
//    25, 22, 19, 16, 11, 08,             35, 38, 43, 46, 49, 52,
//  |---+---+---+---+---+---|           |---+---+---+---+---+---|
//    26, 21, 20, 15, 12, 07,             34, 39, 42, 47, 48, 53,
//  |---+---+---+---+---+---+---|   |---+---+---+---+---+---+---|
//                    14, 13, 06,     33, 40, 41
//                  '-----------'   '-----------'
// Underglow:            00 - 05      27 - 32

#pragma once
// split keyboard
static void rgb_matrix_set_color_split(uint8_t index, uint8_t r, uint8_t g, uint8_t b) {
    if ((is_keyboard_master() && index < 27) || (!is_keyboard_master() && index >= 27)) {
        rgb_matrix_set_color(index, r, g, b);
    }
}


// Set underglow LEDs within a specified range
static inline void set_underglow(uint8_t r, uint8_t g, uint8_t b) {
    int UNDERGLOW_LEDS[12] = {0, 1, 2, 3, 4, 5, 27, 28, 29, 30, 31, 32};
    for (uint8_t i = 0; i < 12; i++) {
        uint8_t led_index = UNDERGLOW_LEDS[i];
        rgb_matrix_set_color_split(led_index, r, g, b);
    }
}


// Set all thumb keys within specified range
static inline void set_thumb_keys(uint8_t r, uint8_t g, uint8_t b) {
    int THUMB_LEDS[6] = {6, 14, 13, 33, 41, 40};
    for (uint8_t i = 0; i < 6; i++) {
        rgb_matrix_set_color_split(THUMB_LEDS[i], r, g, b);
    }
}