// muwrapper_large.cpp - MUWrapper large functions (257-1024 bytes)
// Object file: muwrapper.obj
// 7 functions

#include "types.h"
#include "stub_classes.h"

extern "C" {
    int strcmp_impl(const char* a, const char* b);
    void* operator_new(u32 size);
    void operator_delete(void* ptr);
    void memset_impl(void* dst, int val, u32 size);
}

// ============================================================================
// MUWrapper::Shutdown - 0x8007f7bc | 316 bytes
// Shuts down the MU (memory unit/mem card) wrapper
// ============================================================================
// NON_MATCHING
void MUWrapper_Shutdown(void* self) {
    // Release all allocated resources
    // Iterate through slot list and free each
    void** slotStart = *(void***)((u8*)self + 0x08);
    void** slotEnd = *(void***)((u8*)self + 0x0C);

    while (slotStart != slotEnd) {
        void* slot = *slotStart;
        if (slot != 0) {
            operator_delete(slot);
        }
        slotStart++;
    }

    // Clear slot list
    void** listStart = *(void***)((u8*)self + 0x08);
    if (listStart != 0) {
        operator_delete(listStart);
    }
    *(void***)((u8*)self + 0x08) = 0;
    *(void***)((u8*)self + 0x0C) = 0;
    *(void***)((u8*)self + 0x10) = 0;

    // Call parent Wrapper::Shutdown
}

// ============================================================================
// MUWrapper::ResetSlotSelection - 0x80080ba8 | 984 bytes
// Resets all slot selections in the memory unit dialog
// ============================================================================
// NON_MATCHING - large function with multiple slot iteration
void MUWrapper_ResetSlotSelection(void* self, int clearAll) {
    // Iterate through all memory card slots
    // For each slot, reset selection state and visual indicators
    // Large loop with nested conditionals

    int numSlots = *(int*)((u8*)self + 0xC0);

    for (int i = 0; i < numSlots; i++) {
        void** slotArray = *(void***)((u8*)self + 0xB0);
        void* slot = slotArray[i];
        if (slot == 0) continue;

        // Reset slot state
        *(int*)((u8*)slot + 0x00) = 0;  // state
        *(int*)((u8*)slot + 0x04) = 0;  // selected
        *(int*)((u8*)slot + 0x08) = 0;  // highlighted

        if (clearAll) {
            *(int*)((u8*)slot + 0x0C) = 0;  // dirty flag
            *(int*)((u8*)slot + 0x10) = 0;  // save data valid
        }

        // Update visual state via shader calls
        // Set icon shaders for empty/full/selected states
    }

    // Reset scroll position
    *(int*)((u8*)self + 0xD0) = 0;
    *(int*)((u8*)self + 0xD4) = 0;
}

// ============================================================================
// MUWrapper::HideDialog - 0x80081880 | 340 bytes
// Hides the MU dialog
// ============================================================================
// NON_MATCHING
void MUWrapper_HideDialog(void* self) {
    // Set visibility flags
    u32 flags = *(u32*)((u8*)self + 0x04);
    flags &= ~1; // hide
    *(u32*)((u8*)self + 0x04) = flags;

    // Hide all child panes
    void** paneList = *(void***)((u8*)self + 0x08);
    void** paneEnd = *(void***)((u8*)self + 0x0C);

    while (paneList != paneEnd) {
        void* pane = *paneList;
        if (pane != 0) {
            *(u32*)((u8*)pane + 0x04) &= ~1;
        }
        paneList++;
    }

    // Reset state
    *(int*)((u8*)self + 0xC8) = 0;  // dialog state
    *(int*)((u8*)self + 0xCC) = -1; // selection
}

