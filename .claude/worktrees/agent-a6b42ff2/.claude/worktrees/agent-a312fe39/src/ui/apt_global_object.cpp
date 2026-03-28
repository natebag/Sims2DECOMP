// AptGlobalObject.cpp - APT global scope object
// Source: libaptz.a(AptGlobalObject.cpp.obj)
// 3 small functions (<=64 bytes) decompiled

#include "ui/apt_global_object.h"
#include "ui/apt_types.h"

// External functions (AptNativeHash embedded at this+12)
extern AptNativeHash* AptNativeHash_Cast(void* ptr);

// ============================================================================
// AptValueGC::IsGarbageCollected (0x802b5c24, 8 bytes) NON_MATCHING
// Duplicate instance for this TU. Already defined in apt_value.cpp.
// Original: li r3,1 / blr. GCC uses SDA vs lis for globals.
// ============================================================================

// ============================================================================
// AptGlobal::Set (0x802b5d0c, 36 bytes) NON_MATCHING
// Delegates to embedded AptNativeHash at this+12.
// Original:
//   stwu r1,-8(r1) / mflr r0 / stw r0,12(r1)
//   addi r3,r3,12  (this + 12 = embedded hash)
//   bl AptNativeHash::Set
//   lwz r0,12(r1) / mtlr r0 / addi r1,r1,8 / blr
// ============================================================================
void AptGlobal::Set(EAStringC* key, AptValue* val) {
    AptNativeHash* hash = (AptNativeHash*)((u8*)this + 12);
    hash->Set(key, val);
}

// ============================================================================
// AptGlobal::Lookup (0x802b5d30, 36 bytes) NON_MATCHING
// Delegates to embedded AptNativeHash at this+12.
// Original:
//   stwu r1,-8(r1) / mflr r0 / stw r0,12(r1)
//   addi r3,r3,12  (this + 12 = embedded hash)
//   bl AptNativeHash::Lookup
//   lwz r0,12(r1) / mtlr r0 / addi r1,r1,8 / blr
// ============================================================================
AptValue* AptGlobal::Lookup(EAStringC* key) const {
    AptNativeHash* hash = (AptNativeHash*)((u8*)this + 12);
    return hash->Lookup(key);
}
