#ifndef CHEATMENUPARAMS_H
#define CHEATMENUPARAMS_H

#include "types.h"

// CheatMenuParams - struct layout extracted from assembly analysis
// Estimated minimum size: 0xC (12 bytes)
// 3 known fields (1 named), 14 methods

class CheatMenuParams {
public:
    // Constructors / Destructors
    CheatMenuParams(void)  // 0x807F2334
    ~CheatMenuParams(void);  // 0x807F2394

    // Methods
    void Add(EDebugMenuItem &);  // 0x807F23F8 (80B)
    void Remove(EDebugMenuItem &);  // 0x807F2448 (96B)
    void SetupWindow(CUIWindow *);  // 0x807F24A8 (744B)
    void HandleWriteToCheatFileButtonClick(unsigned int, CUIWindow *, int);  // 0x807F2790 (80B)
    /* ? */ GetWindowName(void);  // 0x807F28A0 (44B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [R/W] - vtable pointer (Remove)
    u32 m_field_004;  // 0x004 [R/W] (Remove)
    u32 m_field_008;  // 0x008 [R/W] (Remove)
};

#endif // CHEATMENUPARAMS_H
