#ifndef EQUAT_H
#define EQUAT_H

#include "types.h"

// EQuat - struct layout extracted from assembly analysis
// Estimated minimum size: 0x10 (16 bytes)
// 4 known fields (0 named), 44 methods

class EQuat {
public:
    // Constructors / Destructors
    EQuat(void)  // 0x80031408
    EQuat(EQuat &)  // 0x80031430
    EQuat(float, float, float, float)  // 0x8004E1E0
    EQuat(EVec3 &, float)  // 0x8075D788

    // Methods
    void Id(void);  // 0x8003147C (72B)
    void operator-(EQuat &);  // 0x8004C3C4 (140B)
    void Mag(void);  // 0x8004C450 (80B)
    void MagSq(void);  // 0x8004E228 (100B)
    void Blend(float, EQuat &, EQuat);  // 0x80758520 (116B)
    void Set(EVec3 &, float);  // 0x8075D410 (300B)
    void FromMat4(EMat4 &);  // 0x8075C74C (980B)
    void ExtractAxisRotation(EVec3 &);  // 0x8075CC6C (132B)
    void ToMat4(EMat4 &);  // 0x8075C4C4 (648B)
    void Slerp(float, EQuat &, EQuat);  // 0x8075CEB8 (568B)
    void Print(void);  // 0x8075C454 (112B)
    void ToAxisAngle(EVec3 &, float &);  // 0x8075CB20 (332B)
    void Set(float, float, float);  // 0x8075CCF0 (356B)
    void operator*(EQuat &);  // 0x8075DA9C (340B)
    void RemoveAxisFlip(EQuat &);  // 0x8075CE54 (100B)
    void Dot(EQuat &);  // 0x8075DC90 (104B)
    void Negate(void);  // 0x8075DC38 (88B)
    void LinearBlend(float, EQuat &, EQuat &);  // 0x8075DCF8 (188B)
    void operator*(float);  // 0x8075DA18 (132B)
    void operator+(EQuat &);  // 0x8075D98C (140B)
    void SlerpNoInvert(float, EQuat &, EQuat &);  // 0x8075D0F0 (540B)
    void Scale(float, EQuat &);  // 0x8075D30C (260B)
    void operator[](int);  // 0x8075D82C (176B)
    void Normalize(void);  // 0x8075E14C (124B)
    void operator/=(float);  // 0x8075E24C (124B)
    void LinearBlendNoNormalize(float, EQuat &, EQuat &);  // 0x80901780 (180B)

    // ---- Field Layout (from assembly analysis) ----
    f32 m_field_000;  // 0x000 [R/W] (FromMat4, RemoveAxisFlip, Scale, ...)
    f32 m_field_004;  // 0x004 [R/W] (FromMat4, RemoveAxisFlip, Scale, ...)
    f32 m_field_008;  // 0x008 [R/W] (FromMat4, RemoveAxisFlip, Scale, ...)
    f32 m_field_00C;  // 0x00C [R/W] (FromMat4, RemoveAxisFlip, Scale, ...)
};

#endif // EQUAT_H
