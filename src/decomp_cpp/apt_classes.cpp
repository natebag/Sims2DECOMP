// =============================================================================
// apt_classes.cpp - All APT Class Decompilations
// =============================================================================
//
// Decompiled C++ for the Sims 2 GameCube APT UI subsystem classes.
// Converted from PPC inline assembly (src/asm_decomp/Apt*.cpp) using
// struct layouts, field offsets, and calling conventions from the
// existing decomp in src/decomp_cpp/ui_system.cpp.
//
// This file covers:
//   AptValue, AptBoolean, AptFloat, AptInteger, AptNone, AptExtern,
//   AptString, AptObject, AptPrototype, AptArray, AptValueWithHash,
//   AptValueVector, AptValueFactory, AptGC, AptCharacter,
//   AptDisplayListState, AptError, AptXmlNode, AptXml,
//   AptXmlAttributes, AptScriptFunctionBase, AptScriptFunction1,
//   AptScriptFunction2, AptScriptFunctionByteCodeBlock,
//   AptViewer, AptWord, AptParagraph, AptTextFormat, AptDate,
//   AptDisplayList, AptCIH, AptMathObj, AptActionInterpreter,
//   AptLinker, AptLoader, AptCharacterInst, AptAnimationPoolData,
//   AptStage, AptSound, AptNativeHash, AptFormat, AptMovie,
//   AptMovieClip, AptKey, AptLine, AptGlobal, AptGlobalExtensionObject,
//   AptRegister, AptRenderingContext, AptShaderWord, AptUserFunctions,
//   AptPseudoCIH_t, AptPseudoData_t, AptPseudoDisplayList,
//   AptCharacterTextInst, AptCharacterButtonInst, AptCharacterSpriteInstBase,
//   AptCharacterAnimationInst, AptCharacterMorphInst, AptCharacterShapeInst,
//   AptCharacterStaticTextInst, AptCharacterSpriteInst,
//   AptActionQueueC, AptIntervalTimer, AptFrameStack, AptLoadVars,
//   AptLookup, AptMemoryAllocationsT, AptNativeFunction,
//   AptSavedInputCheckpoints, AptScriptColour, AptStringObject
//
// All struct offsets are derived from the PPC assembly analysis and
// verified against the inline asm in src/asm_decomp/*.cpp.
//
// =============================================================================

#include "types.h"
extern "C" {
    void* malloc(unsigned int size);
    void  free(void* ptr);
    void* memset(void* dst, int c, unsigned int n);
    void* memcpy(void* dst, const void* src, unsigned int n);
    int   memcmp(const void* a, const void* b, unsigned int n);
    unsigned int strlen(const char* s);
    int   strcmp(const char* a, const char* b);
    int   strncmp(const char* a, const char* b, unsigned int n);
    char* strcpy(char* dst, const char* src);
    char* strcat(char* dst, const char* src);
    int   sprintf(char* buf, const char* fmt, ...);
    int   printf(const char* fmt, ...);
    double sqrt(double x);
    double fabs(double x);
    double floor(double x);
    double ceil(double x);
}

// -- Basic types (matching include/types.h) --
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef float f32;


// =============================================================================
// Forward Declarations
// =============================================================================
class AptValue;
class AptCIH;
class AptCharacterInst;
class AptMatrix;
class AptRect;
class AptRenderingContext;
class AptNativeHash;
class AptFile;
class AptMovie;
class AptConstFile;
class AptCharacter;
class AptArray;
class AptAction_DefineFunction;
class AptAction_DefineFunction2;
class AptInitParmsT;
class IAptXmlNode;
class TextFormat;
struct AptMovieclipInformation;
struct AptMaskRenderOperation { int value; };
struct _AptScriptFunctionState;
class UIObjectBase;
class ERC;
class ERFont;
class EMat4;
class EVec2;
class EVec4;
class EMutex;
class E3DWindow;
class EWindow;
class EAHeap;
struct ECTRL_CMD;

// =============================================================================
// Type tag enum
// =============================================================================
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
    APT_VFT_ERROR            = 41,
    APT_VFT_STRING2          = 42,
    APT_VFT_SCRIPTFUNCTION1  = 43,
    APT_VFT_SCRIPTFUNCTION2  = 44,
    APT_VFT_SCRIPTFUNCTIONBC = 45,
    APT_VFT_DISPLAYLISTSTATE = 46,
};


// =============================================================================
// EAStringC internal data layout
// =============================================================================
struct EAStringCInternalData {
    u16 m_refCount;    // 0x00
    u16 m_pad;         // 0x02
    u16 m_length;      // 0x04
    u16 m_pad2;        // 0x06
    // char m_data[];  // 0x08 onwards
    const char* data() const { return reinterpret_cast<const char*>(this) + 8; }
    char* data_mut() { return reinterpret_cast<char*>(this) + 8; }
};

struct EAStringC {
    EAStringCInternalData* m_pData; // 0x00

    EAStringC();
    EAStringC(const char* str);
    EAStringC(EAStringC& other);
    ~EAStringC();

    const char* c_str() const;
    bool IsEmpty() const;
    bool IsEnoughSize(u32 size) const;
    void ReserveSize(u32 size);
    void Clear();
    bool Equal(const char* str) const;
    void operator=(EAStringC& other);
    void Duplicate(EAStringC& other);
    void InitFromBuffer(const char* buf);
    operator char*() const;
};


// =============================================================================
// DOGMA_PoolManager / AptValueGC_PoolManager
// =============================================================================
class DOGMA_PoolManager {
public:
    void* Allocate(u32 size);
    void  Deallocate(void* ptr, u32 size);
};

class AptValueGC_PoolManager {
public:
    AptValue* AllocateAptValueGC(u32 size);
    void DeallocateAptValueGC(AptValue* val, u32 size);
    AptValue* GetFirstAptValue();
    AptValue* GetNextAptValue(AptValue* val);
};


// =============================================================================
// Global Externs (r13-relative in original PPC binary)
// =============================================================================

// Pool heads for primitive value types
extern AptValue* g_pBooleanPool;        // r13 - 26916
extern AptValue* g_pFloatPool;          // r13 - 26912
extern AptValue* g_pIntegerPool;        // r13 - 26908
extern AptValue* g_pStringPool;         // r13 - 26892

// Allocators
extern DOGMA_PoolManager*       g_pDogmaPoolMgr;       // r13 - 23020
extern AptValueGC_PoolManager*  g_pAptValueGCPoolMgr;  // r13 - 23016

// GC
extern AptValue*  g_pAptValueVector;     // r13 - 27600
extern u32        g_bInDeleteCycle;      // r13 - 27028
extern void*      g_pGCRegistrationCb;   // r13 - 27024

// Sentinel / undefined
extern AptValue*  gpUndefinedValue;      // r13 - 22936

// Statics for AptError
extern AptValue*  g_pErrorNativeFuncs;   // r13 - 27112

// Various native function statics
extern AptValue*  g_pXmlNFBytesTotal;    // r13 - 26956
extern AptValue*  g_pXmlNFBytesLoaded;   // r13 - 26952
extern AptValue*  g_pXmlNFLoad;          // r13 - 26948
extern AptValue*  g_pXmlNFParseXml;      // r13 - 26944

// AptScriptFunctionBase statics
extern u32        g_nStaticDataCount;    // r13 - 26964
extern AptValue** g_pStaticDataArray;    // r13 - 26976
extern AptValue** g_pStaticDataCurrent;  // r13 - 26972
extern u32        g_nStaticDataUsed;     // r13 - 26968
extern AptValue*  g_pFrameStackLocal;    // r13 - 26960

// External function declarations
extern void AptRegisterGlobalReferences();
extern void AptBoolean_ClearPool();
extern void AptFloat_ClearPool();
extern void AptInteger_ClearPool();
extern void StringPool_ClearTemporaryPool();
extern int  AptGetSwfVersion();
extern f32  Apt_atoff(const char* str);
extern int  _AptGetAnimationAtLevel(int level);


// =============================================================================
// AptValueVector
// =============================================================================

// Layout:
//   0x00: u32 m_capacity
//   0x04: u32 m_count
//   0x08: AptValue** m_data
class AptValueVector {
public:
    u32 m_capacity;       // 0x00
    u32 m_count;          // 0x04
    AptValue** m_data;    // 0x08

    AptValueVector(int capacity) {
        m_count = 0;
        m_capacity = capacity;
        m_data = (AptValue**)g_pDogmaPoolMgr->Allocate(capacity * 4);
    }

    ~AptValueVector() {
        g_pDogmaPoolMgr->Deallocate(m_data, m_capacity * 4);
        // Note: if (deleteFlag & 1), also deallocate this
    }

    void ReleaseValues() {
        while (m_count > 0) {
            m_count--;
            AptValue* val = m_data[m_count];
            u32 flags = *(u32*)val;
            u32 refCount = (flags >> 14) & 0xFFF;
            if (refCount == 0) {
                // Clear the GC mark bit (bit 29)
                flags &= ~(1u << 29);
                *(u32*)val = flags;
                continue;
            }
            // Decrement ref and release if needed
            // (vtable call through offset 96/100 in vtable desc)
        }
    }
};


// =============================================================================
// AptValue - Core Variant Type
// =============================================================================
//
// Layout:
//   0x00: u32 m_flags       (vtblIndex bits 0-6, isDefined bit 27, refCount bits 14-25, gcMark bit 30, etc.)
//   0x04: u32 m_data
//   0x08: void* m_vtableDesc (pointer to vtable descriptor)
//   0x0C: u32/f32 m_value   (int or float stored here)
//   0x10-0x20: padding / additional fields
//   0x24: AptValue* m_stringData (for STRING2 types)
//
class AptValue {
public:
    u32   m_flags;         // 0x00
    u32   m_data;          // 0x04
    void* m_vtableDesc;    // 0x08
    union {
        u32 m_intValue;
        f32 m_floatValue;
    };                     // 0x0C
    u32   m_pad10;         // 0x10
    u32   m_pad14;         // 0x14
    u32   m_pad18;         // 0x18
    u32   m_pad1C;         // 0x1C
    u32   m_pad20;         // 0x20
    AptValue* m_stringData; // 0x24

    // ----- Bitfield accessors -----
    u32  getVtblIndex() const   { return m_flags & 0x7F; }
    void setVtblIndex(u32 idx)  { m_flags = (m_flags & ~0x7F) | (idx & 0x7F); }
    bool getIsDefined() const   { return (m_flags & 0x08000000) != 0; }
    void setIsDefined(bool v)   { if (v) m_flags |= 0x08000000; else m_flags &= ~0x08000000; }
    u32  getRefCount() const    { return (m_flags >> 14) & 0xFFF; }
    void setRefCount(u32 rc)    { m_flags = (m_flags & ~(0xFFF << 14)) | ((rc & 0xFFF) << 14); }
    bool getGCMark() const      { return (m_flags >> 30) & 1; }
    void setGCMark(bool v)      { if (v) m_flags |= (1u << 30); else m_flags &= ~(1u << 30); }
    u32  getGCRoot() const      { return (m_flags >> 8) & 0x3F; }
    void setGCRoot(u32 val)     { m_flags = (m_flags & ~(0x3F << 8)) | ((val & 0x3F) << 8); }
    bool isReleaseAtEnd() const { return (m_flags >> 29) & 1; }
    bool isUndefined() const    { return !getIsDefined(); }

    AptValue* resolveString() const {
        if (getVtblIndex() != APT_VFT_STRING) {
            return m_stringData;
        }
        return const_cast<AptValue*>(this);
    }

    // Constructed via vtable index
    AptValue(AptVirtualFunctionTable_Indices vftIdx);

    // CIH_ONLY construction (used for AptCIH subclasses)
    AptValue(AptVirtualFunctionTable_Indices vftIdx, int cihOnly);

    ~AptValue();

    // ----- Type Conversions -----
    // These are already decompiled in ui_system.cpp; declared here for reference
    int  toInteger() const;
    f32  toFloat() const;
    bool toBool() const;
    void toString(char* outBuf) const;
    void toString(EAStringC& outStr) const;
    void* urlEncode();

    // ----- Reference Counting -----
    void AddRef(const char* file, const char* func, int line);
    void Release(const char* file, const char* func, int line);
    void ForceDelete();

    // Child lookup
    AptValue* findChild(EAStringC* name, AptValue* scope);
    bool isMCInParentChain() const;
    bool CanCreateScriptObject() const;
};


