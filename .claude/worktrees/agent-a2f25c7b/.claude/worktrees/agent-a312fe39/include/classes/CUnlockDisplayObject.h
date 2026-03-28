#ifndef CUNLOCKDISPLAYOBJECT_H
#define CUNLOCKDISPLAYOBJECT_H

#include "types.h"

// CUnlockDisplayObject - struct layout extracted from assembly analysis
// Estimated minimum size: 0x88 (136 bytes)
// 28 known fields (10 named), 58 methods

class CUnlockDisplayObject {
public:
    // Constructors / Destructors
    CUnlockDisplayObject(void)  // 0x80175BF0
    ~CUnlockDisplayObject(void);  // 0x80175DB4

    // Methods
    void SetCharacterID(unsigned int);  // 0x801794DC (80B)
    void SetModelID(unsigned int);  // 0x801794B4 (40B)
    void SetAnimationID(unsigned int);  // 0x8017952C (80B)
    void SetPos(EVec3 &);  // 0x8017957C (68B)
    void SetRot(EVec3 &);  // 0x80179610 (68B)
    void SetRotAdd(EVec3 &);  // 0x801796A4 (68B)
    void SetAnimationLoops(unsigned int);  // 0x80179738 (40B)
    void Update(void);  // 0x80176130 (1612B)
    bool IsReady(void);  // 0x801797C8 (44B)
    /* ? */ GetRadius(void);  // 0x80179848 (44B)
    void SetTrigger(void);  // 0x801797F4 (40B)
    bool IsDone(void);  // 0x8017981C (44B)
    bool IsActive(void);  // 0x80176960 (84B)
    /* ? */ GetCenter(void);  // 0x80179874 (80B)
    /* ? */ GetRot(void);  // 0x80179654 (80B)
    /* ? */ GetPos(void);  // 0x801795C0 (80B)
    bool HasDrawn(void);  // 0x801798C4 (44B)
    /* ? */ GetModel(void);  // 0x801769B4 (44B)
    void SetMultiColorIndex(int);  // 0x801769E0 (200B)
    void ServiceDataReady(void);  // 0x80175EFC (220B)
    void Setup(void);  // 0x80175FD8 (344B)
    void Draw(ERC *);  // 0x8017677C (484B)
    bool IsSimple(void);  // 0x80179488 (44B)
    /* ? */ GetRotAdd(void);  // 0x801796E8 (80B)
    void SetPlayAndHold(bool);  // 0x80179760 (40B)
    void SetOrient(EMat4 &);  // 0x80179788 (64B)
    /* ? */ GetType(void);  // 0x801798F0 (44B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [R/W] - vtable pointer (CUnlockDisplayObject, SetMultiColorIndex)
    u32 m_field_004;  // 0x004 [W] (CUnlockDisplayObject)
    u32 m_field_008;  // 0x008 [R/W] (CUnlockDisplayObject, Update, ~CUnlockDisplayObject)
    u32 m_field_00C;  // 0x00C [R/W] (CUnlockDisplayObject, Draw, Update)
    u32 m_up;  // 0x010 [R/W] (CUnlockDisplayObject, Draw, Setup, ...)
    u32 m_up_014;  // 0x014 [R/W] (CUnlockDisplayObject, Draw, ServiceDataReady, ...)
    u32 m_multiColorIndex_018;  // 0x018 [R/W] (CUnlockDisplayObject, SetMultiColorIndex, Update)
    u32 m_multiColorIndex_01C;  // 0x01C [R/W] (CUnlockDisplayObject, Draw, SetMultiColorIndex, ...)
    u32 m_field_020;  // 0x020 [R/W] (CUnlockDisplayObject, ServiceDataReady)
    u32 m_orient;  // 0x024 [R/W] (CUnlockDisplayObject, Draw, SetOrient, ...)
    f32 m_field_028;  // 0x028 [W] (CUnlockDisplayObject, Update)
    u32 m_up_02C;  // 0x02C [R/W] (CUnlockDisplayObject, ServiceDataReady, Setup, ...)
    u32 m_up_030;  // 0x030 [R/W] (CUnlockDisplayObject, Setup, Update)
    u32 m_field_034;  // 0x034 [R/W] (CUnlockDisplayObject, ServiceDataReady, Update, ...)
    u32 m_field_038;  // 0x038 [R/W] (CUnlockDisplayObject, Update)
    u32 m_field_03C;  // 0x03C [W] (CUnlockDisplayObject)
    u8 _pad_040[8];  // 0x040
    f32 m_field_048;  // 0x048 [R/W] (CUnlockDisplayObject, Update)
    u8 _pad_04C[8];  // 0x04C
    f32 m_field_054;  // 0x054 [R/W] (CUnlockDisplayObject, Update)
    u8 _pad_058[8];  // 0x058
    f32 m_field_060;  // 0x060 [R/W] (Update)
    f32 m_field_064;  // 0x064 [R/W] (Update)
    f32 m_field_068;  // 0x068 [R/W] (Update)
    u32 m_field_06C;  // 0x06C [R/W] (CUnlockDisplayObject, Update)
    u32 m_field_070;  // 0x070 [R/W] (CUnlockDisplayObject, Update)
    u32 m_multiColorIndex_074;  // 0x074 [R/W] (CUnlockDisplayObject, SetMultiColorIndex, Update)
    u32 m_field_078;  // 0x078 [W] (CUnlockDisplayObject, Update)
    u32 m_field_07C;  // 0x07C [W] (CUnlockDisplayObject, Draw)
    u32 m_up_080;  // 0x080 [R/W] (CUnlockDisplayObject, Draw, ServiceDataReady, ...)
    u32 m_field_084;  // 0x084 [R/W] (CUnlockDisplayObject, Update, ~CUnlockDisplayObject)
};

#endif // CUNLOCKDISPLAYOBJECT_H
