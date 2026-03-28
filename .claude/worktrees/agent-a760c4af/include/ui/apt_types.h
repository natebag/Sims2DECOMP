#ifndef APT_TYPES_H
#define APT_TYPES_H

#include "types.h"
#include "ui/apt_value.h"

// Forward declarations
class AptCIH;
class AptDisplayList;
class AptNativeHash;
class AptControl;
class AptFile;
class AptLinkerThingy;
struct AptConstFile;

// ============================================================================
// AptArray - ActionScript Array type
// Layout (partial):
//   0x24: AptValue** m_data (array of value pointers)
//   0x28: u32 m_pad28
//   0x2C: u32 m_length (number of elements)
// ============================================================================
class AptArray : public AptValueGC {
public:
    // Additional fields beyond AptValueGC base
    // ...up to 0x24
    AptValue** m_data;    // 0x24
    u32 m_pad28;          // 0x28
    u32 m_length;         // 0x2C

    AptValue* get(int index);
    int length();
    AptValue* GetAt(int index) const;
    void ConvertAptValue(AptValue* val);

    // Static method dispatchers (stored as data, not code)
    static AptValue* (*psMethod_concat);
    static AptValue* (*psMethod_join);
    static AptValue* (*psMethod_pop);
    static AptValue* (*psMethod_push);
    static AptValue* (*psMethod_shift);
    static AptValue* (*psMethod_unshift);
    static AptValue* (*psMethod_reverse);
    static AptValue* (*psMethod_sort);
    static AptValue* (*psMethod_splice);
    static AptValue* (*psMethod_slice);
    static AptValue* (*psMethod_sortOn);
};

// ============================================================================
// AptDate - ActionScript Date type
// ============================================================================
class AptDate : public AptValueGC {
public:
    static int dateGetNumDaysInYear(int year);
    static int dateIsLeapYear(int year);

    static AptValue* sMethod_UTC(AptValue* thisObj, int argc);

    // Static method dispatchers (stored as data, not code)
    static AptValue* (*psMethod_getDate);
    static AptValue* (*psMethod_getDay);
    static AptValue* (*psMethod_getFullYear);
    static AptValue* (*psMethod_getHours);
    static AptValue* (*psMethod_getMilliseconds);
    static AptValue* (*psMethod_getMinutes);
    static AptValue* (*psMethod_getMonth);
    static AptValue* (*psMethod_getSeconds);
    static AptValue* (*psMethod_getTime);
    static AptValue* (*psMethod_getTimezoneOffset);
    static AptValue* (*psMethod_getUTCDate);
    static AptValue* (*psMethod_getUTCDay);
    static AptValue* (*psMethod_getUTCFullYear);
    static AptValue* (*psMethod_getUTCHours);
    static AptValue* (*psMethod_getUTCMilliseconds);
    static AptValue* (*psMethod_getUTCMinutes);
    static AptValue* (*psMethod_getUTCMonth);
    static AptValue* (*psMethod_getUTCSeconds);
    static AptValue* (*psMethod_getYear);
    static AptValue* (*psMethod_setDate);
    static AptValue* (*psMethod_setFullYear);
    static AptValue* (*psMethod_setHours);
    static AptValue* (*psMethod_setMilliseconds);
    static AptValue* (*psMethod_setMinutes);
    static AptValue* (*psMethod_setMonth);
    static AptValue* (*psMethod_setSeconds);
    static AptValue* (*psMethod_setTime);
    static AptValue* (*psMethod_setUTCDate);
    static AptValue* (*psMethod_setUTCFullYear);
    static AptValue* (*psMethod_setUTCHours);
    static AptValue* (*psMethod_setUTCMilliseconds);
    static AptValue* (*psMethod_setUTCMinutes);
    static AptValue* (*psMethod_setUTCMonth);
    static AptValue* (*psMethod_setUTCSeconds);
    static AptValue* (*psMethod_setYear);
    static AptValue* (*psMethod_toString);
    static AptValue* (*psMethod_UTC_ptr);
};

// ============================================================================
// AptSound - ActionScript Sound type
// ============================================================================
class AptSound : public AptValueGC {
public:
    static AptValue* sMethod_stop(AptValue* thisObj, int argc);

    static AptValue* (*psMethod_attachSound);
    static AptValue* (*psMethod_stop_ptr);
    static AptValue* (*psMethod_start);
};

