// aptanimationpooldata_stubs.cpp - Stub implementations for Aptanimationpooldata
// Auto-generated from symbols.json - 23 functions
// These are stub implementations to register progress.
// Each function needs proper decompilation to match the original binary.

#include "types.h"

// 0x80401DC4 | 548 bytes
AptAnimationPoolData::AptAnimationPoolData(AptInitParmsT &) { }

// 0x80401FE8 | 688 bytes
AptAnimationPoolData::~AptAnimationPoolData(void) { }

// 0x80402298 | 704 bytes
void AptAnimationPoolData::PreDestroy(void) { }

// 0x80402598 | 932 bytes
void AptAnimationPoolData::tickIntervalTimers(int) { }

// 0x8040293C | 308 bytes
void AptAnimationPoolData::_tickNewInsts(void) { }

// 0x80402A70 | 800 bytes
void AptAnimationPoolData::runActions(void) { }

// 0x80402D90 | 132 bytes
void AptAnimationPoolData::addAnalogInput(AptAnalogStickInfo) { }

// 0x80402EE0 | 396 bytes
void AptAnimationPoolData::removeTimerFunctions(AptCIH *) { }

// 0x8040306C | 140 bytes
void AptAnimationPoolData::clearBIL(void) { }

// 0x804030F8 | 184 bytes
void AptAnimationPoolData::appendButtonToBIL(AptCIH *, AptMatrix *) { }

// 0x804031B0 | 196 bytes
void AptAnimationPoolData::removeFromBIL(AptCIH *) { }

// 0x804036FC | 684 bytes
void AptAnimationPoolData::RegisterReferences(void) { }

// 0x8041B8FC | 472 bytes
void AptAnimationPoolData::_doButtonActions(AptCIH *, int) { }

// 0x8041BAD4 | 412 bytes
void AptAnimationPoolData::setValidFocusButton(void) { }

// 0x8041BD60 | 408 bytes
void AptAnimationPoolData::_isPointInButtonHitTestRegion(AptCharacterButton *, AptMatrix *, int, int) { }

// 0x8041BEF8 | 640 bytes
void AptAnimationPoolData::ProcessInputSet(AptInputType, AptInputState, unsigned int, AptInputController, bool) { }

// 0x8041C178 | 180 bytes
void AptAnimationPoolData::_pointHits(AptCIH *, unsigned int) { }

// 0x8041C22C | 220 bytes
void AptAnimationPoolData::ProcessListenerEvents(AptInputType, AptInputState, unsigned int, AptInputController) { }

// 0x8041C308 | 580 bytes
void AptAnimationPoolData::AddListenerToQueue(AptValue *, int, unsigned int) { }

// 0x8041C54C | 1320 bytes
void AptAnimationPoolData::HandleFocusButton(AptInputType, AptInputState, AptCIH **) { }

// 0x8041CA74 | 428 bytes
void AptAnimationPoolData::HandleAutoNav(AptCIH *, AptInputType, AptInputState) { }

// 0x8041CC20 | 160 bytes
void AptAnimationPoolData::ProcessAptInput(unsigned int, bool) { }

// 0x8041CCC8 | 112 bytes
void AptAnimationPoolData::ProcessInputs(void) { }
