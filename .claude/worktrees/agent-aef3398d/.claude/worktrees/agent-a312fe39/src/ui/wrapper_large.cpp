// wrapper_large.cpp - UI wrapper large functions (257-1024 bytes)
// Object file: wrapper.obj
// 20 functions

#include "types.h"
#include "stub_classes.h"

// Forward declarations
struct EVec2;
struct EVec4;
class ERC;
class ERShader;
class ERFont;

extern "C" {
    void operator_delete(void* ptr);
    void SmallBlockAllocator_Free(void* ptr);
    void* SmallBlockAllocator_Alloc(u32 size);
    void* operator_new(u32 size);
    void memset_impl(void* dst, int val, u32 size);
    void memcpy_impl(void* dst, const void* src, u32 size);
    void ERShader_Release_v(void* shader);
    void TextBlock_SetDirty(void* tb);
    void TextBlock_Draw(void* tb, void* rc, float alpha);
    void TextBaseItem_Startup(void* item);
    void TextBaseItem_Reset(void* item);
    void TextBaseItem_CalculateSize(void* item);
    void TextBaseItem_SetText(void* item, unsigned short* text);
    void WrapperPaneBase_DrawItem(void* rc, void* pos, void* size, float alpha,
        void* shader, void* color, int flags);
    int strcmp_impl(const char* a, const char* b);
    int strlen_impl(const char* s);
}

// ============================================================================
// DrawIcon - 0x800842d8 | 396 bytes
// Draws an icon with position/size/color and optional alpha blending
// ============================================================================
// NON_MATCHING - vtable dispatch offsets may differ
void DrawIcon(void* rc, void* pos, void* size, void* color, void* shader) {
    // r3=ERC*, r4=EVec2* pos, r5=EVec2* size, r6=EVec4* color, r7=ERShader*
    float posX = *(float*)((u8*)pos + 0x00);
    float posY = *(float*)((u8*)pos + 0x04);
    float sizeX = *(float*)((u8*)size + 0x00);
    float sizeY = *(float*)((u8*)size + 0x04);

    // Scale factor from rodata (0x803d7230)
    float scale = 0.5f;
    float adjX = posX - sizeX * scale;
    float adjY = posY - sizeY * scale;

    // Get render context vtable dispatch
    void* shaderObj = *(void**)((u8*)shader + 0x14);
    if (shaderObj == 0) {
        void* next = *(void**)((u8*)shader + 0x18);
        if (next != 0) {
            shaderObj = *(void**)((u8*)next + 0x14);
        }
    }

    // Call Begin via vtable
    void** vtbl = *(void***)((u8*)shaderObj + 0xF0);
    s16 thisAdj = *(s16*)((u8*)vtbl + 0x10);
    void* beginFunc = *(void**)((u8*)vtbl + 0x14);
    void* thisPtr = (u8*)rc + thisAdj;
    // blrl dispatch to begin

    // Check alpha != 0.0
    float alpha = *(float*)((u8*)color + 0x0C);
    if (alpha != 0.0f) {
        // Set alpha blend mode via vtable at offset 0x140
        void** vtbl2 = *(void***)((u8*)rc + 0x70);
        // dispatch alpha blend
    }

    // Draw the icon
    void** vtbl3 = *(void***)((u8*)rc + 0x70);
    float endX = adjX + sizeX;
    float endY = adjY + sizeY;
    float one = 1.0f;
    float zero = 0.0f;
    // dispatch draw call via vtable at offset 0x188

    // Restore alpha if needed
    if (alpha != 0.0f) {
        // dispatch restore alpha
    }
}

// ============================================================================
// TextBaseItem::SetStyle - 0x800845dc | 560 bytes
// Sets the visual style of a text item, initializing color arrays
// ============================================================================
// NON_MATCHING - large static color table initialization
void TextBaseItem_SetStyle(void* self, int style) {
    static int s_initialized = 0; // r13 - 24660
    *(int*)((u8*)self + 0x6C) = style;

    if (!s_initialized) {
        // Initialize 13 style color entries (EVec4[13]) at global table
        // Each entry is 20 bytes (EVec4 + flag)
        // Addresses: 0x80485810 area
        // Copies from rodata color tables at 0x80476270, 0x80476280, etc.
        // This is a one-time static init of the style color table
        s_initialized = 1;
    }

    // Look up the style in the table
    int offset = style * 20;
    // Copy color from table to the TextBlock's color pointer
    void* tb = (u8*)self + 0x20;
    void* colorPtr = *(void**)((u8*)tb + 0x24);
    // Copy 4 floats from style table[style] to colorPtr
    // Set shadow flag based on table entry
    int flag = *(int*)((u8*)self + 0x20 + 0x38);
    // Update shadow enable bit
}

