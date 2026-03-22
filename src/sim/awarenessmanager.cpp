// awarenessmanager.cpp - AwarenessManager (NPC awareness system)
// Part of the Sims 2 GC decompilation
// Original: u2_ngc_release_dvd(awarenessmanager.obj)
//
// Small functions (<=64 bytes) decompiled from the awarenessmanager object file.
// AwarenessManager handles NPC awareness of events, weather, other sims.

#include "types.h"
#include "stub_classes.h"

// Forward declarations
class cXObject;

//=============================================================================
// AwarenessManager
//=============================================================================
class AwarenessManager {
public:
    u8 pad00[0x10];
    int m_awarenessAction;          // 0x10 (approx offset from GetAwarenessAction)
    void* m_awareOfObject;          // 0x14
    u8 pad18[0x08];
    int m_memoryAwarenessAnimPend;  // 0x20 (approx)
    u8 pad24[0x04];
    int m_autoCarryActive;          // 0x28 (approx)
    u8 pad2C[0x04];
    float m_timeMultiplier;         // 0x30 (approx)
    float m_pauseMultiplier;        // 0x34
    int m_stateFlags;               // 0x38

    // SetIsRaining
    // Address: 0x80012250, Size: 8
    void SetIsRaining(bool val) {
        // Stores to sdata global (m_bIsRaining)
        // NON_MATCHING - sdata access
    }

    // SetPlayerControl
    // Address: 0x800122B0, Size: 40
    // NON_MATCHING - complex flag manipulation
    void SetPlayerControl(bool val);

    // SetAwareOfObjectKilled
    // Address: 0x80012BD0, Size: 52
    // NON_MATCHING - virtual dispatch
    void SetAwareOfObjectKilled(cXObject* obj);

    // GetPlayerObject
    // Address: 0x80014028, Size: 40
    // NON_MATCHING - array index access
    void* GetPlayerObject(int idx);

    // GetAwarenessAction
    // Address: 0x80014248, Size: 8
    int GetAwarenessAction() {
        return m_awarenessAction;
    }

    // GetAwareOfObject
    // Address: 0x80014250, Size: 8
    void* GetAwareOfObject() {
        return m_awareOfObject;
    }

    // IsMemoryAwarenessAnimPending
    // Address: 0x80014258, Size: 12
    int IsMemoryAwarenessAnimPending() {
        return m_memoryAwarenessAnimPend;
    }

    // IsAutoCarryActive
    // Address: 0x80014264, Size: 12
    int IsAutoCarryActive() {
        return m_autoCarryActive;
    }

    // SetTimeMultiplier
    // Address: 0x80014270, Size: 8
    void SetTimeMultiplier(float val) {
        m_timeMultiplier = val;
    }

    // SetPauseMultiplier
    // Address: 0x80014278, Size: 8
    void SetPauseMultiplier(float val) {
        m_pauseMultiplier = val;
    }

    // GetStateFlags
    // Address: 0x80014280, Size: 8
    int GetStateFlags() {
        return m_stateFlags;
    }
};
