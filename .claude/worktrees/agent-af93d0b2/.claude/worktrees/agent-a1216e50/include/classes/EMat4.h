#ifndef EMAT4_H
#define EMAT4_H

#include "types.h"

// EMat4 - struct layout extracted from assembly analysis
// Estimated minimum size: 0x40 (64 bytes)
// 16 known fields (8 named), 144 methods

class EMat4 {
public:
    // Constructors / Destructors
    EMat4(void)  // 0x8000D924
    EMat4(EMat4 &)  // 0x80018DF8
    EMat4(EMat4 &, EMat4 &)  // 0x8004DF94

    // Methods
    void operator=(EMat4 &);  // 0x8000D94C (172B)
    void operator[](int);  // 0x80018E40 (176B)
    void VectorRotate(EVec3 &);  // 0x8002257C (232B)
    void operator*(EVec3 &);  // 0x8004BFB4 (244B)
    void operator*(EMat4 &);  // 0x8004BEF4 (84B)
    void SwapXY(void);  // 0x8007D9A0 (136B)
    void Translate(float, float, float);  // 0x8007D91C (132B)
    void Mult(EVec4 &, EVec4 &);  // 0x8007DAD4 (84B)
    void PostTranslate(float, float, float);  // 0x8008C0AC (132B)
    void PreScale(float, float, float);  // 0x8008C130 (132B)
    void Scale(float, float, float);  // 0x8008C028 (132B)
    void operator*=(EMat4 &);  // 0x804498A0 (108B)
    void Scale(float);  // 0x80652A48 (100B)
    void Id(void);  // 0x80753F00 (232B)
    /* ? */ GetScaleX(void);  // 0x807540B0 (92B)
    /* ? */ GetScaleY(void);  // 0x8075410C (92B)
    void Scale(EVec3 &);  // 0x80754048 (104B)
    void PostRotateX(float);  // 0x807551C0 (392B)
    void PostRotateY(float);  // 0x80755488 (392B)
    void PostRotateZ(float);  // 0x80755750 (392B)
    void PostTranslate(EVec3 &);  // 0x807558D8 (144B)
    void RotateZ(float);  // 0x807542B4 (120B)
    void Mult4x4(EMat4 &, EMat4 &);  // 0x807532DC (72B)
    void Rotate(EVec3 &, float);  // 0x80754D64 (796B)
    void LookAtPos(EVec3 &, EVec3 &, EVec3 &);  // 0x807562A8 (348B)
    void Invert(EMat4 &);  // 0x8075432C (2152B)
    void Normalize(void);  // 0x80753BE4 (160B)
    /* ? */ GetLookAtPos(EVec3 &, EVec3 &, EVec3 &);  // 0x80756170 (312B)
    void BlendQuat(float, EMat4 &, EMat4 &);  // 0x80757150 (1240B)
    void PreRotateZ(float);  // 0x80755610 (320B)
    void Translate(EVec3 &);  // 0x80753FE8 (96B)
    void PreScale(float);  // 0x80753324 (196B)
    void RotateY(float);  // 0x8075423C (120B)
    void PreScale(EVec3 &);  // 0x807533E8 (312B)
    /* ? */ GetColumn(int, EVec3 &);  // 0x807538E4 (184B)
    /* ? */ GetHPR(float &, float &, float &);  // 0x80756034 (208B)
    void RotateX(float);  // 0x807541C4 (120B)
    void Transpose(EMat4 &);  // 0x80753C84 (308B)
    void PreRotateX(float);  // 0x80755080 (320B)
    void PreRotateY(float);  // 0x80755348 (320B)
    void PreTranslate(EVec3 &);  // 0x80753520 (284B)
    void operator=(float);  // 0x807537B8 (300B)
    /* ? */ GetColumn(int, EVec4 &);  // 0x8075399C (228B)
    void SetColumn(int, EVec3 &);  // 0x80753A80 (160B)
    void SetColumn(int, EVec4 &);  // 0x80753B20 (196B)
    void Transpose(void);  // 0x80753DB8 (328B)
    /* ? */ GetScaleZ(void);  // 0x80754168 (92B)
    void InvertSimple(EMat4 &);  // 0x80754B94 (464B)
    void PostScale(EVec3 &);  // 0x80755968 (396B)
    void PostScale(float);  // 0x80755AF4 (196B)
    void Conform(EVec3 &);  // 0x80755BB8 (296B)
    void OrientPosNormal(EVec3 &, EVec3 &, EVec3 &);  // 0x80755CE0 (104B)
    void LookAtDirect(EVec3 &, EVec3 &, float);  // 0x80756464 (252B)
    void Clamp(void);  // 0x80755D48 (296B)
    void Print(void);  // 0x80755E70 (232B)
    /* ? */ GetMaxScale(void);  // 0x80755F58 (220B)
    void ExtractAxisRotation(EVec3 &);  // 0x80756104 (108B)
    void LookAt(EVec3 &, EVec3 &, EVec3 &);  // 0x80756404 (96B)
    void Invert(void);  // 0x80758454 (88B)
    void LookTo(EVec3 &, EVec3 &, EVec3 &);  // 0x80756560 (348B)
    void Projection(float, float, float, float);  // 0x807566BC (608B)
    void Ortho(float, float, float, float, float, float);  // 0x8075691C (408B)
    void BlendEuler(float, EMat4 &, EMat4 &);  // 0x80756AB4 (1692B)
    void TexturePerspectiveProjection(EVec3 &, EVec3 &, EVec3 &, float, float, float, float);  // 0x80757628 (412B)
    void TexturePlanarProjection(EVec3 &, EVec3 &, EVec3 &, float, float, float, float);  // 0x807577C4 (176B)
    void InvertComplex(void);  // 0x807A4708 (100B)
    void PreTranslate(float, float, float);  // 0x807D5558 (132B)
    void PostScale(float, float, float);  // 0x807EC304 (132B)
    void Mult3x3(EVec3 &, EVec3 &);  // 0x808E9334 (260B)
    void Id3x4(void);  // 0x808EFB24 (120B)

