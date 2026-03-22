// nghresfile.cpp - NghResFile (neighborhood resource file) and related functions
// Part of the Sims 2 GC decompilation
// Original: u2_ngc_release_dvd(nghresfile.obj)
//
// Small functions (<=64 bytes) decompiled from the nghresfile object file.

#include "types.h"
#include "stub_classes.h"

// Forward declarations
struct StringBuffer { u8 data[64]; };  // Opaque struct, actual size unknown
class MemoryCardCache;
struct NghLayout;
namespace Memory { class HandleNode; }

// External functions
extern void* NghResFile_GetGlobalManager();
extern int MemoryCardCache_SaveAll(void* mgr, int slot);
extern int MemoryCardCache_LoadCache(void* mgr, int slot);
extern int MemoryCardCache_LoadCacheInternal(void* mgr, void* layout, int slot, void* globalMgr);
extern int MemoryCardCache_GetTotalSize(void* mgr, void* layout);
extern int MemoryCardCache_GetSectionSize(void* mgr, void* layout, u32 section);
extern void StringBuffer_Assign(StringBuffer& dst, void* src);
extern void NghResFile_CreateInternal(void* mgr, StringBuffer& name);

// Globals
extern void* g_nghLayoutData;  // at sdata offset
extern u32 g_totalSaveGameSize;
extern u32 g_totalSaveGameSections;
extern int g_nghIds[4];        // neighborhood IDs
extern int g_houseIds[6];      // house IDs

//=============================================================================
// SaveAllMemoryCardCache
// Address: 0x800D25AC, Size: 64
//=============================================================================
int SaveAllMemoryCardCache(int slot) {
    void* mgr = NghResFile_GetGlobalManager();
    int result = MemoryCardCache_SaveAll(mgr, slot);
    return result != 0 ? 1 : 0;
}

//=============================================================================
// LoadCacheFromMemoryCard (global)
// Address: 0x800D25EC, Size: 64
//=============================================================================
int LoadCacheFromMemoryCard(int slot) {
    void* mgr = NghResFile_GetGlobalManager();
    int result = MemoryCardCache_LoadCache(mgr, slot);
    return result != 0 ? 1 : 0;
}

//=============================================================================
// MemoryCardCache::LoadCacheFromMemoryCard (member)
// Address: 0x800D2FBC, Size: 36
//=============================================================================
// Wrapper that passes global manager to internal function
// NON_MATCHING - sdata global reference

//=============================================================================
// GetTotalMemoryCardCacheSize
// Address: 0x800D2670, Size: 48
// NON_MATCHING - sdata layout pointer
//=============================================================================

//=============================================================================
// GetMemoryCardCacheSectionSize
// Address: 0x800D26A0, Size: 64
// NON_MATCHING - sdata layout pointer
//=============================================================================

//=============================================================================
// GetTotalSaveGameSize
// Address: 0x800D26E0, Size: 12
//=============================================================================
int GetTotalSaveGameSize() {
    return g_totalSaveGameSize;
}

//=============================================================================
// GetTotalNumberOfSaveGameSections
// Address: 0x800D26EC, Size: 12
//=============================================================================
int GetTotalNumberOfSaveGameSections() {
    return g_totalSaveGameSections;
}

//=============================================================================
// GetNumNghSubSections
// Address: 0x800D26F8, Size: 8
//=============================================================================
int GetNumNghSubSections(NghLayout* layout) {
    return *(int*)((u8*)layout + 12);
}

//=============================================================================
// getCurrentbuildVerNum - pack version into 32-bit value
// Address: 0x800D3860, Size: 32
//=============================================================================
int getCurrentbuildVerNum(int major, int minor, int patch, int build) {
    return (major << 24) | ((minor & 0xFF) << 16) | ((patch & 0xFF) << 8) | (build & 0xFF);
}

//=============================================================================
// GetNghIndex - find neighborhood index from ID
// Address: 0x800D3880, Size: 56
//=============================================================================
int GetNghIndex(int id) {
    for (int i = 0; i < 4; i++) {
        if (g_nghIds[i] == id) return i;
    }
    return -1;
}

//=============================================================================
// GetHouseIndex - find house index from ID
// Address: 0x800D38B8, Size: 56
//=============================================================================
int GetHouseIndex(int id) {
    for (int i = 0; i < 6; i++) {
        if (g_houseIds[i] == id) return i;
    }
    return -1;
}

//=============================================================================
// NghResFile stubs - most return 0 or are empty
//=============================================================================
class NghResFile {
public:
    u8 pad00[0x28];
    StringBuffer m_fileName; // 0x28
    u8 pad_rest[0x158];
    void* m_handleData;     // 0x180

    // Create - calls internal create, returns 0
    // Address: 0x800D3B94, Size: 36
    int Create(StringBuffer& name) {
        NghResFile_CreateInternal(this, name);
        return 0;
    }

    // Delete - returns 0
    // Address: 0x800D3BB8, Size: 8
    int Delete(StringBuffer&) { return 0; }

    // Open - returns 0
    // Address: 0x800D3BC0, Size: 8
    int Open(StringBuffer&) { return 0; }

    // CloseForReopen - returns 0
    // Address: 0x800D3BC8, Size: 8
    int CloseForReopen() { return 0; }

    // Reopen - returns 0
    // Address: 0x800D3BD0, Size: 8
    int Reopen() { return 0; }

    // Close - returns 0
    // Address: 0x800D3BD8, Size: 8
    int Close() { return 0; }

    // Update - empty
    // Address: 0x800D3BE0, Size: 4
    void Update() {}

    // Writable - returns 0
    // Address: 0x800D3BE4, Size: 8
    int Writable() { return 0; }

    // GetFileName
    // Address: 0x800D3BEC, Size: 44
    void GetFileName(StringBuffer& out) {
        StringBuffer_Assign(out, &m_fileName);
    }

    // ValidFile - returns 1
    // Address: 0x800D3C18, Size: 8
    int ValidFile() { return 1; }

    // CountTypes - returns 0
    // Address: 0x800D3C20, Size: 8
    int CountTypes() { return 0; }

    // GetIndType - returns 0
    // Address: 0x800D3C28, Size: 8
    int GetIndType(short) { return 0; }

    // GetByName - returns 0
    // Address: 0x800D3CC8, Size: 8
    void* GetByName(int, StringBuffer&, void (*)(void*, int)) { return NULL; }

    // GetName - empty
    // Address: 0x800D3D3C, Size: 4
    void GetName(int*, StringBuffer&) {}

    // GetResType - returns 0
    // Address: 0x800D3D40, Size: 8
    int GetResType(int*) { return 0; }

    // GetID
    // Address: 0x800D3D48, Size: 16
    void GetID(int* node, short* outID) {
        void* data = m_handleData;
        *outID = *(short*)((u8*)data + 8);
    }

    // GetIndex - empty
    // Address: 0x800D3D58, Size: 4
    void GetIndex(int*, short*) {}

    // FindUniqueName - empty
    // Address: 0x800D3D5C, Size: 4
    void FindUniqueName(int, StringBuffer&) {}
};
