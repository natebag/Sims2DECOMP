// apt_types.cpp - Small functions from APT library types
// From libaptz.a: AptAnimation, AptArray, AptCIH, AptDate, AptLoad,
//   AptNativeHash, AptObject, AptSound, AptTextFormat

#include "ui/apt_types.h"
#include "ui/apt_value.h"
#include "ui/apt_character.h"

extern "C" int strcmp(const char*, const char*);

// Global pool managers (SDA-relative via r13)
extern DOGMA_PoolManager* gpNonGCPoolManager;
extern AptValueGC_PoolManager* gpGCPoolManager;
extern AptValue* gpUndefinedValue;
extern AptValue* gpObjRegistrationFunc;

// ============================================================================
// AptAnimation.cpp.obj functions
// ============================================================================

// AptCharacterAnimationInst::getSwfVersion
// NON_MATCHING - register allocation may differ
// Reads version byte from control->constFile->data[8], converts '0'-'9' to int
int AptCharacterAnimationInst::getSwfVersion() {
    // this+0x34 = m_control
    u32* pControl = (u32*)((u8*)this + 0x34);
    u32 control = *pControl;
    // control+0x0C = constFile ptr
    u32 constFile = *(u32*)(control + 0x0C);
    // constFile+0x08 = version string ptr
    u8 ch = *(u8*)(constFile + 0x08);
    if (ch == ':') {
        s8 digit = *(s8*)(constFile + 0x09);
        return digit - '0';
    }
    return 6;
}

// AptCharacterAnimationInst::PreDestroy
// NON_MATCHING - GCC emits tail call, SN emits full wrapper
// Calls AptDisplayList::clear(false) on embedded display list at this+0x24
void AptCharacterAnimationInst::PreDestroy() {
    AptDisplayList* dl = (AptDisplayList*)((u8*)this + 0x24);
    dl->clear(false);
}

// AptActionQueueC::operator delete
// NON_MATCHING - SDA access to gpNonGCPoolManager differs
void AptActionQueueC::operator delete(void* ptr, unsigned int size) {
    gpNonGCPoolManager->Deallocate(ptr, size);
}

// AptAnimationPoolData::Reset
// NON_MATCHING - register allocation, SDA access
void AptAnimationPoolData::Reset() {
    u32* p = (u32*)this;
    u32 undef = (u32)gpUndefinedValue;

    *(u32*)((u8*)this + 0x94) = 0;   // m_inputMask = NULL
    *(u32*)((u8*)this + 0x60) = undef; // field_60 = gpUndefinedValue
    *(u32*)((u8*)this + 0x04) = 0;
    *(u32*)((u8*)this + 0x34) = 0;
    *(u32*)((u8*)this + 0x64) = 0;
    *(u32*)((u8*)this + 0x68) = 0;
    *(u32*)((u8*)this + 0x10) = 0;
    *(u32*)((u8*)this + 0x6C) = 0;
    *(u32*)((u8*)this + 0x70) = 0;
    *(u32*)((u8*)this + 0x30) = 0;
    *(u32*)((u8*)this + 0x3C) = undef;
    *(u32*)((u8*)this + 0x58) = undef;
    *(u32*)((u8*)this + 0x5C) = undef;
}

// AptActionQueueC::IncrementDequeLocation
// NON_MATCHING - register allocation differs
AptActionQueueC::AptActionPool* AptActionQueueC::IncrementDequeLocation(AptActionPool* pool) {
    AptActionPool* next = (AptActionPool*)((u8*)pool + 20);
    u8* end = (u8*)m_poolStart + m_poolCount * 20;
    if ((u8*)next == end) {
        next = (AptActionPool*)m_poolStart;
    }
    return next;
}

// AptAnimationPoolData::addInput(AptInputType, AptInputState, AptInputController)
// NON_MATCHING - bit manipulation encoding may differ
// Encodes type/state/controller into a single u32, calls addInput(u32)
void AptAnimationPoolData::addInput(int type, int state, int controller) {
    u32 encoded = ((u32)type << 17) | (((u32)state << 10) & 0x003FC000) | 1;
    encoded |= ((u32)controller << 2) & 0x000003FC;
    addInput(encoded);
}

// AptAnimationPoolData::setInputMask - MATCHING
// Stores CIH pointer at offset 0x94
void AptAnimationPoolData::setInputMask(AptCIH* mask) {
    *(AptCIH**)((u8*)this + 0x94) = mask;
}

