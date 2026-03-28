#ifndef SAVEGAMETARGET_H
#define SAVEGAMETARGET_H

#include "types.h"

// SaveGameTarget - struct layout extracted from assembly analysis
// Estimated minimum size: 0x168 (360 bytes)
// 55 known fields (1 named), 62 methods

class SaveGameTarget {
public:
    // Constructors / Destructors
    SaveGameTarget(M2MTarget *, int, int)  // 0x804B9310
    ~SaveGameTarget(void);  // 0x804B97EC

    // Methods
    /* ? */ GetDevice(void);  // 0x804BF710 (68B)
    void SelectionCallback(int);  // 0x804B9898 (1376B)
    void ZeroInputCallback(void);  // 0x804B9DF8 (576B)
    void Update(void);  // 0x804BA038 (1772B)
    void SpawnMemCardRemovedDialog(void);  // 0x804BD320 (556B)
    void SpawnCheckingDialog(void);  // 0x804BAF10 (508B)
    void PerformMemoryCardChecks(void);  // 0x804BA79C (1908B)
    void SpawnFormatDecideDialog(void);  // 0x804BB898 (548B)
    void SpawnFormatConfirmDialog(void);  // 0x804BBABC (536B)
    void SpawnFormattingDialog(void);  // 0x804BBCD4 (424B)
    void SpawnFormatSuccessDialog(void);  // 0x804BC2AC (492B)
    void SpawnFormatFailDialog(void);  // 0x804BC094 (536B)
    void SpawnFormatCancelDialog(void);  // 0x804BBE7C (536B)
    void SpawnSaveFailedDialog(void);  // 0x804BD0D8 (584B)
    void SpawnSaveConfirmDialog(void);  // 0x804BCAF4 (632B)
    void SpawnSavingDialog(void);  // 0x804BCD6C (500B)
    void PerformSaveGame(void);  // 0x804BD54C (2684B)
    void SpawnSaveSucceededDialog(void);  // 0x804BCF60 (376B)
    void Hide(void);  // 0x804BA724 (68B)
    /* ? */ GetResult(void);  // 0x804BA768 (52B)
    void SpawnWrongDeviceDialog(void);  // 0x804BB3AC (548B)
    void SpawnCardDamagedDialog(void);  // 0x804BB5D0 (712B)
    void SpawnCardCorruptDialog(void);  // 0x804BB10C (672B)
    void SpawnOverwriteDialog(void);  // 0x804BC880 (628B)
    void SpawnNoSpaceDialog(SaveGameTarget::NoSpaceType);  // 0x804BC498 (1000B)
    /* ? */ GetPlayerNum(void);  // 0x804BF754 (68B)
    void BGCall_SaveGame(void);  // 0x804BDFC8 (140B)
    void BGExec_SaveGame(void *);  // 0x804BE054 (224B)
    /* ? */ GetSaveGameID(void);  // 0x804BF798 (68B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [R/W] - vtable pointer (PerformSaveGame, SaveGameTarget, ~SaveGameTarget)
    f32 m_field_004;  // 0x004 [R/W] (SaveGameTarget, Update, ~SaveGameTarget)
    u32 m_field_008;  // 0x008 [R/W] (SaveGameTarget, ~SaveGameTarget)
    u32 m_field_00C;  // 0x00C [R/W] (SaveGameTarget, ~SaveGameTarget)
    u32 m_field_010;  // 0x010 [R/W] (SaveGameTarget, ~SaveGameTarget)
    u32 m_field_014;  // 0x014 [R/W] (SaveGameTarget, ~SaveGameTarget)
    u32 m_field_018;  // 0x018 [R/W] (SaveGameTarget, ~SaveGameTarget)
    u32 m_field_01C;  // 0x01C [R/W] (SaveGameTarget, ~SaveGameTarget)
    u32 m_field_020;  // 0x020 [R/W] (SaveGameTarget, ~SaveGameTarget)
    u32 m_field_024;  // 0x024 [R/W] (SaveGameTarget, ~SaveGameTarget)
    u32 m_field_028;  // 0x028 [W] (SaveGameTarget)
    u8 _pad_02C[0xC];  // 0x02C
    u32 m_field_038;  // 0x038 [W] (SaveGameTarget)
    u8 _pad_03C[0xC];  // 0x03C
    u32 m_field_048;  // 0x048 [W] (SaveGameTarget)
    u8 _pad_04C[0xC];  // 0x04C
    u32 m_field_058;  // 0x058 [R/W] (SaveGameTarget, ~SaveGameTarget)
    u8 _pad_05C[0xC];  // 0x05C
    u32 m_field_068;  // 0x068 [R/W] (SaveGameTarget, ~SaveGameTarget)
    u8 _pad_06C[0xC];  // 0x06C
    u32 m_field_078;  // 0x078 [W] (SaveGameTarget)
    u32 m_field_07C;  // 0x07C [R/W] (SaveGameTarget, ~SaveGameTarget)
    u32 m_field_080;  // 0x080 [W] (SaveGameTarget, ~SaveGameTarget)
    u32 m_field_084;  // 0x084 [W] (SaveGameTarget, SpawnCardCorruptDialog, SpawnCardDamagedDialog, ...)
    u32 m_field_088;  // 0x088 [W] (SpawnCardCorruptDialog, SpawnCardDamagedDialog, SpawnCheckingDialog, ...)
    u32 m_field_08C;  // 0x08C [W] (SpawnCardCorruptDialog, SpawnCardDamagedDialog, SpawnCheckingDialog, ...)
    u32 m_field_090;  // 0x090 [W] (SpawnCardCorruptDialog, SpawnCardDamagedDialog, SpawnCheckingDialog, ...)
    u32 m_field_094;  // 0x094 [W] (SpawnCardCorruptDialog, SpawnCardDamagedDialog, SpawnCheckingDialog, ...)
    u32 m_field_098;  // 0x098 [W] (SpawnCardCorruptDialog, SpawnCardDamagedDialog, SpawnCheckingDialog, ...)
    u8 _pad_09C[4];  // 0x09C
    u32 m_field_0A0;  // 0x0A0 [W] (SpawnCardCorruptDialog, SpawnCardDamagedDialog, SpawnCheckingDialog, ...)
    u8 _pad_0A4[0x1C];  // 0x0A4
    u32 m_field_0C0;  // 0x0C0 [W] (SpawnCardCorruptDialog, SpawnCardDamagedDialog, SpawnCheckingDialog, ...)
    u8 _pad_0C4[8];  // 0x0C4
    u16 m_field_0CC;  // 0x0CC [W] (SpawnCardCorruptDialog, SpawnCardDamagedDialog, SpawnCheckingDialog, ...)
    u16 m_field_0CE;  // 0x0CE [W] (SpawnCardCorruptDialog, SpawnCardDamagedDialog, SpawnCheckingDialog, ...)
    u32 m_field_0D0;  // 0x0D0 [W] (SpawnCardCorruptDialog, SpawnCardDamagedDialog, SpawnFormatCancelDialog, ...)
    u32 m_field_0D4;  // 0x0D4 [W] (SaveGameTarget)
    u8 _pad_0D8[0xC];  // 0x0D8
    u32 m_field_0E4;  // 0x0E4 [W] (SaveGameTarget)
    u8 _pad_0E8[0xC];  // 0x0E8
    u32 m_field_0F4;  // 0x0F4 [W] (SaveGameTarget)
    u8 _pad_0F8[0xC];  // 0x0F8
    u32 m_field_104;  // 0x104 [W] (SaveGameTarget)
    u32 m_field_108;  // 0x108 [W] (SaveGameTarget, ~SaveGameTarget)
    u8 _pad_10C[4];  // 0x10C
    u32 m_field_110;  // 0x110 [R/W] (PerformMemoryCardChecks, PerformSaveGame, SaveGameTarget, ...)
    u32 m_field_114;  // 0x114 [W] (SaveGameTarget, ~SaveGameTarget)
    u32 m_field_118;  // 0x118 [R/W] (PerformSaveGame, SaveGameTarget, SpawnCardCorruptDialog, ...)
    u32 m_field_11C;  // 0x11C [R/W] (SaveGameTarget, SelectionCallback, Update)
    u32 m_field_120;  // 0x120 [R/W] (SaveGameTarget, Update)
    u8 _pad_124[4];  // 0x124
    u32 m_field_128;  // 0x128 [R/W] (PerformMemoryCardChecks, PerformSaveGame, SaveGameTarget, ...)
    u32 m_field_12C;  // 0x12C [R/W] (PerformMemoryCardChecks, PerformSaveGame, SaveGameTarget, ...)
    u32 m_field_130;  // 0x130 [R/W] (PerformMemoryCardChecks, PerformSaveGame, SaveGameTarget, ...)
    u32 m_field_134;  // 0x134 [R/W] (PerformSaveGame, SaveGameTarget, Update)
    u32 m_field_138;  // 0x138 [R/W] (PerformMemoryCardChecks, PerformSaveGame, SaveGameTarget, ...)
    u32 m_field_13C;  // 0x13C [R/W] (PerformSaveGame, SaveGameTarget)
    u32 m_field_140;  // 0x140 [R/W] (PerformSaveGame, SaveGameTarget, Update)
    u32 m_field_144;  // 0x144 [R/W] (PerformSaveGame, SaveGameTarget)
    u32 m_field_148;  // 0x148 [R/W] (PerformSaveGame, SaveGameTarget)
    u32 m_field_14C;  // 0x14C [W] (SaveGameTarget, Update, ZeroInputCallback)
    u32 m_field_150;  // 0x150 [W] (SaveGameTarget, Update)
    u32 m_field_154;  // 0x154 [R/W] (PerformSaveGame, SaveGameTarget, Update)
    u32 m_field_158;  // 0x158 [R/W] (PerformSaveGame)
    u32 m_field_15C;  // 0x15C [R/W] (PerformSaveGame)
    f32 m_field_160;  // 0x160 [W] (SaveGameTarget)
    f32 m_field_164;  // 0x164 [W] (SaveGameTarget)
};

#endif // SAVEGAMETARGET_H
