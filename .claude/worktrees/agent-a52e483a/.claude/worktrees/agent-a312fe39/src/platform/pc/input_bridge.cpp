// input_bridge.cpp — Win32 keyboard + XInput → GC PAD bridge
// Maps PC input to PADStatus structs that the decompiled game code reads.

#include "input_bridge.h"
#include "platform/platform.h"

#ifdef SIMS2_PLATFORM_PC

#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <stdio.h>
#include <string.h>

// ============================================================================
// Keyboard state
// ============================================================================

static int g_keys[256] = {0};  // 1 = pressed, 0 = released

// Analog stick emulation from keyboard
static signed char g_stickX = 0;
static signed char g_stickY = 0;

// ============================================================================
// Key mapping: keyboard → GC PAD buttons
// ============================================================================

struct KeyMapping {
    unsigned int vkCode;
    unsigned short padButton;
};

// Default keyboard mapping (can be customized later)
static const KeyMapping g_keyMap[] = {
    { 'Z',         PAD_BUTTON_A },
    { 'X',         PAD_BUTTON_B },
    { 'A',         PAD_BUTTON_X },
    { 'S',         PAD_BUTTON_Y },
    { VK_RETURN,   PAD_BUTTON_START },
    { 'Q',         PAD_TRIGGER_L },
    { 'W',         PAD_TRIGGER_R },
    { 'E',         PAD_TRIGGER_Z },
    { VK_UP,       PAD_BUTTON_UP },
    { VK_DOWN,     PAD_BUTTON_DOWN },
    { VK_LEFT,     PAD_BUTTON_LEFT },
    { VK_RIGHT,    PAD_BUTTON_RIGHT },
};
static const int g_keyMapCount = sizeof(g_keyMap) / sizeof(g_keyMap[0]);

// WASD / arrow keys for analog stick
struct StickMapping {
    unsigned int vkCode;
    signed char  dx, dy;
};

static const StickMapping g_stickMap[] = {
    { 'I',      0,  127 },   // up
    { 'K',      0, -127 },   // down
    { 'J',   -127,    0 },   // left
    { 'L',    127,    0 },   // right
};
static const int g_stickMapCount = sizeof(g_stickMap) / sizeof(g_stickMap[0]);

// ============================================================================
// Public API
// ============================================================================

void input_init(void) {
    memset(g_keys, 0, sizeof(g_keys));
    g_stickX = 0;
    g_stickY = 0;
    printf("[INPUT] Keyboard input initialized\n");
    printf("[INPUT] Controls: Z=A, X=B, A=X, S=Y, Enter=Start, Q=L, W=R\n");
    printf("[INPUT]           Arrows=D-Pad, IJKL=Analog Stick\n");
}

void input_handle_key(unsigned int vkCode, int isDown) {
    if (vkCode < 256) {
        g_keys[vkCode] = isDown;
    }

    // Recompute analog stick from stick keys
    g_stickX = 0;
    g_stickY = 0;
    for (int i = 0; i < g_stickMapCount; i++) {
        if (g_keys[g_stickMap[i].vkCode]) {
            int newX = (int)g_stickX + g_stickMap[i].dx;
            int newY = (int)g_stickY + g_stickMap[i].dy;
            if (newX > 127) newX = 127;
            if (newX < -128) newX = -128;
            if (newY > 127) newY = 127;
            if (newY < -128) newY = -128;
            g_stickX = (signed char)newX;
            g_stickY = (signed char)newY;
        }
    }
}

void input_handle_mouse(int x, int y, int buttons) {
    // Future: mouse for camera control
    (void)x; (void)y; (void)buttons;
}

void input_poll_controllers(void) {
    // Future: XInput polling
    // For now, keyboard state is updated via input_handle_key from WndProc
}

int input_get_pad_status(void* statusPtr) {
    PADStatus* status = (PADStatus*)statusPtr;
    if (!status) return -1;

    // Controller 0 = keyboard
    memset(&status[0], 0, sizeof(PADStatus));
    status[0].err = 0;  // PAD_ERR_NONE

    // Map buttons
    unsigned short buttons = 0;
    for (int i = 0; i < g_keyMapCount; i++) {
        if (g_keys[g_keyMap[i].vkCode]) {
            buttons |= g_keyMap[i].padButton;
        }
    }
    status[0].button = buttons;

    // Analog stick
    status[0].stickX = g_stickX;
    status[0].stickY = g_stickY;

    // C-stick (not mapped yet)
    status[0].substickX = 0;
    status[0].substickY = 0;

    // Triggers
    status[0].triggerL = g_keys['Q'] ? 255 : 0;
    status[0].triggerR = g_keys['W'] ? 255 : 0;

    // Controllers 1-3: not connected
    for (int i = 1; i < 4; i++) {
        memset(&status[i], 0, sizeof(PADStatus));
        status[i].err = -1;  // PAD_ERR_NO_CONTROLLER
    }

    return 0;
}

#endif // SIMS2_PLATFORM_PC
