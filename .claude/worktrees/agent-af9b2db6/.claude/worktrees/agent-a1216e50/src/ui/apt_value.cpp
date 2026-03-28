// AptValue.cpp - APT UI engine value/variant type
// Source: libaptz.a(AptValue.cpp.obj)
// 101 small functions (<=64 bytes) decompiled from the Sims 2 GameCube ELF
//
// Functions compiled with SN Systems ProDG differ from devkitPPC/GCC in:
// - Register allocation (SN uses r0 as scratch, GCC uses r9/r10)
// - Boolean normalization (SN uses cmpwi/beq/li pattern, GCC shifts directly)
// - Compare types (SN uses cmpwi signed, GCC uses cmplwi unsigned)
// - Bitfield insertion (SN uses rlwimi, GCC uses clear+shift+or)
//
// Functions marked MATCHING produce byte-identical output with devkitPPC -O2.
// Functions marked NON_MATCHING are functionally correct but differ in codegen.

#include "ui/apt_value.h"

// ============================================================================
// External function declarations (called by functions in this file)
// ============================================================================
extern "C" {
    void AptNativeHash_RegisterReferences(void* hash, AptValue* val);
    void AptNativeHash_DestroyGCPointers(void* hash);
    AptValue* AptNativeHash_Lookup(void* hash, EAStringC* key);
    void AptNativeHash_SetIfNotExists(void* hash, EAStringC* key, AptValue* val);
}

// ============================================================================
// _constructorObject (0x802b0e44, 8 bytes) NON_MATCHING
// Original uses SDA r13-relative access (lwz r3,-22936(r13)); GCC uses lis+lwz.
// Returns gpObjectPrototype global
// ============================================================================
AptValue* _constructorObject(AptValue* thisObj, int argc) {
    return gpObjectPrototype;
}

// ============================================================================
// AptValue bitfield getters - all MATCHING (12 bytes each)
// Pattern: lwz r3,0(r3) / rlwinm r3,r3,SH,MB,ME / blr
// ============================================================================

// 0x802b47dc (12 bytes) MATCHING
AptVirtualFunctionTable_Indices AptValue::getVtblIndex() const {
    return (AptVirtualFunctionTable_Indices)(m_flags & 0x7F);
}

// 0x802b47a4 (12 bytes) MATCHING
bool AptValue::GetMaxRefCountHit() const {
    return (m_flags >> 7) & 1;
}

// 0x802b47d0 (12 bytes) MATCHING
u32 AptValue::getRefCount() const {
    return (m_flags >> 14) & 0xFFF;
}

// 0x802b47e8 (12 bytes) MATCHING
bool AptValue::getGCMark() const {
    return (m_flags >> 30) & 1;
}

// 0x802b47f4 (12 bytes) MATCHING
u32 AptValue::getGCRoot() const {
    return (m_flags >> 8) & 0x3F;
}

// 0x802b4800 (12 bytes) MATCHING
bool AptValue::getIsDefined() const {
    return (m_flags >> 27) & 1;
}

// 0x802b48f4 (12 bytes) MATCHING
bool AptValue::IsReleaseAtEnd() const {
    return (m_flags >> 29) & 1;
}

// 0x802b4294 (12 bytes) MATCHING
bool AptValue::GetAllowDelayedDeletion() const {
    return (m_flags >> 26) & 1;
}

// ============================================================================
// AptValue bitfield setters - NON_MATCHING
// SN Systems uses r0 + rlwimi; GCC uses r9 + clear/shift/or
// ============================================================================

// 0x802b4834 (16 bytes) NON_MATCHING - GCC uses different register and rlwimi encoding
void AptValue::setVtblIndex(AptVirtualFunctionTable_Indices idx) {
    m_flags = (m_flags & ~0x7F) | ((u32)idx & 0x7F);
}

// 0x802b4884 (16 bytes) NON_MATCHING - GCC register allocation differs
void AptValue::setGCRoot(u32 val) {
    m_flags = (m_flags & ~0x3F00) | ((val & 0x3F) << 8);
}

