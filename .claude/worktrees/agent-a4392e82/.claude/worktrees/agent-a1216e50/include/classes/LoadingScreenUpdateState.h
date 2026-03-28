#ifndef LOADINGSCREENUPDATESTATE_H
#define LOADINGSCREENUPDATESTATE_H

#include "types.h"

// LoadingScreenUpdateState - struct layout extracted from assembly analysis
// Estimated minimum size: 0xAC (172 bytes)
// 2 known fields (1 named), 14 methods

class LoadingScreenUpdateState {
public:
    // Constructors / Destructors
    LoadingScreenUpdateState(int)  // 0x801C5540
    ~LoadingScreenUpdateState(void);  // 0x801C4540

    // Methods
    void Update(float);  // 0x801C11F0 (272B)
    bool IsLoadComplete(void);  // 0x801C5654 (112B)
    void FaderStart(float);  // 0x801C55AC (88B)
    void DrawTopmost(ERC *);  // 0x801C1300 (168B)
    void FaderGetFadeOpacity(void);  // 0x801C5604 (80B)

    // ---- Field Layout (from assembly analysis) ----
    u8 _pad_000[8];  // 0x000
    u32 m_field_008;  // 0x008 [R] (DrawTopmost, FaderGetFadeOpacity, Update)
    u8 _pad_00C[0x9C];  // 0x00C
    f32 m_topmost;  // 0x0A8 [R] (DrawTopmost)
};

#endif // LOADINGSCREENUPDATESTATE_H
