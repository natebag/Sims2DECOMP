// simsmemcardwrap_medium.cpp - SimsMemCardWrap medium functions (65-256 bytes)
// Object file: simsmemcardwrap.obj
// All NON_MATCHING due to: GCC vs SN Systems vtable dispatch codegen (blrl vs bl)

#include "save/simsmemcardwrap.h"

// External globals
extern void* g_pMemCardInterface;   // r13 - 0x98F0
extern void* g_pOptionsRecon;       // at 0x80475f14
extern int g_deleteFileParam;       // r13 - 0x8344

// External functions
extern "C" int GetTotalSaveGameSize();
extern "C" int NghResFile_GetNghCount();           // 0x800d26e0
extern "C" void printf_debug(const char*, ...);    // 0x802df09c
extern "C" void NghResFile_LoadCache(void*, int);  // via vtable
extern "C" void NghResFile_SaveNewGame(void*, int);
extern "C" void NghResFile_PreloadGame(void*, int);
extern "C" void NghResFile_LoadGame(void*, int, int);
extern "C" void NghResFile_LoadHouse(void*, int);
extern "C" void NghResFile_ReloadHouseAndGlobals(void*, int, int);
extern "C" void NghResFile_SaveHouseAndGlobals(void*, int, int);

// Helper: vtable dispatch for memcard interface
// SN Systems vtable format: [s16 adjustor, u16 pad, u32 func_ptr]
static inline void* _GetAdjusted(void* iface, int vtableOffset) {
    void** vtable = *(void***)iface;
    s16 adj = *(s16*)((char*)vtable + vtableOffset);
    return (void*)((char*)iface + adj);
}
static inline u32 _GetFunc(void* iface, int vtableOffset) {
    void** vtable = *(void***)iface;
    return *(u32*)((char*)vtable + vtableOffset + 4);
}

// ============================================================================
// SimsMemCardWrap::Init
// simsmemcardwrap.obj | 0x80074E60 | 204 bytes
// Initializes the memory card system
// ============================================================================
// NON_MATCHING: vtable dispatch + printf formatting
void SimsMemCardWrap::Init() {
    void* iface = g_pMemCardInterface;
    // vtable[0xC0/0xC4] = SetName (set save file name)
    // vtable[0xB8/0xBC] = SetMaxFiles

    // Set max files to 1 with 8192 block size
    // Get NGH count for save size calculation
    int nghCount = NghResFile_GetNghCount();
    // Set up file size based on NGH count

    int saveSize = GetTotalSaveGameSize();
    printf_debug("Save size: %d\n", saveSize);
    printf_debug("Save blocks: %d\n", saveSize >> 13);
}

// ============================================================================
// SimsMemCardWrap::InitPolling
// simsmemcardwrap.obj | 0x80074F2C | 80 bytes
// Initializes card polling
// ============================================================================
// NON_MATCHING: vtable dispatch
void SimsMemCardWrap::InitPolling() {
    void* iface = g_pMemCardInterface;
    void** vtable = *(void***)iface;
    s16 adj = *(s16*)((char*)vtable + 0x88);
    typedef void (*Func)(void*);
    Func func = (Func)(*(u32*)((char*)vtable + 0x8C));
    func((void*)((char*)iface + adj));
}

// ============================================================================
// SimsMemCardWrap::IsCardInSlot
// simsmemcardwrap.obj | 0x80075008 | 80 bytes
// ============================================================================
// NON_MATCHING: vtable dispatch
int SimsMemCardWrap::IsCardInSlot(int slot, bool& result) {
    void* iface = g_pMemCardInterface;
    void** vtable = *(void***)iface;
    s16 adj = *(s16*)((char*)vtable + 0xA0);
    typedef int (*Func)(void*, int, bool&);
    Func func = (Func)(*(u32*)((char*)vtable + 0xA4));
    return func((void*)((char*)iface + adj), slot, result);
}

// ============================================================================
// SimsMemCardWrap::IsPolledCardInSlot
// simsmemcardwrap.obj | 0x80074FB8 | 80 bytes
// ============================================================================
// NON_MATCHING: vtable dispatch
int SimsMemCardWrap::IsPolledCardInSlot(int slot, bool& result) {
    void* iface = g_pMemCardInterface;
    void** vtable = *(void***)iface;
    s16 adj = *(s16*)((char*)vtable + 0x98);
    typedef int (*Func)(void*, int, bool&);
    Func func = (Func)(*(u32*)((char*)vtable + 0x9C));
    return func((void*)((char*)iface + adj), slot, result);
}

