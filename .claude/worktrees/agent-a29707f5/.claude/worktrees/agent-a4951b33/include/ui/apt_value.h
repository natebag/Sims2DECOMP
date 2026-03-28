#ifndef APT_VALUE_H
#define APT_VALUE_H

#include "types.h"

// Forward declarations
class AptValue;
class AptValueGC;
class AptValueNoGC;
class AptValueWithHash;
class AptNativeHash;
class AptNativeFunction;
class AptExtern;
class AptNone;
class AptGlobalExtensionObject;
class AptCIH;
class AptArray;
class AptValueVector;
struct EAStringC;
struct AptValueGC_PoolManager;

// AptVirtualFunctionTable_Indices enum
// Derived from isXxx() type checks in AptValue.cpp
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

// AptValue bitfield layout (32-bit m_flags at offset 0x00):
// MSB-0 bit numbering (PPC convention):
//   bit  0:    (unused)
//   bit  1:    gcMark
//   bit  2:    isReleaseAtEnd
//   bit  3:    (unused)
//   bit  4:    isDefined
//   bit  5:    allowDelayedDeletion
//   bits 6-17: refCount (12 bits, max 4095)
//   bits 18-23: gcRoot (6 bits, max 63)
//   bit  24:   maxRefCountHit
//   bits 25-31: vtblIndex (7 bits)

// APT uses a CUSTOM virtual dispatch mechanism, NOT C++ virtual functions.
// The vtable descriptor is stored at offset 0x08, containing pairs of
// (s16 thisAdjust, funcPtr) for each virtual slot.
// There is NO compiler-generated vtable pointer in the object layout.

struct AptValueVTableDesc;

// AptValue - the core variant/value type in EA's APT ActionScript engine
// Object layout:
//   0x00: u32 m_flags (bitfield with type tag, refcount, GC bits)
//   0x04: u32 m_data  (union: integer, float bits, pointer, etc.)
//   0x08: AptValueVTableDesc* m_vtableDesc (custom vtable descriptor)
//   0x0C+: subclass-specific data
//   ...
//   0x24: AptValue* m_stringData (used by c_string for non-string types)
class AptValue {
public:
    // Tag used to distinguish CIH-only constructor
    enum CIH_ONLY { CIH_ONLY_TAG };

    u32 m_flags;                        // 0x00 - bitfield
    u32 m_data;                         // 0x04 - union data
    AptValueVTableDesc* m_vtableDesc;   // 0x08 - custom vtable descriptor
    u32 m_pad0C;                        // 0x0C
    u32 m_pad10;                        // 0x10
    u32 m_pad14;                        // 0x14
    u32 m_pad18;                        // 0x18
    u32 m_pad1C;                        // 0x1C
    u32 m_pad20;                        // 0x20
    AptValue* m_stringData;             // 0x24 - used by c_string fallback

    // Constructors / Destructor
    AptValue(AptVirtualFunctionTable_Indices vtblIdx);
    AptValue(AptVirtualFunctionTable_Indices vtblIdx, CIH_ONLY);
    ~AptValue();

    // Vtable index / type
    AptVirtualFunctionTable_Indices getVtblIndex() const;
    void setVtblIndex(AptVirtualFunctionTable_Indices idx);

    // Bitfield accessors
    bool getIsDefined() const;
    void setIsDefined(bool val);
    bool GetAllowDelayedDeletion() const;
    void SetAllowDelayedDeletion(bool val);
    bool GetMaxRefCountHit() const;
    void SetMaxRefCountHit(bool val);
    bool getGCMark() const;
    void setGCMark(bool val);
    u32 getGCRoot() const;
    void setGCRoot(u32 val);
    void incGCRoot();
    void decGCRoot();
    u32 getRefCount() const;
    void setRefCount(u32 val);
    bool IsReleaseAtEnd() const;
    void SetReleaseAtEnd();
    void ClearReleaseAtEnd();
    bool isUndefined() const;

    // Type cast accessors (return this for most types)
    AptValue* c_lookup() const;
    AptValue* c_integer() const;
    AptValue* c_register() const;
    AptValue* c_float() const;
    AptValue* c_string() const;
    AptValue* c_boolean() const;
    AptValue* c_scriptfunction() const;
    AptValue* c_nativefunction() const;
    AptValue* c_cih(bool) const;
    AptValue* c_array() const;
    AptValue* c_sound() const;
    AptValue* c_key() const;
    AptValue* c_global() const;
    AptValue* c_math() const;
    AptValue* c_scriptcolour() const;
    AptValue* c_object() const;
    AptValue* c_prototype() const;
    AptValue* c_date() const;
    AptValue* c_textformat() const;
    AptValue* c_movieClip() const;
    AptValue* c_xmlnode() const;
    AptValue* c_xml() const;
    AptValue* c_xmlattributes() const;
    AptValue* c_loadvars() const;
    AptValue* c_stage() const;

