#ifndef CTGMICROTIMER_H
#define CTGMICROTIMER_H

#include "types.h"

// CTGMicroTimer - struct layout extracted from assembly analysis
// Estimated minimum size: 0x1C (28 bytes)
// 7 known fields (7 named), 7 methods

class CTGMicroTimer {
public:
    // Constructors / Destructors
    CTGMicroTimer(void)  // 0x802CF704
    ~CTGMicroTimer(void);  // 0x802CF7F4

    // Methods
    /* ? */ GetElapsedTime(void);  // 0x80184D54 (288B)
    void Start(void);  // 0x802CF840 (64B)
    void Stop(void);  // 0x802CF880 (68B)
    bool IsRunning(void);  // 0x802F1818 (44B)

    // ---- Field Layout (from assembly analysis) ----
    u32 m_elapsedTime;  // 0x000 [R] (GetElapsedTime)
    u32 m_elapsedTime_004;  // 0x004 [R] (GetElapsedTime)
    u32 m_elapsedTime_008;  // 0x008 [R] (GetElapsedTime)
    u32 m_elapsedTime_00C;  // 0x00C [R] (GetElapsedTime)
    u32 m_elapsedTime_010;  // 0x010 [R] (GetElapsedTime)
    u32 m_elapsedTime_014;  // 0x014 [R] (GetElapsedTime)
    u32 m_elapsedTime_018;  // 0x018 [R] (GetElapsedTime)
};

#endif // CTGMICROTIMER_H
