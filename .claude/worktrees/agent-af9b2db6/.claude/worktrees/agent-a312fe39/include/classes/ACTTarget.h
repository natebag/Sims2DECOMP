#ifndef ACTTARGET_H
#define ACTTARGET_H

#include "types.h"

// ACTTarget - struct layout extracted from assembly analysis
// Estimated minimum size: 0x658 (1624 bytes)
// 107 known fields (15 named), 52 methods

class ACTTarget {
public:
    // Constructors / Destructors
    ACTTarget(int)  // 0x804E6A38
    ~ACTTarget(void);  // 0x804E8028

    // Methods
    void SetVariable(char *, char *);  // 0x804E81E4 (712B)
    /* ? */ GetVariable(char *);  // 0x804E84AC (340B)
    /* ? */ GetLocalizable(char *);  // 0x804E8600 (600B)
    void Update(void);  // 0x804E8858 (1156B)
    void HideActionQueue(void);  // 0x804E8D04 (40B)
    void ShowActionQueue(void);  // 0x804E8CDC (40B)
    /* ? */ GetRecord(void);  // 0x804E9A90 (188B)
    void PlaceItem(ACTTarget::ACTRecord *, int, Interaction *, int, cXPerson *, BString2 &, unsigned int, ERShader *, unsigned int);  // 0x804E9264 (932B)
    void UpdateActionQueue(void);  // 0x804E8D2C (684B)
    void UpdateCancelModeWidgets(void);  // 0x804EA140 (288B)
    void ExitCancelMode(void);  // 0x804EA260 (144B)
    bool IsActionQueueActive(void);  // 0x804E8FD8 (44B)
    void AddAction(int, Interaction *, BString2 &, unsigned int, ERShader *, unsigned int);  // 0x804E9004 (608B)
    void DebugListValidation(void);  // 0x804E9C44 (32B)
    void ReOrderActionQueue(void);  // 0x804E9B4C (248B)
    void RemoveAction(int, Interaction *);  // 0x804E9608 (884B)
    void RemoveAllActions(int);  // 0x804E997C (232B)
    /* ? */ GetInteractionFromID(int);  // 0x804E9C64 (304B)
    bool IsActionQueueAvailable(int);  // 0x804E9A64 (44B)
    void MoveCancelCursorUp(void);  // 0x804E9D94 (124B)
    void MoveCancelCursorDown(void);  // 0x804E9E10 (104B)
    bool CancelModeEnabled(bool);  // 0x804E9E78 (240B)
    bool CancelCurrentObject(void);  // 0x804E9F68 (472B)
    bool CancellingLastObject(void);  // 0x804EA2F0 (168B)