// 0x802b4844 (32 bytes) NON_MATCHING - SN uses cmpwi/beq/li bool pattern
void AptValue::setIsDefined(bool val) {
    u32 v = val ? 1 : 0;
    m_flags = (m_flags & ~0x08000000) | (v << 27);
}

// 0x802b480c (40 bytes) NON_MATCHING - SN loads m_flags after branch
void AptValue::setRefCount(u32 val) {
    if (val > 4095) {
        m_flags |= 0x80;
        val = 4095;
    }
    m_flags = (m_flags & ~0x03FFC000) | ((val & 0xFFF) << 14);
}

// 0x802b4864 (32 bytes) NON_MATCHING - SN uses cmpwi/beq/li bool pattern
void AptValue::setGCMark(bool val) {
    u32 v = val ? 1 : 0;
    m_flags = (m_flags & ~0x40000000) | (v << 30);
}

// 0x802b4274 (32 bytes) NON_MATCHING - SN uses cmpwi/beq/li bool pattern
void AptValue::SetAllowDelayedDeletion(bool val) {
    u32 v = val ? 1 : 0;
    m_flags = (m_flags & ~0x04000000) | (v << 26);
}

// 0x802b47b0 (32 bytes) NON_MATCHING - SN uses cmpwi/beq/li bool pattern
void AptValue::SetMaxRefCountHit(bool val) {
    u32 v = val ? 1 : 0;
    m_flags = (m_flags & ~0x80) | (v << 7);
}

// 0x802b48d4 (16 bytes) NON_MATCHING - SN uses r0, GCC uses r9
void AptValue::SetReleaseAtEnd() {
    m_flags |= 0x20000000;
}

// 0x802b48e4 (16 bytes) NON_MATCHING - SN uses r0, GCC uses r9
void AptValue::ClearReleaseAtEnd() {
    m_flags &= ~0x20000000;
}

// 0x802b4894 (32 bytes) NON_MATCHING - SN uses rlwimi, GCC clear+shift+or
void AptValue::incGCRoot() {
    u32 root = (m_flags >> 8) & 0x3F;
    if (root > 62) return;
    root++;
    m_flags = (m_flags & ~0x3F00) | ((root & 0x3F) << 8);
}

// 0x802b48b4 (32 bytes) NON_MATCHING - SN uses rlwimi, GCC clear+shift+or
void AptValue::decGCRoot() {
    if ((m_flags & 0x3F00) == 0) return;
    u32 root = (m_flags >> 8) & 0x3F;
    root--;
    m_flags = (m_flags & ~0x3F00) | ((root & 0x3F) << 8);
}

// ============================================================================
// AptValue::isUndefined (0x802b49f0, 16 bytes) MATCHING
// ============================================================================
bool AptValue::isUndefined() const {
    return !((m_flags >> 27) & 1);
}

// ============================================================================
// AptValue c_* accessor functions - all MATCHING (4 bytes each, just blr)
// These are type-specific cast accessors that return this (the implicit
// return of the 'this' pointer in r3 - compiler generates only 'blr').
// ============================================================================

// 0x802b4900 (4 bytes) MATCHING
AptValue* AptValue::c_lookup() const {
    return (AptValue*)this;
}

// 0x802b4904 (4 bytes) MATCHING
AptValue* AptValue::c_integer() const {
    return (AptValue*)this;
}

// 0x802b4908 (4 bytes) MATCHING
AptValue* AptValue::c_register() const {
    return (AptValue*)this;
}

// 0x802b490c (4 bytes) MATCHING
AptValue* AptValue::c_float() const {
    return (AptValue*)this;
}

// 0x802b4928 (4 bytes) MATCHING
AptValue* AptValue::c_boolean() const {
    return (AptValue*)this;
}

// 0x802b492c (4 bytes) MATCHING
AptValue* AptValue::c_scriptfunction() const {
    return (AptValue*)this;
}

// 0x802b4930 (4 bytes) MATCHING
AptValue* AptValue::c_nativefunction() const {
    return (AptValue*)this;
}

// 0x802b4934 (4 bytes) MATCHING
AptValue* AptValue::c_cih(bool) const {
    return (AptValue*)this;
}

