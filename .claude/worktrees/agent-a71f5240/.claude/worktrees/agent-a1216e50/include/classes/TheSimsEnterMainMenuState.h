#ifndef THESIMSENTERMAINMENUSTATE_H
#define THESIMSENTERMAINMENUSTATE_H

#include "types.h"

// TheSimsEnterMainMenuState - struct layout extracted from assembly analysis
// Estimated minimum size: 0x20 (32 bytes)
// 2 known fields (0 named), 16 methods

class TheSimsEnterMainMenuState {
public:
    // Constructors / Destructors
    TheSimsEnterMainMenuState(int)  // 0x801E9020
    ~TheSimsEnterMainMenuState(void);  // 0x801E9094

    // Methods
    void Reset(void);  // 0x801E0A4C (496B)
    void Shutdown(void);  // 0x801E0C3C (56B)
    void Startup(void);  // 0x801E0D34 (704B)
    void Update(float);  // 0x801E0FF4 (1972B)
    void Draw(ERC *);  // 0x801E17A8 (72B)
    void DrawTopmost(ERC *);  // 0x801E17F0 (72B)

    // ---- Field Layout (from assembly analysis) ----
    u8 _pad_000[0xC];  // 0x000
    u32 m_field_00C;  // 0x00C [R/W] (Reset, Update)
    u8 _pad_010[0xC];  // 0x010
    u32 m_field_01C;  // 0x01C [R/W] (Update)
};

#endif // THESIMSENTERMAINMENUSTATE_H
