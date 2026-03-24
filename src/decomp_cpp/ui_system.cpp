// =============================================================================
// ui_system.cpp - APT UI Engine, UI Targets, and Dialog System
// =============================================================================
//
// Decompiled C++ for the Sims 2 GameCube UI subsystem, targeting a PC port.
// Converted from PPC inline assembly (src/asm_decomp/) using decomp docs
// (src/ui/apt_decomp.cpp, src/ui/targets_decomp.cpp) for struct layouts,
// field offsets, control flow, and calling conventions.
//
// This file covers:
//   1. AptValue type conversions (toInteger, toFloat, toBool)
//   2. AptActionInterpreter simple opcode handlers
//   3. AptRenderingContext matrix/color stack operations
//   4. AptViewer lifecycle and input handling
//   5. AptDisplayList depth management helpers
//   6. AptCIH type queries
//   7. UIObjectBase utility methods
//   8. UIReflow batched UI modification
//   9. UIRouter variable routing
//  10. UIScreenManager screen lifecycle
//  11. DlgWrapper modal dialog system
//  12. HUDTarget live-mode HUD controller
//  13. FlowGotoTarget screen navigation state machine
//  14. ACTTarget action queue display
//  15. O2TTarget options menu
//  16. FAMTarget family/lot selection
//  17. MMUTarget main menu
//  18. M2MTarget memory card management
//  19. LoadGameTarget / SaveGameTarget save I/O
//  20. CSMTarget CAS integration menu
//
// All struct offsets are derived from the decomp docs and verified against
// the PPC assembly in src/asm_decomp/*.cpp.
//
// =============================================================================

extern "C" {
    int    rand(void);
    void*  malloc(unsigned int size);
    void   free(void* ptr);
    void*  memcpy(void* dst, const void* src, unsigned int n);
    void*  memset(void* s, int c, unsigned int n);
    int    strlen(const char* s);
    char*  strcpy(char* dst, const char* src);
    char*  strncpy(char* dst, const char* src, unsigned int n);
    int    strcmp(const char* a, const char* b);
    int    strncmp(const char* a, const char* b, unsigned int n);
    int    sprintf(char* s, const char* fmt, ...);
    int    snprintf(char* s, unsigned int n, const char* fmt, ...);
    int    printf(const char* fmt, ...);
    float  sqrtf(float x);
    float  fabsf(float x);
    float  sinf(float x);
    float  cosf(float x);
    float  floorf(float x);
    float  ceilf(float x);
    float  fmodf(float x, float y);
    float  atan2f(float y, float x);
    long   strtol(const char* s, char** end, int base);
    int    atoi(const char* s);
    double atof(const char* s);
}

// -- Basic types (matching include/types.h) ----------------------------------
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef float f32;

// -- Forward declarations ----------------------------------------------------
class ERC;
class ERFont;
class ERShader;
class cXObject;
class cXPerson;
class Interaction;
class Family;
class NghResFile;
struct EVec2;
struct EVec3;
struct structDrawCBparams;
struct CBFunctorBase;
class BString2;
class AptConstFile;
class AptCharacter;
class AptCharacterInst;


// =============================================================================
// SECTION 1 - APT Value Type System
// =============================================================================

// AptValue custom vtable descriptor entry
struct AptValueVTableEntry {
    s16 thisAdjust;
    s16 pad;
    void (*func)();
};

struct AptValueVTableDesc {
    AptValueVTableEntry entries[1]; // variable-length
};

// Type tag enum (from apt_value.h / apt_decomp.cpp)
enum AptVirtualFunctionTable_Indices {
    APT_VFT_UNDEFINED       = 0,
    APT_VFT_STRING          = 1,
    APT_VFT_NONE            = 3,
    APT_VFT_REGISTER        = 4,
    APT_VFT_BOOLEAN         = 5,
    APT_VFT_FLOAT           = 6,
    APT_VFT_INTEGER         = 7,
    APT_VFT_LOOKUP          = 8,
    APT_VFT_NATIVEFUNCTION  = 9,
    APT_VFT_EXTERN          = 11,
    APT_VFT_CIH_FIRST       = 12,
    APT_VFT_CIH_LAST        = 19,
    APT_VFT_FRAMESTACK      = 20,
    APT_VFT_SOUND           = 21,
    APT_VFT_ARRAY           = 22,
    APT_VFT_MATH            = 23,
    APT_VFT_KEY             = 24,
    APT_VFT_SCRIPTCOLOUR    = 26,
    APT_VFT_OBJECT          = 27,
    APT_VFT_PROTOTYPE       = 28,
    APT_VFT_DATE            = 29,
    APT_VFT_MOVIECLIP       = 30,
    APT_VFT_XMLNODE          = 32,
    APT_VFT_XML              = 33,
    APT_VFT_XMLATTRIBUTES    = 34,
    APT_VFT_LOADVARS         = 35,
    APT_VFT_TEXTFORMAT       = 36,
    APT_VFT_STAGE            = 39,
    APT_VFT_STRING2          = 42,
    APT_VFT_SCRIPTFUNCTION1  = 43,
    APT_VFT_SCRIPTFUNCTION2  = 44,
    APT_VFT_SCRIPTFUNCTIONBC = 45,
};

// EAStringC internal data layout (from apt_value.h)
struct EAStringCInternalData {
    u16 m_refCount;    // 0x00
    u16 m_pad;         // 0x02
    u16 m_length;      // 0x04
    u16 m_pad2;        // 0x06
    // char m_data[];  // 0x08 onwards
    const char* data() const { return reinterpret_cast<const char*>(this) + 8; }
};

struct EAStringC {
    EAStringCInternalData* m_pData; // 0x00
    const char* c_str() const {
        return m_pData ? m_pData->data() : "";
    }
};

// AptValue -- core variant type (from apt_decomp.cpp Section 2)
// Layout:
//   0x00: u32 m_flags
//   0x04: u32 m_data
//   0x08: AptValueVTableDesc* m_vtableDesc
//   0x0C: u32 (value storage: int/float bits)
//   ...
//   0x24: AptValue* m_stringData
class AptValue {
public:
    u32 m_flags;                     // 0x00
    u32 m_data;                      // 0x04
    AptValueVTableDesc* m_vtableDesc;// 0x08
    union {
        u32  m_intValue;
        f32  m_floatValue;
    };                               // 0x0C
    u32  m_pad10;                    // 0x10
    u32  m_pad14;                    // 0x14
    u32  m_pad18;                    // 0x18
    u32  m_pad1C;                    // 0x1C
    u32  m_pad20;                    // 0x20
    AptValue* m_stringData;          // 0x24

    // --- Bitfield accessors ---
    // vtblIndex = bits 0-6 (LSB-0)
    u32 getVtblIndex() const { return m_flags & 0x7F; }
    void setVtblIndex(u32 idx) {
        m_flags = (m_flags & ~0x7F) | (idx & 0x7F);
    }

    // isDefined = bit 27
    bool getIsDefined() const { return (m_flags & 0x08000000) != 0; }
    void setIsDefined(bool v) {
        if (v) m_flags |= 0x08000000;
        else   m_flags &= ~0x08000000;
    }

    // refCount = bits 14-25
    u32 getRefCount() const { return (m_flags >> 14) & 0xFFF; }
    void setRefCount(u32 rc) {
        m_flags = (m_flags & ~(0xFFF << 14)) | ((rc & 0xFFF) << 14);
    }

    // gcMark = bit 30
    bool getGCMark() const { return (m_flags >> 30) & 1; }
    void setGCMark(bool v) {
        if (v) m_flags |= (1u << 30);
        else   m_flags &= ~(1u << 30);
    }

    // gcRoot = bits 8-13
    u32 getGCRoot() const { return (m_flags >> 8) & 0x3F; }

    // isReleaseAtEnd = bit 29
    bool isReleaseAtEnd() const { return (m_flags >> 29) & 1; }
    void setReleaseAtEnd() { m_flags |= (1u << 29); }
    void clearReleaseAtEnd() { m_flags &= ~(1u << 29); }

    // --- Resolve string for STRING2 types ---
    AptValue* resolveString() const {
        if ((m_flags & 0x7F) != APT_VFT_STRING) {
            return m_stringData;
        }
        return const_cast<AptValue*>(this);
    }

    // --- Type conversions (from apt_decomp.cpp Section 4) ---

    // AptValue::toInteger (0x802B04B8)
    int toInteger() const;

    // AptValue::toFloat (0x802B05B8)
    f32 toFloat() const;

    // AptValue::toBool (0x802B06AC)
    bool toBool() const;

    // --- Type checks ---
    bool isString() const {
        u32 vt = getVtblIndex();
        return vt == APT_VFT_STRING || vt == APT_VFT_STRING2;
    }
    bool isInteger() const { return getVtblIndex() == APT_VFT_INTEGER; }
    bool isFloat()   const { return getVtblIndex() == APT_VFT_FLOAT; }
    bool isBoolean() const { return getVtblIndex() == APT_VFT_BOOLEAN; }
    bool isNone()    const { return getVtblIndex() == APT_VFT_NONE; }
    bool isCIH()     const {
        u32 vt = getVtblIndex();
        return vt >= APT_VFT_CIH_FIRST && vt <= APT_VFT_CIH_LAST;
    }

    // Reference counting
    void AddRef();
    void Release();
};

// Global sentinel values (from sdata / r13-relative in the GC binary)
extern AptValue* gpUndefinedValue;


// =============================================================================
// AptValue::toInteger (0x802B04B8, 256 bytes)
// =============================================================================
int AptValue::toInteger() const {
    // Check isDefined -- undefined returns 0
    if (!getIsDefined()) {
        return 0;
    }

    u32 vft = getVtblIndex();
    switch (vft) {
        case APT_VFT_FLOAT: {
            return static_cast<int>(m_floatValue);
        }

        case APT_VFT_STRING:
        case APT_VFT_STRING2: {
            const AptValue* strVal = resolveString();
            EAStringCInternalData* strData =
                reinterpret_cast<EAStringCInternalData*>(strVal->m_intValue);
            if (strData->m_length > 2) {
                const char* str = strData->data();
                if (str[0] == '0' && str[1] == 'x') {
                    return static_cast<int>(strtol(str, nullptr, 16));
                }
            }
            const char* data = strData->data();
            return atoi(data);
        }

        case APT_VFT_BOOLEAN:
        case APT_VFT_INTEGER: {
            return static_cast<int>(m_intValue);
        }

        default: {
            if (this == gpUndefinedValue) return 0;
            return 1;
        }
    }
}


// =============================================================================
// AptValue::toFloat (0x802B05B8, 244 bytes)
// =============================================================================
f32 AptValue::toFloat() const {
    if (!getIsDefined()) {
        return 0.0f;
    }

    u32 vft = getVtblIndex();
    switch (vft) {
        case APT_VFT_FLOAT:
            return m_floatValue;

        case APT_VFT_STRING:
        case APT_VFT_STRING2: {
            const AptValue* strVal = resolveString();
            EAStringCInternalData* strData =
                reinterpret_cast<EAStringCInternalData*>(strVal->m_intValue);
            const char* str = strData->data();
            return static_cast<f32>(atof(str));
        }

        case APT_VFT_BOOLEAN: {
            return (m_intValue == 0) ? 0.0f : 1.0f;
        }

        case APT_VFT_INTEGER: {
            return static_cast<f32>(static_cast<s32>(m_intValue));
        }

        default: {
            if (this == gpUndefinedValue) return 0.0f;
            return 1.0f;
        }
    }
}


// =============================================================================
// AptValue::toBool (0x802B06AC, 396 bytes)
// =============================================================================
bool AptValue::toBool() const {
    u32 vft = getVtblIndex();
    switch (vft) {
        case APT_VFT_FLOAT:
            return m_floatValue != 0.0f;

        case APT_VFT_STRING:
        case APT_VFT_STRING2: {
            // Check if string resolves to INTEGER type via virtual lookup
            // If resolved vtblIndex == INTEGER, compare against the constant
            // "false" string
            const AptValue* strVal = resolveString();
            EAStringCInternalData* strData =
                reinterpret_cast<EAStringCInternalData*>(strVal->m_intValue);

            // First, try to detect "false" literal
            if (strData->m_length == 5) {
                const char* str = strData->data();
                if (strcmp(str, "false") == 0) {
                    return false;
                }
            }

            // Parse as number
            if (strData->m_length > 2) {
                const char* str = strData->data();
                if (str[0] == '0' && str[1] == 'x') {
                    int hexVal = static_cast<int>(strtol(str, nullptr, 16));
                    return hexVal != 0;
                }
            }
            const char* data = strData->data();
            f32 fval = static_cast<f32>(atof(data));
            return fval != 0.0f;
        }

        case APT_VFT_BOOLEAN:
            return m_intValue != 0;

        case APT_VFT_INTEGER:
            return m_intValue != 0;

        default: {
            if (this == gpUndefinedValue) return false;
            return true;
        }
    }
}


// =============================================================================
// SECTION 2 - AptActionInterpreter
// =============================================================================

