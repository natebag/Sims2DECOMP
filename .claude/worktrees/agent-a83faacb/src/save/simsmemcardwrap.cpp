// simsmemcardwrap.cpp - Memory card / save system wrapper
// Object file: simsmemcardwrap.obj
// 13 functions decompiled from Sims 2 GC
// 3 MATCHING, 10 NON_MATCHING
// Matching: InvalidatePS2SavedGame, XboxOnNoMemory, GetSpaceRequiredForPs2HDDSave
// NON_MATCHING causes: GCC tail-call optimization (bctr/b vs blrl/bl),
// different global addressing (abs vs SDA r13-relative), register allocation
//
// SimsMemCardWrap uses a vtable-based platform interface.
// The global at r13 - 26384 (0x98F0) holds the interface pointer.
// All platform calls go through: vtable = *interface; adjustor + func_ptr dispatch.
//
// SN Systems vtable entry format (8 bytes each):
//   [s16 adjustor (at offset), u16 pad, u32 func_ptr (at offset+4)]
//
// Interface vtable entries used by small functions:
//   [0x30/0x34]: CheckForFileDescriptorLeaks(char*, int)
//   [0x58/0x5C]: DeleteFile(int, int)  -- note: uses r13-31932 for 2nd param
//   [0x68/0x6C]: FormatCard(int)
//   [0x90/0x94]: PollCards(bool)
//   [0xB0/0xB4]: IsCardFormatted(int, bool&)
//
// OptionsRecon globals:
//   _globals + 0x148 = 0x80475f14: OptionsRecon* g_pOptionsRecon
//   +0x0C: int m_freeplayUnlocked

#include "save/simsmemcardwrap.h"

// External globals (SDA-relative via r13)
extern void* g_pMemCardInterface;     // r13 - 0x98F0 (-26384)
extern int g_deleteFileParam;         // r13 - 0x8344 (-31932) -- used by DeleteFile

// External global pointer to OptionsRecon
extern void* g_pOptionsRecon;         // at 0x80475f14 (_globals + 0x148)

// External functions
extern "C" int GetTotalSaveGameSize();
extern void OptionsRecon_PreservePreferences(void* opts);
extern void OptionsRecon_RestorePreferences(void* opts);
extern int OptionsRecon_ReadIn(void* opts, int slot);

// ============================================================================
// CheckForFileDescriptorLeaks(char*, int) @ 0x80074de0, 64 bytes
// Calls vtable[0x30/0x34] on the platform interface with (filename, fd) args
// ============================================================================
// NON_MATCHING: GCC vtable dispatch codegen differs from SN
void CheckForFileDescriptorLeaks(char* filename, int fd) {
    void* iface = g_pMemCardInterface;
    void** vtable = *(void***)iface;
    s16 adjustor = *(s16*)((char*)vtable + 0x30);
    typedef void (*Func)(void*, char*, int);
    Func func = (Func)(*(u32*)((char*)vtable + 0x34));
    void* adjusted = (void*)((char*)iface + adjustor);
    func(adjusted, filename, fd);
}

// MATCHING
// InvalidatePS2SavedGame(int) @ 0x80074e20, 8 bytes
// li r3,1; blr -- always returns 1 (PS2-specific, stub on GC)
int InvalidatePS2SavedGame(int slot) {
    return 1;
}

// ============================================================================
// IsConfigFileValid(int, OptionsRecon&) @ 0x80074e28, 56 bytes
// Calls OptionsRecon::ReadIn(slot), then returns !result (inverted boolean)
// Original uses: xori r3,r3,1; subfic r0,r3,0; adde r3,r0,r3
// This is the "bool to int" idiom: converts non-zero to 1
// ============================================================================
// NON_MATCHING: GCC bool conversion idiom differs
int IsConfigFileValid(int slot, OptionsRecon& options) {
    int result = OptionsRecon_ReadIn(&options, slot);
    return result ? 0 : 1;
}

// ============================================================================
// SimsMemCardWrap::GetSpaceRequiredForSave(void) @ 0x800756bc, 32 bytes
// Tail-calls GetTotalSaveGameSize()
// ============================================================================
// NON_MATCHING: GCC may tail-call optimize differently
int SimsMemCardWrap::GetSpaceRequiredForSave() {
    return GetTotalSaveGameSize();
}

