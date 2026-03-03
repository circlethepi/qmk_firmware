/**
 * Utilities for RGB lighting
 * Copyright (c) MNZK 2026
 * MIT License
 */
#pragma once

// Underglow LED indices for split keyboard
static const uint8_t UNDERGLOW_LEDS[] = {0, 1, 2, 3, 4, 5, 27, 28, 29, 30, 31, 32};
#define UNDERGLOW_LED_COUNT (sizeof(UNDERGLOW_LEDS) / sizeof(UNDERGLOW_LEDS[0]))

// Set underglow LEDs within a specified range
static inline void set_underglow(uint8_t r, uint8_t g, uint8_t b, uint8_t led_min, uint8_t led_max) {
    for (uint8_t i = 0; i < UNDERGLOW_LED_COUNT; i++) {
        uint8_t led_index = UNDERGLOW_LEDS[i];
        if (led_index >= led_min && led_index <= led_max) {
            rgb_matrix_set_color(led_index, r, g, b);
        }
    }
}

// Thumb key LED indices
static const uint8_t THUMB_LEDS[] = {6, 14, 13, 33, 41, 40};
#define THUMB_LED_COUNT (sizeof(THUMB_LEDS) / sizeof(THUMB_LEDS[0]))

// Set all thumb keys within specified range
static inline void set_thumb_keys(uint8_t r, uint8_t g, uint8_t b, uint8_t led_min, uint8_t led_max) {
    for (uint8_t i = 0; i < THUMB_LED_COUNT; i++) {
        uint8_t led_index = THUMB_LEDS[i];
        if (led_index >= led_min && led_index <= led_max) {
            rgb_matrix_set_color(led_index, r, g, b);
        }
    }
}