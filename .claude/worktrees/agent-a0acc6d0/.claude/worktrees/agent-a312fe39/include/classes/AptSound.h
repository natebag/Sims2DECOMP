#ifndef APTSOUND_H
#define APTSOUND_H

#include "types.h"

// AptSound - struct layout extracted from assembly analysis
// Estimated minimum size: 0x30 (48 bytes)
// 8 known fields (1 named), 14 methods

class AptSound {
public:
    // Constructors / Destructors
    AptSound(AptCIH *)  // 0x806FBE84
    ~AptSound(void);  // 0x806FC67C

    // Methods
    void CleanNativeFunctions(void);  // 0x806FBF04 (320B)
    void sMethod_attachSound(AptValue *, int);  // 0x806FC044 (452B)
    void sMethod_start(AptValue *, int);  // 0x806FC208 (160B)
    void sMethod_stop(AptValue *, int);  // 0x806FC2A8 (144B)
    void objectMemberLookup(AptValue *, EAStringC *);  // 0x806FC338 (624B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [R/W] - vtable pointer (objectMemberLookup, sMethod_attachSound, sMethod_start)
    u16 m_field_002;  // 0x002 [R] (objectMemberLookup)
    u32 m_field_004;  // 0x004 [R] (objectMemberLookup)
    u32 m_field_008;  // 0x008 [W] (AptSound, objectMemberLookup, ~AptSound)
    u8 _pad_00C[0x14];  // 0x00C
    u8 m_field_020;  // 0x020 [R/W] (AptSound, objectMemberLookup)
    u8 _pad_021[3];  // 0x021
    u32 m_field_024;  // 0x024 [R/W] (AptSound, objectMemberLookup, sMethod_attachSound)
    u32 m_field_028;  // 0x028 [R/W] (AptSound, sMethod_attachSound, sMethod_start)
    u32 m_field_02C;  // 0x02C [R/W] (AptSound, sMethod_attachSound, sMethod_start)
};

#endif // APTSOUND_H
