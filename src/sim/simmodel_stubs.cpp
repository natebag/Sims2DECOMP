// simmodel_stubs.cpp - Stub implementations for Simmodel
// Auto-generated from symbols.json - 62 functions
// These are stub implementations to register progress.
// Each function needs proper decompilation to match the original binary.

#include "types.h"

// 0x800BF2CC | 268 bytes
SimModel::SimModel(void) { }

// 0x800BF3D8 | 140 bytes
SimModel::~SimModel(void) { }

// 0x800BF464 | 160 bytes
void SimModel::Init(CasSimDescriptionS2C *, bool) { }

// 0x800BF590 | 68 bytes
void SimModel::DeallocateAllModels(void) { }

// 0x800BF5D4 | 168 bytes
void SimModel::DeallocateModelPart(eBodyPartS2C) { }

// 0x800BF67C | 120 bytes
void SimModel::DeallocateMorphResources(void) { }

// 0x800BF6F4 | 164 bytes
void SimModel::DeallocateAllSkinTextures(void) { }

// 0x800BF798 | 160 bytes
void SimModel::SetSimDescription(CasSimDescriptionS2C *) { }

// 0x800BF84C | 256 bytes
void SimModel::DetachSimDescription(void) { }

// 0x800BF94C | 400 bytes
void SimModel::Clone(void) { }

// 0x800BFADC | 416 bytes
void SimModel::SetAllModels(void) { }

// 0x800BFC7C | 576 bytes
void SimModel::SetModelPart(eBodyPartS2C, unsigned int) { }

// 0x800BFEBC | 128 bytes
void SimModel::UpdateModelPart(eBodyPartS2C, bool, bool) { }

// 0x800BFF3C | 824 bytes
void SimModel::UpdateQueuedModelPart(eBodyPartS2C, bool, bool) { }

// 0x800C0274 | 328 bytes
void SimModel::ChangeModelPart(eBodyPartS2C, unsigned int, bool, bool) { }

// 0x800C03BC | 292 bytes
void SimModel::GetChangedModels(int *) { }

// 0x800C04E0 | 192 bytes
void SimModel::SetModelPartASync(eBodyPartS2C, unsigned int) { }

// 0x800C05CC | 212 bytes
void SimModel::FlushLoadingModels(void) { }

// 0x800C0838 | 140 bytes
void SimModel::WeldAllSharedVertices(void) { }

// 0x800C08C4 | 200 bytes
void SimModel::WeldSharedVertices(eBodyPartS2C, eBodyPartS2C, bool) { }

// 0x800C098C | 268 bytes
void SimModel::ApplyAllLatticeMorphing(void) { }

// 0x800C0A98 | 1008 bytes
void SimModel::ApplyLatticeMorphingToModelPart(eBodyPartS2C) { }

// 0x800C0E88 | 900 bytes
void SimModel::ApplyAllMorphTargets(void) { }

// 0x800C120C | 716 bytes
void SimModel::ApplyMorphTargetsToRegion(unsigned int, unsigned int, float, unsigned int *) { }

// 0x800C14D8 | 892 bytes
void SimModel::CreateSkin(char *) { }

// 0x800C1854 | 116 bytes
void SimModel::GetSkinTextureDef(ETextureDef &, bool) { }

// 0x800C18C8 | 68 bytes
void SimModel::ApplySkinToModels(void) { }

// 0x800C190C | 488 bytes
void SimModel::ApplySkinToModelPart(eBodyPartS2C) { }

// 0x800C1AF4 | 68 bytes
void SimModel::TransformAllModelUV(void) { }

// 0x800C1B38 | 144 bytes
void SimModel::TransformModelPartUV(eBodyPartS2C) { }

// 0x800C1BC8 | 1152 bytes
void SimModel::GetModelUVTransformParameters(eBodyPartS2C, EVec2 &, EVec2 &, unsigned int &, EVec2 &, EVec2 &) { }

// 0x800C2048 | 264 bytes
void SimModel::CompositeAllSkin(void) { }

// 0x800C2150 | 328 bytes
void SimModel::CompositeSkinPart(unsigned char) { }

// 0x800C2298 | 200 bytes
void SimModel::UpdateReweld(bool) { }

// 0x800C2360 | 88 bytes
void SimModel::UpdateReweldCAS(bool) { }

// 0x800C23B8 | 156 bytes
void SimModel::UpdateSimDescriptionIndices(unsigned int *) { }

// 0x800C2454 | 136 bytes
void SimModel::RebuildModified(void) { }

// 0x800C24DC | 372 bytes
void SimModel::LoadAllMorphTargets(void) { }

// 0x800C2650 | 100 bytes
void SimModel::GetGameStateModelID(unsigned int, bool) { }

// 0x800C26B4 | 100 bytes
void SimModel::GetGameStateTextureID(unsigned int, bool) { }

// 0x800C2738 | 228 bytes
void SimModel::UpdateInnerLayerTorso(bool, bool, bool) { }

// 0x800C281C | 212 bytes
void SimModel::UpdateInnerLayerSleeve(bool, bool, bool) { }

// 0x800C28F0 | 216 bytes
void SimModel::UpdateMidLayerTorso(bool, bool, bool, bool) { }

// 0x800C29C8 | 264 bytes
void SimModel::UpdateMidLayerSleeve(bool, bool, bool, bool) { }

// 0x800C2AD0 | 152 bytes
void SimModel::UpdateMidLayerCollar(bool) { }

// 0x800C2B68 | 340 bytes
void SimModel::UpdateOuterLayerTorso(bool, bool, bool, bool) { }

// 0x800C2CBC | 224 bytes
void SimModel::UpdateOuterLayerSleeve(bool, bool, bool, bool) { }

// 0x800C2D9C | 168 bytes
void SimModel::UpdateOuterLayerCollar(bool, bool) { }

// 0x800C2E44 | 208 bytes
void SimModel::UpdateLowerBody(bool, bool) { }

// 0x800C2F14 | 548 bytes
void SimModel::UpdateHair(bool, bool, bool) { }

// 0x800C3138 | 172 bytes
void SimModel::UpdateHead(bool, bool, bool) { }

// 0x800C31E4 | 164 bytes
void SimModel::UpdateHat(bool, bool, bool) { }

// 0x800C3288 | 324 bytes
void SimModel::UpdateArmAccessory(bool, bool, bool) { }

// 0x800C33CC | 216 bytes
void SimModel::UpdateVestScarf(bool, bool, bool) { }

// 0x800C34A4 | 164 bytes
void SimModel::UpdateNecklaceEarring(bool, bool, bool) { }

// 0x800C3548 | 620 bytes
void SimModel::UpdateBelt(bool, bool, bool) { }

// 0x800C37B4 | 216 bytes
void SimModel::UpdateShoes(bool, bool, bool) { }

// 0x800C388C | 144 bytes
void SimModel::UpdateFacialFeature(bool, bool, bool) { }

// 0x800C391C | 144 bytes
void SimModel::UpdateGlasses(bool, bool, bool) { }

// 0x800C39AC | 108 bytes
void SimModel::GetModelName(eBodyPartS2C, EString &) { }

// 0x800C3A18 | 176 bytes
void SimModel::GetTextureName(eBodyPartS2C, EString &) { }

// 0x800C3AC8 | 188 bytes
void SimModel::GetTattooTextureName(eTattooTextureTypeS2C, EString &) { }
