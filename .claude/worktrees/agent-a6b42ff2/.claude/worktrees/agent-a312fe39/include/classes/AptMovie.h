#ifndef APTMOVIE_H
#define APTMOVIE_H

#include "types.h"

// AptMovie - struct layout extracted from assembly analysis
// Estimated minimum size: 0x50 (80 bytes)
// 5 known fields (0 named), 14 methods

class AptMovie {
public:
    // Methods
    void labelToFrame(EAStringC *);  // 0x806F84B8 (124B)
    void runFrameActions(AptCIH *, int);  // 0x806F8274 (356B)
    void resolve(unsigned char *, AptConstFile *, int *);  // 0x806F64F0 (3104B)
    void unresolve(unsigned char *, int *);  // 0x806F7110 (1988B)
    void doFrameControls(AptDisplayList *, AptCIH *, int);  // 0x806F7E08 (1132B)
    void DoTemporaryFrameControls(AptPseudoDisplayList *, int);  // 0x806F78D4 (1332B)
    void queueFrameActions(AptCIH *, int);  // 0x806F83D8 (224B)

    // ---- Field Layout (from assembly analysis) ----
    u32 m_field_000;  // 0x000 [R] (resolve, unresolve)
    u32 m_field_004;  // 0x004 [R/W] (DoTemporaryFrameControls, doFrameControls, queueFrameActions, ...)
    u32 m_field_008;  // 0x008 [R/W] (DoTemporaryFrameControls, resolve, unresolve)
    u32 m_field_00C;  // 0x00C [W] (resolve)
    u8 _pad_010[0x3C];  // 0x010
    u32 m_field_04C;  // 0x04C [R] (doFrameControls, runFrameActions)
};

#endif // APTMOVIE_H
