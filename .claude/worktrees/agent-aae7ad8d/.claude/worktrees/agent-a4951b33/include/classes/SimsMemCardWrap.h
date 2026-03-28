#ifndef SIMSMEMCARDWRAP_H
#define SIMSMEMCARDWRAP_H

#include "types.h"

// SimsMemCardWrap - struct layout extracted from assembly analysis
// Estimated minimum size: 0xCC (204 bytes)
// 4 known fields (1 named), 62 methods

class SimsMemCardWrap {
public:
    // Static members (from map file)
    // static ??? saveFileName;

    // Methods
    void Init(void);  // 0x80164718 (316B)
    /* ? */ GetSpaceRequiredForSave(void);  // 0x80165D98 (60B)
    void InitPolling(void);  // 0x80164854 (248B)
    bool IsCardInSlot(int, bool &);  // 0x80164B18 (236B)
    void PollCards(bool);  // 0x8016494C (224B)
    bool IsPolledCardInSlot(int, bool &);  // 0x80164A2C (236B)
    bool IsWrongDevice(int, bool &);  // 0x80164C04 (236B)
    bool IsCardFormatted(int, bool &);  // 0x80164CF0 (232B)
    bool IsCardCorrupted(int, bool &);  // 0x80164DD8 (280B)
    bool IsCardDamaged(int, bool &);  // 0x80164EF0 (300B)
    bool HasSavedGame(int, bool &, int);  // 0x8016501C (252B)
    bool HasValidSavedGame(int, bool &, int);  // 0x80165118 (448B)
    bool HasInvalidGame(int, bool &, int);  // 0x801652D8 (132B)
    bool HasSpaceForSave(int, bool &, unsigned int *);  // 0x8016535C (340B)
    bool CanBeUsed(int, bool &, int);  // 0x801654B0 (560B)
    bool IsDifferentCard(int, bool &);  // 0x801656E0 (284B)
    void LoadConfigFile(int);  // 0x801657FC (208B)
    void SaveConfigFile(int);  // 0x801658CC (220B)
    void PreservePrefs(void);  // 0x801659A8 (168B)
    void RestorePrefs(void);  // 0x80165A50 (168B)
    bool IsFreeplayUnlocked(void);  // 0x80165AF8 (176B)
    void FormatCard(int);  // 0x80165BA8 (232B)
    void DeleteFile(int, int);  // 0x80165C90 (236B)
    void XboxOnNoMemory(void);  // 0x80165D7C (28B)
    void SaveNewGame(int);  // 0x80165DD4 (420B)
    void PreloadGame(int);  // 0x80165F78 (228B)
    void LoadGame(int, int);  // 0x8016605C (472B)
    void SaveGame(int, bool, bool, int);  // 0x80166234 (776B)
    void LoadHouse(int);  // 0x8016653C (484B)
    void ReloadHouseAndGlobals(int, int);  // 0x80166720 (248B)
    void SaveHouseAndGlobals(int, int);  // 0x80166818 (232B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [W] - vtable pointer (HasSpaceForSave)
    u32 m_field_004;  // 0x004 [R] (Init, PreloadGame)
    u8 _pad_008[0xB0];  // 0x008
    s16 m_field_0B8;  // 0x0B8 [R] (Init)
    u8 _pad_0BA[0xE];  // 0x0BA
    u32 m_field_0C8;  // 0x0C8 [R] (SaveGame)
};

#endif // SIMSMEMCARDWRAP_H