// ============================================================================
// SimsMemCardWrap::PollCards(bool) @ 0x80074f7c, 60 bytes
// Calls vtable[0x90/0x94] on platform interface
// ============================================================================
// NON_MATCHING: GCC vtable dispatch codegen differs
int SimsMemCardWrap::PollCards(bool force) {
    void* iface = g_pMemCardInterface;
    void** vtable = *(void***)iface;
    s16 adjustor = *(s16*)((char*)vtable + 0x90);
    typedef int (*Func)(void*, bool);
    Func func = (Func)(*(u32*)((char*)vtable + 0x94));
    void* adjusted = (void*)((char*)iface + adjustor);
    return func(adjusted, force);
}

// ============================================================================
// SimsMemCardWrap::IsCardFormatted(int, bool&) @ 0x800750a8, 64 bytes
// Calls vtable[0xB0/0xB4] on platform interface
// ============================================================================
// NON_MATCHING: GCC vtable dispatch codegen differs
int SimsMemCardWrap::IsCardFormatted(int slot, bool& result) {
    void* iface = g_pMemCardInterface;
    void** vtable = *(void***)iface;
    s16 adjustor = *(s16*)((char*)vtable + 0xB0);
    typedef int (*Func)(void*, int, bool&);
    Func func = (Func)(*(u32*)((char*)vtable + 0xB4));
    void* adjusted = (void*)((char*)iface + adjustor);
    return func(adjusted, slot, result);
}

// ============================================================================
// SimsMemCardWrap::PreservePrefs(void) @ 0x800755dc, 40 bytes
// Loads g_pOptionsRecon and calls OptionsRecon::PreservePreferences
// ============================================================================
// NON_MATCHING: GCC codegen differs
void SimsMemCardWrap::PreservePrefs() {
    OptionsRecon_PreservePreferences(g_pOptionsRecon);
}

// ============================================================================
// SimsMemCardWrap::RestorePrefs(void) @ 0x80075604, 40 bytes
// Loads g_pOptionsRecon and calls OptionsRecon::RestorePreferences
// ============================================================================
// NON_MATCHING: GCC codegen differs
void SimsMemCardWrap::RestorePrefs() {
    OptionsRecon_RestorePreferences(g_pOptionsRecon);
}

// NON_MATCHING: GCC uses r9 for intermediate; original uses r9+r11 (different register allocation)
// SimsMemCardWrap::IsFreeplayUnlocked(void) @ 0x8007562c, 16 bytes
// Loads g_pOptionsRecon, returns int at offset 0x0C
int SimsMemCardWrap::IsFreeplayUnlocked() {
    return *(int*)((char*)g_pOptionsRecon + 0x0C);
}

// ============================================================================
// SimsMemCardWrap::FormatCard(int) @ 0x8007563c, 60 bytes
// Calls vtable[0x68/0x6C] on platform interface
// ============================================================================
// NON_MATCHING: GCC vtable dispatch codegen differs
int SimsMemCardWrap::FormatCard(int slot) {
    void* iface = g_pMemCardInterface;
    void** vtable = *(void***)iface;
    s16 adjustor = *(s16*)((char*)vtable + 0x68);
    typedef int (*Func)(void*, int);
    Func func = (Func)(*(u32*)((char*)vtable + 0x6C));
    void* adjusted = (void*)((char*)iface + adjustor);
    return func(adjusted, slot);
}

// ============================================================================
// SimsMemCardWrap::DeleteFile(int, int) @ 0x80075678, 64 bytes
// Calls vtable[0x58/0x5C] on platform interface
// Note: uses g_deleteFileParam (r13 - 31932) as the second arg,
//   and the first parameter (slot) as third arg
// ============================================================================
// NON_MATCHING: GCC vtable dispatch + arg reordering differs
int SimsMemCardWrap::DeleteFile(int slot, int index) {
    void* iface = g_pMemCardInterface;
    void** vtable = *(void***)iface;
    s16 adjustor = *(s16*)((char*)vtable + 0x58);
    typedef int (*Func)(void*, int, int);
    Func func = (Func)(*(u32*)((char*)vtable + 0x5C));
    void* adjusted = (void*)((char*)iface + adjustor);
    return func(adjusted, g_deleteFileParam, slot);
}

// MATCHING
// SimsMemCardWrap::XboxOnNoMemory(void) @ 0x800756b8, 4 bytes
// blr -- empty stub (Xbox-specific, no-op on GC)
void SimsMemCardWrap::XboxOnNoMemory() {
}

// MATCHING
// GetSpaceRequiredForPs2HDDSave(void) @ 0x80075b08, 8 bytes
// li r3,0; blr -- always returns 0 (PS2-specific, stub on GC)
int GetSpaceRequiredForPs2HDDSave() {
    return 0;
}
