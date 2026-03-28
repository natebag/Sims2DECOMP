#ifndef HOUSEIMPL_H
#define HOUSEIMPL_H

#include "types.h"

// HouseImpl - struct layout extracted from assembly analysis
// Estimated minimum size: 0x74 (116 bytes)
// 8 known fields (5 named), 42 methods

class HouseImpl {
public:
    // Constructors / Destructors
    HouseImpl(void)  // 0x8024AC28
    ~HouseImpl(void);  // 0x8024ACB0

    // Methods
    void Destroy(void);  // 0x8024B154 (288B)
    void Initialize(void);  // 0x8024AD30 (1060B)
    void RefreshHouse(void);  // 0x8024B274 (208B)
    void SetLotSize(int, int);  // 0x8024B344 (412B)
    void LoadFile(iResFile *, int *);  // 0x8024B4E0 (3072B)
    void ComputeAndStoreLotData(void);  // 0x8024C0E0 (588B)
    void SaveFile(iResFile *);  // 0x8024C32C (340B)
    /* ? */ GetFirstObject(void);  // 0x8024C480 (116B)
    void DoCommand(short, int);  // 0x8024C4F4 (1032B)
    bool IsNative(cXPerson *);  // 0x8024C8FC (208B)
    bool IsResident(cXPerson *);  // 0x8024C9CC (376B)
    void EnterLiveMode(void);  // 0x8024CB44 (204B)
    void PrepareForBudgetWindow(void);  // 0x8024CC10 (168B)
    void DoStream(ReconBuffer *, int);  // 0x8024CCB8 (220B)
    /* ? */ GetHouseStats(HouseStats &);  // 0x8024CD94 (864B)
    /* ? */ GetFamily(void);  // 0x8024EB08 (44B)
    /* ? */ GetSizeScoreCurve(void);  // 0x8024EB34 (44B)
    /* ? */ GetFurnishingsScoreCurve(void);  // 0x8024EB60 (44B)
    void SetFamilyToNull(void);  // 0x8024EB8C (40B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [R/W] - vtable pointer (DoCommand, EnterLiveMode, HouseImpl, ...)
    u8 _pad_004[0xC];  // 0x004
    u32 m_field_010;  // 0x010 [W] (HouseImpl, ~HouseImpl)
    u32 m_houseStats;  // 0x014 [R/W] (ComputeAndStoreLotData, Destroy, DoCommand, ...)
    u8 _pad_018[4];  // 0x018
    u32 m_field_01C;  // 0x01C [R/W] (Destroy, HouseImpl, Initialize)
    u32 m_field_020;  // 0x020 [R/W] (Destroy, HouseImpl, Initialize)
    u8 _pad_024[0x10];  // 0x024
    u32 m_houseStats_034;  // 0x034 [R] (GetHouseStats)
    u8 _pad_038[0x34];  // 0x038
    u32 m_houseStats_06C;  // 0x06C [R] (GetHouseStats)
    u32 m_houseStats_070;  // 0x070 [R] (GetHouseStats)
};

#endif // HOUSEIMPL_H
