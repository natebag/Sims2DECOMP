#ifndef WORLDMAP_H
#define WORLDMAP_H

#include "types.h"

// WorldMap - struct layout extracted from assembly analysis
// Estimated minimum size: 0x11C (284 bytes)
// 25 known fields (1 named), 16 methods

class WorldMap {
public:
    // Constructors / Destructors
    WorldMap(void)  // 0x801E32C0
    ~WorldMap(void);  // 0x801E3560

    // Methods
    /* ? */ GetDt(void);  // 0x8000E384 (44B)
    /* ? */ GetHour(void);  // 0x8000E3B0 (44B)
    /* ? */ GetMinute(void);  // 0x8000E3DC (44B)
    /* ? */ GetWeather(void);  // 0x8000E408 (44B)
    void Animate(bool);  // 0x801E9410 (40B)
    void ShowLogo(bool);  // 0x801E93E8 (40B)
    void Update(void);  // 0x801E3A08 (1288B)
    void Draw(ERC *);  // 0x801E3F10 (424B)
    void Reset(void);  // 0x801E37F4 (532B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [R/W] - vtable pointer (Reset, Update, WorldMap)
    u32 m_field_004;  // 0x004 [R/W] (Draw, Reset, WorldMap, ...)
    u32 m_field_008;  // 0x008 [R/W] (Draw, Reset, Update, ...)
    u32 m_field_00C;  // 0x00C [R/W] (Update, WorldMap, ~WorldMap)
    u32 m_field_010;  // 0x010 [R/W] (Update, WorldMap, ~WorldMap)
    u32 m_field_014;  // 0x014 [R/W] (Draw, Update, WorldMap, ...)
    u32 m_field_018;  // 0x018 [R] (Draw)
    u8 _pad_01C[0x38];  // 0x01C
    f32 m_field_054;  // 0x054 [W] (Update)
    f32 m_field_058;  // 0x058 [W] (Update)
    u8 _pad_05C[8];  // 0x05C
    u32 m_field_064;  // 0x064 [W] (Update)
    u32 m_field_068;  // 0x068 [W] (Update)
    u8 _pad_06C[0x24];  // 0x06C
    u32 m_field_090;  // 0x090 [R/W] (Update, WorldMap, ~WorldMap)
    u32 m_field_094;  // 0x094 [R/W] (Update, WorldMap, ~WorldMap)
    u32 m_field_098;  // 0x098 [R/W] (Draw, Update, WorldMap, ...)
    u32 m_field_09C;  // 0x09C [R/W] (Draw, WorldMap)
    u8 _pad_0A0[4];  // 0x0A0
    u32 m_field_0A4;  // 0x0A4 [W] (WorldMap)
    u8 _pad_0A8[0x14];  // 0x0A8
    f32 m_field_0BC;  // 0x0BC [R/W] (Reset, Update, WorldMap)
    f32 m_field_0C0;  // 0x0C0 [R/W] (Update, WorldMap)
    f32 m_field_0C4;  // 0x0C4 [W] (Update, WorldMap)
    u32 m_field_0C8;  // 0x0C8 [W] (Update, WorldMap)
    u32 m_field_0CC;  // 0x0CC [W] (Update, WorldMap)
    u32 m_field_0D0;  // 0x0D0 [W] (Update, WorldMap)
    u32 m_field_0D4;  // 0x0D4 [R/W] (Draw, WorldMap)
    u32 m_field_0D8;  // 0x0D8 [R/W] (Update, WorldMap)
    u8 _pad_0DC[0x3C];  // 0x0DC
    u32 m_field_118;  // 0x118 [R] (Reset)
};

#endif // WORLDMAP_H
