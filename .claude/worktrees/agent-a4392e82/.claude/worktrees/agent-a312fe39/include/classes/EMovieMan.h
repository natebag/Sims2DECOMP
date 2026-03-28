#ifndef EMOVIEMAN_H
#define EMOVIEMAN_H

#include "types.h"

// EMovieMan - struct layout extracted from assembly analysis
// Estimated minimum size: 0xD24 (3364 bytes)
// 4 known fields (0 named), 12 methods

class EMovieMan {
public:
    // Constructors / Destructors
    EMovieMan(void)  // 0x8088C064
    ~EMovieMan(void);  // 0x8088BEF8

    // Methods
    void AddRef(unsigned int, EFile *, int);  // 0x8088BFAC (92B)
    void AllocateAndLoadResource(EFile *, unsigned int, unsigned int);  // 0x8088BC90 (616B)
    void AddRef(char *, EFile *, int);  // 0x8088C008 (92B)
    void SetMovieId(unsigned int);  // 0x8088C0B8 (40B)

    // ---- Field Layout (from assembly analysis) ----
    u8 _pad_000[8];  // 0x000
    u32 m_field_008;  // 0x008 [W] (AllocateAndLoadResource)
    u8 _pad_00C[0x48];  // 0x00C
    u32 m_field_054;  // 0x054 [W] (EMovieMan)
    u8 _pad_058[0xCC4];  // 0x058
    u32 m_field_D1C;  // 0xD1C [W] (EMovieMan)
    u32 m_field_D20;  // 0xD20 [R] (AllocateAndLoadResource)
};

#endif // EMOVIEMAN_H
