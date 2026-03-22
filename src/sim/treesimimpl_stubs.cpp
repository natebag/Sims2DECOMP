// treesimimpl_stubs.cpp - Stub implementations for Treesimimpl
// Auto-generated from symbols.json - 27 functions
// These are stub implementations to register progress.
// Each function needs proper decompilation to match the original binary.

#include "types.h"

// 0x8020C208 | 476 bytes
TreeSimImpl::~TreeSimImpl(void) { }

// 0x8020C3E4 | 8 bytes
void TreeSimImpl::SetError(short) { }

// 0x8020C3EC | 8 bytes
void TreeSimImpl::GetError(void) { }

// 0x8020C3F4 | 12 bytes
void TreeSimImpl::ClearError(void) { }

// 0x8020C6E4 | 76 bytes
void TreeSimImpl::GetISimInstance(void) { }

// 0x8020C730 | 508 bytes
TreeSimImpl::TreeSimImpl(int) { }

// 0x8020C92C | 56 bytes
void TreeSimImpl::Initialize(int, short *) { }

// 0x8020C964 | 92 bytes
void TreeSimImpl::GetCurrentNode(short *, short *) { }

// 0x8020C9C0 | 196 bytes
void TreeSimImpl::GetCurrentPrimitive(void) { }

// 0x8020CAF0 | 488 bytes
void TreeSimImpl::Gosub(Behavior *, short *, short) { }

// 0x8020CCD8 | 892 bytes
void TreeSimImpl::RunCheckTree(Behavior *, short, short, short *) { }

// 0x8020D054 | 56 bytes
void TreeSimImpl::RunOneTickTree(Behavior *, short, short, short *) { }

// 0x8020D08C | 72 bytes
void TreeSimImpl::HandleBreakpoint(StackElem *, BehaviorNode *) { }

// 0x8020D0D8 | 2436 bytes
void TreeSimImpl::DoNodeAction(StackElem *) { }

// 0x8020DA5C | 128 bytes
void TreeSimImpl::GetLastTransition(void) { }

// 0x8020DADC | 136 bytes
void TreeSimImpl::Simulate(int) { }

// 0x8020DB64 | 244 bytes
void TreeSimImpl::GetHighLevelAction(void) { }

// 0x8020DC58 | 60 bytes
void TreeSimImpl::GetCurElem(void) { }

// 0x8020DC94 | 272 bytes
void TreeSimImpl::GetMainSimElem(void) { }

// 0x8020DDA4 | 36 bytes
void TreeSimImpl::GetNthElem(short) { }

// 0x8020DDC8 | 40 bytes
void TreeSimImpl::GetStackSize(void) { }

// 0x8020DDF0 | 4 bytes
void TreeSimImpl::StackJustPopped(void) { }

// 0x8020EED0 | 8 bytes
void TreeSimImpl::GetIterations(void) { }

// 0x8020EED8 | 8 bytes
void TreeSimImpl::GetLastResult(void) { }

// 0x8020EEE0 | 16 bytes
void TreeSimImpl::HasMainTreeSim(void) { }

// 0x8020EEF0 | 8 bytes
void TreeSimImpl::SetNoMainTreeSim(bool) { }

// 0x8020EEF8 | 4 bytes
void TreeSimImpl::AsTreeSim(void) { }