// =============================================================================
// AptBoolean
// =============================================================================
//
// Layout: extends AptValue (16 bytes total)
//   0x00-0x07: AptValue base (m_flags, m_data)
//   0x08: void* vtableDesc (AptBoolean vtable)
//   0x0C: u32 m_boolValue (0 or 1)
//
class AptBoolean : public AptValue {
public:
    // Static pool head for fast allocation recycling
    // g_pBooleanPool (r13 - 26916)

    // ClearPool: iterates the free-list at g_pBooleanPool, calls
    // each node's destructor through vtable, then Release(3) to free.
    static void ClearPool() {
        while (g_pBooleanPool != nullptr) {
            AptValue* current = g_pBooleanPool;
            AptValue* next = reinterpret_cast<AptValue*>(current->m_intValue);
            // vtable call: destructor through offset 96/100 in vtable desc
            // Then Release with mode=3
            // Then advance to next
            g_pBooleanPool = next;
        }
    }

    ~AptBoolean() {
        // Set vtable to AptBoolean's vtable
        // Then call AptValue::~AptValue(mode=0)
        // If deleteFlag & 1, call operator delete(this, 16)
    }

    AptBoolean(bool val) : AptValue(APT_VFT_BOOLEAN) {
        m_intValue = val ? 1 : 0;
        // m_vtableDesc set to AptBoolean vtable
    }

    // Create: pool-based allocation -- tries to pop from g_pBooleanPool first,
    // falls back to DOGMA_PoolManager::Allocate(16) + placement new
    static AptValue* Create(bool val) {
        AptValue* node = g_pBooleanPool;
        if (node != nullptr) {
            AptValue* next = reinterpret_cast<AptValue*>(node->m_intValue);
            g_pBooleanPool = next;

            // Reclaim from GC: set isDefined bit
            u32 flags = node->m_flags;
            flags |= 0x20000000; // oris with 8192 = 0x20000000
            node->m_flags = flags;

            // Register with AptValueVector if capacity available
            AptValueVector* vec = (AptValueVector*)g_pAptValueVector;
            if (vec->m_count >= vec->m_capacity) {
                // Clear the isDefined flag again
                flags &= ~(1u << 29);
                node->m_flags = flags;
            } else {
                vec->m_data[vec->m_count] = node;
                vec->m_count++;
            }

            node->m_intValue = val ? 1 : 0;
            return node;
        } else {
            // Fresh allocation
            void* mem = g_pDogmaPoolMgr->Allocate(16);
            AptValue* newVal = reinterpret_cast<AptValue*>(mem);
            // Construct as AptValue(APT_VFT_BOOLEAN), then set vtableDesc, set value
            newVal->m_intValue = val ? 1 : 0;
            // m_vtableDesc = &AptBoolean_vtable
            return newVal;
        }
    }
};


// =============================================================================
// AptFloat
// =============================================================================
//
// Layout: extends AptValue (16 bytes total)
//   0x0C: f32 m_floatValue
//
class AptFloat : public AptValue {
public:
    static void ClearPool() {
        while (g_pFloatPool != nullptr) {
            AptValue* current = g_pFloatPool;
            AptValue* next = reinterpret_cast<AptValue*>(current->m_intValue);
            // Destructor via vtable offset 96/100, then Release(3)
            g_pFloatPool = next;
        }
    }

    ~AptFloat() {
        // Set vtable to AptFloat vtable
        // AptValue::~AptValue(mode=0)
        // If deleteFlag & 1: operator delete(this, 16)
    }

    AptFloat(f32 val) : AptValue(APT_VFT_FLOAT) {
        m_floatValue = val;
        // m_vtableDesc = &AptFloat_vtable
    }

    static AptValue* Create(f32 val) {
        AptValue* node = g_pFloatPool;
        if (node != nullptr) {
            AptValue* next = reinterpret_cast<AptValue*>(node->m_intValue);
            g_pFloatPool = next;

            u32 flags = node->m_flags;
            flags |= 0x20000000;
            node->m_flags = flags;

            AptValueVector* vec = (AptValueVector*)g_pAptValueVector;
            if (vec->m_count >= vec->m_capacity) {
                flags &= ~(1u << 29);
                node->m_flags = flags;
            } else {
                vec->m_data[vec->m_count] = node;
                vec->m_count++;
            }

            node->m_floatValue = val;
            return node;
        } else {
            void* mem = g_pDogmaPoolMgr->Allocate(16);
            AptValue* newVal = reinterpret_cast<AptValue*>(mem);
            // AptValue(APT_VFT_FLOAT)
            newVal->m_floatValue = val;
            // m_vtableDesc = &AptFloat_vtable
            return newVal;
        }
    }
};


// =============================================================================
// AptInteger
// =============================================================================
//
// Layout: extends AptValue (16 bytes total)
//   0x0C: u32 m_intValue
//
class AptInteger : public AptValue {
public:
    static void ClearPool() {
        while (g_pIntegerPool != nullptr) {
            AptValue* current = g_pIntegerPool;
            AptValue* next = reinterpret_cast<AptValue*>(current->m_intValue);
            // Destructor via vtable, then Release(3)
            g_pIntegerPool = next;
        }
    }

    ~AptInteger() {
        // Set vtable to AptInteger vtable
        // AptValue::~AptValue(mode=0)
        // If deleteFlag & 1: operator delete(this, 16)
    }

    AptInteger(int val) : AptValue(APT_VFT_INTEGER) {
        m_intValue = (u32)val;
        // m_vtableDesc = &AptInteger_vtable
    }

    static AptValue* Create(int val) {
        AptValue* node = g_pIntegerPool;
        if (node != nullptr) {
            AptValue* next = reinterpret_cast<AptValue*>(node->m_intValue);
            g_pIntegerPool = next;

            u32 flags = node->m_flags;
            flags |= 0x20000000;
            node->m_flags = flags;

            AptValueVector* vec = (AptValueVector*)g_pAptValueVector;
            if (vec->m_count >= vec->m_capacity) {
                flags &= ~(1u << 29);
                node->m_flags = flags;
            } else {
                vec->m_data[vec->m_count] = node;
                vec->m_count++;
            }

            node->m_intValue = (u32)val;
            return node;
        } else {
            void* mem = g_pDogmaPoolMgr->Allocate(16);
            AptValue* newVal = reinterpret_cast<AptValue*>(mem);
            // AptValue(APT_VFT_INTEGER)
            newVal->m_intValue = (u32)val;
            // m_vtableDesc = &AptInteger_vtable
            return newVal;
        }
    }
};


// =============================================================================
// AptNone
// =============================================================================
//
// Layout: extends AptValue (12 bytes, minimal)
//
class AptNone : public AptValue {
public:
    ~AptNone() {
        // Set vtable to AptNone vtable
        // AptValue::~AptValue(mode=0)
        // If deleteFlag & 1: DOGMA_PoolManager::Deallocate(this, 12)
    }
};


// =============================================================================
// AptExtern
// =============================================================================
//
// Layout: extends AptValue (12 bytes)
//   Used for external object references in the APT ActionScript VM
//
class AptExtern : public AptValue {
public:
    // objectMemberSet: converts the value to string, gets the c_str from
    // the member name, then calls the extern callback function at offset 60
    // of the extern context object.
    bool objectMemberSet(AptValue* scope, EAStringC* memberName, AptValue* value) {
        EAStringC tempStr;
        value->toString(tempStr);

        // Get the extern context (stored at some global address)
        // const char* nameStr = memberName->c_str();
        // const char* valStr = (const char*)tempStr;
        // externCtx->callback(nameStr, valStr);  // vtable offset 60

        // ~EAStringC destroys tempStr
        return true;  // always returns 1
    }

    ~AptExtern() {
        // Set vtable to AptExtern vtable
        // AptValue::~AptValue(mode=0)
        // If deleteFlag & 1: DOGMA_PoolManager::Deallocate(this, 12)
    }
};


// =============================================================================
// AptNativeHash
// =============================================================================
//
// An open-addressing hash table used by AptObject, AptPrototype, etc.
// for member lookup.
//
class AptNativeHash {
public:
    AptNativeHash(int initialCapacity);
    ~AptNativeHash();

    AptValue* Lookup(EAStringC* key) const;
    void Set(EAStringC* key, AptValue* value);
};


// =============================================================================
// AptString
// =============================================================================
//
// Layout:
//   0x00-0x0B: AptValue base
//   0x0C: EAStringCInternalData* m_strData  (refcounted string)
//   0x10: AptValue* m_nextInPool  (for pool recycling)
//
class AptString : public AptValue {
public:
    // 0x0C: m_strData (stored as m_intValue in AptValue union)
    // 0x10: m_nextInPool

    AptString() : AptValue(APT_VFT_STRING) {
        // m_vtableDesc = &AptString_vtable
        // m_intValue = address of global empty string constant
        // Increment refcount on the empty string
        // m_pad10 = 0 (next-in-pool)
    }

    AptString(char* str) : AptValue(APT_VFT_STRING) {
        // m_vtableDesc = &AptString_vtable
        // EAStringC::InitFromBuffer(str) into m_intValue (offset 0x0C)
        // m_pad10 = 0
    }

    ~AptString() {
        // m_vtableDesc = &AptString_vtable (ensure correct vtable)
        EAStringCInternalData* strData = reinterpret_cast<EAStringCInternalData*>(m_intValue);
        if (strData != nullptr) {
            strData->m_refCount--;
            if (strData->m_refCount == 0) {
                u32 totalSize = strData->m_length + 9;
                g_pDogmaPoolMgr->Deallocate(strData, totalSize);
            }
        }
        // AptValue::~AptValue(mode=0)
        // If deleteFlag & 1: DOGMA_PoolManager::Deallocate(this, 20)
    }

    // DeleteThis: moves this AptString into the g_pStringPool free list.
    // Checks if the internal EAStringC buffer is large enough to hold 33 chars;
    // if so, clears it instead of fully destroying.
    void DeleteThis() {
        AptValue* oldHead = g_pStringPool;
        m_pad10 = (u32)(uintptr_t)oldHead;
        g_pStringPool = this;

        EAStringC* internalStr = reinterpret_cast<EAStringC*>(&m_intValue);
        if (internalStr->IsEnoughSize(33)) {
            internalStr->Clear();
        }
    }

    // ForceDelete: same logic as DeleteThis
    void ForceDelete() {
        AptValue* oldHead = g_pStringPool;
        m_pad10 = (u32)(uintptr_t)oldHead;
        g_pStringPool = this;

        EAStringC* internalStr = reinterpret_cast<EAStringC*>(&m_intValue);
        if (internalStr->IsEnoughSize(33)) {
            internalStr->Clear();
        }
    }

    static void CleanNativeFunctions();

    // Factory methods
    static AptValue* Create(char* str) {
        AptValue* node = g_pStringPool;
        if (node != nullptr) {
            AptValue* next = reinterpret_cast<AptValue*>(node->m_pad10);
            g_pStringPool = next;

            u32 flags = node->m_flags;
            flags |= 0x20000000;
            node->m_flags = flags;

            AptValueVector* vec = (AptValueVector*)g_pAptValueVector;
            if (vec->m_count >= vec->m_capacity) {
                flags &= ~(1u << 29);
                node->m_flags = flags;
            } else {
                vec->m_data[vec->m_count] = node;
                vec->m_count++;
            }

            EAStringC* internalStr = reinterpret_cast<EAStringC*>(&node->m_intValue);
            if (!internalStr->IsEmpty()) {
                internalStr->ReserveSize(0);
            }
            return node;
        } else {
            void* mem = g_pDogmaPoolMgr->Allocate(20);
            AptValue* newVal = new (mem) AptString(str);
            return newVal;
        }
    }

    static AptValue* Create() {
        AptValue* node = g_pStringPool;
        if (node != nullptr) {
            AptValue* next = reinterpret_cast<AptValue*>(node->m_pad10);
            g_pStringPool = next;

            u32 flags = node->m_flags;
            flags |= 0x20000000;
            node->m_flags = flags;

            AptValueVector* vec = (AptValueVector*)g_pAptValueVector;
            if (vec->m_count >= vec->m_capacity) {
                flags &= ~(1u << 29);
                node->m_flags = flags;
            } else {
                vec->m_data[vec->m_count] = node;
                vec->m_count++;
            }

            EAStringC* internalStr = reinterpret_cast<EAStringC*>(&node->m_intValue);
            if (!internalStr->IsEmpty()) {
                internalStr->ReserveSize(0);
            }
            return node;
        } else {
            void* mem = g_pDogmaPoolMgr->Allocate(20);
            AptValue* newVal = new (mem) AptString();
            return newVal;
        }
    }

