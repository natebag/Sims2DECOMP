#ifndef APTKEY_H
#define APTKEY_H

#include "types.h"

// AptKey - struct layout extracted from assembly analysis
// Estimated minimum size: 0x28 (40 bytes)
// 7 known fields (1 named), 24 methods

class AptKey {
public:
    // Constructors / Destructors
    AptKey(void)  // 0x806F5A9C
    ~AptKey(void);  // 0x806F5AFC

    // Methods
    void CleanNativeFunctions(void);  // 0x806F2634 (788B)
    void objectMemberLookup(AptValue *, EAStringC *);  // 0x806F2948 (2044B)
    void sMethod_isDown(AptValue *, int);  // 0x806F3144 (384B)
    void sMethod_isToggled(AptValue *, int);  // 0x806F32C4 (140B)
    void sMethod_getCode(AptValue *, int);  // 0x806F3350 (276B)
    void sMethod_getController(AptValue *, int);  // 0x806F3548 (164B)
    void sMethod_addListener(AptValue *, int);  // 0x806F35EC (248B)
    void sMethod_removeListener(AptValue *, int);  // 0x806F36E4 (228B)
    void sMethod_getAnalogStickInfo(AptValue *, int);  // 0x806F37C8 (816B)
    void sMethod_getAscii(AptValue *, int);  // 0x806F3464 (228B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [R/W] - vtable pointer (objectMemberLookup, sMethod_getAscii, sMethod_getCode, ...)
    u16 m_field_002;  // 0x002 [R] (objectMemberLookup)
    u32 m_field_004;  // 0x004 [R] (objectMemberLookup)
    u32 m_field_008;  // 0x008 [W] (AptKey, objectMemberLookup, sMethod_getAnalogStickInfo, ...)
    u32 m_field_00C;  // 0x00C [R/W] (objectMemberLookup, sMethod_getAnalogStickInfo, sMethod_getAscii, ...)
    u8 _pad_010[0x10];  // 0x010
    u8 m_field_020;  // 0x020 [R/W] (AptKey, objectMemberLookup, sMethod_getAnalogStickInfo)
    u8 _pad_021[3];  // 0x021
    u32 m_field_024;  // 0x024 [W] (objectMemberLookup)
};

#endif // APTKEY_H
