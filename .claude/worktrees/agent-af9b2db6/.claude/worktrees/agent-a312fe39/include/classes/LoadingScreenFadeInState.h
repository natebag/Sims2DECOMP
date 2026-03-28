#ifndef LOADINGSCREENFADEINSTATE_H
#define LOADINGSCREENFADEINSTATE_H

#include "types.h"

// LoadingScreenFadeInState - struct layout extracted from assembly analysis
// Estimated minimum size: 0xAC (172 bytes)
// 2 known fields (1 named), 14 methods

class LoadingScreenFadeInState {
public:
    // Constructors / Destructors
    LoadingScreenFadeInState(int)  // 0x801C53C0
    ~LoadingScreenFadeInState(void);  // 0x801C4500

    // Methods
    void Update(float);  // 0x801C105C (236B)
    void FaderUpdate(float);  // 0x801C542C (84B)
    bool IsLoadComplete(void);  // 0x801C54D0 (112B)
    void DrawTopmost(ERC *);  // 0x801C1148 (168B)
    void FaderGetFadeOpacity(void);  // 0x801C5480 (80B)

    // ---- Field Layout (from assembly analysis) ----
    u8 _pad_000[8];  // 0x000
    u32 m_field_008;  // 0x008 [R] (DrawTopmost, FaderGetFadeOpacity, FaderUpdate, ...)
    u8 _pad_00C[0x9C];  // 0x00C
    f32 m_topmost;  // 0x0A8 [R] (DrawTopmost)
};

#endif // LOADINGSCREENFADEINSTATE_H
