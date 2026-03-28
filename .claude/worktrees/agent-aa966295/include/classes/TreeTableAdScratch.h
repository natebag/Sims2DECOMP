#ifndef TREETABLEADSCRATCH_H
#define TREETABLEADSCRATCH_H

#include "types.h"

// TreeTableAdScratch - struct layout extracted from assembly analysis
// Estimated minimum size: 0x10 (16 bytes)
// 2 known fields (0 named), 28 methods

class TreeTableAdScratch {
public:
    // Constructors / Destructors
    TreeTableAdScratch(void)  // 0x803D17FC
    ~TreeTableAdScratch(void);  // 0x803D1868

    // Methods
    void QueryInterface(unsigned int, void **);  // 0x803D0FA8 (248B)
    void AddRef(void);  // 0x803D10A0 (64B)
    void Release(void);  // 0x803D10E0 (160B)
    void operator=(ITreeTableAd &);  // 0x803D18C0 (348B)
    /* ? */ GetPersonalityAd(void);  // 0x803D1A1C (48B)
    void SetPersonalityAd(int);  // 0x803D1A4C (44B)
    /* ? */ GetMin(void);  // 0x803D1A78 (48B)
    void SetMin(int);  // 0x803D1AA8 (44B)
    /* ? */ GetMax(void);  // 0x803D1AD4 (60B)
    void SetMax(int);  // 0x803D1B10 (56B)
    /* ? */ GetRange(void);  // 0x803D1B48 (48B)
    void SetRange(int);  // 0x803D1B78 (44B)

    // ---- Field Layout (from assembly analysis) ----
    u32 m_field_000;  // 0x000 [R] (QueryInterface, Release, operator=)
    u8 _pad_004[8];  // 0x004
    u32 m_field_00C;  // 0x00C [R/W] (Release)
};

#endif // TREETABLEADSCRATCH_H
