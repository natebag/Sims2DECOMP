#ifndef INTERACTION_H
#define INTERACTION_H

#include "types.h"

// Interaction - struct layout extracted from assembly analysis
// Estimated minimum size: 0x15A (346 bytes)
// 19 known fields (7 named), 126 methods

class Interaction {
public:
    // Constructors / Destructors
    Interaction(void)  // 0x8025B660
    Interaction(Interaction &)  // 0x8025B758
    Interaction(cXPerson *, cXObject *, int)  // 0x8025B7C8
    Interaction(cXPerson *, cXPerson *)  // 0x8025B8F4
    Interaction(cXPerson *, cXObject *, int, int)  // 0x8025BD1C
    ~Interaction(void);  // 0x8025BFB8

    // Methods
    /* ? */ GetIconObject(void);  // 0x8025C9C8 (44B)
    /* ? */ GetStackObject(void);  // 0x8025C970 (44B)
    /* ? */ GetName(void);  // 0x8025C304 (280B)
    /* ? */ GetTextColor(void);  // 0x8025CB08 (52B)
    /* ? */ GetDisabled(void);  // 0x8025D588 (52B)
    /* ? */ GetPerson(void);  // 0x8025C99C (44B)
    void operator=(Interaction &);  // 0x8025B520 (320B)
    void SetLocalVars(short *, int);  // 0x8025C0A8 (228B)
    void SetChecked(bool);  // 0x8025D184 (68B)
    void SetAutoFirstSelect(bool);  // 0x8025D094 (68B)
    void SetContinuation(bool);  // 0x8025D10C (68B)
    /* ? */ GetEntry(void);  // 0x8025C18C (312B)
    void SetMustRun(bool);  // 0x8025D544 (68B)
    void SetStackVars(short *);  // 0x8025C048 (96B)
    void SetUniqueID(void);  // 0x8025C2C4 (64B)
    void SetNameChanged(bool);  // 0x8025D3DC (68B)
    void SetName(BString2 &);  // 0x8025C41C (80B)
    void SetName(int, int);  // 0x8025C46C (672B)
    void DoStream(ReconBuffer *, int);  // 0x8025C70C (612B)
    void SetIconObject(cXObject *);  // 0x8025C9F4 (44B)
    /* ? */ GetCTilePt(void);  // 0x8025CA5C (172B)
    void SetTextColor(Interaction::tColor);  // 0x8025CB3C (60B)
    void SetShader(EActionIcon *);  // 0x8025D6CC (44B)
    /* ? */ GetType(void);  // 0x8025CE48 (44B)
    /* ? */ GetAttenuation(void);  // 0x8025CE74 (44B)
    /* ? */ GetTreeID(void);  // 0x8025CEA0 (48B)
    /* ? */ GetStackVars(void);  // 0x8025CED0 (44B)
    /* ? */ GetLocalVars(void);  // 0x8025CEFC (44B)
    /* ? */ GetLocalVarsCount(void);  // 0x8025CF28 (44B)
    /* ? */ GetTreeTabEntryIndex(void);  // 0x8025CF54 (44B)
    /* ? */ GetPriority(void);  // 0x8025CF80 (44B)
    void SetPriority(int);  // 0x8025CFAC (40B)
    bool HasID(void);  // 0x8025CFD4 (60B)
    /* ? */ GetID(void);  // 0x8025D010 (44B)
    void SetID(int);  // 0x8025D03C (40B)
    /* ? */ GetAutoFirstSelect(void);  // 0x8025D064 (48B)
    /* ? */ GetContinuation(void);  // 0x8025D0D8 (52B)
    /* ? */ GetChecked(void);  // 0x8025D150 (52B)
    /* ? */ GetAvailable(void);  // 0x8025D1C8 (52B)
    void SetAvailable(bool);  // 0x8025D1FC (68B)
    /* ? */ GetHidden(void);  // 0x8025D240 (52B)
    void SetHidden(bool);  // 0x8025D274 (68B)
    /* ? */ GetPushToHead(void);  // 0x8025D2B8 (52B)
    void SetPushToHead(bool);  // 0x8025D2EC (68B)
    /* ? */ GetCarryNameOver(void);  // 0x8025D330 (52B)
    void SetCarryNameOver(bool);  // 0x8025D364 (68B)
    /* ? */ GetNameChanged(void);  // 0x8025D3A8 (52B)
    /* ? */ GetCancelled(void);  // 0x8025D420 (52B)
    void SetCancelled(bool);  // 0x8025D454 (68B)
    /* ? */ GetDebugOverride(void);  // 0x8025D498 (52B)
    void SetDebugOverride(bool);  // 0x8025D4CC (68B)
    /* ? */ GetMustRun(void);  // 0x8025D510 (52B)
    void SetDisabled(bool);  // 0x8025D5BC (68B)
    /* ? */ GetRunAsSub(void);  // 0x8025D600 (52B)
    void SetRunAsSub(bool);  // 0x8025D634 (68B)
    /* ? */ GetFlags(void);  // 0x8025D678 (44B)
    void SetFlags(int);  // 0x8025D6A4 (40B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [R/W] - vtable pointer (GetEntry, operator=)
    u32 m_cTilePt;  // 0x004 [R/W] (DoStream, GetCTilePt, Interaction, ...)
    u32 m_field_008;  // 0x008 [R/W] (DoStream, Interaction, operator=)
    u32 m_entry_00C;  // 0x00C [R/W] (DoStream, GetEntry, Interaction, ...)
    u32 m_field_010;  // 0x010 [R/W] (DoStream, Interaction, operator=)
    u32 m_entry_014;  // 0x014 [R/W] (GetEntry, Interaction, operator=)
    u16 m_field_018;  // 0x018 [W] (Interaction, operator=)
    u16 m_field_01A;  // 0x01A [W] (Interaction, operator=)
    u16 m_field_01C;  // 0x01C [W] (Interaction, operator=)
    u16 m_field_01E;  // 0x01E [W] (Interaction, operator=)
    u32 m_localVars;  // 0x020 [R/W] (Interaction, SetLocalVars, operator=)
    u32 m_localVars_024;  // 0x024 [R/W] (Interaction, SetLocalVars, operator=, ...)
    u32 m_field_028;  // 0x028 [W] (Interaction, operator=)
    u16 m_field_02C;  // 0x02C [W] (Interaction, operator=)
    u8 _pad_02E[2];  // 0x02E
    f32 m_field_030;  // 0x030 [W] (Interaction, operator=)
    u8 _pad_034[4];  // 0x034
    u32 m_field_038;  // 0x038 [R/W] (DoStream, Interaction, operator=)
    u32 m_name;  // 0x03C [R/W] (GetName, Interaction, operator=)
    u32 m_field_040;  // 0x040 [W] (Interaction, ~Interaction)
    u8 _pad_044[0x114];  // 0x044
    s16 m_field_158;  // 0x158 [R] (Interaction)
};

#endif // INTERACTION_H
