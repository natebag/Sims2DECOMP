/**
 * e_fontdata.cpp - Font data classes for The Sims 2 (GameCube)
 *
 * Decompiled from engine_ngc_release_dvd.lib(e_fontdata.obj)
 * Original source: c:\BuildAgent\cm3-build22-NGC\CMBuild\
 *
 * Contains EFontCharacter, EFontPage, EFontSize, EFontData classes
 * and their associated TArray template instantiations.
 *
 * NOTE: Original was compiled with SN Systems ProDG for GameCube.
 * Many functions use the SN Systems destructor ABI (r4 flags, single
 * destructor entry point) which differs from GCC's D0/D1/D2 pattern.
 * Functions marked NON_MATCHING note the specific codegen difference.
 */

#include "render/e_fontdata.h"

// Placement new support
inline void* operator new(u32 size, void* ptr) { return ptr; }

// External functions (from base_ngc_release_dvd.lib)
extern void* __builtin_new(u32 size);
extern void __builtin_delete(void* ptr);

// EStorable::CreateCopy (base implementation at 0x802D1388)
extern void* EStorable__CreateCopy(const void* obj);

// EResource::DelRef (at 0x80311F70)
class EResource {
public:
    void DelRef(void);
};

// ============================================================================
// Stream operators for EFontCharacter
// ============================================================================

// 0x803634C0 | 0x20 bytes
// Calls operator<<(EStream&, EStorable*)
EStream& operator<<(EStream& stream, EFontCharacter* obj) {
    return operator<<(stream, (EStorable*)obj);
}

// 0x803634E0 | 0x40 bytes
// Calls operator>>(EStream&, EStorable*&)
EStream& operator>>(EStream& stream, EFontCharacter*& obj) {
    EStorable* tmp;
    operator>>(stream, tmp);
    obj = (EFontCharacter*)tmp;
    return stream;
}

// 0x80363520 | 0x40 bytes
// Calls operator>>(EFile&, EStorable*&)
EFile& operator>>(EFile& file, EFontCharacter*& obj) {
    EStorable* tmp;
    operator>>(file, tmp);
    obj = (EFontCharacter*)tmp;
    return file;
}

// ============================================================================
// Stream operators for EFontPage
// ============================================================================

// 0x803637A4 | 0x20 bytes
EStream& operator<<(EStream& stream, EFontPage* obj) {
    return operator<<(stream, (EStorable*)obj);
}

// 0x803637C4 | 0x40 bytes
EStream& operator>>(EStream& stream, EFontPage*& obj) {
    EStorable* tmp;
    operator>>(stream, tmp);
    obj = (EFontPage*)tmp;
    return stream;
}

// 0x80363804 | 0x40 bytes
EFile& operator>>(EFile& file, EFontPage*& obj) {
    EStorable* tmp;
    operator>>(file, tmp);
    obj = (EFontPage*)tmp;
    return file;
}

// ============================================================================
// Stream operators for EFontSize
// ============================================================================

// 0x80363A88 | 0x20 bytes
EStream& operator<<(EStream& stream, EFontSize* obj) {
    return operator<<(stream, (EStorable*)obj);
}

// 0x80363AA8 | 0x40 bytes
EStream& operator>>(EStream& stream, EFontSize*& obj) {
    EStorable* tmp;
    operator>>(stream, tmp);
    obj = (EFontSize*)tmp;
    return stream;
}

// 0x80363AE8 | 0x40 bytes
EFile& operator>>(EFile& file, EFontSize*& obj) {
    EStorable* tmp;
    operator>>(file, tmp);
    obj = (EFontSize*)tmp;
    return file;
}

// ============================================================================
// Stream operators for EFontData
// ============================================================================

// 0x80363F84 | 0x20 bytes
EStream& operator<<(EStream& stream, EFontData* obj) {
    return operator<<(stream, (EStorable*)obj);
}

// 0x80363FA4 | 0x40 bytes
EStream& operator>>(EStream& stream, EFontData*& obj) {
    EStorable* tmp;
    operator>>(stream, tmp);
    obj = (EFontData*)tmp;
    return stream;
}

// 0x80363FE4 | 0x40 bytes
EFile& operator>>(EFile& file, EFontData*& obj) {
    EStorable* tmp;
    operator>>(file, tmp);
    obj = (EFontData*)tmp;
    return file;
}

// ============================================================================
// EFontPage constructor
// ============================================================================

// 0x80363844 | 0x20 bytes | NON_MATCHING
// SN Systems: lis r9,vtable_hi; mr r11,r3; li r0,0; addi r9,vtable_lo;
//             stw r9,0(r11); stw r0,8(r11); stw r0,4(r11)
// GCC may reorder stores or use r3 directly instead of r11
EFontPage::EFontPage(void) {
    // vtable set by compiler
    m_field_04 = 0;
    m_pShader = 0;
}