// ============================================================================
// WrapperPaneBase::Shutdown - 0x80084ab4 | 324 bytes
// Shuts down a wrapper pane, releasing shaders and items
// ============================================================================
// NON_MATCHING - shader release loop details
void WrapperPaneBase_Shutdown(void* self) {
    // Release background shader if present
    void* bgShader = *(void**)((u8*)self + 0x18);
    if (bgShader != 0) {
        ERShader_Release_v(bgShader);
        *(void**)((u8*)self + 0x18) = 0;
    }

    // Delete item list
    // Call DeleteItemList at 0x800856b8
    // bl 0x800856b8

    // Check if button shaders are allocated (flags & 0xFF00)
    u32 flags = *(u32*)((u8*)self + 0x04);
    if ((flags & 0xFF00) == 0) return;

    // Release main accept shader
    void* acceptShader = *(void**)((u8*)self + 0x38);
    if (acceptShader != 0) {
        // Call shader release function
    } else {
        // Load from different path
    }

    // Loop through 7 button shaders (0x40-0x5C) releasing each
    for (int i = 0; i <= 6; i++) {
        *(void**)((u8*)self + 0x40 + i * 4) = 0;
        u32 mask = 0x100 << i;
        if (flags & mask) {
            // Release button shader via vtable
        }
    }

    // Release decline shader
    // Call shader release at offset 0x74
}

// ============================================================================
// WrapperPaneBase::DeleteItemList - 0x800856b8 | 296 bytes
// Deletes all items in the pane's item list
// ============================================================================
// NON_MATCHING
void WrapperPaneBase_DeleteItemList(void* self) {
    // Get the item list vector at offset 0x08
    void** listStart = *(void***)((u8*)self + 0x08);
    void** listEnd = *(void***)((u8*)self + 0x0C);

    // Iterate through items and delete each
    while (listStart != listEnd) {
        void* item = *listStart;
        if (item != 0) {
            // Call item destructor via vtable
            void** vtbl = *(void***)item;
            // vtbl[0] = destructor
        }
        listStart++;
    }

    // Clear the vector
    // Free memory if > 128 bytes (SmallBlockAllocator threshold)
}

// ============================================================================
// WrapperPaneBase::DrawBackground - 0x80084bf8 | 652 bytes
// Draws the background of a wrapper pane with borders
// ============================================================================
// NON_MATCHING - complex rendering setup with multiple vtable dispatches
void WrapperPaneBase_DrawBackground(void* self, void* rc) {
    // Get background shader from offset 0x18
    void* bgShader = *(void**)((u8*)self + 0x18);
    if (bgShader == 0) return;

    // Get pane position and size
    float posX = *(float*)((u8*)self + 0x24);
    float posY = *(float*)((u8*)self + 0x28);
    float sizeX = *(float*)((u8*)self + 0x2C);
    float sizeY = *(float*)((u8*)self + 0x30);

    // Setup border rendering
    // Uses 9-slice rendering pattern:
    // TL, TC, TR, ML, MC, MR, BL, BC, BR
    float borderSize = 8.0f;

    // Draw center
    // Draw edges
    // Draw corners
    // All via vtable dispatch through the render context
}

// ============================================================================
// WrapperPaneBase::GetVariableButtonIndex - 0x800857e0 | 384 bytes
// Parses variable name to get button index
// ============================================================================
// NON_MATCHING
int WrapperPaneBase_GetVariableButtonIndex(void* self, char* varName, char* value) {
    // Parse button index from variable name
    // Format: "btn_N_property" where N is the button index
    int index = -1;

    // strcmp against known variable names
    // "accept", "decline", "btn0"-"btn5"
    if (strcmp_impl(varName, "accept") == 0) {
        index = 0;
    } else if (strcmp_impl(varName, "decline") == 0) {
        index = 1;
    }
    // ... more button name checks

    return index;
}

