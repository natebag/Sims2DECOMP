#ifndef ESEMAPHORE_H
#define ESEMAPHORE_H

#include "types.h"

// ESemaphore - struct layout extracted from assembly analysis
// Estimated minimum size: 0x10 (16 bytes)
// 4 known fields (1 named), 34 methods

class ESemaphore {
public:
    // Constructors / Destructors
    ESemaphore(void)  // 0x8077CC38
    ESemaphore(int, int)  // 0x8077CC94
    ~ESemaphore(void);  // 0x8077CD08

    // Methods
    void Release(void);  // 0x8077D1C4 (220B)
    void Create(int, int);  // 0x8077CE94 (420B)
    void Acquire(unsigned int);  // 0x8077D0D0 (244B)
    void iAcquire(void);  // 0x8077D2A0 (204B)
    void iRelease(void);  // 0x8077D36C (176B)
    void Destroy(void);  // 0x8077D038 (152B)
    /* ? */ GetObject(int);  // 0x8077CD68 (240B)
    bool IsCreated(void);  // 0x8077CE58 (60B)
    /* ? */ GetCurrentCount(void);  // 0x8077D41C (44B)
    /* ? */ GetMaxCount(void);  // 0x8077D448 (44B)
    void operator++(void);  // 0x8077D474 (104B)
    void operator++(int);  // 0x8077D4DC (108B)
    void operator--(void);  // 0x8077D548 (100B)
    void operator--(int);  // 0x8077D5AC (104B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [R/W] - vtable pointer (ESemaphore, operator++, operator--, ...)
    u32 m_field_004;  // 0x004 [R/W] (Create, ESemaphore, ~ESemaphore)
    u32 m_field_008;  // 0x008 [R/W] (Create, ESemaphore, Release)
    u32 m_field_00C;  // 0x00C [R] (Acquire, Release)
};

#endif // ESEMAPHORE_H
