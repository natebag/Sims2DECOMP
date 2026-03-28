// aptactionqueuec_stubs.cpp - Stub implementations for Aptactionqueuec
// Auto-generated from symbols.json - 8 functions
// These are stub implementations to register progress.
// Each function needs proper decompilation to match the original binary.

#include "types.h"
#include "stub_classes.h"

// 0x804039A8 | 256 bytes
void AptActionQueueC::ClearActions(void) { }

// 0x80403AA8 | 196 bytes
void AptActionQueueC::AddActionBack(AptActionBlock *, AptCIH *, unsigned int) { }

// 0x80403B6C | 196 bytes
void AptActionQueueC::AddActionFront(AptActionBlock *, AptCIH *, unsigned int) { }

// 0x80403C30 | 240 bytes
void AptActionQueueC::AddFunctionBack(AptCIH *, AptValue *, int, unsigned int) { }

// 0x80403D20 | 240 bytes
void AptActionQueueC::AddFunctionFront(AptCIH *, AptValue *, int, unsigned int) { }

// 0x80403E10 | 440 bytes
void AptActionQueueC::RemoveActionFor(AptCIH *) { }

// 0x80403FFC | 80 bytes
void AptActionQueueC::GetDequeLocation(int) const { }

// 0x8040404C | 196 bytes
void AptActionQueueC::RegisterReferences(void) { }