// AptAnimationPoolData::isInputMasked
// NON_MATCHING - branch structure may differ
// Walks parent chain of cih, returns 0 if cih or any parent == m_inputMask
int AptAnimationPoolData::isInputMasked(AptCIH* cih) {
    u32 mask = *(u32*)((u8*)this + 0x94);
    if (mask == 0) {
        return 0;
    }
    AptCIH* cur = cih;
    while (cur != 0) {
        if ((u32)cur == mask) {
            return 0;
        }
        cur = *(AptCIH**)((u8*)cur + 0x48);
    }
    return 1;
}

// AptActionQueueC::GetDequeSize
// NON_MATCHING - signed division pattern differs
int AptActionQueueC::GetDequeSize() const {
    int diff = (int)((u8*)m_dequeEnd - (u8*)m_dequeStart);
    int count = diff / 20;
    if (count < 0) {
        count += (int)m_poolCount;
    }
    return count;
}

// AptCharacterInst::DestroyGCPointers (from AptAnimation.cpp.obj)
// NON_MATCHING - register allocation differs
// Destroys native hash GC pointers, sets gc flag
void AptCharacterInst::DestroyGCPointers() {
    AptNativeHash* hash = (AptNativeHash*)m_pad0C;
    if (hash != 0) {
        hash->DestroyGCPointers();
    }
    m_pad10 = 1;
}

// AptCharacterAnimationInst::operator new
// NON_MATCHING - SDA access to gpNonGCPoolManager
void* AptCharacterAnimationInst::operator new(unsigned int size) {
    return gpNonGCPoolManager->Allocate(size);
}

// AptCharacterAnimationInst::operator delete
// NON_MATCHING - SDA access to gpNonGCPoolManager
void AptCharacterAnimationInst::operator delete(void* ptr, unsigned int size) {
    gpNonGCPoolManager->Deallocate(ptr, size);
}

// AptCharacterAnimationInst::operator new[]
// NON_MATCHING - GCC emits tail call, SN emits full wrapper
void* AptCharacterAnimationInst::operator new[](unsigned int size) {
    return (void*)AptNonGCAllocSaveSize(size);
}

// AptCharacterAnimationInst::operator delete[]
// NON_MATCHING - GCC emits tail call, SN emits full wrapper
void AptCharacterAnimationInst::operator delete[](void* ptr) {
    AptNonGCFreeSavedSize(ptr);
}

// ============================================================================
// AptArray.cpp.obj functions
// ============================================================================

// AptArray::get
// NON_MATCHING - SDA access, branch structure
AptValue* AptArray::get(int index) {
    if (index < 0 || index >= (int)m_length) {
        return gpUndefinedValue;
    }
    AptValue* val = m_data[index];
    if (val == 0) {
        return gpUndefinedValue;
    }
    return val;
}

// AptArray::length - MATCHING
int AptArray::length() {
    return (int)m_length;
}

// AptArray::GetAt
// NON_MATCHING - register allocation
AptValue* AptArray::GetAt(int index) const {
    return m_data[index];
}

// AptArray::ConvertAptValue - MATCHING
void AptArray::ConvertAptValue(AptValue* val) {
    // No-op stub
}

// ============================================================================
// AptCIH.cpp.obj functions
// ============================================================================

// AptCIH::GetNativeHashVirtual
// NON_MATCHING - GCC emits tail call, SN emits full wrapper
AptValue* AptCIH::GetNativeHashVirtual() {
    return (AptValue*)GetNativeHash();
}

// AptCIH::ContainsNativeHashVirtual
// NON_MATCHING - GCC emits tail call + comparison differs
int AptCIH::ContainsNativeHashVirtual() const {
    AptNativeHash* hash = ((AptCIH*)this)->GetNativeHash();
    if (hash != 0) {
        return 1;
    }
    return 0;
}

// AptCIH::objectMemberLookup
// NON_MATCHING - GCC emits tail call, SN emits full wrapper
AptValue* AptCIH::objectMemberLookup(AptValue* obj, EAStringC* name) const {
    // Ignores this, calls AptCharacterInst::objectMemberLookup on obj
    return ((AptCharacterInst*)obj)->objectMemberLookup(obj, name);
}

