#ifndef APTSAVEDINPUTCHECKPOINTS_H
#define APTSAVEDINPUTCHECKPOINTS_H

#include "types.h"

// AptSavedInputCheckpoints - struct layout extracted from assembly analysis
// Estimated minimum size: 0xC (12 bytes)
// 2 known fields (1 named), 10 methods

class AptSavedInputCheckpoints {
public:
    // Constructors / Destructors
    AptSavedInputCheckpoints(void)  // 0x806A6FC0
    ~AptSavedInputCheckpoints(void);  // 0x806A6F68

    // Methods
    bool CanContinueSavedInputs(void);  // 0x806A7198 (76B)
    void Checkpoint(EAStringC &);  // 0x806A7000 (408B)
    void allStatesAre2(AptFileSavedInputState::State, AptFileSavedInputState::State);  // 0x806A7CC4 (208B)
    bool CanLinkPendingFiles(void);  // 0x806EC164 (76B)
    void AllLinked(void);  // 0x806EC110 (84B)
    void FileLoaded(EAStringC &);  // 0x806EC0C4 (76B)
    void updateState(EAStringC &, AptFileSavedInputState::State, AptFileSavedInputState::State, AptFileSavedInputState::State);  // 0x806ED158 (300B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [W] - vtable pointer (~AptSavedInputCheckpoints)
    u8 _pad_004[4];  // 0x004
    u32 m_field_008;  // 0x008 [R] (~AptSavedInputCheckpoints)
};

#endif // APTSAVEDINPUTCHECKPOINTS_H