// ============================================================================
// EFontPage::DeallocateShader
// ============================================================================

// 0x80363A48 | 0x40 bytes
// Checks m_pShader, calls EResource::DelRef if non-null, then zeroes it
void EFontPage::DeallocateShader(void) {
    if (m_pShader != 0) {
        ((EResource*)m_pShader)->DelRef();
        m_pShader = 0;
    }
}

// ============================================================================
// EFontSize::DeallocatePages
// ============================================================================

// 0x80363CD8 | 0x24 bytes
// Calls TArray<EFontPage*>::SafeDeleteAll on m_pages (at this+0x20)
void EFontSize::DeallocatePages(void) {
    m_pages.SafeDeleteAll();
}

// ============================================================================
// EFontCharacter factory functions
// ============================================================================

// 0x80364684 | 0x34 bytes | NON_MATCHING
// SN Systems: allocates 0x10 bytes, sets vtable directly using mr r11,r3
// GCC may differ in register usage
EFontCharacter* EFontCharacter::New(void) {
    EFontCharacter* obj = (EFontCharacter*)__builtin_new(0x10);
    // vtable set inline by SN compiler
    return obj;
}

// 0x803646B8 | 0x10 bytes | NON_MATCHING
// SN Systems: lis r9,vtable_hi; addi r9,vtable_lo; stw r9,0(r3); blr
// Just sets the vtable pointer on an already-allocated object
void EFontCharacter::Construct(EFontCharacter* obj) {
    // vtable assignment (placement construction)
    (void)obj;
}

// 0x803646C8 | 0x10 bytes | NON_MATCHING
// SN Systems: Sets vtable to EStorable base vtable
void EFontCharacter::Destruct(EFontCharacter* obj) {
    // Sets vtable to base class (trivial destructor)
    (void)obj;
}

// ============================================================================
// EFontCharacter virtual functions
// ============================================================================

// 0x803646D8 | 0x40 bytes
// SafeDelete: if (this != NULL) { call destructor via vtable with delete flag }
void EFontCharacter::SafeDelete(void) {
    // Implemented via vtable dispatch in assembly
    // The pattern reads vtable[0x30] offset and vtable[0x34] func ptr
    // then calls destructor with r4=3 (delete flag)
    delete this;
}

// 0x80364718 | 0x0C bytes
// Returns pointer to static ETypeInfo for EFontCharacter
const ETypeInfo* EFontCharacter::GetTypeInfo(void) const {
    return gpTypeInfo_EFontCharacter;
}

// 0x80364724 | 0x0C bytes
// Returns type name string from ETypeInfo
const char* EFontCharacter::GetTypeName(void) const {
    return gpTypeInfo_EFontCharacter->m_pName;
}

// 0x80364730 | 0x0C bytes
// Returns type key from ETypeInfo
u32 EFontCharacter::GetTypeKey(void) const {
    return gpTypeInfo_EFontCharacter->m_nKey;
}

// 0x8036473C | 0x0C bytes
// Returns type version from ETypeInfo (lhz = unsigned short load)
u16 EFontCharacter::GetTypeVersion(void) const {
    return gpTypeInfo_EFontCharacter->m_nVersion;
}

// 0x80364748 | 0x0C bytes
const ETypeInfo* EFontCharacter::GetTypeInfoStatic(void) {
    return gpTypeInfo_EFontCharacter;
}

// 0x80364754 | 0x0C bytes
u16 EFontCharacter::GetReadVersion(void) {
    return gpTypeInfo_EFontCharacter->m_nReadVersion;
}

// 0x80364760 | 0x54 bytes
// Calls ETypeInfo::Register with New, Construct, Destruct function pointers
void EFontCharacter::RegisterType(u16 version) {
    ETypeInfo__Register(
        gpTypeInfo_EFontCharacter,
        (void*)EFontCharacter::New,
        (void*)EFontCharacter::Construct,
        (void*)EFontCharacter::Destruct,
        version,
        "EFontCharacter",
        gpTypeInfo_EFontCharacter  // parent type info
    );
}

// 0x803647B4 | 0x20 bytes
// Calls EStorable::CreateCopy base implementation
EFontCharacter* EFontCharacter::CreateCopy(void) const {
    return (EFontCharacter*)EStorable__CreateCopy(this);
}

// 0x803C85D8 | 0x34 bytes | NON_MATCHING
// Destructor (in template section): sets base vtable, conditionally deletes
// SN Systems destructor ABI: tests r4 & 1 for delete flag
EFontCharacter::~EFontCharacter() {
}

