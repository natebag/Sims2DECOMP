#ifndef EMOVIE_H
#define EMOVIE_H

#include "types.h"

// EMovie - struct layout extracted from assembly analysis
// Estimated minimum size: 0x74 (116 bytes)
// 2 known fields (0 named), 16 methods

class EMovie {
public:
    // Constructors / Destructors
    EMovie(void)  // 0x8090CB58
    ~EMovie(void);  // 0x8090CB00

    // Methods
    void Start(int, int);  // 0x8090CA68 (48B)
    void Update(void);  // 0x8090C908 (296B)
    void Load(EFile *, unsigned int, unsigned int, unsigned int);  // 0x8090CA30 (56B)
    void Stop(void);  // 0x8090CA98 (32B)
    void Reset(void);  // 0x8090CAB8 (32B)
    bool IsFinished(void);  // 0x8090CAD8 (40B)

    // ---- Field Layout (from assembly analysis) ----
    u8 _pad_000[8];  // 0x000
    u32 m_field_008;  // 0x008 [R] (Update)
    u8 _pad_00C[0x64];  // 0x00C
    u32 m_field_070;  // 0x070 [R] (Update)
};

#endif // EMOVIE_H
