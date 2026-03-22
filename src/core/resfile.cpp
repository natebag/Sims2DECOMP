// resfile.cpp - Resource file system
// Covers: resfile.obj, chainresfile.obj, objresfile.obj, iffresfile2.obj,
//         quickresfile.obj, seqresfile.obj, nghresfile.obj, stdresfile.obj
//
// All small functions (<=64 bytes) decompiled from the above object files.

#include "core/resfile.h"

// External functions (resolved by linker)
extern void StringBuffer_Clear(StringBuffer& buf);           // 0x800a6610
extern void StringBuffer_CopyFrom(StringBuffer& dest, void* src); // 0x800a6768
extern int  EString_IsValid(void* estring);                  // 0x800a62f0
extern void EString_GetFileName(void* estring, StringBuffer& dest); // 0x800a641c
extern void IFFResMap_DoStream(void* map, ReconBuffer* buf, int dir); // 0x800bdd24
extern void IFFResFile2_dtor_impl(void* obj);                // 0x800bdde8
extern void ReconObject_dtor(void* obj);                     // 0x80134734
extern void SeqResFile_dtor_impl(SeqResFile* obj);           // 0x8013dad0
extern int  SeqResFile_Open_impl(SeqResFile* self, StringBuffer& name); // 0x8013e0f4
extern void iResFile_ctor_impl(iResFile* self);              // 0x80135588
extern void __throw_length_error(const char* msg);           // 0x802427c0
extern void __terminate();                                   // 0x802427e8
extern void __static_init_nghresfile(int a, int b);          // 0x800d9264
extern void NghResFile_reset(void* self);                    // 0x800d4258
extern MemoryCardCache* NghResFile_GetMemoryCardCache_impl(void* self); // 0x800d8a28
extern int  MemoryCardCache_SaveAllToMemoryCard(MemoryCardCache* self, int slot); // 0x800d333c
extern int  MemoryCardCache_LoadCacheFromMemoryCard2(MemoryCardCache* self, int slot, void* file); // 0x800d2fe0
extern int  MemoryCardCache_GetMemoryUsage(MemoryCardCache* self, NghLayout* layout); // 0x800d29dc
extern int  MemoryCardCache_GetSubSectionMemoryUsage(MemoryCardCache* self, NghLayout* layout, int section); // 0x800d2a68
extern int  NghResFile_FindNodeInRegistry_impl(void* self, int id, void* node); // 0x800d8d10
extern void EString_dtor(void* estring, int mode);           // 0x800a1d70

// Static data references
// s_nghIndex: 4 entries at 0x80424128
// s_houseIndex: 6 entries at 0x80424138
// s_userIndex: 2 entries at 0x804FDC5C (via r13 offset)
// s_nghLayout: at 0x8048632C
// s_nghLayout7: at 0x80486344
// s_saveFileName: at 0x804FDC64
// NghResFile::m_uBothSectionChecksum: at 0x804FDC68 (r13-31924)
// NghResFile::m_uLastBothSectionChecksum: at 0x804FDC6C (r13-31928)
// iResFile::sFileList: at 0x804FDD60 (r13-31680)

// Global singleton pointer (r13-32056 offset)
// extern NghResFile* g_nghResFile;  // at r13-32056

// ============================================================================
// iResFile methods
// ============================================================================

// iResFile::Link - Add to global file list
// 0x8013553C (size=16)
void iResFile::Link(void) {
    m_next = sFileList;
    sFileList = this;
}

// iResFile::Unlink - Remove from global file list
// 0x8013554C (size=60)
void iResFile::Unlink(void) {
    iResFile** prev = &sFileList;
    if (*prev == 0) return;

    while (true) {
        iResFile* curr = *prev;
        if (curr == this) {
            *prev = curr->m_next;
            return;
        }
        prev = &curr->m_next;
        if (*prev == 0) return;
    }
}

// iResFile::GetError
// 0x80135624 (size=8)
int iResFile::GetError(void) {
    return m_error;
}

// iResFile::SetError
// 0x8013562C (size=8)
void iResFile::SetError(int error) {
    m_error = error;
}

// iResFile::GetResFileData
// 0x801358B8 (size=8)
ResFile* iResFile::GetResFileData(void) const {
    return m_resFileData;
}

// iResFile::SetResFileData
// 0x801358C0 (size=8)
void iResFile::SetResFileData(ResFile* data) {
    m_resFileData = data;
}

