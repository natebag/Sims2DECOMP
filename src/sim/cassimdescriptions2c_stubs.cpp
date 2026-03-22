// cassimdescriptions2c_stubs.cpp - Stub implementations for Cassimdescriptions2C
// Auto-generated from symbols.json - 37 functions
// These are stub implementations to register progress.
// Each function needs proper decompilation to match the original binary.

#include "types.h"

// 0x802540DC | 52 bytes
CasSimDescriptionS2C::CasSimDescriptionS2C(void) { }

// 0x80254110 | 536 bytes
void CasSimDescriptionS2C::ClearSim(bool) { }

// 0x80254398 | 412 bytes
void CasSimDescriptionS2C::GetBodyPartIndex(eBodyPartS2C) const { }

// 0x80254534 | 352 bytes
void CasSimDescriptionS2C::SetBodyPartIndex(eBodyPartS2C, signed char) { }

// 0x80254694 | 540 bytes
void CasSimDescriptionS2C::GetBodyPartTextureIndex(eBodyPartS2C) const { }

// 0x802548B0 | 408 bytes
void CasSimDescriptionS2C::SetBodyPartTextureIndex(eBodyPartS2C, signed char) { }

// 0x80254A48 | 516 bytes
void CasSimDescriptionS2C::GetBodyPartParam(eBodyPartS2C) const { }

// 0x80254C4C | 900 bytes
void CasSimDescriptionS2C::ReadOldDescription(ReconBuffer *) { }

// 0x80254FD0 | 1288 bytes
void CasSimDescriptionS2C::DoStream(ReconBuffer *, int) { }

// 0x802554D8 | 272 bytes
void CasSimDescriptionS2C::AssertWithInfo(char *) { }

// 0x802555E8 | 3988 bytes
void CasSimDescriptionS2C::Verify(void) { }

// 0x8025657C | 272 bytes
void CasSimDescriptionS2C::VerifyBodyPartNoTexture(CasSimPartsS2C &, eBodyPartS2C, signed char &, signed char, bool) { }

// 0x8025668C | 516 bytes
void CasSimDescriptionS2C::VerifyBodyPartWithNoOptions(CasSimPartsS2C &, eBodyPartS2C, signed char &, signed char &, signed char, signed char, bool) { }

// 0x80256890 | 640 bytes
void CasSimDescriptionS2C::VerifyBodyPartWithOneOption(CasSimPartsS2C &, eBodyPartS2C, signed char &, signed char &, signed char &, signed char, signed char, signed char, bool) { }

// 0x80256B10 | 68 bytes
void CasSimDescriptionS2C::SetInnerLayerTorsoStyle(CasSimPartsS2C &) { }

// 0x80256B54 | 28 bytes
void CasSimDescriptionS2C::SwitchInnerLayerTorso(bool) { }

// 0x80256B70 | 156 bytes
void CasSimDescriptionS2C::SwitchMidLayerTorso(bool) { }

// 0x80256C0C | 64 bytes
void CasSimDescriptionS2C::SetMidLayerTorsoStyle(Sim::MidLayerTorsoStyleS2C, CasSimPartsS2C &) { }

// 0x80256C4C | 124 bytes
void CasSimDescriptionS2C::InnerLayerHalfTorsoRequired(CasSimPartsS2C &) { }

// 0x80256CC8 | 328 bytes
void CasSimDescriptionS2C::SwitchInnerLayerSleeveToFirstAvailableStyle(CasSimPartsS2C &) { }

// 0x80256E10 | 124 bytes
void CasSimDescriptionS2C::MidLayerHalfTorsoRequired(CasSimPartsS2C &) { }

// 0x80256E8C | 340 bytes
void CasSimDescriptionS2C::SwitchMidLayerTorsoToFirstAvailableStyle(CasSimPartsS2C &, bool) { }

// 0x80256FE0 | 160 bytes
void CasSimDescriptionS2C::SwitchMidLayerCollarToFirstAvailableStyle(CasSimPartsS2C &) { }

// 0x80257080 | 216 bytes
void CasSimDescriptionS2C::SwitchMidLayerSleeveToFirstAvailableStyle(CasSimPartsS2C &) { }

// 0x80257158 | 160 bytes
void CasSimDescriptionS2C::SwitchOuterLayerTorsoToFirstAvailableStyle(CasSimPartsS2C &) { }

// 0x802571F8 | 272 bytes
void CasSimDescriptionS2C::SwitchOuterLayerCollarToFirstAvailableStyle(CasSimPartsS2C &) { }

// 0x80257308 | 160 bytes
void CasSimDescriptionS2C::SwitchOuterLayerSleeveToFirstAvailableStyle(CasSimPartsS2C &) { }

// 0x802573A8 | 344 bytes
void CasSimDescriptionS2C::SwitchLowerBodyToFirstAvailableStyle(CasSimPartsS2C &) { }

// 0x80257500 | 340 bytes
void CasSimDescriptionS2C::SwitchHatToFirstAvailableStyle(CasSimPartsS2C &) { }

// 0x80257654 | 136 bytes
void CasSimDescriptionS2C::ShouldBootTopBeDisplayed(CasSimPartsS2C &) { }

// 0x802576DC | 48 bytes
void CasSimDescriptionS2C::SetShoeBoottopDisplayedFlag(CasSimPartsS2C &) { }

// 0x8025770C | 320 bytes
void CasSimDescriptionS2C::SetBodyTypeMorphValues(void) { }

// 0x8025784C | 120 bytes
void CasSimDescriptionS2C::InitializeToDefaultCostume(bool) { }

// 0x802578C4 | 92 bytes
void CasSimDescriptionS2C::GetCompositeTextureID(char *, eSimPartsMapLocation) const { }

// 0x80257920 | 344 bytes
void CasSimDescriptionS2C::GetCompositeTextureName(char *, eSimPartsMapLocation) const { }

// 0x80257A78 | 192 bytes
void CasSimDescriptionS2C::GetHairBodyPart(void) { }

// 0x80257B38 | 4988 bytes
void CasSimDescriptionS2C::WriteSimDescriptionToTextFile(__sFILE *, SimModel *) { }