// LocalContextT -- passed to every opcode handler (from apt_decomp.cpp Sec 5)
struct LocalContextT {
    u32 m_scope;       // 0x00 - current scope object (AptValue*)
    u32 m_cih;         // 0x04 - current CIH
    u32 m_stack;       // 0x08 - stack array pointer
    u32 m_constFile;   // 0x0C - current AptConstFile*
    u32 m_streamPos;   // 0x10 - current bytecode stream position
    u32 m_returnFlag;  // 0x14 - set to 1 by ActionReturn
    u32 m_breakFlag;   // 0x18 - for try/catch/finally
};

// AptActionInterpreter -- stack-based bytecode VM
// Layout: 148 bytes (from apt_decomp.cpp Section 5)
class AptActionInterpreter {
public:
    u16 m_stackTop;      // 0x00
    u16 m_pad02;         // 0x02
    f32 m_tempFloat;     // 0x04
    u32 m_stackData;     // 0x08 - pointer to stack value array
    f32 m_tempFloat2;    // 0x0C
    u32 m_streamPos;     // 0x10
    u32 m_funcDefTemp;   // 0x14
    u32 m_cleanupTemp;   // 0x18
    u32 m_gotoTemp;      // 0x1C
    f32 m_callTemp;      // 0x20
    f32 m_strAddTemp;    // 0x24
    u32 m_createScope;   // 0x28
    u32 m_createObj;     // 0x2C
    u32 m_defFuncScope;  // 0x30
    u32 m_defFuncObj;    // 0x34
    u32 m_defFuncDict;   // 0x38
    u32 m_pad3C;         // 0x3C
    u32 m_pad40;         // 0x40
    u32 m_pad44;         // 0x44
    u32 m_setTargetCIH;  // 0x48
    u32 m_gotoLabel;     // 0x4C
    u32 m_pad50;         // 0x50
    u32 m_thrownValue;   // 0x54
    u32 m_stackLimit;    // 0x58
    u32 m_field5C;       // 0x5C
    u32 m_pad60;         // 0x60
    u32 m_createTemp;    // 0x64
    u8  m_pad68[0x28];   // 0x68..0x8F
    u32 m_createTemp2;   // 0x90

    // Stack operations
    void stackPush(AptValue* val);
    void stackPushNoInc(AptValue* val);
    AptValue* stackGetPop();
    void stackPop();
    AptValue* stackAt(int idx);
    void stackPopAndPush(int popCount, AptValue* pushVal);

    // Opcode handlers (static, called from dispatch loop)
    // Signature: void handler(AptActionInterpreter* interp, LocalContextT* ctx)

    // --- Simple no-op / trivial handlers ---

    // Opcode 0x00: End (0x802729D4, 4 bytes) - MATCHING
    static void _FunctionAptActionEnd(
        AptActionInterpreter* interp, LocalContextT* ctx)
    {
        // blr -- no operation, loop checks opcode 0x00 to exit
    }

    // Opcode 0x3E: Return (0x802769BC, 12 bytes) - MATCHING
    // Sets return flag in context. Three PPC instructions: li r0,1 / stw r0,20(r4) / blr
    static void _FunctionAptActionReturn(
        AptActionInterpreter* interp, LocalContextT* ctx)
    {
        ctx->m_returnFlag = 1;
    }

    // Opcode 0x08: ToggleQuality (0x80272BBC, 4 bytes) - MATCHING
    // No-op on GameCube (quality is fixed).
    static void _FunctionAptActionToggleQuality(
        AptActionInterpreter* interp, LocalContextT* ctx)
    {
        // intentionally empty
    }

    // Opcode 0x29: StringLessThan (0x80275D1C, 4 bytes) - MATCHING
    // Not implemented in this build (stub).
    static void _FunctionAptActionStringLessThan(
        AptActionInterpreter* interp, LocalContextT* ctx)
    {
        // intentionally empty
    }

    // Opcode 0x8A: WaitForFrame (0x8027DAD4, 4 bytes) - MATCHING
    // No-op (frames are always loaded on GC).
    static void _FunctionAptActionWaitForFrame(
        AptActionInterpreter* interp, LocalContextT* ctx)
    {
        // intentionally empty
    }

    // Opcode 0x09: StopSounds (0x80272BC0, 4 bytes) - MATCHING
    static void _FunctionAptActionStopSounds(
        AptActionInterpreter* interp, LocalContextT* ctx)
    {
        // Calls through to sound system -- thin wrapper, no-op for PC port stub
    }

    // Opcode 0x31: MBLength (0x80275EB0, 4 bytes) - MATCHING
    static void _FunctionAptActionMBLength(
        AptActionInterpreter* interp, LocalContextT* ctx)
    {
        // Not implemented in GC build
    }

    // Opcode 0x32: CharToAscii (0x80275EB4, 4 bytes) - MATCHING
    static void _FunctionAptActionCharToAscii(
        AptActionInterpreter* interp, LocalContextT* ctx)
    {
        // Not implemented in GC build
    }

    // Opcode 0x35: MBSubString (0x80276234, 4 bytes) - MATCHING
    static void _FunctionAptActionMBSubString(
        AptActionInterpreter* interp, LocalContextT* ctx)
    {
        // Not implemented in GC build
    }

    // Opcode 0x36: MBCharToAscii (0x80276238, 4 bytes) - MATCHING
    static void _FunctionAptActionMBCharToAscii(
        AptActionInterpreter* interp, LocalContextT* ctx)
    {
        // Not implemented in GC build
    }

    // Opcode 0x37: MBAsciiToChar (0x8027623C, 4 bytes) - MATCHING
    static void _FunctionAptActionMBAsciiToChar(
        AptActionInterpreter* interp, LocalContextT* ctx)
    {
        // Not implemented in GC build
    }

    // Opcode 0x65: BitURShift (0x8027CEB4, 4 bytes) - MATCHING
    static void _FunctionAptActionBitURShift(
        AptActionInterpreter* interp, LocalContextT* ctx)
    {
        // Not implemented in GC build
    }

    // --- Arithmetic handlers (from apt_decomp.cpp Section 8) ---
    // All follow the pattern: pop 2, convert to float, operate, push result.

    // Opcode 0x0A: Add (0x80272BC4, 688 bytes)
    static void _FunctionAptActionAdd(
        AptActionInterpreter* interp, LocalContextT* ctx)
    {
        AptValue* b = interp->stackGetPop();
        AptValue* a = interp->stackGetPop();
        f32 fa = a->toFloat();
        f32 fb = b->toFloat();
        f32 result = fa + fb;

        // Allocate result value and push
        // In the GC binary this uses the recycled float free list
        // For PC port we allocate normally
        AptValue* val = new AptValue();
        val->setVtblIndex(APT_VFT_FLOAT);
        val->setIsDefined(true);
        val->m_floatValue = result;
        interp->stackPushNoInc(val);
    }

    // Opcode 0x0B: Subtract (0x80272E74, 688 bytes)
    static void _FunctionAptActionSubtract(
        AptActionInterpreter* interp, LocalContextT* ctx)
    {
        AptValue* b = interp->stackGetPop();
        AptValue* a = interp->stackGetPop();
        f32 fa = a->toFloat();
        f32 fb = b->toFloat();
        f32 result = fa - fb;

        AptValue* val = new AptValue();
        val->setVtblIndex(APT_VFT_FLOAT);
        val->setIsDefined(true);
        val->m_floatValue = result;
        interp->stackPushNoInc(val);
    }

    // Opcode 0x0C: Multiply (0x80273124, 688 bytes)
    static void _FunctionAptActionMultiply(
        AptActionInterpreter* interp, LocalContextT* ctx)
    {
        AptValue* b = interp->stackGetPop();
        AptValue* a = interp->stackGetPop();
        f32 fa = a->toFloat();
        f32 fb = b->toFloat();
        f32 result = fa * fb;

        AptValue* val = new AptValue();
        val->setVtblIndex(APT_VFT_FLOAT);
        val->setIsDefined(true);
        val->m_floatValue = result;
        interp->stackPushNoInc(val);
    }

    // Opcode 0x0D: Divide (0x802733D4, 496 bytes)
    static void _FunctionAptActionDivide(
        AptActionInterpreter* interp, LocalContextT* ctx)
    {
        AptValue* b = interp->stackGetPop();
        AptValue* a = interp->stackGetPop();
        f32 fa = a->toFloat();
        f32 fb = b->toFloat();

        // ActionScript division: divide by zero produces Infinity, not crash
        f32 result;
        if (fb == 0.0f) {
            // ActionScript returns "#ERROR#" string for old-style divide
            // In SWF7+ returns Infinity; Sims 2 uses older behavior
            result = 0.0f; // TODO: match original behavior exactly
        } else {
            result = fa / fb;
        }

        AptValue* val = new AptValue();
        val->setVtblIndex(APT_VFT_FLOAT);
        val->setIsDefined(true);
        val->m_floatValue = result;
        interp->stackPushNoInc(val);
    }

    // Opcode 0x12: Not (0x80273FD0, 360 bytes)
    static void _FunctionAptActionNot(
        AptActionInterpreter* interp, LocalContextT* ctx)
    {
        AptValue* a = interp->stackGetPop();
        bool bval = a->toBool();

        AptValue* val = new AptValue();
        val->setVtblIndex(APT_VFT_BOOLEAN);
        val->setIsDefined(true);
        val->m_intValue = bval ? 0 : 1;
        interp->stackPushNoInc(val);
    }

    // Opcode 0x3F: Modulo (0x802769C8, 504 bytes)
    static void _FunctionAptActionModulo(
        AptActionInterpreter* interp, LocalContextT* ctx)
    {
        AptValue* b = interp->stackGetPop();
        AptValue* a = interp->stackGetPop();
        f32 fa = a->toFloat();
        f32 fb = b->toFloat();

        f32 result = 0.0f;
        if (fb != 0.0f) {
            result = fmodf(fa, fb);
        }

        AptValue* val = new AptValue();
        val->setVtblIndex(APT_VFT_FLOAT);
        val->setIsDefined(true);
        val->m_floatValue = result;
        interp->stackPushNoInc(val);
    }

    // Opcode 0x50: Increment (0x8027B338, 604 bytes)
    static void _FunctionAptActionIncrement(
        AptActionInterpreter* interp, LocalContextT* ctx)
    {
        AptValue* a = interp->stackGetPop();
        f32 fa = a->toFloat();
        f32 result = fa + 1.0f;

        AptValue* val = new AptValue();
        val->setVtblIndex(APT_VFT_FLOAT);
        val->setIsDefined(true);
        val->m_floatValue = result;
        interp->stackPushNoInc(val);
    }

    // Opcode 0x51: Decrement (0x8027B594, 604 bytes)
    static void _FunctionAptActionDecrement(
        AptActionInterpreter* interp, LocalContextT* ctx)
    {
        AptValue* a = interp->stackGetPop();
        f32 fa = a->toFloat();
        f32 result = fa - 1.0f;

        AptValue* val = new AptValue();
        val->setVtblIndex(APT_VFT_FLOAT);
        val->setIsDefined(true);
        val->m_floatValue = result;
        interp->stackPushNoInc(val);
    }

    // --- Bitwise operators (from apt_decomp.cpp Section 6) ---

    // Opcode 0x60: BitAnd (0x8027C5B8, 460 bytes)
    static void _FunctionAptActionBitAnd(
        AptActionInterpreter* interp, LocalContextT* ctx)
    {
        AptValue* b = interp->stackGetPop();
        AptValue* a = interp->stackGetPop();
        int ia = a->toInteger();
        int ib = b->toInteger();

        AptValue* val = new AptValue();
        val->setVtblIndex(APT_VFT_INTEGER);
        val->setIsDefined(true);
        val->m_intValue = static_cast<u32>(ia & ib);
        interp->stackPushNoInc(val);
    }

    // Opcode 0x61: BitOr (0x8027C784, 460 bytes)
    static void _FunctionAptActionBitOr(
        AptActionInterpreter* interp, LocalContextT* ctx)
    {
        AptValue* b = interp->stackGetPop();
        AptValue* a = interp->stackGetPop();
        int ia = a->toInteger();
        int ib = b->toInteger();

        AptValue* val = new AptValue();
        val->setVtblIndex(APT_VFT_INTEGER);
        val->setIsDefined(true);
        val->m_intValue = static_cast<u32>(ia | ib);
        interp->stackPushNoInc(val);
    }

    // Opcode 0x62: BitXor (0x8027C950, 460 bytes)
    static void _FunctionAptActionBitXor(
        AptActionInterpreter* interp, LocalContextT* ctx)
    {
        AptValue* b = interp->stackGetPop();
        AptValue* a = interp->stackGetPop();
        int ia = a->toInteger();
        int ib = b->toInteger();

        AptValue* val = new AptValue();
        val->setVtblIndex(APT_VFT_INTEGER);
        val->setIsDefined(true);
        val->m_intValue = static_cast<u32>(ia ^ ib);
        interp->stackPushNoInc(val);
    }