// 0x802b4938 (4 bytes) MATCHING
AptValue* AptValue::c_array() const {
    return (AptValue*)this;
}

// 0x802b493c (4 bytes) MATCHING
AptValue* AptValue::c_sound() const {
    return (AptValue*)this;
}

// 0x802b4940 (4 bytes) MATCHING
AptValue* AptValue::c_key() const {
    return (AptValue*)this;
}

// 0x802b4944 (4 bytes) MATCHING
AptValue* AptValue::c_global() const {
    return (AptValue*)this;
}

// 0x802b4948 (4 bytes) MATCHING
AptValue* AptValue::c_math() const {
    return (AptValue*)this;
}

// 0x802b494c (4 bytes) MATCHING
AptValue* AptValue::c_scriptcolour() const {
    return (AptValue*)this;
}

// 0x802b4950 (4 bytes) MATCHING
AptValue* AptValue::c_object() const {
    return (AptValue*)this;
}

// 0x802b4954 (4 bytes) MATCHING
AptValue* AptValue::c_prototype() const {
    return (AptValue*)this;
}

// 0x802b4958 (4 bytes) MATCHING
AptValue* AptValue::c_date() const {
    return (AptValue*)this;
}

// 0x802b495c (4 bytes) MATCHING
AptValue* AptValue::c_textformat() const {
    return (AptValue*)this;
}

// 0x802b4960 (4 bytes) MATCHING
AptValue* AptValue::c_movieClip() const {
    return (AptValue*)this;
}

// 0x802b4964 (4 bytes) MATCHING
AptValue* AptValue::c_xmlnode() const {
    return (AptValue*)this;
}

// 0x802b4968 (4 bytes) MATCHING
AptValue* AptValue::c_xml() const {
    return (AptValue*)this;
}

// 0x802b496c (4 bytes) MATCHING
AptValue* AptValue::c_xmlattributes() const {
    return (AptValue*)this;
}

// 0x802b4970 (4 bytes) MATCHING
AptValue* AptValue::c_loadvars() const {
    return (AptValue*)this;
}

// 0x802b4974 (4 bytes) MATCHING
AptValue* AptValue::c_stage() const {
    return (AptValue*)this;
}

// ============================================================================
// AptValue::c_string (0x802b4910, 24 bytes) NON_MATCHING
// SN uses r0 + cmpwi (signed), GCC uses r9 + cmplwi (unsigned)
// ============================================================================
AptValue* AptValue::c_string() const {
    if ((m_flags & 0x7F) == APT_VFT_STRING) {
        return (AptValue*)this;
    }
    return m_stringData;
}

// ============================================================================
// AptValue is* type check functions - NON_MATCHING
// SN generates: li r9,0 / clrlwi r0,r3,25 / cmpwi r0,N / bne / rlwinm r9,...
// GCC generates different register allocation and comparison sequences.
// All are functionally correct.
// ============================================================================

// 0x802b4978 (24 bytes) NON_MATCHING - GCC uses cntlzw instead of subfic/adde
bool AptValue::isXmlNode() const {
    return (m_flags & 0x7F) == APT_VFT_XMLNODE;
}

// 0x802b4990 (24 bytes) NON_MATCHING
bool AptValue::isXml() const {
    return (m_flags & 0x7F) == APT_VFT_XML;
}

// 0x802b49a8 (24 bytes) NON_MATCHING
bool AptValue::isXmlAttributes() const {
    return (m_flags & 0x7F) == APT_VFT_XMLATTRIBUTES;
}

// 0x802b49c0 (24 bytes) NON_MATCHING
bool AptValue::isLoadVars() const {
    return (m_flags & 0x7F) == APT_VFT_LOADVARS;
}

// 0x802b49d8 (24 bytes) NON_MATCHING
bool AptValue::isNone() const {
    return (m_flags & 0x7F) == APT_VFT_NONE;
}

// 0x802b4a00 (32 bytes) NON_MATCHING - different register and branch pattern
bool AptValue::isLookup() const {
    u32 vft = m_flags & 0x7F;
    if (vft != APT_VFT_LOOKUP) return false;
    return (m_flags >> 27) & 1;
}