    void Destroy() {
        // Releases the string data and frees this
    }

    void cpy(char* str) {
        // Copies str into this AptString's internal EAStringC
    }

    void printf(char* fmt, ...) {
        // Formatted string builder -- uses va_list
    }

    // Member lookup for ActionScript String object
    AptValue* objectMemberLookup(AptValue* scope, EAStringC* memberName) const;

    // sMethod_* are the ActionScript String prototype methods:
    static void sMethod_charAt(AptValue* args, int argc);
    static void sMethod_charCodeAt(AptValue* args, int argc);
    static void sMethod_concat(AptValue* args, int argc);
    static void sMethod_fromCharCode(AptValue* args, int argc);
    static void sMethod_indexOf(AptValue* args, int argc);
    static void sMethod_slice(AptValue* args, int argc);
    static void sMethod_split(AptValue* args, int argc);
    static void sMethod_substr(AptValue* args, int argc);
    static void sMethod_substring(AptValue* args, int argc);
    static void sMethod_toLowerCase(AptValue* args, int argc);
    static void sMethod_toUpperCase(AptValue* args, int argc);
};


// =============================================================================
// AptValueWithHash
// =============================================================================
//
// Layout:
//   0x00-0x0B: AptValue base
//   0x0C: AptNativeHash m_hash  (embedded, ends at ~0x1F)
//
// Size: 32 bytes
//
class AptValueWithHash : public AptValue {
public:
    // Embedded AptNativeHash at offset 0x0C (accessed as this+12)

    AptValueWithHash(AptVirtualFunctionTable_Indices vftIdx, int hashCapacity)
        : AptValue(vftIdx)
    {
        // m_vtableDesc = generic AptValueWithHash vtable
        // Construct AptNativeHash at this+12 with hashCapacity
    }

    ~AptValueWithHash() {
        // Destroy AptNativeHash at this+12
        // AptValue::~AptValue(mode=0)
        // If deleteFlag & 1: AptValueGC_PoolManager::DeallocateAptValueGC(this, 32)
    }

    void DestroyGCPointers();
    void RegisterReferences() const;
};


// =============================================================================
// AptObject
// =============================================================================
//
// Layout (extends AptValue, 36 bytes):
//   0x00-0x0B: AptValue base
//   0x0C-0x1F: AptNativeHash m_hash
//   0x14: AptValue* m_prototype  (at hash offset +8 = this+20)
//   0x20: u8 m_implementedObjectCount
//
// The AptNativeHash stores named properties.
// m_prototype points to the prototype chain for method lookup.
//
class AptObject : public AptValue {
public:
    // AptNativeHash at this+12
    // m_implementedObjectCount at this+32

    AptObject(AptVirtualFunctionTable_Indices vftIdx, int hashCapacity)
        : AptValue(vftIdx)
    {
        // m_vtableDesc = AptObject initial vtable
        // Construct AptNativeHash(hashCapacity) at this+12
        *(u8*)((char*)this + 32) = 0;  // m_implementedObjectCount = 0
        // m_vtableDesc = &AptObject_vtable
        // Clear bits 22-31 in the byte at this+32
        u32 miscByte = *(u32*)((char*)this + 32);
        miscByte &= 0x003FFFFF;  // rlwinm 0,0,0,10,7
        *(u32*)((char*)this + 32) = miscByte;
    }

    ~AptObject() {
        // m_vtableDesc = &AptObject_vtable
        // ~AptNativeHash() at this+12
        // ~AptValue(mode=0)
        // If deleteFlag & 1: AptValueGC_PoolManager::DeallocateAptValueGC(this, 36)
    }

    // Set the __implements array and count
    void SetImplementedObjects(AptArray* arr, int count) {
        EAStringC key;
        key.InitFromBuffer("__implements");
        // m_hash.Set(&key, arr)
        *(u8*)((char*)this + 32) = (u8)count;
        // Release key's EAStringC ref
    }

    // Get the __implements array (looks up "__implements" in hash)
    AptValue* GetImplementedObjects(int* outCount) const {
        *outCount = *(u8*)((char*)this + 32);
        if (*outCount == 0) {
            return nullptr;
        }
        EAStringC key;
        key.InitFromBuffer("__implements");
        // AptValue* result = m_hash.Lookup(&key)
        // Release key's EAStringC ref
        // return result;
        return nullptr; // placeholder
    }

    // Check if a particular AptValue is in the prototype chain
    // or in the __implements array
    bool DoesImplementObject(AptValue* target) const {
        // Walk prototype chain: this->m_prototype -> m_prototype -> ...
        AptValue* proto = *(AptValue**)((char*)this + 20);
        while (proto != nullptr) {
            if (proto == target) return true;
            // Check if proto is an object type via vtable
            // Get proto's prototype
            u32 protoVt = proto->getVtblIndex();
            if (protoVt == 0) break; // not an object
            // proto = proto->m_prototype
            proto = *(AptValue**)((char*)proto + 8); // simplified
            // In assembly this walks vtable+32/36 to get __proto__
        }

        // Check __implements array
        u8 implCount = *(u8*)((char*)this + 32);
        if (implCount == 0) return false;

        EAStringC key;
        key.InitFromBuffer("__implements");
        // AptValue* implArray = m_hash.Lookup(&key)
        // for (u32 i = 0; i < implCount; i++) {
        //     AptValue* impl = implArray->m_data[i] (at offset 36)
        //     if (impl == target) return true;
        // }
        return false;
    }

    // Set the __proto__ reference for this object
    void SetPrototype(AptValue* proto) {
        AptValue** protoSlot = (AptValue**)((char*)this + 12 + 12); // hash+12 = this+24
        AptValue* oldProto = *protoSlot;

        if (proto != nullptr) {
            // AddRef on proto
            proto->AddRef("AptObject.cpp", "SetPrototype", 102);
        }

        if (oldProto != nullptr) {
            // Release on oldProto
            oldProto->Release("AptObject.cpp", "SetPrototype", 103);
        }

        *protoSlot = proto;
    }
};


// =============================================================================
// AptPrototype
// =============================================================================
//
// Layout (extends AptValue, 36 bytes):
//   0x00-0x0B: AptValue base
//   0x0C-0x1F: AptNativeHash m_hash
//   0x20: AptValue* m_superConstructor
//
class AptPrototype : public AptValue {
public:
    // m_superConstructor at offset 32

    AptPrototype() : AptValue(APT_VFT_PROTOTYPE) {
        // m_vtableDesc initially set to AptValueWithHash vtable
        // Construct AptNativeHash(8) at this+12
        // m_vtableDesc = &AptPrototype_vtable
        // Clear bit 5 (CIH flag) in m_flags
        u32 flags = m_flags;
        flags &= ~(1u << 5);
        m_flags = flags;
        *(AptValue**)((char*)this + 32) = nullptr;
    }

    ~AptPrototype() {
        // m_vtableDesc = &AptPrototype_vtable
        // ~AptNativeHash at this+12
        // ~AptValue(mode=0)
        // If deleteFlag & 1: AptValueGC_PoolManager::DeallocateAptValueGC(this, 36)
    }

    void DestroyGCPointers() {
        AptValue* superCtor = *(AptValue**)((char*)this + 32);
        if (superCtor != nullptr) {
            // Release reference
            superCtor->Release("AptPrototype.cpp", "DestroyGCPointers", 51);
        }
        *(AptValue**)((char*)this + 32) = nullptr;
        // Call base: AptValueWithHash::DestroyGCPointers()
    }

    void RegisterReferences() const {
        // AptValueWithHash::RegisterReferences()
        AptValue* superCtor = *(AptValue**)((char*)this + 32);
        if (superCtor != nullptr) {
            // Register reference via g_pGCRegistrationCb
        }
    }

    // Lookup "__constructor__" member
    AptValue* objectMemberLookup(AptValue* scope, EAStringC* memberName) const {
        if (memberName->Equal("__constructor__")) {
            return GetSuperConstructor();
        }
        return nullptr;
    }

    bool objectMemberSet(AptValue* scope, EAStringC* memberName, AptValue* value) {
        if (memberName->Equal("__constructor__")) {
            SetSuperConstructor(value);
            return true;
        }
        return false;
    }

    AptValue* GetSuperConstructor() const {
        return *(AptValue**)((char*)this + 32);
    }

    void SetSuperConstructor(AptValue* newCtor) {
        AptValue* oldCtor = *(AptValue**)((char*)this + 32);
        *(AptValue**)((char*)this + 32) = newCtor;

        if (newCtor != nullptr) {
            newCtor->AddRef("AptPrototype.cpp", "SetSuperConstructor", 218);
        }
        if (oldCtor != nullptr) {
            oldCtor->Release("AptPrototype.cpp", "SetSuperConstructor", 219);
        }
    }
};


// =============================================================================
// AptArray
// =============================================================================
//
// Layout (extends AptValue, 48 bytes):
//   0x00-0x0B: AptValue base
//   0x0C-0x1F: AptNativeHash (embedded)
//   0x20: u8 (implementedObjects count?)
//   0x24: AptValue** m_elements  (at offset 36)
//   0x28: u32 m_allocated        (at offset 40)
//   0x2C: u32 m_length           (at offset 44)
//
class AptArray : public AptValue {
public:
    // m_elements at offset 36
    // m_allocated at offset 40
    // m_length at offset 44

    AptArray(int length, AptValue** elements) : AptValue(APT_VFT_ARRAY) {
        // Construct AptNativeHash(length) at this+12
        // m_vtableDesc = &AptArray_vtable
        *(u8*)((char*)this + 32) = 0;
        *(AptValue***)((char*)this + 36) = nullptr;
        *(u32*)((char*)this + 40) = 0;
        *(u32*)((char*)this + 44) = length;
        u32 miscByte = *(u32*)((char*)this + 32);
        miscByte &= 0x003FFFFF;
        *(u32*)((char*)this + 32) = miscByte;

        // _reserve(length)
        _reserve(length);

        // Copy elements
        AptValue** elems = *(AptValue***)((char*)this + 36);
        for (int i = 0; i < length; i++) {
            AptValue* elem = elements[i];
            // AddRef on elem
            elem->AddRef("AptArray.cpp", "AptArray", 284);
            // Release old element if any
            AptValue* old = elems[i];
            if (old != nullptr) {
                old->Release("AptArray.cpp", "AptArray", 285);
            }
            elems[i] = elem;
        }
    }

    AptArray() : AptValue(APT_VFT_ARRAY) {
        // Construct AptNativeHash(8) at this+12
        // m_vtableDesc = &AptArray_vtable
        *(u8*)((char*)this + 32) = 0;
        *(u32*)((char*)this + 44) = 0;
        *(u32*)((char*)this + 40) = 0;
        u32 miscByte = *(u32*)((char*)this + 32);
        miscByte &= 0x003FFFFF;
        *(u32*)((char*)this + 32) = miscByte;
        *(AptValue***)((char*)this + 36) = nullptr;
    }

    ~AptArray() {
        // m_vtableDesc = &AptObject_vtable (intermediate)
        // ~AptNativeHash at this+12
        // ~AptValue(mode=0)
        // If deleteFlag & 1: AptValueGC_PoolManager::DeallocateAptValueGC(this, 48)
    }

    void _reserve(int newCapacity);
    void set(int index, AptValue* value);
    void DestroyGCPointers();
    void RegisterReferences() const;

    static void CleanNativeFunctions();

    void toString(char* separator, char* outBuf);
    void toString(EAStringC& outStr, char* separator);
    AptValue* objectMemberLookup(AptValue* scope, EAStringC* memberName) const;
    bool objectMemberSet(AptValue* scope, EAStringC* memberName, AptValue* value);

    // ActionScript Array prototype methods
    static void sMethod_concat(AptValue* args, int argc);
    static void sMethod_join(AptValue* args, int argc);
    static void sMethod_pop(AptValue* args, int argc);
    static void sMethod_push(AptValue* args, int argc);
    static void sMethod_shift(AptValue* args, int argc);
    static void sMethod_unshift(AptValue* args, int argc);
    static void sMethod_sort(AptValue* args, int argc);
    static void sMethod_sortOn(AptValue* args, int argc);
    static void sMethod_reverse(AptValue* args, int argc);
    static void sMethod_splice(AptValue* args, int argc);
    static void sMethod_slice(AptValue* args, int argc);

    static int defaultSortCompareFunc(void* a, void* b);
    static int scriptFunctionSortFunc(void* a, void* b);
    static int defaultSortOnCompareFunc(void* a, void* b);

