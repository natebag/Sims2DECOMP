#ifndef APTSCRIPTFUNCTIONBASE_H
#define APTSCRIPTFUNCTIONBASE_H

#include "types.h"

// AptScriptFunctionBase - struct layout extracted from assembly analysis
// Estimated minimum size: 0x32 (50 bytes)
// 8 known fields (3 named), 40 methods

class AptScriptFunctionBase {
public:
    // Constructors / Destructors
    AptScriptFunctionBase(AptVirtualFunctionTable_Indices, AptScriptFunctionBase *, AptCIH *, bool)  // 0x8070DF3C
    AptScriptFunctionBase(AptVirtualFunctionTable_Indices, AptScriptFunctionBase *, AptCIH *)  // 0x8070E1F0
    ~AptScriptFunctionBase(void);  // 0x8070E47C

    // Methods
    void ShutdownStaticData(void);  // 0x8070DB2C (372B)
    void InitializeStaticData(AptInitParmsT &);  // 0x8070DA7C (176B)
    void PushStaticData(void);  // 0x8070DCA0 (240B)
    void PopStaticData(void *);  // 0x8070DD90 (428B)
    /* ? */ GetRegisterValue(int);  // 0x8070EAB8 (344B)
    void SetWhereExistsInScopeChain(EAStringC *, AptValue *);  // 0x8070F71C (144B)
    void SetInLocalScope(EAStringC *, AptValue *);  // 0x8070F6C0 (92B)
    /* ? */ GetInScopeChain(EAStringC *);  // 0x8070F7AC (132B)
    void ExistsInLocalScope(EAStringC *);  // 0x8070F63C (132B)
    void SetRegisterValue(int, AptValue *);  // 0x8070EC10 (528B)
    void PreDestroy(void);  // 0x8070E76C (32B)
    void RegisterReferences(void);  // 0x8070E78C (212B)
    void DestroyGCPointers(void);  // 0x8070E860 (316B)
    void SetupBeforeExecution(_AptScriptFunctionState *, AptValue *);  // 0x8070E99C (60B)
    void CleanupAfterExecution(_AptScriptFunctionState *);  // 0x8070E9D8 (224B)
    void CreatingNestedFunction(void);  // 0x8070F900 (68B)
    void CreateFrameStack(void);  // 0x8070F830 (208B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [R/W] - vtable pointer (AptScriptFunctionBase, CleanupAfterExecution, InitializeStaticData)
    u8 _pad_004[4];  // 0x004
    u32 m_field_008;  // 0x008 [R/W] (AptScriptFunctionBase, CreateFrameStack, CreatingNestedFunction, ...)
    u32 m_field_00C;  // 0x00C [R/W] (AptScriptFunctionBase)
    u8 _pad_010[0x10];  // 0x010
    u8 m_inScopeChain;  // 0x020 [R/W] (AptScriptFunctionBase, CreateFrameStack, CreatingNestedFunction, ...)
    u8 _pad_021[3];  // 0x021
    u32 m_field_024;  // 0x024 [R/W] (AptScriptFunctionBase, DestroyGCPointers, RegisterReferences)
    u32 m_field_028;  // 0x028 [R/W] (AptScriptFunctionBase, DestroyGCPointers, RegisterReferences)
    u32 m_inScopeChain_02C;  // 0x02C [R/W] (AptScriptFunctionBase, CreateFrameStack, CreatingNestedFunction, ...)
    u16 m_field_030;  // 0x030 [R/W] (AptScriptFunctionBase, CleanupAfterExecution, CreateFrameStack, ...)
};

#endif // APTSCRIPTFUNCTIONBASE_H