// ============================================================================
// WrapperPaneBase::GetVariable - 0x80085960 | 320 bytes
// Gets a variable value by name
// ============================================================================
// NON_MATCHING
char* WrapperPaneBase_GetVariable(void* self, char* varName) {
    // Check various variable names
    // "visible", "x", "y", "width", "height", "alpha"
    // Returns string representation of the value

    if (strcmp_impl(varName, "visible") == 0) {
        u32 flags = *(u32*)((u8*)self + 0x04);
        return (char*)((flags & 1) ? "1" : "0");
    }

    return "";
}

// ============================================================================
// WrapperPaneBase::AddButton - 0x80085b9c | 800 bytes
// Adds a button to the wrapper pane
// ============================================================================
// NON_MATCHING - complex vector insertion with memory management
void WrapperPaneBase_AddButton_impl(void* self, int buttonType, int enabled, unsigned short* text) {
    int buttonIdx = buttonType;
    int slotOffset = buttonIdx * 4;
    void* existingBtn = *(void**)((u8*)self + 0x40 + slotOffset);

    if (existingBtn != 0) {
        // Button already exists, just update
        return;
    }

    // Allocate new TextBaseItem (0x70 bytes)
    void* newItem = operator_new(0x70);

    // Initialize the item
    *(int*)((u8*)newItem + 0x00) = 2; // type = button
    *(int*)((u8*)newItem + 0x04) = 1; // enabled
    *(void**)((u8*)newItem + 0x08) = 0; // no extra data

    // Call TextBlock constructor
    // Set style to button style (5)

    // Store in button slot
    *(void**)((u8*)self + 0x40 + slotOffset) = newItem;

    // Insert into item list vector
    void** listEnd = *(void***)((u8*)self + 0x0C);
    void** listCapacity = *(void***)((u8*)self + 0x10);

    if (listEnd != listCapacity) {
        // Simple append
        *listEnd = newItem;
        *(void***)((u8*)self + 0x0C) = listEnd + 1;
    } else {
        // Need to grow the vector
        void** listStart = *(void***)((u8*)self + 0x08);
        int oldCount = (int)((u8*)listEnd - (u8*)listStart) / 4;
        int newCapacity = oldCount + 1;
        int newSize = newCapacity * 4;

        void* newBuf;
        if (newSize > 128) {
            newBuf = operator_new(newSize);
        } else {
            newBuf = SmallBlockAllocator_Alloc(newSize);
        }

        // Copy old items
        if (listStart != listEnd) {
            memcpy_impl(newBuf, listStart, oldCount * 4);
        }

        // Free old buffer
        // Store new buffer and update pointers
    }
}

// ============================================================================
// WrapperPaneBase::ShowEnabledButtons - 0x80085ebc | 308 bytes
// Shows all enabled buttons
// ============================================================================
// NON_MATCHING
void WrapperPaneBase_ShowEnabledButtons(void* self) {
    u32 flags = *(u32*)((u8*)self + 0x04);

    for (int i = 0; i < 7; i++) {
        void* btn = *(void**)((u8*)self + 0x40 + i * 4);
        if (btn != 0) {
            u32 mask = 0x100 << i;
            if (flags & mask) {
                *(u32*)((u8*)btn + 0x04) |= 1; // show
            }
        }
    }
}

// ============================================================================
// WrapperPaneBase::HideEnabledButtons - 0x80085ff0 | 308 bytes
// Hides all enabled buttons
// ============================================================================
// NON_MATCHING
void WrapperPaneBase_HideEnabledButtons(void* self) {
    u32 flags = *(u32*)((u8*)self + 0x04);

    for (int i = 0; i < 7; i++) {
        void* btn = *(void**)((u8*)self + 0x40 + i * 4);
        if (btn != 0) {
            u32 mask = 0x100 << i;
            if (flags & mask) {
                *(u32*)((u8*)btn + 0x04) &= ~1; // hide
            }
        }
    }
}

