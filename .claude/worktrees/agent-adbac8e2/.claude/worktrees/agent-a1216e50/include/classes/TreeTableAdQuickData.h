#ifndef TREETABLEADQUICKDATA_H
#define TREETABLEADQUICKDATA_H

#include "types.h"

// TreeTableAdQuickData - struct layout extracted from assembly analysis
// Estimated minimum size: 0xC (12 bytes)
// 2 known fields (0 named), 30 methods

class TreeTableAdQuickData {
public:
    // Constructors / Destructors
    TreeTableAdQuickData(TreeTableAd *)  // 0x80401854
    ~TreeTableAdQuickData(void);  // 0x80401928

    // Methods
    void QueryInterface(unsigned int, void **);  // 0x80402874 (248B)
    void AddRef(void);  // 0x8040296C (64B)
    void Release(void);  // 0x804029AC (160B)
    void operator=(ITreeTableAd &);  // 0x80404C24 (164B)
    /* ? */ GetPersonalityAd(void);  // 0x80404B14 (68B)
    void SetPersonalityAd(int);  // 0x80404CC8 (156B)
    /* ? */ GetMin(void);  // 0x80404B58 (68B)
    void SetMin(int);  // 0x80404D64 (156B)
    /* ? */ GetMax(void);  // 0x80404B9C (68B)
    void SetMax(int);  // 0x80404E00 (156B)
    /* ? */ GetRange(void);  // 0x80404BE0 (68B)
    void SetRange(int);  // 0x80404E9C (156B)
    /* ? */ GetImplementation(void);  // 0x80404F38 (44B)

    // ---- Field Layout (from assembly analysis) ----
    u32 m_field_000;  // 0x000 [R] (QueryInterface, Release)
    u8 _pad_004[4];  // 0x004
    u32 m_field_008;  // 0x008 [R/W] (Release)
};

#endif // TREETABLEADQUICKDATA_H
