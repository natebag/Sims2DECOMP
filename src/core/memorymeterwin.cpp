#if 0 // SKIP
// memorymeterwin.cpp - Debug memory meter window small functions
// From: memorymeterwin.obj
// Small functions (<=64 bytes) decompiled from this object

#include "core/memorymeterwin.h"

// ============================================================================
// External references
// ============================================================================

// __builtin_delete (0x802d1220)
extern "C" void __builtin_delete(void* ptr);

// EMemoryMeterWin::PollMemoryLevels (0x80057a1c)

// ============================================================================
// EMemoryMeterWin::Init(void)
// 0x80057998 - 4 bytes
// Empty no-op (just blr)
// ============================================================================
// blr
void EMemoryMeterWin::Init(void) {
    // empty
}

// ============================================================================
// EMemoryMeterWin::Reset(void)
// 0x8005799C - 4 bytes
// Empty no-op (just blr)
// ============================================================================
// blr
void EMemoryMeterWin::Reset(void) {
    // empty
}

// ============================================================================
// EMemoryMeterWin::SetState(Panelstateman::Panelstate)
// 0x800579A0 - 32 bytes
// Delegates to PollMemoryLevels
// ============================================================================
// stwu r1,-8(r1); mflr r0; stw r0,12(r1)
// bl EMemoryMeterWin::PollMemoryLevels
// lwz r0,12(r1); mtlr r0; addi r1,r1,8; blr
// NON_MATCHING - GCC tail-call-optimizes to 'b' instead of bl+prolog/epilog
void EMemoryMeterWin::SetState(int state) {
    PollMemoryLevels();
}

// ============================================================================
// EMemoryMeterWin::SetEvent(Panelstateman::PanelEvent, unsigned int)
// 0x80057C14 - 4 bytes
// Empty no-op (just blr)
// ============================================================================
// blr
void EMemoryMeterWin::SetEvent(int event, unsigned int param) {
    // empty
}

// ============================================================================
// Panelstateman::~Panelstateman(void)
// 0x803A0218 - 52 bytes
// Virtual destructor: sets vtable at +0x04, conditionally deletes
// ============================================================================
// lis r9,0x8046; andi. r0,r4,1; addi r9,r9,-13992
// stw r9,4(r3); beq- skip; bl __builtin_delete
// NON_MATCHING - vtable address is a link-time constant
Panelstateman::~Panelstateman(void) {
    // compiler generates: *(this+4) = &Panelstateman_vtable;
    // if (__in_charge & 1) __builtin_delete(this);
}
#endif