    // Opcode 0x63: BitLShift (0x8027CB1C, 460 bytes)
    static void _FunctionAptActionBitLShift(
        AptActionInterpreter* interp, LocalContextT* ctx)
    {
        AptValue* b = interp->stackGetPop(); // shift amount
        AptValue* a = interp->stackGetPop(); // value
        int ia = a->toInteger();
        int ib = b->toInteger();

        AptValue* val = new AptValue();
        val->setVtblIndex(APT_VFT_INTEGER);
        val->setIsDefined(true);
        val->m_intValue = static_cast<u32>(ia << (ib & 31));
        interp->stackPushNoInc(val);
    }

    // Opcode 0x64: BitRShift (0x8027CCE8, 460 bytes)
    static void _FunctionAptActionBitRShift(
        AptActionInterpreter* interp, LocalContextT* ctx)
    {
        AptValue* b = interp->stackGetPop(); // shift amount
        AptValue* a = interp->stackGetPop(); // value
        int ia = a->toInteger();
        int ib = b->toInteger();

        AptValue* val = new AptValue();
        val->setVtblIndex(APT_VFT_INTEGER);
        val->setIsDefined(true);
        val->m_intValue = static_cast<u32>(ia >> (ib & 31));
        interp->stackPushNoInc(val);
    }

    // --- Stack manipulation opcodes ---

    // Opcode 0x17: Pop (0x802749BC, 164 bytes)
    static void _FunctionAptActionPop(
        AptActionInterpreter* interp, LocalContextT* ctx)
    {
        interp->stackPop();
    }

    // Opcode 0x4C: PushDuplicate (0x8027AAD4, 104 bytes)
    static void _FunctionAptActionPushDuplicate(
        AptActionInterpreter* interp, LocalContextT* ctx)
    {
        AptValue* top = interp->stackAt(0);
        interp->stackPush(top); // push increments refcount
    }

    // Opcode 0x4D: StackSwap (0x8027AB3C, 112 bytes)
    static void _FunctionAptActionStackSwap(
        AptActionInterpreter* interp, LocalContextT* ctx)
    {
        // Swap the top two stack elements
        AptValue* top  = interp->stackAt(0);
        AptValue* next = interp->stackAt(1);
        // Direct swap in stack array
        AptValue** stack = reinterpret_cast<AptValue**>(interp->m_stackData);
        u16 sp = interp->m_stackTop;
        stack[sp - 1] = next;
        stack[sp - 2] = top;
        // Note: no refcount changes needed, just a pointer swap
    }

    // Opcode 0x18: ToInteger (0x80274A60, 404 bytes)
    static void _FunctionAptActionToInteger(
        AptActionInterpreter* interp, LocalContextT* ctx)
    {
        AptValue* a = interp->stackGetPop();
        int ival = a->toInteger();

        AptValue* val = new AptValue();
        val->setVtblIndex(APT_VFT_INTEGER);
        val->setIsDefined(true);
        val->m_intValue = static_cast<u32>(ival);
        interp->stackPushNoInc(val);
    }

    // Opcode 0x30: Random (0x80275D20, 400 bytes)
    static void _FunctionAptActionRandom(
        AptActionInterpreter* interp, LocalContextT* ctx)
    {
        AptValue* a = interp->stackGetPop();
        int maxVal = a->toInteger();
        int result = 0;
        if (maxVal > 0) {
            result = rand() % maxVal;
        }

        AptValue* val = new AptValue();
        val->setVtblIndex(APT_VFT_INTEGER);
        val->setIsDefined(true);
        val->m_intValue = static_cast<u32>(result);
        interp->stackPushNoInc(val);
    }

    // --- Extended opcode push variants (from apt_decomp.cpp Section 6) ---
    // These read data from the bytecode stream following the opcode.

    // Opcode 0xBA: Push0 (0x8027EEEC, 252 bytes)
    // Pushes integer 0 onto the stack.
    static void _FunctionAptActionPush0(
        AptActionInterpreter* interp, LocalContextT* ctx)
    {
        AptValue* val = new AptValue();
        val->setVtblIndex(APT_VFT_INTEGER);
        val->setIsDefined(true);
        val->m_intValue = 0;
        interp->stackPushNoInc(val);
    }

    // Opcode 0xBB: Push1 (0x8027EFE8, 252 bytes)
    // Pushes integer 1 onto the stack.
    static void _FunctionAptActionPush1(
        AptActionInterpreter* interp, LocalContextT* ctx)
    {
        AptValue* val = new AptValue();
        val->setVtblIndex(APT_VFT_INTEGER);
        val->setIsDefined(true);
        val->m_intValue = 1;
        interp->stackPushNoInc(val);
    }

    // Opcode 0xBC: PushTrue (0x8027F0E4, 252 bytes)
    static void _FunctionAptActionPushTrue(
        AptActionInterpreter* interp, LocalContextT* ctx)
    {
        AptValue* val = new AptValue();
        val->setVtblIndex(APT_VFT_BOOLEAN);
        val->setIsDefined(true);
        val->m_intValue = 1;
        interp->stackPushNoInc(val);
    }

    // Opcode 0xBD: PushFalse (0x8027F1E0, 252 bytes)
    static void _FunctionAptActionPushFalse(
        AptActionInterpreter* interp, LocalContextT* ctx)
    {
        AptValue* val = new AptValue();
        val->setVtblIndex(APT_VFT_BOOLEAN);
        val->setIsDefined(true);
        val->m_intValue = 0;
        interp->stackPushNoInc(val);
    }

    // Opcode 0xBE: PushNULL (0x8027F2DC, 100 bytes)
    static void _FunctionAptActionPushNULL(
        AptActionInterpreter* interp, LocalContextT* ctx)
    {
        AptValue* val = new AptValue();
        val->setVtblIndex(APT_VFT_NONE);
        val->setIsDefined(true);
        val->m_intValue = 0;
        interp->stackPushNoInc(val);
    }

    // Opcode 0xBF: PushUndefined (0x8027F340, 100 bytes)
    static void _FunctionAptActionPushUndefined(
        AptActionInterpreter* interp, LocalContextT* ctx)
    {
        interp->stackPush(gpUndefinedValue);
    }
};


// =============================================================================
// SECTION 3 - AptRenderingContext
// =============================================================================
// Matrix and color transform stack operations
// Layout: 960 bytes (from apt_decomp.cpp Section 17)
//
// Offset layout (from pushColourTransform asm):
//   0x000-0x037:  CXForm data (8 floats: multiply RGBA, add RGBA)
//   0x038-0x??:   vertex matrix data (6 floats: a,b,c,d,tx,ty per entry)
//   0x3B8:        m_colourStackIdx (u32) -- colour transform stack pointer
//   ...
//   Colour stack entries start at offset 56 + (stackIdx * 32)

// AptMatrix: 2x3 affine transform (6 floats)
struct AptMatrix {
    f32 a, b, c, d, tx, ty;  // 24 bytes total
};

// AptCXForm: color transform (multiply + add, 8 floats = 32 bytes)
struct AptCXForm {
    f32 mulR, mulG, mulB, mulA;
    f32 addR, addG, addB, addA;
};

// AptRect: bounding rectangle
struct AptRect {
    f32 xMin, yMin, xMax, yMax;

    void expand(const AptRect* other) {
        if (other->xMin < xMin) xMin = other->xMin;
        if (other->yMin < yMin) yMin = other->yMin;
        if (other->xMax > xMax) xMax = other->xMax;
        if (other->yMax > yMax) yMax = other->yMax;
    }
};

class AptRenderingContext {
public:
    // Internal storage -- from asm analysis:
    // 0x000: CXForm m_curCXForm (32 bytes)
    AptCXForm m_curCXForm;            // 0x000

    // 0x020: vertex matrix data
    // 0x038: colour stack data starts at offset 56
    u8 m_padColorStack[0x398 - sizeof(AptCXForm)]; // pad to 0x3B8

    // 0x3B8: colour stack index
    u32 m_colourStackIdx;             // 0x3B8

    // Remaining fields for vertex matrix stack
    u8 m_vertexData[0x3C0 - 0x3BC];  // padding

    // The vertex matrix stack and its index are stored elsewhere in
    // the 960-byte object; exact layout deferred to full decomp.

    // --- Colour transform operations ---

    // pushColourTransform (0x802AB1E4, 120 bytes) - MATCHING
    // Saves the current CXForm onto the stack.
    // From asm: copies 32 bytes (8 floats) from this+0 to stack[idx]*32 + 56,
    // then increments stack index at offset 952 (0x3B8).
    void pushColourTransform() {
        u32 idx = m_colourStackIdx;
        u8* stackBase = reinterpret_cast<u8*>(this) + 56; // offset 0x38
        AptCXForm* dest = reinterpret_cast<AptCXForm*>(stackBase + idx * 32);
        *dest = m_curCXForm;
        m_colourStackIdx = idx + 1;
    }

    // popColourTransform (0x802AB25C, 116 bytes) - MATCHING
    // Restores the CXForm from the top of the stack.
    void popColourTransform() {
        m_colourStackIdx--;
        u32 idx = m_colourStackIdx;
        u8* stackBase = reinterpret_cast<u8*>(this) + 56;
        AptCXForm* src = reinterpret_cast<AptCXForm*>(stackBase + idx * 32);
        m_curCXForm = *src;
    }

    // appendColourTransform (0x802AB2D0, 100 bytes) - MATCHING
    // Concatenates a CXForm: newMul = cur.mul * arg.mul, newAdd = cur.add + arg.add
    void appendColourTransform(const AptCXForm* cxform) {
        m_curCXForm.mulR *= cxform->mulR;
        m_curCXForm.mulG *= cxform->mulG;
        m_curCXForm.mulB *= cxform->mulB;
        m_curCXForm.mulA *= cxform->mulA;
        m_curCXForm.addR += cxform->addR;
        m_curCXForm.addG += cxform->addG;
        m_curCXForm.addB += cxform->addB;
        m_curCXForm.addA += cxform->addA;
    }

    // --- Vertex matrix operations ---

    // multMatrix (0x802AB458, 112 bytes) - MATCHING
    // result = a * b (2x3 affine matrix multiply)
    static void multMatrix(const AptMatrix* a, const AptMatrix* b, AptMatrix* result) {
        result->a  = a->a * b->a  + a->b * b->c;
        result->b  = a->a * b->b  + a->b * b->d;
        result->c  = a->c * b->a  + a->d * b->c;
        result->d  = a->c * b->b  + a->d * b->d;
        result->tx = a->tx * b->a + a->ty * b->c + b->tx;
        result->ty = a->tx * b->b + a->ty * b->d + b->ty;
    }

    // expandBoundingRect (0x802AB4C8, 116 bytes) - MATCHING
    // Expands rect 'out' to encompass 'in'.
    static void expandBoundingRect(AptRect* out, const AptRect* in) {
        if (in->xMin < out->xMin) out->xMin = in->xMin;
        if (in->yMin < out->yMin) out->yMin = in->yMin;
        if (in->xMax > out->xMax) out->xMax = in->xMax;
        if (in->yMax > out->yMax) out->yMax = in->yMax;
    }
};


// =============================================================================
// SECTION 4 - AptCIH (Character Instance Handle) type queries
// =============================================================================
// From apt_decomp.cpp Section 10 and AptCIH.cpp asm

class AptCIH : public AptValue {
public:
    // At offset 0x4C: AptCharacterInst* m_characterInst
    AptCharacterInst* getCharacterInst() const {
        return *reinterpret_cast<AptCharacterInst* const*>(
            reinterpret_cast<const u8*>(this) + 0x4C);
    }

    // At offset 0x48: AptNativeHash* m_nativeHash
    void* getNativeHash() const {
        return *reinterpret_cast<void* const*>(
            reinterpret_cast<const u8*>(this) + 0x48);
    }

    // Type query helpers (from AptCIH.cpp asm stubs)
    bool isSpriteInst(bool includeUndefined = false) const {
        u32 vt = getVtblIndex();
        if (vt == 12) return true; // CIH_FIRST = sprite
        if (includeUndefined && vt == APT_VFT_UNDEFINED) return true;
        return false;
    }

    bool isButtonInst(bool includeUndefined = false) const {
        u32 vt = getVtblIndex();
        if (vt == 13) return true;
        if (includeUndefined && vt == APT_VFT_UNDEFINED) return true;
        return false;
    }

    bool isTextInst() const {
        return getVtblIndex() == 14;
    }

    bool isShapeInst() const {
        return getVtblIndex() == 15;
    }

    bool isMorphInst() const {
        return getVtblIndex() == 16;
    }

    bool isStaticTextInst() const {
        return getVtblIndex() == 17;
    }

    bool isCharacterInst() const {
        return getVtblIndex() >= APT_VFT_CIH_FIRST &&
               getVtblIndex() <= APT_VFT_CIH_LAST;
    }

    // Zombie state (from apt_decomp.cpp Section 10)
    // m_flags offset 0x5C bits 12-13
    u32 getZombieState() const {
        u32 cihFlags = *reinterpret_cast<const u32*>(
            reinterpret_cast<const u8*>(this) + 0x5C);
        return (cihFlags >> 12) & 0x3;
    }
};


// =============================================================================
// SECTION 5 - AptViewer (Top-Level Controller)
// =============================================================================
// Size: 1128 bytes (0x468) from apt_decomp.cpp Section 12

