#ifndef HOUSESTATS_H
#define HOUSESTATS_H

#include "types.h"

// HouseStats - struct layout extracted from assembly analysis
// Estimated minimum size: 0x28 (40 bytes)
// 5 known fields (5 named), 24 methods

class HouseStats {
public:
    // Constructors / Destructors
    HouseStats(void)  // 0x8024D0F4

    // Methods
    /* ? */ GetSquareFeet(void);  // 0x8024D16C (44B)
    /* ? */ GetSizeScore(void);  // 0x8024D198 (260B)
    /* ? */ GetFurnishingsScore(void);  // 0x8024D29C (400B)
    /* ? */ GetYardScore(void);  // 0x8024D42C (184B)
    /* ? */ GetUpkeepScore(void);  // 0x8024D4E4 (252B)
    /* ? */ GetOverallScore(void);  // 0x8024D5E0 (328B)
    /* ? */ GetNumBedrooms(void);  // 0x8024D728 (44B)
    /* ? */ GetNumBathrooms(void);  // 0x8024D754 (44B)
    /* ? */ GetNumLevels(void);  // 0x8024D780 (44B)
    /* ? */ GetLotSize(void);  // 0x8024D7AC (44B)
    /* ? */ GetObjectCount(void);  // 0x8024D7D8 (44B)

    // ---- Field Layout (from assembly analysis) ----
    u32 m_furnishingsScore;  // 0x000 [R] (GetFurnishingsScore, GetSizeScore)
    u32 m_furnishingsScore_004;  // 0x004 [R] (GetFurnishingsScore, GetSizeScore)
    u32 m_furnishingsScore_008;  // 0x008 [R] (GetFurnishingsScore, GetSizeScore)
    u8 _pad_00C[0x14];  // 0x00C
    u32 m_upkeepScore;  // 0x020 [R] (GetUpkeepScore)
    u32 m_upkeepScore_024;  // 0x024 [R] (GetUpkeepScore)
};

#endif // HOUSESTATS_H