    // Type check functions
    bool isXmlNode() const;
    bool isXml() const;
    bool isXmlAttributes() const;
    bool isLoadVars() const;
    bool isNone() const;
    bool isLookup() const;
    bool isString() const;
    bool isBoolean() const;
    bool isInteger() const;
    bool isRegister() const;
    bool isFloat() const;
    bool isNativeFunction() const;
    bool isScriptFunction() const;
    bool isExtern() const;
    bool isFrameStack() const;
    bool isArray() const;
    bool isSound() const;
    bool isKey() const;
    bool isMath() const;
    bool isScriptColour() const;
    bool isCIH(bool includeUndefined) const;
    bool isObject() const;
    bool isPrototype() const;
    bool isDate() const;
    bool isTextFormat() const;
    bool isMovieClip() const;
    bool isStage() const;

    // Conversion
    int toInteger() const;
    float toFloat() const;
    bool toBool() const;
    void toString(char* buf) const;
    void toString(EAStringC& str) const;
    bool CanCreateScriptObject() const;

    // Reference counting
    void AddRef(char* file, char* func, int line);
    void Release(char* file, char* func, int line);

    // Custom virtual functions (dispatched through m_vtableDesc, NOT C++ virtual)
    AptValue* GetNativeHashVirtual();
    bool ContainsNativeHashVirtual() const;
    bool getHasClass() const;
    void setHasClass(int val);
    AptValue* objectMemberLookup(AptValue* obj, EAStringC* name) const;
    int objectMemberSet(AptValue* obj, EAStringC* name, AptValue* val);
    void PreDestroy();
    void DestroyGCPointers();
    void DeleteThis();

    // Misc
    void ForceDelete();
    bool isMCInParentChain() const;
    void urlEncode();
    void urlEncodeCustomRender();
    AptValue* findChild(EAStringC* name, AptValue* val);

    // Static
    static void (*sReferenceRegistrationCb)(AptValue*, AptValue*, char*);
    static int snCurrentAllocationNumber;
    static int sbSuspendRefcountDeletions;
};

// AptValueGC - garbage collected value (returns true for IsGarbageCollected)
class AptValueGC : public AptValue {
public:
    bool IsGarbageCollected() const;
};

// AptValueNoGC - non-garbage collected value
class AptValueNoGC : public AptValue {
public:
    bool IsGarbageCollected() const;
    void RegisterReferences() const;
};

// AptValueWithHash - AptValue with an embedded AptNativeHash at this+12
class AptValueWithHash : public AptValue {
public:
    // AptNativeHash is embedded starting at offset 0x0C (this + 12)
    // The m_pad0C and subsequent fields overlap with hash data

    AptValueWithHash(AptVirtualFunctionTable_Indices vtblIdx, int param);
    ~AptValueWithHash();

    AptValue* GetNativeHashVirtual();
    bool ContainsNativeHashVirtual() const;
    void RegisterReferences() const;
    void DestroyGCPointers();

    AptValue* Lookup(EAStringC* key) const;
    void Set(EAStringC* key, AptValue* val);
};

// AptExtern - extern value (AddRef/Release are no-ops)
class AptExtern : public AptValue {
public:
    void AddRef(char* file, char* func, int line);
    void Release(char* file, char* func, int line);
    ~AptExtern();
    int objectMemberSet(AptValue* obj, EAStringC* name, AptValue* val);
};

// AptNone - none/null value (AddRef/Release are no-ops)
class AptNone : public AptValue {
public:
    void AddRef(char* file, char* func, int line);
    void Release(char* file, char* func, int line);
    ~AptNone();
};

// AptNativeFunction - native C++ callback function
class AptNativeFunction : public AptValue {
public:
    ~AptNativeFunction();
};

// AptGlobalExtensionObject
class AptGlobalExtensionObject : public AptValue {
public:
    ~AptGlobalExtensionObject();
};

// EAStringC - EA's simple string class
// Layout:
//   0x00: pointer to internal data block
// Internal data block layout:
//   0x00: u16 refCount
//   0x04: u16 length
//   0x08: char data[] (null-terminated)
struct EAStringCInternalData {
    u16 m_refCount;         // 0x00
    u16 m_pad;              // 0x02
    u16 m_length;           // 0x04
    u16 m_pad2;             // 0x06
    // char m_data[];       // 0x08 - variable length string data
};

extern EAStringCInternalData EAStringC_s_EmptyInternalData;

struct EAStringC {
    EAStringCInternalData* m_pData; // 0x00

    EAStringC();
    EAStringC(char* str);
    ~EAStringC();
    const char* c_str() const;
    operator char*() const;
    bool IsEmpty() const;
};

// AptValueVector - simple vector of AptValue pointers
struct AptValueVector {
    u32 m_capacity;         // 0x00
    u32 m_size;             // 0x04
    AptValue** m_data;      // 0x08

    void PushValue(AptValue* val);
};

// Global variables
extern AptValue* gpUndefinedValue;
extern AptValue* gpObjRegistrationFunc;
extern AptValue* gpObjectPrototype;

// Free functions
AptValue* _constructorObject(AptValue* thisObj, int argc);

#endif // APT_VALUE_H
