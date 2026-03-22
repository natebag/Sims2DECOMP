// esubmodelshader_stubs.cpp - Stub implementations for Esubmodelshader
// Auto-generated from symbols.json - 43 functions
// These are stub implementations to register progress.
// Each function needs proper decompilation to match the original binary.

#include "types.h"

// 0x804A2714 | 56 bytes
void ESubModelShader::VertexDataAllocation(int, char *, int, char *) { }

// 0x804A274C | 64 bytes
void ESubModelShader::VertexDataDeallocation(void *, bool) { }

// 0x804A278C | 40 bytes
void ESubModelShader::MorphDataAllocation(int, int) { }

// 0x804A27B4 | 40 bytes
void ESubModelShader::MorphDataDeallocation(void *) { }

// 0x804A27DC | 124 bytes
ESubModelShader::ESubModelShader(void) { }

// 0x804A2858 | 88 bytes
ESubModelShader::~ESubModelShader(void) { }

// 0x804A28B0 | 64 bytes
void ESubModelShader::DelRefSubResources(void) { }

// 0x804A28F0 | 76 bytes
void ESubModelShader::AddRefSubResources(void) { }

// 0x804A293C | 76 bytes
void ESubModelShader::TryIncrementSubResources(void) { }

// 0x804A2988 | 208 bytes
void ESubModelShader::DeallocateStripData(ESMSStrip *) { }

// 0x804A2A58 | 204 bytes
void ESubModelShader::Deallocate(void) { }

// 0x804A2B24 | 112 bytes
void ESubModelShader::FreeStripResource(void) { }

// 0x804A2B94 | 156 bytes
void ESubModelShader::FreeMorphStripResource(void) { }

// 0x804A2C30 | 164 bytes
void ESubModelShader::FreeMorphResource(void) { }

// 0x804A2CD4 | 292 bytes
void ESubModelShader::CreateRCPrimitive(unsigned int, ERC *, ESMSStrip *, bool, bool, bool) { }

// 0x804A2DF8 | 316 bytes
void ESubModelShader::ReadPositions(unsigned char *, ESMSStrip *, bool) { }

// 0x804A2F34 | 172 bytes
void ESubModelShader::ReadTexcoords(unsigned char *, ESMSStrip *) { }

// 0x804A2FE0 | 192 bytes
void ESubModelShader::ReadColors(unsigned char *, ESMSStrip *) { }

// 0x804A30A0 | 248 bytes
void ESubModelShader::ReadNormalsOld(unsigned char *, ESMSStrip *) { }

// 0x804A3198 | 180 bytes
void ESubModelShader::ReadNormals(unsigned char *, ESMSStrip *) { }

// 0x804A324C | 420 bytes
void ESubModelShader::ReadWeights(unsigned char *, ESMSStrip *, bool) { }

// 0x804A33F0 | 1692 bytes
void ESubModelShader::OptimizeStripsForMemory(ESubModelShader *, ESMSStrip *, int, bool) { }

// 0x804A3A8C | 304 bytes
void ESubModelShader::ReadIndices(unsigned char *, ESMSStrip *, unsigned int &) { }

// 0x804A3F34 | 4 bytes
void ESubModelShader::DrawNormals(ERC *) { }

// 0x804A3F38 | 4 bytes
void ESubModelShader::DrawWireFrame(ERC *) { }

// 0x804A3F3C | 4 bytes
void ESubModelShader::MorphBreakUpStrip(TArray<ESMSStrip, TArrayERModelAllocator> &, TArray<ESMSStrip, TArrayERModelAllocator> &) { }

// 0x804A3F40 | 216 bytes
void ESubModelShader::AllocateMorph(void) { }

// 0x804A4018 | 184 bytes
void ESubModelShader::RegisterMorphTarget(ESubModelShader *, int) { }

// 0x804A40D0 | 20 bytes
void ESubModelShader::UnRegisterMorphTarget(int) { }

// 0x804A40E4 | 136 bytes
void ESubModelShader::ResetMorph(void) { }

// 0x804A416C | 1244 bytes
void ESubModelShader::ApplyMorph(void) { }

// 0x804A4648 | 332 bytes
void ESubModelShader::GetMorphedVertex(EVec3 &, short, short) { }

// 0x804A4794 | 792 bytes
void ESubModelShader::GenerateMorphTargetDeltas(ESubModelShader *) { }

// 0x804A4AAC | 992 bytes
void ESubModelShader::Morph(float *) { }

// 0x804A4E8C | 604 bytes
void ESubModelShader::CreateLatticeList(TArray<BSplineVolume, TArrayERModelAllocator> *) { }

// 0x804A50E8 | 460 bytes
void ESubModelShader::AllocateParameterizeVerts(void) { }

// 0x804A52B4 | 836 bytes
void ESubModelShader::ParameterizeVerts(TArray<BSplineVolume, TArrayERModelAllocator> *) { }

// 0x804A55F8 | 1048 bytes
void ESubModelShader::LatticeDeform(void) { }

// 0x804A5A10 | 1336 bytes
void ESubModelShader::BuildDisplayList(ESMBuildDisplayListData *) { }

// 0x804A63E0 | 216 bytes
void ESubModelShader::GetMinMaxX(float *, float *) { }

// 0x804A64B8 | 64 bytes
void ESubModelShader::CanColorBeModified(void) { }

// 0x804A64F8 | 52 bytes
void ESubModelShader::GetModifiableColor(unsigned int) { }

// 0x804A652C | 852 bytes
void ESubModelShader::TransformModelUV(EVec2 &, EVec2 &, unsigned int, EVec2 &, EVec2 &, bool) { }