// ============================================================================
// AptObject - ActionScript object base
// Layout (partial):
//   0x0C: AptNativeHash (embedded, starts at this+12)
//   0x20: u32 m_objectFlags (bitfield)
//         bit 8 (MSB 23): hasClass
//         bit 9 (MSB 22): inMainInst
// ============================================================================
class AptObject : public AptValueGC {
public:
    // Embedded AptNativeHash at offset 0x0C (m_pad0C in AptValue)
    // Additional fields:
    u32 m_objectFlags;  // 0x20 - bitfield

    AptValue* objectMemberLookup(AptValue* obj, EAStringC* name) const;
    void RegisterReferences() const;
    void DestroyGCPointers();

    int getHasClass() const;
    void setHasClass(int val);
    int getInMainInst() const;
    void setInMainInst(int val);

    void Set(EAStringC* key, AptValue* val);
    AptValue* Lookup(EAStringC* key) const;
};

// ============================================================================
// AptPrototype - prototype object with super constructor ref
// Layout (partial):
//   0x20: AptValue* m_superConstructor
// ============================================================================
class AptPrototype : public AptValueGC {
public:
    AptValue* GetSuperConstructor() const;
};

// ============================================================================
// AptTextFormat - ActionScript TextFormat type
// ============================================================================
class AptTextFormat : public AptValueGC {
public:
    void* operator new(unsigned int size);
    void operator delete(void* ptr, unsigned int size);
    void* operator new[](unsigned int size);
    void operator delete[](void* ptr);
};

// ============================================================================
// AptCIH - Character Instance Handler
// Layout (partial):
//   0x00: u32 (bitfield with zombie state at bits 20-21, etc.)
//   0x48: AptCIH* m_parent
//   0x4C: void* m_characterInst (various inst types share offset)
//   0x5C: u32 m_cihFlags (bitfield)
//         bits 0-15:  zombieCount (u16, accessed via lhz/sth at 0x5C)
//         bit 17 (MSB 14): hasClass
//         bit 16 (MSB 15): asChanged
//         bits 18-19 (MSB 12-13): zombieState
//         bit 21 (MSB 10): inCtor
// ============================================================================
class AptCIH : public AptValueGC {
public:
    AptValue* GetNativeHashVirtual();
    int ContainsNativeHashVirtual() const;
    AptValue* objectMemberLookup(AptValue* obj, EAStringC* name) const;
    int objectMemberSet(AptValue* obj, EAStringC* name, AptValue* val);
    void Release(char* file, char* func, int line);

    // Parent chain
    int getParentCount();
    int isParent(AptCIH* parent);

    // Events
    int HasMouseEvent();
    int HasEvent(int eventMask);

    // Zombie system
    void decZombieCount();
    void incZombieCount();
    u32 getZombieCount();
    void setZombieSate(int state);
    int getZombieState() const;

    // Class flag
    int getHasClass() const;
    void setHasClass(int val);

    // AS changed flag
    void setASChanged(int val);
    int getASChanged() const;

    // Constructor flag
    int IsInCtor() const;
    void SetInCtor(unsigned int val);

    // Character instance accessors (all return m_characterInst at offset 0x4C)
    void* getSpriteInst() const;
    void* getSpriteInstBase() const;
    void* getTextInst() const;
    void* getStaticTextInst() const;
    void* getMorphInst() const;
    void* getButtonInst() const;
    void* getAnimationInst() const;
    void* getShapeInst() const;
    void* getCharacterInst() const;

    // Embedded native hash access
    AptNativeHash* GetNativeHash();

    static EAStringC emptyAssetString;
};

// ============================================================================
// AptCharacterAnimationInst - animation character instance
// Layout (partial):
//   0x24: AptDisplayList (embedded, via addi r3,r3,36)
//   0x34: AptControl* m_control
// ============================================================================
class AptCharacterAnimationInst : public AptValue {
public:
    int getSwfVersion();
    void PreDestroy();

    void* operator new(unsigned int size);
    void operator delete(void* ptr, unsigned int size);
    void* operator new[](unsigned int size);
    void operator delete[](void* ptr);
};

// ============================================================================
// AptActionQueueC - action queue with pool-based allocation
// Layout:
//   0x00: void* m_poolStart (base of pool)
//   0x04: void* m_dequeStart
//   0x08: void* m_dequeEnd
//   0x10: u32 m_poolCount
// ============================================================================
class AptActionQueueC {
public:
    struct AptActionPool;

