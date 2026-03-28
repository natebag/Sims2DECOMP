#ifndef ERSAMPLEDATA_H
#define ERSAMPLEDATA_H

#include "types.h"

// ERSampledata - struct layout extracted from assembly analysis
// Estimated minimum size: 0x1C (28 bytes)
// 3 known fields (1 named), 12 methods

class ERSampledata {
public:
    // Constructors / Destructors
    ERSampledata(void)  // 0x808B4E24
    ~ERSampledata(void);  // 0x808B4E80

    // Methods
    void Load(EFile *);  // 0x808B4F20 (268B)
    void LoadStereo(EFile *);  // 0x808B502C (268B)
    /* ? */ GetSampleHeader(void);  // 0x808B51F4 (44B)
    /* ? */ GetSampleHeader2(void);  // 0x808B5220 (44B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [W] - vtable pointer (ERSampledata, ~ERSampledata)
    u8 _pad_004[0x10];  // 0x004
    u32 m_field_014;  // 0x014 [R/W] (ERSampledata, Load, ~ERSampledata)
    u32 m_field_018;  // 0x018 [R/W] (ERSampledata, LoadStereo, ~ERSampledata)
};

#endif // ERSAMPLEDATA_H
