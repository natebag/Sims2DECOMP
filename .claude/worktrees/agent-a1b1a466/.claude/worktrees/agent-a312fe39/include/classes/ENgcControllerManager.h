#ifndef ENGCCONTROLLERMANAGER_H
#define ENGCCONTROLLERMANAGER_H

#include "types.h"

// ENgcControllerManager - struct layout extracted from assembly analysis
// Estimated minimum size: 0x20C (524 bytes)
// 5 known fields (0 named), 10 methods

class ENgcControllerManager {
public:
    // Constructors / Destructors
    ENgcControllerManager(void)  // 0x808A6938
    ~ENgcControllerManager(void);  // 0x808A698C

    // Methods
    void Init(void);  // 0x808A69D8 (388B)
    void Shutdown(void);  // 0x808A6B5C (32B)
    void Update(void);  // 0x808A6B7C (364B)

    // ---- Field Layout (from assembly analysis) ----
    u8 _pad_000[0x2E];  // 0x000
    u8 m_field_02E;  // 0x02E [R] (Update)
    u8 _pad_02F[0xB];  // 0x02F
    u8 m_field_03A;  // 0x03A [R] (Update)
    u8 _pad_03B[0xB];  // 0x03B
    u8 m_field_046;  // 0x046 [R] (Update)
    u8 _pad_047[0xB];  // 0x047
    u8 m_field_052;  // 0x052 [R] (Update)
    u8 _pad_053[0x1B5];  // 0x053
    u32 m_field_208;  // 0x208 [W] (Init)
};

#endif // ENGCCONTROLLERMANAGER_H
