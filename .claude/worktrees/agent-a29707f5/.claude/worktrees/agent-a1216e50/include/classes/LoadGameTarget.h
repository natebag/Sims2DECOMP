#ifndef LOADGAMETARGET_H
#define LOADGAMETARGET_H

#include "types.h"

// LoadGameTarget - struct layout extracted from assembly analysis
// Estimated minimum size: 0x14C (332 bytes)
// 50 known fields (1 named), 70 methods

class LoadGameTarget {
public:
    // Constructors / Destructors
    LoadGameTarget(M2MTarget *, int, int)  // 0x804B22DC
    ~LoadGameTarget(void);  // 0x804B277C

    // Methods
    /* ? */ GetDevice(void);  // 0x804B7FE4 (68B)
    void SelectionCallback(int);  // 0x804B2818 (1480B)
    void SpawnCheckingDialog(void);  // 0x804B3F18 (508B)
    void ZeroInputCallback(void);  // 0x804B2DE0 (272B)
    void Update(void);  // 0x804B2EF0 (1612B)
    void SpawnMemCardRemovedDialog(void);  // 0x804B5940 (544B)
    void PerformMemoryCardChecks(void);  // 0x804B35A0 (1872B)
    void SpawnLoadConfirmDialog(void);  // 0x804B5024 (628B)
    void SpawnLoadingDialog(void);  // 0x804B5298 (500B)
    void BackgroundPerformLoad(void);  // 0x804B66A8 (692B)
    void SpawnLoadSucceededDialog(void);  // 0x804B548C (376B)
    void SpawnLoadFailedDialog(void);  // 0x804B5604 (828B)
    void SpawnFormatDecideDialog(void);  // 0x804B5CD8 (408B)
    void SpawnFormatConfirmDialog(void);  // 0x804B5E70 (408B)
    void SpawnFormattingDialog(void);  // 0x804B6008 (296B)
    void SpawnFormatCancelDialog(void);  // 0x804B6130 (408B)
    void SpawnFormatFailDialog(void);  // 0x804B62C8 (628B)
    void SpawnFormatSuccessDialog(void);  // 0x804B653C (364B)
    /* ? */ GetResult(void);  // 0x804B353C (52B)
    void ImportLoad(NghResFile::SectionID, NghResFile::SaveRecord &);  // 0x804B3570 (48B)
    void SpawnWrongDeviceDialog(void);  // 0x804B4114 (768B)
    void SpawnCardDamagedDialog(void);  // 0x804B4414 (848B)
    void SpawnCardCorruptDialog(void);  // 0x804B4764 (828B)
    void SpawnNoSaveDialog(void);  // 0x804B4DDC (584B)
    void SpawnWrongSaveDialog(void);  // 0x804B4AA0 (828B)
    void SpawnSameCardDialog(void);  // 0x804B5B60 (376B)
    void PerformLoad(void);  // 0x804B3CF0 (552B)
    void ImportSave(NghResFile::SectionID, NghResFile::SaveRecord &);  // 0x804B7EA4 (160B)
    void ImportSaveComplete(NghResFile::SectionID, NghResFile::SaveRecord &);  // 0x804B7F44 (160B)
    /* ? */ GetPlayerNum(void);  // 0x804B8028 (68B)
    void BGCall_PerformLoad(void);  // 0x804B695C (140B)
    void BGExec_PerformLoad(void *);  // 0x804B69E8 (184B)
    /* ? */ GetSaveGameID(void);  // 0x804B806C (68B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [R/W] - vtable pointer (LoadGameTarget, ~LoadGameTarget)
    u32 m_field_004;  // 0x004 [R/W] (LoadGameTarget, ~LoadGameTarget)
    u32 m_field_008;  // 0x008 [R/W] (LoadGameTarget, ~LoadGameTarget)
    u32 m_field_00C;  // 0x00C [R/W] (LoadGameTarget, ~LoadGameTarget)
    u32 m_field_010;  // 0x010 [R/W] (LoadGameTarget, ~LoadGameTarget)
    u32 m_field_014;  // 0x014 [R/W] (LoadGameTarget, ~LoadGameTarget)
    u32 m_field_018;  // 0x018 [R/W] (LoadGameTarget, ~LoadGameTarget)
    u32 m_field_01C;  // 0x01C [R/W] (LoadGameTarget, ~LoadGameTarget)
    u32 m_field_020;  // 0x020 [R/W] (LoadGameTarget, ~LoadGameTarget)
    u32 m_field_024;  // 0x024 [R/W] (LoadGameTarget, ~LoadGameTarget)
    u32 m_field_028;  // 0x028 [W] (LoadGameTarget)
    u8 _pad_02C[0xC];  // 0x02C
    u32 m_field_038;  // 0x038 [W] (LoadGameTarget)
    u8 _pad_03C[0xC];  // 0x03C
    u32 m_field_048;  // 0x048 [W] (LoadGameTarget)
    u8 _pad_04C[0xC];  // 0x04C
    u32 m_field_058;  // 0x058 [R/W] (LoadGameTarget, ~LoadGameTarget)
    u8 _pad_05C[0xC];  // 0x05C
    u32 m_field_068;  // 0x068 [R/W] (LoadGameTarget, ~LoadGameTarget)
    u8 _pad_06C[0xC];  // 0x06C
    u32 m_field_078;  // 0x078 [W] (LoadGameTarget)
    u32 m_field_07C;  // 0x07C [R/W] (LoadGameTarget, ~LoadGameTarget)
    u32 m_field_080;  // 0x080 [W] (LoadGameTarget, ~LoadGameTarget)
    u32 m_field_084;  // 0x084 [W] (LoadGameTarget, SpawnCardCorruptDialog, SpawnCardDamagedDialog, ...)
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
    u32 m_field_0D4;  // 0x0D4 [W] (LoadGameTarget)
    u8 _pad_0D8[0xC];  // 0x0D8
    u32 m_field_0E4;  // 0x0E4 [W] (LoadGameTarget)
    u8 _pad_0E8[0xC];  // 0x0E8
    u32 m_field_0F4;  // 0x0F4 [W] (LoadGameTarget)
    u8 _pad_0F8[0xC];  // 0x0F8
    u32 m_field_104;  // 0x104 [W] (LoadGameTarget)
    u32 m_field_108;  // 0x108 [W] (LoadGameTarget, ~LoadGameTarget)
    u32 m_field_10C;  // 0x10C [R/W] (BackgroundPerformLoad, LoadGameTarget, PerformMemoryCardChecks, ...)
    u8 _pad_110[4];  // 0x110
    u32 m_field_114;  // 0x114 [W] (LoadGameTarget, ~LoadGameTarget)
    u32 m_field_118;  // 0x118 [R/W] (BackgroundPerformLoad, LoadGameTarget, SpawnCardCorruptDialog, ...)
    u32 m_field_11C;  // 0x11C [R/W] (LoadGameTarget, SelectionCallback, Update)
    u32 m_field_120;  // 0x120 [R/W] (LoadGameTarget, Update)
    u32 m_field_124;  // 0x124 [R/W] (LoadGameTarget, Update)
    u32 m_field_128;  // 0x128 [R/W] (LoadGameTarget, PerformLoad, PerformMemoryCardChecks, ...)
    u8 m_field_12B;  // 0x12B [R] (PerformLoad)
    u32 m_field_12C;  // 0x12C [R/W] (BackgroundPerformLoad, LoadGameTarget, PerformMemoryCardChecks, ...)
    u32 m_field_130;  // 0x130 [R/W] (BackgroundPerformLoad, LoadGameTarget, SelectionCallback, ...)
    u32 m_field_134;  // 0x134 [R/W] (BackgroundPerformLoad, LoadGameTarget, Update)
    u32 m_field_138;  // 0x138 [R/W] (LoadGameTarget, PerformLoad, PerformMemoryCardChecks, ...)
    u32 m_field_13C;  // 0x13C [W] (LoadGameTarget)
    u32 m_field_140;  // 0x140 [R/W] (LoadGameTarget, SelectionCallback, Update)
    u32 m_field_144;  // 0x144 [R/W] (BackgroundPerformLoad, LoadGameTarget, PerformLoad)
    u32 m_field_148;  // 0x148 [R/W] (BackgroundPerformLoad)
};

#endif // LOADGAMETARGET_H
