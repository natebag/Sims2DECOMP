#ifndef SIMSMEMCARDWRAP_H
#define SIMSMEMCARDWRAP_H

#include "types.h"

// Forward declarations
class OptionsRecon;

// OptionsRecon partial layout (from Get*Volume / PreservePrefs / etc):
//   +0x0C: int m_freeplayUnlocked
//   +0x1C: s8 m_sfxVolume
//   +0x1D: s8 m_musicVolume
//   +0x28: s8 m_voxVolume
//   +0x29: s8 m_ambientVolume

// SimsMemCardWrap - memory card / save system wrapper
// Object file: simsmemcardwrap.obj
//
// Uses a vtable-based interface through a global pointer (r13 - 26384)
// Most functions delegate to the platform-specific implementation via vtable calls.
//
// The vtable interface has entries for:
//   vtable[0x30/0x34]: CheckForFileDescriptorLeaks (offset 48/52)
//   vtable[0x58/0x5C]: DeleteFile (offset 88/92)
//   vtable[0x68/0x6C]: FormatCard (offset 104/108)
//   vtable[0x90/0x94]: PollCards (offset 144/148)
//   vtable[0xB0/0xB4]: IsCardFormatted (offset 176/180)
class SimsMemCardWrap {
public:
    void Init();
    void InitPolling();

    int GetSpaceRequiredForSave();

    int PollCards(bool force);
    int IsCardInSlot(int slot, bool& result);
    int IsPolledCardInSlot(int slot, bool& result);
    int IsWrongDevice(int slot, bool& result);
    int IsCardFormatted(int slot, bool& result);
    int IsCardCorrupted(int slot, bool& result);
    int IsCardDamaged(int slot, bool& result);
    int HasSavedGame(int slot, bool& result, int index);
    int HasValidSavedGame(int slot, bool& result, int index);
    int HasInvalidGame(int slot, bool& result, int index);
    int HasSpaceForSave(int slot, bool& result, unsigned int* spaceNeeded);

    int CanBeUsed(int slot, bool& result, int index);
    int IsDifferentCard(int slot, bool& result);

    int LoadConfigFile(int slot);
    int SaveConfigFile(int slot);

    void PreservePrefs();
    void RestorePrefs();

    int IsFreeplayUnlocked();

    int FormatCard(int slot);
    int DeleteFile(int slot, int index);

    void XboxOnNoMemory();

    int SaveNewGame(int slot);
    int PreloadGame(int slot);
    int LoadGame(int slot, int index);
    int SaveGame(int slot, bool flag1, bool flag2, int index);
    int LoadHouse(int slot);
    int ReloadHouseAndGlobals(int slot, int index);
    int SaveHouseAndGlobals(int slot, int index);
};

// Free functions
void CheckForFileDescriptorLeaks(char* filename, int fd);
int InvalidatePS2SavedGame(int slot);
int IsConfigFileValid(int slot, OptionsRecon& options);
int GetSpaceRequiredForPs2HDDSave();

#endif // SIMSMEMCARDWRAP_H
