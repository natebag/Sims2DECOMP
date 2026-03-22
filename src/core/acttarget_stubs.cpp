// acttarget_stubs.cpp - Stub implementations for Acttarget
// Auto-generated from symbols.json - 22 functions
// These are stub implementations to register progress.
// Each function needs proper decompilation to match the original binary.

#include "types.h"

// 0x802AFEE0 | 7532 bytes
ACTTarget::ACTTarget(int) { }

// 0x802B1C4C | 620 bytes
ACTTarget::~ACTTarget(void) { }

// 0x802B1EB8 | 468 bytes
void ACTTarget::SetVariable(char *, char *) { }

// 0x802B208C | 244 bytes
void ACTTarget::GetVariable(char *) { }

// 0x802B2180 | 392 bytes
void ACTTarget::GetLocalizable(char *) { }

// 0x802B2308 | 916 bytes
void ACTTarget::Update(void) { }

// 0x802B26B4 | 440 bytes
void ACTTarget::UpdateActionQueue(void) { }

// 0x802B2874 | 500 bytes
void ACTTarget::AddAction(int, Interaction *, BString2 &, unsigned int, ERShader *, unsigned int) { }

// 0x802B2A68 | 800 bytes
void ACTTarget::PlaceItem(ACTTarget::ACTRecord *, int, Interaction *, int, cXPerson *, BString2 &, unsigned int, ERShader *, unsigned int) { }

// 0x802B2D88 | 644 bytes
void ACTTarget::RemoveAction(int, Interaction *) { }

// 0x802B300C | 136 bytes
void ACTTarget::RemoveAllActions(int) { }

// 0x802B309C | 104 bytes
void ACTTarget::GetRecord(void) { }

// 0x802B3104 | 140 bytes
void ACTTarget::ReOrderActionQueue(void) { }

// 0x802B3194 | 168 bytes
void ACTTarget::GetInteractionFromID(int) { }

// 0x802B323C | 84 bytes
void ACTTarget::MoveCancelCursorUp(void) { }

// 0x802B3290 | 72 bytes
void ACTTarget::MoveCancelCursorDown(void) { }

// 0x802B32D8 | 184 bytes
void ACTTarget::CancelModeEnabled(bool) { }

// 0x802B3390 | 384 bytes
void ACTTarget::CancelCurrentObject(void) { }

// 0x802B3510 | 264 bytes
void ACTTarget::UpdateCancelModeWidgets(void) { }

// 0x802B3618 | 124 bytes
void ACTTarget::ExitCancelMode(void) { }

// 0x802B3694 | 180 bytes
void ACTTarget::CancellingLastObject(void) { }

// 0x803191F8 | 100 bytes
ACTTarget::iqRecord::~iqRecord(void) { }
