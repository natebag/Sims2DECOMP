// apt_action_medium.cpp - AptActionInterpreter medium functions (65-256 bytes)
// Object file: libaptz.a(AptActionInterpreter.cpp.obj)
// 57 functions

#include "ui/apt_action.h"

extern "C" {
    void operator_delete(void* ptr);
    void SmallBlockAllocator_Free(void* ptr);
    void AptValue_Release(void* val);
    void AptValue_AddRef_impl(void* val);
    void EAStringC_dtor(void* str);
    int strcmp_impl(const char* a, const char* b);
    int strncmp_impl(const char* a, const char* b, int n);
}

// Forward declarations for interpreter types
struct LocalContextT {
    void* m_stack;          // 0x00
    void* m_stackTop;       // 0x04
    void* m_ip;             // 0x08 - instruction pointer
    void* m_cih;            // 0x0C
    void* m_scope;          // 0x10
    void* m_registers;      // 0x14
    int m_numRegisters;     // 0x18
};

struct AptActionSetup {
    void* m_data;
    int m_size;
};

// ============================================================================
// Initialization / Shutdown
// ============================================================================

// 0x8026c8bc | 172 bytes
// NON_MATCHING - initializes action interpreter tables
void AptActionInterpreter_initialize(void* self, void* initParms) {
    // Initialize action function table
    // Register all built-in action handlers
    // Set up string dictionary
}

// 0x8026c968 | 220 bytes
// NON_MATCHING - shuts down action interpreter
void AptActionInterpreter_shutdown(void* self) {
    // Release all registered actions
    // Free string dictionary
    // Release scope chain
}

// 0x8026f824 | 184 bytes
// NON_MATCHING - gets name from CIH
void AptActionInterpreter_getName(void* self, void* cih, void* outStr) {
    // Look up character instance hierarchy name
    // Walk the CIH chain building qualified name
}

// 0x8026ff94 | 220 bytes
// NON_MATCHING - converts value to object
void AptActionInterpreter_valueToObject(void* self, void* val, void* scope, void* target, void** outObj) {
    // Check value type
    // If string, look up in scope chain
    // If object reference, dereference
}

// 0x802820ac | 116 bytes
void EAStringC_assign_action(void* dst, void* src) {
    // EAStringC assignment operator
    char* dstData = *(char**)((u8*)dst + 0x04);
    char* srcData = *(char**)((u8*)src + 0x04);
    if (dstData == srcData) return;
    // Free old, copy new
}

// 0x80270788 | 212 bytes
// NON_MATCHING - cleanup after string-based execution
void AptActionInterpreter_CleanupAfterExecution1(void* self, char* name, void* data) {
    // Release temporary scope
    // Pop execution context
}

// 0x8027085c | 212 bytes
// NON_MATCHING - cleanup after setup-based execution
void AptActionInterpreter_CleanupAfterExecution2(void* self, void* data, void* setup) {
    // Release temporary scope
    // Pop execution context
}

// 0x80281e94 | 92 bytes
void AptStringObject_setString(void* self, void* aptString) {
    void* oldStr = *(void**)((u8*)self + 0x08);
    if (oldStr) AptValue_Release(oldStr);
    *(void**)((u8*)self + 0x08) = aptString;
    if (aptString) AptValue_AddRef_impl(aptString);
}

// 0x80282044 | 104 bytes
void EAStringC_dtor_action(void* self) {
    char* data = *(char**)((u8*)self + 0x04);
    char* staticBuf = (char*)((u8*)self + 0x08);
    if (data != staticBuf && data != 0) {
        operator_delete(data);
    }
    *(char**)((u8*)self + 0x04) = 0;
}

// ============================================================================
// Action Function Handlers - Stack machine operations
// ============================================================================

// 0x802729d8 | 76 bytes
void _FunctionAptActionNextFrame(void* interp, LocalContextT* ctx) {
    // Advance frame on current target
    void* target = ctx->m_cih;
    if (target) {
        int frame = *(int*)((u8*)target + 0x1C);
        *(int*)((u8*)target + 0x1C) = frame + 1;
    }
}

// 0x80272a24 | 76 bytes
void _FunctionAptActionPrevFrame(void* interp, LocalContextT* ctx) {
    void* target = ctx->m_cih;
    if (target) {
        int frame = *(int*)((u8*)target + 0x1C);
        *(int*)((u8*)target + 0x1C) = frame - 1;
    }
}