// AptCIH::objectMemberSet
// NON_MATCHING - GCC emits tail call, SN emits full wrapper
int AptCIH::objectMemberSet(AptValue* obj, EAStringC* name, AptValue* val) {
    return ((AptCharacterInst*)obj)->objectMemberSet(obj, name, val);
}

// AptCIH::Release
// NON_MATCHING - bitfield extraction differs
void AptCIH::Release(char* file, char* func, int line) {
    u32 flags = *(u32*)((u8*)this + 0x5C);
    u32 zombieState = (flags >> 12) & 3;
    u32 field0 = *(u32*)((u8*)this);
    u32 refCount = (field0 >> 14) & 0xFFF;
    if (zombieState == 1 && refCount == 1) {
        // Already handled
    } else {
        AptValue::Release(file, func, line);
    }
}

// AptPseudoData_t::operator delete
// NON_MATCHING - SDA access
void AptPseudoData_t::operator delete(void* ptr, unsigned int size) {
    gpNonGCPoolManager->Deallocate(ptr, size);
}

// AptPseudoCIH_t::operator delete
// NON_MATCHING - SDA access
void AptPseudoCIH_t::operator delete(void* ptr, unsigned int size) {
    gpNonGCPoolManager->Deallocate(ptr, size);
}

// AptPseudoDisplayList::operator delete
// NON_MATCHING - SDA access
void AptPseudoDisplayList::operator delete(void* ptr, unsigned int size) {
    gpNonGCPoolManager->Deallocate(ptr, size);
}

// AptAnimationPoolData::GetActionPool - MATCHING
void* AptAnimationPoolData::GetActionPool() {
    return *(void**)((u8*)this + 0x98);
}

// AptCIH::getParentCount
// NON_MATCHING - branch structure differs
int AptCIH::getParentCount() {
    AptCIH* parent = *(AptCIH**)((u8*)this + 0x48);
    int count = 0;
    if (parent == 0) return count;
    while (parent != 0) {
        count++;
        parent = *(AptCIH**)((u8*)parent + 0x48);
    }
    return count;
}

// AptCIH::isParent
// NON_MATCHING - branch structure differs
int AptCIH::isParent(AptCIH* target) {
    AptCIH* cur = *(AptCIH**)((u8*)this + 0x48);
    while (cur != 0) {
        if (target == cur) return 1;
        cur = *(AptCIH**)((u8*)cur + 0x48);
    }
    return 0;
}

// AptCIH::HasMouseEvent
// NON_MATCHING - GCC emits tail call, SN emits full wrapper
int AptCIH::HasMouseEvent() {
    return HasEvent(0x0009FC38);
}

// AptCIH::decZombieCount
// NON_MATCHING - register allocation, SDA access
void AptCIH::decZombieCount() {
    u16* pCount = (u16*)((u8*)this + 0x5C);
    u16 count = *pCount;
    count--;
    *pCount = count;
    if ((u16)count == 0) {
        AptUpdateZombieVector(false);
    }
}

// AptCIH::getHasClass - MATCHING candidate
// Reads bit 14 of flags at offset 0x5C (bit 17 in MSB-0)
int AptCIH::getHasClass() const {
    u32 flags = *(u32*)((u8*)this + 0x5C);
    return (flags >> 14) & 1;
}

// AptCIH::setHasClass
// NON_MATCHING - register allocation
void AptCIH::setHasClass(int val) {
    u32 bit = (val != 0) ? 1 : 0;
    u32* pFlags = (u32*)((u8*)this + 0x5C);
    u32 flags = *pFlags;
    flags = (flags & ~(1 << 14)) | (bit << 14);
    *pFlags = flags;
}

// AptCIH::setASChanged
// NON_MATCHING - register allocation
void AptCIH::setASChanged(int val) {
    u32 bit = (val != 0) ? 1 : 0;
    u32* pFlags = (u32*)((u8*)this + 0x5C);
    u32 flags = *pFlags;
    flags = (flags & ~(1 << 15)) | (bit << 15);
    *pFlags = flags;
}

// AptCIH::getASChanged - MATCHING candidate
int AptCIH::getASChanged() const {
    u32 flags = *(u32*)((u8*)this + 0x5C);
    return (flags >> 15) & 1;
}