    void* m_poolStart;   // 0x00
    void* m_dequeStart;  // 0x04
    void* m_dequeEnd;    // 0x08
    u32 m_pad0C;         // 0x0C
    u32 m_poolCount;     // 0x10

    int GetDequeSize() const;
    AptActionPool* IncrementDequeLocation(AptActionPool* pool);

    void operator delete(void* ptr, unsigned int size);
};

// ============================================================================
// AptAnimationPoolData - animation pool with input handling
// Extended layout:
//   0x04: u32 field_04
//   0x10: u32 field_10
//   0x30: u32 field_30
//   0x34: u32 field_34
//   0x3C: u32 field_3C
//   0x58: u32 field_58
//   0x5C: u32 field_5C
//   0x60: AptValue* m_undefinedValue (from gpUndefinedValue)
//   0x64: u32 field_64
//   0x68: u32 field_68
//   0x6C: u32 field_6C
//   0x70: u32 field_70
//   0x94: AptCIH* m_inputMask
//   0x98: void* m_actionPool
// ============================================================================
class AptAnimationPoolData {
public:
    void Reset();
    void addInput(u32 encodedInput);
    void addInput(int type, int state, int controller);
    void setInputMask(AptCIH* mask);
    int isInputMasked(AptCIH* cih);
    void* GetActionPool();
};

// ============================================================================
// AptPseudoData_t, AptPseudoCIH_t, AptPseudoDisplayList - pseudo types
// ============================================================================
class AptPseudoData_t {
public:
    void operator delete(void* ptr, unsigned int size);
};

class AptPseudoCIH_t {
public:
    void operator delete(void* ptr, unsigned int size);
};

class AptPseudoDisplayList {
public:
    void operator delete(void* ptr, unsigned int size);
};

// ============================================================================
// AptFile - loaded APT file
// Layout (partial):
//   0x00: u32 m_refCount
//   0x10: void* m_mainCharacter
// ============================================================================
class AptFile {
public:
    u32 m_refCount;        // 0x00
    u32 m_pad04;           // 0x04
    u32 m_pad08;           // 0x08
    u32 m_pad0C;           // 0x0C
    void* m_mainCharacter; // 0x10

    void* GetMainCharacter() const;

    void operator delete(void* ptr, unsigned int size);
};

// ============================================================================
// AptLinkerThingy - linker reference type
// Layout (partial):
//   0x00: u32 m_refCount
// ============================================================================
class AptLinkerThingy {
public:
    u32 m_refCount; // 0x00
};

// ============================================================================
// Shared pointer helpers
// ============================================================================
void AptSharedPtrIncRef(AptFile* ptr);
void AptSharedPtrDecRef(AptFile* ptr);
void AptSharedPtrIncRef(AptLinkerThingy* ptr);
void AptSharedPtrDecRef(AptLinkerThingy* ptr);

// ============================================================================
// Pool managers (global pointers accessed via r13/SDA)
// ============================================================================
class DOGMA_PoolManager {
public:
    void* Allocate(unsigned int size);
    void Deallocate(void* ptr, unsigned int size);
};

class AptValueGC_PoolManager {
public:
    void* AllocateAptValueGC(unsigned int size);
    void DeallocateAptValueGC(AptValueGC* ptr, unsigned int size);
};

extern DOGMA_PoolManager* gpNonGCPoolManager;
extern AptValueGC_PoolManager* gpGCPoolManager;

// Global script sort function pointers (AptArray)
extern AptValue* (*gpfnScriptSortFunctionFunction);
extern AptValue* (*gpfnScriptSortFunctionContext);

// Free functions
void* AptNonGCAllocSaveSize(unsigned int size);
void AptNonGCFreeSavedSize(void* ptr);
void AptUpdateZombieVector(bool flag);

// AptDisplayList
class AptDisplayList {
public:
    void clear(bool flag);
};

// AptNativeHash - hash table for APT values
class AptNativeHash {
public:
    void Set(EAStringC* key, AptValue* val);
    AptValue* Lookup(EAStringC* key) const;
    void DestroyGCPointers();
    void RegisterReferences() const;
};

// AptCharacterInst forward declaration only.
// Full class definition is in apt_character.h.
// Methods used here: objectMemberLookup, objectMemberSet, DestroyGCPointers
class AptCharacterInst;

#endif // APT_TYPES_H