// ============================================================================
// WrapperPaneBase::ShowButton - 0x80086124 | 268 bytes
// Shows a specific button by type
// ============================================================================
// NON_MATCHING
void WrapperPaneBase_ShowButton(void* self, int buttonType) {
    void* btn = *(void**)((u8*)self + 0x40 + buttonType * 4);
    if (btn != 0) {
        *(u32*)((u8*)btn + 0x04) |= 1;
        u32 flags = *(u32*)((u8*)self + 0x04);
        flags |= (0x100 << buttonType);
        *(u32*)((u8*)self + 0x04) = flags;
    }
}

// ============================================================================
// WrapperPaneBase::HideButton - 0x80086230 | 268 bytes
// Hides a specific button by type
// ============================================================================
// NON_MATCHING
void WrapperPaneBase_HideButton(void* self, int buttonType) {
    void* btn = *(void**)((u8*)self + 0x40 + buttonType * 4);
    if (btn != 0) {
        *(u32*)((u8*)btn + 0x04) &= ~1;
        u32 flags = *(u32*)((u8*)self + 0x04);
        flags &= ~(0x100 << buttonType);
        *(u32*)((u8*)self + 0x04) = flags;
    }
}

// ============================================================================
// DialogPaneBase::Startup - 0x800863cc | 940 bytes
// Initializes a dialog pane with all its items
// ============================================================================
// NON_MATCHING - complex initialization sequence
void DialogPaneBase_Startup(void* self) {
    // Call WrapperPaneBase::Startup (0x80084a8c)
    // This is a large initialization that:
    // 1. Allocates title TextBaseItem (0x70 bytes)
    // 2. Sets up TextBlock
    // 3. Sets style to 5
    // 4. Allocates body text item
    // 5. Sets up accept/decline buttons
    // 6. Configures layout
    // All done through the same pattern as AddButton
}

// ============================================================================
// Wrapper::WrapperShutdown - 0x80086848 | 316 bytes
// Shuts down the wrapper system
// ============================================================================
// NON_MATCHING
void Wrapper_WrapperShutdown(void* self) {
    // Iterate through all panes and shut each down
    void** paneList = *(void***)((u8*)self + 0x08);
    void** paneEnd = *(void***)((u8*)self + 0x0C);

    while (paneList != paneEnd) {
        void* pane = *paneList;
        if (pane != 0) {
            // Call pane shutdown via vtable
        }
        paneList++;
    }

    // Release the pane list
}

// ============================================================================
// Wrapper::WrapperDraw - 0x80086994 | 340 bytes
// Draws all visible wrapper panes
// ============================================================================
// NON_MATCHING
void Wrapper_WrapperDraw(void* self, void* rc) {
    // Read input state
    // Update controller manager
    void* ctrlMgr = *(void**)((u8*)self + 0x00);

    // Iterate through panes, draw each visible one
    void** paneList = *(void***)((u8*)self + 0x08);
    void** paneEnd = *(void***)((u8*)self + 0x0C);

    while (paneList != paneEnd) {
        void* pane = *paneList;
        if (pane != 0) {
            u32 paneFlags = *(u32*)((u8*)pane + 0x04);
            if (paneFlags & 1) {
                // Draw pane background
                // Draw pane items
            }
        }
        paneList++;
    }
}

// ============================================================================
// Wrapper::AddPane - 0x80086b1c | 360 bytes
// Adds a pane to the wrapper
// ============================================================================
// NON_MATCHING
void Wrapper_AddPane(void* self, void* pane) {
    // Get pane list vector
    void** listEnd = *(void***)((u8*)self + 0x0C);
    void** listCapacity = *(void***)((u8*)self + 0x10);

    if (listEnd != listCapacity) {
        *listEnd = pane;
        *(void***)((u8*)self + 0x0C) = listEnd + 1;
    } else {
        // Grow vector and insert
        void** listStart = *(void***)((u8*)self + 0x08);
        int count = (int)((u8*)listEnd - (u8*)listStart) / 4;
        int newCap = count + 1;
        int newSize = newCap * 4;

        void* newBuf;
        if (newSize > 128) {
            newBuf = operator_new(newSize);
        } else {
            newBuf = SmallBlockAllocator_Alloc(newSize);
        }

        if (listStart != listEnd) {
            memcpy_impl(newBuf, listStart, count * 4);
        }

        // Update pointers
    }
}

