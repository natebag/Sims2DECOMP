// cassimpartss2c_stubs.cpp - Stub implementations for Cassimpartss2C
// Auto-generated from symbols.json - 34 functions
// These are stub implementations to register progress.
// Each function needs proper decompilation to match the original binary.

#include "types.h"

// 0x80259FB4 | 172 bytes
CasSimPartsS2C::CasSimPartsS2C(void) { }

// 0x8025A060 | 88 bytes
CasSimPartsS2C::~CasSimPartsS2C(void) { }

// 0x8025A0B8 | 236 bytes
void CasSimPartsS2C::SetGender(bool) { }

// 0x8025A1A4 | 332 bytes
void CasSimPartsS2C::GetNumBodyModels(eBodyPartS2C) const { }

// 0x8025A2F0 | 620 bytes
void CasSimPartsS2C::GetNumBodyTextures(eBodyPartS2C, unsigned int) const { }

// 0x8025A55C | 72 bytes
void CasSimPartsS2C::GetNumTattooTextures(eTattooTextureTypeS2C) const { }

// 0x8025A5A4 | 3240 bytes
void CasSimPartsS2C::GetModelID(eBodyPartS2C, unsigned int, Sim::SimPartsS2CParam) const { }

// 0x8025B24C | 392 bytes
void CasSimPartsS2C::GetSkinTextureID(eSkinColorType, eBodyTypeS2C, eSimPartsMapLocation) { }

// 0x8025B3D4 | 340 bytes
void CasSimPartsS2C::GetSkinTexturesDatasetID(eSkinColorType, eBodyTypeS2C) { }

// 0x8025B528 | 204 bytes
void CasSimPartsS2C::GetTextureIDFromVector(VECTOR<unsigned int> &, int, bool, unsigned char, char *) const { }

// 0x8025B5F4 | 4088 bytes
void CasSimPartsS2C::GetTextureID(eBodyPartS2C, CasSimDescriptionS2C *, bool) const { }

// 0x8025C5EC | 36 bytes
void CasSimPartsS2C::GetReflectionTextureID(eBodyPartS2C, CasSimDescriptionS2C *) const { }

// 0x8025C610 | 260 bytes
void CasSimPartsS2C::GetTattooTextureID(eTattooTextureTypeS2C, unsigned int) const { }

// 0x8025C714 | 476 bytes
void CasSimPartsS2C::IsGamecubeOnly(eBodyPartS2C, unsigned int) const { }

// 0x8025C8F0 | 516 bytes
void CasSimPartsS2C::GetIconTextureId(eBodyPartS2C, unsigned int) const { }

// 0x8025CAF4 | 256 bytes
void CasSimPartsS2C::GetIconTattooTextureId(eTattooTextureTypeS2C, unsigned int) const { }

// 0x8025CBF4 | 40 bytes
void CasSimPartsS2C::OuterLayerTorsoRequiresFullTorsoMeshInMidLayer(unsigned int) const { }

// 0x8025CC1C | 40 bytes
void CasSimPartsS2C::OuterLayerTorsoHidesMusicPlayer(unsigned int) const { }

// 0x8025CC44 | 188 bytes
void CasSimPartsS2C::LongSleeveDoesNotHideArmAccessory(eBodyPartS2C, unsigned int) const { }

// 0x8025CD00 | 268 bytes
void CasSimPartsS2C::OuterLayerCollarIsAHood(unsigned int, Sim::OuterLayerCollarStyleS2C) const { }

// 0x8025CE0C | 188 bytes
void CasSimPartsS2C::OuterLayerTorsoIsAHood(unsigned int, Sim::OuterLayerTorsoStyleS2C) const { }

// 0x8025CEC8 | 260 bytes
void CasSimPartsS2C::CanBeWornSleeveless(eBodyPartS2C, unsigned int, Sim::SimPartsS2CParam) const { }

// 0x8025CFCC | 216 bytes
void CasSimPartsS2C::MidLayerTorsoHidesBelt(unsigned int, Sim::MidLayerTorsoStyleS2C, unsigned int) const { }

// 0x8025D0A4 | 220 bytes
void CasSimPartsS2C::OuterLayerTorsoHidesBelt(unsigned int, Sim::OuterLayerTorsoStyleS2C, unsigned int) const { }

// 0x8025D180 | 608 bytes
void CasSimPartsS2C::GetUnlockGroupNum(eBodyPartS2C, unsigned int) const { }

// 0x8025D5AC | 220 bytes
void CasSimPartsS2C::GetTattoosForLocation(eTattooTextureTypeS2C, unsigned char *) const { }

// 0x8025D688 | 140 bytes
void CasSimPartsS2C::ConvertTattooTextureTypeToLocation(eTattooTextureTypeS2C) const { }

// 0x8025D714 | 168 bytes
void CasSimPartsS2C::GetIndexFromResId(eBodyPartS2C, int, Sim::SimPartsS2CParam, int *) { }

// 0x8025D7BC | 44 bytes
void CasSimPartsS2C::GetGameStateModelID(unsigned int) const { }

// 0x8025D7E8 | 44 bytes
void CasSimPartsS2C::GetGameStateTextureID(unsigned int) const { }

// 0x8025D814 | 1672 bytes
void CasSimPartsS2C::GetWeldableBodyPartConnections(eBodyPartS2C, unsigned int *, unsigned int) { }

// 0x8025DE9C | 240 bytes
void CasSimPartsS2C::GetNumBodyPartOptions(eBodyPartS2C) { }

// 0x8025DF8C | 236 bytes
void CasSimPartsS2C::GetBodyPartName(eBodyPartS2C) { }

// 0x8025E078 | 7060 bytes
void CasSimPartsS2C::VerifyBodyPartsData(void) { }
