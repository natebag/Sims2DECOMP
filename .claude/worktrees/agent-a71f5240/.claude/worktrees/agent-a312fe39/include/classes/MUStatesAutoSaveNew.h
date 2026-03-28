#ifndef MUSTATESAUTOSAVENEW_H
#define MUSTATESAUTOSAVENEW_H

#include "types.h"

// MUStatesAutoSaveNew - struct layout extracted from assembly analysis
// Estimated minimum size: 0x9C (156 bytes)
// 4 known fields (0 named), 8 methods

class MUStatesAutoSaveNew {
public:
    // Constructors / Destructors
    MUStatesAutoSaveNew(int)  // 0x801CEA24
    ~MUStatesAutoSaveNew(void);  // 0x801CEA90

    // Methods
    void Update(float);  // 0x801C7A68 (924B)
    /* ? */ GetWrapper(void);  // 0x801CEADC (80B)

    // ---- Field Layout (from assembly analysis) ----
    u8 _pad_000[8];  // 0x000
    u32 m_field_008;  // 0x008 [R] (Update)
    u8 _pad_00C[0x10];  // 0x00C
    u32 m_field_01C;  // 0x01C [R/W] (Update)
    u8 _pad_020[0x70];  // 0x020
    u32 m_field_090;  // 0x090 [R/W] (Update)
    u8 _pad_094[4];  // 0x094
    u32 m_field_098;  // 0x098 [R] (Update)
};

#endif // MUSTATESAUTOSAVENEW_H