// 0x80272a70 | 212 bytes
// NON_MATCHING - play action with frame argument
void _FunctionAptActionPlay(void* interp, LocalContextT* ctx) {
    void* target = ctx->m_cih;
    if (target) {
        int flags = *(int*)((u8*)target + 0x08);
        *(int*)((u8*)target + 0x08) = flags | 2;  // set playing
    }
}

// 0x80272b44 | 120 bytes
void _FunctionAptActionStop(void* interp, LocalContextT* ctx) {
    void* target = ctx->m_cih;
    if (target) {
        int flags = *(int*)((u8*)target + 0x08);
        *(int*)((u8*)target + 0x08) = flags & ~2;  // clear playing
    }
}

// 0x802749bc | 164 bytes
// NON_MATCHING - pop value from stack
void _FunctionAptActionPop(void* interp, LocalContextT* ctx) {
    // Pop top of stack and release if needed
    void** stackTop = (void**)ctx->m_stackTop;
    if (stackTop > (void**)ctx->m_stack) {
        stackTop--;
        void* val = *stackTop;
        ctx->m_stackTop = stackTop;
        if (val) AptValue_Release(val);
    }
}

// 0x8027554c | 236 bytes
// NON_MATCHING - clone sprite action
void _FunctionAptActionCloneSprite(void* interp, LocalContextT* ctx) {
    // Pop depth, name, target from stack
    // Clone the sprite at target with new name and depth
}

// 0x80275638 | 240 bytes
// NON_MATCHING - remove sprite action
void _FunctionAptActionRemoveSprite(void* interp, LocalContextT* ctx) {
    // Pop target from stack
    // Remove the sprite from display list
}

// 0x80275cb8 | 100 bytes
void _FunctionAptActionStopDragMovie(void* interp, LocalContextT* ctx) {
    // Stop any active drag operation
    void* renderCtx = *(void**)((u8*)interp + 0x04);
    if (renderCtx) {
        *(void**)((u8*)renderCtx + 0x20) = 0;  // clear drag target
    }
}

// 0x80281b14 | 192 bytes
// NON_MATCHING - throw exception
void _FunctionAptActionThrow(void* interp, LocalContextT* ctx) {
    // Pop exception value from stack
    // Set exception state
}

// 0x80276138 | 252 bytes
// NON_MATCHING - getTimer returns milliseconds since start
void _FunctionAptActionGetTimer(void* interp, LocalContextT* ctx) {
    // Push current timer value onto stack as AptValue integer
}

// 0x8027aad4 | 104 bytes
void _FunctionAptActionPushDuplicate(void* interp, LocalContextT* ctx) {
    // Duplicate top of stack
    void** stackTop = (void**)ctx->m_stackTop;
    void* top = stackTop[-1];
    if (top) AptValue_AddRef_impl(top);
    *stackTop = top;
    ctx->m_stackTop = stackTop + 1;
}

// 0x8027ab3c | 112 bytes
void _FunctionAptActionStackSwap(void* interp, LocalContextT* ctx) {
    // Swap top two stack entries
    void** stackTop = (void**)ctx->m_stackTop;
    void* a = stackTop[-1];
    void* b = stackTop[-2];
    stackTop[-1] = b;
    stackTop[-2] = a;
}

// 0x8027eeec | 252 bytes
// NON_MATCHING - push integer 0
void _FunctionAptActionPush0(void* interp, LocalContextT* ctx) {
    // Create AptValue integer(0) and push
}

// 0x8027efe8 | 252 bytes
// NON_MATCHING - push integer 1
void _FunctionAptActionPush1(void* interp, LocalContextT* ctx) {
    // Create AptValue integer(1) and push
}

// 0x8027f3a4 | 160 bytes
// NON_MATCHING - call function and pop result
void _FunctionAptActionCallFuncAndPop(void* interp, LocalContextT* ctx) {
    // Pop function name, call it, discard result
}

// 0x8027f444 | 92 bytes
void _FunctionAptActionCallFuncSetVar(void* interp, LocalContextT* ctx) {
    // Pop function name, call it, set result to variable
}

// 0x8027f4a0 | 160 bytes
// NON_MATCHING - call method and pop
void _FunctionAptActionCallMethodPop(void* interp, LocalContextT* ctx) {
    // Pop method name and object, call method, discard result
}

