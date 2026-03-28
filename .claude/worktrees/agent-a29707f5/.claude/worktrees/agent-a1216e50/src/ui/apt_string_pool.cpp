// StringPool.cpp - String interning pool
// Source: libaptz.a(StringPool.cpp.obj)
// 3 small functions (<=64 bytes) decompiled
//
// All NON_MATCHING due to SN Systems vs GCC codegen differences.

#include "ui/apt_value.h"
#include "ui/apt_ea_string.h"

// External: static init/destroy function from StringPool.cpp
// Called with (action=1, priority=0xFFFF) for construction
// Called with (action=0, priority=0xFFFF) for destruction
extern void StringPool_static_init(int action, unsigned int priority);

// ============================================================================
// EAStringC::IsEmpty (0x802c4a14, 28 bytes) NON_MATCHING
// Duplicate instance for StringPool TU.
// Same code as all other EAStringC::IsEmpty instances:
//   lwz r0,0(r3) / lis r3,hi(EmptyData) / addi r3,r3,lo(EmptyData)
//   xor r3,r0,r3 / subfic r9,r3,0 / adde r3,r9,r3 / blr
// ============================================================================
// Already defined in apt_value.cpp

// ============================================================================
// global constructors keyed to StringPool::spPool (0x802c4a30, 44 bytes)
// NON_MATCHING
// Original:
//   li r4,0 / li r3,1 / ori r4,r4,0xFFFF
//   bl __static_initialization_and_destruction_0
// Calls the static init function with action=1, priority=65535.
// ============================================================================
// This is compiler-generated startup code. We document it but don't
// reimplement it since it would be linked from the global ctor table.

// ============================================================================
// global destructors keyed to StringPool::spPool (0x802c4a5c, 44 bytes)
// NON_MATCHING
// Original:
//   li r4,0 / li r3,0 / ori r4,r4,0xFFFF
//   bl __static_initialization_and_destruction_0
// Calls the static init function with action=0, priority=65535.
// ============================================================================
// This is compiler-generated cleanup code.
