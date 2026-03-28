// apt_display_medium.cpp - AptDisplayList medium functions (65-256 bytes)
// Object file: libaptz.a(AptDisplayList.cpp.obj)
// 30 functions

#include "ui/apt_display.h"

extern "C" {
    void operator_delete(void* ptr);
    void SmallBlockAllocator_Free(void* ptr);
    void AptValue_Release(void* val);
    void AptValue_AddRef_impl(void* val);
    void EAStringC_dtor(void* str);
}

// ============================================================================
// AptPseudoData_t - pseudo display list data node
// ============================================================================

// 0x80298f64 | 132 bytes
void AptPseudoData_ctor(void* self, void* control, int depth, void* character) {
    *(void**)((u8*)self + 0x00) = control;
    *(int*)((u8*)self + 0x04) = depth;
    *(void**)((u8*)self + 0x08) = character;
    *(void**)((u8*)self + 0x0C) = 0;  // next
    *(void**)((u8*)self + 0x10) = 0;  // prev
    *(int*)((u8*)self + 0x14) = 0;    // flags
    if (character) AptValue_AddRef_impl(character);
}

// 0x80298fe8 | 140 bytes
void AptPseudoCIH_ctor(void* self, void* control, int charIdx, int depth, void* character) {
    *(void**)((u8*)self + 0x00) = control;
    *(int*)((u8*)self + 0x04) = charIdx;
    *(int*)((u8*)self + 0x08) = depth;
    *(void**)((u8*)self + 0x0C) = character;
    *(void**)((u8*)self + 0x10) = 0;  // next
    *(void**)((u8*)self + 0x14) = 0;  // prev
    *(int*)((u8*)self + 0x18) = 0;    // flags
    if (character) AptValue_AddRef_impl(character);
}

// 0x80299074 | 140 bytes
void AptPseudoDisplayList_ClearList(void* self) {
    // Walk linked list and free all nodes
    void* node = *(void**)((u8*)self + 0x00);
    while (node != 0) {
        void* next = *(void**)((u8*)node + 0x10);
        void* character = *(void**)((u8*)node + 0x0C);
        if (character) AptValue_Release(character);
        // Free node
        u32 size = 0x1C;
        if (size > 128) { operator_delete(node); } else { SmallBlockAllocator_Free(node); }
        node = next;
    }
    *(void**)((u8*)self + 0x00) = 0;  // head = null
    *(void**)((u8*)self + 0x04) = 0;  // tail = null
    *(int*)((u8*)self + 0x08) = 0;    // count = 0
}

// 0x80299100 | 80 bytes
void* AptPseudoDisplayList_FindInst(void* self, int depth, void** outPrev, void** outNext) {
    void* node = *(void**)((u8*)self + 0x00);
    while (node != 0) {
        int nodeDepth = *(int*)((u8*)node + 0x08);
        if (nodeDepth == depth) {
            if (outPrev) *outPrev = *(void**)((u8*)node + 0x14);
            if (outNext) *outNext = *(void**)((u8*)node + 0x10);
            return node;
        }
        node = *(void**)((u8*)node + 0x10);
    }
    return 0;
}

// 0x80299150 | 144 bytes
void AptPseudoDisplayList_Insert(void* self, void* newNode) {
    int depth = *(int*)((u8*)newNode + 0x08);
    void* cur = *(void**)((u8*)self + 0x00);
    void* prev = 0;
    // Find insertion point (sorted by depth)
    while (cur != 0) {
        int curDepth = *(int*)((u8*)cur + 0x08);
        if (curDepth > depth) break;
        prev = cur;
        cur = *(void**)((u8*)cur + 0x10);
    }
    // Insert between prev and cur
    *(void**)((u8*)newNode + 0x14) = prev;
    *(void**)((u8*)newNode + 0x10) = cur;
    if (prev) *(void**)((u8*)prev + 0x10) = newNode;
    else *(void**)((u8*)self + 0x00) = newNode;
    if (cur) *(void**)((u8*)cur + 0x14) = newNode;
    else *(void**)((u8*)self + 0x04) = newNode;
    int count = *(int*)((u8*)self + 0x08);
    *(int*)((u8*)self + 0x08) = count + 1;
}