// iResFile::GetLanguage - Default implementation
// 0x8013579C (size=60)
// NON_MATCHING - vtable dispatch with SN Systems ABI adjustor thunks
int iResFile::GetLanguage(int* node) {
    // Original dispatches through vtable to call GetID(node, &id)
    // via SN Systems adjustor thunk, then returns 0
    short id;
    GetID(node, &id);
    return 0;
}

// iResFile::_dyncastimpl
// 0x801358A8 (size=16)
iResFile* iResFile::_dyncastimpl(SCID id) {
    if (id == 0x10) return this;
    return 0;
}

// ============================================================================
// ChainResFile methods
// ============================================================================

// ChainResFile::AddFile - Add a file to the chain (up to 8 slots)
// 0x800B1E98 (size=64)
// NON_MATCHING - loop structure and slot array stride differ with GCC layout
void ChainResFile::AddFile(iResFile* file) {
    // Original walks an array of 8 slots (stride 0x18 = 24 bytes each)
    // starting at this+0x14. Each slot has:
    //   -4: iResFile* (file pointer)
    //   +0: next pointer
    //   +16: active flag
    // Finds first empty slot (file ptr == NULL), stores the file
    char* slotBase = (char*)this + 0x14;
    for (int i = 0; i < 8; i++) {
        iResFile** fileSlot = (iResFile**)(slotBase - 4);
        if (*fileSlot == 0) {
            void* nextPtr = *(void**)slotBase;
            *fileSlot = file;
            *(void**)(slotBase + 4) = nextPtr;
            *(int*)(slotBase + 16) = 1;
            return;
        }
        slotBase += 0x18;
    }
}

// ChainResFile::CountFiles - Count non-null files in the chain
// 0x800B1FA8 (size=60)
// NON_MATCHING - loop structure differs with GCC layout
short ChainResFile::CountFiles(void) {
    // Original walks file pointers at this+0x10, stride 0x18
    // counting non-null entries up to 8
    char* ptr = (char*)this + 0x10;
    int count = 0;
    if (*(void**)ptr == 0) return (short)count;
    for (int i = 0; i < 8; i++) {
        count++;
        if (i >= 7) break;
        ptr += 0x18;
        if (*(void**)ptr == 0) break;
    }
    return (short)count;
}

// ChainResFile::_dyncastimpl
// 0x800B3C94 (size=32)
iResFile* ChainResFile::_dyncastimpl(SCID id) {
    if (id == 0x0F) return this;
    if (id == 0x10) return this;
    return 0;
}

// ChainResFile::Load - Sets error and returns (stub that calls SetError)
// 0x800B3230 (size=36)
void ChainResFile::Load(int* node) {
    SetError(-95);
}

// ChainResFile::GetByID - Delegates to GetByIDAndLanguage with lang=0
// 0x800B2A48 (size=60)
// NON_MATCHING - vtable dispatch
int* ChainResFile::GetByID(int type, short id, void (*callback)(void*, int)) {
    return GetByIDAndLanguage(type, id, 0, callback);
}

// ChainResFile::Add - Delegates to AddWithLanguage with lang=0
// 0x800B3318 (size=60)
// NON_MATCHING - vtable dispatch
int ChainResFile::Add(int* node, int type, short id, StringBuffer& name, bool flag) {
    return AddWithLanguage(node, type, id, name, 0, flag);
}

// ============================================================================
// QuickResFile methods
// ============================================================================

// QuickResFile::QuickResFile
// 0x801329B4 (size=60)
// NON_MATCHING - vtable pointer setup
QuickResFile::QuickResFile(void) : iResFile() {
    // vtable set to QuickResFile vtable (0x80464180)
}

// QuickResFile::Create
// 0x80132A54 (size=8)
int QuickResFile::Create(StringBuffer& name) {
    return -95;
}

// QuickResFile::Delete
// 0x80132A5C (size=8)
int QuickResFile::Delete(StringBuffer& name) {
    return -95;
}

// QuickResFile::Open - Delegates to global resfile via vtable
// 0x80132A64 (size=64)
// NON_MATCHING - global/vtable dispatch pattern
int QuickResFile::Open(StringBuffer& name) {
    // Opens via a global iResFile pointer, dispatching Open through vtable
    // Returns 0 after delegating
    return 0;
}

// QuickResFile::CloseForReopen
// 0x80132AA4 (size=8)
int QuickResFile::CloseForReopen(void) {
    return 0;
}

// QuickResFile::Reopen
// 0x80132AAC (size=8)
int QuickResFile::Reopen(void) {
    return 0;
}

// QuickResFile::Close
// 0x80132AB4 (size=8)
int QuickResFile::Close(void) {
    return 0;
}

// QuickResFile::Update
// 0x80132ABC (size=4)
void QuickResFile::Update(void) {
}

