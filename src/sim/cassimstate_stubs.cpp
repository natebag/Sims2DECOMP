// cassimstate_stubs.cpp - Stub implementations for Cassimstate
// Auto-generated from symbols.json - 21 functions
// These are stub implementations to register progress.
// Each function needs proper decompilation to match the original binary.

#include "types.h"
#include "stub_classes.h"

// 0x80267F10 | 80 bytes
CasSimState::CasSimState(void) { }

// 0x80268050 | 1828 bytes
void CasSimState::GetAdjacentIndex(unsigned char, bool) { }

// 0x80268774 | 1736 bytes
void CasSimState::GetMoreThanOneOption(unsigned char) { }

// 0x80268E3C | 844 bytes
void CasSimState::GetNextAvailableSleeveStyle(eBodyPartS2C, signed char, bool, CasSimPartsS2C &) { }

// 0x80269188 | 272 bytes
void CasSimState::GetNextSleeveStyle(eBodyPartS2C, int, bool) { }

// 0x80269298 | 208 bytes
void CasSimState::GetNextAvailableMidLayerTorsoStyle(signed char, bool, CasSimPartsS2C &) { }

// 0x80269368 | 280 bytes
void CasSimState::GetNextMidLayerTorsoStyle(int, bool) { }

// 0x80269480 | 212 bytes
void CasSimState::GetNextAvailableMidLayerCollarStyle(signed char, CasSimPartsS2C &) { }

// 0x80269554 | 212 bytes
void CasSimState::GetNextAvailableOuterLayerTorsoStyle(signed char, CasSimPartsS2C &) { }

// 0x80269628 | 216 bytes
void CasSimState::GetNextAvailableOuterLayerCollarStyle(signed char, bool, CasSimPartsS2C &) { }

// 0x80269700 | 216 bytes
void CasSimState::GetNextAvailableLowerBodyStyle(signed char, bool, CasSimPartsS2C &) { }

// 0x802697D8 | 536 bytes
void CasSimState::GetNextAvailableHairStyle(signed char, bool, CasSimPartsS2C &) { }

// 0x802699F0 | 216 bytes
void CasSimState::GetNextAvailableHatStyle(signed char, bool, CasSimPartsS2C &) { }

// 0x80269AC8 | 216 bytes
void CasSimState::GetNextAvailableArmAccessoryStyle(signed char, bool, CasSimPartsS2C &) { }

// 0x80269BA0 | 176 bytes
void CasSimState::GetNextBodyPartStyle(int, int, bool) { }

// 0x80269C50 | 172 bytes
void CasSimState::HandleEventInitSim(CasEventInitSim &) { }

// 0x80269CFC | 280 bytes
void CasSimState::HandleEventResetSim(CasEventResetSim &) { }

// 0x80269E14 | 88 bytes
void CasSimState::HandleEventStoreSim(CasEventStoreSim &) { }

// 0x80269E6C | 2020 bytes
void CasSimState::HandleEventChangeSim(CasEventChangeSimS2C &) { }

// 0x8026A650 | 252 bytes
void CasSimState::HandleEventMorphSim(CasEventMorphSimS2C &) { }

// 0x8026A74C | 108 bytes
void CasSimState::SetSimName(wchar_t *, wchar_t *) { }