// 0x802b4a20 (48 bytes) NON_MATCHING
bool AptValue::isString() const {
    u32 vft = m_flags & 0x7F;
    if (vft != APT_VFT_STRING && vft != APT_VFT_STRING2) return false;
    if (!(m_flags & 0x08000000)) return false;
    return true;
}

// 0x802b4a50 (32 bytes) NON_MATCHING
bool AptValue::isBoolean() const {
    u32 vft = m_flags & 0x7F;
    if (vft != APT_VFT_BOOLEAN) return false;
    return (m_flags >> 27) & 1;
}

// 0x802b4a70 (32 bytes) NON_MATCHING
bool AptValue::isInteger() const {
    u32 vft = m_flags & 0x7F;
    if (vft != APT_VFT_INTEGER) return false;
    return (m_flags >> 27) & 1;
}

// 0x802b4a90 (32 bytes) NON_MATCHING
bool AptValue::isRegister() const {
    u32 vft = m_flags & 0x7F;
    if (vft != APT_VFT_REGISTER) return false;
    return (m_flags >> 27) & 1;
}

// 0x802b4ab0 (32 bytes) NON_MATCHING
bool AptValue::isFloat() const {
    u32 vft = m_flags & 0x7F;
    if (vft != APT_VFT_FLOAT) return false;
    return (m_flags >> 27) & 1;
}

// 0x802b4ad0 (32 bytes) NON_MATCHING
bool AptValue::isNativeFunction() const {
    u32 vft = m_flags & 0x7F;
    if (vft != APT_VFT_NATIVEFUNCTION) return false;
    return (m_flags >> 27) & 1;
}

// 0x802b4af0 (36 bytes) NON_MATCHING
bool AptValue::isScriptFunction() const {
    u32 vft = m_flags & 0x7F;
    if (vft - APT_VFT_SCRIPTFUNCTION1 > 2) return false;
    return (m_flags >> 27) & 1;
}

// 0x802b4b14 (32 bytes) NON_MATCHING
bool AptValue::isExtern() const {
    u32 vft = m_flags & 0x7F;
    if (vft != APT_VFT_EXTERN) return false;
    return (m_flags >> 27) & 1;
}

// 0x802b4b34 (32 bytes) NON_MATCHING
bool AptValue::isFrameStack() const {
    u32 vft = m_flags & 0x7F;
    if (vft != APT_VFT_FRAMESTACK) return false;
    return (m_flags >> 27) & 1;
}

// 0x802b4b54 (32 bytes) NON_MATCHING
bool AptValue::isArray() const {
    u32 vft = m_flags & 0x7F;
    if (vft != APT_VFT_ARRAY) return false;
    return (m_flags >> 27) & 1;
}

// 0x802b4b74 (32 bytes) NON_MATCHING
bool AptValue::isSound() const {
    u32 vft = m_flags & 0x7F;
    if (vft != APT_VFT_SOUND) return false;
    return (m_flags >> 27) & 1;
}

// 0x802b4b94 (32 bytes) NON_MATCHING
bool AptValue::isKey() const {
    u32 vft = m_flags & 0x7F;
    if (vft != APT_VFT_KEY) return false;
    return (m_flags >> 27) & 1;
}

// 0x802b4bb4 (32 bytes) NON_MATCHING
bool AptValue::isMath() const {
    u32 vft = m_flags & 0x7F;
    if (vft != APT_VFT_MATH) return false;
    return (m_flags >> 27) & 1;
}

// 0x802b4bd4 (32 bytes) NON_MATCHING
bool AptValue::isScriptColour() const {
    u32 vft = m_flags & 0x7F;
    if (vft != APT_VFT_SCRIPTCOLOUR) return false;
    return (m_flags >> 27) & 1;
}

// 0x802b4bf4 (52 bytes) NON_MATCHING
bool AptValue::isCIH(bool includeUndefined) const {
    u32 vft = m_flags & 0x7F;
    if ((u32)(vft - APT_VFT_CIH_FIRST) > 7) return false;
    if (includeUndefined) return true;
    if (!(m_flags & 0x08000000)) return false;
    return true;
}