// QuickResFile::Writable
// 0x80132AC0 (size=8)
int QuickResFile::Writable(void) {
    return 0;
}

// QuickResFile::ValidFile
// 0x80132B70 (size=24)
int QuickResFile::ValidFile(void) {
    if (m_resFileData != 0) return 1;
    return 0;
}

// QuickResFile::CountTypes
// 0x80132B88 (size=8)
int QuickResFile::CountTypes(void) {
    return 0;
}

// QuickResFile::GetIndType
// 0x80132B90 (size=8)
int QuickResFile::GetIndType(short index) {
    return 0;
}

// QuickResFile::Count
// 0x80132B98 (size=8)
int QuickResFile::Count(int type) {
    return 0;
}

// QuickResFile::GetByID
// 0x80132BA0 (size=8)
int* QuickResFile::GetByID(int type, short id, void (*callback)(void*, int)) {
    return 0;
}

// QuickResFile::GetByName
// 0x80132BA8 (size=8)
int* QuickResFile::GetByName(int type, StringBuffer& name, void (*callback)(void*, int)) {
    return 0;
}

// QuickResFile::GetByIndex
// 0x80132BB0 (size=8)
int* QuickResFile::GetByIndex(int type, short index, void (*callback)(void*, int)) {
    return 0;
}

// QuickResFile::GetByIDAndLanguage
// 0x80132BB8 (size=8)
int* QuickResFile::GetByIDAndLanguage(int type, short id, char lang, void (*callback)(void*, int)) {
    return 0;
}

// QuickResFile::GetName - Clears the output StringBuffer
// 0x80132BC0 (size=36)
void QuickResFile::GetName(int* node, StringBuffer& name) {
    StringBuffer_Clear(name);
}

// QuickResFile::GetResType
// 0x80132BE4 (size=8)
int QuickResFile::GetResType(int* node) {
    return 0;
}

// QuickResFile::GetID
// 0x80132BEC (size=12)
void QuickResFile::GetID(int* node, short* id) {
    *id = 0;
}

// QuickResFile::GetIndex
// 0x80132BF8 (size=12)
void QuickResFile::GetIndex(int* node, short* index) {
    *index = 0;
}

// QuickResFile::GetLanguage
// 0x80132C04 (size=8)
int QuickResFile::GetLanguage(int* node) {
    return 0;
}

// QuickResFile::FindUniqueName - Clears the output StringBuffer
// 0x80132C0C (size=36)
void QuickResFile::FindUniqueName(int type, StringBuffer& name) {
    StringBuffer_Clear(name);
}

// QuickResFile::FindUniqueID
// 0x80132C30 (size=8)
int QuickResFile::FindUniqueID(int type) {
    return 0;
}

// QuickResFile::Detach
// 0x80132C38 (size=4)
void QuickResFile::Detach(int* node) {
}

// QuickResFile::Load
// 0x80132C3C (size=4)
void QuickResFile::Load(int* node) {
}

// QuickResFile::IsLittleEndian
// 0x80132C40 (size=8)
int QuickResFile::IsLittleEndian(int* node) {
    return 0;
}

// QuickResFile::SetID
// 0x80132C48 (size=4)
void QuickResFile::SetID(int* node, short id) {
}

// QuickResFile::Add
// 0x80132C4C (size=4)
int QuickResFile::Add(int* node, int type, short id, StringBuffer& name, bool flag) {
    return 0;
}

// QuickResFile::AddWithLanguage
// 0x80132C50 (size=4)
int QuickResFile::AddWithLanguage(int* node, int type, short id, StringBuffer& name, char lang, bool flag) {
    return 0;
}

// QuickResFile::Write
// 0x80132C54 (size=4)
int QuickResFile::Write(int* node) {
    return 0;
}

// QuickResFile::Remove
// 0x80132C58 (size=4)
int QuickResFile::Remove(int* node) {
    return 0;
}

// QuickResFile::SetInfo
// 0x80132C5C (size=4)
void QuickResFile::SetInfo(int* node, short id, StringBuffer& name, char lang) {
}

// QuickResFile::_dyncastimpl
// 0x80132D1C (size=32)
iResFile* QuickResFile::_dyncastimpl(SCID id) {
    if (id == 0x11) return this;
    if (id == 0x10) return this;
    return 0;
}

// ============================================================================
// ObjResFile methods
// ============================================================================

// ObjResFile::_dyncastimpl
// 0x8011047C (size=56)
iResFile* ObjResFile::_dyncastimpl(SCID id) {
    if (id == 0x0C) return this;
    if (id == 0x0D) return this;
    if (id == 0x0E) return this;
    if (id == 0x0F) return this;
    if (id == 0x10) return this;
    return 0;
}