// AptCIH::setZombieSate (original misspelling)
// NON_MATCHING - bitfield insertion
void AptCIH::setZombieSate(int state) {
    u32* pFlags = (u32*)((u8*)this + 0x5C);
    u32 flags = *pFlags;
    u32 masked = (u32)state & 3;
    flags = (flags & ~(3 << 12)) | (masked << 12);
    *pFlags = flags;
}

// AptCIH::getZombieState - MATCHING candidate
int AptCIH::getZombieState() const {
    u32 flags = *(u32*)((u8*)this + 0x5C);
    return (flags >> 12) & 3;
}

// AptCIH::incZombieCount
// NON_MATCHING - register allocation
void AptCIH::incZombieCount() {
    u16* pCount = (u16*)((u8*)this + 0x5C);
    *pCount = *pCount + 1;
}

// AptCIH::getZombieCount - MATCHING
u32 AptCIH::getZombieCount() {
    return *(u16*)((u8*)this + 0x5C);
}

// AptCIH::getSpriteInst - MATCHING
void* AptCIH::getSpriteInst() const {
    return *(void**)((u8*)this + 0x4C);
}

// AptCIH::getSpriteInstBase - MATCHING
void* AptCIH::getSpriteInstBase() const {
    return *(void**)((u8*)this + 0x4C);
}

// AptCIH::getTextInst - MATCHING
void* AptCIH::getTextInst() const {
    return *(void**)((u8*)this + 0x4C);
}

// AptCIH::getStaticTextInst - MATCHING
void* AptCIH::getStaticTextInst() const {
    return *(void**)((u8*)this + 0x4C);
}

// AptCIH::getMorphInst - MATCHING
void* AptCIH::getMorphInst() const {
    return *(void**)((u8*)this + 0x4C);
}

// AptCIH::getButtonInst - MATCHING
void* AptCIH::getButtonInst() const {
    return *(void**)((u8*)this + 0x4C);
}

// AptCIH::getAnimationInst - MATCHING
void* AptCIH::getAnimationInst() const {
    return *(void**)((u8*)this + 0x4C);
}

// AptCIH::getShapeInst - MATCHING
void* AptCIH::getShapeInst() const {
    return *(void**)((u8*)this + 0x4C);
}

// AptCIH::getCharacterInst - MATCHING
void* AptCIH::getCharacterInst() const {
    return *(void**)((u8*)this + 0x4C);
}

// AptCIH::IsInCtor - MATCHING candidate
int AptCIH::IsInCtor() const {
    u32 flags = *(u32*)((u8*)this + 0x5C);
    return (flags >> 10) & 1;
}

// AptCIH::SetInCtor
// NON_MATCHING - rlwimi encoding
void AptCIH::SetInCtor(unsigned int val) {
    u32* pFlags = (u32*)((u8*)this + 0x5C);
    u32 flags = *pFlags;
    flags = (flags & ~(1 << 10)) | ((val & 1) << 10);
    *pFlags = flags;
}

// ============================================================================
// AptDate.cpp.obj functions
// ============================================================================

// AptDate::dateGetNumDaysInYear
// NON_MATCHING - GCC emits tail call, SN emits full wrapper
int AptDate::dateGetNumDaysInYear(int year) {
    if (int(year)) {
        return 366;
    }
    return 365;
}

// AptDate::sMethod_UTC - returns gpUndefinedValue (stub)
// NON_MATCHING - SDA access
AptValue* AptDate::sMethod_UTC(AptValue* thisObj, int argc) {
    return gpUndefinedValue;
}

// ============================================================================
// AptLoad.cpp.obj functions
// ============================================================================

// AptSharedPtrIncRef(AptFile*) - MATCHING candidate
void AptSharedPtrIncRef(AptFile* ptr) {
    ptr->m_refCount++;
}

// AptSharedPtrDecRef(AptFile*) - MATCHING candidate
void AptSharedPtrDecRef(AptFile* ptr) {
    ptr->m_refCount--;
}

// AptFile::GetMainCharacter - MATCHING
void* AptFile::GetMainCharacter() const {
    return m_mainCharacter;
}

// AptSharedPtrIncRef(AptLinkerThingy*) - MATCHING candidate
void AptSharedPtrIncRef(AptLinkerThingy* ptr) {
    ptr->m_refCount++;
}

