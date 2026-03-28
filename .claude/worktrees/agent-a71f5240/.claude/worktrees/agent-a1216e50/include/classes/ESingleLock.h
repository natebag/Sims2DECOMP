#ifndef ESINGLELOCK_H
#define ESINGLELOCK_H

#include "types.h"

// ESingleLock - struct layout extracted from assembly analysis
// Estimated minimum size: 0xC (12 bytes)
// 3 known fields (1 named), 10 methods

class ESingleLock {
public:
    // Constructors / Destructors
    ESingleLock(ESyncObject *, bool, bool)  // 0x80798324
    ~ESingleLock(void);  // 0x807983F8

    // Methods
    void Lock(unsigned int);  // 0x8079845C (324B)
    void Unlock(void);  // 0x807985A0 (140B)
    void Unlock(unsigned int, unsigned int *);  // 0x8079862C (252B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [R/W] - vtable pointer (ESingleLock, Lock, Unlock)
    u32 m_field_004;  // 0x004 [R/W] (ESingleLock, Lock, Unlock)
    u32 m_field_008;  // 0x008 [R/W] (ESingleLock, ~ESingleLock)
};

#endif // ESINGLELOCK_H
