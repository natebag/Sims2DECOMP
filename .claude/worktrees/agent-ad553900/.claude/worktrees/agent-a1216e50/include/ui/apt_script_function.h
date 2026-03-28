#ifndef APT_SCRIPT_FUNCTION_H
#define APT_SCRIPT_FUNCTION_H

#include "types.h"
#include "ui/apt_value.h"

// Forward declarations
class AptCIH;

// ============================================================================
// Constant pool pair - two pointers (pool pointer + size/count)
// ============================================================================
struct AptConstantPoolPair {
    void* m_pool;   // 0x00
    u32 m_count;    // 0x04
};

// ============================================================================
// _AptScriptFunctionState - saved state for script function execution
// ============================================================================
struct _AptScriptFunctionState {
    u32 m_savedRegisters;  // 0x00
};

// ============================================================================
// AptScriptFunctionBase - base class for ActionScript script functions
// Source: libaptz.a(AptScriptFunction.cpp.obj)
//
// Uses static data stored in SDA (r13-relative):
//   r13-26976: static AptValueVector* s_staticData (current data vector)
//   r13-26972: static AptValue** s_registerBase (current register pointer)
//   r13-26968: static u32 s_registerCount
//   r13-26960: static u32 s_savedRegisters (saved for execution state)
// ============================================================================
class AptScriptFunctionBase : public AptValueGC {
public:
    // 0x34: void* m_functionData (pointer to function-specific data block)

    static void ShutdownStaticData();
    static void PushStaticData();
    void PreDestroy();
    static void SetupBeforeExecution(_AptScriptFunctionState* state, AptValue* val);
    static AptValue* GetRegisterValue(int index);

    // Additional large functions not decompiled here
};

// ============================================================================
// Function data block layout for AptScriptFunction1:
//   0x00: char* m_name
//   0x04: u32 m_numArguments
//   0x0C: u32 m_byteCodeSize
//   0x10: AptConstantPoolPair (pool ptr at +0x10, count at +0x14)
//   0x18: bytecode starts here (m_byteCodeBase = dataPtr + 0x18)
// ============================================================================
class AptScriptFunction1 : public AptScriptFunctionBase {
public:
    const char* GetName() const;
    int GetNumArguments();
    void* GetByteCodeBase();
    int GetByteCodeSize();
    AptConstantPoolPair GetConstantPool();
};

// ============================================================================
// Function data block layout for AptScriptFunction2:
//   0x00: char* m_name
//   0x04: u32 m_numArguments
//   0x10: u32 m_byteCodeSize
//   0x14: AptConstantPoolPair (pool ptr at +0x14, count at +0x18)
//   0x1C: bytecode starts here (m_byteCodeBase = dataPtr + 0x1C)
// ============================================================================
class AptScriptFunction2 : public AptScriptFunctionBase {
public:
    const char* GetName() const;
    int GetNumArguments();
    void* GetByteCodeBase();
    int GetByteCodeSize();
    AptConstantPoolPair GetConstantPool();
};

// ============================================================================
// AptScriptFunctionByteCodeBlock - pre-compiled bytecode block
// Layout:
//   0x34: void* m_byteCodeBase (raw bytecode pointer)
//   0x38: u32 m_byteCodeSize
//   0x3C: char* m_name
//   0x40: AptConstantPoolPair (pool ptr at +0x40, count at +0x44)
// ============================================================================
class AptScriptFunctionByteCodeBlock : public AptScriptFunctionBase {
public:
    AptCIH* Duplicate(AptCIH* cih);
    const char* GetName() const;
    int GetNumArguments();
    void* GetByteCodeBase();
    int GetByteCodeSize();
    AptConstantPoolPair GetConstantPool();
    void SetArgument(AptValue* val, int index);
};

#endif // APT_SCRIPT_FUNCTION_H
