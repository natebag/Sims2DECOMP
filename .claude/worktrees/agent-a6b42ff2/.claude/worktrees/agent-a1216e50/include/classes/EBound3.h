#ifndef EBOUND3_H
#define EBOUND3_H

#include "types.h"

// EBound3 - struct layout extracted from assembly analysis
// Estimated minimum size: 0x10 (16 bytes)
// 4 known fields (4 named), 46 methods

class EBound3 {
public:
    // Constructors / Destructors
    EBound3(void)  // 0x8007DBB8
    EBound3(EBound3 &)  // 0x8007DC5C
    EBound3(EBoundSphere &)  // 0x80141D10
    EBound3(EVec3 &)  // 0x8064F54C
    EBound3(EVec3 &, EVec3 &)  // 0x8065DF10

    // Methods
    void operator=(EVec3 &);  // 0x8007DCEC (112B)
    void operator+=(EVec3 &);  // 0x8007DD5C (288B)
    bool IsWithin(EBound3 &);  // 0x8007DE7C (364B)
    void Center(void);  // 0x80095CE8 (100B)
    void operator=(EBound3 &);  // 0x800D763C (108B)
    void Width(void);  // 0x801268EC (104B)
    void Depth(void);  // 0x80126954 (104B)
    void operator+=(EBound3 &);  // 0x80327320 (344B)
    void operator*=(float);  // 0x80327478 (96B)
    void Overlap(EBound3 &);  // 0x805F2528 (364B)
    void Height(void);  // 0x806323FC (104B)
    void operator!=(EBound3 &);  // 0x8064F6DC (128B)
    void Overlap(EVec3 &);  // 0x8064F8B4 (352B)
    void CalcBoundSphere(EBoundSphere &);  // 0x80746CC8 (152B)
    void Compute(EBoundSphere &);  // 0x80746E64 (280B)
    /* ? */ GetCorners(EVec3 *);  // 0x807460B4 (320B)
    void Compute(EVec3 &, float);  // 0x80746D60 (260B)
    /* ? */ GetCorners(EVec4 *);  // 0x807461F4 (332B)
    void Transform(EMat4 &, EVec3 *);  // 0x80746340 (360B)
    void Transform(EMat4 &, EBound3 &);  // 0x807464A8 (164B)
    void Compute(EVec3 *, int, EMat4 &);  // 0x80746B24 (212B)
    void Add(EVec3 *, int);  // 0x8074654C (324B)
    void Add(float *, int);  // 0x80746690 (236B)
    void Add(EVec3 *, int, EMat4 &);  // 0x8074677C (352B)
    void Add(EBound3 &, EMat4 &);  // 0x807468DC (232B)
    void Compute(EVec3 *, int);  // 0x807469C4 (352B)
    void Compute(EBound3 &, EMat4 &);  // 0x80746BF8 (208B)

    // ---- Field Layout (from assembly analysis) ----
    f32 m_corners;  // 0x000 [R/W] (CalcBoundSphere, Compute, GetCorners)
    f32 m_corners_004;  // 0x004 [R/W] (CalcBoundSphere, Compute, GetCorners)
    f32 m_corners_008;  // 0x008 [R/W] (CalcBoundSphere, Compute, GetCorners)
    f32 m_corners_00C;  // 0x00C [R/W] (CalcBoundSphere, Compute, GetCorners)
};

#endif // EBOUND3_H
