#ifndef SPRITESLOT_H
#define SPRITESLOT_H

#include "types.h"

// SpriteSlot - struct layout extracted from assembly analysis
// Estimated minimum size: 0x68 (104 bytes)
// 26 known fields (8 named), 75 methods

class SpriteSlot {
public:
    // Constructors / Destructors
    SpriteSlot(SpriteSlot &)  // 0x80380BAC
    SpriteSlot(cXObject *)  // 0x803BE760
    SpriteSlot(SlotDescriptor *, cXObject *)  // 0x803BE8BC
    ~SpriteSlot(void);  // 0x803BEA80

    // Methods
    bool IsActive(void);  // 0x803C29D0 (60B)
    void SetPriority(int);  // 0x803C2BCC (40B)
    void Reset(void);  // 0x803BF310 (120B)
    void SetOptions(int);  // 0x803C2A5C (40B)
    void SetPopSize(float);  // 0x803C2A84 (40B)
    void SetSprite(unsigned int, int, int, bool);  // 0x803BEACC (168B)
    void UseBalloonSprite(int);  // 0x803C2A0C (40B)
    void UseOverlaySprite(int);  // 0x803C2A34 (40B)
    void ActivateForever(void);  // 0x803C2958 (60B)
    /* ? */ GetOptions(void);  // 0x803C2C20 (44B)
    /* ? */ GetAltOffset(void);  // 0x803C2CD4 (44B)
    /* ? */ GetSizeMultiplierX(void);  // 0x803C2D28 (44B)
    /* ? */ GetSizeMultiplierY(void);  // 0x803C2D54 (44B)
    /* ? */ GetAlpha(void);  // 0x803C2D80 (44B)
    /* ? */ GetSpriteID(void);  // 0x803C2AF0 (44B)
    /* ? */ GetIsSkillMeter(void);  // 0x803C2C4C (52B)
    /* ? */ GetSelector(void);  // 0x803C2AAC (68B)
    /* ? */ GetBalloonSpriteID(void);  // 0x803C2B1C (44B)
    /* ? */ GetOverlaySpriteID(void);  // 0x803C2B48 (44B)
    /* ? */ GetPPerson(void);  // 0x803C2BA0 (44B)
    /* ? */ GetPriority(void);  // 0x803C2BF4 (44B)
    void Deactivate(void);  // 0x803C2994 (60B)
    void SetSprite(ObjSelector *);  // 0x803BEB74 (128B)
    void AlternateWithSprite(int, int);  // 0x803BEC44 (100B)
    void SetShowOverInactivePeople(bool);  // 0x803C2CAC (40B)
    void ActivateForLoops(int);  // 0x803BF2B4 (92B)
    void ActivateForTicks(int);  // 0x803BF0D0 (484B)
    void Tick(void);  // 0x803BECA8 (1064B)
    void SetAltOffset(float);  // 0x803C2D00 (40B)
    void WriteSlot(SlotDescriptor *);  // 0x803BEA20 (96B)
    void ChangeToSprite(int);  // 0x803BEBF4 (80B)
    /* ? */ GetTicksPerFrame(void);  // 0x803C2934 (36B)
    /* ? */ GetCurrentFrame(void);  // 0x803C2B74 (44B)
    /* ? */ GetShowOverInactivePeople(void);  // 0x803C2C80 (44B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [W] - vtable pointer (SpriteSlot)
    f32 m_field_004;  // 0x004 [W] (SpriteSlot)
    f32 m_field_008;  // 0x008 [W] (SpriteSlot)
    f32 m_field_00C;  // 0x00C [R/W] (SpriteSlot, Tick)
    u32 m_field_010;  // 0x010 [R/W] (ActivateForTicks, SpriteSlot, Tick)
    u32 m_field_014;  // 0x014 [R/W] (ActivateForTicks, Tick)
    u32 m_sprite;  // 0x018 [R/W] (ActivateForTicks, SetSprite, SpriteSlot, ...)
    u32 m_field_01C;  // 0x01C [R/W] (ActivateForTicks, SpriteSlot, Tick)
    u32 m_field_020;  // 0x020 [R/W] (SpriteSlot, Tick)
    u32 m_field_024;  // 0x024 [R/W] (SpriteSlot, Tick)
    u32 m_sprite_028;  // 0x028 [W] (SetSprite, SpriteSlot)
    u32 m_sprite_02C;  // 0x02C [R/W] (SetSprite, Tick)
    u32 m_sprite_030;  // 0x030 [R/W] (SetSprite, SpriteSlot, Tick)
    u32 m_sprite_034;  // 0x034 [R/W] (SetSprite, Tick)
    u32 m_field_038;  // 0x038 [R/W] (ActivateForTicks, Tick)
    u32 m_sprite_03C;  // 0x03C [W] (SetSprite, SpriteSlot)
    u32 m_sprite_040;  // 0x040 [W] (SetSprite, SpriteSlot)
    u32 m_field_044;  // 0x044 [W] (SpriteSlot, Tick)
    u32 m_field_048;  // 0x048 [R] (ActivateForTicks, Tick)
    f32 m_field_04C;  // 0x04C [W] (SpriteSlot)
    f32 m_field_050;  // 0x050 [W] (Tick)
    f32 m_field_054;  // 0x054 [W] (Tick)
    f32 m_field_058;  // 0x058 [W] (Tick)
    f32 m_field_05C;  // 0x05C [R] (Tick)
    u32 m_field_060;  // 0x060 [W] (SpriteSlot)
    u32 m_field_064;  // 0x064 [R/W] (ActivateForTicks, SpriteSlot)
};

#endif // SPRITESLOT_H