// 0x802992a4 | 156 bytes
void AptPseudoDisplayList_Remove(void* self, void* node) {
    if (node == 0) return;
    void* prev = *(void**)((u8*)node + 0x14);
    void* next = *(void**)((u8*)node + 0x10);
    if (prev) *(void**)((u8*)prev + 0x10) = next;
    else *(void**)((u8*)self + 0x00) = next;
    if (next) *(void**)((u8*)next + 0x14) = prev;
    else *(void**)((u8*)self + 0x04) = prev;
    void* character = *(void**)((u8*)node + 0x0C);
    if (character) AptValue_Release(character);
    u32 size = 0x1C;
    if (size > 128) { operator_delete(node); } else { SmallBlockAllocator_Free(node); }
    int count = *(int*)((u8*)self + 0x08);
    *(int*)((u8*)self + 0x08) = count - 1;
}

// 0x802991e0 | 96 bytes
void AptPseudoDisplayList_InsertBetween(void* self, void* newNode, void* prev, void* next) {
    *(void**)((u8*)newNode + 0x14) = prev;
    *(void**)((u8*)newNode + 0x10) = next;
    if (prev) *(void**)((u8*)prev + 0x10) = newNode;
    else *(void**)((u8*)self + 0x00) = newNode;
    if (next) *(void**)((u8*)next + 0x14) = newNode;
    else *(void**)((u8*)self + 0x04) = newNode;
    int count = *(int*)((u8*)self + 0x08);
    *(int*)((u8*)self + 0x08) = count + 1;
}

// 0x802994a4 | 92 bytes
void AptDisplayListState_RegisterReferences(void* self, void* aptVal) {
    // Walk display items and register references
    void* item = *(void**)((u8*)self + 0x00);
    while (item != 0) {
        void* character = *(void**)((u8*)item + 0x0C);
        if (character) AptValue_AddRef_impl(character);
        item = *(void**)((u8*)item + 0x10);
    }
}

// 0x80299500 | 256 bytes
// NON_MATCHING - inserts CIH into display list state
void AptDisplayListState_insert(void* self, void* cih, void* afterCih) {
    // Complex insertion with depth sorting
    // Handles replacement of existing items at same depth
}

// 0x8029985c | 96 bytes
void AptDisplayListState_insertAtDepth(void* self, int depth, void* cih) {
    // Insert at specific depth
    AptDisplayListState_insert(self, cih, 0);
}

// 0x8029ae18 | 172 bytes
void AptDisplayList_removeObject(void* self, void* cih) {
    // Find and remove object from display list
    void* node = *(void**)((u8*)self + 0x00);
    while (node != 0) {
        void* next = *(void**)((u8*)node + 0x10);
        void* nodeCih = *(void**)((u8*)node + 0x0C);
        if (nodeCih == cih) {
            AptPseudoDisplayList_Remove(self, node);
            return;
        }
        node = next;
    }
}

// 0x8029a2e4 | 196 bytes
// NON_MATCHING - place object with color transform
void AptDisplayList_placeObjectNCXForm(void* self, void* cih, int depth, void* character,
    void* name, void* afterCih, int replaceFlag, int flag2, void* cxform, void* matrix,
    void* eventActions, float ratio) {
    // Complex placement logic with matrix and color transform
}

// 0x8029aec4 | 72 bytes
void AptDisplayList_removeObjectByDepth(void* self, int depth) {
    void* found = 0;
    void* node = *(void**)((u8*)self + 0x00);
    while (node != 0) {
        int nodeDepth = *(int*)((u8*)node + 0x08);
        if (nodeDepth == depth) {
            found = node;
            break;
        }
        node = *(void**)((u8*)node + 0x10);
    }
    if (found) AptPseudoDisplayList_Remove(self, found);
}

// 0x8029af30 | 92 bytes
void AptDisplayList_removeClonedObject(void* self, void* cih) {
    // Remove cloned object and clean up
    AptDisplayList_removeObject(self, cih);
    if (cih) AptValue_Release(cih);
}

// 0x8029afcc | 88 bytes
void AptDisplayList_dtor(void* self) {
    AptPseudoDisplayList_ClearList(self);
    // Clear state
    *(void**)((u8*)self + 0x00) = 0;
    *(void**)((u8*)self + 0x04) = 0;
    *(int*)((u8*)self + 0x08) = 0;
}

// 0x8029c34c | 108 bytes
void AptDisplayListState_dtor(void* self) {
    // Release all items in state
    void* item = *(void**)((u8*)self + 0x00);
    while (item != 0) {
        void* next = *(void**)((u8*)item + 0x10);
        void* character = *(void**)((u8*)item + 0x0C);
        if (character) AptValue_Release(character);
        SmallBlockAllocator_Free(item);
        item = next;
    }
}

