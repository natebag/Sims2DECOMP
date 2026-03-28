#ifndef TREETABLEENTRYQUICKDATA_H
#define TREETABLEENTRYQUICKDATA_H

#include "types.h"

// TreeTableEntryQuickData - struct layout extracted from assembly analysis
// Estimated minimum size: 0x1C (28 bytes)
// 6 known fields (5 named), 126 methods

class TreeTableEntryQuickData {
public:
    // Constructors / Destructors
    TreeTableEntryQuickData(TreeTableEntry *)  // 0x8040198C
    ~TreeTableEntryQuickData(void);  // 0x80401B30

    // Methods
    /* ? */ GetAd(int);  // 0x80401BB0 (492B)
    /* ? */ GetImplementation(void);  // 0x80406704 (44B)
    /* ? */ GetName(void);  // 0x80401D9C (92B)
    void QueryInterface(unsigned int, void **);  // 0x80402A4C (248B)
    void AddRef(void);  // 0x80402B44 (64B)
    void Release(void);  // 0x80402B84 (160B)
    /* ? */ GetOrderIndex(void);  // 0x80404FA8 (68B)
    void SetOrderIndex(int);  // 0x804057A4 (156B)
    /* ? */ GetIndex(void);  // 0x80404F64 (68B)
    /* ? */ GetAvailableToVisitors(void);  // 0x80404FEC (68B)
    void SetAvailableToVisitors(bool);  // 0x80405840 (156B)
    /* ? */ GetCanJoin(void);  // 0x80405030 (68B)
    void SetCanJoin(bool);  // 0x804058DC (156B)
    /* ? */ GetImmediate(void);  // 0x80405074 (68B)
    void SetImmediate(bool);  // 0x80405978 (156B)
    /* ? */ GetAllowConsecutive(void);  // 0x804050B8 (68B)
    void SetAllowConsecutive(bool);  // 0x80405A14 (156B)
    /* ? */ GetAvailableToGhosts(void);  // 0x804050FC (68B)
    void SetAvailableToGhosts(bool);  // 0x80405AB0 (156B)
    /* ? */ GetAvailableToAdults(void);  // 0x80405140 (68B)
    void SetAvailableToAdults(bool);  // 0x80405B4C (156B)
    /* ? */ GetAvailableToChildrenDemo(void);  // 0x80405184 (68B)
    void SetAvailableToChildrenDemo(bool);  // 0x80405BE8 (156B)
    /* ? */ GetAvailableToVisitingPlayers(void);  // 0x80405294 (68B)
    void SetAvailableToVisitingPlayers(bool);  // 0x80405E58 (156B)
    /* ? */ GetJoinIndex(void);  // 0x804051C8 (68B)
    void SetJoinIndex(int);  // 0x80405C84 (156B)
    /* ? */ GetDebugOnly(void);  // 0x8040520C (68B)
    void SetDebugOnly(bool);  // 0x80405D20 (156B)
    /* ? */ GetAutoFirstSelect(void);  // 0x80405250 (68B)
    void SetAutoFirstSelect(bool);  // 0x80405DBC (156B)
    /* ? */ GetManualOnly(void);  // 0x804052D8 (68B)
    void CountAds(void);  // 0x8040531C (68B)
    /* ? */ GetRangeRef(int);  // 0x804053E8 (76B)
    /* ? */ GetMinRef(int);  // 0x80405434 (76B)
    /* ? */ GetPersonalityVarRef(int);  // 0x80405480 (76B)
    void SetAd(int, ITreeTableAd &);  // 0x804060D0 (160B)
    /* ? */ GetActionTreeID(void);  // 0x804054CC (72B)
    void SetActionTreeID(short);  // 0x80406170 (156B)
    /* ? */ GetCheckTreeID(void);  // 0x80405514 (72B)
    void SetCheckTreeID(short);  // 0x8040620C (156B)
    /* ? */ GetAttenuation(void);  // 0x8040555C (72B)
    void SetAttenuation(ITreeTableEntry::Attenuation);  // 0x804062A8 (156B)
    /* ? */ GetAttenuationValue(bool);  // 0x804055A4 (76B)
    /* ? */ GetCustomAttenuationValue(void);  // 0x804055F0 (68B)
    void SetCustomAttenuation(float);  // 0x80406344 (164B)
    /* ? */ GetAutonomyThreshold(void);  // 0x80405634 (72B)
    void SetAutonomyThreshold(short);  // 0x804063E8 (156B)
    /* ? */ GetIgnorePrefixTree(void);  // 0x80405360 (68B)
    void SetIgnorePrefixTree(bool);  // 0x80405EF4 (156B)
    /* ? */ GetMustRun(void);  // 0x804053A4 (68B)
    void SetMustRun(bool);  // 0x80405F90 (156B)
    void SetName(BString2 &);  // 0x80406484 (156B)
    /* ? */ GetUseCustomActivation(void);  // 0x804056C0 (68B)
    void SetUseCustomActivation(bool);  // 0x80406520 (156B)
    /* ? */ GetActivationSubtile(unsigned char &, unsigned char &);  // 0x80405704 (72B)
    void SetActivationSubtile(unsigned char, unsigned char);  // 0x804065BC (160B)
    /* ? */ GetActivationExtents(unsigned char &, unsigned char &, unsigned char &, unsigned char &);  // 0x8040574C (88B)
    void SetActivationExtents(unsigned char, unsigned char, unsigned char, unsigned char);  // 0x8040665C (168B)
    /* ? */ GetFlags(void);  // 0x8040567C (68B)

    // ---- Field Layout (from assembly analysis) ----
    s16 m_ad;  // 0x000 [R/W] (GetAd, QueryInterface, Release, ...)
    s16 m_ad_002;  // 0x002 [R] (GetAd)
    s16 m_ad_004;  // 0x004 [R/W] (GetAd, TreeTableEntryQuickData, ~TreeTableEntryQuickData)
    u8 _pad_006[2];  // 0x006
    u32 m_ad_008;  // 0x008 [R/W] (GetAd, TreeTableEntryQuickData, ~TreeTableEntryQuickData)
    u32 m_ad_00C;  // 0x00C [R] (GetAd)
    u8 _pad_010[8];  // 0x010
    u32 m_field_018;  // 0x018 [R/W] (Release, TreeTableEntryQuickData)
};

#endif // TREETABLEENTRYQUICKDATA_H
