#ifndef CUNLOCKDISPLAYOBJECTSIM_H
#define CUNLOCKDISPLAYOBJECTSIM_H

#include "types.h"

// CUnlockDisplayObjectSim - struct layout extracted from assembly analysis
// Estimated minimum size: 0x1B8 (440 bytes)
// 11 known fields (9 named), 16 methods

class CUnlockDisplayObjectSim {
public:
    // Constructors / Destructors
    CUnlockDisplayObjectSim(void)  // 0x80179AE4
    ~CUnlockDisplayObjectSim(void);  // 0x80179B64

    // Methods
    void SetPerson(cXPerson *);  // 0x80179C24 (508B)
    void ServiceDataReady(void);  // 0x80179E20 (160B)
    void Setup(void);  // 0x80179EC0 (32B)
    void Draw(ERC *);  // 0x80179EE0 (368B)
    bool IsMale(void);  // 0x8017C594 (48B)
    bool IsAdult(void);  // 0x8017C5C4 (40B)

    // ---- Field Layout (from assembly analysis) ----
    u32 m_person;  // 0x000 [R] (SetPerson)
    u32 m_person_004;  // 0x004 [R/W] (CUnlockDisplayObjectSim, SetPerson)
    u32 m_person_008;  // 0x008 [R] (SetPerson)
    u32 m_person_00C;  // 0x00C [R] (Draw, SetPerson)
    u32 m_person_010;  // 0x010 [R/W] (CUnlockDisplayObjectSim, Draw, ServiceDataReady, ...)
    u32 m_person_014;  // 0x014 [R] (SetPerson)
    u8 _pad_018[0x1C];  // 0x018
    u32 m_field_034;  // 0x034 [R] (ServiceDataReady)
    u8 _pad_038[0x4C];  // 0x038
    u32 m_field_084;  // 0x084 [W] (CUnlockDisplayObjectSim, ~CUnlockDisplayObjectSim)
    u32 m_person_088;  // 0x088 [R/W] (CUnlockDisplayObjectSim, SetPerson)
    u32 m_person_08C;  // 0x08C [R/W] (CUnlockDisplayObjectSim, Draw, ServiceDataReady, ...)
    u8 _pad_090[0x124];  // 0x090
    u32 m_person_1B4;  // 0x1B4 [W] (CUnlockDisplayObjectSim, SetPerson)
};

#endif // CUNLOCKDISPLAYOBJECTSIM_H