// 0x8027f540 | 92 bytes
void _FunctionAptActionCallMethodSetVar(void* interp, LocalContextT* ctx) {
    // Pop method name and object, call method, set result
}

// 0x8027f59c | 144 bytes
// NON_MATCHING - push 'this' variable
void _FunctionAptActionPushThisVariable(void* interp, LocalContextT* ctx) {
    // Push current scope's 'this' onto stack
    void* scope = ctx->m_scope;
    if (scope) {
        AptValue_AddRef_impl(scope);
    }
    void** stackTop = (void**)ctx->m_stackTop;
    *stackTop = scope;
    ctx->m_stackTop = stackTop + 1;
}

// 0x8027f62c | 100 bytes
void _FunctionAptActionPushGlobalVariable(void* interp, LocalContextT* ctx) {
    // Push global object onto stack
    void* global = *(void**)((u8*)interp + 0x08);
    if (global) {
        AptValue_AddRef_impl(global);
    }
    void** stackTop = (void**)ctx->m_stackTop;
    *stackTop = global;
    ctx->m_stackTop = stackTop + 1;
}

// 0x8027f0e4 | 252 bytes
// NON_MATCHING - push boolean true
void _FunctionAptActionPushTrue(void* interp, LocalContextT* ctx) {
    // Create AptValue bool(true) and push
}

// 0x8027f1e0 | 252 bytes
// NON_MATCHING - push boolean false
void _FunctionAptActionPushFalse(void* interp, LocalContextT* ctx) {
    // Create AptValue bool(false) and push
}

// 0x8027f2dc | 100 bytes
void _FunctionAptActionPushNULL(void* interp, LocalContextT* ctx) {
    // Push null value
    void** stackTop = (void**)ctx->m_stackTop;
    *stackTop = 0;
    ctx->m_stackTop = stackTop + 1;
}

// 0x8027f340 | 100 bytes
void _FunctionAptActionPushUndefined(void* interp, LocalContextT* ctx) {
    // Push undefined value (global undefined singleton)
    void* undef = *(void**)((u8*)interp + 0x0C);  // gpUndefinedValue
    if (undef) AptValue_AddRef_impl(undef);
    void** stackTop = (void**)ctx->m_stackTop;
    *stackTop = undef;
    ctx->m_stackTop = stackTop + 1;
}

// 0x8027d7d8 | 232 bytes
// NON_MATCHING - goto frame by number
void _FunctionAptActionGotoFrame(void* interp, LocalContextT* ctx) {
    // Read frame number from instruction stream
    // Set current frame on target
}

// 0x8027da60 | 76 bytes
void _FunctionAptActionStoreRegister(void* interp, LocalContextT* ctx) {
    // Read register index from instruction
    // Store top of stack in register
    u8* ip = (u8*)ctx->m_ip;
    int regIdx = *ip++;
    ctx->m_ip = ip;
    void** stackTop = (void**)ctx->m_stackTop;
    void* val = stackTop[-1];
    void** regs = (void**)ctx->m_registers;
    if (regIdx < ctx->m_numRegisters) {
        if (regs[regIdx]) AptValue_Release(regs[regIdx]);
        regs[regIdx] = val;
        if (val) AptValue_AddRef_impl(val);
    }
}

// 0x8027dc4c | 228 bytes
// NON_MATCHING - goto frame by label
void _FunctionAptActionGotoLabel(void* interp, LocalContextT* ctx) {
    // Read label string from instruction stream
    // Find frame with matching label
    // Set current frame
}

// 0x8027ec04 | 96 bytes
void _FunctionAptActionBranchAlways(void* interp, LocalContextT* ctx) {
    // Read branch offset (s16) from instruction stream
    u8* ip = (u8*)ctx->m_ip;
    s16 offset = *(s16*)ip;
    ctx->m_ip = ip + 2 + offset;
}

// 0x8027e6b4 | 228 bytes
// NON_MATCHING - conditional branch on true
void _FunctionAptActionBranchIfTrue(void* interp, LocalContextT* ctx) {
    // Read offset, pop value, branch if truthy
}

// 0x8027f924 | 128 bytes
// NON_MATCHING - push string from byte-indexed dictionary
void _FunctionAptActionPushStringDictByte(void* interp, LocalContextT* ctx) {
    // Read byte index from instruction
    // Look up string in dictionary
    // Push as AptValue string
}