// 0x8029b024 | 176 bytes
// NON_MATCHING - renders a character instance
void _drawCharacterInst(void* renderCtx, void* cih, int maskOp) {
    // Get character from CIH
    // Apply matrix and color transform
    // Call character's render method
}

// 0x8029b450 | 84 bytes
void AptDisplayList_deallocAssetStringRecursive(void* self) {
    void* node = *(void**)((u8*)self + 0x00);
    while (node != 0) {
        void* next = *(void**)((u8*)node + 0x10);
        // Release asset string if present
        void* assetStr = *(void**)((u8*)node + 0x1C);
        if (assetStr) {
            EAStringC_dtor(assetStr);
            *(void**)((u8*)node + 0x1C) = 0;
        }
        node = next;
    }
}

// 0x8029b718 | 164 bytes
// NON_MATCHING - bounding rect of entire display list
void AptDisplayList_getBoundingRect(void* self, void* renderCtx, void* outRect) {
    // Initialize rect to empty
    // Walk all display items and union their bounding rects
}

// 0x8029b7bc | 224 bytes
// NON_MATCHING - tick all items in display list
void AptDisplayList_tick(void* self) {
    // Walk display items in depth order
    // Call tick on each character instance
    // Handle removed items
}

// 0x8029b9a0 | 76 bytes
void AptDisplayList_PreDestroy(void* self) {
    // Walk display items and call PreDestroy on each
    void* node = *(void**)((u8*)self + 0x00);
    while (node != 0) {
        void* next = *(void**)((u8*)node + 0x10);
        void* character = *(void**)((u8*)node + 0x0C);
        if (character) {
            void** vtable = *(void***)character;
            typedef void (*PreDestroyFn)(void*);
            ((PreDestroyFn)vtable[4])(character);
        }
        node = next;
    }
}

// 0x8029ba20 | 240 bytes
// NON_MATCHING - add to display list from native hash
void AptDisplayList_AddToDisplayList(void* self, void* nativeHash, void* pseudoCih, void* cih) {
    // Look up in hash, create character instance, add to list
}

// 0x8029bb10 | 208 bytes
// NON_MATCHING - replace display list item
void AptDisplayList_ReplaceDisplayListItem(void* self, void* nativeHash, void* cih,
    void* pseudoCih, void* newCih) {
    // Find existing item, replace with new character
}

// 0x8029c12c | 88 bytes
int AptDisplayListState_hasRenderData(void* self) {
    void* item = *(void**)((u8*)self + 0x00);
    while (item != 0) {
        int flags = *(int*)((u8*)item + 0x14);
        if (flags & 1) return 1;  // has render data
        item = *(void**)((u8*)item + 0x10);
    }
    return 0;
}

// 0x8029c184 | 76 bytes
void AptDisplayListState_GetMovieclipInfo(void* self, void* outInfo) {
    // Copy movieclip information to output struct
    void* data = *(void**)((u8*)self + 0x04);
    if (data) {
        *(int*)((u8*)outInfo + 0x00) = *(int*)((u8*)data + 0x00);
        *(int*)((u8*)outInfo + 0x04) = *(int*)((u8*)data + 0x04);
    }
}

// ============================================================================
// Character instance destructors
// ============================================================================

// 0x8029c588 | 76 bytes
void AptCharacterSpriteInst_dtor(void* self) {
    void* spriteData = *(void**)((u8*)self + 0x10);
    if (spriteData) AptValue_Release(spriteData);
}

// 0x8029c524 | 100 bytes
void AptCharacterMorphInst_dtor(void* self) {
    void* morphData = *(void**)((u8*)self + 0x10);
    if (morphData) AptValue_Release(morphData);
    // Call base dtor
}

// 0x8029c4c0 | 100 bytes
void AptCharacterStaticTextInst_dtor(void* self) {
    void* textData = *(void**)((u8*)self + 0x10);
    if (textData) AptValue_Release(textData);
    // Call base dtor
}

// 0x8029c45c | 100 bytes
void AptCharacterShapeInst_dtor(void* self) {
    void* shapeData = *(void**)((u8*)self + 0x10);
    if (shapeData) AptValue_Release(shapeData);
    // Call base dtor
}

// 0x8029c5f4 | 92 bytes
void AptCharacterInst_dtor_display(void* self) {
    // Release display list
    void* displayList = *(void**)((u8*)self + 0x18);
    if (displayList) AptValue_Release(displayList);
    // Call base dtor
}
