#ifndef ERMOVIE_H
#define ERMOVIE_H

#include "types.h"

// ERMovie - struct layout extracted from assembly analysis
// Estimated minimum size: 0x28 (40 bytes)
// 7 known fields (2 named), 14 methods

class ERMovie {
public:
    // Constructors / Destructors
    ERMovie(EFile *, unsigned int, unsigned int, unsigned int)  // 0x80864880
    ~ERMovie(void);  // 0x808649E0

    // Methods
    void Stop(void);  // 0x80864B18 (112B)
    void Start(int, int);  // 0x80864A98 (128B)
    void Update(void);  // 0x80864BF8 (112B)
    bool IsFinished(void);  // 0x80864C68 (144B)
    void Reset(void);  // 0x80864B88 (112B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [R/W] - vtable pointer (ERMovie, ~ERMovie)
    u8 _pad_004[4];  // 0x004
    u32 m_field_008;  // 0x008 [R] (ERMovie)
    u8 _pad_00C[8];  // 0x00C
    u32 m_field_014;  // 0x014 [W] (ERMovie)
    u32 m_field_018;  // 0x018 [W] (ERMovie)
    u32 m_field_01C;  // 0x01C [W] (ERMovie)
    u32 m_field_020;  // 0x020 [W] (ERMovie)
    u32 m_bIsFinished;  // 0x024 [R/W] (ERMovie, IsFinished, ~ERMovie)
};

#endif // ERMOVIE_H
