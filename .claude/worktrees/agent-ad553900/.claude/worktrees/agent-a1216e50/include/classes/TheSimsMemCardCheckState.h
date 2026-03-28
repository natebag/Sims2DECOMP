#ifndef THESIMSMEMCARDCHECKSTATE_H
#define THESIMSMEMCARDCHECKSTATE_H

#include "types.h"

// TheSimsMemCardCheckState - struct layout extracted from assembly analysis
// Estimated minimum size: 0x190 (400 bytes)
// 3 known fields (0 named), 12 methods

class TheSimsMemCardCheckState {
public:
    // Constructors / Destructors
    TheSimsMemCardCheckState(int)  // 0x801E8D04
    ~TheSimsMemCardCheckState(void);  // 0x801E8D70

    // Methods
    void Startup(void);  // 0x801DFA34 (128B)
    void Shutdown(void);  // 0x801DFAB4 (56B)
    void Update(float);  // 0x801DFAEC (64B)
    void Draw(ERC *);  // 0x801DFB2C (300B)

    // ---- Field Layout (from assembly analysis) ----
    u8 _pad_000[0xF0];  // 0x000
    u32 m_field_0F0;  // 0x0F0 [R] (Draw)
    u8 _pad_0F4[0x94];  // 0x0F4
    s16 m_field_188;  // 0x188 [R] (Draw)
    u8 _pad_18A[2];  // 0x18A
    u32 m_field_18C;  // 0x18C [R] (Draw)
};

#endif // THESIMSMEMCARDCHECKSTATE_H