// ============================================================================
// SeqResFile methods
// ============================================================================

// SeqResFile::ClearOpenSpecs
// 0x8013DA08 (size=12)
void SeqResFile::ClearOpenSpecs(void) {
    m_numOpenSpecs = 0;
}

// SeqResFile::_dyncastimpl
// 0x8013E420 (size=40)
iResFile* SeqResFile::_dyncastimpl(SCID id) {
    if (id == 0x0E) return this;
    if (id == 0x0F) return this;
    if (id == 0x10) return this;
    return 0;
}

// ============================================================================
// StdResFile methods
// ============================================================================

// StdResFile::_dyncastimpl
// 0x80145D28 (size=48)
iResFile* StdResFile::_dyncastimpl(SCID id) {
    if (id == 0x0D) return this;
    if (id == 0x0E) return this;
    if (id == 0x0F) return this;
    if (id == 0x10) return this;
    return 0;
}

// EdithResFile::Open - Delegates to SeqResFile::Open
// 0x80145CFC (size=44)
// NON_MATCHING - compiler generates mr. + conditional branch
int EdithResFile::Open(StringBuffer& name) {
    int result = SeqResFile::Open(name);
    if (result != 0) return result;
    return 0;
}

// ============================================================================
// IFFResFile2 / IFF methods
// ============================================================================

// GetLanguage - Extract language from packed short (high byte)
// 0x800BCD04 (size=8)
short GetLanguage(short value) {
    return value >> 8;
}

// SetLanguage - Set language byte in packed short (high byte = lang, low byte preserved)
// 0x800BCD0C (size=20)
// NON_MATCHING - GCC generates different load/store pattern
void SetLanguage(short* dest, char lang) {
    unsigned char lowByte = *((unsigned char*)dest + 1);
    unsigned short value = (unsigned short)((unsigned int)lang << 8) | lowByte;
    *dest = (short)value;
}

// IFFResMap::CountTypes - Count types in the vector (size / sizeof(IFFResList))
// 0x800BD968 (size=32)
// NON_MATCHING - magic constant division
int IFFResMap::CountTypes(void) {
    // Uses the magic constant 0xAAAAAAAAB to divide by 24 (sizeof IFFResList)
    // The original does: (end - begin) * 0xAAAAAAAB >> 3
    // This is equivalent to (end - begin) / 24 for the specific struct size
    int* begin = *(int**)((char*)this + 0);
    int* end = *(int**)((char*)this + 4);
    return (int)((unsigned int)((char*)end - (char*)begin) / 24);
}

// IFFResFile2::Writable
// 0x800BEA00 (size=8)
int IFFResFile2::Writable(void) {
    return *(int*)((char*)this + 0x11C);
}

// IFFResFile2::GetFileName - Delegates to EString at offset +0x10
// 0x800BEA08 (size=36)
void IFFResFile2::GetFileName(StringBuffer& name) {
    EString_GetFileName((char*)this + 0x10, name);
}

// IFFResFile2::ValidFile - Checks EString at offset +0x10
// 0x800BEA2C (size=36)
int IFFResFile2::ValidFile(void) {
    return EString_IsValid((char*)this + 0x10);
}

// IFFResFile2::GetByID - Delegates to GetByIDAndLanguage with lang=0
// 0x800BED18 (size=60)
// NON_MATCHING - vtable dispatch pattern
int* IFFResFile2::GetByID(int type, short id, void (*callback)(void*, int)) {
    return GetByIDAndLanguage(type, id, 0, callback);
}

// IFFResFile2::Add - Delegates to AddWithLanguage with lang=0
// 0x800BF8E4 (size=60)
// NON_MATCHING - vtable dispatch pattern
int IFFResFile2::Add(int* node, int type, short id, StringBuffer& name, bool flag) {
    return AddWithLanguage(node, type, id, name, 0, flag);
}

// IFFResFile2::SetOptimizeTarget
// 0x800C1034 (size=12)
void IFFResFile2::SetOptimizeTarget(void) {
    *(int*)((char*)this + 0x148) = 1;
}

// ============================================================================
// NghResFile methods
// ============================================================================

// NghResFile::Create - Calls reset(), returns 0
// 0x800D3B94 (size=36)
int NghResFile::Create(StringBuffer& name) {
    reset();
    return 0;
}

// NghResFile::Delete - Returns 0 (stub)
// 0x800D3BB8 (size=8)
int NghResFile::Delete(StringBuffer& name) {
    return 0;
}

