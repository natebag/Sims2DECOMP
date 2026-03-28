#ifndef APTMATHOBJ_H
#define APTMATHOBJ_H

#include "types.h"

// AptMathObj - struct layout extracted from assembly analysis
// Estimated minimum size: 0x28 (40 bytes)
// 7 known fields (1 named), 44 methods

class AptMathObj {
public:
    // Constructors / Destructors
    AptMathObj(void)  // 0x806F59D8
    ~AptMathObj(void);  // 0x806F5A38

    // Methods
    void CleanNativeFunctions(void);  // 0x806F0578 (1720B)
    void objectMemberLookup(AptValue *, EAStringC *);  // 0x806F0C30 (3556B)
    void sMethod_sin(AptValue *, int);  // 0x806F1A14 (152B)
    void sMethod_cos(AptValue *, int);  // 0x806F1AAC (152B)
    void sMethod_atan2(AptValue *, int);  // 0x806F1B44 (200B)
    void sMethod_round(AptValue *, int);  // 0x806F1C0C (240B)
    void sMethod_min(AptValue *, int);  // 0x806F1CFC (224B)
    void sMethod_max(AptValue *, int);  // 0x806F1DDC (224B)
    void sMethod_abs(AptValue *, int);  // 0x806F1EBC (212B)
    void sMethod_acos(AptValue *, int);  // 0x806F1F90 (152B)
    void sMethod_asin(AptValue *, int);  // 0x806F2028 (152B)
    void sMethod_atan(AptValue *, int);  // 0x806F20C0 (152B)
    void sMethod_ceil(AptValue *, int);  // 0x806F2158 (152B)
    void sMethod_exp(AptValue *, int);  // 0x806F21F0 (152B)
    void sMethod_floor(AptValue *, int);  // 0x806F2288 (152B)
    void sMethod_log(AptValue *, int);  // 0x806F2320 (152B)
    void sMethod_pow(AptValue *, int);  // 0x806F23B8 (200B)
    void sMethod_random(AptValue *, int);  // 0x806F2480 (132B)
    void sMethod_sqrt(AptValue *, int);  // 0x806F2504 (152B)
    void sMethod_tan(AptValue *, int);  // 0x806F259C (152B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [R/W] - vtable pointer (objectMemberLookup, sMethod_abs, sMethod_acos, ...)
    u16 m_field_002;  // 0x002 [R] (objectMemberLookup)
    u32 m_field_004;  // 0x004 [R] (objectMemberLookup)
    u32 m_field_008;  // 0x008 [W] (AptMathObj, objectMemberLookup, sMethod_abs, ...)
    f32 m_field_00C;  // 0x00C [R/W] (sMethod_abs, sMethod_acos, sMethod_asin, ...)
    u8 _pad_010[0x10];  // 0x010
    u8 m_field_020;  // 0x020 [R/W] (AptMathObj, objectMemberLookup)
    u8 _pad_021[3];  // 0x021
    u32 m_field_024;  // 0x024 [W] (objectMemberLookup)
};

#endif // APTMATHOBJ_H
