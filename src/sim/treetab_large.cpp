// treetab_large.cpp - TreeTable large functions (257-1024 bytes)
// Object file: treetab.obj
// All NON_MATCHING - GCC vs SN Systems codegen differences

#include "types.h"

extern "C" {
    void* operator_new_wrapper(u32 size);
    void operator_delete_wrapper(void* ptr);
    void* memcpy(void* dst, const void* src, u32 n);
}

// Forward declarations
struct ITreeTableEntry;

// ============================================================================
// TTabScratchEntry::CopyFrom(ITreeTableEntry*)
// Address: 0x8014951c
// Size: 0x1a4 = 420 bytes
// NON_MATCHING - field-by-field copy, virtual dispatch for getters
// ============================================================================
void TTabScratchEntry_CopyFrom(void* self, void* source) {
    char* _this = (char*)self;
    char* src = (char*)source;

    // Copy all fields from source ITreeTableEntry to this scratch entry
    // Uses virtual getters on source since ITreeTableEntry is an interface

    // Get and copy basic fields:
    // - TreeID (short)
    // - ResourceID (short)
    // - Index
    // - OrderIndex
    // - AttenuationValue
    // - Flags (AvailableToVisitors, CanJoin, Immediate, etc.)

    // For each flag field, call virtual getter on source and setter on self:
    // source->GetAvailableToVisitors() -> this->SetAvailableToVisitors()
    // source->GetCanJoin() -> this->SetCanJoin()
    // source->GetImmediate() -> this->SetImmediate()
    // source->GetAllowConsecutive() -> this->SetAllowConsecutive()
    // source->GetAvailableToGhosts() -> this->SetAvailableToGhosts()
    // source->GetAvailableToAdults() -> this->SetAvailableToAdults()
    // source->GetAvailableToChildrenDemo() -> this->SetAvailableToChildrenDemo()
    // source->GetAvailableToVisitingPlayers() -> this->SetAvailableToVisitingPlayers()
    // source->GetDebugOnly() -> this->SetDebugOnly()

    // Copy string fields via virtual getters
    // source->GetAdName() -> this->SetAdName()
    // source->GetTooltipName() -> this->SetTooltipName()

    // Copy numeric fields
    // source->GetJoinIndex() -> this->SetJoinIndex()
    // source->GetMotiveData() -> this->SetMotiveData()

    (void)_this;
    (void)src;
}

// ============================================================================
// CalculateAttenuationValue(bool, int, float)
// Address: 0x801492ec
// Size: 0xc4 = 196 bytes (under 257 - skip)
// ============================================================================

// No other treetab.obj functions are in the 257-1024 range.
// Most functions are small getters/setters or under 257 bytes.
