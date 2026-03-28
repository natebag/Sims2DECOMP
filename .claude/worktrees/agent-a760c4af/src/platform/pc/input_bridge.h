#ifndef INPUT_BRIDGE_H
#define INPUT_BRIDGE_H

// Maps Win32 keyboard/mouse and XInput controller input to GC PAD buttons.
// The game reads input via PADRead() which fills a PADStatus struct.
// We intercept that call and populate it from PC input state.

#ifdef _WIN32
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#endif

// Call once at startup
void input_init(void);

// Call from WndProc to capture keyboard events
void input_handle_key(unsigned int vkCode, int isDown);

// Call from WndProc for mouse (future — for camera control)
void input_handle_mouse(int x, int y, int buttons);

// Poll XInput controllers (call once per frame before PADRead)
void input_poll_controllers(void);

// Get the current PAD state. Called by our PADRead implementation.
// status: pointer to PADStatus[4] array (4 GC controllers)
// Returns PAD_ERR_NONE (0) for connected controllers
int input_get_pad_status(void* status);

#endif // INPUT_BRIDGE_H
