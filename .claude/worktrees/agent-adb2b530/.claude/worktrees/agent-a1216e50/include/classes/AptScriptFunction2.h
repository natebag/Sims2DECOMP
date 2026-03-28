#ifndef APTSCRIPTFUNCTION2_H
#define APTSCRIPTFUNCTION2_H

#include "types.h"

// AptScriptFunction2 - struct layout extracted from assembly analysis
// Estimated minimum size: 0x38 (56 bytes)
// 8 known fields (8 named), 24 methods

class AptScriptFunction2 {
public:
    // Constructors / Destructors
    AptScriptFunction2(AptScriptFunctionBase *, AptAction_DefineFunction2 *, AptCIH *)  // 0x8070E5C0
    AptScriptFunction2(AptScriptFunction2 *, AptCIH *)  // 0x8070E630
    ~AptScriptFunction2(void);  // 0x8070E704

    // Methods
    void SetupBeforeExecution(_AptScriptFunctionState *, AptValue *);  // 0x8070EE20 (828B)
    void CleanupAfterExecution(_AptScriptFunctionState *);  // 0x8070F15C (276B)
    void Duplicate(AptCIH *);  // 0x8070FCFC (92B)
    /* ? */ GetName(void);  // 0x8070FB2C (48B)
    /* ? */ GetNumArguments(void);  // 0x8070FB5C (48B)
    /* ? */ GetByteCodeBase(void);  // 0x8070FB8C (48B)
    /* ? */ GetByteCodeSize(void);  // 0x8070FBBC (48B)
    /* ? */ GetConstantPool(void);  // 0x8070FBEC (68B)
    void SetArgument(AptValue *, int);  // 0x8070FC30 (204B)

    // ---- Field Layout (from assembly analysis) ----
    u16 m_upBeforeExecution;  // 0x000 [R/W] (SetupBeforeExecution)
    u8 _pad_002[2];  // 0x002
    u16 m_upBeforeExecution_004;  // 0x004 [R] (SetupBeforeExecution)
    u8 _pad_006[2];  // 0x006
    u32 m_argument;  // 0x008 [R/W] (AptScriptFunction2, SetArgument, ~AptScriptFunction2)
    u8 _pad_00C[0x14];  // 0x00C
    u32 m_argument_020;  // 0x020 [W] (SetArgument)
    u32 m_upBeforeExecution_024;  // 0x024 [R] (SetupBeforeExecution)
    u8 _pad_028[4];  // 0x028
    u32 m_argument_02C;  // 0x02C [R] (SetArgument)
    u16 m_argument_030;  // 0x030 [R] (SetArgument)
    u8 _pad_032[2];  // 0x032
    u32 m_upBeforeExecution_034;  // 0x034 [R/W] (AptScriptFunction2, SetArgument, SetupBeforeExecution)
};

#endif // APTSCRIPTFUNCTION2_H