// AptSharedPtrDecRef(AptLinkerThingy*) - MATCHING candidate
void AptSharedPtrDecRef(AptLinkerThingy* ptr) {
    ptr->m_refCount--;
}

// AptFile::operator delete
// NON_MATCHING - SDA access
void AptFile::operator delete(void* ptr, unsigned int size) {
    gpNonGCPoolManager->Deallocate(ptr, size);
}

// ============================================================================
// AptSound.cpp.obj functions
// ============================================================================

// AptSound::sMethod_stop - returns gpUndefinedValue (stub)
// NON_MATCHING - SDA access
AptValue* AptSound::sMethod_stop(AptValue* thisObj, int argc) {
    return gpUndefinedValue;
}

// ============================================================================
// AptTextFormat.cpp.obj functions
// ============================================================================

// AptTextFormat::operator new
// NON_MATCHING - SDA access to gpGCPoolManager
void* AptTextFormat::operator new(unsigned int size) {
    return gpGCPoolManager->AllocateAptValueGC(size);
}

// AptTextFormat::operator delete
// NON_MATCHING - SDA access to gpGCPoolManager
void AptTextFormat::operator delete(void* ptr, unsigned int size) {
    gpGCPoolManager->DeallocateAptValueGC((AptValueGC*)ptr, size);
}

// AptTextFormat::operator new[] - MATCHING
void* AptTextFormat::operator new[](unsigned int size) {
    return (void*)0;
}

// AptTextFormat::operator delete[] - MATCHING
void AptTextFormat::operator delete[](void* ptr) {
    // No-op
}

// ============================================================================
// AptObject.cpp.obj functions
// ============================================================================

// AptObject::objectMemberLookup
// NON_MATCHING - SDA access, string comparison pattern
AptValue* AptObject::objectMemberLookup(AptValue* obj, EAStringC* name) const {
    // Compare name to "__proto__" (at address 0x8041524C in original)
    if (strcmp((const char*)((u8*)name->m_pData + 8), "__proto__") == 0) {
        return gpObjRegistrationFunc;
    }
    return 0;
}

// AptObject::RegisterReferences
// NON_MATCHING - GCC emits tail call, SN emits full wrapper
void AptObject::RegisterReferences() const {
    ((AptValueWithHash*)this)->RegisterReferences();
}

// AptObject::DestroyGCPointers
// NON_MATCHING - GCC emits tail call, SN emits full wrapper
void AptObject::DestroyGCPointers() {
    ((AptValueWithHash*)this)->DestroyGCPointers();
}

// AptObject::getHasClass
// NON_MATCHING - bitfield extraction may differ (bit 23 in MSB-0 = bit 8)
int AptObject::getHasClass() const {
    return (m_objectFlags >> 23) & 1;
}

// AptObject::setHasClass
// NON_MATCHING - register allocation, rlwimi encoding
void AptObject::setHasClass(int val) {
    u32 bit = (val != 0) ? 1 : 0;
    m_objectFlags = (m_objectFlags & ~(1 << 23)) | (bit << 23);
}

// AptPrototype::GetSuperConstructor - MATCHING candidate
AptValue* AptPrototype::GetSuperConstructor() const {
    return *(AptValue**)((u8*)this + 0x20);
}

// AptObject::setInMainInst
// NON_MATCHING - register allocation, rlwimi encoding
void AptObject::setInMainInst(int val) {
    u32 bit = (val != 0) ? 1 : 0;
    m_objectFlags = (m_objectFlags & ~(1 << 22)) | (bit << 22);
}

// AptObject::getInMainInst - MATCHING candidate
int AptObject::getInMainInst() const {
    return (m_objectFlags >> 22) & 1;
}

// AptObject::Set
// NON_MATCHING - GCC emits tail call, SN emits full wrapper
void AptObject::Set(EAStringC* key, AptValue* val) {
    // Calls AptNativeHash::Set on embedded hash at this+0x0C
    AptNativeHash* hash = (AptNativeHash*)((u8*)this + 0x0C);
    hash->Set(key, val);
}

// AptObject::Lookup
// NON_MATCHING - GCC emits tail call, SN emits full wrapper
AptValue* AptObject::Lookup(EAStringC* key) const {
    // Calls AptNativeHash::Lookup on embedded hash at this+0x0C
    AptNativeHash* hash = (AptNativeHash*)((u8*)this + 0x0C);
    return hash->Lookup(key);
}