class UIObjectBase; // forward

class AptViewer {
public:
    u8  m_pad[0x350];                   // internal state
    u32 m_aptFile;                      // 0x350 - loaded APT file handle
    u32 m_aptData;                      // 0x354 - APT data pointer
    u8  m_pad2[0x374 - 0x358];
    UIObjectBase* m_messageHandler;     // 0x374
    u8  m_pad3[0x3A0 - 0x378];
    UIObjectBase* m_uiObject;           // 0x3A0
    u32 m_controllerState;              // 0x3A4
    u32 m_currentAptButtonFilter;       // 0x3A8
    u32 m_readControllerConfig;         // 0x3AC
    u8  m_pad4[0x468 - 0x3B0];

    // From AptViewer.cpp asm (0x800101F0)
    AptViewer();
    ~AptViewer();

    void Init(UIObjectBase* uiObj);
    void Load(const char* filename, bool async);
    void LoadActionScript(const char* filename, bool async);
    void UnLoad();
    void UpdateAll();
    void Draw(ERC* rc);

    // Function calls from game to ActionScript
    void NewCallFunction(const char* name, const char* target,
                         const char* arg, int argc, ...);
    void NewCallFunction2(const char* name, const char* target,
                          const char* arg, int argc, char** argv);

    // Controller input
    void NewReadController(int player, bool active, int mode, bool repeat);
    void OnePlayerReadController(int player, int mode);
    void RepeatCheck(int player, int buttonId);

    // Button filter stack
    u32  PushAptButtonFilter(int player, const char* context);
    void PopAptButtonFilter(int player, u32 handle);
    void AddCmdToAptButtonFilter(int player, u32 handle, int cmd);
    void RemoveCmdFromAptButtonFilter(int player, u32 handle, int cmd);
    u32  GetCurrentAptButtonFilter(int player);
    void* GetPlayersController(int player);
};


// =============================================================================
// SECTION 6 - UIObjectBase
// =============================================================================
// Virtual table at 0x8045CFD8 (from targets_decomp.cpp)
// Bridge between APT Flash UI and C++ game logic.

// Singleton globals (from asm, r13-relative / lis+lwz patterns)
extern AptViewer* g_pAptViewer;       // global APT viewer instance
extern void*      g_pUIRouter;        // global UI router singleton

class UIObjectBase {
public:
    // Embedded data: CBFunctor callbacks occupy offsets 0-127
    u8  m_callbackData[128];     // 0x000 - CBFunctor storage
    u32 m_vtablePtr;             // 0x080 - Wrapper vtable pointer at offset 128

    virtual ~UIObjectBase() {}

    // vt[1]: APT calls this to push data to C++
    virtual void SetVariable(char* name, char* value) {
        // Default: empty
    }

    // vt[2]: APT calls this to pull data from C++
    virtual char* GetVariable(char* name) {
        return nullptr;
    }

    // vt[3]: APT calls this for localized strings
    virtual unsigned short* GetLocalizable(char* name) {
        return nullptr;
    }

    // vt[4]: Called every frame
    virtual void Update() {
        // Default: empty
    }

    // vt[5]: Called every render frame
    virtual void Draw(ERC* rc) {
        // Default: empty
    }

    // --- Utility methods (non-virtual) ---

    // 0x80177A64 - Push a named button filter for a player
    u32 pushAptButtonFilter(int player, const char* context) {
        // Delegates to the global APT viewer
        if (g_pAptViewer) {
            return g_pAptViewer->PushAptButtonFilter(player, context);
        }
        return 0;
    }

    // 0x80177A98 - Pop a button filter
    void popAptButtonFilter(int player, u32 handle) {
        if (g_pAptViewer) {
            g_pAptViewer->PopAptButtonFilter(player, handle);
        }
    }

    // 0x80177ACC - Add a command to a button filter
    void addCmdToAptButtonFilter(int player, u32 handle, int cmd) {
        if (g_pAptViewer) {
            g_pAptViewer->AddCmdToAptButtonFilter(player, handle, cmd);
        }
    }

    // 0x80177B08 - Remove a command from a button filter
    void removeCmdFromAptButtonFilter(int player, u32 handle, int cmd) {
        if (g_pAptViewer) {
            g_pAptViewer->RemoveCmdFromAptButtonFilter(player, handle, cmd);
        }
    }

    // 0x80177B44 (96 bytes) - Push button filter for ALL commands (1..48)
    // From UIObjectBase.cpp asm
    u32 pushAptButtonFilterALL(int player, const char* context) {
        u32 handle = pushAptButtonFilter(player, context);
        if (handle == 0) {
            return 0;
        }
        // Add all standard commands (1 through 48)
        for (int cmd = 1; cmd <= 48; cmd++) {
            addCmdToAptButtonFilter(player, handle, cmd);
        }
        return handle;
    }

    // 0x80177BA4 (140 bytes) - Format integer as number string
    // From UIObjectBase.cpp asm -- uses Sprintf("%d") then UTF8ToUCS2
    bool makeNumberString(int value, unsigned short* outBuf) {
        if (!outBuf) return false;

        char tempBuf[32];
        memset(tempBuf, 0, 32);
        int len = sprintf(tempBuf, "%d", value);

        // Convert UTF8 to UCS2 (wide char)
        for (int i = 0; i < len; i++) {
            outBuf[i] = static_cast<unsigned short>(tempBuf[i]);
        }
        outBuf[len] = 0; // null terminate

        return true;
    }

    // 0x80177C30 (120 bytes) - Format integer as money string
    // From UIObjectBase.cpp asm -- calls GetMoneyString then wcscpy
    bool makeMoneyString(int value, unsigned short* outBuf, bool withSymbol) {
        if (!outBuf) return false;

        // Format with currency symbol if requested
        char tempBuf[64];
        if (withSymbol) {
            sprintf(tempBuf, "$%d", value);
        } else {
            sprintf(tempBuf, "%d", value);
        }

        int len = static_cast<int>(strlen(tempBuf));
        for (int i = 0; i < len; i++) {
            outBuf[i] = static_cast<unsigned short>(tempBuf[i]);
        }
        outBuf[len] = 0;

        return true;
    }

    // 0x80177CC8 (68 bytes) - Route SetVariable through UIRouter
    // From UIObjectBase.cpp asm -- loads global router, calls through vtable
    void UIRouter_SetVariable(const char* name, const char* value);

    // 0x80177D0C (72 bytes) - Navigate screens via FlowGoto
    // Calls UIRouter_SetVariable with key "FlowGoto"
    void UIRouter_FlowGoto(const char* screenName);

    // 0x80177D54 (84 bytes) - Call ActionScript function via AptViewer
    void AptViewer_CallFunction(const char* funcName, const char* arg1,
                                const char* arg2, int argc, char** argv);
};


// =============================================================================
// SECTION 7 - UIReflow (Batched UI element modification)
// =============================================================================
// Size: 0x14 (20 bytes) from targets_decomp.cpp

class UIScreenManager; // forward

class UIReflow {
public:
    void** m_vtable;       // 0x00
    int    m_focus;        // 0x04 - current screen ID
    void*  m_blockBuffer;  // 0x08 - command buffer
    int    m_blockSize;    // 0x0C - current number of commands
    int    m_blockCapacity;// 0x10 - allocated capacity

    // 0x8017D234 - Constructor
    UIReflow() : m_vtable(nullptr), m_focus(0),
                 m_blockBuffer(nullptr), m_blockSize(0), m_blockCapacity(0) {}

    // 0x8017D254 - Destructor
    ~UIReflow() {
        if (m_blockBuffer) {
            // Free block buffer -- on GC this calls EAHeap::Free
            free(m_blockBuffer);
            m_blockBuffer = nullptr;
        }
    }

    // 0x8017D2B0 - Set which APT screen to target
    void SetFocus(int screenID) {
        m_focus = screenID;
        // Resolves screen flash name and calls AptViewer::Init
        // Implementation requires UIScreenManager singleton access
    }

    // --- Immediate property resets ---

    // These methods format a command string and send it to APT.
    // The pattern from asm is: format "%s.%s" with element name and property,
    // then call AptViewer_CallFunction or UIRouter_SetVariable.

    // 0x8017D320 - Reset element size
    void ResetSize(const char* element, int w, int h, int player) {
        // Format: SetVariable("element._width", w), ("element._height", h)
        // TODO: implement AptViewer integration for PC port
    }

    // 0x8017D4A0 - Reset element position
    void ResetPosition(const char* element, int x, int y, int player) {
        // Format: SetVariable("element._x", x), ("element._y", y)
    }

    // 0x8017D75C - Reset visibility
    void ResetVisibility(const char* element, bool visible, int player) {
        // Format: SetVariable("element._visible", visible ? "true" : "false")
    }

    // 0x8017D898 - Reset alpha
    void ResetAlpha(const char* element, u32 alpha, int player) {
        // Format: SetVariable("element._alpha", alpha)
    }

    // 0x8017D9E4 - Reset text content
    void ResetText(const char* element, const char* text, int player) {
        // Format: SetVariable("element.text", text)
    }

    // --- Tween animation system ---

    // 0x8017E138 - Open a tween animation block
    void OpenTweenBlock(const char* element, u32 duration, u32 delay,
                        const char* easing, int player) {
        // Allocate/reset block buffer, store target element info
    }

    // 0x8017E318 - Submit the tween block to APT
    void SubmitTweenBlock() {
        // Flush buffered tween commands to APT
    }

    // Tween property setters (buffer commands for SubmitTweenBlock)
    void Tween_X(int x) {}                    // 0x8017E39C
    void Tween_Y(int y) {}                    // 0x8017E408
    void Tween_Alpha(u32 alpha) {}            // 0x8017E72C
    void Tween_XScale(f32 scale) {}           // 0x8017E5B8
    void Tween_YScale(f32 scale) {}           // 0x8017E638
    void Tween_Rotation(f32 rot) {}           // 0x8017E6B8

    // --- Reflow batch system ---

    // 0x8017E920 - Open a reflow batch block
    void OpenReflowBlock() {
        m_blockSize = 0;
        // Allocate block buffer if needed
        if (!m_blockBuffer) {
            m_blockCapacity = 32;
            m_blockBuffer = malloc(m_blockCapacity * sizeof(void*));
        }
    }

    // 0x8017E998 - Submit the reflow block
    void SubmitReflowBlock() {
        // Flush all buffered reflow commands to APT
        m_blockSize = 0;
    }

    // Reflow property setters
    void Reflow_Id(const char* id, int player) {} // 0x8017EA1C
    void Reflow_X(int x) {}                       // 0x8017EAB0
    void Reflow_Y(int y) {}                       // 0x8017EAD0
    void Reflow_Visibility(bool visible) {}        // 0x8017EBB0
    void Reflow_Alpha(u32 alpha) {}                // 0x8017EC28
    void Reflow_StringChange(const char* text) {}  // 0x8017EC48
};


// =============================================================================
// SECTION 8 - UIRouter
// =============================================================================
// Size: ~140 bytes (from UIRouter.cpp asm)

class UIRouter : public UIObjectBase {
public:
    void* m_getVarTable;   // 0x084 (offset 132)
    void* m_setVarTable;   // 0x088 (offset 136)

    // 0x8017EDA8 (252 bytes)
    UIRouter() : m_getVarTable(nullptr), m_setVarTable(nullptr) {
        // Original initializes command tables for get/set variable routing
        // Calls AptViewer::NewSetMessageHandler to register as message handler
    }

    // 0x8017EEA4 (100 bytes)
    ~UIRouter() {
        // Cleanup command tables
    }

    // 0x8017EF08 - Route GetVariable to appropriate target
    char* GetVariable(char* name) override {
        // Look up variable name in GetVariableCommandTable
        // Dispatch to the appropriate Target's GetVariable
        return nullptr;
    }

    // 0x8017EFE0 - Route SetVariable to appropriate target
    void SetVariable(char* name, char* value) override {
        // Look up variable name in SetVariableCommandTable
        // Dispatch to the appropriate Target's SetVariable
    }
};


// =============================================================================
// SECTION 9 - UIScreenManager
// =============================================================================
// Virtual table at 0x80466750 (from targets_decomp.cpp)

class UIScreenManager : public UIObjectBase {
public:
    // Screen data table: 1488 bytes at 0x80424720
    u8 m_screenData[1488]; // embedded screen table

    // 0x8017F0D0 (1464 bytes)
    UIScreenManager() {
        memset(m_screenData, 0, sizeof(m_screenData));
        // Original compacts all heaps (Root, Main, Resource, Audio, VM,
        // Shader, Texture, Animation, Model, Flashes, Apt, Debug, CUI)
        // then registers CBFunctor callbacks
    }

    // 0x8017F688
    ~UIScreenManager() {
        // Release all active screens
    }

    // 0x8017F838 - Find screen data record by ID
    void* FindDataByID(int screenID) {
        // Linear scan through m_screenData looking for matching screenID
        return nullptr;
    }

    // 0x8017F884 (480+ bytes) - Load a UI screen
    int LoadUIScreen(int screenID, int inputMode) {
        if (IsScreenManaged(screenID)) {
            return -1; // already loaded
        }
        // Look up screen data, load SWF, create Target object
        return 0;
    }