// ============================================================================
// MUWrapper::ShowDialog - 0x800815d4 | 684 bytes
// Shows the MU dialog with slot information
// ============================================================================
// NON_MATCHING - complex dialog setup
void MUWrapper_ShowDialog(void* self) {
    // Set up dialog visibility
    u32 flags = *(u32*)((u8*)self + 0x04);
    flags |= 1; // show
    *(u32*)((u8*)self + 0x04) = flags;

    // Initialize slot display
    int numSlots = *(int*)((u8*)self + 0xC0);
    for (int i = 0; i < numSlots; i++) {
        // Set up each slot's visual state
        // Load save file info
        // Set icon shaders
    }

    // Show relevant panes
    void** paneList = *(void***)((u8*)self + 0x08);
    int numPanes = (int)((u8*)*(void***)((u8*)self + 0x0C) - (u8*)paneList) / 4;
    for (int i = 0; i < numPanes; i++) {
        void* pane = paneList[i];
        if (pane != 0) {
            *(u32*)((u8*)pane + 0x04) |= 1;
        }
    }

    // Set initial selection
    *(int*)((u8*)self + 0xCC) = 0;
    *(int*)((u8*)self + 0xC8) = 1; // active state
}

// ============================================================================
// MUWrapper::Update - 0x80080f80 | 840 bytes
// Main update for MU dialog - handles input and state
// ============================================================================
// NON_MATCHING - large state machine
void MUWrapper_Update(void* self) {
    int state = *(int*)((u8*)self + 0xC8);
    if (state == 0) return; // not active

    // Call parent Wrapper::Update
    // Read input

    // Process input based on current state
    switch (state) {
        case 1: // Slot selection
        {
            // Handle D-pad up/down for slot navigation
            // Handle A button for selection
            // Handle B button for cancel
            break;
        }
        case 2: // Confirming
        {
            // Handle confirmation dialog response
            break;
        }
        case 3: // Saving/Loading
        {
            // Handle async save/load progress
            break;
        }
        case 4: // Error
        {
            // Handle error dialog
            break;
        }
    }

    // Update visual state
    int selection = *(int*)((u8*)self + 0xCC);
    // Highlight current selection
    // Update scroll position
}

// ============================================================================
// MUWrapper::Draw - 0x800812c8 | 636 bytes
// Draws the MU dialog
// ============================================================================
// NON_MATCHING - rendering with multiple passes
void MUWrapper_Draw(void* self, void* rc) {
    int state = *(int*)((u8*)self + 0xC8);
    if (state == 0) return;

    // Draw background
    // Call parent Wrapper::Draw

    // Draw slot icons
    int numSlots = *(int*)((u8*)self + 0xC0);
    int scrollPos = *(int*)((u8*)self + 0xD0);
    int visibleSlots = 4; // max visible at once

    for (int i = scrollPos; i < numSlots && i < scrollPos + visibleSlots; i++) {
        void** slotArray = *(void***)((u8*)self + 0xB0);
        void* slot = slotArray[i];
        if (slot == 0) continue;

        // Draw slot icon
        // Draw slot text
        // Draw selection highlight if selected
        int selection = *(int*)((u8*)self + 0xCC);
        if (i == selection) {
            // Draw highlight
        }
    }

    // Draw scroll arrows if needed
    if (scrollPos > 0) {
        // Draw up arrow
    }
    if (scrollPos + visibleSlots < numSlots) {
        // Draw down arrow
    }
}

// ============================================================================
// MUWrapper::SetVariable - 0x800819d4 | 532 bytes
// Sets a variable in the MU dialog
// ============================================================================
// NON_MATCHING - string comparison chain
void MUWrapper_SetVariable(void* self, char* varName, char* value) {
    if (strcmp_impl(varName, "title") == 0) {
        // Set dialog title
        *(void**)((u8*)self + 0xE0) = value;
        return;
    }
    if (strcmp_impl(varName, "body") == 0) {
        // Set dialog body text
        *(void**)((u8*)self + 0xE4) = value;
        return;
    }
    if (strcmp_impl(varName, "num_slots") == 0) {
        // Parse and set number of slots
        return;
    }
    if (strcmp_impl(varName, "mode") == 0) {
        // Set dialog mode (save/load)
        return;
    }
    if (strcmp_impl(varName, "slot_name") == 0) {
        // Set name for current slot
        return;
    }

    // Fall through to parent SetVariable
}
