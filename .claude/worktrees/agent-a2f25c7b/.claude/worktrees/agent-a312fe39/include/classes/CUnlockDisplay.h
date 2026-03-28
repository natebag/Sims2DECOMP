#ifndef CUNLOCKDISPLAY_H
#define CUNLOCKDISPLAY_H

#include "types.h"

// CUnlockDisplay - struct layout extracted from assembly analysis
// Estimated minimum size: 0x5FAC (24492 bytes)
// 30 known fields (15 named), 54 methods

class CUnlockDisplay {
public:
    // Constructors / Destructors
    CUnlockDisplay(void)  // 0x801706CC
    ~CUnlockDisplay(void);  // 0x80170AEC

    // Methods
    void SetDisplayBoxTop(float);  // 0x801717C0 (176B)
    void SetDisplayBoxLeft(float);  // 0x80171710 (176B)
    void SetDisplayBoxBottom(float);  // 0x80171920 (176B)
    void SetDisplayBoxRight(float);  // 0x80171870 (176B)
    void Draw(ERC *);  // 0x80171A50 (3704B)
    void SetAmbientLight(float, float, float);  // 0x80172988 (128B)
    void SetDirectLight(float, float, float, int);  // 0x801728C8 (192B)
    void SetDirectLightDir(EVec3, bool, int);  // 0x80172BB0 (188B)
    void ManualCameraPos(float, float, float);  // 0x80171A04 (76B)
    void destroyObjects(void);  // 0x80170D80 (184B)
    void makeObjects(void);  // 0x80170B74 (524B)
    void SetupForObject(ObjectDefinition *, EVec3 &, EVec3 &, EVec3 &);  // 0x80170E38 (504B)
    /* ? */ GetBedOtherHalfIDs(unsigned int, unsigned int &, unsigned int &);  // 0x80172C94 (720B)
    void SetupForPromotion(cXPerson *, void *);  // 0x80171030 (816B)
    void SetupForSocial(void *);  // 0x80171360 (172B)
    void Update(void);  // 0x8017140C (772B)
    void SetViewZoomFactor(float);  // 0x801719D0 (52B)
    bool HasDrawn(void);  // 0x80172A08 (152B)
    void ObjectHasMultiColor(void);  // 0x80172AA0 (168B)
    void SetMultiColorNumber(int);  // 0x80172B48 (104B)
    void RemoveAllDirectLights(void);  // 0x80172C6C (40B)
    bool IsDone(void);  // 0x8017598C (44B)
    void Hide(void);  // 0x801759B8 (40B)
    void UnHide(void);  // 0x801759E0 (40B)
    void DonePreloadObject(void);  // 0x80175A08 (44B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [R/W] - vtable pointer (GetBedOtherHalfIDs, makeObjects)
    u32 m_bedOtherHalfIDs_004;  // 0x004 [R] (GetBedOtherHalfIDs)
    u32 m_bedOtherHalfIDs_008;  // 0x008 [R] (GetBedOtherHalfIDs)
    u32 m_bedOtherHalfIDs_00C;  // 0x00C [R] (GetBedOtherHalfIDs)
    u32 m_bedOtherHalfIDs_010;  // 0x010 [R] (GetBedOtherHalfIDs)
    u32 m_bedOtherHalfIDs_014;  // 0x014 [R] (GetBedOtherHalfIDs)
    u8 _pad_018[0x18];  // 0x018
    u32 m_upForPromotion;  // 0x030 [R] (SetupForPromotion)
    u32 m_upForPromotion_034;  // 0x034 [W] (SetupForPromotion)
    u32 m_upForPromotion_038;  // 0x038 [W] (SetupForPromotion)
    u8 _pad_03C[0x44];  // 0x03C
    u32 m_upForPromotion_080;  // 0x080 [W] (SetupForPromotion)
    u8 _pad_084[0x18];  // 0x084
    u32 m_field_09C;  // 0x09C [R] (Draw)
    u8 _pad_0A0[0x3A0];  // 0x0A0
    u32 m_directLightDir;  // 0x440 [R/W] (Draw, SetDirectLight, SetDirectLightDir)
    u8 _pad_444[4];  // 0x444
    u32 m_field_448;  // 0x448 [R/W] (CUnlockDisplay, Update)
    u32 m_upForObject;  // 0x44C [R/W] (CUnlockDisplay, Draw, SetupForObject, ...)
    u32 m_field_450;  // 0x450 [W] (CUnlockDisplay, Update)
    u32 m_field_454;  // 0x454 [R/W] (CUnlockDisplay, Draw, Update)
    u32 m_field_458;  // 0x458 [R/W] (CUnlockDisplay, Draw, Update)
    u32 m_field_45C;  // 0x45C [R/W] (CUnlockDisplay, Draw, Update)
    f32 m_field_460;  // 0x460 [R/W] (CUnlockDisplay, Draw, Update)
    u32 m_multiColorNumber;  // 0x464 [R/W] (CUnlockDisplay, Draw, ObjectHasMultiColor, ...)
    f32 m_field_468;  // 0x468 [R/W] (CUnlockDisplay, Draw)
    f32 m_field_46C;  // 0x46C [R/W] (CUnlockDisplay, Draw)
    f32 m_field_470;  // 0x470 [R/W] (CUnlockDisplay, Draw)
    f32 m_field_474;  // 0x474 [R/W] (CUnlockDisplay, Draw)
    u8 _pad_478[0x18];  // 0x478
    u32 m_upForPromotion_490;  // 0x490 [R/W] (CUnlockDisplay, SetupForPromotion, makeObjects)
    u32 m_upForPromotion_494;  // 0x494 [R/W] (CUnlockDisplay, SetupForPromotion, makeObjects)
    f32 m_field_498;  // 0x498 [R/W] (CUnlockDisplay, Draw)
    u32 m_field_49C;  // 0x49C [R] (Draw)
    u8 _pad_4A0[0x48];  // 0x4A0
    u32 m_field_4E8;  // 0x4E8 [W] (CUnlockDisplay, ~CUnlockDisplay)
    u8 _pad_4EC[0x5ABC];  // 0x4EC
    f32 m_field_5FA8;  // 0x5FA8 [R] (Draw)
};

#endif // CUNLOCKDISPLAY_H