    void SetAt(int index, AptValue* value);
};


// =============================================================================
// AptValueFactory
// =============================================================================
//
// Factory class for creating primitive AptValue types.
// Uses the pool-based allocation strategy (tries pool first, then fresh alloc).
//
class AptValueFactory {
public:
    // CreateInteger: identical to AptInteger::Create
    static AptValue* CreateInteger(int val) {
        return AptInteger::Create(val);
    }

    // CreateFloat: identical to AptFloat::Create
    static AptValue* CreateFloat(f32 val) {
        return AptFloat::Create(val);
    }

    // CreateBoolean: identical to AptBoolean::Create
    static AptValue* CreateBoolean(bool val) {
        return AptBoolean::Create(val);
    }

    // CreateArray: allocates a new AptArray with the given elements
    static AptValue* CreateArray(int count, AptValue** elements) {
        void* mem = g_pAptValueGCPoolMgr->AllocateAptValueGC(48);
        // Placement new AptArray(count, elements)
        return reinterpret_cast<AptValue*>(mem);
    }

    // CreateStringFormatted: creates a formatted string (uses va_list)
    static AptValue* CreateStringFormatted(char* fmt, ...);
};


// =============================================================================
// AptGC -- Garbage Collector
// =============================================================================
//
// The APT GC uses a mark-and-sweep strategy:
//   1. Release all tracked values in the AptValueVector
//   2. Get the first AptValue from the pool manager
//   3. Mark reachable values via RegisterReferences callbacks
//   4. Sweep: destroy unmarked values, clear marks on remaining
//   5. Clear primitive pools (Boolean, Integer, Float, String)
//
class AptGC {
public:
    // Callback invoked during reference registration.
    // Marks a value as referenced (sets bit 30 in flags) and
    // calls its RegisterReferences vtable method.
    static void sReferenceRegistrationCb(AptValue* owner, AptValue* ref, char* debugName) {
        u32 flags = ref->m_flags;
        // Check if already marked (bit 30)
        if (flags & 0x40000000) {
            return;
        }
        // Set mark bit
        flags |= 0x40000000;
        ref->m_flags = flags;

        // Call RegisterReferences via vtable offset 112/116
        // (vtable desc at ref->m_vtableDesc, entries at offset 112)
    }

    // CleanUnreachable: mark-and-sweep for values not reachable from roots
    static void CleanUnreachable() {
        // 1. Release all values in the global AptValueVector
        ((AptValueVector*)g_pAptValueVector)->ReleaseValues();

        // 2. Get first value from pool, set up GC registration callback
        AptValue* val = g_pAptValueGCPoolMgr->GetFirstAptValue();
        void* savedCb = g_pGCRegistrationCb;
        // g_pGCRegistrationCb = &sReferenceRegistrationCb;

        // 3. Mark phase: iterate all values, mark roots
        while (val != nullptr) {
            u32 flags = val->m_flags;
            u32 gcRoot = (flags >> 8) & 0x3F;
            if (gcRoot != 0) {
                bool alreadyMarked = (flags & 0x40000000) != 0;
                bool gcBit = (flags >> 30) & 1;
                if (!alreadyMarked && !gcBit) {
                    // Set mark bit (bit 30)
                    flags |= (1u << 30);
                    val->m_flags = flags;
                    // Call RegisterReferences via vtable offset 112/116
                }
            }
            val = g_pAptValueGCPoolMgr->GetNextAptValue(val);
        }

        // 4. Register global references
        AptRegisterGlobalReferences();

        // g_pGCRegistrationCb = savedCb;

        // 5. Get first value again, sweep unmarked
        val = g_pAptValueGCPoolMgr->GetFirstAptValue();
        u32 savedDeleteCycle = g_bInDeleteCycle;
        g_bInDeleteCycle = 1;

        while (val != nullptr) {
            u32 flags = val->m_flags;
            if (!(flags & 0x40000000)) {
                // Not marked -- call PreDestroy (vtable offset 88/92)
                // Then call destructor (vtable offset 96/100)
            }
            val = g_pAptValueGCPoolMgr->GetNextAptValue(val);
        }

        // 6. Reset marks on surviving values
        ((AptValueVector*)g_pAptValueVector)->ReleaseValues();
        g_bInDeleteCycle = savedDeleteCycle;

        val = g_pAptValueGCPoolMgr->GetFirstAptValue();
        while (val != nullptr) {
            u32 flags = val->m_flags;
            if (!(flags & 0x40000000)) {
                // Call cleanup (vtable offset 80/84)
            } else {
                // Clear mark bit
                flags &= ~(1u << 30);
                val->m_flags = flags;
            }
            val = g_pAptValueGCPoolMgr->GetNextAptValue(val);
        }

        // 7. Clear primitive pools
        ((AptValueVector*)g_pAptValueVector)->ReleaseValues();
        AptBoolean::ClearPool();
        AptInteger::ClearPool();
        AptFloat::ClearPool();
        StringPool_ClearTemporaryPool();
    }

    // CleanAll: destroy ALL GC-managed values (used at shutdown)
    static void CleanAll() {
        ((AptValueVector*)g_pAptValueVector)->ReleaseValues();

        AptValue* val = g_pAptValueGCPoolMgr->GetFirstAptValue();
        u32 savedDeleteCycle = g_bInDeleteCycle;
        g_bInDeleteCycle = 1;

        while (val != nullptr) {
            // Call PreDestroy (vtable offset 88/92)
            // Call destructor (vtable offset 96/100)
            val = g_pAptValueGCPoolMgr->GetNextAptValue(val);
        }

        ((AptValueVector*)g_pAptValueVector)->ReleaseValues();
        g_bInDeleteCycle = savedDeleteCycle;

        val = g_pAptValueGCPoolMgr->GetFirstAptValue();
        while (val != nullptr) {
            // Call cleanup (vtable offset 80/84)
            val = g_pAptValueGCPoolMgr->GetNextAptValue(val);
        }

        ((AptValueVector*)g_pAptValueVector)->ReleaseValues();
        AptBoolean::ClearPool();
        AptInteger::ClearPool();
        AptFloat::ClearPool();
        StringPool_ClearTemporaryPool();
    }
};


// =============================================================================
// AptCharacter
// =============================================================================
//
// Layout:
//   0x00: u32 m_type  (1 = shape, 10 = sprite/movieclip, etc.)
//   0x08: AptRect m_boundingRect (16 bytes, at offset 8)
//   0x18: AptValue* m_data (at offset 24)
//
class AptCharacter {
public:
    u32 m_type;               // 0x00
    u32 m_pad04;              // 0x04
    f32 m_rectLeft;           // 0x08
    f32 m_rectTop;            // 0x0C
    f32 m_rectRight;          // 0x10
    f32 m_rectBottom;         // 0x14
    void* m_data;             // 0x18

    // render: optionally pushes a vertex matrix, then dispatches
    // to the appropriate rendering function based on m_type.
    void render(AptRenderingContext* ctx, AptMaskRenderOperation maskOp, AptMatrix* matrix) {
        bool hasMatrix = (matrix != nullptr);

        if (hasMatrix) {
            // ctx->pushVertexMatrix()
            // ctx->appendVertexMatrix(matrix)
        }

        if (m_type == 1) {
            // Shape rendering: call function pointer from global table
            // fnPtr = *(void**)(globalAddr - 16160)
            // fnPtr(m_data, maskOp)
        }

        if (hasMatrix) {
            // ctx->popVertexMatrix()
        }
    }

    // _getBoundingRect: expands the bounding rect through the rendering context
    void _getBoundingRect(AptRenderingContext* ctx, AptRect* outRect, AptMatrix* matrix) {
        if (matrix != nullptr) {
            // ctx->pushVertexMatrix()
            // ctx->appendVertexMatrix(matrix)
        }

        switch (m_type) {
            case 1:   // Shape
            case 10:  // Sprite/MovieClip
                // ctx->expandBoundingRect(outRect, &this->m_rectLeft)
                break;
            default:
                break;
        }

        if (matrix != nullptr) {
            // ctx->popVertexMatrix()
        }
    }
};


// =============================================================================
// AptDisplayListState
// =============================================================================
//
// Layout:
//   0x00: AptCIH* m_head  (pointer to first CIH in display list)
//
// The display list is a doubly-linked list of AptCIH nodes.
// Each AptCIH has:
//   0x50 (80): AptCIH* m_prev
//   0x54 (84): AptCIH* m_next
//   0x58 (88): u32 m_depthAndFlags
//   0x5C (92): u32 m_flags2
//
class AptDisplayListState {
public:
    AptCIH** m_pHead;  // 0x00 -- pointer to the CIH head pointer

    // findInst: searches for an instance by depth or name in the display list
    void findInst(int depth, EAStringC* name, AptCIH** outPrev, AptCIH** outFound) {
        AptCIH* head = *m_pHead;
        AptCIH* current = *(AptCIH**)((char*)head + 84); // head->m_next
        AptCIH* prev = head;

        // First: search by name if name is provided
        if (name != nullptr && current != nullptr) {
            while (current != nullptr) {
                u32 flags = *(u32*)current;
                if (flags & 0x08000000) {
                    // Skip undefined entries
                    prev = current;
                    current = *(AptCIH**)((char*)current + 84);
                    continue;
                }

                // Compare names via EAStringC
                EAStringCInternalData* nameData = (EAStringCInternalData*)(*(u32*)((char*)name));
                EAStringCInternalData* instName = (EAStringCInternalData*)(*(u32*)((char*)current + 12));

                if (nameData->m_length == instName->m_length) {
                    if (nameData == instName ||
                        memcmp(nameData->data(), instName->data(), nameData->m_length) == 0) {
                        *outFound = current;
                        *outPrev = prev;
                        return;
                    }
                }

                prev = current;
                current = *(AptCIH**)((char*)current + 84);
            }
        }

        // Second: search by depth
        head = *m_pHead;
        current = *(AptCIH**)((char*)head + 84);
        prev = head;

        while (current != nullptr) {
            s32 currentDepth = (s32)(*(u32*)((char*)current + 88)) >> 15;
            if (currentDepth >= depth) {
                if (currentDepth == depth) {
                    *outFound = current;
                } else {
                    *outFound = nullptr;
                }
                *outPrev = prev;
                return;
            }
            prev = current;
            current = *(AptCIH**)((char*)current + 84);
        }

        *outFound = nullptr;
        *outPrev = prev;
    }

    // RegisterReferences: walks the display list and registers each CIH with the GC
    void RegisterReferences(AptValue* owner) const {
        AptCIH* head = *m_pHead;
        if (head == nullptr) return;

        AptCIH* current = head;
        while (current != nullptr) {
            // Call g_pGCRegistrationCb(owner, current, "AptDisplayListState")
            void (*cb)(AptValue*, AptValue*, const char*) =
                (void(*)(AptValue*, AptValue*, const char*))g_pGCRegistrationCb;
            if (cb != nullptr) {
                cb(owner, (AptValue*)current, "AptDisplayListState");
            }
            current = *(AptCIH**)((char*)current + 84);
        }
    }

    // insert(AptCIH*, AptCIH*): inserts newNode after prevNode in the linked list
    void insert(AptCIH* prevNode, AptCIH* newNode) {
        // Check if newNode is a CIH type 13 or 18 that is undefined
        // (used for deciding whether to skip insertion validation)

        // Link: newNode->m_prev = prevNode
        *(AptCIH**)((char*)newNode + 80) = prevNode;
        // newNode->m_next = prevNode->m_next
        AptCIH* oldNext = *(AptCIH**)((char*)prevNode + 84);
        *(AptCIH**)((char*)newNode + 84) = oldNext;

        // AddRef on newNode via vtable offset 8/12
        // (validation call with file/line info)

        // Fix backlink: if oldNext exists, oldNext->m_prev = newNode
        if (oldNext != nullptr) {
            *(AptCIH**)((char*)oldNext + 80) = newNode;
        }

        // prevNode->m_next = newNode
        *(AptCIH**)((char*)prevNode + 84) = newNode;
    }

    // insert(int depth, AptCIH* node): finds position by depth and inserts
    void insert(int depth, AptCIH* node) {
        AptCIH* prevNode = nullptr;
        AptCIH* foundNode = nullptr;
        findInst(depth, nullptr, &prevNode, &foundNode);
        insert(prevNode, node);

        // Set depth bits in node's m_depthAndFlags
        u32 depthFlags = *(u32*)((char*)node + 88);
        depthFlags = (depthFlags & 0x7FFF) | ((u32)depth << 15);
        *(u32*)((char*)node + 88) = depthFlags;
    }

