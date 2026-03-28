#ifndef EFLOORSHDTBLNODE_H
#define EFLOORSHDTBLNODE_H

#include "types.h"

// EFloorShdTblNode - struct layout extracted from assembly analysis
// Estimated minimum size: 0xB8 (184 bytes)
// 6 known fields (0 named), 24 methods

class EFloorShdTblNode {
public:
    // Constructors / Destructors
    EFloorShdTblNode(void)  // 0x800CF7EC
    ~EFloorShdTblNode(void);  // 0x800CF8A8

    // Methods
    void CleanUp(void);  // 0x800CF9D8 (96B)
    void InitTable(void);  // 0x800CFA38 (612B)
    void AddStripToTable(int, EFloorStripInfo &);  // 0x800CFC9C (248B)
    void AddLightStrip(EFloorStripInfo);  // 0x800CFD94 (248B)
    void BuildTable(ERLevel *);  // 0x800D03F4 (3584B)
    void CheckForObjectsInFloor(CTilePt &);  // 0x800D11F4 (228B)
    void BuildStrip(ERC *, EFloorStripInfo, EVec2 &, EFloorTileStrip *, bool, ERLevel *, EBound3 &, bool &);  // 0x800D19AC (3408B)
    void EmptyTable(void);  // 0x800D26FC (328B)
    void RemapFloorAndGrassId(unsigned int);  // 0x800D339C (100B)
    void PreviewTable(void);  // 0x800D45A0 (1024B)

    // ---- Field Layout (from assembly analysis) ----
    f32 m_field_000;  // 0x000 [R/W] (BuildStrip, BuildTable, CleanUp, ...)
    f32 m_field_004;  // 0x004 [W] (BuildStrip)
    f32 m_field_008;  // 0x008 [W] (BuildStrip)
    f32 m_field_00C;  // 0x00C [W] (BuildStrip)
    u8 _pad_010[0x60];  // 0x010
    u32 m_field_070;  // 0x070 [R] (BuildStrip)
    u8 _pad_074[0x42];  // 0x074
    u16 m_field_0B6;  // 0x0B6 [R] (CheckForObjectsInFloor)
};

#endif // EFLOORSHDTBLNODE_H
