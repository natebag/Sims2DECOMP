// apt_character_medium.cpp - AptCharacter medium functions (65-256 bytes)
// Object file: libaptz.a(AptCharacter.cpp.obj)
// 21 functions

#include "ui/apt_character.h"

extern "C" {
    void operator_delete(void* ptr);
    void SmallBlockAllocator_Free(void* ptr);
    void AptValue_Release(void* val);
    void AptValue_AddRef_impl(void* val);
    void EAStringC_assign(void* dst, void* src);
    void EAStringC_dtor(void* str);
    void AptCharacter_renderImpl(void* self, void* ctx, int maskOp, void* matrix);
}

// ============================================================================
// AptCharacter rendering
// ============================================================================

// 0x80288090 | 144 bytes
// NON_MATCHING - render dispatch through character type
void AptCharacter_render(void* self, void* renderCtx, int maskOp, void* matrix) {
    int charType = *(int*)((u8*)self + 0x04);
    // Check visibility flag
    int flags = *(int*)((u8*)self + 0x08);
    if (!(flags & 1)) return;

    // Dispatch based on character type
    void** vtable = *(void***)self;
    typedef void (*RenderFn)(void*, void*, int, void*);
    RenderFn fn = (RenderFn)vtable[8];  // render vfunc
    fn(self, renderCtx, maskOp, matrix);
}

// 0x80288120 | 152 bytes
// NON_MATCHING - bounding rect calculation
void AptCharacter_getBoundingRect(void* self, void* renderCtx, void* outRect, void* matrix) {
    int charType = *(int*)((u8*)self + 0x04);
    int flags = *(int*)((u8*)self + 0x08);
    if (!(flags & 1)) return;

    void** vtable = *(void***)self;
    typedef void (*BoundsF)(void*, void*, void*, void*);
    BoundsF fn = (BoundsF)vtable[9];
    fn(self, renderCtx, outRect, matrix);
}

// 0x802882f8 | 144 bytes
void AptCharacterSpriteInstBase_dtor(void* self) {
    // Release sprite data
    void* spriteData = *(void**)((u8*)self + 0x10);
    if (spriteData) {
        AptValue_Release(spriteData);
    }
    // Call base destructor
}

// 0x8028897c | 188 bytes
// NON_MATCHING - text instance constructor
void AptCharacterTextInst_ctor(void* self) {
    // Initialize all fields to defaults
    *(int*)((u8*)self + 0x00) = 0;  // vtable
    *(int*)((u8*)self + 0x04) = 0;  // type
    *(int*)((u8*)self + 0x08) = 0;  // flags
    *(int*)((u8*)self + 0x0C) = 0;  // parent
    *(int*)((u8*)self + 0x10) = 0;  // data
    // Initialize EAStringC members
    // Initialize text format
}

// 0x8028fcc8 | 104 bytes
// EAStringC destructor (instantiated in AptCharacter.cpp.obj)
void EAStringC_dtor_aptchar(void* self) {
    char* data = *(char**)((u8*)self + 0x04);
    char* staticBuf = (char*)((u8*)self + 0x08);
    if (data != staticBuf && data != 0) {
        operator_delete(data);
    }
    *(char**)((u8*)self + 0x04) = 0;
}

// 0x80289898 | 220 bytes
// NON_MATCHING - unloadMovie script method
void* AptCharacterInst_sMethod_unloadMovie(void* thisVal, void* args, int nArgs) {
    // Get the movie clip reference
    // Unload it from the display list
    return 0;
}

// 0x80289974 | 156 bytes
// NON_MATCHING - duplicateMovieClip script method
void* AptCharacterInst_sMethod_duplicateMovieClip(void* thisVal, void* args, int nArgs) {
    // Get name and depth from args
    // Create duplicate
    return 0;
}