    // ---- Field Layout (from assembly analysis) ----
    f32 m_lookAtPos;  // 0x000 [R/W] (BlendEuler, Conform, GetLookAtPos, ...)
    f32 m_lookAtPos_004;  // 0x004 [R/W] (BlendEuler, Conform, GetHPR, ...)
    f32 m_lookAtPos_008;  // 0x008 [R/W] (BlendEuler, Conform, GetLookAtPos, ...)
    f32 m_field_00C;  // 0x00C [R/W] (BlendEuler, Id, Invert, ...)
    f32 m_field_010;  // 0x010 [R/W] (BlendEuler, Conform, Id, ...)
    f32 m_hPR;  // 0x014 [R/W] (BlendEuler, GetHPR, Id, ...)
    f32 m_field_018;  // 0x018 [R/W] (BlendEuler, Id, Invert, ...)
    f32 m_field_01C;  // 0x01C [R/W] (BlendEuler, Id, Invert, ...)
    f32 m_hPR_020;  // 0x020 [R/W] (BlendEuler, Conform, GetHPR, ...)
    f32 m_hPR_024;  // 0x024 [R/W] (BlendEuler, GetHPR, Id, ...)
    f32 m_hPR_028;  // 0x028 [R/W] (BlendEuler, GetHPR, Id, ...)
    f32 m_field_02C;  // 0x02C [R/W] (BlendEuler, Id, Invert, ...)
    f32 m_lookAtPos_030;  // 0x030 [R/W] (BlendEuler, BlendQuat, GetLookAtPos, ...)
    f32 m_field_034;  // 0x034 [R/W] (BlendEuler, BlendQuat, Id, ...)
    f32 m_field_038;  // 0x038 [R/W] (BlendEuler, BlendQuat, Id, ...)
    f32 m_field_03C;  // 0x03C [W] (BlendEuler, Id, Invert, ...)
};

#endif // EMAT4_H