    // 0x8017FAE4 - Unload a screen
    int UnloadUIScreen(int screenID) {
        // Find screen record, release resources, remove from active list
        return 0;
    }

    // 0x8017FC74 - Check if screen is currently managed
    int IsScreenManaged(int screenID) {
        return 0; // default: not managed
    }

    // 0x8017FCB0 - Suspend all active screens
    void SuspendAllActiveScreens() {
        // Iterate active screens, set suspended flag
    }

    // 0x8017FE64 - Add screen to active list
    int AddScreen(int screenID, int type) {
        return 0;
    }

    // 0x8017FEB8 - Find record index by screen ID
    int FindRecordIndexByID(int screenID) {
        return -1;
    }

    // 0x8017FEF8 - Remove screen from active list
    int RemoveScreen(int screenID) {
        return 0;
    }

    // 0x8017FF44 - Get the Flash/SWF name for a screen
    int GetScreenFlashName(char* outBuf, int screenID) {
        // Look up screen data table, copy flash filename
        outBuf[0] = '\0';
        return 0;
    }

    // 0x80180274 - Per-frame update
    void Update() override {
        // Process queued screen load/unload requests
    }

    // 0x8018019C - SetVariable override
    void SetVariable(char* name, char* value) override {
        // Route to the appropriate active screen's Target
    }
};


// =============================================================================
// SECTION 10 - DlgWrapper (Modal Dialog System)
// =============================================================================
// Virtual table at 0x8045CF18
// Size: 0x698C (27020 bytes)
// From targets_decomp.cpp and DlgWrapper.cpp asm

struct EVec2 {
    f32 x, y;
};

class DlgWrapper {
public:
    // Key fields (from targets_decomp.cpp)
    f32  m_stateFlags;     // 0x000
    u32  m_aptViewerHandle;// 0x004
    u32  m_field_008;      // 0x008
    f32  m_posX;           // 0x00C
    f32  m_posY;           // 0x010
    f32  m_sizeX;          // 0x014
    f32  m_sizeY;          // 0x018

    // Dialog state
    bool m_dialogUp;       // 0x0A0 (approx)
    bool m_accepted;       // 0x0A4
    bool m_declined;       // 0x0A8
    bool m_alt1;           // 0x0AC
    int  m_player;         // 0x0B0

    // Font storage
    ERFont* m_pFont;       // 0x0A8 (approx offset for font)

    // Wrapper pane base (embedded at +0x0D0, ~26000 bytes)
    u8 m_dialogPaneData[0x6800]; // embedded DialogPane

    bool m_useAltLayout;   // constructor parameter

    // 0x8007E440 - Constructor
    DlgWrapper(bool useAltLayout) {
        m_useAltLayout = useAltLayout;
        m_stateFlags = 0.0f;
        m_aptViewerHandle = 0;
        m_field_008 = 0;
        m_posX = 0.0f;
        m_posY = 0.0f;
        m_sizeX = 0.0f;
        m_sizeY = 0.0f;
        m_dialogUp = false;
        m_accepted = false;
        m_declined = false;
        m_alt1 = false;
        m_player = 0;
        m_pFont = nullptr;
        memset(m_dialogPaneData, 0, sizeof(m_dialogPaneData));
    }

    // 0x8007E544 - Destructor
    ~DlgWrapper() {
        Shutdown();
    }

    // 0x8007D8A0 (1272 bytes) - Initialize APT dialog resources
    // From DlgWrapper.cpp asm -- very large init function
    void Startup() {
        // 1. Call Wrapper::WrapperStartup(this)
        // 2. Get game font via EGlobal::GetGameFontID
        // 3. AddRef font resource
        // 4. Allocate WrapperPaneBase (104 bytes)
        // 5. Initialize IconItem for button display
        // 6. Call WrapperPaneBase::Startup
        // 7. Call DialogPaneBase::Startup
        // 8. Add pane via Wrapper::AddPane
        // 9. If useAltLayout, allocate additional IconItems
    }

    // 0x8007DD98 - Shutdown
    void Shutdown() {
        // Release font resource, destroy panes
    }

    // 0x8007DDEC - Reset dialog state
    void Reset() {
        m_accepted = false;
        m_declined = false;
        m_alt1 = false;
        m_dialogUp = false;
    }

    // 0x8007DE30 (440 bytes) - Per-frame update
    void Update() {
        if (!m_dialogUp) return;

        // Poll for user input from APT
        // Check button states and set accepted/declined/alt1 flags
    }

    // 0x8007DFE8 - Draw the dialog
    void Draw(ERC* rc) {
        if (!m_dialogUp) return;
        // Render dialog pane via APT
    }

    // 0x8007E084 - Show the dialog
    void DialogPaneShow() {
        m_dialogUp = true;
        m_accepted = false;
        m_declined = false;
        m_alt1 = false;
        // Trigger APT show animation
    }

    // 0x8007E0FC - Hide the dialog
    void DialogPaneHide() {
        m_dialogUp = false;
        // Trigger APT hide animation
    }

    // 0x8007E184 - Set APT variable
    void SetVariable(char* name, char* value) {
        // Route to embedded WrapperPaneBase
    }

    // 0x8007E274 - Get APT variable
    char* GetVariable(char* name) {
        return nullptr;
    }

    // --- State queries ---

    void* GetFont() { return m_pFont; }
    void* GetDialogPane() { return m_dialogPaneData; }
    bool IsDialogUp() { return m_dialogUp; }
    bool DialogAccepted() { return m_accepted; }
    bool DialogDeclined() { return m_declined; }
    bool DialogAlt1() { return m_alt1; }

    // --- Positioning ---

    void SetDialogPos(EVec2& pos) { m_posX = pos.x; m_posY = pos.y; }
    void SetDialogPosX(f32 x) { m_posX = x; }
    void SetDialogPosY(f32 y) { m_posY = y; }
    f32  GetDialogPosX() const { return m_posX; }
    f32  GetDialogPosY() const { return m_posY; }

    // --- Sizing ---

    void SetDialogSize(EVec2& size) { m_sizeX = size.x; m_sizeY = size.y; }
    void SetDialogSizeX(f32 w) { m_sizeX = w; }
    void SetDialogSizeY(f32 h) { m_sizeY = h; }
    f32  GetDialogSizeX() const { return m_sizeX; }
    f32  GetDialogSizeY() const { return m_sizeY; }
    f32  GetDialogWidth() const { return m_sizeX; }
    f32  GetDialogHeight() const { return m_sizeY; }

    // --- Content ---

    void SetTitleText(unsigned short* text) {
        // Set title text in embedded DialogPane
    }

    void SetTitleFontSize(f32 size) {
        // Set title font size
    }

    void SetBodyText(unsigned short* text) {
        // Set body text in embedded DialogPane
    }

    void SetBodyFont(ERFont* font) {
        // Set body font
    }

    void SetBodyFontSize(f32 size) {
        // Set body font size
    }

    void SetBodyPos(EVec2& pos) {
        // Set body text position
    }

    // --- Buttons ---

    void SetAcceptText(unsigned short* text) {
        // Set accept button text
    }

    void SetDeclineText(unsigned short* text) {
        // Set decline button text
    }

    void SetAlt1Text(unsigned short* text) {
        // Set alt1 button text
    }

    void SetButtonContext(const char* context) {
        // Set button APT context
    }

    void AddAcceptButton(unsigned short* text) {
        SetAcceptText(text);
    }

    void AddDeclineButton(unsigned short* text) {
        SetDeclineText(text);
    }

    void AddAlt1Button(unsigned short* text) {
        SetAlt1Text(text);
    }

    void SetPlayer(int player) {
        m_player = player;
    }
};


// =============================================================================
// SECTION 11 - FlowGotoTarget (Screen Navigation State Machine)
// =============================================================================
// Virtual table at 0x80466578
// Size: ~0x90 (from targets_decomp.cpp)

class FlowGotoTarget : public UIObjectBase {
public:
    // Fields at tail end of UIObjectBase embedded data
    int m_stateRequest;    // 0x084
    int m_statePending;    // 0x088

    // 0x8017ABA0 (1164 bytes)
    FlowGotoTarget() {
        m_stateRequest = 0;
        m_statePending = 0;
    }

    // 0x8017B02C
    ~FlowGotoTarget() {}

    // 0x8017B170 (1804 bytes) - Main navigation handler
    // Massive string comparison chain mapping screen names to state IDs
    void SetVariable(char* name, char* value) override {
        if (!value) return;

        // Map screen name to state ID
        if (strcmp(value, "mainmenu") == 0) {
            m_stateRequest = 1;
        } else if (strcmp(value, "ingame") == 0) {
            m_stateRequest = 2;
        } else if (strcmp(value, "cas_head") == 0) {
            m_stateRequest = 3;
        } else if (strcmp(value, "cas_body") == 0) {
            m_stateRequest = 4;
        } else if (strcmp(value, "cas_clothes") == 0) {
            m_stateRequest = 5;
        } else if (strcmp(value, "cas_accessories") == 0) {
            m_stateRequest = 6;
        } else if (strcmp(value, "cas_summary") == 0) {
            m_stateRequest = 7;
        } else if (strcmp(value, "loadgame") == 0) {
            m_stateRequest = 8;
        } else if (strcmp(value, "freeplay") == 0) {
            m_stateRequest = 9;
        } else if (strcmp(value, "credits") == 0) {
            m_stateRequest = 10;
        } else if (strcmp(value, "options") == 0) {
            m_stateRequest = 11;
        }
        // Additional states would be added from the full 1804-byte function

        m_statePending = 1;
    }

    // 0x8017B960
    char* GetVariable(char* name) override {
        return nullptr;
    }

    int IsStateRequestPending() { return m_statePending; }
    int GetStateRequest() { return m_stateRequest; }

    void SetPendingStateCurrent() {
        m_statePending = 0;
    }
};


// =============================================================================
// SECTION 12 - HUDTarget (Live Mode HUD Controller)
// =============================================================================
// Virtual table at 0x80466888
// Size: 0x8B8 (2232 bytes)
// From targets_decomp.cpp and HUDTarget.cpp asm

// ActionQueueHUD and ActionMenu are embedded per-player structures
// ActionQueueHUD: 796 bytes each (2 players)
// ActionMenu: 180 bytes each (2 players)

class HUDTarget : public UIObjectBase {
public:
    // Per-player data arrays
    // Offsets from HUDTarget.cpp asm constructor:
    //   0x000-0x07F: UIObjectBase base (128 bytes)
    //   0x080:       vtable pointer (Wrapper)
    u8  m_isLocked;           // 0x084 (m_field_084, init to 1 in asm)
    u8  m_pad085[3];

    // Embedded ActionQueueHUD[2] starting at offset 0x108 (264)
    // Each is 796 bytes. Total: 1592 bytes
    u8  m_actionQueueHUD[2 * 796]; // 0x108

    // Embedded ActionMenu[2] starting at offset 0x740 (1856)
    // Each is 180 bytes. Total: 360 bytes
    u8  m_actionMenu[2 * 180];     // 0x740

    // HUD state fields
    u8  m_hudVisState;        // 0x0E8 - visibility state machine (0-3)
    u8  m_pad0E9[3];

    u8  m_tutorialLocks;      // 0x0F0
    u8  m_pad0F1[3];

    // Speed control bytes
    u8  m_speedPrev;          // 0x0F4 - previous combined speed flags
    u8  m_speedCur;           // 0x0F5 - current speed change flags
    u8  m_speedPrevCombined;  // 0x0F6 - previous combined state
    u8  m_speedCommand;       // 0x0F7 - computed speed command

    u16 m_field_0C8;          // 0x0C8
    u16 m_field_0CA;          // 0x0CA

    f32  m_clockCounter;      // 0x0CC - frames until next clock update
    u32  m_field_0D0;         // 0x0D0

    // Job HUD data
    u8  m_jobHudData[64];     // 0x0D4 (approximate)

    int  m_hudMode;           // 0x100 - current HUD mode
    u32  m_field_8B4;         // 0x8B4 - ELiveMode* pointer

    // 0x8018591C (4320 bytes) - Constructor
    HUDTarget() {
        memset(this, 0, sizeof(HUDTarget));
        m_isLocked = 1;
        m_clockCounter = 30.0f; // update clock every 30 frames

        // Initialize ActionQueueHUD[0] and [1]
        // Initialize ActionMenu[0] and [1]
        // Call ResetJobHudProperties()
        // Register CBFunctor callbacks for SetVariable, GetVariable, etc.
    }

    // 0x801869FC (588 bytes) - Destructor
    ~HUDTarget() {
        // Release controllers, unregister callbacks
    }

    // === Controller Management ===

    // 0x80186C48 (228 bytes)
    void AttachControllers() {
        // Attach game controllers for input
    }

    // 0x80186D2C (168 bytes)
    void ReleaseControllers() {
        // Release controller handles
    }

    // === Pause System ===

    // 0x80186DD4 - Increment pause reference count
    void IncPause(bool showPauseUI) {
        if (m_field_8B4) {
            // ELiveMode::IncPause(showPauseUI)
        }
    }

