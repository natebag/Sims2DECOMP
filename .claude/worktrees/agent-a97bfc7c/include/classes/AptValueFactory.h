#ifndef APTVALUEFACTORY_H
#define APTVALUEFACTORY_H

#include "types.h"

// AptValueFactory - struct layout extracted from assembly analysis
// Estimated minimum size: 0x10 (16 bytes)
// 3 known fields (1 named), 14 methods

class AptValueFactory {
public:
    // Methods
    void CreateString(char *);  // 0x807090EC (144B)
    void CreateInteger(int);  // 0x8070917C (76B)
    void CreateFloat(float);  // 0x807091C8 (76B)
    void CreateBoolean(bool);  // 0x80709214 (72B)
    void CreateArray(int, AptValue **);  // 0x8070925C (168B)
    void CreateStringFormatted(char *,...);  // 0x80709304 (312B)
    void CreateUndefined(void);  // 0x8070943C (40B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [R/W] - vtable pointer (CreateBoolean, CreateFloat, CreateInteger)
    u8 _pad_004[4];  // 0x004
    u32 m_field_008;  // 0x008 [W] (CreateBoolean, CreateFloat, CreateInteger)
    f32 m_field_00C;  // 0x00C [R/W] (CreateBoolean, CreateFloat, CreateInteger)
};

#endif // APTVALUEFACTORY_H
