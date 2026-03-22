// dlgwrapper_large.cpp - DlgWrapper large functions (257-1024 bytes)
// Object file: dlgwrapper.obj
// 3 functions

#include "types.h"

extern "C" {
    int strcmp_impl(const char* a, const char* b);
    void* operator_new(u32 size);
    void operator_delete(void* ptr);
}

// ============================================================================
// DlgWrapper::Update - 0x8007de30 | 440 bytes
// Main update loop for dialog wrapper - handles button presses and state changes
// ============================================================================
// NON_MATCHING - switch/case structure with dialog state machine
void DlgWrapper_Update(void* self) {
    // Call Wrapper::Update (0x80086990)
    // bl 0x80086990

    // Read input with player count from offset 0xCC
    int playerCount = *(int*)((u8*)self + 0xCC);
    // Call Wrapper::ReadInput with player=1
    // bl 0x80086aec

    int result = 0; // r3 return
    if (result >= 0) return; // no button pressed

    // Strip high bit: result &= 0x7FFFFFFF
    int button = result & 0x7FFFFFFF;

    switch (button) {
        case 7: { // Accept
            int dialogCount = *(int*)((u8*)self + 0xB8);
            if (dialogCount <= 0) break;

            // Get current dialog at offset 0xAC
            void* dialog = *(void**)((u8*)self + 0xAC);
            int hasCallback = *(int*)((u8*)dialog + 0x40);
            if (hasCallback == 0) break;

            int isActive = *(int*)((u8*)dialog + 0x34);
            if (isActive != 0) break;

            // Set active flag
            *(int*)((u8*)dialog + 0x34) = 1;

            // Check singleton at r13 - 31536
            // If null, allocate new (0x78 bytes) and call constructor at 0x801770c0
            // Call hash function with 0x374BDCEA
            break;
        }

        case 8: { // Decline
            int dialogCount = *(int*)((u8*)self + 0xB8);
            if (dialogCount <= 0) break;

            void* dialog = *(void**)((u8*)self + 0xAC);
            int hasCallback = *(int*)((u8*)dialog + 0x40);
            if (hasCallback == 0) break;

            int isActive = *(int*)((u8*)dialog + 0x34);
            if (isActive != 0) break;

            *(int*)((u8*)dialog + 0x34) = 1;
            // Call with hash 0x5BE54A91
            break;
        }

        case 9: { // Selection changed
            // Similar pattern but with different hash
            break;
        }

        default:
            break;
    }
}

// ============================================================================
// DlgWrapper::GetVariable - 0x8007e274 | 460 bytes
// Gets variable value from dialog wrapper state
// ============================================================================
// NON_MATCHING - string comparison chain
char* DlgWrapper_GetVariable(void* self, char* varName) {
    // Large series of strcmp checks against known variable names
    // Returns string values for:
    // "title", "body", "btn0_text", "btn1_text", "btn2_text"
    // "selection", "visible", "x", "y", "width", "height"
    // "num_buttons", "button_type", etc.

    if (strcmp_impl(varName, "title") == 0) {
        return (char*)*(void**)((u8*)self + 0x80);
    }
    if (strcmp_impl(varName, "body") == 0) {
        return (char*)*(void**)((u8*)self + 0x84);
    }
    if (strcmp_impl(varName, "selection") == 0) {
        static char buf[16];
        int sel = *(int*)((u8*)self + 0x90);
        // Format integer to string
        return buf;
    }
    if (strcmp_impl(varName, "visible") == 0) {
        u32 flags = *(u32*)((u8*)self + 0x04);
        return (char*)((flags & 1) ? "1" : "0");
    }
    if (strcmp_impl(varName, "num_buttons") == 0) {
        static char buf2[16];
        int count = *(int*)((u8*)self + 0x94);
        return buf2;
    }

    // Fall through to parent GetVariable
    return "";
}

// ============================================================================
// DlgWrapper::DlgWrapper - 0x8007e440 | 260 bytes
// Constructor
// ============================================================================
// NON_MATCHING
void DlgWrapper_Ctor(void* self, int isModal) {
    // Call Wrapper constructor
    // Initialize all dialog-specific fields

    *(u32*)((u8*)self + 0x78) = 0;     // state
    *(void**)((u8*)self + 0x80) = 0;   // title string
    *(void**)((u8*)self + 0x84) = 0;   // body string
    *(u32*)((u8*)self + 0x88) = 0;     // button count
    *(u32*)((u8*)self + 0x8C) = 0;     // selection type
    *(u32*)((u8*)self + 0x90) = 0;     // current selection
    *(u32*)((u8*)self + 0x94) = 0;     // num buttons
    *(void**)((u8*)self + 0xAC) = 0;   // current dialog
    *(u32*)((u8*)self + 0xB8) = 0;     // dialog stack count
    *(u32*)((u8*)self + 0xCC) = 1;     // player count

    if (isModal) {
        *(u32*)((u8*)self + 0x78) |= 1; // set modal flag
    }
}
