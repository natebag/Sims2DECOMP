#ifndef ESPRITERENDER_H
#define ESPRITERENDER_H

#include "types.h"

// ESpriteRender - struct layout extracted from assembly analysis
// Estimated minimum size: 0x5E98 (24216 bytes)
// 53 known fields (49 named), 30 methods

class ESpriteRender {
public:
    // Constructors / Destructors
    ESpriteRender(void)  // 0x800905B0
    ~ESpriteRender(void);  // 0x800906BC

    // Methods
    void SpriteRenderOrderTableCallback(ELevelDrawData &, EOrderTableData *);  // 0x8009101C (104B)
    void DeleteShaders(void);  // 0x80090724 (388B)
    void Update(void);  // 0x800908A8 (656B)
    void DrawIntoOrderTable(void);  // 0x80090B38 (1252B)
    void DrawDirectly(ERC *);  // 0x80091084 (1980B)
    void SetUpRect(ERC *, EVec3 &, float, float, ESpriteRender::SpriteData &);  // 0x80092398 (1164B)
    void SetUpDoubleRect(ERC *, EVec3 &, float, float, ERShader *, ERShader *, ESpriteRender::SpriteData &);  // 0x80092824 (2100B)
    void SetSprite(void);  // 0x80091840 (2904B)
    /* ? */ GetObject(void);  // 0x80095F5C (44B)
    /* ? */ GetMarked(void);  // 0x80095F88 (44B)
    /* ? */ GetMarkedAsNew(void);  // 0x80095FB4 (44B)
    void Mark(void);  // 0x80095FE0 (40B)
    void MarkAsNew(void);  // 0x80096008 (40B)

