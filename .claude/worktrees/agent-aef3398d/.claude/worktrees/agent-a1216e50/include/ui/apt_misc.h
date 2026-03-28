#ifndef APT_MISC_H
#define APT_MISC_H

#include "types.h"
#include "ui/apt_value.h"

// Forward declarations
class AptCIH;
struct AptMatrix;
struct AptInputType;
struct AptInputState;
struct AptInputController;
class AptCharacterButton;

// ============================================================================
// AptMovie - movie clip definition (frame controls, labels, etc.)
// Layout (partial):
//   0x08: AptNativeHash* m_labelHash
// ============================================================================
class AptMovie {
public:
    u32 m_pad00;         // 0x00
    u32 m_pad04;         // 0x04
    void* m_labelHash;   // 0x08 - AptNativeHash for frame labels

    void resolve(u8* data, void* constFile, int* offset);
    void unresolve(u8* data, int* offset);
    void DoTemporaryFrameControls(void* pseudoDisplayList, int frame);
    void doFrameControls(void* displayList, AptCIH* cih, int frame);
    void runFrameActions(AptCIH* cih, int frame);
    void queueFrameActions(AptCIH* cih, int frame);
    int labelToFrame(EAStringC* label);
};

// ============================================================================
// AptAnimationPoolData - animation pool with input handling
// Layout (partial):
//   0x98: void* m_actionPool
// ============================================================================
class AptAnimationPoolData {
public:
    void* GetActionPool();
    int validateBIL();
    void _doButtonActions(AptCIH* cih, int actions);
    void setValidFocusButton();
    void ProcessInputs();
    void ProcessAptInput(u32 input, bool flag);
};

// ============================================================================
// AptMath - math utilities for APT clip stack
// ============================================================================
class AptMath {
public:
    static void ClipStackMakeUnit();
    static void ClipStackPushUnit();
    static void ClipStackInit(u32 size);
    static void ClipStackShutdown();
};

// ============================================================================
// AptGC - garbage collector for APT values
// ============================================================================
class AptGC {
public:
    static void Initialize();
    static void sReferenceRegistrationCb(AptValue* a, AptValue* b, char* name);
    static void CleanUnreachable();
    static void CleanAll();
};

// ============================================================================
// AptString - ActionScript string object
// AptString does NOT use the full AptValue layout - only the first 12 bytes.
// Layout:
//   0x00: u32 m_flags
//   0x04: u32 m_data
//   0x08: AptValueVTableDesc* m_vtableDesc
//   0x0C: EAStringC m_string (4 bytes - pointer to internal data)
//   0x10: AptString* m_next (linked list pointer)
// Total size: 0x14 (20 bytes)
// ============================================================================
class AptString {
public:
    u32 m_flags;                        // 0x00
    u32 m_data;                         // 0x04
    void* m_vtableDesc;                 // 0x08
    EAStringC m_string;                 // 0x0C
    AptString* m_next;                  // 0x10

    AptString();
    AptString(char* str);
    ~AptString();
    void DeleteThis();
    void ForceDelete();
    void CleanNativeFunctions();

    // ActionScript method dispatchers
    static AptValue* sMethod_charAt(AptValue* thisObj, int argc);
    static AptValue* sMethod_charCodeAt(AptValue* thisObj, int argc);
    static AptValue* sMethod_concat(AptValue* thisObj, int argc);
    static AptValue* sMethod_fromCharCode(AptValue* thisObj, int argc);
    static AptValue* sMethod_indexOf(AptValue* thisObj, int argc);
    static AptValue* sMethod_lastIndexOf(AptValue* thisObj, int argc);
    static AptValue* sMethod_slice(AptValue* thisObj, int argc);
    static AptValue* sMethod_split(AptValue* thisObj, int argc);
    static AptValue* sMethod_substr(AptValue* thisObj, int argc);
    static AptValue* sMethod_substring(AptValue* thisObj, int argc);
    static AptValue* sMethod_toLowerCase(AptValue* thisObj, int argc);
    static AptValue* sMethod_toUpperCase(AptValue* thisObj, int argc);
    AptValue* objectMemberLookup(AptValue* obj, EAStringC* name) const;

    static AptString* Create(char* str);
    static AptString* Create();
    void Destroy();
    AptValue* printf(char* fmt, ...);

    // String operations
    void cpy(EAStringC* src);
    void cpy(char* src);
    void cat(EAStringC* src);
    void cat(char* src);
    EAStringC* GetInternalString();
    void SetNext(AptString* next);
    AptString* GetNext() const;

    // Memory management
    void* operator new(unsigned int size);
    void operator delete(void* ptr, unsigned int size);
    void* operator new[](unsigned int size);
    void operator delete[](void* ptr);
};

// ============================================================================
// AptBoolean - ActionScript boolean value
// Layout:
//   0x00: u32 m_flags
//   0x04: u32 m_data
//   0x08: void* m_vtableDesc
//   0x0C: u32 m_boolValue / AptBoolean* m_freeListNext
// ============================================================================
class AptBoolean {
public:
    u32 m_flags;           // 0x00
    u32 m_data;            // 0x04
    void* m_vtableDesc;    // 0x08
    u32 m_value;           // 0x0C - bool value or free list next pointer

    void DeleteThis();
    void ForceDelete();
    void Destroy();
    u32 GetBool() const;

    void* operator new(unsigned int size);
    void operator delete(void* ptr, unsigned int size);
    void* operator new[](unsigned int size);
    void operator delete[](void* ptr);
};

// ============================================================================
// AptFloat - ActionScript float value
// Layout:
//   0x00: u32 m_flags
//   0x04: u32 m_data
//   0x08: void* m_vtableDesc
//   0x0C: float m_floatValue / AptFloat* m_freeListNext
// ============================================================================
class AptFloat {
public:
    u32 m_flags;           // 0x00
    u32 m_data;            // 0x04
    void* m_vtableDesc;    // 0x08
    float m_value;         // 0x0C - float value or free list next pointer (as u32)

    void DeleteThis();
    void ForceDelete();
    void Destroy();
    float GetFloat() const;

    void* operator new(unsigned int size);
    void operator delete(void* ptr, unsigned int size);
    void* operator new[](unsigned int size);
    void operator delete[](void* ptr);
};

// ============================================================================
// AptInteger - ActionScript integer value
// Layout:
//   0x00: u32 m_flags
//   0x04: u32 m_data
//   0x08: void* m_vtableDesc
//   0x0C: int m_intValue / AptInteger* m_freeListNext
// ============================================================================
class AptInteger {
public:
    u32 m_flags;           // 0x00
    u32 m_data;            // 0x04
    void* m_vtableDesc;    // 0x08
    int m_value;           // 0x0C - int value or free list next pointer

    void DeleteThis();
    void ForceDelete();
    void Destroy();
    int GetInt() const;

    void* operator new(unsigned int size);
    void operator delete(void* ptr, unsigned int size);
    void* operator new[](unsigned int size);
    void operator delete[](void* ptr);
};

// ============================================================================
// AptRand - Mersenne Twister random number generator
// ============================================================================

// Mersenne Twister state (624 u32s)
#define MT_N 624

extern "C" {
    void _randReloadMersenneTwister();
    void AptSeedRand(u32 seed);
    u32 AptRand();
}

#endif // APT_MISC_H
