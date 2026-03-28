#ifndef CAUDIOINFO_H
#define CAUDIOINFO_H

#include "types.h"

// cAudioInfo - struct layout extracted from assembly analysis
// Estimated minimum size: 0x8 (8 bytes)
// 2 known fields (2 named), 8 methods

class cAudioInfo {
public:
    // Methods
    void CurrentSimSpeed(void);  // 0x802112F4 (112B)
    /* ? */ GetObjectPosition(int, cAudioWorldCoord &);  // 0x80211364 (372B)
    /* ? */ GetObjectData(int, cAudioInfo::DataIdx);  // 0x802114D8 (3152B)
    void OutdoorTileRatio(void);  // 0x80212128 (740B)

    // ---- Field Layout (from assembly analysis) ----
    u32 m_objectData;  // 0x000 [R] (GetObjectData, GetObjectPosition, OutdoorTileRatio)
    u32 m_objectData_004;  // 0x004 [R] (GetObjectData, GetObjectPosition)
};

#endif // CAUDIOINFO_H