// ============================================================================
// __static_initialization_and_destruction_0 - 0x80086d40 | 692 bytes
// Static constructor for wrapper color tables
// ============================================================================
// NON_MATCHING - static initialization of 13 style color entries
void wrapper_static_init(int a, int b) {
    if (b != 0xFFFF) return;
    if (a != 0) return;

    // Initialize style color table (13 entries x 20 bytes = 260 bytes)
    // at global address 0x80485810
    // Copies from rodata color constants:
    //   Style 0: 0x80476280 (default)
    //   Style 1: 0x80476270 (title)
    //   Style 2: 0x804762B0 (subtitle)
    //   Style 3: 0x80476320 (menu)
    //   Style 4: 0x80476310 (button)
    //   Style 5: 0x804762A0 (inactive)
    //   Style 6: 0x80476330 (highlight)
    //   ...
    // Each memset/copy initializes the color table entry
}

// ============================================================================
// WrapperPaneBase::WrapperPaneBase - 0x800878c4 | 284 bytes
// Constructor
// ============================================================================
// NON_MATCHING
void WrapperPaneBase_Ctor(void* self, int width, int height) {
    // Initialize all member fields to defaults
    *(u32*)((u8*)self + 0x00) = 0;    // type
    *(u32*)((u8*)self + 0x04) = 0;    // flags
    *(void**)((u8*)self + 0x08) = 0;  // item list start
    *(void**)((u8*)self + 0x0C) = 0;  // item list end
    *(void**)((u8*)self + 0x10) = 0;  // item list capacity
    *(void**)((u8*)self + 0x18) = 0;  // background shader
    *(float*)((u8*)self + 0x24) = 0.0f; // posX
    *(float*)((u8*)self + 0x28) = 0.0f; // posY
    *(float*)((u8*)self + 0x2C) = (float)width;  // sizeX
    *(float*)((u8*)self + 0x30) = (float)height; // sizeY

    // Clear button slots (0x40-0x5C)
    for (int i = 0; i < 7; i++) {
        *(void**)((u8*)self + 0x40 + i * 4) = 0;
    }
}

// ============================================================================
// WrapperPaneBase::AddItem - 0x80087b70 | 340 bytes
// Adds an item to the pane's item list
// ============================================================================
// NON_MATCHING
void WrapperPaneBase_AddItem(void* self, void* item) {
    // Vector push_back pattern
    void** listEnd = *(void***)((u8*)self + 0x0C);
    void** listCapacity = *(void***)((u8*)self + 0x10);

    if (listEnd != listCapacity) {
        *listEnd = item;
        *(void***)((u8*)self + 0x0C) = listEnd + 1;
    } else {
        // Grow vector (same pattern as AddButton/AddPane)
        void** listStart = *(void***)((u8*)self + 0x08);
        int count = (int)((u8*)listEnd - (u8*)listStart) / 4;
        int newCap = (count == 0) ? 1 : count * 2;
        int newSize = newCap * 4;

        void* newBuf;
        if (newSize > 128) {
            newBuf = operator_new(newSize);
        } else {
            newBuf = SmallBlockAllocator_Alloc(newSize);
        }

        if (listStart != listEnd) {
            memcpy_impl(newBuf, listStart, count * 4);
        }

        // Free old, update pointers, append item
    }
}

// ============================================================================
// DialogPaneBase::DialogPaneBase - 0x80088b6c | 312 bytes
// Constructor for dialog pane
// ============================================================================
// NON_MATCHING
void DialogPaneBase_Ctor(void* self, int width, int height) {
    // Call WrapperPaneBase constructor
    WrapperPaneBase_Ctor(self, width, height);

    // Initialize dialog-specific fields
    *(void**)((u8*)self + 0x60) = 0;   // title item
    *(void**)((u8*)self + 0x64) = 0;   // body item
    *(u32*)((u8*)self + 0x68) = 0;     // state
    *(u32*)((u8*)self + 0x6C) = 0;     // result
    *(u32*)((u8*)self + 0x70) = 0;     // callback
}