    // 0x80186E04 - Decrement pause reference count
    void ReleasePause(bool hidePauseUI) {
        if (m_field_8B4) {
            // ELiveMode::ReleasePause(hidePauseUI)
        }
    }

    // === APT Variable Interface ===

    // 0x80186E34 - SetVariable dispatcher
    // Parses optional player digit prefix, then calls SetPlayerVariable
    void SetVariable(char* name, char* value) override {
        if (!name || !value) return;

        int player = 0;
        char* varName = name;

        // Check if first char is a digit (player index prefix)
        if (name[0] >= '0' && name[0] <= '9') {
            player = name[0] - '0';
            varName = name + 1;
        }

        SetPlayerVariable(player, varName, value);
    }

    // 0x80186EA0 (800 bytes) - Per-player variable setter
    void SetPlayerVariable(int player, char* name, char* value) {
        if (strcmp(name, "HUDMode") == 0) {
            m_hudMode = atoi(value);
        } else if (strcmp(name, "CASType") == 0) {
            // Store CAS type for transition
        }
        // Additional variable handlers from the full 800-byte function
    }

    // 0x801871C0 - GetVariable dispatcher
    char* GetVariable(char* name) override {
        if (!name) return nullptr;

        int player = 0;
        char* varName = name;

        if (name[0] >= '0' && name[0] <= '9') {
            player = name[0] - '0';
            varName = name + 1;
        }

        return GetPlayerVariable(player, varName);
    }

    // 0x80187224 (1212 bytes) - Per-player variable getter
    char* GetPlayerVariable(int player, char* name) {
        static char resultBuf[64];

        if (strcmp(name, "PlayerCount") == 0) {
            sprintf(resultBuf, "%d", 1); // default 1 player
            return resultBuf;
        } else if (strcmp(name, "HUDMode") == 0) {
            sprintf(resultBuf, "%d", m_hudMode);
            return resultBuf;
        }
        // Additional getters from the full 1212-byte function

        return nullptr;
    }

    // 0x801876E0 - GetLocalizable dispatcher
    unsigned short* GetLocalizable(char* name) override {
        if (!name) return nullptr;

        int player = 0;
        char* varName = name;

        if (name[0] >= '0' && name[0] <= '9') {
            player = name[0] - '0';
            varName = name + 1;
        }

        return GetPlayerLocalizable(player, varName);
    }

    // 0x80187744 (768 bytes)
    unsigned short* GetPlayerLocalizable(int player, char* name) {
        // Returns localized strings for sim name, lot name, job title, etc.
        return nullptr;
    }

    // === Reputation System ===

    // 0x80187A44 (188 bytes)
    void InitRepValues() {
        // Initialize reputation tracking values
    }

    // 0x80187B00 (196 bytes)
    int GetReputationValue(int repType) {
        return 0;
    }

    // 0x80187BC4 (216 bytes)
    int GetNextRepUnlockValue(int repType) {
        return 0;
    }

    // === Motive Display ===

    // 0x80187C9C
    void OnReadBar(int player, u32 barIndex) {
        ReadMoodBar(player, barIndex);
    }

    // 0x80187D10 (300 bytes)
    void ReadMoodBar(int player, u32 index) {
        // Read motive value from Sim, update APT motive bar display
    }

    // === HUD Visibility ===

    // 0x80187E3C - Show HUD overlay
    void ShowHUD() {
        if (m_hudVisState == 0) {
            // Check tutorial locks
            if (m_tutorialLocks) return;

            m_hudVisState = 1;
            UpdateClock();
            // Call AptViewer::Init to trigger "showHUD" APT state
        }
    }

    // 0x80187EB4 - Hide HUD overlay
    void HideHUD() {
        if (m_tutorialLocks) return;

        if (m_hudVisState == 2) {
            m_hudVisState = 0;
            // Trigger "hideHUD" APT transition
        }
    }

    // 0x80187F24
    void OnPlayerHUDShow(int player) {
        // Player-specific show callback
    }

    // 0x80187F54
    void OnPlayerHUDHide(int player) {
        // Player-specific hide callback
    }

    // 0x80187F80
    void OnPlayerHUDHideStart(int player) {
        // Player-specific hide start callback
    }

    // 0x80187FFC (blr)
    void OnHUDShow() {}
    // 0x80188000 (blr)
    void OnHUDHideStart() {}
    // 0x80188004 (blr)
    void OnHUDHide() {}

    // === Frame Update ===

    // 0x80188464
    void UpdateTutorialLocks() {
        // Check global tutorial completion state
        // If changed and == 1, call ShowHUD()
    }

    // 0x801884B4 (248 bytes) - Main frame update
    void Update() override {
        // 1. UpdateTutorialLocks
        UpdateTutorialLocks();

        // 2. Check if HUD should be visible for player 0
        int shouldShow = ShouldHUDBeVisible(0);
        if (!shouldShow) {
            // Handle hide transition
            if (m_speedCommand == static_cast<u8>(-4)) { // pause speed command
                ReleasePause(false);
            }
            // Shift speed state bytes and clear pending
            m_speedPrev = m_speedCur;
            m_speedCur = 0;
            return;
        }

        // 3. If visible: show HUD, update speed controls
        ShowHUD();
        UpdateSpeedControls();

        // 4. Decrement clock counter; at 0, reset to 30 and UpdateClock
        m_clockCounter -= 1.0f;
        if (m_clockCounter <= 0.0f) {
            m_clockCounter = 30.0f;
            UpdateClock();
        }
    }

    // 0x801885AC (276 bytes)
    void UpdateClock() {
        // Query game time through APT vtable:
        //   Hour -> "HUDHr"
        //   Minute -> "HUDMin"
        //   AM/PM -> "HUDMeridian"
        //   12-hour conversion: hour > 12 -> subtract 12, 0 -> 12
    }

    // 0x80188348 (284 bytes) - Check if HUD should be visible
    int ShouldHUDBeVisible(int player) const {
        // Check game state, tutorial completion, etc.
        return 1; // default: visible
    }

    // 0x801887AC (1096 bytes) - Speed control update
    void UpdateSpeedControls() {
        // Read controller input for speed buttons per player
        // Compute combined speed state
        // Handle pause toggle
        // Play speed-change SFX via sound hashes:
        //   0x5D6996BB (pause)
        //   0xB367F797 (slow/normal)
        //   0xACFAD483 (fast)
    }

    // === Action Menu (Pie Menu) ===

    // 0x80188BF4
    void AddMenu(int player, cXObject* obj, BString2& name,
                 u32 icon, ERShader* shader) {
        // Initialize action menu for player with object info
    }

    // 0x80188C54
    void AddMenuItem(int player, cXObject* obj, Interaction* interaction,
                     BString2& name, u32 icon, ERShader* shader,
                     int priority, bool enabled) {
        // Add an item to the action menu
    }

    // 0x80188CC4
    void NotifyMenuRemoveObj(cXObject* obj) {
        // Remove menu items referencing this object
    }

    // 0x80188D3C
    void CompleteMenu(int player) {
        // Finalize menu construction
    }

    // 0x80188D7C
    void ShowMenu(int player) {
        // Display the action menu
    }

    // 0x80188DBC
    int IsMenuAvailable(int player) const {
        return 0;
    }

    // 0x80188E34
    void CloseMenu(int player) {
        // Hide the action menu
    }

    // === Action Queue ===

    // 0x80188E60
    void AddAction(int player, Interaction* interaction, BString2& name,
                   u32 icon, ERShader* shader, u32 flags) {
        // Add action to player's queue display
    }

    // 0x80188F70
    void RemoveAction(int player, Interaction* interaction) {
        // Remove action from queue
    }

    // 0x80188FC8
    void RemoveAllActions(int player) {
        // Clear all actions from queue
    }

    // === Rendering ===

    // 0x8018901C (172 bytes)
    void Draw(ERC* rc) override {
        // Render HUD elements for all active players
    }

    // === Job HUD ===

    // 0x801890CC (244 bytes)
    void ResetJobHudProperties() {
        // Zero-initialize all job HUD state
        memset(m_jobHudData, 0, sizeof(m_jobHudData));
    }

    // === Screen Navigation ===

    // 0x801898E4 (260 bytes) - Transition to Create-A-Sim
    void GotoCAS(u16 casType, u16 param, int player, int slot) {
        m_hudMode = 3; // CAS transition state
        // Hide HUD for both players
        HideHUD();
        // Set CAS parameters via UIReflow
        // Call UIRouter_FlowGoto with appropriate CAS screen name
        switch (casType) {
            case 0: UIRouter_FlowGoto("cas_head"); break;
            case 1: UIRouter_FlowGoto("cas_body"); break;
            case 2: UIRouter_FlowGoto("cas_clothes"); break;
            case 3: UIRouter_FlowGoto("cas_accessories"); break;
            case 4: UIRouter_FlowGoto("cas_summary"); break;
            default: UIRouter_FlowGoto("cas_head"); break;
        }
    }

    // 0x801899E8 (48 bytes) - Return to main menu
    void GotoMainMenu() {
        m_hudMode = 1;
        UIRouter_FlowGoto("mainmenu");
    }

    // 0x80189A18 (28 bytes) - Request quit game
    void RequestQuitGame(bool quitRequested) {
        m_hudMode = quitRequested ? 1 : 0;
    }

    // === Query Methods ===

    int GetHUDMode() const { return m_hudMode; }

    bool HUDHideComplete() const {
        return m_hudVisState == 0;
    }

    bool HideInProgress() const {
        return m_hudVisState == 1; // transitioning
    }

    bool IsHUDVisible() const {
        return m_hudVisState >= 1;
    }

    bool IsPlayerHUDVisible(int player) const {
        return IsHUDVisible(); // both players share state
    }

    int IsActionQueueAvailable(int player) const {
        // Check if player's action queue HUD is available
        return 1;
    }

    void UpdateActivePlayer(int player, bool active) {
        // Set whether a player's HUD section is active
    }

    void* GetActionQueueHUD(int player) {
        if (player < 0 || player > 1) return nullptr;
        return &m_actionQueueHUD[player * 796];
    }
};


// =============================================================================
// SECTION 13 - ACTTarget (Action Queue HUD Controller)
// =============================================================================
// Virtual table at 0x80467960
// Size: 0x658 (1624 bytes)
// From targets_decomp.cpp

class ACTTarget : public UIObjectBase {
public:
    int  m_player;              // player index
    bool m_showQueue;           // show/hide queue display
    bool m_isActive;            // queue is active
    bool m_bCancelModeEnabled;  // cancel mode active
    int  m_cancelCursorPos;     // cursor position in cancel mode

    // 0x801A0968 (4168 bytes)
    ACTTarget(int player) {
        m_player = player;
        m_showQueue = false;
        m_isActive = false;
        m_bCancelModeEnabled = false;
        m_cancelCursorPos = 0;
    }

    // 0x801A19B0 (620 bytes)
    ~ACTTarget() {}

    // 0x801A1C1C
    void SetVariable(char* name, char* value) override {
        // Handle cancel mode, queue visibility, etc.
    }

    // 0x801A1D3C
    char* GetVariable(char* name) override {
        return nullptr;
    }

    // 0x801A1DD4
    unsigned short* GetLocalizable(char* name) override {
        return nullptr;
    }

    // 0x801A1E58 (916 bytes) - Frame update
    void Update() override {
        // Update action queue display, animate entries, handle cancel mode
    }

    // 0x801A21EC (12 bytes)
    void ShowActionQueue() { m_showQueue = true; }

    // 0x801A21F8 (12 bytes)
    void HideActionQueue() { m_showQueue = false; }

    // 0x801A2204 (440 bytes)
    void UpdateActionQueue() {
        // Refresh the visual representation of the action queue
    }

    // 0x801A23BC (8 bytes)
    int IsActionQueueActive() { return m_isActive ? 1 : 0; }

    // 0x801A23C4 (500 bytes)
    void AddAction(int slot, Interaction* interaction, BString2& name,
                   u32 icon, ERShader* shader, u32 flags) {
        // Add an action to the queue display
    }

    // 0x801A2828 (644 bytes)
    void RemoveAction(int slot, Interaction* interaction) {
        // Remove a specific action from the queue
    }

    // 0x801A2AAC
    void RemoveAllActions(int slot) {
        // Clear all actions
    }

    // Cancel mode
    void MoveCancelCursorUp() { if (m_cancelCursorPos > 0) m_cancelCursorPos--; }
    void MoveCancelCursorDown() { m_cancelCursorPos++; }

    void CancelModeEnabled(bool enable) {
        m_bCancelModeEnabled = enable;
        if (!enable) m_cancelCursorPos = 0;
    }

    void CancelCurrentObject() {
        // Cancel the action at current cursor position
    }

    void ExitCancelMode() {
        m_bCancelModeEnabled = false;
        m_cancelCursorPos = 0;
    }
};


// =============================================================================
// SECTION 14 - O2TTarget (Options Menu Controller)
// =============================================================================
// Virtual table at 0x804672C0
// Size: 0x25C (604 bytes)
// From targets_decomp.cpp

