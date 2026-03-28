#ifndef CSOUNDCACHE_H
#define CSOUNDCACHE_H

#include "types.h"

// cSoundCache - struct layout extracted from assembly analysis
// Estimated minimum size: 0x104 (260 bytes)
// 2 known fields (1 named), 26 methods

class cSoundCache {
public:
    // Constructors / Destructors
    cSoundCache(void)  // 0x8034650C
    ~cSoundCache(void);  // 0x8034655C

    // Methods
    void CleanupIdleTracks(void);  // 0x80346724 (680B)
    void UpdateDuckingPriorities(void);  // 0x803469CC (624B)
    /* ? */ GetTrackObject(ERSoundEvent *, bool);  // 0x80346E78 (760B)
    void KillAll(void);  // 0x80346C3C (132B)
    bool IsInMemory(cTrack *);  // 0x80347170 (80B)
    void PauseGroup(int);  // 0x80346CC0 (220B)
    void UnpauseGroup(int);  // 0x80346D9C (220B)
    void Shutdown(void);  // 0x80346634 (240B)
    void onTrackDelete(cTrack *);  // 0x803465B4 (128B)
    bool IsInMemory(ERSoundEvent *);  // 0x803471C0 (148B)
    void printTrackList(void);  // 0x80347254 (244B)

    // ---- Field Layout (from assembly analysis) ----
    u32 m_field_000;  // 0x000 [R] (KillAll, PauseGroup, UnpauseGroup, ...)
    u8 _pad_004[0xFC];  // 0x004
    u32 m_trackObject;  // 0x100 [R/W] (CleanupIdleTracks, GetTrackObject)
};

#endif // CSOUNDCACHE_H