    // hasRenderData: returns true if any CIH in the list has render data
    bool hasRenderData() {
        AptCIH* head = *m_pHead;
        AptCIH* current = head;
        while (current != nullptr) {
            // Call current->hasRenderData() -- returns bool
            // if (current->hasRenderData()) return true;
            current = *(AptCIH**)((char*)current + 84);
        }
        return false;
    }

    // GetMovieclipInfo: collects movieclip information from all CIHs in the list
    void GetMovieclipInfo(AptMovieclipInformation* outInfo) {
        AptCIH* head = *m_pHead;
        AptCIH* current = head;
        while (current != nullptr) {
            // current->GetMovieclipInfo(outInfo)
            current = *(AptCIH**)((char*)current + 84);
        }
    }

    // Constructor: allocates a sentinel CIH node for the list head
    AptDisplayListState() {
        // Allocate 100-byte AptValueGC for the head sentinel
        AptValue* head = g_pAptValueGCPoolMgr->AllocateAptValueGC(100);
        // Initialize as AptValue(APT_VFT_DISPLAYLISTSTATE, CIH_ONLY)
        // Set up matrix identity at various offsets (16-68)
        // Set gcRoot = 1
        // Initialize linked list: head->m_prev = NULL, head->m_next = NULL
        // Set depth to -1 (0xFFFF in the depth field)
        *m_pHead = (AptCIH*)head;
    }

    ~AptDisplayListState() {
        // Clear the character pointer at head->offset(76)
        AptCIH* head = *m_pHead;
        *(u32*)((char*)head + 76) = 0;

        // Call head's PreDestroy (vtable offset 24/28)
        // If deleteFlag & 1: DOGMA_PoolManager::Deallocate(this, 4)
    }
};


// =============================================================================
// AptError
// =============================================================================
//
// Layout (extends AptValue, 44 bytes):
//   0x00-0x0B: AptValue base
//   0x0C-0x1F: AptNativeHash (embedded, 8 entries)
//   0x20: u8 (misc flags)
//   0x24: EAStringC m_name    (4 bytes, at offset 36)
//   0x28: EAStringC m_message (4 bytes, at offset 40)
//
class AptError : public AptValue {
public:
    // m_name at offset 36
    // m_message at offset 40

    AptError() : AptValue(APT_VFT_ERROR) {
        // Construct AptNativeHash(8) at this+12
        *(u8*)((char*)this + 32) = 0;
        // m_vtableDesc = &AptError_vtable
        u32 misc = *(u32*)((char*)this + 32);
        misc &= 0x003FFFFF;
        *(u32*)((char*)this + 32) = misc;

        // Initialize m_name and m_message from empty string
        // EAStringC::EAStringC("") at this+36
        // EAStringC::EAStringC("") at this+40
    }

    AptError(EAStringC msg) : AptValue(APT_VFT_ERROR) {
        // Construct AptNativeHash(8) at this+12
        *(u8*)((char*)this + 32) = 0;
        // m_vtableDesc = &AptError_vtable
        u32 misc = *(u32*)((char*)this + 32);
        misc &= 0x003FFFFF;
        *(u32*)((char*)this + 32) = misc;

        // EAStringC copy ctor at this+36 from msg
        // EAStringC("") at this+40
        // Destroy msg
    }

    ~AptError() {
        // m_vtableDesc = &AptError_vtable
        // Release m_message ref (at this+40)
        EAStringCInternalData* msgData = *(EAStringCInternalData**)((char*)this + 40);
        if (msgData != nullptr) {
            msgData->m_refCount--;
            if (msgData->m_refCount == 0) {
                g_pDogmaPoolMgr->Deallocate(msgData, msgData->m_length + 9);
            }
        }

        // Release m_name ref (at this+36)
        EAStringCInternalData* nameData = *(EAStringCInternalData**)((char*)this + 36);
        if (nameData != nullptr) {
            nameData->m_refCount--;
            if (nameData->m_refCount == 0) {
                g_pDogmaPoolMgr->Deallocate(nameData, nameData->m_length + 9);
            }
        }

        // ~AptNativeHash at this+12
        // ~AptValue(mode=0)
        // If deleteFlag & 1: AptValueGC_PoolManager::DeallocateAptValueGC(this, 44)
    }

    // objectMemberLookup: handles "name", "message", and "constructor" lookups
    AptValue* objectMemberLookup(AptValue* scope, EAStringC* memberName) const {
        const char* str = memberName->c_str();

        // Check "name"
        if (strcmp(str, "name") == 0) {
            AptValue* result = AptString::Create();
            // Copy m_name (at offset 36) into result's string
            EAStringC temp((char*)(*(u32*)((char*)this + 36) + 8));
            EAStringC* resultStr = (EAStringC*)(&result->m_intValue);
            resultStr->operator=(temp);
            return result;
        }

        // Check "message"
        if (strcmp(str, "message") == 0) {
            AptValue* result = AptString::Create();
            // Copy m_message (at offset 40) into result's string
            EAStringC temp((char*)(*(u32*)((char*)this + 40) + 8));
            EAStringC* resultStr = (EAStringC*)(&result->m_intValue);
            resultStr->operator=(temp);
            return result;
        }

        // Check "constructor" -- returns the NativeFunction for Error
        if (strcmp(str, "constructor") == 0) {
            if (g_pErrorNativeFuncs == nullptr) {
                // Allocate and initialize the native function table
                AptValue* nf = g_pAptValueGCPoolMgr->AllocateAptValueGC(40);
                // AptValue(APT_VFT_NATIVEFUNCTION)
                // AptNativeHash(8) at nf+12
                // Setup native functions
                g_pErrorNativeFuncs = nf;
            }
            return g_pErrorNativeFuncs;
        }

        return nullptr;
    }

    // objectMemberSet: handles setting "name" and "message" properties
    bool objectMemberSet(AptValue* scope, EAStringC* memberName, AptValue* value) {
        const char* str = memberName->c_str();

        if (strcmp(str, "name") == 0) {
            EAStringC temp;
            value->toString(temp);
            EAStringC* nameStr = (EAStringC*)((char*)this + 36);
            nameStr->Duplicate(temp);
            // ~temp
            return true;
        }

        if (strcmp(str, "message") == 0) {
            EAStringC temp;
            value->toString(temp);
            EAStringC* msgStr = (EAStringC*)((char*)this + 40);
            msgStr->Duplicate(temp);
            // ~temp
            return true;
        }

        return false;
    }

    // sMethod_toString: creates a string representation of the error
    static AptValue* sMethod_toString(AptValue* scope, int argc) {
        AptValue* result = AptString::Create();
        // urlEncode the scope, then copy into result
        return result;
    }

    // CleanNativeFunctions: releases the static native function table
    static void CleanNativeFunctions() {
        if (g_pErrorNativeFuncs != nullptr) {
            // Release via vtable offset 16/20
            g_pErrorNativeFuncs = nullptr;
        }
    }
};


// =============================================================================
// AptXmlNode
// =============================================================================
//
// Layout (extends AptValue, 44 bytes):
//   0x00-0x0B: AptValue base
//   0x0C-0x1F: AptNativeHash (embedded, 8 entries)
//   0x20: u8 misc flags
//   0x24: IAptXmlNode* m_xmlNode  (at offset 36)
//   0x28: AptValue* m_something   (at offset 40)
//
class AptXmlNode : public AptValue {
public:
    AptXmlNode(AptVirtualFunctionTable_Indices vftIdx, IAptXmlNode* xmlNode)
        : AptValue(vftIdx)
    {
        // m_vtableDesc = intermediate vtable
        // Construct AptNativeHash(8) at this+12
        *(u8*)((char*)this + 32) = 0;
        // m_vtableDesc = &AptXmlNode_vtable
        *(IAptXmlNode**)((char*)this + 36) = xmlNode;
        *(u32*)((char*)this + 40) = 0;
        u32 misc = *(u32*)((char*)this + 32);
        misc &= 0x003FFFFF;
        *(u32*)((char*)this + 32) = misc;
    }

    ~AptXmlNode() {
        // Clear fields
        *(u32*)((char*)this + 40) = 0;
        *(u32*)((char*)this + 36) = 0;
        // m_vtableDesc = &AptObject_vtable (for ~AptNativeHash)
        // ~AptNativeHash at this+12
        // ~AptValue(mode=0)
        // If deleteFlag & 1: AptValueGC_PoolManager::DeallocateAptValueGC(this, 44)
    }

    static void CleanNativeFunctions();

    void objectMemberSet(AptValue* scope, EAStringC* memberName, AptValue* value);
    AptValue* objectMemberLookup(AptValue* scope, EAStringC* memberName) const;

    static void sMethod_hasChildNodes(AptValue* args, int argc);
    static void sMethod_toString(AptValue* args, int argc);
};


// =============================================================================
// AptXml
// =============================================================================
//
// Layout: extends AptXmlNode (44 bytes)
//
class AptXml : public AptXmlNode {
public:
    AptXml(IAptXmlNode* xmlNode) : AptXmlNode(APT_VFT_XML, xmlNode) {
        // m_vtableDesc = &AptXml_vtable
    }

    AptXml(AptValue* stringValue) : AptXmlNode(APT_VFT_XML, nullptr) {
        // m_vtableDesc = &AptXml_vtable
        // If stringValue is a STRING or STRING2 type and is defined:
        //   Parse the string as XML using the global XML parser
        u32 vt = stringValue->getVtblIndex();
        bool isString = false;
        if ((vt == APT_VFT_STRING || vt == APT_VFT_STRING2) &&
            stringValue->getIsDefined()) {
            isString = true;
        }

        if (isString) {
            // Parse XML from the string data
            // Set m_xmlNode (at offset 36) to the parsed result
        }
    }

    ~AptXml() {
        // m_vtableDesc = &AptXml_vtable
        // ~AptXmlNode(mode=0)
        // If deleteFlag & 1: AptValueGC_PoolManager::DeallocateAptValueGC(this, 44)
    }

    static void CleanNativeFunctions() {
        // Release up to 4 static native function pointers
        if (g_pXmlNFBytesTotal != nullptr) {
            // Release via vtable
            g_pXmlNFBytesTotal = nullptr;
        }
        if (g_pXmlNFBytesLoaded != nullptr) {
            g_pXmlNFBytesLoaded = nullptr;
        }
        if (g_pXmlNFLoad != nullptr) {
            g_pXmlNFLoad = nullptr;
        }
        if (g_pXmlNFParseXml != nullptr) {
            g_pXmlNFParseXml = nullptr;
        }
    }

    void PreDestroy();
    AptValue* objectMemberLookup(AptValue* scope, EAStringC* memberName) const;

    static void sMethod_getBytesTotal(AptValue* args, int argc);
    static void sMethod_getBytesLoaded(AptValue* args, int argc);
    static void sMethod_load(AptValue* args, int argc);
    static void sMethod_parseXml(AptValue* args, int argc);
};


// =============================================================================
// AptXmlAttributes
// =============================================================================
//
// Layout (extends AptValue, 40 bytes):
//   0x00-0x0B: AptValue base
//   0x0C-0x1F: AptNativeHash (8 entries)
//   0x20: u8 misc
//   0x24: IAptXmlNode* m_xmlNode  (at offset 36)
//
class AptXmlAttributes : public AptValue {
public:
    AptXmlAttributes(AptVirtualFunctionTable_Indices vftIdx, IAptXmlNode* xmlNode)
        : AptValue(vftIdx)
    {
        // Construct AptNativeHash(8) at this+12
        *(u8*)((char*)this + 32) = 0;
        // m_vtableDesc = &AptXmlAttributes_vtable
        *(IAptXmlNode**)((char*)this + 36) = xmlNode;
        u32 misc = *(u32*)((char*)this + 32);
        misc &= 0x003FFFFF;
        *(u32*)((char*)this + 32) = misc;
    }

    ~AptXmlAttributes() {
        *(u32*)((char*)this + 36) = 0;
        // m_vtableDesc = &AptObject_vtable
        // ~AptNativeHash at this+12
        // ~AptValue(mode=0)
        // If deleteFlag & 1: AptValueGC_PoolManager::DeallocateAptValueGC(this, 40)
    }