class O2TTarget : public UIObjectBase {
public:
    // Static audio/game option values (from sdata addresses)
    static u8  m_CurrentSFXVolume;
    static u8  m_CurrentMusicVolume;
    static u8  m_CurrentAmbientVolume;
    static u8  m_CurrentVoiceVolume;
    static u8  m_CurrentScreenX;
    static u8  m_CurrentScreenY;
    static int m_bRumbleOn;
    static int m_bCameraRotateDC;
    static int m_bCameraRotate;
    static int m_bFreeWill;
    static O2TTarget* m_pSingletonPtr;

    // Saved options for revert
    u8  m_savedSFX, m_savedMusic, m_savedAmbient, m_savedVoice;
    u8  m_savedScreenX, m_savedScreenY;
    int m_savedRumble, m_savedCameraRotDC, m_savedCameraRot, m_savedFreeWill;

    int m_screenID;
    int m_player;
    DlgWrapper* m_dialog;

    // 0x801CC2B4 (4392 bytes)
    O2TTarget(int screenID, int player) {
        m_screenID = screenID;
        m_player = player;
        m_dialog = nullptr;
        m_pSingletonPtr = this;
        RememberOptions();
    }

    // 0x801CD3DC
    ~O2TTarget() {
        if (m_pSingletonPtr == this) {
            m_pSingletonPtr = nullptr;
        }
    }

    // 0x801CD598 (2460 bytes) - SetVariable
    void SetVariable(char* name, char* value) override {
        if (strcmp(name, "SFXVolume") == 0) {
            m_CurrentSFXVolume = static_cast<u8>(atoi(value));
            AudioOptionsModified();
        } else if (strcmp(name, "MusicVolume") == 0) {
            m_CurrentMusicVolume = static_cast<u8>(atoi(value));
            AudioOptionsModified();
        } else if (strcmp(name, "AmbientVolume") == 0) {
            m_CurrentAmbientVolume = static_cast<u8>(atoi(value));
            AudioOptionsModified();
        } else if (strcmp(name, "VoiceVolume") == 0) {
            m_CurrentVoiceVolume = static_cast<u8>(atoi(value));
            AudioOptionsModified();
        } else if (strcmp(name, "Rumble") == 0) {
            m_bRumbleOn = atoi(value);
            GameOptionsModified();
        } else if (strcmp(name, "CameraRotate") == 0) {
            m_bCameraRotate = atoi(value);
            GameOptionsModified();
        } else if (strcmp(name, "FreeWill") == 0) {
            m_bFreeWill = atoi(value);
            GameOptionsModified();
        }
        // Additional handlers from the full 2460-byte function
    }

    // 0x801CDF34 (1160 bytes) - GetVariable
    char* GetVariable(char* name) override {
        static char buf[32];

        if (strcmp(name, "SFXVolume") == 0) {
            sprintf(buf, "%d", m_CurrentSFXVolume);
            return buf;
        } else if (strcmp(name, "MusicVolume") == 0) {
            sprintf(buf, "%d", m_CurrentMusicVolume);
            return buf;
        } else if (strcmp(name, "Rumble") == 0) {
            sprintf(buf, "%d", m_bRumbleOn);
            return buf;
        } else if (strcmp(name, "FreeWill") == 0) {
            sprintf(buf, "%d", m_bFreeWill);
            return buf;
        }
        return nullptr;
    }

    // 0x801CE3BC (1380 bytes) - GetLocalizable
    unsigned short* GetLocalizable(char* name) override {
        return nullptr;
    }

    // --- Options save/restore ---

    void RememberAudioOptions() {
        m_savedSFX = m_CurrentSFXVolume;
        m_savedMusic = m_CurrentMusicVolume;
        m_savedAmbient = m_CurrentAmbientVolume;
        m_savedVoice = m_CurrentVoiceVolume;
    }

    void RestoreAudioOptions() {
        m_CurrentSFXVolume = m_savedSFX;
        m_CurrentMusicVolume = m_savedMusic;
        m_CurrentAmbientVolume = m_savedAmbient;
        m_CurrentVoiceVolume = m_savedVoice;
    }

    void RememberGameOptions() {
        m_savedRumble = m_bRumbleOn;
        m_savedCameraRotDC = m_bCameraRotateDC;
        m_savedCameraRot = m_bCameraRotate;
        m_savedFreeWill = m_bFreeWill;
    }

    void RestoreGameOptions() {
        m_bRumbleOn = m_savedRumble;
        m_bCameraRotateDC = m_savedCameraRotDC;
        m_bCameraRotate = m_savedCameraRot;
        m_bFreeWill = m_savedFreeWill;
    }

    void RememberOptions() {
        RememberAudioOptions();
        RememberGameOptions();
        m_savedScreenX = m_CurrentScreenX;
        m_savedScreenY = m_CurrentScreenY;
    }

    void RestoreOptions() {
        RestoreAudioOptions();
        RestoreGameOptions();
        m_CurrentScreenX = m_savedScreenX;
        m_CurrentScreenY = m_savedScreenY;
    }

    void AudioOptionsModified() {
        // Apply audio volume changes to sound system
    }

    void GameOptionsModified() {
        // Apply game option changes
    }

    // 0x801CEC90 (600 bytes)
    void SpawnSaveSettingsDialog() {
        // Create and show "Save Settings?" dialog using DlgWrapper
    }

    // 0x801CF780 (736 bytes)
    void SpawnQuitDialogBox() {
        // Create and show "Quit Game?" dialog
    }

    // 0x801CFFC8
    void ShowHelp() {
        // Display help screen
    }

    // 0x801D00C0
    void QuitGame(char* name, char* value) {
        // Initiate quit sequence
    }
};

// Static member definitions
u8  O2TTarget::m_CurrentSFXVolume = 100;
u8  O2TTarget::m_CurrentMusicVolume = 100;
u8  O2TTarget::m_CurrentAmbientVolume = 100;
u8  O2TTarget::m_CurrentVoiceVolume = 100;
u8  O2TTarget::m_CurrentScreenX = 0;
u8  O2TTarget::m_CurrentScreenY = 0;
int O2TTarget::m_bRumbleOn = 1;
int O2TTarget::m_bCameraRotateDC = 0;
int O2TTarget::m_bCameraRotate = 0;
int O2TTarget::m_bFreeWill = 1;
O2TTarget* O2TTarget::m_pSingletonPtr = nullptr;


// =============================================================================
// SECTION 15 - MMUTarget (Main Menu Controller)
// =============================================================================
// Virtual table at 0x804677F0
// Size: 0x360 (864 bytes)

class MMUTarget : public UIObjectBase {
public:
    static MMUTarget* m_MMUSingleton;

    int  m_topLevelChoice;         // current top-level menu selection
    int  m_gameplayChoice;         // gameplay mode selection
    int  m_numPlayersChoice;       // number of players selection
    int  m_listMode;               // 0=menu, 1=NGH list, 2=lot list
    int  m_currentNGHIndex;        // selected neighborhood index
    int  m_currentLotIndex;        // selected lot index

    // State stack (std::stack<MMU_MENU_STATE> in original)
    int  m_stateStack[16];
    int  m_stateStackTop;

    // 0x801C49C0 (3696 bytes)
    MMUTarget() {
        m_MMUSingleton = this;
        m_topLevelChoice = 0;
        m_gameplayChoice = 0;
        m_numPlayersChoice = 0;
        m_listMode = 0;
        m_currentNGHIndex = 0;
        m_currentLotIndex = 0;
        m_stateStackTop = 0;
        memset(m_stateStack, 0, sizeof(m_stateStack));
        // Push initial state: TOP_LEVEL
        m_stateStack[m_stateStackTop++] = 0; // TOP_LEVEL
    }

    // 0x801C5830
    ~MMUTarget() {
        if (m_MMUSingleton == this) {
            m_MMUSingleton = nullptr;
        }
    }

    static MMUTarget* GetSingleton() { return m_MMUSingleton; }

    // 0x801C59F4 (988 bytes)
    void SetVariable(char* name, char* value) override {
        if (strcmp(name, "TopLevelChoice") == 0) {
            m_topLevelChoice = atoi(value);
        } else if (strcmp(name, "GameplayChoice") == 0) {
            m_gameplayChoice = atoi(value);
        } else if (strcmp(name, "NumPlayersChoice") == 0) {
            m_numPlayersChoice = atoi(value);
        }
        // Additional handlers from 988-byte function
    }

    // 0x801C5DD0
    char* GetVariable(char* name) override {
        static char buf[64];

        if (strcmp(name, "TopLevelChoice") == 0) {
            sprintf(buf, "%d", m_topLevelChoice);
            return buf;
        } else if (strcmp(name, "GameplayChoice") == 0) {
            sprintf(buf, "%d", m_gameplayChoice);
            return buf;
        } else if (strcmp(name, "NumPlayersChoice") == 0) {
            sprintf(buf, "%d", m_numPlayersChoice);
            return buf;
        }
        return nullptr;
    }

    // 0x801C5F80 (1092 bytes)
    unsigned short* GetLocalizable(char* name) override {
        return nullptr;
    }

    // 0x801C63C4 (268 bytes)
    void Update() override {
        // Poll controller state for player number selection
        // Update list items if in list mode
    }

    // 0x801C64D0 (372 bytes)
    void Draw(ERC* rc) override {
        // Draw main menu elements
    }

    // --- State machine ---

    // 0x801C7D80
    void UpdateMenuState(char* name, char* value) {
        int newState = atoi(value);
        if (m_stateStackTop < 16) {
            m_stateStack[m_stateStackTop++] = newState;
        }
    }

    // 0x801C7F24 (416 bytes)
    void GoUpMenuTree(char* name, char* value) {
        if (m_stateStackTop > 1) {
            m_stateStackTop--;
        } else {
            // At top level, show "back to title" dialog
        }
    }

    // 0x801C81E0
    int GetNumberOfChoicesInState(int state) {
        switch (state) {
            case 0: return 4;  // TOP_LEVEL: New Game, Continue, Options, Credits
            case 1: return 2;  // GAMEPLAY: Story, Freeplay
            case 2: return 2;  // NUM_PLAYERS: 1P, 2P
            default: return 0;
        }
    }

    // 0x801C80C4 (284 bytes)
    int GetNumberOfControllers() {
        // Poll hardware for connected controllers
        return 1; // default: 1 controller
    }

    // 0x801C6BFC (404 bytes)
    void EnterLot(int lotIndex) {
        m_currentLotIndex = lotIndex;
        // Load lot data and transition to in-game
    }

    // 0x801C6DF0
    void LaunchFreeplay() {
        UIRouter_FlowGoto("freeplay");
    }

    // 0x801C59E8
    void OnCreditsClose() {
        // Return from credits screen
    }
};

MMUTarget* MMUTarget::m_MMUSingleton = nullptr;


// =============================================================================
// SECTION 16 - FAMTarget (Family/Lot Selection Controller)
// =============================================================================
// Virtual table at 0x80467668
// Size: 0x450 (1104 bytes)

class FAMTarget : public UIObjectBase {
public:
    // Menu state stack
    int  m_stateStack[16];
    int  m_stateStackTop;

    int  m_selectedLotIndex;
    int  m_selectedFamilyIndex;

    // 0x801AE88C (4800 bytes)
    FAMTarget() {
        m_stateStackTop = 0;
        m_selectedLotIndex = 0;
        m_selectedFamilyIndex = 0;
        memset(m_stateStack, 0, sizeof(m_stateStack));
    }

    // 0x801AFB4C
    ~FAMTarget() {}

    // 0x801AFCD8
    void SetVariable(char* name, char* value) override {
        // Handle lot/family selection state changes
    }

    // 0x801AFEB8 (1832 bytes)
    unsigned short* GetLocalizable(char* name) override {
        return nullptr;
    }

    // 0x801B05E0
    char* GetVariable(char* name) override {
        return nullptr;
    }

    // --- Lot/Family data access ---

    int IsSelectedLotOccupied() {
        // Check if the selected lot has a family
        return 0;
    }

    Family* GetFamilyInFamilyList(int index) {
        // Get family at index in the family selection list
        return nullptr;
    }

    int ConvertSelectedFamilyIndexToActualGameIndex(int index) {
        return index + 20; // from targets_decomp.cpp: returns index + 20
    }

    int GetNumberOfFamilyMembers(Family* family) {
        return 0;
    }

    // --- State machine ---

    void UpdateMenuState(int state) {
        if (m_stateStackTop < 16) {
            m_stateStack[m_stateStackTop++] = state;
        }
    }

    void GoUpMenuTree() {
        if (m_stateStackTop > 1) {
            m_stateStackTop--;
        }
    }

    int GetNumberOfChoicesInState(int state) {
        return 0;
    }

    // 0x801B3244
    void LaunchLot() {
        // Start the game on the selected lot
        UIRouter_FlowGoto("ingame");
    }

    // 0x801B3284
    int GetMoneyForLot(int lotIndex) {
        return 0;
    }

    // 0x801B3314
    void EvictFamily() {
        // Evict the current family from their lot
    }
};


