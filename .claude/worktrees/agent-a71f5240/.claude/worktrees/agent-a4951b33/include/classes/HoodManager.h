#ifndef HOODMANAGER_H
#define HOODMANAGER_H

#include "types.h"

// HoodManager - struct layout extracted from assembly analysis
// Estimated minimum size: 0x618C (24972 bytes)
// 20 known fields (5 named), 22 methods

class HoodManager {
public:
    // Methods
    void TestMoveInFamily(int, Family *);  // 0x800C3BE8 (348B)
    void MoveInFamily(int, Family *, bool);  // 0x800C3D44 (348B)
    void UnmarkFamilyForDeletion(int, Family *);  // 0x800C3EA0 (836B)
    void EvictFamilyAndLiquidateAssets(int);  // 0x800C41E4 (928B)
    void EvictFamily(int, bool);  // 0x800C4584 (1520B)
    void RemoveAllObjects(int);  // 0x800C4B74 (652B)
    void DemolishCurrentHouse(int);  // 0x800C4E00 (2504B)
    void ResetToPristine(void);  // 0x800C57C8 (6660B)
    void ResetNeighbors(void);  // 0x800C71CC (1240B)
    /* ? */ GetMatrix(Neighbor *, Neighbor *, RelMatrix **, int *);  // 0x800C76A4 (228B)
    /* ? */ GetRelatedPeople(int, cXPerson *, void *);  // 0x800C7C48 (716B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [R/W] - vtable pointer (DemolishCurrentHouse, GetRelatedPeople, MoveInFamily, ...)
    f32 m_relatedPeople_004;  // 0x004 [R/W] (GetRelatedPeople, ResetNeighbors, ResetToPristine)
    u32 m_field_008;  // 0x008 [R/W] (ResetToPristine)
    u32 m_field_00C;  // 0x00C [R/W] (ResetToPristine)
    u8 _pad_010[2];  // 0x010
    s16 m_field_012;  // 0x012 [R] (EvictFamily)
    u8 _pad_014[8];  // 0x014
    u32 m_relatedPeople_01C;  // 0x01C [R] (EvictFamily, GetRelatedPeople)
    u8 _pad_020[0x18];  // 0x020
    u32 m_field_038;  // 0x038 [R] (EvictFamily, ResetToPristine)
    u8 _pad_03C[0x34];  // 0x03C
    u32 m_field_070;  // 0x070 [W] (EvictFamily, EvictFamilyAndLiquidateAssets, TestMoveInFamily)
    s16 m_field_074;  // 0x074 [R] (ResetToPristine)
    u8 _pad_076[0x4A];  // 0x076
    s16 m_relatedPeople_0C0;  // 0x0C0 [R] (GetRelatedPeople)
    u8 _pad_0C2[6];  // 0x0C2
    s16 m_field_0C8;  // 0x0C8 [R] (TestMoveInFamily)
    u8 _pad_0CA[2];  // 0x0CA
    u32 m_field_0CC;  // 0x0CC [R] (TestMoveInFamily)
    u8 _pad_0D0[0x1A];  // 0x0D0
    s16 m_relatedPeople_0EA;  // 0x0EA [R] (GetRelatedPeople)
    u32 m_field_0EC;  // 0x0EC [R] (ResetToPristine)
    u8 _pad_0F0[0x48];  // 0x0F0
    s16 m_field_138;  // 0x138 [R] (EvictFamilyAndLiquidateAssets)
    u8 _pad_13A[2];  // 0x13A
    u32 m_field_13C;  // 0x13C [R] (EvictFamilyAndLiquidateAssets)
    u8 _pad_140[0x50];  // 0x140
    s16 m_field_190;  // 0x190 [R] (EvictFamily, EvictFamilyAndLiquidateAssets, TestMoveInFamily)
    u8 _pad_192[2];  // 0x192
    u32 m_field_194;  // 0x194 [R] (EvictFamily, EvictFamilyAndLiquidateAssets, TestMoveInFamily)
    u8 _pad_198[0x5ADC];  // 0x198
    u32 m_field_5C74;  // 0x5C74 [R] (EvictFamilyAndLiquidateAssets)
    u8 _pad_5C78[0x510];  // 0x5C78
    u32 m_field_6188;  // 0x6188 [R] (TestMoveInFamily)
};

#endif // HOODMANAGER_H
