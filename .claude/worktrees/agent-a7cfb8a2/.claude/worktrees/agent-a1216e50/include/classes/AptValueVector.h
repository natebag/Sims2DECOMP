#ifndef APTVALUEVECTOR_H
#define APTVALUEVECTOR_H

#include "types.h"

// AptValueVector - struct layout extracted from assembly analysis
// Estimated minimum size: 0xC (12 bytes)
// 3 known fields (1 named), 14 methods

class AptValueVector {
public:
    // Constructors / Destructors
    AptValueVector(int)  // 0x807140D0
    ~AptValueVector(void);  // 0x807141A0

    // Methods
    /* ? */ GetAt(int);  // 0x806A7298 (164B)
    void RemoveAt(int);  // 0x806A733C (268B)
    void ReleaseValues(void);  // 0x80714270 (248B)
    /* ? */ GetNumValues(void);  // 0x80714038 (44B)
    void PushValue(AptValue *);  // 0x80713E68 (300B)
    bool IsVectorFull(void);  // 0x80714064 (64B)
    void PopValue(void);  // 0x80713F94 (164B)
    /* ? */ GetHighWaterValues(void);  // 0x807140A4 (44B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [R/W] - vtable pointer (AptValueVector, ~AptValueVector)
    u32 m_field_004;  // 0x004 [R/W] (AptValueVector, ReleaseValues)
    u32 m_field_008;  // 0x008 [R/W] (AptValueVector, ReleaseValues, ~AptValueVector)
};

#endif // APTVALUEVECTOR_H