// 0x8027f9a4 | 140 bytes
// NON_MATCHING - push string from word-indexed dictionary
void _FunctionAptActionPushStringDictWord(void* interp, LocalContextT* ctx) {
    // Read word index from instruction
    // Look up string in dictionary
    // Push as AptValue string
}

// 0x80280014 | 192 bytes
// NON_MATCHING - get variable using dictionary byte key
void _FunctionAptActionStringDictByteGetVar(void* interp, LocalContextT* ctx) {
    // Read byte index, get string from dictionary
    // Look up variable by that name
    // Push result
}

// 0x802800d4 | 152 bytes
// NON_MATCHING - get member using dictionary byte key
void _FunctionAptActionStringDictByteGetMember(void* interp, LocalContextT* ctx) {
    // Pop object, read byte index for member name
    // Get member from object
    // Push result
}

// 0x80280274 | 196 bytes
// NON_MATCHING - call function using dict key and set var
void _FunctionAptActionDictCallFuncSetVar(void* interp, LocalContextT* ctx) {
    // Read function name from dictionary
    // Call function, set result to variable
}

// 0x80280440 | 196 bytes
// NON_MATCHING - call method using dict key and set var
void _FunctionAptActionDictCallMethodSetVar(void* interp, LocalContextT* ctx) {
    // Pop object, read method name from dictionary
    // Call method, set result to variable
}

// 0x80280978 | 228 bytes
// NON_MATCHING - conditional branch on false
void _FunctionAptActionBranchIfFalse(void* interp, LocalContextT* ctx) {
    // Read offset, pop value, branch if falsy
}

// ============================================================================
// Utility functions
// ============================================================================

// 0x8027263c | 96 bytes
int _escape2Char(char c1, char c2) {
    // Convert two hex chars to byte value
    int hi = 0, lo = 0;
    if (c1 >= '0' && c1 <= '9') hi = c1 - '0';
    else if (c1 >= 'a' && c1 <= 'f') hi = c1 - 'a' + 10;
    else if (c1 >= 'A' && c1 <= 'F') hi = c1 - 'A' + 10;
    if (c2 >= '0' && c2 <= '9') lo = c2 - '0';
    else if (c2 >= 'a' && c2 <= 'f') lo = c2 - 'a' + 10;
    else if (c2 >= 'A' && c2 <= 'F') lo = c2 - 'A' + 10;
    return (hi << 4) | lo;
}

// 0x80272938 | 76 bytes
int AptActionInterpreter_isFSCommand(void* self, char* cmd) {
    return strncmp_impl(cmd, "FSCommand:", 10) == 0;
}

// 0x80272984 | 80 bytes
void AptActionInterpreter_doFSCommand(void* self, char* cmd, char* args) {
    // Skip "FSCommand:" prefix
    char* actualCmd = cmd + 10;
    // Dispatch to registered FS command handler
}

// ============================================================================
// Destructors
// ============================================================================

// 0x80281f54 | 104 bytes
void AptMovieClip_dtor(void* self) {
    // Release display list
    // Release frame data
    // Call base dtor
}

// 0x80281ef0 | 100 bytes
void* AptStringObject_objectMemberLookup(void* self, void* aptVal, void* name) {
    // Look up member on string prototype
    void* proto = *(void**)((u8*)self + 0x14);
    if (proto) {
        void** vtable = *(void***)proto;
        typedef void* (*LookupFn)(void*, void*, void*);
        return ((LookupFn)vtable[6])(proto, aptVal, name);
    }
    return 0;
}

// 0x80281de0 | 180 bytes
void AptStringObject_dtor(void* self) {
    // Release string value
    void* str = *(void**)((u8*)self + 0x08);
    if (str) AptValue_Release(str);
    // Call base dtor chain
}

// 0x80281d88 | 88 bytes
void AptLookup_dtor(void* self) {
    // Release lookup data
    // Call base dtor
}

// 0x80281d30 | 88 bytes
void AptRegister_dtor(void* self) {
    // Release register value
    // Call base dtor
}

// 0x80281bd4 | 184 bytes
void AptActionInterpreter_dtor(void* self) {
    // Release all action tables
    // Release scope chains
    // Release string dictionary
    // Call base dtor
}

// 0x80281c8c | 144 bytes
// NON_MATCHING - static initialization
void __static_initialization_and_destruction_0_action() {
    // Initialize global AptActionInterpreter instance
    // Register all action handler functions
}
