// esubmodel_stubs.cpp - Stub implementations for Esubmodel
// Auto-generated from symbols.json - 27 functions
// These are stub implementations to register progress.
// Each function needs proper decompilation to match the original binary.

#include "types.h"

// 0x804A0978 | 56 bytes
ESubModel::ESubModel(void) { }

// 0x804A09B0 | 76 bytes
ESubModel::~ESubModel(void) { }

// 0x804A09FC | 92 bytes
void ESubModel::DelRefSubResources(void) { }

// 0x804A0A58 | 92 bytes
void ESubModel::AddRefSubResources(void) { }

// 0x804A0AB4 | 148 bytes
void ESubModel::TryIncrementSubResources(void) { }

// 0x804A0B48 | 8 bytes
void ESubModel::GetCompositeShaderFlags(void) { }

// 0x804A0C48 | 228 bytes
void ESubModel::Draw(ERC *) { }

// 0x804A0D2C | 152 bytes
void ESubModel::DrawGeometry(ERC *) { }

// 0x804A0DC4 | 224 bytes
void ESubModel::DrawAsShadow(ERC *) { }

// 0x804A0EA4 | 100 bytes
void ESubModel::DrawNormals(ERC *) { }

// 0x804A0F08 | 100 bytes
void ESubModel::DrawWireFrame(ERC *) { }

// 0x804A0F6C | 148 bytes
void ESubModel::BuildDisplayList(bool, char *, bool, float, float) { }

// 0x804A1064 | 108 bytes
void ESubModel::GetMinMaxX(float *, float *) { }

// 0x804A10D0 | 96 bytes
void ESubModel::ApplyMorph(void) { }

// 0x804A1130 | 92 bytes
void ESubModel::ResetMorph(void) { }

// 0x804A118C | 104 bytes
void ESubModel::Morph(float *) { }

// 0x804A11F4 | 92 bytes
void ESubModel::LatticeDeform(void) { }

// 0x804A1250 | 116 bytes
void ESubModel::RegisterMorphTarget(ESubModel *, int) { }

// 0x804A12C4 | 100 bytes
void ESubModel::UnRegisterMorphTarget(int) { }

// 0x804A1328 | 120 bytes
void ESubModel::GenerateMorphTargetDeltas(ESubModel *) { }

// 0x804A13A0 | 100 bytes
void ESubModel::ParameterizeVerts(TArray<BSplineVolume, TArrayERModelAllocator> *) { }

// 0x804A1404 | 92 bytes
void ESubModel::FreeMorphResource(void) { }

// 0x804A1460 | 92 bytes
void ESubModel::FreeStripResource(void) { }

// 0x804A14BC | 92 bytes
void ESubModel::FreeMorphStripResource(void) { }

// 0x804A1518 | 112 bytes
void ESubModel::HasModifiableColor(void) { }

// 0x804A1588 | 128 bytes
void ESubModel::GetModifiableColor(unsigned int) { }

// 0x804A1608 | 140 bytes
void ESubModel::TransformModelUV(EVec2 &, EVec2 &, unsigned int, EVec2 &, EVec2 &, bool) { }
