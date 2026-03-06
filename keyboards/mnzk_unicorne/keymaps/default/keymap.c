#include QMK_KEYBOARD_H

#ifdef OLED_ENABLE
#include "animation.c"
#endif

#ifdef RGB_MATRIX_ENABLE
#include "rgb-utils.h"
#endif


// layer enums
enum {
  _BASE,    // (mostly) Gallium layout
  _SYMBOL,
  _NAV,
  _MEDIA,
  _EDIT,
  _UTILITY,
  _OBSIDIAN,

  _TOTAL_LAYERS
};

/*===========================================================================*/
// Custom Keycodes
/*===========================================================================*/

// Base Home Row Mods
#define LC_N    LCTL_T(KC_N)
#define LA_R    LALT_T(KC_R)
#define LG_T    LGUI_T(KC_T)
#define LS_S    LSFT_T(KC_S)

#define RS_H    RSFT_T(KC_H)
#define RG_A    RGUI_T(KC_A)
#define RA_E    LALT_T(KC_E)
#define RC_I    RCTL_T(KC_I)

// Symbol Home Row Mods
// #define LC_LPRN LCTL_T(LSFT(KC_9))
// #define LA_RPRN LALT_T(LSFT(KC_0))
#define LG_LBRC LGUI_T(KC_LBRC)
#define LS_RBRC LSFT_T(KC_RBRC)

#define RS_4    RSFT_T(KC_4)
#define RG_5    RGUI_T(KC_5)
#define RA_6    LALT_T(KC_6)
#define RC_EQL  RCTL_T(KC_EQL)

// Layer Navigation 
#define CK_LLK3     LT(_UTILITY, KC_BACKSLASH) 
#define CK_LLK2     LT(_SYMBOL, KC_BACKSPACE)
#define CK_LLK1     LT(_EDIT, KC_ENTER)

#define CK_RLK1     LT(_NAV, KC_ENTER)
#define CK_RLK2     LT(_SYMBOL, KC_SPACE)
#define CK_RLK3     LT(_MEDIA, KC_SLSH)

// basic shortcuts (mac)
#define UNDO    LGUI(KC_Z)
#define REDO    LGUI(KC_Y)
#define CUT     LGUI(KC_X)
#define COPY    LGUI(KC_C)
#define PASTE   LGUI(KC_V)
#define FIND    LGUI(KC_F)
#define SAVE    LGUI(KC_S)
#define ALL     LGUI(KC_A)
#define CLOSE   LGUI(KC_W)
#define NEWTAB  LGUI(KC_T)
#define WINDOW  LGUI(KC_N)
#define REFRESH LGUI(KC_R)
#define BOLD    LGUI(KC_B)
#define ITALIC  LGUI(KC_I)

// nav shortcuts (mac)
#define GOBACK  LGUI(KC_LBRC)
#define GOFORE  LGUI(KC_RBRC)
#define ZOOMIN  LGUI(KC_EQL)
#define ZOOMOUT LGUI(KC_MINS)


// custom keycodes
enum custom_keycodes {
    LC_LPRN,
    LA_RPRN,
};