// NghResFile::Open - Returns 0 (stub)
// 0x800D3BC0 (size=8)
int NghResFile::Open(StringBuffer& name) {
    return 0;
}

// NghResFile::CloseForReopen - Returns 0 (stub)
// 0x800D3BC8 (size=8)
int NghResFile::CloseForReopen(void) {
    return 0;
}

// NghResFile::Reopen - Returns 0 (stub)
// 0x800D3BD0 (size=8)
int NghResFile::Reopen(void) {
    return 0;
}

// NghResFile::Close - Returns 0 (stub)
// 0x800D3BD8 (size=8)
int NghResFile::Close(void) {
    return 0;
}

// NghResFile::Update - No-op (stub)
// 0x800D3BE0 (size=4)
void NghResFile::Update(void) {
}

// NghResFile::Writable - Returns 0 (stub)
// 0x800D3BE4 (size=8)
int NghResFile::Writable(void) {
    return 0;
}

// NghResFile::GetFileName - Copies internal filename to output
// 0x800D3BEC (size=44)
void NghResFile::GetFileName(StringBuffer& name) {
    StringBuffer_CopyFrom(name, (char*)this + 0x28);
}

// NghResFile::ValidFile - Always returns 1
// 0x800D3C18 (size=8)
int NghResFile::ValidFile(void) {
    return 1;
}

// NghResFile::CountTypes - Returns 0 (stub)
// 0x800D3C20 (size=8)
int NghResFile::CountTypes(void) {
    return 0;
}

// NghResFile::GetIndType - Returns 0 (stub)
// 0x800D3C28 (size=8)
int NghResFile::GetIndType(short index) {
    return 0;
}

// NghResFile::GetByName - Returns 0 (stub)
// 0x800D3CC8 (size=8)
int* NghResFile::GetByName(int type, StringBuffer& name, void (*callback)(void*, int)) {
    return 0;
}

// NghResFile::GetName - No-op (stub)
// 0x800D3D3C (size=4)
void NghResFile::GetName(int* node, StringBuffer& name) {
}

// NghResFile::GetResType - Returns 0 (stub)
// 0x800D3D40 (size=8)
int NghResFile::GetResType(int* node) {
    return 0;
}

// NghResFile::GetID - Gets ID from internal node data
// 0x800D3D48 (size=16)
void NghResFile::GetID(int* node, short* id) {
    // r3+0x180 -> pointer to node, then +8 -> ID field
    void* internalNode = *(void**)((char*)this + 0x180);
    *id = *(unsigned short*)((char*)internalNode + 8);
}

// NghResFile::GetIndex - No-op (stub)
// 0x800D3D58 (size=4)
void NghResFile::GetIndex(int* node, short* index) {
}

// NghResFile::FindUniqueName - No-op (stub)
// 0x800D3D5C (size=4)
void NghResFile::FindUniqueName(int type, StringBuffer& name) {
}

// NghResFile::FindUniqueID - Returns 0 (stub)
// 0x800D3D60 (size=8)
int NghResFile::FindUniqueID(int type) {
    return 0;
}

// NghResFile::Detach - No-op (stub)
// 0x800D3D68 (size=4)
void NghResFile::Detach(int* node) {
}

// NghResFile::Load - No-op (stub)
// 0x800D3D6C (size=4)
void NghResFile::Load(int* node) {
}

// NghResFile::IsLittleEndian - Always returns 1 (true)
// 0x800D3D70 (size=8)
int NghResFile::IsLittleEndian(int* node) {
    return 1;
}

// NghResFile::SetID - No-op (stub)
// 0x800D3D78 (size=4)
void NghResFile::SetID(int* node, short id) {
}

// NghResFile::Write - No-op (stub)
// 0x800D3F6C (size=4)
int NghResFile::Write(int* node) {
    return 0;
}

// NghResFile::Remove - No-op (stub)
// 0x800D3F70 (size=4)
int NghResFile::Remove(int* node) {
    return 0;
}

// NghResFile::SetInfo - No-op (stub)
// 0x800D3F74 (size=4)
void NghResFile::SetInfo(int* node, short id, StringBuffer& name, char lang) {
}

// NghResFile::SetCurrentHouse - Store house number (0-based internally, 1-based input)
// 0x800D3F78 (size=12)
void NghResFile::SetCurrentHouse(unsigned int house) {
    m_currentHouse = (int)(house - 1);
}

// NghResFile::GetCurrentHouse - Returns house number (converts back to 1-based)
// 0x800D93C0 (size=12)
unsigned int NghResFile::GetCurrentHouse(void) const {
    return (unsigned int)(m_currentHouse + 1);
}

