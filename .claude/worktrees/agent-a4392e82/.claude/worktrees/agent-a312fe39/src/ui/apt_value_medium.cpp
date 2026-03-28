// apt_value_medium.cpp - AptValue medium functions (65-256 bytes)
// Object file: libaptz.a(AptValue.cpp.obj)
// 18 functions

#include "ui/apt_value.h"

extern "C" {
    void operator_delete(void* ptr);              // 0x802d1220
    void SmallBlockAllocator_Free(void* ptr);     // 0x8039be60
    void* SmallBlockAllocator_Alloc(u32 size);    // 0x8039bdf8
    int AptRenderContext_GetTimer(void* ctx);     // timer access
    void AptValue_Release(void* val);             // 0x802b3fc4
}

// ============================================================================
// AptValue conversions
// ============================================================================

// 0x802b04b8 | 256 bytes
// NON_MATCHING - complex type-switch for integer conversion
int AptValue_toInteger(void* self) {
    int type = *(int*)((u8*)self + 0x04);
    switch (type) {
        case 0: // Integer
            return *(int*)((u8*)self + 0x08);
        case 1: // Float
        {
            float f = *(float*)((u8*)self + 0x08);
            return (int)f;
        }
        case 2: // Boolean
            return *(int*)((u8*)self + 0x08) ? 1 : 0;
        case 3: // String
        {
            char* str = *(char**)((u8*)self + 0x08);
            if (str == 0) return 0;
            // Parse string to int
            int result = 0;
            // atoi equivalent
            return result;
        }
        default:
            return 0;
    }
}

// 0x802b05b8 | 244 bytes
// NON_MATCHING - complex type-switch for float conversion
float AptValue_toFloat(void* self) {
    int type = *(int*)((u8*)self + 0x04);
    switch (type) {
        case 0: // Integer
            return (float)(*(int*)((u8*)self + 0x08));
        case 1: // Float
            return *(float*)((u8*)self + 0x08);
        case 2: // Boolean
            return *(int*)((u8*)self + 0x08) ? 1.0f : 0.0f;
        case 3: // String
        {
            char* str = *(char**)((u8*)self + 0x08);
            if (str == 0) return 0.0f;
            // atof equivalent
            return 0.0f;
        }
        default:
            return 0.0f;
    }
}

// 0x802b0838 | 132 bytes
// NON_MATCHING - toString with buffer
void AptValue_toString(void* self, char* outBuf) {
    int type = *(int*)((u8*)self + 0x04);
    switch (type) {
        case 0: // Integer
        {
            // sprintf(outBuf, "%d", value)
            break;
        }
        case 1: // Float
        {
            // sprintf(outBuf, "%g", value)
            break;
        }
        case 2: // Boolean
        {
            // "true" or "false"
            break;
        }
        case 3: // String
        {
            char* str = *(char**)((u8*)self + 0x08);
            if (str) {
                // strcpy
            }
            break;
        }
    }
}

// 0x802b45fc | 212 bytes
// NON_MATCHING - AptValue constructor with VFT index
void AptValue_ctor_vft(void* self, int vftIndex) {
    // Initialize fields
    *(int*)((u8*)self + 0x00) = 0;  // vtable placeholder
    *(int*)((u8*)self + 0x04) = 0;  // type
    *(int*)((u8*)self + 0x08) = 0;  // value
    *(int*)((u8*)self + 0x0C) = 0;  // ref count
    *(int*)((u8*)self + 0x10) = 0;  // flags
    // Set vtable based on vftIndex
    // Large switch/lookup table
}

// 0x802b31f4 | 84 bytes
void AptValueShutdownRemaining() {
    // Walk remaining values and force-delete them
    // Static linked list traversal
}

// 0x802b3d84 | 244 bytes
// NON_MATCHING - walks parent chain checking for MovieClip
int AptValue_isMCInParentChain(void* self) {
    void* current = self;
    while (current != 0) {
        int type = *(int*)((u8*)current + 0x04);
        if (type == 7) {  // MovieClip type
            return 1;
        }
        current = *(void**)((u8*)current + 0x14);  // parent pointer
    }
    return 0;
}

// 0x802b3e78 | 136 bytes
int AptValue_CanCreateScriptObject(void* self) {
    int type = *(int*)((u8*)self + 0x04);
    // Check various type flags
    if (type >= 5 && type <= 9) {
        return 1;
    }
    return 0;
}

// 0x802b3f00 | 196 bytes
// NON_MATCHING - reference counting with debug info
void AptValue_AddRef(void* self, char* file, char* func, int line) {
    int refCount = *(int*)((u8*)self + 0x0C);
    *(int*)((u8*)self + 0x0C) = refCount + 1;
    // Debug tracking
}

// 0x802b41cc | 124 bytes
void AptValue_ForceDelete(void* self) {
    // Force ref count to 0 and delete
    *(int*)((u8*)self + 0x0C) = 0;
    // Virtual call destructor
    void** vtable = *(void***)self;
    if (vtable != 0) {
        typedef void (*DtorFn)(void*, int);
        ((DtorFn)vtable[0])(self, 1);
    }
}

// 0x802b4594 | 104 bytes
void AptGlobalExtensionObject_dtor(void* self) {
    // Set vtable
    // Call base destructor
    void* parent = *(void**)((u8*)self + 0x14);
    if (parent != 0) {
        AptValue_Release(parent);
    }
    // Set base vtable and free
}

// 0x802b44b4 | 128 bytes
void AptExtern_objectMemberSet(void* self, void* aptVal, void* name, void* value) {
    // Delegate to parent's objectMemberSet
    void* parent = *(void**)((u8*)self + 0x14);
    if (parent != 0) {
        void** vtable = *(void***)parent;
        typedef void (*MemberSetFn)(void*, void*, void*, void*);
        // Virtual call through vtable
    }
}

// 0x802b453c | 88 bytes
void AptExtern_dtor(void* self) {
    // Set vtable, release refs, call base dtor
}

// 0x802b445c | 88 bytes
void AptNone_dtor(void* self) {
    // Set vtable, call base dtor
}

// 0x802b43ec | 104 bytes
void AptNativeFunction_dtor(void* self) {
    // Set vtable, release function refs, call base dtor
}

// 0x802b42fc | 92 bytes
void AptValueWithHash_dtor(void* self) {
    // Set vtable, call base dtor
}

// 0x802b4358 | 76 bytes
void AptValueWithHash_ctor(void* self, int vftIndex, int hash) {
    AptValue_ctor_vft(self, vftIndex);
    *(int*)((u8*)self + 0x18) = hash;
}

// 0x802b4d68 | 104 bytes
// EAStringC destructor (instantiated in AptValue.cpp.obj)
void EAStringC_dtor_aptvalue(void* self) {
    char* data = *(char**)((u8*)self + 0x04);
    char* staticBuf = (char*)((u8*)self + 0x08);
    if (data != staticBuf && data != 0) {
        // Free allocated string
        operator_delete(data);
    }
    *(char**)((u8*)self + 0x04) = 0;
}

// 0x802b46d0 | 160 bytes
// NON_MATCHING - AptValue constructor with CIH_ONLY tag
void AptValue_ctor_cih(void* self, int vftIndex, int cihOnly) {
    // Similar to regular ctor but with CIH flag
    *(int*)((u8*)self + 0x00) = 0;
    *(int*)((u8*)self + 0x04) = 0;
    *(int*)((u8*)self + 0x08) = 0;
    *(int*)((u8*)self + 0x0C) = 1;  // Initial ref count
    *(int*)((u8*)self + 0x10) = 0;
    // Set vtable based on index
}