/*===========================================================================*/
// ACTUAL KEYMAPPING 
/*===========================================================================*/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT( //0
    //,-----------------------------------------------------,                    ,-----------------------------------------------------,
         KC_ESC,    KC_B,    KC_L,    KC_D,    KC_C,    KC_V,                         KC_J,    KC_F,    KC_O,    KC_U,  KC_DOT, KC_BSPC,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
         KC_TAB,    LC_N,    LA_R,    LG_T,    LS_S,    KC_G,                         KC_Y,    RS_H,    RG_A,    RA_E,    RC_I, KC_COMM,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_LALT,    KC_X,    KC_Q,    KC_M,    KC_W,    KC_Z,                         KC_K,    KC_P, KC_QUOT,  KC_DOT, KC_SCLN, KC_SLSH,
    //'--------+--------+--------+--------+--------+--------+--------,  ,--------+--------+--------+--------+--------+--------+--------'
                                            CK_LLK3, CK_LLK2, CK_LLK1,    CK_RLK1, CK_RLK2, CK_RLK3
                                        //'--------+--------+--------'  '--------+--------+--------'
    ),

    [_SYMBOL] = LAYOUT( //1
    //,-----------------------------------------------------,                    ,-----------------------------------------------------,
        _______, KC_LABK, KC_RABK, KC_MINUS, KC_GRV, _______,                      KC_PSLS,    KC_7,    KC_8,    KC_9,KC_MINUS, _______,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        _______, LC_LPRN, LA_RPRN, LG_LBRC, LS_RBRC, KC_BSLS,                     KC_COMMA,    RS_4,    RG_5,    RA_6,  RC_EQL, _______,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|  
           REDO,    UNDO,     CUT,   COPY,    PASTE, _______,                       KC_DOT,    KC_1,    KC_2,    KC_3, KC_KP_0, _______,
    //'--------+--------+--------+--------+--------+--------+--------,  ,--------+--------+--------+--------+--------+--------+--------'
                                            _______, _______, _______,    _______, _______, _______ 
                                        //'--------+--------+--------'  '--------+--------+--------'
                                        //                     ^^^          ^^^
    ),
                                    
    [_NAV] = LAYOUT( //2 
    //,-----------------------------------------------------,                    ,-----------------------------------------------------,
        _______, _______, _______,   MS_UP, ZOOMOUT,  ZOOMIN,                      _______, KC_HOME,   KC_UP,  KC_END, _______, _______, 
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        _______, _______, MS_LEFT, MS_DOWN, MS_RGHT, MS_WHLD,                       GOBACK, KC_LEFT, KC_DOWN,KC_RIGHT,  GOFORE, _______, 
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        _______, KC_LCTL, KC_LSFT, KC_LALT, _______, MS_WHLU,                      _______, _______, _______, _______, _______, _______, \
    //'--------+--------+--------+--------+--------+--------+--------,  ,--------+--------+--------+--------+--------+--------+--------'
                                        _______, MS_BTN1, MS_BTN2,    _______, _______, _______ 
                                    //'--------+--------+--------'  '--------+--------+--------'
                                    //                                                   ^^^
    ),

    [_MEDIA] = LAYOUT( //3
    //,-----------------------------------------------------,                    ,-----------------------------------------------------,
        _______, _______, _______, _______, _______, _______,                      KC_MUTE, KC_VOLD, KC_VOLU, _______, _______, _______, 
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        _______, _______, _______, _______, _______, _______,                      RM_VALU, KC_MPRV, KC_MPLY, KC_MNXT, _______, _______, 
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        _______, _______, _______, _______, _______, _______,                      RM_VALD, KC_BRID, KC_BRIU, _______, _______, _______, 
    //'--------+--------+--------+--------+--------+--------+--------,  ,--------+--------+--------+--------+--------+--------+--------'
                                            _______, _______, _______,    _______, _______, _______ 
                                        //'--------+--------+--------'  '--------+--------+--------'
                                        //                                          ^^^
    ),

    [_EDIT] = LAYOUT ( //4
    //,-----------------------------------------------------,                    ,-----------------------------------------------------,
        _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______, 
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______, 
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
           REDO,    UNDO,     CUT,   COPY,    PASTE, _______,                      _______, _______, _______, _______, _______, _______, 
    //'--------+--------+--------+--------+--------+--------+--------,  ,--------+--------+--------+--------+--------+--------+--------'
                                            _______, _______, _______,    _______, _______, _______ 
                                        //'--------+--------+--------'  '--------+--------+--------'
                                        //             ^^^
    ),              
    
    [_UTILITY] = LAYOUT( //5
        QK_BOOT, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, QK_CLEAR_EEPROM, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______)
};

/*===========================================================================*/
// COMBOS
/*===========================================================================*/
enum combos {
  FO_DOLLAR,
};

const uint16_t PROGMEM fo_dollar[] = {    KC_F,    KC_O,  COMBO_END};

combo_t key_combos[] = {
  [FO_DOLLAR]   =   COMBO(fo_dollar, LSFT(KC_4)),
};