    // ---- Field Layout (from assembly analysis) ----
    f32 m_upDoubleRect;  // 0x000 [R/W] (DrawDirectly, DrawIntoOrderTable, SetSprite, ...)
    u8 m_upDoubleRect_001;  // 0x001 [W] (SetUpDoubleRect, SetUpRect)
    u8 m_upDoubleRect_002;  // 0x002 [W] (SetUpDoubleRect, SetUpRect)
    u8 m_upDoubleRect_003;  // 0x003 [W] (SetUpDoubleRect, SetUpRect)
    f32 m_upDoubleRect_004;  // 0x004 [R/W] (DrawDirectly, DrawIntoOrderTable, SetSprite, ...)
    u8 m_upDoubleRect_005;  // 0x005 [W] (SetUpDoubleRect, SetUpRect)
    u8 m_upDoubleRect_006;  // 0x006 [W] (SetUpDoubleRect, SetUpRect)
    u8 m_upDoubleRect_007;  // 0x007 [W] (SetUpDoubleRect, SetUpRect)
    f32 m_upDoubleRect_008;  // 0x008 [R/W] (DrawDirectly, DrawIntoOrderTable, SetSprite, ...)
    f32 m_upDoubleRect_00C;  // 0x00C [R/W] (DeleteShaders, DrawDirectly, DrawIntoOrderTable, ...)
    f32 m_upDoubleRect_010;  // 0x010 [R/W] (DeleteShaders, DrawDirectly, DrawIntoOrderTable, ...)
    f32 m_upDoubleRect_014;  // 0x014 [R/W] (DeleteShaders, SetSprite, SetUpDoubleRect, ...)
    f32 m_upDoubleRect_018;  // 0x018 [R/W] (DeleteShaders, DrawDirectly, SetSprite, ...)
    f32 m_upDoubleRect_01C;  // 0x01C [R/W] (DeleteShaders, SetSprite, SetUpDoubleRect, ...)
    u32 m_sprite;  // 0x020 [R/W] (DeleteShaders, DrawDirectly, SetSprite, ...)
    u32 m_sprite_024;  // 0x024 [R/W] (DeleteShaders, DrawDirectly, SetSprite, ...)
    u32 m_sprite_028;  // 0x028 [R/W] (DeleteShaders, SetSprite, Update)
    u32 m_sprite_02C;  // 0x02C [R/W] (DeleteShaders, DrawDirectly, SetSprite, ...)
    u32 m_sprite_030;  // 0x030 [R/W] (DeleteShaders, SetSprite, Update)
    u8 _pad_034[4];  // 0x034
    f32 m_upDoubleRect_038;  // 0x038 [R/W] (DrawDirectly, SetSprite, SetUpDoubleRect)
    f32 m_sprite_03C;  // 0x03C [R/W] (DrawDirectly, SetSprite)
    f32 m_sprite_040;  // 0x040 [R/W] (DrawDirectly, SetSprite)
    u8 _pad_044[4];  // 0x044
    u32 m_sprite_048;  // 0x048 [R] (SetSprite)
    f32 m_sprite_04C;  // 0x04C [W] (SetSprite)
    f32 m_directly;  // 0x050 [R] (DrawDirectly)
    f32 m_directly_054;  // 0x054 [R] (DrawDirectly)
    f32 m_directly_058;  // 0x058 [R/W] (DrawDirectly)
    f32 m_sprite_05C;  // 0x05C [R/W] (DrawDirectly, SetSprite)
    f32 m_sprite_060;  // 0x060 [R/W] (DrawDirectly, SetSprite)
    f32 m_sprite_064;  // 0x064 [R/W] (DrawDirectly, SetSprite)
    u8 _pad_068[8];  // 0x068
    f32 m_sprite_070;  // 0x070 [W] (SetSprite)
    u8 _pad_074[8];  // 0x074
    f32 m_directly_07C;  // 0x07C [W] (DrawDirectly)
    f32 m_sprite_080;  // 0x080 [R/W] (DrawDirectly, SetSprite)
    f32 m_sprite_084;  // 0x084 [R/W] (DrawDirectly, SetSprite)
    f32 m_sprite_088;  // 0x088 [R/W] (DrawDirectly, SetSprite)
    u8 _pad_08C[8];  // 0x08C
    u32 m_sprite_094;  // 0x094 [W] (SetSprite)
    s16 m_field_098;  // 0x098 [R] (DrawDirectly, DrawIntoOrderTable, SpriteRenderOrderTableCallback)
    u8 _pad_09A[2];  // 0x09A
    u32 m_intoOrderTable;  // 0x09C [R] (DrawDirectly, DrawIntoOrderTable)
    u8 _pad_0A0[8];  // 0x0A0
    u32 m_field_0A8;  // 0x0A8 [W] (SpriteRenderOrderTableCallback)
    u32 m_intoOrderTable_0AC;  // 0x0AC [W] (DrawIntoOrderTable, SpriteRenderOrderTableCallback)
    s16 m_upDoubleRect_0B0;  // 0x0B0 [R/W] (SetUpDoubleRect, SpriteRenderOrderTableCallback)
    u8 _pad_0B2[2];  // 0x0B2
    u32 m_upDoubleRect_0B4;  // 0x0B4 [R/W] (SetUpDoubleRect, SpriteRenderOrderTableCallback)
    u8 _pad_0B8[0x10];  // 0x0B8
    u32 m_intoOrderTable_0C8;  // 0x0C8 [R] (DrawIntoOrderTable)
    u8 _pad_0CC[0x10];  // 0x0CC
    u32 m_intoOrderTable_0DC;  // 0x0DC [W] (DrawIntoOrderTable)
    f32 m_upDoubleRect_0E0;  // 0x0E0 [R] (SetUpDoubleRect)
    u8 _pad_0E4[4];  // 0x0E4
    u32 m_field_0E8;  // 0x0E8 [W] (~ESpriteRender)
    u8 _pad_0EC[4];  // 0x0EC
    f32 m_upDoubleRect_0F0;  // 0x0F0 [R] (DrawDirectly, SetUpDoubleRect)
    u8 _pad_0F4[0x2DC];  // 0x0F4
    u32 m_intoOrderTable_3D0;  // 0x3D0 [R] (DrawIntoOrderTable)
    u8 _pad_3D4[0x18];  // 0x3D4
    u32 m_field_3EC;  // 0x3EC [R] (Update)
    u8 _pad_3F0[0x1110];  // 0x3F0
    f32 m_intoOrderTable_1500;  // 0x1500 [R] (DrawIntoOrderTable)
    u8 _pad_1504[4];  // 0x1504
    f32 m_directly_1508;  // 0x1508 [R] (DrawDirectly)
    u8 _pad_150C[0x48];  // 0x150C
    f32 m_upDoubleRect_1554;  // 0x1554 [R] (SetUpDoubleRect)
    u8 _pad_1558[0x493C];  // 0x1558
    u32 m_intoOrderTable_5E94;  // 0x5E94 [R] (DrawIntoOrderTable)
};

#endif // ESPRITERENDER_H
