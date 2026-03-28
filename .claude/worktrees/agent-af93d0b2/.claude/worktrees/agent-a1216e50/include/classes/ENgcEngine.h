#ifndef ENGCENGINE_H
#define ENGCENGINE_H

#include "types.h"

// ENgcEngine - struct layout extracted from assembly analysis
// Estimated minimum size: 0x54 (84 bytes)
// 2 known fields (1 named), 18 methods

class ENgcEngine {
public:
    // Constructors / Destructors
    ENgcEngine(void)  // 0x808A7B50
    ~ENgcEngine(void);  // 0x808A7BB4

    // Methods
    void InitMemoryManager(void);  // 0x808A7D94 (1928B)
    void InitConsole(void);  // 0x808A7CC8 (204B)
    void Init(void);  // 0x808A7C00 (200B)
    void InitializeProfiler(void);  // 0x808A851C (108B)
    void PreFrameUpdate(void);  // 0x808A8588 (100B)
    void ErrorHandler(unsigned short, OSContext *, unsigned int, unsigned int);  // 0x808A85EC (80B)
    bool IsResetting(void);  // 0x808A8924 (44B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [W] - vtable pointer (ENgcEngine)
    u8 _pad_004[0x4C];  // 0x004
    u32 m_field_050;  // 0x050 [W] (ENgcEngine)
};

#endif // ENGCENGINE_H
