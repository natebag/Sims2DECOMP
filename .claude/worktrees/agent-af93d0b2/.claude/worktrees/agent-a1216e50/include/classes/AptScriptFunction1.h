#ifndef APTSCRIPTFUNCTION1_H
#define APTSCRIPTFUNCTION1_H

#include "types.h"

// AptScriptFunction1 - struct layout extracted from assembly analysis
// Estimated minimum size: 0x38 (56 bytes)
// 5 known fields (5 named), 20 methods

class AptScriptFunction1 {
public:
    // Constructors / Destructors
    AptScriptFunction1(AptScriptFunctionBase *, AptAction_DefineFunction *, AptCIH *)  // 0x8070E4E4
    AptScriptFunction1(AptScriptFunction1 *, AptCIH *)  // 0x8070E554
    ~AptScriptFunction1(void);  // 0x8070E69C

    // Methods
    void Duplicate(AptCIH *);  // 0x8070FAD0 (92B)
    /* ? */ GetName(void);  // 0x8070F944 (48B)
    /* ? */ GetNumArguments(void);  // 0x8070F974 (48B)
    /* ? */ GetByteCodeBase(void);  // 0x8070F9A4 (48B)
    /* ? */ GetByteCodeSize(void);  // 0x8070F9D4 (48B)
    /* ? */ GetConstantPool(void);  // 0x8070FA04 (68B)
    void SetArgument(AptValue *, int);  // 0x8070FA48 (136B)

    // ---- Field Layout (from assembly analysis) ----
    u8 _pad_000[8];  // 0x000
    u32 m_argument;  // 0x008 [R/W] (AptScriptFunction1, SetArgument, ~AptScriptFunction1)
    u8 _pad_00C[0x14];  // 0x00C
    u32 m_argument_020;  // 0x020 [W] (SetArgument)
    u8 _pad_024[8];  // 0x024
    u32 m_argument_02C;  // 0x02C [R] (SetArgument)
    u16 m_argument_030;  // 0x030 [R] (SetArgument)
    u8 _pad_032[2];  // 0x032
    u32 m_argument_034;  // 0x034 [R/W] (AptScriptFunction1, SetArgument)
};

#endif // APTSCRIPTFUNCTION1_H