    // objectMemberSet: for XML attributes, checks if scope is type 34 (XMLATTRIBUTES)
    // and if value is a string type, then calls the underlying IAptXmlNode's setAttribute
    bool objectMemberSet(AptValue* scope, EAStringC* memberName, AptValue* value) {
        u32 scopeVt = scope->getVtblIndex();
        if (scopeVt != APT_VFT_XMLATTRIBUTES) {
            return true;
        }

        u32 valFlags = value->m_flags;
        u32 valVt = valFlags & 0x7F;
        bool isString = false;
        if ((valVt == APT_VFT_STRING || valVt == APT_VFT_STRING2) &&
            (valFlags & 0x08000000)) {
            isString = true;
        }

        if (!isString) {
            return true;
        }

        // Get the IAptXmlNode from scope (at scope offset 36)
        IAptXmlNode* xmlNode = *(IAptXmlNode**)((char*)scope + 36);
        // Get attribute name from memberName
        // Get string value from value (resolving STRING2)
        // Call xmlNode->setAttribute(name, strValue)
        // via vtable at offset 40

        return true;
    }
};


// =============================================================================
// AptScriptFunctionBase
// =============================================================================
//
// Layout (extends AptValue, ~52+ bytes):
//   0x00-0x0B: AptValue base
//   0x0C-0x1F: AptNativeHash
//   0x20: u8 misc
//   0x24: AptCIH* m_cih       (at offset 36)
//   0x28: AptValue* m_rootAnim (at offset 40)
//   0x2C: AptValue* m_scope    (at offset 44)
//   0x30: u16 m_numRegisters   (at offset 48)
//
class AptScriptFunctionBase : public AptValue {
public:
    // Static data management for ActionScript registers

    // InitializeStaticData: allocates the static register array
    static void InitializeStaticData(AptInitParmsT& parms) {
        u32 count = *(u32*)((char*)&parms + 48); // parms.m_numRegisters
        g_nStaticDataCount = count;
        AptValue** arr = (AptValue**)(operator new[](count * 4));
        g_pStaticDataArray = arr;
        g_pStaticDataCurrent = arr;

        if (count > 0) {
            for (u32 i = 0; i < count; i++) {
                arr[i] = gpUndefinedValue;
            }
        }
        g_nStaticDataUsed = 0;
    }

    // PopStaticData: restores static data from a saved pointer
    static void PopStaticData(void* savedPtr) {
        u32 i = 0;
        while (i < g_nStaticDataUsed) {
            AptValue** arr = g_pStaticDataCurrent;
            AptValue* old = arr[i];
            arr[i] = gpUndefinedValue;

            // Release old value
            old->Release("AptScriptFunctionBase.cpp", "PopStaticData", 206);
            i++;
        }

        // Restore pointer and recompute count
        AptValue** oldArr = g_pStaticDataCurrent;
        g_pStaticDataCurrent = (AptValue**)savedPtr;
        g_nStaticDataUsed = (u32)((char*)oldArr - (char*)savedPtr) / 4;
    }

    AptScriptFunctionBase(AptVirtualFunctionTable_Indices vftIdx,
                          AptScriptFunctionBase* parent, AptCIH* cih, bool flag)
        : AptValue(vftIdx)
    {
        // m_vtableDesc = intermediate
        // Construct AptNativeHash(8) at this+12
        *(u8*)((char*)this + 32) = 0;
        // m_vtableDesc = &AptScriptFunctionBase_vtable
        u32 misc = *(u32*)((char*)this + 32);
        misc &= 0x003FFFFF;
        *(u32*)((char*)this + 32) = misc;

        *(u16*)((char*)this + 48) = 0;
        *(AptCIH**)((char*)this + 36) = cih;
        *(AptValue**)((char*)this + 40) = nullptr;
        *(AptValue**)((char*)this + 44) = nullptr;

        if (parent != nullptr) {
            // Get parent's scope via vtable offset 200/204
            // Store the frame stack local
            AptValue* scope = g_pFrameStackLocal;
            *(AptValue**)((char*)this + 44) = scope;

            if (scope != nullptr) {
                scope->AddRef("AptScriptFunctionBase.cpp", "ctor", 250);
            }
        }

        // Determine root animation
        u32 cihFlags = ((AptValue*)cih)->m_flags;
        u32 cihVt = cihFlags & 0x7F;
        bool isCIH = (cihVt >= APT_VFT_CIH_FIRST && cihVt <= APT_VFT_CIH_LAST);
        if (isCIH) {
            // m_rootAnim = cih->getRootAnimation()
        } else {
            // m_rootAnim = _AptGetAnimationAtLevel(0)
        }
    }

    AptScriptFunctionBase(AptVirtualFunctionTable_Indices vftIdx,
                          AptScriptFunctionBase* source, AptCIH* cih)
        : AptValue(vftIdx)
    {
        // Copy constructor variant -- copies from source, updates cih
    }

    ~AptScriptFunctionBase() {
        // ~AptNativeHash at this+12
        // Release m_scope, m_rootAnim references
        // ~AptValue(mode=0)
    }

    void RegisterReferences() const;
    void DestroyGCPointers();
    void CleanupAfterExecution(_AptScriptFunctionState* state);
    void SetRegisterValue(int regIdx, AptValue* val);
    bool ExistsInLocalScope(EAStringC* name);
    void SetInLocalScope(EAStringC* name, AptValue* val);
    void SetWhereExistsInScopeChain(EAStringC* name, AptValue* val);
    AptValue* GetInScopeChain(EAStringC* name);
    void CreateFrameStack();
    void CreatingNestedFunction();
};


// =============================================================================
// AptScriptFunction1
// =============================================================================
//
// Layout (extends AptScriptFunctionBase, 56 bytes):
//   0x34: AptAction_DefineFunction* m_funcDef  (at offset 52)
//
class AptScriptFunction1 : public AptScriptFunctionBase {
public:
    AptScriptFunction1(AptScriptFunctionBase* parent, AptAction_DefineFunction* funcDef, AptCIH* cih)
        : AptScriptFunctionBase(APT_VFT_SCRIPTFUNCTION1, parent, cih, true)
    {
        *(AptAction_DefineFunction**)((char*)this + 52) = funcDef;
        // m_vtableDesc = &AptScriptFunction1_vtable
    }

    AptScriptFunction1(AptScriptFunction1* source, AptCIH* cih)
        : AptScriptFunctionBase(APT_VFT_SCRIPTFUNCTION1, source, cih)
    {
        // m_vtableDesc = &AptScriptFunction1_vtable
        // Copy m_funcDef from source
        *(u32*)((char*)this + 52) = *(u32*)((char*)source + 52);
    }

    ~AptScriptFunction1() {
        // m_vtableDesc = &AptScriptFunction1_vtable
        // ~AptScriptFunctionBase(mode=0)
        // If deleteFlag & 1: AptValueGC_PoolManager::DeallocateAptValueGC(this, 56)
    }

    void SetArgument(AptValue* value, int argIndex);
    AptValue* Duplicate(AptCIH* cih);
};


// =============================================================================
// AptScriptFunction2
// =============================================================================
//
// Layout (extends AptScriptFunctionBase, 56 bytes):
//   0x34: AptAction_DefineFunction2* m_funcDef2  (at offset 52)
//
class AptScriptFunction2 : public AptScriptFunctionBase {
public:
    AptScriptFunction2(AptScriptFunctionBase* parent, AptAction_DefineFunction2* funcDef, AptCIH* cih)
        : AptScriptFunctionBase(APT_VFT_SCRIPTFUNCTION2, parent, cih, true)
    {
        *(AptAction_DefineFunction2**)((char*)this + 52) = funcDef;
        // m_vtableDesc = &AptScriptFunction2_vtable
    }

    AptScriptFunction2(AptScriptFunction2* source, AptCIH* cih)
        : AptScriptFunctionBase(APT_VFT_SCRIPTFUNCTION2, source, cih)
    {
        // m_vtableDesc = &AptScriptFunction2_vtable
        *(u32*)((char*)this + 52) = *(u32*)((char*)source + 52);
    }

    ~AptScriptFunction2() {
        // m_vtableDesc = &AptScriptFunction2_vtable
        // ~AptScriptFunctionBase(mode=0)
        // If deleteFlag & 1: AptValueGC_PoolManager::DeallocateAptValueGC(this, 56)
    }

    void SetupBeforeExecution(_AptScriptFunctionState* state, AptValue* thisObj);
    void CleanupAfterExecution(_AptScriptFunctionState* state);
    void SetArgument(AptValue* value, int argIndex);
    AptValue* Duplicate(AptCIH* cih);
};


// =============================================================================
// AptTextFormat
// =============================================================================
//
// Layout (extends AptValue, ~60+ bytes):
//   0x00-0x0B: AptValue base
//   0x0C-0x1F: AptNativeHash
//   ... various TextFormat fields ...
//   0x2C: s32 m_size        (at offset 44)
//   0x30: u32 m_align       (at offset 48)
//   0x34: u32 m_styleFlags  (at offset 52)
//
class AptTextFormat : public AptValue {
public:
    AptTextFormat(AptValue* font, f32 size, u32 color, int bold, int italic,
                  int underline, int align, int leftMargin, AptValue* url,
                  int rightMargin, int indent, int leading, int letterSpacing);
    AptTextFormat(TextFormat* tf);

    ~AptTextFormat() {
        // Release various string references
        // ~AptNativeHash at this+12
        // ~AptValue(mode=0)
    }

    // objectMemberLookup: uses a perfect hash (TextFormatMembersIndex::in_word_set)
    // to quickly look up member names like "align", "bold", "color", "font",
    // "indent", "italic", "leading", "leftMargin", "rightMargin", "size",
    // "underline", "url", etc.
    AptValue* objectMemberLookup(AptValue* scope, EAStringC* memberName) const;

    // objectMemberSet: sets TextFormat properties by name
    bool objectMemberSet(AptValue* scope, EAStringC* memberName, AptValue* value);
};


// =============================================================================
// AptMathObj
// =============================================================================
//
// Layout (extends AptValue):
//   Hosts all ActionScript Math.* static methods
//
class AptMathObj : public AptValue {
public:
    AptMathObj() : AptValue(APT_VFT_MATH) {
        // Construct AptNativeHash(8) at this+12
        // m_vtableDesc = &AptMathObj_vtable
    }

    ~AptMathObj() {
        // ~AptNativeHash at this+12
        // ~AptValue(mode=0)
    }

    static void CleanNativeFunctions();

    AptValue* objectMemberLookup(AptValue* scope, EAStringC* memberName) const;

    // ActionScript Math prototype methods
    static void sMethod_sin(AptValue* args, int argc);
    static void sMethod_cos(AptValue* args, int argc);
    static void sMethod_atan2(AptValue* args, int argc);
    static void sMethod_round(AptValue* args, int argc);
    static void sMethod_min(AptValue* args, int argc);
    static void sMethod_max(AptValue* args, int argc);
    static void sMethod_abs(AptValue* args, int argc);
    static void sMethod_acos(AptValue* args, int argc);
    static void sMethod_asin(AptValue* args, int argc);
    static void sMethod_atan(AptValue* args, int argc);
    static void sMethod_ceil(AptValue* args, int argc);
    static void sMethod_exp(AptValue* args, int argc);
    static void sMethod_floor(AptValue* args, int argc);
    static void sMethod_log(AptValue* args, int argc);
    static void sMethod_pow(AptValue* args, int argc);
    static void sMethod_random(AptValue* args, int argc);
    static void sMethod_sqrt(AptValue* args, int argc);
    static void sMethod_tan(AptValue* args, int argc);
};