// 0x802b4c28 (32 bytes) NON_MATCHING
bool AptValue::isObject() const {
    u32 vft = m_flags & 0x7F;
    if (vft != APT_VFT_OBJECT) return false;
    return (m_flags >> 27) & 1;
}

// 0x802b4c48 (32 bytes) NON_MATCHING
bool AptValue::isPrototype() const {
    u32 vft = m_flags & 0x7F;
    if (vft != APT_VFT_PROTOTYPE) return false;
    return (m_flags >> 27) & 1;
}

// 0x802b4c68 (32 bytes) NON_MATCHING
bool AptValue::isDate() const {
    u32 vft = m_flags & 0x7F;
    if (vft != APT_VFT_DATE) return false;
    return (m_flags >> 27) & 1;
}

// 0x802b4c88 (32 bytes) NON_MATCHING
bool AptValue::isTextFormat() const {
    u32 vft = m_flags & 0x7F;
    if (vft != APT_VFT_TEXTFORMAT) return false;
    return (m_flags >> 27) & 1;
}

// 0x802b4ca8 (32 bytes) NON_MATCHING
bool AptValue::isMovieClip() const {
    u32 vft = m_flags & 0x7F;
    if (vft != APT_VFT_MOVIECLIP) return false;
    return (m_flags >> 27) & 1;
}

// 0x802b4cc8 (32 bytes) NON_MATCHING
bool AptValue::isStage() const {
    u32 vft = m_flags & 0x7F;
    if (vft != APT_VFT_STAGE) return false;
    return (m_flags >> 27) & 1;
}

// ============================================================================
// AptValue base class virtual function implementations
// ============================================================================

// 0x802b4248 (8 bytes) MATCHING - returns NULL
AptValue* AptValue::GetNativeHashVirtual() {
    return (AptValue*)0;
}

// 0x802b4250 (8 bytes) MATCHING - returns false
bool AptValue::ContainsNativeHashVirtual() const {
    return false;
}

// 0x802b4258 (8 bytes) MATCHING - returns false
bool AptValue::getHasClass() const {
    return false;
}

// 0x802b4260 (4 bytes) MATCHING - no-op
void AptValue::setHasClass(int val) {
}

// 0x802b4264 (8 bytes) MATCHING - returns NULL
AptValue* AptValue::objectMemberLookup(AptValue* obj, EAStringC* name) const {
    return (AptValue*)0;
}

// 0x802b426c (8 bytes) MATCHING - returns 0
int AptValue::objectMemberSet(AptValue* obj, EAStringC* name, AptValue* val) {
    return 0;
}

// 0x802b42e0 (4 bytes) MATCHING - no-op
void AptValue::PreDestroy() {
}

// 0x802b42e4 (4 bytes) MATCHING - no-op
void AptValue::DestroyGCPointers() {
}

// ============================================================================
// AptValueGC / AptValueNoGC
// ============================================================================

// 0x802b42e8 (8 bytes) MATCHING
bool AptValueGC::IsGarbageCollected() const {
    return true;
}

// 0x802b42f0 (8 bytes) MATCHING
bool AptValueNoGC::IsGarbageCollected() const {
    return false;
}

// 0x802b42f8 (4 bytes) MATCHING
void AptValueNoGC::RegisterReferences() const {
}

// ============================================================================
// AptValueWithHash
// ============================================================================

// 0x802b4170 (8 bytes) MATCHING - returns this + 12
AptValue* AptValueWithHash::GetNativeHashVirtual() {
    return (AptValue*)((char*)this + 12);
}

// 0x802b4178 (8 bytes) MATCHING - returns true
bool AptValueWithHash::ContainsNativeHashVirtual() const {
    return true;
}

// 0x802b4180 (40 bytes) NON_MATCHING - calls AptNativeHash::RegisterReferences
void AptValueWithHash::RegisterReferences() const {
    AptNativeHash_RegisterReferences((void*)((char*)this + 12), (AptValue*)this);
}

