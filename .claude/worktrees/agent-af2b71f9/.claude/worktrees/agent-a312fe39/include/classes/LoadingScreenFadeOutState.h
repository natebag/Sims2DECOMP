#ifndef LOADINGSCREENFADEOUTSTATE_H
#define LOADINGSCREENFADEOUTSTATE_H

#include "types.h"

// LoadingScreenFadeOutState - struct layout extracted from assembly analysis
// Estimated minimum size: 0xB8 (184 bytes)
// 3 known fields (1 named), 14 methods

class LoadingScreenFadeOutState {
public:
    // Constructors / Destructors
    LoadingScreenFadeOutState(int)  // 0x801C56C4
    ~LoadingScreenFadeOutState(void);  // 0x801C4580

    // Methods
    void Update(float);  // 0x801C13A8 (220B)
    void FaderUpdate(float);  // 0x801C5730 (84B)
    void DrawTopmost(ERC *);  // 0x801C1484 (168B)
    void FaderGetFadeOpacity(void);  // 0x801C5784 (80B)
    bool IsLoadComplete(void);  // 0x801C57D4 (112B)

    // ---- Field Layout (from assembly analysis) ----
    u8 _pad_000[8];  // 0x000
    u32 m_field_008;  // 0x008 [R] (DrawTopmost, FaderGetFadeOpacity, FaderUpdate, ...)
    u8 _pad_00C[0x9C];  // 0x00C
    f32 m_topmost;  // 0x0A8 [R] (DrawTopmost)
    u8 _pad_0AC[8];  // 0x0AC
    u32 m_field_0B4;  // 0x0B4 [R] (Update)
};

#endif // LOADINGSCREENFADEOUTSTATE_H