// =============================================================================
// AptViewer
// =============================================================================
//
// Layout (extends E3DWindow, ~1128+ bytes):
//   Inherited from E3DWindow (which extends EWindow)
//   0x350 (848): u32 m_loaded
//   0x354 (852): u32 m_pad852
//   0x358 (856): EMutex m_mutex
//   0x374 (884): u8* m_buttonData
//   0x378 (888): f32 m_scaleX
//   0x37C (892): f32 m_scaleY
//   0x3A0 (928): u32 m_pad928
//   0x3A4 (932): u32 m_controllerCount
//   0x3A8 (936): u32 m_playerCount
//   0x3AC (940): u32 m_padCount
//   0x3B0 (944): start of controller data arrays (2 x 80 bytes)
//   0x458 (1112): u32 m_pad1112
//   0x45C (1116): u32 m_pad1116
//   0x460 (1120): u32 m_pad1120
//   0x464 (1124): u32 m_pad1124
//
class AptViewer {
public:
    // The constructor is complex: initializes E3DWindow, EMutex,
    // zeroes out controller data arrays, sets scale factors, allocates
    // button filter data.
    AptViewer() {
        // E3DWindow::E3DWindow()
        // EMutex::EMutex() at this+856

        // Zero out two 80-byte controller arrays at this+944
        // (2 iterations of 10 32-bit store pairs)
        for (int j = 0; j < 2; j++) {
            u32* ptr = (u32*)((char*)this + 944 + j * 80);
            for (int i = 0; i < 10; i++) {
                ptr[i*2] = 0;
                ptr[i*2+1] = 0;
            }
        }

        *(u32*)((char*)this + 848) = 0;   // m_loaded = 0
        *(u32*)((char*)this + 852) = 0;
        *(u32*)((char*)this + 928) = 0;
        *(f32*)((char*)this + 892) = 1.0f; // m_scaleY = 1.0
        *(u32*)((char*)this + 940) = 0;    // m_padCount
        *(u32*)((char*)this + 936) = 1;    // m_playerCount
        *(f32*)((char*)this + 888) = 1.0f; // m_scaleX = 1.0
        *(u32*)((char*)this + 932) = 1;    // m_controllerCount

        // Allocate 16 bytes for button data
        u8* btnData = (u8*)operator new(16);
        *(u8**)((char*)this + 884) = btnData;

        // Initialize from global viewer config
        // Set global flags |= 2

        *(u32*)((char*)this + 1124) = 0;
        *(u32*)((char*)this + 1112) = 0;
        *(u32*)((char*)this + 1116) = 0;
        *(u32*)((char*)this + 1120) = 0;
    }

    ~AptViewer() {
        // UnLoad()
        // closeFunc()

        // Delete button data
        u8* btnData = *(u8**)((char*)this + 884);
        if (btnData != nullptr) {
            operator delete(btnData);
            *(u8**)((char*)this + 884) = nullptr;
        }

        // ~EMutex at this+856
        // ~EWindow(mode=0)
        // If deleteFlag & 1: free via MainHeap
    }

    void NewCallFunction(char* funcName, char* targetPath, char* file, int argc, ...);
    void NewCallFunction2(char* funcName, char* targetPath, char* file, int argc, char** args);
    void Init(UIObjectBase* uiObj);
    void UpdateAll();
    void Draw(ERC* rc);
    void Load(char* filename, bool flag);
    void LoadActionScript(char* filename, bool flag);
    void UnLoad();
    void RepeatCheck(int controller, int input);
    void NewReadController(int controller, bool repeat, int mode, bool exclusive);
    void OnePlayerReadController(int controller, int player);
    void PushAptButtonFilter(int controller, char* filterName);
    void PopAptButtonFilter(int controller, u32 filterHandle);
    void AddCmdToAptButtonFilter(int controller, u32 filterHandle, ECTRL_CMD cmd);
    void RemoveCmdFromAptButtonFilter(int controller, u32 filterHandle, ECTRL_CMD cmd);
    u32  GetCurrentAptButtonFilter(int controller);
    int  GetPlayersController(int player);
};


// =============================================================================
// AptWord
// =============================================================================
//
// Layout:
//   0x08: void* m_data   (character data buffer)
//   0x0C: void* m_format (AptFormat* for rendering)
//   0x10: void* m_fontFX (font effects)
//   0x1C: f32 m_x        (at offset 28)
//   0x20: f32 m_y        (at offset 32)
//   0x24: void* m_particles (at offset 36)
//
class AptWord {
public:
    void Draw(ERC* rc, EMat4* matrix, EVec4* highlightColor, EVec4* shadowColor);
    void SetWord(u16* chars, int length, EVec2& position);
    void Resize(f32 scale);
    void InsertSpace();
    void ForceFormat(AptWord* other);
    ~AptWord();
};


// =============================================================================
// AptParagraph
// =============================================================================
//
// Contains a list of AptWord objects forming a paragraph of text.
// Used by the text rendering system.
//
class AptParagraph {
public:
    void Draw(ERC* rc, EMat4* matrix, EVec4* highlightColor, EVec4* shadowColor);
    void InsertWord(AptWord* word);
    void InsertSpace();
    void Clear();
    void ForceFormat(AptParagraph* other);
    ~AptParagraph();
};


// =============================================================================
// AptDate
// =============================================================================
//
// ActionScript Date object
//
class AptDate : public AptValue {
public:
    AptDate();
    ~AptDate();

    static void CleanNativeFunctions();
    AptValue* objectMemberLookup(AptValue* scope, EAStringC* memberName) const;
    bool objectMemberSet(AptValue* scope, EAStringC* memberName, AptValue* value);

    // ActionScript Date methods
    static void sMethod_getDate(AptValue* args, int argc);
    static void sMethod_getDay(AptValue* args, int argc);
    static void sMethod_getFullYear(AptValue* args, int argc);
    static void sMethod_getHours(AptValue* args, int argc);
    static void sMethod_getMilliseconds(AptValue* args, int argc);
    static void sMethod_getMinutes(AptValue* args, int argc);
    static void sMethod_getMonth(AptValue* args, int argc);
    static void sMethod_getSeconds(AptValue* args, int argc);
    static void sMethod_getTime(AptValue* args, int argc);
    static void sMethod_getYear(AptValue* args, int argc);
    static void sMethod_setDate(AptValue* args, int argc);
    static void sMethod_setFullYear(AptValue* args, int argc);
    static void sMethod_setHours(AptValue* args, int argc);
    static void sMethod_setMilliseconds(AptValue* args, int argc);
    static void sMethod_setMinutes(AptValue* args, int argc);
    static void sMethod_setMonth(AptValue* args, int argc);
    static void sMethod_setSeconds(AptValue* args, int argc);
    static void sMethod_setTime(AptValue* args, int argc);
    static void sMethod_setYear(AptValue* args, int argc);
    static void sMethod_toString(AptValue* args, int argc);
};


// =============================================================================
// AptDisplayList
// =============================================================================
//
// Manages the depth-sorted display list for a MovieClip.
//
class AptDisplayList : public AptValue {
public:
    void addToDisplayList(AptCIH* cih, int depth);
    void removeFromDisplayList(AptCIH* cih);
    void removeAll();
    void swapDepths(AptCIH* a, AptCIH* b);
    void getNextHighestDepth() const;
    void getInstanceAtDepth(int depth) const;

    static void CleanNativeFunctions();
    AptValue* objectMemberLookup(AptValue* scope, EAStringC* memberName) const;
    bool objectMemberSet(AptValue* scope, EAStringC* memberName, AptValue* value);

    ~AptDisplayList();
};


// =============================================================================
// AptCIH (Character Instance Handler)
// =============================================================================
//
// Central class for managing character instances on the display list.
// Contains the matrix, color transform, display list state, and
// movie clip data for an instance.
//
// Layout (extends AptValue, 100 bytes):
//   0x0C: EAStringC m_name
//   0x10-0x44: Matrix3x3 + color transform
//   0x48: f32 m_alpha
//   0x4C: AptCharacterInst* m_characterInst (at offset 76)
//   0x50: AptCIH* m_prev  (at offset 80)
//   0x54: AptCIH* m_next  (at offset 84)
//   0x58: u32 m_depthAndFlags (at offset 88)
//   0x5C: u32 m_flags2       (at offset 92)
//   0x60: u32 m_pad96        (at offset 96)
//
class AptCIH : public AptValue {
public:
    bool hasRenderData();
    void GetMovieclipInfo(AptMovieclipInformation* outInfo);
    void jumpToFrame(int frame);
    AptValue* getRootAnimation();

    void render(AptRenderingContext* ctx);
    void _getBoundingRect(AptRenderingContext* ctx, AptRect* outRect);
};


// =============================================================================
// AptCharacterInst
// =============================================================================
//
// Character instance with ActionScript support.
// Handles MovieClip methods like gotoAndPlay, gotoAndStop, attachMovie, etc.
//
class AptCharacterInst : public AptValue {
public:
    // _gotoAndX: implements gotoAndPlay/gotoAndStop
    // If argCount > 0, resolves the frame from the argument (string label or int)
    // and calls jumpToFrame.
    void _gotoAndX(AptValue* args, int argCount, int playFlag) {
        if (argCount <= 0) return;

        // Get the last stack entry
        AptValue* frameArg = nullptr; // from stack
        if (this == nullptr) return;

        // Check if frameArg is a string (type 19 = CIH_LAST?)
        bool isUndefined = false;
        u32 vt = frameArg->getVtblIndex();
        if (vt == 19) {
            isUndefined = frameArg->isUndefined();
        }
        if (isUndefined) return;

        // Check if string type
        u32 flags = frameArg->m_flags;
        u32 valVt = flags & 0x7F;
        bool isString = false;
        if ((valVt == APT_VFT_STRING || valVt == APT_VFT_STRING2) &&
            (flags & 0x08000000)) {
            isString = true;
        }

        int frameNum;
        if (isString) {
            // Look up frame label in movie
            // AptCharacterInst* ci = (AptCharacterInst*)((char*)this + 76);
            // AptMovie* movie = ci->getMovie();
            // frameNum = movie->labelToFrame(frameArg->resolveString()) + 1;
            frameNum = 1; // placeholder
        } else {
            frameNum = frameArg->toInteger();
        }

        if (frameNum - 1 < 0) return;

        // jumpToFrame(frameNum - 1)
        // Set play/stop flag
    }

    static void CleanNativeFunctions();

    // ActionScript MovieClip methods
    static void sMethod_attachMovie(AptValue* args, int argc);
    static void sMethod_loadMovie(AptValue* args, int argc);
    static void sMethod_unloadMovie(AptValue* args, int argc);
    static void sMethod_duplicateMovieClip(AptValue* args, int argc);
    static void sMethod_removeMovieClip(AptValue* args, int argc);
    static void sMethod_removeTextField(AptValue* args, int argc);
    static void sMethod_createTextField(AptValue* args, int argc);
    static void sMethod_getDepth(AptValue* args, int argc);
    static void sMethod_swapDepths(AptValue* args, int argc);
    static void sMethod_setMask(AptValue* args, int argc);
    static void sMethod_getBounds(AptValue* args, int argc);
    static void sMethod_startDrag(AptValue* args, int argc);
    static void sMethod_hitTest(AptValue* args, int argc);
    static void sMethod_createEmptyMovieClip(AptValue* args, int argc);
    static void sMethod_loadVariables(AptValue* args, int argc);
    static void sMethod_stop(AptValue* args, int argc);
    static void sMethod_play(AptValue* args, int argc);
    static void sMethod_nextFrame(AptValue* args, int argc);
    static void sMethod_prevFrame(AptValue* args, int argc);
    static void sMethod_getBytesTotal(AptValue* args, int argc);
    static void sMethod_getBytesLoaded(AptValue* args, int argc);
    static void sMethod_setTextFormat(AptValue* args, int argc);
    static void sMethod_getNewTextFormat(AptValue* args, int argc);
    static void sMethod_getTextFormat(AptValue* args, int argc);
    static void sMethod_localToGlobal(AptValue* args, int argc);

    bool objectMemberSet(AptValue* scope, EAStringC* memberName, AptValue* value);
    AptValue* objectMemberLookup(AptValue* scope, EAStringC* memberName);

    ~AptCharacterInst();
};


// =============================================================================
// AptAnimationPoolData
// =============================================================================
//
// Manages pool data for APT animations.
//
class AptAnimationPoolData {
public:
    void Register(AptValue* val);
    void Unregister(AptValue* val);
    void Clear();
    ~AptAnimationPoolData();
};


// =============================================================================
// AptLinker
// =============================================================================
//
// Handles loading and linking of APT files (importing shared libraries).
//
// Layout:
//   0x00: linked list of pending loads
//   0x04: internal array of AptSharedPtr<AptFile>
//   0x10: internal array of loaded files
//
class AptLinker {
public:
    ~AptLinker() {
        // Walk internal arrays, decrement shared ptr refs, free nodes
        // Walk pending list, release shared ptrs, free nodes
    }

    void SwapOut(void* oldFile, void* newFile);
    void Update();
    void Notify(void* file);
    void Load(EAStringC& name, EAStringC basePath);
    void CancelLoad(AptCIH* cih);
};


// =============================================================================
// AptLoader
// =============================================================================
//
// File loader for APT resources.
//
// Layout:
//   0x00: linked list head (of loaded/loading files)
//
class AptLoader {
public:
    void* m_head;  // linked list of loaded files

    void* findFile(EAStringC& name) {
        // Walk linked list, compare file names using AptFileNameCompare
        return nullptr;
    }