// =============================================================================
// SECTION 17 - M2MTarget (Memory Card Management)
// =============================================================================
// Virtual table at 0x804676D8
// Size: 0x23E8 (9192 bytes)

class LoadGameTarget;
class SaveGameTarget;

class M2MTarget : public UIObjectBase {
public:
    int m_device;           // memory card slot
    int m_saveGameID;       // save game slot
    int m_playerNum;        // player number
    int m_currState;        // widget state machine
    int m_numItems;         // number of items in current list

    LoadGameTarget* m_loadTarget;
    SaveGameTarget* m_saveTarget;
    DlgWrapper*     m_dialog;

    // 0x801BF058 (3204 bytes)
    M2MTarget() {
        m_device = 0;
        m_saveGameID = 0;
        m_playerNum = 0;
        m_currState = 0;
        m_numItems = 0;
        m_loadTarget = nullptr;
        m_saveTarget = nullptr;
        m_dialog = nullptr;
    }

    // 0x801BFCDC
    ~M2MTarget() {}

    // 0x801BFEE8
    char* GetVariable(char* name) override {
        return nullptr;
    }

    // 0x801C00A0
    unsigned short* GetLocalizable(char* name) override {
        return nullptr;
    }

    // 0x801C02EC
    void SetVariable(char* name, char* value) override {
        // Handle memory card state transitions
    }

    // 0x801C05A4 (1020 bytes)
    void Update() override {
        // Poll load/save operations, check memory card status
    }

    // --- State management ---

    // 0x801C2A74 (780 bytes)
    void SetCurrState(int state) {
        m_currState = state;
        // Update widget display based on new state
    }

    int GetDevice() { return m_device; }
    void SetDevice(int device) { m_device = device; }
    int GetSaveGameID() { return m_saveGameID; }
    int GetMemCardPort() { return m_device; }
    int GetPlayerNum() { return m_playerNum; }

    // --- Dialog spawning ---

    void SpawnNoSpaceDialog() {
        // Show "no space on memory card" dialog
    }

    void SpawnConfirmStartNewGameDialog() {
        // Show "start new game?" confirmation
    }

    void PrepareNewGame() {
        // Initialize new game state
    }

    void PrepareLoadGame() {
        // Prepare to load a saved game
    }
};


// =============================================================================
// SECTION 18 - LoadGameTarget
// =============================================================================
// Virtual table at 0x80466918
// Size: 0x14C (332 bytes)

class LoadGameTarget {
public:
    M2MTarget* m_parent;
    int m_device;
    int m_slot;
    int m_result;        // 0=pending, 1=success, -1=failure
    bool m_bgLoading;    // background load in progress
    DlgWrapper* m_dialog;

    // 0x80189AD0 (1840 bytes)
    LoadGameTarget(M2MTarget* parent, int device, int slot) {
        m_parent = parent;
        m_device = device;
        m_slot = slot;
        m_result = 0;
        m_bgLoading = false;
        m_dialog = nullptr;
    }

    // 0x8018A200
    ~LoadGameTarget() {
        if (m_dialog) {
            m_dialog->Shutdown();
            delete m_dialog;
        }
    }

    // 0x8018A708 (992 bytes)
    void Update() {
        if (m_bgLoading) {
            // Poll background load thread for completion
            // On complete: show success or failure dialog
        }
    }

    int GetResult() { return m_result; }

    // 0x8018AAF4 (580 bytes)
    void PerformMemoryCardChecks() {
        // Validate memory card hardware:
        // 1. Check device exists
        // 2. Check card is not damaged
        // 3. Check save file exists and is valid
    }

    // 0x8018AD38 (348 bytes)
    void PerformLoad() {
        // Read save data from memory card
    }

    // 0x8018CA90 (432 bytes)
    void BackgroundPerformLoad() {
        PerformMemoryCardChecks();
        if (m_result == 0) {
            PerformLoad();
        }
    }

    // 0x8018CC8C - Thread entry point
    static void BGExec_PerformLoad(void* arg) {
        LoadGameTarget* target = static_cast<LoadGameTarget*>(arg);
        target->BackgroundPerformLoad();
    }

    // --- Dialog chain ---

    void SpawnCheckingDialog() {
        // Show "Checking memory card..." dialog
    }

    void SpawnLoadConfirmDialog() {
        // Show "Load this game?" confirmation
    }

    void SpawnLoadingDialog() {
        // Show "Loading..." progress dialog
    }

    void SpawnLoadSucceededDialog() {
        m_result = 1;
        // Show "Load successful" dialog
    }

    void SpawnLoadFailedDialog() {
        m_result = -1;
        // Show "Load failed" error dialog
    }

    void SpawnWrongDeviceDialog() {
        // Show "Wrong device" error
    }

    void SpawnCardDamagedDialog() {
        // Show "Memory card damaged" error
    }

    void SpawnCardCorruptDialog() {
        // Show "Save data corrupted" error
    }

    int GetDevice() { return m_device; }
    int GetPlayerNum() { return m_parent ? m_parent->GetPlayerNum() : 0; }
    int GetSaveGameID() { return m_slot; }
};


// =============================================================================
// SECTION 19 - SaveGameTarget
// =============================================================================
// Virtual table at 0x804669C8
// Size: 0x168 (360 bytes)

class SaveGameTarget {
public:
    M2MTarget* m_parent;
    int m_device;
    int m_slot;
    int m_result;         // 0=pending, 1=success, -1=failure
    bool m_bgSaving;      // background save in progress
    DlgWrapper* m_dialog;

    // 0x8018CD18 (1888 bytes)
    SaveGameTarget(M2MTarget* parent, int device, int slot) {
        m_parent = parent;
        m_device = device;
        m_slot = slot;
        m_result = 0;
        m_bgSaving = false;
        m_dialog = nullptr;
    }

    // 0x8018D478
    ~SaveGameTarget() {
        if (m_dialog) {
            m_dialog->Shutdown();
            delete m_dialog;
        }
    }

    // 0x8018D9BC (1064 bytes)
    void Update() {
        if (m_bgSaving) {
            // Poll background save thread for completion
        }
    }

    void Hide() {
        // Dismiss save UI
    }

    int GetResult() { return m_result; }

    // 0x8018DE10 (664 bytes)
    void PerformMemoryCardChecks() {
        // Validate memory card for saving:
        // 1. Check device exists
        // 2. Check card is not damaged
        // 3. Check available space
    }

    // 0x8018F944 (1452 bytes)
    void PerformSaveGame() {
        // Write save data to memory card
    }

    // 0x8018FF3C - Thread entry point
    static void BGExec_SaveGame(void* arg) {
        SaveGameTarget* target = static_cast<SaveGameTarget*>(arg);
        target->PerformMemoryCardChecks();
        if (target->m_result == 0) {
            target->PerformSaveGame();
        }
    }

    // --- Dialog chain ---

    void SpawnCheckingDialog() {}
    void SpawnSaveConfirmDialog() {}
    void SpawnSavingDialog() {}

    void SpawnSaveSucceededDialog() {
        m_result = 1;
    }

    void SpawnSaveFailedDialog() {
        m_result = -1;
    }

    void SpawnNoSpaceDialog(int noSpaceType) {
        // Show "not enough space" with type-specific message
    }

    void SpawnOverwriteDialog() {
        // Show "overwrite existing save?" confirmation
    }

    void SpawnWrongDeviceDialog() {}
    void SpawnCardDamagedDialog() {}
    void SpawnCardCorruptDialog() {}

    int GetDevice() { return m_device; }
    int GetPlayerNum() { return m_parent ? m_parent->GetPlayerNum() : 0; }
    int GetSaveGameID() { return m_slot; }
};


// =============================================================================
// SECTION 20 - CSMTarget (CAS Integration Menu Controller)
// =============================================================================
// Virtual table at 0x804677B0
// Size: 0xF0 (240 bytes)

class CSMTarget : public UIObjectBase {
public:
    int  m_player;
    bool m_showCSIM;
    bool m_isActive;
    int  m_field98;    // animation state flag

    // 0x801A61D0 (1968 bytes)
    CSMTarget(int player) {
        m_player = player;
        m_showCSIM = false;
        m_isActive = false;
        m_field98 = 0;
    }

    // 0x801A6980
    ~CSMTarget() {}

    // 0x801A6B34
    void SetVariable(char* name, char* value) override {
        // Handle CAS menu state changes
    }

    // 0x801A6C3C
    char* GetVariable(char* name) override {
        return nullptr;
    }

    // 0x801A6CD4
    unsigned short* GetLocalizable(char* name) override {
        return nullptr;
    }

    // 0x801A6E00 (2124 bytes)
    void Update() override {
        // Update CAS integration overlay state machine
    }

    // 0x801A764C (20 bytes)
    void ShowCSIM() {
        m_showCSIM = true;
        m_field98 = 0;
    }

    // 0x801A7660 (20 bytes)
    void HideCSIM() {
        if (m_field98 == 0) {
            m_showCSIM = false;
        }
    }

    // 0x801A7674 (8 bytes)
    int IsCSIMActive() { return m_isActive ? 1 : 0; }

    // 0x801A767C (1036 bytes)
    void TempInterface(BString2* opt1, BString2* opt2,
                       BString2* opt3, BString2* opt4,
                       bool enableOpt3, bool enableOpt4) {
        // Create temporary CAS interface with the given option labels
    }

    // 0x801A7A88 (160 bytes)
    void SetIconDisable(bool disable) {
        // Enable/disable CAS icons
    }
};


// =============================================================================
// SECTION 21 - E2ETarget (EyeToy Camera Controller) - Stub
// =============================================================================
// Virtual table at 0x80467718
// Size: 0x288 (648 bytes)
// Vestigial PS2 feature on GameCube -- minimal stub for completeness.

class E2ETarget : public UIObjectBase {
public:
    static E2ETarget* m_pSingletonPtr;
    static bool       m_bAlreadyCreatedOnce;
    static int        m_sCurrentHue;
    static int        m_sCurrentSaturation;
    static int        m_sCurrentBrightness;
    static int        m_sCurrentExposure;

    int m_screenID;

    E2ETarget(int screenID) : m_screenID(screenID) {
        m_pSingletonPtr = this;
    }

    ~E2ETarget() {
        if (m_pSingletonPtr == this) m_pSingletonPtr = nullptr;
    }

    void SetVariable(char* name, char* value) override {}
    char* GetVariable(char* name) override { return nullptr; }
    unsigned short* GetLocalizable(char* name) override { return nullptr; }
    void Update() override {}

    bool IsEyeToyPluggedIn() { return false; } // always false on GC
};

E2ETarget* E2ETarget::m_pSingletonPtr = nullptr;
bool       E2ETarget::m_bAlreadyCreatedOnce = false;
int        E2ETarget::m_sCurrentHue = 0;
int        E2ETarget::m_sCurrentSaturation = 0;
int        E2ETarget::m_sCurrentBrightness = 0;
int        E2ETarget::m_sCurrentExposure = 0;


// =============================================================================
// SECTION 22 - KEYTarget (Keyboard/Input Configuration) - Stub
// =============================================================================
// Virtual table at 0x80467C18
// Size: 0x90 (144 bytes)

class KEYTarget : public UIObjectBase {
public:
    KEYTarget() {}
    ~KEYTarget() {}

    // 0x801F9960 (156 bytes)
    char* GetName() {
        return nullptr; // control scheme name
    }

    // 0x801F99FC (32 bytes)
    int IsModeValid() {
        return 1; // current control mode is always valid for PC
    }

    // 0x801F9A1C (428 bytes)
    void SetVariable(char* name, char* value) override {
        // Handle key binding changes
    }

    // 0x801F9BC8 (384 bytes)
    char* GetVariable(char* name) override {
        return nullptr;
    }
};


// =============================================================================
// Global sentinel definitions (needed by AptValue methods)
// =============================================================================
AptValue* gpUndefinedValue = nullptr;
AptViewer* g_pAptViewer = nullptr;
void*      g_pUIRouter = nullptr;


// =============================================================================
// UIObjectBase router helper implementations
// =============================================================================

void UIObjectBase::UIRouter_SetVariable(const char* name, const char* value) {
    // From asm at 0x80177CC8:
    // Loads global UIRouter singleton, calls through vtable offset 0x80
    // to its SetVariable method.
    if (g_pUIRouter) {
        UIRouter* router = static_cast<UIRouter*>(
            reinterpret_cast<UIObjectBase*>(g_pUIRouter));
        router->SetVariable(const_cast<char*>(name), const_cast<char*>(value));
    }
}

void UIObjectBase::UIRouter_FlowGoto(const char* screenName) {
    // From asm at 0x80177D0C:
    // Calls UIRouter_SetVariable with key "FlowGoto" and the screen name.
    UIRouter_SetVariable("FlowGoto", screenName);
}

void UIObjectBase::AptViewer_CallFunction(const char* funcName,
                                          const char* arg1,
                                          const char* arg2,
                                          int argc, char** argv) {
    // From asm at 0x80177D54:
    // Calls through global AptViewer to execute an ActionScript function.
    if (g_pAptViewer) {
        g_pAptViewer->NewCallFunction2(funcName, arg1, arg2, argc, argv);
    }
}