// ============================================================================
// EFontPage factory functions
// ============================================================================

// 0x803647D4 | 0x28 bytes
// Allocates 0x14 bytes, calls EFontPage::EFontPage()
EFontPage* EFontPage::New(void) {
    EFontPage* obj = (EFontPage*)__builtin_new(0x14);
    new (obj) EFontPage();
    return obj;
}

// 0x803647FC | 0x20 bytes
// Calls EFontPage::EFontPage() on existing memory
void EFontPage::Construct(EFontPage* obj) {
    new (obj) EFontPage();
}

// 0x8036481C | 0x10 bytes | NON_MATCHING
// Sets vtable to base class
void EFontPage::Destruct(EFontPage* obj) {
    (void)obj;
}

// 0x8036482C | 0x40 bytes
void EFontPage::SafeDelete(void) {
    delete this;
}

// 0x8036486C | 0x0C bytes
const ETypeInfo* EFontPage::GetTypeInfo(void) const {
    return gpTypeInfo_EFontPage;
}

// 0x80364878 | 0x0C bytes
const char* EFontPage::GetTypeName(void) const {
    return gpTypeInfo_EFontPage->m_pName;
}

// 0x80364884 | 0x0C bytes
u32 EFontPage::GetTypeKey(void) const {
    return gpTypeInfo_EFontPage->m_nKey;
}

// 0x80364890 | 0x0C bytes
u16 EFontPage::GetTypeVersion(void) const {
    return gpTypeInfo_EFontPage->m_nVersion;
}

// 0x8036489C | 0x0C bytes
const ETypeInfo* EFontPage::GetTypeInfoStatic(void) {
    return gpTypeInfo_EFontPage;
}

// 0x803648A8 | 0x0C bytes
u16 EFontPage::GetReadVersion(void) {
    return gpTypeInfo_EFontPage->m_nReadVersion;
}

// 0x803648B4 | 0x54 bytes
void EFontPage::RegisterType(u16 version) {
    ETypeInfo__Register(
        gpTypeInfo_EFontPage,
        (void*)EFontPage::New,
        (void*)EFontPage::Construct,
        (void*)EFontPage::Destruct,
        version,
        "EFontPage",
        gpTypeInfo_EFontPage
    );
}

// 0x80364908 | 0x20 bytes
EFontPage* EFontPage::CreateCopy(void) const {
    return (EFontPage*)EStorable__CreateCopy(this);
}

// 0x803C860C | 0x34 bytes | NON_MATCHING (SN destructor ABI)
EFontPage::~EFontPage() {
}

// ============================================================================
// EFontSize factory functions
// ============================================================================

// 0x80364928 | 0x28 bytes
// Allocates 0x2C bytes, calls EFontSize::EFontSize()
EFontSize* EFontSize::New(void) {
    EFontSize* obj = (EFontSize*)__builtin_new(0x2C);
    new (obj) EFontSize();
    return obj;
}

// 0x80364950 | 0x20 bytes
void EFontSize::Construct(EFontSize* obj) {
    new (obj) EFontSize();
}

// 0x80364970 | 0x24 bytes
// Calls EFontSize::~EFontSize(r4=2) — destructor without delete
void EFontSize::Destruct(EFontSize* obj) {
    obj->~EFontSize();
}

// 0x80364994 | 0x40 bytes
void EFontSize::SafeDelete(void) {
    delete this;
}

// 0x803649D4 | 0x0C bytes
const ETypeInfo* EFontSize::GetTypeInfo(void) const {
    return gpTypeInfo_EFontSize;
}

// 0x803649E0 | 0x0C bytes
const char* EFontSize::GetTypeName(void) const {
    return gpTypeInfo_EFontSize->m_pName;
}

// 0x803649EC | 0x0C bytes
u32 EFontSize::GetTypeKey(void) const {
    return gpTypeInfo_EFontSize->m_nKey;
}

// 0x803649F8 | 0x0C bytes
u16 EFontSize::GetTypeVersion(void) const {
    return gpTypeInfo_EFontSize->m_nVersion;
}

// 0x80364A04 | 0x0C bytes
const ETypeInfo* EFontSize::GetTypeInfoStatic(void) {
    return gpTypeInfo_EFontSize;
}

// 0x80364A10 | 0x0C bytes
u16 EFontSize::GetReadVersion(void) {
    return gpTypeInfo_EFontSize->m_nReadVersion;
}

// 0x80364A1C | 0x54 bytes
void EFontSize::RegisterType(u16 version) {
    ETypeInfo__Register(
        gpTypeInfo_EFontSize,
        (void*)EFontSize::New,
        (void*)EFontSize::Construct,
        (void*)EFontSize::Destruct,
        version,
        "EFontSize",
        gpTypeInfo_EFontSize
    );
}