// NghResFile::GetSourceType
// 0x800D93CC (size=8)
int NghResFile::GetSourceType(void) const {
    return m_sourceType;
}

// NghResFile::PrepareMemCardWrite - Increments write ref count, returns 1
// 0x800D43DC (size=32)
int NghResFile::PrepareMemCardWrite(char* data, unsigned char flag) {
    unsigned short* refCount = (unsigned short*)((char*)this + 0x184);
    (*refCount)++;
    // Compares sign-extended refCount to 1, but always returns 1
    return 1;
}

// NghResFile::FinishMemCardWrite - Decrements write ref count
// 0x800D43FC (size=48)
int NghResFile::FinishMemCardWrite(char* data, unsigned char flag) {
    unsigned short* refCount = (unsigned short*)((char*)this + 0x184);
    (*refCount)--;
    short val = (short)*refCount;
    if (val <= 0) {
        m_uBothSectionChecksum = 0;
        return 1;
    }
    return 1;
}

// NghResFile::GetThumbIdFromFamilyAndIndex
// 0x800D53E4 (size=56)
int NghResFile::GetThumbIdFromFamilyAndIndex(int family, int index) {
    // family is passed in r4, index in r5 (due to hidden this in r3)
    if (family == 1 && index == 1) {
        return 3;
    }
    if (family <= 4) {
        return family;
    }
    // For family > 4: (family - 20) * 4 + index + 5
    return (family - 20) * 4 + index + 5;
}

// NghResFile::StoreFamilyThumbGUID
// 0x800D541C (size=64)
void NghResFile::StoreFamilyThumbGUID(int family, int index, unsigned int guid) {
    int thumbId = GetThumbIdFromFamilyAndIndex(family, index);
    // Store at m_thumbGUIDs[thumbId - 1]
    unsigned int* thumbGUIDs = (unsigned int*)((char*)this + 0x194);
    thumbGUIDs[thumbId - 1] = guid;
}

// NghResFile::StoreThumbGUID
// 0x800D545C (size=20)
void NghResFile::StoreThumbGUID(unsigned int thumbId, unsigned int guid) {
    unsigned int* thumbGUIDs = (unsigned int*)((char*)this + 0x194);
    thumbGUIDs[thumbId - 1] = guid;
}

// NghResFile::GetThumbGUID
// 0x800D5470 (size=20)
unsigned int NghResFile::GetThumbGUID(unsigned int thumbId) {
    unsigned int* thumbGUIDs = (unsigned int*)((char*)this + 0x194);
    return thumbGUIDs[thumbId - 1];
}

// NghResFile::GetResIDFromThumbGUID - Search m_thumbGUIDs for matching GUID
// 0x800D5484 (size=60)
unsigned short NghResFile::GetResIDFromThumbGUID(unsigned int guid) {
    unsigned int* thumbGUIDs = (unsigned int*)((char*)this + 0x194);
    for (int i = 0; i < 36; i++) {
        if (thumbGUIDs[i] == guid) {
            return (unsigned short)(i + 1);
        }
    }
    return 0;
}

// NghResFile::AreHouseContentsLoaded
// 0x800D6C08 (size=44)
bool NghResFile::AreHouseContentsLoaded(unsigned int house) const {
    // house is 1-based, convert to 0-based index
    unsigned int** houseContents = (unsigned int**)((char*)this + 0x13C);
    unsigned int* section = houseContents[house - 1];
    if (*(int*)((char*)section + 8) != 0) {
        return true;
    }
    return false;
}

// TMtraceNull - Variadic no-op trace function
// 0x800D7C1C (size=4)
void TMtraceNull(...) {
}

// NghResFile::SwapTwoByteNumber - Byte-swap a 16-bit value in place
// 0x800D8A70 (size=20)
void NghResFile::SwapTwoByteNumber(unsigned short* ptr) {
    unsigned char* bytes = (unsigned char*)ptr;
    unsigned char tmp = bytes[0];
    bytes[0] = bytes[1];
    bytes[1] = tmp;
}

// NghResFile::SwapFourByteNumber - Byte-swap a 32-bit value in place
// 0x800D8A84 (size=36)
void NghResFile::SwapFourByteNumber(unsigned int* ptr) {
    unsigned char* bytes = (unsigned char*)ptr;
    unsigned char b0 = bytes[0];
    unsigned char b1 = bytes[1];
    unsigned char b2 = bytes[2];
    unsigned char b3 = bytes[3];
    bytes[0] = b3;
    bytes[1] = b2;
    bytes[2] = b1;
    bytes[3] = b0;
}