    ~AptLoader() {
        // Walk list, cancel all preloaded animations
        // If deleteFlag & 1: DOGMA_PoolManager::Deallocate(this, 4)
    }

    void Invalidate(AptFile* file);
    void notify(void* file);
    bool IsLoaded(EAStringC& name);
    void* Load(EAStringC& name);
    bool AllImportsAvailable(void* file);
    void Update();
    void CompleteLoad(void* file, void* data, void* constData, void* stringData);
    void CancelPreloadedAnimation(EAStringC& name);
};


// =============================================================================
// AptStage
// =============================================================================
class AptStage : public AptValue {
public:
    AptStage();
    ~AptStage();
    static void CleanNativeFunctions();
    AptValue* objectMemberLookup(AptValue* scope, EAStringC* memberName) const;
    bool objectMemberSet(AptValue* scope, EAStringC* memberName, AptValue* value);
};


// =============================================================================
// AptSound
// =============================================================================
class AptSound : public AptValue {
public:
    AptSound();
    ~AptSound();
    static void CleanNativeFunctions();
    AptValue* objectMemberLookup(AptValue* scope, EAStringC* memberName) const;
    static void sMethod_attachSound(AptValue* args, int argc);
    static void sMethod_start(AptValue* args, int argc);
    static void sMethod_stop(AptValue* args, int argc);
    static void sMethod_setVolume(AptValue* args, int argc);
    static void sMethod_getVolume(AptValue* args, int argc);
    static void sMethod_setPan(AptValue* args, int argc);
    static void sMethod_getPan(AptValue* args, int argc);
};


// =============================================================================
// AptKey
// =============================================================================
class AptKey : public AptValue {
public:
    static void CleanNativeFunctions();
    AptValue* objectMemberLookup(AptValue* scope, EAStringC* memberName) const;
    static void sMethod_isDown(AptValue* args, int argc);
    static void sMethod_getCode(AptValue* args, int argc);
    static void sMethod_getAscii(AptValue* args, int argc);
};


// =============================================================================
// AptLine
// =============================================================================
class AptLine {
public:
    void Draw(ERC* rc, EMat4* matrix);
    ~AptLine();
};


// =============================================================================
// AptGlobal / AptGlobalExtensionObject
// =============================================================================
class AptGlobal : public AptValue {
public:
    AptGlobal();
    ~AptGlobal();
    static void CleanNativeFunctions();
    AptValue* objectMemberLookup(AptValue* scope, EAStringC* memberName) const;
    bool objectMemberSet(AptValue* scope, EAStringC* memberName, AptValue* value);
};

class AptGlobalExtensionObject : public AptValue {
public:
    static void CleanNativeFunctions();
    AptValue* objectMemberLookup(AptValue* scope, EAStringC* memberName) const;
    bool objectMemberSet(AptValue* scope, EAStringC* memberName, AptValue* value);
};


// =============================================================================
// AptRegister
// =============================================================================
class AptRegister : public AptValue {
public:
    ~AptRegister();
};


// =============================================================================
// AptRenderingContext
// =============================================================================
//
// Manages the matrix/color stack for APT rendering.
//
class AptRenderingContext {
public:
    void pushVertexMatrix();
    void popVertexMatrix();
    void appendVertexMatrix(AptMatrix* mat);
    void pushColorTransform();
    void popColorTransform();
    void expandBoundingRect(void* outRect, void* inRect);
};


// =============================================================================
// AptShaderWord
// =============================================================================
class AptShaderWord {
public:
    AptShaderWord();
    ~AptShaderWord();
};


// =============================================================================
// AptUserFunctions
// =============================================================================
class AptUserFunctions {
public:
    AptUserFunctions();
    ~AptUserFunctions();
};


// =============================================================================
// AptPseudoCIH_t / AptPseudoData_t / AptPseudoDisplayList
// =============================================================================
class AptPseudoCIH_t {
public:
    AptPseudoCIH_t();
    ~AptPseudoCIH_t();
};

class AptPseudoData_t {
public:
    AptPseudoData_t();
    ~AptPseudoData_t();
};

class AptPseudoDisplayList {
public:
    AptPseudoDisplayList();
    ~AptPseudoDisplayList();
};


// =============================================================================
// Character Instance Subclasses
// =============================================================================

class AptCharacterTextInst : public AptCharacterInst {
public:
    AptCharacterTextInst();
    ~AptCharacterTextInst();
};

class AptCharacterButtonInst : public AptCharacterInst {
public:
    ~AptCharacterButtonInst();
};

class AptCharacterSpriteInstBase : public AptCharacterInst {
public:
    ~AptCharacterSpriteInstBase();
};

class AptCharacterAnimationInst : public AptCharacterInst {
public:
    ~AptCharacterAnimationInst();
};

class AptCharacterMorphInst : public AptCharacterInst {
public:
    ~AptCharacterMorphInst();
};

class AptCharacterShapeInst : public AptCharacterInst {
public:
    ~AptCharacterShapeInst();
};

class AptCharacterStaticTextInst : public AptCharacterInst {
public:
    ~AptCharacterStaticTextInst();
};

class AptCharacterSpriteInst : public AptCharacterSpriteInstBase {
public:
    ~AptCharacterSpriteInst();
};


// =============================================================================
// AptActionQueueC
// =============================================================================
class AptActionQueueC {
public:
    void Enqueue(void* action);
    void Dequeue();
    void Clear();
    bool IsEmpty() const;
    ~AptActionQueueC();
};


// =============================================================================
// AptIntervalTimer
// =============================================================================
class AptIntervalTimer : public AptValue {
public:
    static void CleanNativeFunctions();
    AptValue* objectMemberLookup(AptValue* scope, EAStringC* memberName) const;
    static void sMethod_setInterval(AptValue* args, int argc);
    static void sMethod_clearInterval(AptValue* args, int argc);
};


// =============================================================================
// AptFrameStack
// =============================================================================
class AptFrameStack : public AptValue {
public:
    ~AptFrameStack();
    void RegisterReferences() const;
    void DestroyGCPointers();
};


// =============================================================================
// AptLoadVars
// =============================================================================
class AptLoadVars : public AptValue {
public:
    ~AptLoadVars();
    static void CleanNativeFunctions();
    AptValue* objectMemberLookup(AptValue* scope, EAStringC* memberName) const;
    bool objectMemberSet(AptValue* scope, EAStringC* memberName, AptValue* value);
    static void sMethod_load(AptValue* args, int argc);
    static void sMethod_send(AptValue* args, int argc);
    static void sMethod_sendAndLoad(AptValue* args, int argc);
    static void sMethod_toString(AptValue* args, int argc);
};


// =============================================================================
// AptLookup
// =============================================================================
class AptLookup : public AptValue {
public:
    ~AptLookup();
};


// =============================================================================
// AptMemoryAllocationsT
// =============================================================================
class AptMemoryAllocationsT {
public:
    void Report();
    ~AptMemoryAllocationsT();
};


// =============================================================================
// AptNativeFunction
// =============================================================================
class AptNativeFunction : public AptValue {
public:
    ~AptNativeFunction();
};


// =============================================================================
// AptSavedInputCheckpoints
// =============================================================================
class AptSavedInputCheckpoints {
public:
    void Save();
    void Restore();
    ~AptSavedInputCheckpoints();
};


// =============================================================================
// AptScriptColour
// =============================================================================
class AptScriptColour : public AptValue {
public:
    ~AptScriptColour();
    static void CleanNativeFunctions();
    AptValue* objectMemberLookup(AptValue* scope, EAStringC* memberName) const;
    static void sMethod_setRGB(AptValue* args, int argc);
    static void sMethod_getRGB(AptValue* args, int argc);
    static void sMethod_setTransform(AptValue* args, int argc);
    static void sMethod_getTransform(AptValue* args, int argc);
};


// =============================================================================
// AptStringObject
// =============================================================================
class AptStringObject : public AptValue {
public:
    static void CleanNativeFunctions();
    AptValue* objectMemberLookup(AptValue* scope, EAStringC* memberName) const;
};


// =============================================================================
// AptScriptFunctionByteCodeBlock
// =============================================================================
class AptScriptFunctionByteCodeBlock : public AptScriptFunctionBase {
public:
    AptScriptFunctionByteCodeBlock(AptScriptFunctionBase* parent, void* bytecodeData, AptCIH* cih);
    AptScriptFunctionByteCodeBlock(AptScriptFunctionByteCodeBlock* source, AptCIH* cih);
    ~AptScriptFunctionByteCodeBlock();
    void SetArgument(AptValue* value, int argIndex);
    AptValue* Duplicate(AptCIH* cih);
};


// =============================================================================
// AptValueGC / AptValueNoGC
// =============================================================================
class AptValueGC : public AptValue {
public:
    ~AptValueGC();
};

class AptValueNoGC : public AptValue {
public:
    ~AptValueNoGC();
};


// =============================================================================
// AptMovie
// =============================================================================
class AptMovie : public AptValue {
public:
    int labelToFrame(EAStringC* label);
    void Update();
    ~AptMovie();
};


// =============================================================================
// AptMovieClip
// =============================================================================
class AptMovieClip : public AptValue {
public:
    static void CleanNativeFunctions();
    AptValue* objectMemberLookup(AptValue* scope, EAStringC* memberName) const;
    bool objectMemberSet(AptValue* scope, EAStringC* memberName, AptValue* value);
    ~AptMovieClip();
};


// =============================================================================
// AptFormat
// =============================================================================
class AptFormat {
public:
    void Draw(EMat4* matrix, EVec4* highlightColor, EVec4* shadowColor);
    void ProcessParticles(ERC* rc, EMat4* matrix, EVec2& pos, EVec2& size,
                          f32 highlightAlpha, f32 shadowAlpha);
    ~AptFormat();
};


// =============================================================================
// AptFile
// =============================================================================
class AptFile : public AptValue {
public:
    ~AptFile();
    void Load(const char* filename);
    void Unload();
};


// =============================================================================
// AptMath (free functions, separate from AptMathObj)
// =============================================================================
class AptMath {
public:
    static f32 Sin(f32 angle);
    static f32 Cos(f32 angle);
    static f32 Atan2(f32 y, f32 x);
    static f32 Sqrt(f32 val);
    static f32 Abs(f32 val);
    static int Random(int max);
};


// =============================================================================
// AptActionInterpreter
// =============================================================================
//
// The stack-based bytecode interpreter for APT ActionScript.
// This class manages the execution stack, local variables, and
// dispatches opcodes.
//
// Full decompilation of this class requires converting ~680 bytes
// of complex PPC assembly per opcode handler. The structure and
// key methods are documented here.
//
class AptActionInterpreter {
public:
    u16  m_stackTop;       // 0x00
    u16  m_pad02;          // 0x02
    f32  m_tempFloat;      // 0x04
    u32  m_stackData;      // 0x08
    f32  m_tempFloat2;     // 0x0C
    u32  m_streamPos;      // 0x10
    u32  m_funcDefTemp;    // 0x14

    // Push/Pop for the value stack
    void Push(AptValue* val);
    AptValue* Pop();
    AptValue* Peek() const;

    // Opcode execution
    void Execute(void* context, u8* bytecode, u32 length);

    // Individual opcode handlers (selected):
    void op_ActionAdd(void* ctx);
    void op_ActionSubtract(void* ctx);
    void op_ActionMultiply(void* ctx);
    void op_ActionDivide(void* ctx);
    void op_ActionEquals(void* ctx);
    void op_ActionLess(void* ctx);
    void op_ActionAnd(void* ctx);
    void op_ActionOr(void* ctx);
    void op_ActionNot(void* ctx);
    void op_ActionPush(void* ctx);
    void op_ActionPop(void* ctx);
    void op_ActionJump(void* ctx);
    void op_ActionIf(void* ctx);
    void op_ActionCall(void* ctx);
    void op_ActionReturn(void* ctx);
    void op_ActionGetVariable(void* ctx);
    void op_ActionSetVariable(void* ctx);
    void op_ActionGetMember(void* ctx);
    void op_ActionSetMember(void* ctx);
    void op_ActionDefineFunction(void* ctx);
    void op_ActionDefineFunction2(void* ctx);
};


// =============================================================================
// AptValueGC_PoolManager (implementation details)
// =============================================================================
//
// The pool manager maintains a chunked allocation pool for GC-managed
// AptValue objects. It provides iteration (GetFirst/GetNext) for the
// garbage collector to walk all live objects.
//
// This is accessed via the global g_pAptValueGCPoolMgr.
//


// =============================================================================
// End of apt_classes.cpp
// =============================================================================