// 0x80364A70 | 0x20 bytes
EFontSize* EFontSize::CreateCopy(void) const {
    return (EFontSize*)EStorable__CreateCopy(this);
}

// ============================================================================
// EFontData factory functions
// ============================================================================

// 0x80364A90 | 0x28 bytes
// Allocates 0x38 bytes, calls EFontData::EFontData()
EFontData* EFontData::New(void) {
    EFontData* obj = (EFontData*)__builtin_new(0x38);
    new (obj) EFontData();
    return obj;
}

// 0x80364AB8 | 0x20 bytes
void EFontData::Construct(EFontData* obj) {
    new (obj) EFontData();
}

// 0x80364AD8 | 0x24 bytes
// Calls EFontData::~EFontData(r4=2) — destructor without delete
void EFontData::Destruct(EFontData* obj) {
    obj->~EFontData();
}

// 0x80364AFC | 0x40 bytes
void EFontData::SafeDelete(void) {
    delete this;
}

// 0x80364B3C | 0x0C bytes
const ETypeInfo* EFontData::GetTypeInfo(void) const {
    return gpTypeInfo_EFontData;
}

// 0x80364B48 | 0x0C bytes
const char* EFontData::GetTypeName(void) const {
    return gpTypeInfo_EFontData->m_pName;
}

// 0x80364B54 | 0x0C bytes
u32 EFontData::GetTypeKey(void) const {
    return gpTypeInfo_EFontData->m_nKey;
}

// 0x80364B60 | 0x0C bytes
u16 EFontData::GetTypeVersion(void) const {
    return gpTypeInfo_EFontData->m_nVersion;
}

// 0x80364B6C | 0x0C bytes
const ETypeInfo* EFontData::GetTypeInfoStatic(void) {
    return gpTypeInfo_EFontData;
}

// 0x80364B78 | 0x0C bytes
u16 EFontData::GetReadVersion(void) {
    return gpTypeInfo_EFontData->m_nReadVersion;
}

// 0x80364B84 | 0x54 bytes
void EFontData::RegisterType(u16 version) {
    ETypeInfo__Register(
        gpTypeInfo_EFontData,
        (void*)EFontData::New,
        (void*)EFontData::Construct,
        (void*)EFontData::Destruct,
        version,
        "EFontData",
        gpTypeInfo_EFontData
    );
}

// 0x80364BD8 | 0x20 bytes
EFontData* EFontData::CreateCopy(void) const {
    return (EFontData*)EStorable__CreateCopy(this);
}

// ============================================================================
// Global constructor
// ============================================================================

// 0x80364BF8 | 0x2C bytes
// Calls __static_initialization_and_destruction_0(1, 0xFFFF)
// (global constructors keyed to operator<<(EStream &, EFontCharacter *))
// This is compiler-generated and invoked from .ctors section

// ============================================================================
// TArray<EFontPage*, TArrayDefaultAllocator> template instantiations
// ============================================================================

// 0x803C7B80 | 0x14 bytes
template<>
void TArray<EFontPage*, TArrayDefaultAllocator>::Init(void) {
    m_nSize = 0;
    m_pData = 0;
    m_nAlloc = 0;
}

// 0x803C7B94 | 0x30 bytes
template<>
TArray<EFontPage*, TArrayDefaultAllocator>::TArray(void) {
    Init();
}

// 0x803C7BC4 | 0x1C bytes
// Loop that does nothing visible (pointer-type elements have no destructor to call)
template<>
void TArray<EFontPage*, TArrayDefaultAllocator>::Destruct(EFontPage** ptr, int count) {
    for (int i = count - 1; i >= 0; i--) {
        // No-op for pointer types (no element destructor)
    }
}

// 0x803C7F0C | 0x1C bytes
// Same empty loop as Destruct
template<>
void TArray<EFontPage*, TArrayDefaultAllocator>::Construct(EFontPage** ptr, int count) {
    for (int i = count - 1; i >= 0; i--) {
        // No-op for pointer types
    }
}

// 0x803C7F28 | 0x2C bytes
// Copies pointer elements one-by-one
template<>
void TArray<EFontPage*, TArrayDefaultAllocator>::Copy(EFontPage** dst, EFontPage** src, int count) {
    for (int i = count - 1; i >= 0; i--) {
        *dst = *src;
        src++;
        dst++;
    }
}

// 0x803C7C2C | 0x40 bytes | NON_MATCHING
// Destructor: calls Deallocate, then conditionally calls operator delete
// SN Systems destructor ABI: tests r4 & 1 for delete flag
template<>
TArray<EFontPage*, TArrayDefaultAllocator>::~TArray(void) {
    Deallocate();
}
