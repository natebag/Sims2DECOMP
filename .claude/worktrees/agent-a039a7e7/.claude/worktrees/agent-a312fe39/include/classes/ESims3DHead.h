#ifndef ESIMS3DHEAD_H
#define ESIMS3DHEAD_H

#include "types.h"

// ESims3DHead - struct layout extracted from assembly analysis
// Estimated minimum size: 0x514C (20812 bytes)
// 31 known fields (3 named), 16 methods

class ESims3DHead {
public:
    // Constructors / Destructors
    ESims3DHead(ESim *)  // 0x8014BC60
    ~ESims3DHead(void);  // 0x8014C0B0

    // Methods
    void InitShaders(void);  // 0x8014BD0C (168B)
    void ResetShaders(void);  // 0x8014BDB4 (148B)
    void InitHead(cXPerson *);  // 0x8014BE48 (616B)
    void Update(void);  // 0x8014C114 (32B)
    void Draw(ERC *);  // 0x8014C134 (5772B)
    void Draw2D(ERC *, cXPerson *);  // 0x8014D890 (464B)

    // ---- Field Layout (from assembly analysis) ----
    u8 _pad_000[4];  // 0x000
    f32 m_field_004;  // 0x004 [R/W] (Draw)
    f32 m_field_008;  // 0x008 [R/W] (Draw)
    u8 _pad_00C[4];  // 0x00C
    s16 m_field_010;  // 0x010 [R] (Draw)
    u8 _pad_012[2];  // 0x012
    u32 m_field_014;  // 0x014 [R] (Draw)
    u8 _pad_018[0x48];  // 0x018
    f32 m_field_060;  // 0x060 [R] (Draw)
    f32 m_field_064;  // 0x064 [R] (Draw)
    f32 m_field_068;  // 0x068 [R] (Draw)
    f32 m_field_06C;  // 0x06C [R] (Draw)
    u8 _pad_070[0x80];  // 0x070
    u32 m_field_0F0;  // 0x0F0 [R] (Draw)
    u8 _pad_0F4[0xDC];  // 0x0F4
    s16 m_field_1D0;  // 0x1D0 [R] (Draw)
    u8 _pad_1D2[2];  // 0x1D2
    u32 m_field_1D4;  // 0x1D4 [R] (Draw)
    u8 _pad_1D8[0x178];  // 0x1D8
    u32 m_field_350;  // 0x350 [R/W] (Draw, ESims3DHead, InitHead)
    u32 m_field_354;  // 0x354 [R/W] (Draw, Draw2D, ESims3DHead)
    f32 m_field_358;  // 0x358 [R/W] (Draw)
    u32 m_field_35C;  // 0x35C [W] (Draw)
    u8 _pad_360[0x38];  // 0x360
    f32 m_field_398;  // 0x398 [R/W] (Draw, Draw2D, InitHead)
    f32 m_field_39C;  // 0x39C [W] (InitHead)
    f32 m_field_3A0;  // 0x3A0 [R/W] (Draw, Draw2D, InitHead)
    f32 m_2D;  // 0x3A4 [R/W] (Draw, Draw2D)
    f32 m_2D_3A8;  // 0x3A8 [W] (Draw, Draw2D)
    f32 m_2D_3AC;  // 0x3AC [R/W] (Draw, Draw2D)
    u32 m_field_3B0;  // 0x3B0 [W] (ESims3DHead, ~ESims3DHead)
    u8 _pad_3B4[0x1C];  // 0x3B4
    u32 m_field_3D0;  // 0x3D0 [R] (Draw)
    u8 _pad_3D4[0x258];  // 0x3D4
    u32 m_field_62C;  // 0x62C [R] (Draw)
    u8 _pad_630[0xC];  // 0x630
    u32 m_field_63C;  // 0x63C [R] (Draw)
    u8 _pad_640[0x4AD8];  // 0x640
    f32 m_field_5118;  // 0x5118 [R] (Draw)
    f32 m_field_511C;  // 0x511C [R] (Draw)
    f32 m_field_5120;  // 0x5120 [R] (Draw)
    f32 m_field_5124;  // 0x5124 [R] (Draw)
    u8 _pad_5128[0x1C];  // 0x5128
    f32 m_field_5144;  // 0x5144 [R] (Draw)
    f32 m_field_5148;  // 0x5148 [R] (Draw)
};

#endif // ESIMS3DHEAD_H