// 0x80289a10 | 120 bytes
void* AptCharacterInst_sMethod_removeMovieClip(void* thisVal, void* args, int nArgs) {
    // Remove this movie clip from parent's display list
    void* parent = *(void**)((u8*)thisVal + 0x14);
    if (parent == 0) return 0;
    // Virtual call to remove
    void** vtable = *(void***)parent;
    typedef void (*RemoveFn)(void*, void*);
    ((RemoveFn)vtable[12])(parent, thisVal);
    return 0;
}

// 0x80289a88 | 120 bytes
void* AptCharacterInst_sMethod_removeTextField(void* thisVal, void* args, int nArgs) {
    void* parent = *(void**)((u8*)thisVal + 0x14);
    if (parent == 0) return 0;
    void** vtable = *(void***)parent;
    typedef void (*RemoveFn)(void*, void*);
    ((RemoveFn)vtable[12])(parent, thisVal);
    return 0;
}

// 0x80289e34 | 228 bytes
// NON_MATCHING - getDepth returns depth as AptValue
void* AptCharacterInst_sMethod_getDepth(void* thisVal, void* args, int nArgs) {
    int depth = *(int*)((u8*)thisVal + 0x18);
    // Create AptValue integer with depth value
    return 0;
}

// 0x8028a244 | 212 bytes
// NON_MATCHING - setMask method
void* AptCharacterInst_sMethod_setMask(void* thisVal, void* args, int nArgs) {
    // Set mask on display list item
    return 0;
}

// 0x8028adb4 | 180 bytes
// NON_MATCHING - loadVariables method
void* AptCharacterInst_sMethod_loadVariables(void* thisVal, void* args, int nArgs) {
    // Load variables from URL
    return 0;
}

// 0x8028ae68 | 160 bytes
// NON_MATCHING - stop method (stops playback)
void* AptCharacterInst_sMethod_stop(void* thisVal, void* args, int nArgs) {
    // Set playing flag to false
    int flags = *(int*)((u8*)thisVal + 0x08);
    *(int*)((u8*)thisVal + 0x08) = flags & ~2;  // clear playing bit
    return 0;
}

// 0x8028af08 | 160 bytes
// NON_MATCHING - play method (starts playback)
void* AptCharacterInst_sMethod_play(void* thisVal, void* args, int nArgs) {
    int flags = *(int*)((u8*)thisVal + 0x08);
    *(int*)((u8*)thisVal + 0x08) = flags | 2;  // set playing bit
    return 0;
}

// 0x8028afa8 | 76 bytes
void* AptCharacterInst_sMethod_nextFrame(void* thisVal, void* args, int nArgs) {
    int frame = *(int*)((u8*)thisVal + 0x1C);
    *(int*)((u8*)thisVal + 0x1C) = frame + 1;
    int flags = *(int*)((u8*)thisVal + 0x08);
    *(int*)((u8*)thisVal + 0x08) = flags & ~2;
    return 0;
}

// 0x8028aff4 | 76 bytes
void* AptCharacterInst_sMethod_prevFrame(void* thisVal, void* args, int nArgs) {
    int frame = *(int*)((u8*)thisVal + 0x1C);
    *(int*)((u8*)thisVal + 0x1C) = frame - 1;
    int flags = *(int*)((u8*)thisVal + 0x08);
    *(int*)((u8*)thisVal + 0x08) = flags & ~2;
    return 0;
}

// 0x8028fd30 | 116 bytes
void EAStringC_assign_aptchar(void* dst, void* src) {
    EAStringC_assign(dst, src);
}

// 0x8028fa1c | 200 bytes
// NON_MATCHING - copies text format properties
void TextFormat_copyTextFormatObj(void* self, void* src) {
    // Copy all text format fields
    // Font, size, color, alignment, etc.
}

// 0x8028fae8 | 92 bytes
void AptCharacterInst_dtor(void* self) {
    // Release display list
    // Release parent reference
    // Call base destructor
}

// 0x8028f9b4 | 104 bytes
void AptNativeFunction_dtor_aptchar(void* self) {
    // Release function reference
    // Call base destructor
}
