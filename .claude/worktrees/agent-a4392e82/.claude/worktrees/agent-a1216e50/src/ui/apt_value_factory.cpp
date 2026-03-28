// AptValueFactory.cpp - Factory for creating APT value objects
// Source: libaptz.a(AptValueFactory.cpp.obj)
// 2 small functions (<=64 bytes) decompiled
//
// All NON_MATCHING due to SN Systems vs GCC codegen differences.

#include "ui/apt_value_factory.h"
#include "ui/apt_value.h"

// External functions
class AptString;
extern AptValue* AptString_Create(char* str);  // AptString::Create at 0x802aeb54

// External globals
extern AptValue* gpUndefinedValue;

// ============================================================================
// AptValueFactory::CreateString (0x802b4ddc, 32 bytes) NON_MATCHING
// Original:
//   stwu r1,-8(r1) / mflr r0 / stw r0,12(r1)
//   bl AptString::Create  (0x802aeb54)
//   lwz r0,12(r1) / mtlr r0 / addi r1,r1,8 / blr
// Simple wrapper around AptString::Create.
// ============================================================================
AptValue* AptValueFactory::CreateString(char* str) {
    return AptString_Create(str);
}

// ============================================================================
// AptValueFactory::CreateUndefined (0x802b5124, 8 bytes) NON_MATCHING
// Original:
//   lwz r3,-22936(r13) / blr
// Returns the global undefined value singleton.
// ============================================================================
AptValue* AptValueFactory::CreateUndefined() {
    return gpUndefinedValue;
}