// NghResFile::IsIDRegistered - Check if a registry ID has been registered
// 0x800D8AA8 (size=60)
int NghResFile::IsIDRegistered(RegistryID id) {
    RegistryNode node;
    // Zero-init the node (16 bytes)
    int* nodeData = (int*)&node;
    nodeData[0] = 0;
    nodeData[1] = 0;
    nodeData[2] = 0;
    nodeData[3] = 0;
    return FindNodeInRegistry(id, node);
}

// NghResFile::SetStoreChecksum
// 0x800D8EE0 (size=8)
void NghResFile::SetStoreChecksum(bool value) {
    *(int*)((char*)this + 0x18C) = (int)value;
}

// NghResFile::GetStoreChecksum
// 0x800D8EE8 (size=8)
bool NghResFile::GetStoreChecksum(void) {
    return *(int*)((char*)this + 0x18C) != 0;
}

// NghResFile::ResetChecksums - Clear both checksum statics
// 0x800D8EF0 (size=16)
void NghResFile::ResetChecksums(void) {
    m_uBothSectionChecksum = 0;
    m_uLastBothSectionChecksum = 0;
}

// ============================================================================
// Free functions - NGH helpers
// ============================================================================

// GetNumNghSubSections
// 0x800D26F8 (size=8)
int GetNumNghSubSections(NghLayout* layout) {
    return layout->m_numSubSections;
}

// GetTotalSaveGameSize - Read from s_nghLayout
// 0x800D26E0 (size=12)
// NON_MATCHING - absolute address load
int GetTotalSaveGameSize(void) {
    // Loads from 0x8048633C (s_nghLayout + 0x10)
    extern NghLayout s_nghLayout;
    return s_nghLayout.m_totalSize;
}

// GetTotalNumberOfSaveGameSections - Read from s_nghLayout
// 0x800D26EC (size=12)
// NON_MATCHING - absolute address load
int GetTotalNumberOfSaveGameSections(void) {
    // Loads from 0x80486334 (s_nghLayout + 0x08)
    extern NghLayout s_nghLayout;
    return s_nghLayout.m_numSections;
}

// getCurrentbuildVerNum - Pack version numbers into a single 32-bit value
// 0x800D3860 (size=32)
unsigned int getCurrentbuildVerNum(int a, int b, int c, int d) {
    return ((unsigned int)a << 24) | ((b & 0xFF) << 16) | ((c & 0xFF) << 8) | (d & 0xFF);
}

// GetNghIndex - Search s_nghIndex array for matching value
// 0x800D3880 (size=56)
// NON_MATCHING - absolute address for s_nghIndex table
int GetNghIndex(int value) {
    // Searches 4-entry table at 0x80424128
    extern int s_nghIndex[4];
    for (int i = 0; i < 4; i++) {
        if (value == s_nghIndex[i]) return i;
    }
    return -1;
}

// GetHouseIndex - Search s_houseIndex array for matching value
// 0x800D38B8 (size=56)
// NON_MATCHING - absolute address for s_houseIndex table
int GetHouseIndex(int value) {
    // Searches 6-entry table at 0x80424138
    extern int s_houseIndex[6];
    for (int i = 0; i < 6; i++) {
        if (value == s_houseIndex[i]) return i;
    }
    return -1;
}

// GetUserIndex - Search s_userIndex array for matching value
// 0x800D38F0 (size=48)
// NON_MATCHING - r13-relative address for s_userIndex
int GetUserIndex(int value) {
    // Searches 2-entry table at r13-31940
    extern int s_userIndex[2];
    for (int i = 0; i < 2; i++) {
        if (value == s_userIndex[i]) return i;
    }
    return -1;
}

// SaveAllMemoryCardCache - Get cache and save all
// 0x800D25AC (size=64)
// NON_MATCHING - r13-relative global access
int SaveAllMemoryCardCache(int slot) {
    extern void* g_nghResFile;  // r13-32056
    MemoryCardCache* cache = NghResFile_GetMemoryCardCache_impl(g_nghResFile);
    int result = MemoryCardCache_SaveAllToMemoryCard(cache, slot);
    return result != 0 ? 1 : 0;
}

// LoadCacheFromMemoryCard(int) - Get cache and load
// 0x800D25EC (size=64)
// NON_MATCHING - r13-relative global access
int LoadCacheFromMemoryCard(int slot) {
    extern void* g_nghResFile;  // r13-32056
    MemoryCardCache* cache = NghResFile_GetMemoryCardCache_impl(g_nghResFile);
    int result = cache->LoadCacheFromMemoryCard(slot);
    return result != 0 ? 1 : 0;
}