// 0x802b41a8 (36 bytes) NON_MATCHING - calls AptNativeHash::DestroyGCPointers
void AptValueWithHash::DestroyGCPointers() {
    AptNativeHash_DestroyGCPointers((void*)((char*)this + 12));
}

// 0x802b43a4 (36 bytes) NON_MATCHING - calls AptNativeHash::Lookup
AptValue* AptValueWithHash::Lookup(EAStringC* key) const {
    return AptNativeHash_Lookup((void*)((char*)this + 12), key);
}

// 0x802b43c8 (36 bytes) NON_MATCHING - calls AptNativeHash::SetIfNotExists
void AptValueWithHash::Set(EAStringC* key, AptValue* val) {
    AptNativeHash_SetIfNotExists((void*)((char*)this + 12), key, val);
}

// ============================================================================
// AptExtern - no-op AddRef/Release
// ============================================================================

// 0x802b4534 (4 bytes) MATCHING
void AptExtern::AddRef(char* file, char* func, int line) {
}

// 0x802b4538 (4 bytes) MATCHING
void AptExtern::Release(char* file, char* func, int line) {
}

// ============================================================================
// AptNone - no-op AddRef/Release
// ============================================================================

// 0x802b4454 (4 bytes) MATCHING
void AptNone::AddRef(char* file, char* func, int line) {
}

// 0x802b4458 (4 bytes) MATCHING
void AptNone::Release(char* file, char* func, int line) {
}

// ============================================================================
// AptValue::DeleteThis (0x802b42a0, 64 bytes) NON_MATCHING
// Dispatches through custom vtable descriptor to delete the object.
// SN generates different null-check and register usage.
// ============================================================================
void AptValue::DeleteThis() {
    if (this == 0) return;
    AptValueVTableDesc* desc = m_vtableDesc;
    s16 offset = *(s16*)((char*)desc + 0x78);
    void (*dtor)(void*, int) = *(void (**)(void*, int))((char*)desc + 0x7C);
    dtor((char*)this + offset, 3);
}

// ============================================================================
// AptValue::~AptValue (0x802b4770, 52 bytes) NON_MATCHING
// Sets vtable descriptor to AptValue base, optionally calls operator delete.
// SN destructor calling convention: r4 bit 0 = should delete memory.
// ============================================================================
AptValue::~AptValue() {
    // In the original, this sets m_vtableDesc to the AptValue vtable
    // and conditionally calls operator delete based on r4 & 1.
    // GCC destructor ABI is fundamentally different from SN Systems.
}

// ============================================================================
// EAStringC functions (from AptValue.cpp.obj)
// ============================================================================

// 0x802b4ce8 (28 bytes) NON_MATCHING - SN uses subfic/adde equality idiom, GCC uses cntlzw/srwi
// Compares m_pData pointer to s_EmptyInternalData address
bool EAStringC::IsEmpty() const {
    return m_pData == &EAStringC_s_EmptyInternalData;
}

// 0x802b4d3c (12 bytes) MATCHING
// Returns pointer to string data (internal data + 8)
const char* EAStringC::c_str() const {
    return (const char*)((char*)m_pData + 8);
}

// 0x802b4dd0 (12 bytes) MATCHING
// Same as c_str but as implicit conversion operator
EAStringC::operator char*() const {
    return (char*)((char*)m_pData + 8);
}

// 0x802b4d48 (32 bytes) NON_MATCHING - SN register allocation differs
// Initializes with s_EmptyInternalData and increments refcount
EAStringC::EAStringC() {
    m_pData = &EAStringC_s_EmptyInternalData;
    m_pData->m_refCount++;
}

// ============================================================================
// AptValueVector::PushValue (0x802b4d04, 56 bytes) NON_MATCHING
// Pushes value or clears release-at-end flag if vector is full
// ============================================================================
void AptValueVector::PushValue(AptValue* val) {
    if (m_size >= m_capacity) {
        val->m_flags &= ~0x20000000;
        return;
    }
    m_data[m_size] = val;
    m_size++;
}
