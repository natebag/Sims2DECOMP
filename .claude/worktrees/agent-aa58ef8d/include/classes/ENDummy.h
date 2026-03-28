#ifndef ENDUMMY_H
#define ENDUMMY_H

#include "types.h"

// ENDummy - struct layout extracted from assembly analysis
// Estimated minimum size: 0x58 (88 bytes)
// 7 known fields (4 named), 29 methods

class ENDummy {
public:
    // Static members (from map file)
    // static ??? MAX_NAME_SIZE;

    // Constructors / Destructors
    ENDummy(void)  // 0x8075986C
    ~ENDummy(void);  // 0x807598D4

    // Methods
    void Write(EStream &);  // 0x80759940 (280B)
    void Read(EStream &);  // 0x80759A58 (420B)
    void Read(unsigned char *);  // 0x80759BFC (540B)
    void SetDummyPoint(int, ENDummyPoint);  // 0x80759F20 (152B)
    /* ? */ GetDummyPointOrient(int, EMat4 &, EMat4 &);  // 0x80759FB8 (172B)
    /* ? */ GetDummyPoint(int);  // 0x8075ABE0 (100B)
    void SetName(char *);  // 0x8075A9F4 (68B)
    void SetID(int);  // 0x8075AA38 (40B)
    void SetKeys(int);  // 0x8075AA60 (76B)
    /* ? */ GetName(void);  // 0x8075AAAC (40B)
    /* ? */ GetID(void);  // 0x8075AAD4 (44B)
    /* ? */ GetKeys(void);  // 0x8075AB00 (44B)
    void operator=(ENDummy &);  // 0x8085F660 (168B)

    // ---- Field Layout (from assembly analysis) ----
    u8 m_dummyPoint;  // 0x000 [W] (ENDummy, GetDummyPoint)
    u8 _pad_001[3];  // 0x001
    f32 m_dummyPoint_004;  // 0x004 [R/W] (GetDummyPoint, SetDummyPoint)
    u8 _pad_008[0x38];  // 0x008
    u32 m_field_040;  // 0x040 [R/W] (ENDummy, Write)
    u32 m_field_044;  // 0x044 [R/W] (ENDummy, Read, Write)
    u32 m_dummyPointOrient;  // 0x048 [R] (GetDummyPointOrient, Read, SetDummyPoint, ...)
    u32 m_dummyPointOrient_04C;  // 0x04C [R] (GetDummyPointOrient)
    u8 _pad_050[4];  // 0x050
    u32 m_field_054;  // 0x054 [W] (ENDummy, ~ENDummy)
};

#endif // ENDUMMY_H
