#ifndef FAMILYIMPL_H
#define FAMILYIMPL_H

#include "types.h"

// FamilyImpl - struct layout extracted from assembly analysis
// Estimated minimum size: 0x38 (56 bytes)
// 14 known fields (2 named), 100 methods

class FamilyImpl {
public:
    // Constructors / Destructors
    FamilyImpl(int)  // 0x8023386C
    ~FamilyImpl(void);  // 0x80233950

    // Methods
    /* ? */ GetHasP1DoneCAS(void);  // 0x80235C50 (52B)
    void SetHasP1DoneCAS(bool);  // 0x80235C0C (68B)
    void SetHasP2DoneCAS(bool);  // 0x80235C84 (68B)
    void CreateFamilyInLot(void);  // 0x802339BC (316B)
    void RemoveFamilyFromLot(void);  // 0x80233AF8 (424B)
    void TestMember(cXPerson *);  // 0x80233CA0 (192B)
    /* ? */ GetMemberByGUID(int);  // 0x80233D60 (160B)
    void TestMember(int);  // 0x80233E00 (160B)
    /* ? */ GetIndexedMember(int);  // 0x80233EA0 (144B)
    /* ? */ GetName(StringBuffer2 *);  // 0x80233F30 (80B)
    void CountMembers(void);  // 0x80233F80 (72B)
    /* ? */ GetFriendCount(void);  // 0x80233FC8 (120B)
    /* ? */ GetNetWorth(void);  // 0x80234040 (120B)
    void LoadFamily(iResFile *, int);  // 0x802340B8 (244B)
    void LoadByResID(iResFile *, short, int *);  // 0x80234360 (236B)
    void ClearFamily(void);  // 0x802341AC (64B)
    void DoStream(ReconBuffer *, int);  // 0x802341EC (372B)
    void SaveFamily(iResFile *, int);  // 0x8023444C (216B)
    void SetName(StringBuffer2 *);  // 0x80234524 (80B)
    void MyDoCommand(short, int);  // 0x80234574 (52B)
    void AddMember(int);  // 0x802345A8 (188B)
    void RemoveMember(int);  // 0x80234664 (164B)
    /* ? */ GetExportName(StringBuffer2 *);  // 0x80234750 (132B)
    /* ? */ GetResfileStorageId(short);  // 0x8023580C (48B)
    /* ? */ GetNumber(void);  // 0x8023583C (44B)
    void SetNumber(int);  // 0x80235868 (40B)
    /* ? */ GetHouseNumber(void);  // 0x80235890 (44B)
    void SetHouseNumber(int);  // 0x802358BC (40B)
    /* ? */ GetCreationOrder(void);  // 0x802358E4 (44B)
    void SetCreationOrder(int);  // 0x80235910 (40B)
    /* ? */ GetFunds(void);  // 0x80235938 (44B)
    void SetFunds(int);  // 0x80235964 (72B)
    /* ? */ GetHouseValue(void);  // 0x802359AC (44B)
    void SetHouseValue(int);  // 0x802359D8 (40B)
    void SetFriendCount(int);  // 0x80235A00 (48B)
    void SetHasPhone(bool);  // 0x80235A30 (68B)
    /* ? */ GetHasPhone(void);  // 0x80235A74 (48B)
    void SetHasBaby(bool);  // 0x80235AA4 (68B)
    /* ? */ GetHasBaby(void);  // 0x80235AE8 (52B)
    void SetJustMovedIn(bool);  // 0x80235B1C (68B)
    /* ? */ GetJustMovedIn(void);  // 0x80235B60 (52B)
    void SetIsFreeplay(bool);  // 0x80235B94 (68B)
    /* ? */ GetIsFreeplay(void);  // 0x80235BD8 (52B)
    /* ? */ GetInventory(void);  // 0x80235CFC (40B)
    /* ? */ GetGoalAndUnlockData(void);  // 0x80235D24 (40B)
    /* ? */ GetStatValue(int);  // 0x80235D4C (44B)
    /* ? */ GetStatRef(int, short **);  // 0x80235D78 (48B)
    /* ? */ GetHasP2DoneCAS(void);  // 0x80235CC8 (52B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [R/W] - vtable pointer (AddMember, CreateFamilyInLot, DoStream, ...)
    u32 m_field_004;  // 0x004 [R/W] (RemoveMember)
    u32 m_exportName_008;  // 0x008 [R/W] (FamilyImpl, GetExportName, LoadFamily, ...)
    s16 m_field_00A;  // 0x00A [R] (SaveFamily)
    u32 m_field_00C;  // 0x00C [R/W] (DoStream, FamilyImpl)
    u32 m_field_010;  // 0x010 [W] (FamilyImpl)
    u32 m_field_014;  // 0x014 [R/W] (DoStream, FamilyImpl)
    u32 m_field_018;  // 0x018 [W] (FamilyImpl)
    u32 m_field_01C;  // 0x01C [W] (FamilyImpl)
    u32 m_field_020;  // 0x020 [W] (FamilyImpl)
    u32 m_field_024;  // 0x024 [R/W] (AddMember, CreateFamilyInLot, DoStream, ...)
    u32 m_field_028;  // 0x028 [R/W] (AddMember, FamilyImpl, LoadByResID)
    u32 m_field_02C;  // 0x02C [R/W] (LoadByResID)
    u8 _pad_030[4];  // 0x030
    u32 m_field_034;  // 0x034 [W] (FamilyImpl)
};

#endif // FAMILYIMPL_H
