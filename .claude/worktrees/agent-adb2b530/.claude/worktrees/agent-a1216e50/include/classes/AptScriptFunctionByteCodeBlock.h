#ifndef APTSCRIPTFUNCTIONBYTECODEBLOCK_H
#define APTSCRIPTFUNCTIONBYTECODEBLOCK_H

#include "types.h"

// AptScriptFunctionByteCodeBlock - struct layout extracted from assembly analysis
// Estimated minimum size: 0x48 (72 bytes)
// 6 known fields (0 named), 18 methods

class AptScriptFunctionByteCodeBlock {
public:
    // Constructors / Destructors
    AptScriptFunctionByteCodeBlock(unsigned char *, int, AptConstantPool, char *, AptCIH *, AptScriptFunctionBase *)  // 0x8070F270
    ~AptScriptFunctionByteCodeBlock(void);  // 0x8070FF30

    // Methods
    void Duplicate(AptCIH *);  // 0x8070FEB8 (120B)
    /* ? */ GetName(void);  // 0x8070FD58 (44B)
    /* ? */ GetNumArguments(void);  // 0x8070FD84 (40B)
    /* ? */ GetByteCodeBase(void);  // 0x8070FDAC (44B)
    /* ? */ GetByteCodeSize(void);  // 0x8070FDD8 (44B)
    /* ? */ GetConstantPool(void);  // 0x8070FE04 (60B)
    void SetArgument(AptValue *, int);  // 0x8070FE40 (120B)

    // ---- Field Layout (from assembly analysis) ----
    u8 _pad_000[8];  // 0x000
    u32 m_field_008;  // 0x008 [W] (AptScriptFunctionByteCodeBlock, ~AptScriptFunctionByteCodeBlock)
    u8 _pad_00C[0x28];  // 0x00C
    u32 m_field_034;  // 0x034 [W] (AptScriptFunctionByteCodeBlock)
    u32 m_field_038;  // 0x038 [W] (AptScriptFunctionByteCodeBlock)
    u32 m_field_03C;  // 0x03C [W] (AptScriptFunctionByteCodeBlock)
    u32 m_field_040;  // 0x040 [W] (AptScriptFunctionByteCodeBlock)
    u32 m_field_044;  // 0x044 [W] (AptScriptFunctionByteCodeBlock)
};

#endif // APTSCRIPTFUNCTIONBYTECODEBLOCK_H