/*===========================================================================*/
// Data Sync - from desync corne keymap (for later)
/*===========================================================================*/

// #include "transactions.h"

// typedef struct _master_to_slave_t {
//     struct {
//         bool static_display :1;
//         bool timeout :1;
//         bool active :1;
//     } oled;

//     struct {
//         bool capturing :1;
//         bool active :1;
//     } case_lock;
// } master_to_slave_t;

// master_to_slave_t sync_data;

// void user_config_sync_handler(uint8_t initiator2target_buffer_size, const void* initiator2target_buffer,
//                       uint8_t target2initiator_buffer_size, void* target2initiator_buffer) {
//     if (initiator2target_buffer_size == sizeof(master_to_slave_t)) {
//         memcpy(&sync_data, initiator2target_buffer, initiator2target_buffer_size);
//     }
// }



/*===========================================================================*/
// OLED 
/*===========================================================================*/

#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (!is_keyboard_master()) { // for right side
        return OLED_ROTATION_180;  
    }
    return rotation;
}

bool oled_task_user(void) {
  if (is_keyboard_master()) {
    oled_render_anim();
  }
  return false;
}

#endif

/*===========================================================================*/
// RGB MATRIX
/*===========================================================================*/

#ifdef RGB_MATRIX_ENABLE

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {

    // Set thumb keys based on active layer
    switch (get_highest_layer(layer_state)) {
        case _SYMBOL:
            set_thumb_keys(0, 255, 0);    // Green
            break;
        case _NAV:
            set_thumb_keys(0, 0, 255);    // Blue
            break;
        case _MEDIA:
            set_thumb_keys(128, 0, 190);  // Purple
            break;
        case _EDIT:
            set_thumb_keys(255, 100, 0);  // Orange
            break;
        case _UTILITY:
            set_thumb_keys(255, 0, 0);  // RED
            break;
        case _BASE:
        default:
            set_thumb_keys(255, 215, 0);  // Golden yellow
            break;
    }
    
    return false;
}

#endif

/*===========================================================================*/
// TAP TIMING
/*===========================================================================*/

bool is_flow_tap_key(uint16_t keycode) {
    switch (get_tap_keycode(keycode)) {
        case KC_SPC:
        case KC_A ... KC_Z:
        case KC_DOT:
        case KC_COMM:
        case KC_SCLN:
        case KC_SLSH:
            return true;
    }
    return false;
}

uint16_t get_flow_tap_term(uint16_t keycode, keyrecord_t* record, 
                           uint16_t prev_keycode) {
    if (get_tap_keycode(prev_keycode) == KC_BSPC) {
        return 0;
    }

    if (is_flow_tap_key(keycode) && is_flow_tap_key(prev_keycode)) {
        switch (keycode) {
            // Shift mod-taps
            case LS_S:
            case RS_H:
                return 25;

            // Ctrl mod-taps
            case LG_T:
            case RG_A:
                return 75;

            // Alt mod-taps
            case LA_R:
            case RA_E:
                return 100;

            // GUI mod-taps
            case LC_N:
            case RC_I:
                return 50;

            default:
                return FLOW_TAP_TERM;
        }
    }

    return 0;
}


/*===========================================================================*/
// Houkeeping / config
/*===========================================================================*/

// Onscreen Overlay
#include "raw_hid.h"
// Notifies the host of the layer change
layer_state_t layer_state_set_user(layer_state_t state) {
    uint8_t hi_layer = get_highest_layer(state);
    uint8_t response[RAW_EPSIZE];
    memset(response, 0x00, RAW_EPSIZE);
    response[PAYLOAD_BEGIN] = PAYLOAD_MARK;
    response[PAYLOAD_BEGIN + 1] = hi_layer;
    raw_hid_send(response, RAW_EPSIZE);
    return state;
}



// Boot
void keyboard_post_init_user(void) {
    layer_move(_BASE);

    rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
    rgb_matrix_sethsv_noeeprom(220, 30, 128);  
    set_underglow(200, 200, 200);

}