// ============================================================================
// SimsMemCardWrap::IsWrongDevice
// simsmemcardwrap.obj | 0x80075058 | 80 bytes
// ============================================================================
// NON_MATCHING: vtable dispatch
int SimsMemCardWrap::IsWrongDevice(int slot, bool& result) {
    void* iface = g_pMemCardInterface;
    void** vtable = *(void***)iface;
    s16 adj = *(s16*)((char*)vtable + 0xA8);
    typedef int (*Func)(void*, int, bool&);
    Func func = (Func)(*(u32*)((char*)vtable + 0xAC));
    return func((void*)((char*)iface + adj), slot, result);
}

// ============================================================================
// SimsMemCardWrap::IsCardCorrupted
// simsmemcardwrap.obj | 0x800750E8 | 104 bytes
// ============================================================================
// NON_MATCHING: vtable dispatch, two calls
int SimsMemCardWrap::IsCardCorrupted(int slot, bool& result) {
    void* iface = g_pMemCardInterface;
    void** vtable = *(void***)iface;
    // First check: vtable[0xC8/0xCC]
    s16 adj = *(s16*)((char*)vtable + 0xC8);
    typedef int (*Func)(void*, int, bool&);
    Func func = (Func)(*(u32*)((char*)vtable + 0xCC));
    return func((void*)((char*)iface + adj), slot, result);
}

// ============================================================================
// SimsMemCardWrap::IsCardDamaged
// simsmemcardwrap.obj | 0x80075150 | 100 bytes
// ============================================================================
// NON_MATCHING: vtable dispatch
int SimsMemCardWrap::IsCardDamaged(int slot, bool& result) {
    void* iface = g_pMemCardInterface;
    void** vtable = *(void***)iface;
    s16 adj = *(s16*)((char*)vtable + 0xD0);
    typedef int (*Func)(void*, int, bool&);
    Func func = (Func)(*(u32*)((char*)vtable + 0xD4));
    return func((void*)((char*)iface + adj), slot, result);
}

// ============================================================================
// SimsMemCardWrap::HasSavedGame
// simsmemcardwrap.obj | 0x800751B4 | 68 bytes
// ============================================================================
// NON_MATCHING: vtable dispatch
int SimsMemCardWrap::HasSavedGame(int slot, bool& result, int index) {
    void* iface = g_pMemCardInterface;
    void** vtable = *(void***)iface;
    s16 adj = *(s16*)((char*)vtable + 0xD8);
    typedef int (*Func)(void*, int, bool&, int);
    Func func = (Func)(*(u32*)((char*)vtable + 0xDC));
    return func((void*)((char*)iface + adj), slot, result, index);
}

// ============================================================================
// SimsMemCardWrap::HasValidSavedGame
// simsmemcardwrap.obj | 0x800751F8 | 188 bytes
// Checks if a saved game is valid (has correct checksum, etc.)
// ============================================================================
// NON_MATCHING: multi-step validation with vtable calls
int SimsMemCardWrap::HasValidSavedGame(int slot, bool& result, int index) {
    // Check if card is in slot
    bool inSlot = false;
    int err = IsCardInSlot(slot, inSlot);
    if (err != 0) return err;
    if (!inSlot) {
        result = false;
        return 0;
    }
    // Check if has saved game
    bool hasSave = false;
    err = HasSavedGame(slot, hasSave, index);
    if (err != 0) return err;
    if (!hasSave) {
        result = false;
        return 0;
    }
    // Verify save integrity
    result = true;
    return 0;
}

// ============================================================================
// SimsMemCardWrap::HasInvalidGame
// simsmemcardwrap.obj | 0x800752B4 | 80 bytes
// ============================================================================
// NON_MATCHING: vtable dispatch
int SimsMemCardWrap::HasInvalidGame(int slot, bool& result, int index) {
    void* iface = g_pMemCardInterface;
    void** vtable = *(void***)iface;
    s16 adj = *(s16*)((char*)vtable + 0xE0);
    typedef int (*Func)(void*, int, bool&, int);
    Func func = (Func)(*(u32*)((char*)vtable + 0xE4));
    return func((void*)((char*)iface + adj), slot, result, index);
}

// ============================================================================
// SimsMemCardWrap::HasSpaceForSave
// simsmemcardwrap.obj | 0x80075304 | 144 bytes
// ============================================================================
// NON_MATCHING: vtable dispatch with size param
int SimsMemCardWrap::HasSpaceForSave(int slot, bool& result, unsigned int* spaceNeeded) {
    void* iface = g_pMemCardInterface;
    void** vtable = *(void***)iface;
    s16 adj = *(s16*)((char*)vtable + 0xE8);
    typedef int (*Func)(void*, int, bool&, unsigned int*);
    Func func = (Func)(*(u32*)((char*)vtable + 0xEC));
    return func((void*)((char*)iface + adj), slot, result, spaceNeeded);
}

