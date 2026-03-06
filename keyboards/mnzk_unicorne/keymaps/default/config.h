/* SPDX-License-Identifier: GPL-2.0-or-later */

#pragma once

// #define DYNAMIC_KEYMAP_LAYER_COUNT 8

// SPLIT
#define SPLIT_LAYER_STATE_ENABLE

// Mouse 
#define MK_KINETIC_SPEED
#define MOUSEKEY_MOVE_DELTA         8  // default 16
#define MOUSEKEY_INITIAL_SPEED      100  // default 100
#define MOUSEKEY_BASE_SPEED         1000 // dfault 5000
#define MOUSEKEY_WHEEL_INITIAL_MOVEMENTS    4 // default 16
#define MOUSEKEY_WHEEL_BASE_MOVEMENTS       20 // default 32

// Tapping
#define TAPPING_TOGGLE 2
//  timers 
#define FLOW_TAP_TERM 100


// Audio
// custom startup song!
#ifdef AUDIO_ENABLE
#   define AUDIO_ENABLE_TONE_MULTIPLEXING
#   define AUDIO_VOICES
#   define MNZK_START_SONG \
        Q__NOTE(_DS5), Q__NOTE(_GS4), H__NOTE(_FS4), \
        E__NOTE(_DS4), E__NOTE(_G4), E__NOTE(_AS4), Q__NOTE(_C5), \
        Q__NOTE(_D5), Q__NOTE(_DS5), H__NOTE(_G5)
#   define STARTUP_SONG SONG(MNZK_START_SONG)
#endif

// Onscreen Overlay
#define RAW_EPSIZE 32
#define PAYLOAD_MARK 0x90
#define PAYLOAD_BEGIN 24
#define RAW_USAGE_PAGE 0xFF60
#define RAW_USAGE 0x61