// GetTotalMemoryCardCacheSize
// 0x800D2670 (size=48)
// NON_MATCHING - absolute address for s_nghLayout
int GetTotalMemoryCardCacheSize(void) {
    extern void* g_nghResFile;  // r13-32056
    extern NghLayout s_nghLayout;  // 0x8048632C
    MemoryCardCache* cache = NghResFile_GetMemoryCardCache_impl(g_nghResFile);
    return MemoryCardCache_GetMemoryUsage(cache, &s_nghLayout);
}

// GetMemoryCardCacheSectionSize
// 0x800D26A0 (size=64)
// NON_MATCHING - absolute address for s_nghLayout
int GetMemoryCardCacheSectionSize(unsigned int section) {
    extern void* g_nghResFile;  // r13-32056
    extern NghLayout s_nghLayout;  // 0x8048632C
    MemoryCardCache* cache = NghResFile_GetMemoryCardCache_impl(g_nghResFile);
    return MemoryCardCache_GetSubSectionMemoryUsage(cache, &s_nghLayout, section);
}

// MemoryCardCache::LoadCacheFromMemoryCard(int) - Thin wrapper
// 0x800D2FBC (size=36)
// NON_MATCHING - r13-relative global access
int MemoryCardCache::LoadCacheFromMemoryCard(int slot) {
    extern void* g_nghResFile;  // r13-32056
    return MemoryCardCache_LoadCacheFromMemoryCard2(this, slot, g_nghResFile);
}

// ============================================================================
// Destructors
// ============================================================================

// StdResFile::~StdResFile - Calls SeqResFile dtor
// 0x803AE07C (size=32)
StdResFile::~StdResFile(void) {
    // Delegates to ~SeqResFile
}

// EdithResFile::~EdithResFile - Calls SeqResFile dtor
// 0x803AE09C (size=32)
EdithResFile::~EdithResFile(void) {
    // Delegates to ~SeqResFile
}

// __tcf_0 - Static destructor for ObjResFile globals
// 0x80110340 (size=40)
// NON_MATCHING - r13-relative access + external call
static void __tcf_0() {
    // Destroys EString at r13-24192 with mode 2
    // EString_dtor((char*)&__r13_offset - 24192, 2);
}

// ============================================================================
// IFF template instantiations
// ============================================================================

// IFFBehResFile::~IFFBehResFile
// 0x803A496C (size=56)
// NON_MATCHING - vtable setup
IFFBehResFile::~IFFBehResFile(void) {
    // Sets vtable pointers then calls IFFResFile2::~IFFResFile2
}

// ============================================================================
// SimpleReconObject<IFFResMap> template instantiations
// ============================================================================

// SimpleReconObject<IFFResMap>::~SimpleReconObject
// 0x803A4BC0 (size=32)
// NON_MATCHING - calls ReconObject destructor
// template<>
// SimpleReconObject<IFFResMap>::~SimpleReconObject(void) {
//     ReconObject_dtor(this);
// }

// SimpleReconObject<IFFResMap>::DoStream
// 0x803A4BE0 (size=36)
// NON_MATCHING - template instantiation
// Loads m_object (offset +4), calls IFFResMap::DoStream on it
// template<>
// void SimpleReconObject<IFFResMap>::DoStream(ReconBuffer* buffer, int direction) {
//     m_object->DoStream(buffer, direction);
// }

// SimpleReconObject<IFFResMap>::GetType
// 0x803A4C04 (size=8)
// NON_MATCHING - template instantiation
// Returns m_type (offset +8)
// template<>
// unsigned int SimpleReconObject<IFFResMap>::GetType(void) {
//     return m_type;
// }

// ============================================================================
// _String_base
// ============================================================================

// _String_base<char, allocator<char>>::_M_throw_length_error
// 0x803AE8E0 (size=28)
// NON_MATCHING - throws length_error exception
// This is an STL internal function that throws a length_error
// with message at 0x803EE0B4, then calls terminate
// void _String_base_throw_length_error() {
//     __throw_length_error("basic_string::_S_create");
//     __terminate();
// }

// ============================================================================
// Global constructors/destructors
// ============================================================================

// global constructors keyed to s_nghSectionLayout
// 0x800D93D4 (size=44)
// NON_MATCHING - compiler-generated static init
// Calls __static_init_nghresfile(1, 0xFFFF)

// global destructors keyed to s_nghSectionLayout
// 0x800D9400 (size=44)
// NON_MATCHING - compiler-generated static fini
// Calls __static_init_nghresfile(0, 0xFFFF)