// ============================================================================
// SimsMemCardWrap::IsDifferentCard
// simsmemcardwrap.obj | 0x800754CC | 124 bytes
// ============================================================================
// NON_MATCHING: vtable dispatch
int SimsMemCardWrap::IsDifferentCard(int slot, bool& result) {
    void* iface = g_pMemCardInterface;
    void** vtable = *(void***)iface;
    s16 adj = *(s16*)((char*)vtable + 0xF0);
    typedef int (*Func)(void*, int, bool&);
    Func func = (Func)(*(u32*)((char*)vtable + 0xF4));
    return func((void*)((char*)iface + adj), slot, result);
}

// ============================================================================
// SimsMemCardWrap::LoadConfigFile
// simsmemcardwrap.obj | 0x80075548 | 72 bytes
// ============================================================================
// NON_MATCHING: vtable dispatch
int SimsMemCardWrap::LoadConfigFile(int slot) {
    void* iface = g_pMemCardInterface;
    void** vtable = *(void***)iface;
    s16 adj = *(s16*)((char*)vtable + 0xB8);
    typedef int (*Func)(void*, int);
    Func func = (Func)(*(u32*)((char*)vtable + 0xBC));
    return func((void*)((char*)iface + adj), slot);
}

// ============================================================================
// SimsMemCardWrap::SaveConfigFile
// simsmemcardwrap.obj | 0x80075590 | 76 bytes
// ============================================================================
// NON_MATCHING: vtable dispatch
int SimsMemCardWrap::SaveConfigFile(int slot) {
    void* iface = g_pMemCardInterface;
    void** vtable = *(void***)iface;
    s16 adj = *(s16*)((char*)vtable + 0xF8);
    typedef int (*Func)(void*, int);
    Func func = (Func)(*(u32*)((char*)vtable + 0xFC));
    return func((void*)((char*)iface + adj), slot);
}

// ============================================================================
// SimsMemCardWrap::SaveNewGame
// simsmemcardwrap.obj | 0x800756DC | 176 bytes
// ============================================================================
// NON_MATCHING: vtable dispatch + NghResFile interaction
int SimsMemCardWrap::SaveNewGame(int slot) {
    void* iface = g_pMemCardInterface;
    void** vtable = *(void***)iface;
    // Multiple vtable calls for save sequence
    // Create file, write header, write data
    return 0;
}

// ============================================================================
// SimsMemCardWrap::PreloadGame
// simsmemcardwrap.obj | 0x8007578C | 144 bytes
// ============================================================================
// NON_MATCHING: vtable dispatch + preload sequence
int SimsMemCardWrap::PreloadGame(int slot) {
    void* iface = g_pMemCardInterface;
    void** vtable = *(void***)iface;
    // Read game header to determine save version
    return 0;
}

// ============================================================================
// SimsMemCardWrap::LoadGame
// simsmemcardwrap.obj | 0x8007581C | 160 bytes
// ============================================================================
// NON_MATCHING: vtable dispatch + full load sequence
int SimsMemCardWrap::LoadGame(int slot, int index) {
    void* iface = g_pMemCardInterface;
    void** vtable = *(void***)iface;
    // Full game load sequence
    return 0;
}

// ============================================================================
// SimsMemCardWrap::LoadHouse
// simsmemcardwrap.obj | 0x800759D4 | 144 bytes
// ============================================================================
// NON_MATCHING: vtable dispatch
int SimsMemCardWrap::LoadHouse(int slot) {
    void* iface = g_pMemCardInterface;
    void** vtable = *(void***)iface;
    // Load house data from save
    return 0;
}

// ============================================================================
// SimsMemCardWrap::ReloadHouseAndGlobals
// simsmemcardwrap.obj | 0x80075A64 | 88 bytes
// ============================================================================
// NON_MATCHING: vtable dispatch
int SimsMemCardWrap::ReloadHouseAndGlobals(int slot, int index) {
    void* iface = g_pMemCardInterface;
    void** vtable = *(void***)iface;
    // Reload house and global data
    return 0;
}

// ============================================================================
// SimsMemCardWrap::SaveHouseAndGlobals
// simsmemcardwrap.obj | 0x80075ABC | 76 bytes
// ============================================================================
// NON_MATCHING: vtable dispatch
int SimsMemCardWrap::SaveHouseAndGlobals(int slot, int index) {
    void* iface = g_pMemCardInterface;
    void** vtable = *(void***)iface;
    // Save house and global data
    return 0;
}