    // ---- Field Layout (from assembly analysis) ----
    u16 m_localizable;  // 0x000 [R/W] (ACTTarget, AddAction, GetLocalizable, ...)
    u8 _pad_002[2];  // 0x002
    u16 m_variable;  // 0x004 [R/W] (ACTTarget, AddAction, CancelCurrentObject, ...)
    u8 m_variable_006;  // 0x006 [W] (GetVariable)
    u8 _pad_007[1];  // 0x007
    u32 m_field_008;  // 0x008 [R/W] (ACTTarget, AddAction, Update, ...)
    u32 m_field_00C;  // 0x00C [R/W] (ACTTarget, ~ACTTarget)
    u32 m_field_010;  // 0x010 [R/W] (ACTTarget, AddAction, Update, ...)
    u32 m_field_014;  // 0x014 [R/W] (ACTTarget, AddAction, Update, ...)
    u32 m_field_018;  // 0x018 [R/W] (ACTTarget, AddAction, Update, ...)
    u32 m_field_01C;  // 0x01C [R/W] (ACTTarget, AddAction, PlaceItem, ...)
    u32 m_field_020;  // 0x020 [R/W] (ACTTarget, ~ACTTarget)
    u32 m_field_024;  // 0x024 [R/W] (ACTTarget, ~ACTTarget)
    u32 m_field_028;  // 0x028 [W] (ACTTarget)
    u8 _pad_02C[0xC];  // 0x02C
    u32 m_interactionFromID;  // 0x038 [R/W] (ACTTarget, AddAction, GetInteractionFromID)
    u32 m_bCancelCurrentObject;  // 0x03C [R] (CancelCurrentObject)
    u8 _pad_040[4];  // 0x040
    u32 m_field_044;  // 0x044 [R] (AddAction)
    u32 m_field_048;  // 0x048 [W] (ACTTarget)
    u8 _pad_04C[0xC];  // 0x04C
    u32 m_field_058;  // 0x058 [R/W] (ACTTarget, ~ACTTarget)
    u8 _pad_05C[0xC];  // 0x05C
    u32 m_field_068;  // 0x068 [R/W] (ACTTarget, ~ACTTarget)
    u8 _pad_06C[0xC];  // 0x06C
    u32 m_field_078;  // 0x078 [W] (ACTTarget)
    u32 m_field_07C;  // 0x07C [R/W] (ACTTarget, PlaceItem, ~ACTTarget)
    u32 m_field_080;  // 0x080 [W] (ACTTarget, ~ACTTarget)
    u8 _pad_084[0x38];  // 0x084
    f32 m_field_0BC;  // 0x0BC [R/W] (ACTTarget)
    u8 _pad_0C0[4];  // 0x0C0
    f32 m_field_0C4;  // 0x0C4 [R/W] (ACTTarget)
    u8 _pad_0C8[4];  // 0x0C8
    u32 m_variable_0CC;  // 0x0CC [R/W] (ACTTarget, GetVariable, Update)
    u32 m_variable_0D0;  // 0x0D0 [R/W] (ACTTarget, SetVariable, Update)
    u32 m_variable_0D4;  // 0x0D4 [R/W] (ACTTarget, SetVariable, Update)
    u32 m_bCancelModeEnabled;  // 0x0D8 [R/W] (ACTTarget, CancelModeEnabled, Update)
    u32 m_interactionFromID_0DC;  // 0x0DC [R/W] (ACTTarget, AddAction, CancelModeEnabled, ...)
    u32 m_field_0E0;  // 0x0E0 [R/W] (ACTTarget, Update)
    u32 m_bCancelModeEnabled_0E4;  // 0x0E4 [R/W] (ACTTarget, AddAction, CancelModeEnabled, ...)
    u32 m_bCancellingLastObject;  // 0x0E8 [R/W] (ACTTarget, CancellingLastObject, PlaceItem, ...)
    u8 _pad_0EC[0x24];  // 0x0EC
    u32 m_field_110;  // 0x110 [W] (ACTTarget)
    u32 m_field_114;  // 0x114 [W] (ACTTarget)
    u32 m_field_118;  // 0x118 [W] (ACTTarget)
    u32 m_field_11C;  // 0x11C [W] (ACTTarget)
    u8 _pad_120[0x3C];  // 0x120
    u32 m_field_15C;  // 0x15C [W] (ACTTarget)
    u32 m_field_160;  // 0x160 [W] (ACTTarget)
    u32 m_field_164;  // 0x164 [W] (ACTTarget)
    u32 m_field_168;  // 0x168 [W] (ACTTarget)
    u8 _pad_16C[0x3C];  // 0x16C
    u32 m_field_1A8;  // 0x1A8 [W] (ACTTarget)
    u32 m_field_1AC;  // 0x1AC [W] (ACTTarget)
    u32 m_field_1B0;  // 0x1B0 [W] (ACTTarget)
    u32 m_field_1B4;  // 0x1B4 [W] (ACTTarget)
    u8 _pad_1B8[0x3C];  // 0x1B8
    u32 m_field_1F4;  // 0x1F4 [W] (ACTTarget)
    u32 m_field_1F8;  // 0x1F8 [W] (ACTTarget)
    u32 m_field_1FC;  // 0x1FC [W] (ACTTarget)
    u32 m_field_200;  // 0x200 [W] (ACTTarget)
    u8 _pad_204[0x3C];  // 0x204
    u32 m_field_240;  // 0x240 [W] (ACTTarget)
    u32 m_field_244;  // 0x244 [W] (ACTTarget)
    u32 m_field_248;  // 0x248 [W] (ACTTarget)
    u32 m_field_24C;  // 0x24C [W] (ACTTarget)
    u8 _pad_250[0x3C];  // 0x250
    u32 m_field_28C;  // 0x28C [W] (ACTTarget)
    u32 m_field_290;  // 0x290 [W] (ACTTarget)
    u32 m_field_294;  // 0x294 [W] (ACTTarget)
    u32 m_field_298;  // 0x298 [W] (ACTTarget)
    u8 _pad_29C[0x3C];  // 0x29C
    u32 m_field_2D8;  // 0x2D8 [W] (ACTTarget)
    u32 m_field_2DC;  // 0x2DC [W] (ACTTarget)
    u32 m_field_2E0;  // 0x2E0 [W] (ACTTarget)
    u32 m_field_2E4;  // 0x2E4 [W] (ACTTarget)
    u8 _pad_2E8[0x3C];  // 0x2E8
    u32 m_field_324;  // 0x324 [W] (ACTTarget)
    u32 m_field_328;  // 0x328 [W] (ACTTarget)
    u32 m_field_32C;  // 0x32C [W] (ACTTarget)
    u32 m_field_330;  // 0x330 [W] (ACTTarget)
    u8 _pad_334[0x3C];  // 0x334
    u32 m_field_370;  // 0x370 [W] (ACTTarget)
    u32 m_field_374;  // 0x374 [W] (ACTTarget)
    u32 m_field_378;  // 0x378 [W] (ACTTarget)
    u32 m_field_37C;  // 0x37C [W] (ACTTarget)
    u8 _pad_380[0x3C];  // 0x380
    u32 m_field_3BC;  // 0x3BC [W] (ACTTarget)
    u32 m_field_3C0;  // 0x3C0 [W] (ACTTarget)
    u32 m_field_3C4;  // 0x3C4 [W] (ACTTarget)
    u32 m_field_3C8;  // 0x3C8 [W] (ACTTarget)
    u8 _pad_3CC[0x3C];  // 0x3CC
    u32 m_field_408;  // 0x408 [W] (ACTTarget)
    u32 m_field_40C;  // 0x40C [W] (ACTTarget)
    u32 m_field_410;  // 0x410 [W] (ACTTarget)
    u32 m_field_414;  // 0x414 [W] (ACTTarget)
    u8 _pad_418[0x3C];  // 0x418
    u32 m_field_454;  // 0x454 [W] (ACTTarget)
    u32 m_field_458;  // 0x458 [W] (ACTTarget)
    u32 m_field_45C;  // 0x45C [W] (ACTTarget)
    u32 m_field_460;  // 0x460 [W] (ACTTarget)
    u8 _pad_464[0x3C];  // 0x464
    u32 m_field_4A0;  // 0x4A0 [W] (ACTTarget)
    u32 m_field_4A4;  // 0x4A4 [W] (ACTTarget)
    u32 m_field_4A8;  // 0x4A8 [W] (ACTTarget)
    u32 m_field_4AC;  // 0x4AC [W] (ACTTarget)
    u8 _pad_4B0[0x3C];  // 0x4B0
    u32 m_field_4EC;  // 0x4EC [W] (ACTTarget)
    u32 m_field_4F0;  // 0x4F0 [W] (ACTTarget)
    u32 m_field_4F4;  // 0x4F4 [W] (ACTTarget)
    u32 m_field_4F8;  // 0x4F8 [W] (ACTTarget)
    u8 _pad_4FC[0x3C];  // 0x4FC
    u32 m_field_538;  // 0x538 [W] (ACTTarget)
    u32 m_field_53C;  // 0x53C [W] (ACTTarget)
    u32 m_field_540;  // 0x540 [W] (ACTTarget)
    u32 m_field_544;  // 0x544 [W] (ACTTarget)
    u8 _pad_548[0x3C];  // 0x548
    u32 m_field_584;  // 0x584 [W] (ACTTarget)
    u32 m_field_588;  // 0x588 [W] (ACTTarget)
    u32 m_field_58C;  // 0x58C [W] (ACTTarget)
    u32 m_field_590;  // 0x590 [W] (ACTTarget)
    u8 _pad_594[0x3C];  // 0x594
    u32 m_field_5D0;  // 0x5D0 [W] (ACTTarget)
    u32 m_field_5D4;  // 0x5D4 [W] (ACTTarget)
    u32 m_field_5D8;  // 0x5D8 [W] (ACTTarget)
    u32 m_field_5DC;  // 0x5DC [W] (ACTTarget)
    u8 _pad_5E0[0x3C];  // 0x5E0
    u32 m_field_61C;  // 0x61C [W] (ACTTarget)
    u32 m_field_620;  // 0x620 [W] (ACTTarget)
    u32 m_field_624;  // 0x624 [W] (ACTTarget)
    u32 m_field_628;  // 0x628 [W] (ACTTarget)
    u8 _pad_62C[0x18];  // 0x62C
    u32 m_bCancelModeEnabled_644;  // 0x644 [R/W] (ACTTarget, CancelCurrentObject, CancelModeEnabled, ...)
    u32 m_bCancelModeEnabled_648;  // 0x648 [R/W] (ACTTarget, CancelCurrentObject, CancelModeEnabled, ...)
    u32 m_bCancelModeEnabled_64C;  // 0x64C [R/W] (ACTTarget, CancelCurrentObject, CancelModeEnabled, ...)
    u8 _pad_650[4];  // 0x650
    u32 m_field_654;  // 0x654 [R] (RemoveAction)
};

#endif // ACTTARGET_H
