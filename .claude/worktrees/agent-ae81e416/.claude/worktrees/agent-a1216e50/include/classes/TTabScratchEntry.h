#ifndef TTABSCRATCHENTRY_H
#define TTABSCRATCHENTRY_H

#include "types.h"

// TTabScratchEntry - struct layout extracted from assembly analysis
// Estimated minimum size: 0x11C (284 bytes)
// 9 known fields (1 named), 132 methods

class TTabScratchEntry {
public:
    // Constructors / Destructors
    TTabScratchEntry(void)  // 0x803D0A80
    ~TTabScratchEntry(void);  // 0x803D0B48

    // Methods
    /* ? */ GetRangeRef(int);  // 0x803D23B0 (64B)
    /* ? */ GetPersonalityVarRef(int);  // 0x803D2430 (64B)
    /* ? */ GetMinRef(int);  // 0x803D23F0 (64B)
    void CopyFrom(ITreeTableEntry *);  // 0x803D0C1C (828B)
    /* ? */ GetAttenuationValue(bool);  // 0x803D0F58 (80B)
    void QueryInterface(unsigned int, void **);  // 0x803D1180 (248B)
    void AddRef(void);  // 0x803D1278 (64B)
    void Release(void);  // 0x803D12B8 (160B)
    /* ? */ GetOrderIndex(void);  // 0x803D2804 (160B)
    void SetOrderIndex(int);  // 0x803D28A4 (156B)
    /* ? */ GetIndex(void);  // 0x803D1BA4 (48B)
    /* ? */ GetAvailableToVisitors(void);  // 0x803D1BD4 (52B)
    void SetAvailableToVisitors(bool);  // 0x803D1C08 (76B)
    /* ? */ GetCanJoin(void);  // 0x803D1C54 (60B)
    void SetCanJoin(bool);  // 0x803D1C90 (76B)
    /* ? */ GetImmediate(void);  // 0x803D1CDC (60B)
    void SetImmediate(bool);  // 0x803D1D18 (76B)
    /* ? */ GetAllowConsecutive(void);  // 0x803D1D64 (60B)
    void SetAllowConsecutive(bool);  // 0x803D1DA0 (76B)
    /* ? */ GetAvailableToGhosts(void);  // 0x803D1DEC (60B)
    void SetAvailableToGhosts(bool);  // 0x803D1E28 (76B)
    /* ? */ GetAvailableToAdults(void);  // 0x803D1E74 (64B)
    void SetAvailableToAdults(bool);  // 0x803D1EB4 (76B)
    /* ? */ GetAvailableToChildrenDemo(void);  // 0x803D1F00 (60B)
    void SetAvailableToChildrenDemo(bool);  // 0x803D1F3C (76B)
    /* ? */ GetAvailableToVisitingPlayers(void);  // 0x803D20F4 (60B)
    void SetAvailableToVisitingPlayers(bool);  // 0x803D2130 (76B)
    /* ? */ GetJoinIndex(void);  // 0x803D1F88 (48B)
    void SetJoinIndex(int);  // 0x803D1FB8 (44B)
    /* ? */ GetDebugOnly(void);  // 0x803D1FE4 (60B)
    void SetDebugOnly(bool);  // 0x803D2020 (76B)
    /* ? */ GetAutoFirstSelect(void);  // 0x803D206C (60B)
    void SetAutoFirstSelect(bool);  // 0x803D20A8 (76B)
    /* ? */ GetManualOnly(void);  // 0x803D228C (60B)
    void CountAds(void);  // 0x803D22C8 (40B)
    /* ? */ GetAd(int);  // 0x803D2470 (60B)
    void SetAd(int, ITreeTableAd &);  // 0x803D24E8 (136B)
    /* ? */ GetActionTreeID(void);  // 0x803D2570 (48B)
    void SetActionTreeID(short);  // 0x803D25A0 (44B)
    /* ? */ GetCheckTreeID(void);  // 0x803D25CC (48B)
    void SetCheckTreeID(short);  // 0x803D25FC (44B)
    /* ? */ GetAttenuation(void);  // 0x803D2628 (44B)
    void SetAttenuation(ITreeTableEntry::Attenuation);  // 0x803D2654 (40B)
    /* ? */ GetCustomAttenuationValue(void);  // 0x803D267C (44B)
    void SetCustomAttenuation(float);  // 0x803D26A8 (48B)
    /* ? */ GetAutonomyThreshold(void);  // 0x803D26D8 (48B)
    void SetAutonomyThreshold(short);  // 0x803D2708 (44B)
    /* ? */ GetIgnorePrefixTree(void);  // 0x803D217C (60B)
    void SetIgnorePrefixTree(bool);  // 0x803D21B8 (76B)
    /* ? */ GetMustRun(void);  // 0x803D2204 (60B)
    void SetMustRun(bool);  // 0x803D2240 (76B)
    /* ? */ GetName(void);  // 0x803D2734 (124B)
    void SetName(BString2 &);  // 0x803D27B0 (36B)
    /* ? */ GetUseCustomActivation(void);  // 0x803D2940 (40B)
    void SetUseCustomActivation(bool);  // 0x803D2968 (36B)
    /* ? */ GetActivationSubtile(unsigned char &, unsigned char &);  // 0x803D298C (40B)
    void SetActivationSubtile(unsigned char, unsigned char);  // 0x803D29B4 (40B)
    /* ? */ GetActivationExtents(unsigned char &, unsigned char &, unsigned char &, unsigned char &);  // 0x803D29DC (48B)
    void SetActivationExtents(unsigned char, unsigned char, unsigned char, unsigned char);  // 0x803D2A0C (48B)
    /* ? */ GetFlags(void);  // 0x803D27D4 (48B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [R/W] - vtable pointer (CopyFrom, QueryInterface, Release, ...)
    u16 m_field_004;  // 0x004 [W] (CopyFrom)
    u16 m_field_006;  // 0x006 [W] (CopyFrom)
    u8 _pad_008[0x100];  // 0x008
    u32 m_field_108;  // 0x108 [W] (CopyFrom)
    f32 m_field_10C;  // 0x10C [W] (CopyFrom)
    u16 m_field_110;  // 0x110 [W] (CopyFrom)
    u16 m_field_112;  // 0x112 [W] (CopyFrom)
    u8 _pad_114[2];  // 0x114
    u16 m_field_116;  // 0x116 [W] (CopyFrom)
    u32 m_field_118;  // 0x118 [R/W] (Release)
};

#endif // TTABSCRATCHENTRY_H
