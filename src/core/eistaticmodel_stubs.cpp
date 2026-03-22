// eistaticmodel_stubs.cpp - Stub implementations for Eistaticmodel
// Auto-generated from symbols.json - 39 functions
// These are stub implementations to register progress.
// Each function needs proper decompilation to match the original binary.

#include "types.h"
#include "stub_classes.h"

// 0x80392F20 | 176 bytes
EIStaticModel::EIStaticModel(void) { }

// 0x80392FD0 | 92 bytes
EIStaticModel::~EIStaticModel(void) { }

// 0x8039302C | 100 bytes
void EIStaticModel::Write(EStream &) { }

// 0x80393148 | 40 bytes
void EIStaticModel::GetBoundSphere(EBoundSphere &) { }

// 0x80393170 | 448 bytes
void EIStaticModel::Setup(EInstance *, EAnimController *) { }

// 0x80393330 | 148 bytes
void EIStaticModel::DeallocateModel(void) { }

// 0x803933C4 | 60 bytes
void EIStaticModel::SetModel(unsigned int, bool, EInstance *, EAnimController *) { }

// 0x80393448 | 364 bytes
void EIStaticModel::SetOrient(EMat4 &) { }

// 0x803935B4 | 268 bytes
void EIStaticModel::SlamOrient(EMat4 &, EMat4 &) { }

// 0x80393748 | 732 bytes
void EIStaticModel::RegisterFloor(void) { }

// 0x80393A24 | 356 bytes
void EIStaticModel::SetupModel(EInstance *, EAnimController *) { }

// 0x80393B88 | 732 bytes
void EIStaticModel::BuildDigests(void) { }

// 0x80393E64 | 480 bytes
void EIStaticModel::SetupBounds(void) { }

// 0x80394044 | 44 bytes
void EIStaticModel::VisibilityTest(E3DWindow &) { }

// 0x80394070 | 1160 bytes
void EIStaticModel::Draw(ELevelDrawData &) { }

// 0x803944F8 | 504 bytes
void EIStaticModel::DrawAsShadow(ELevelDrawData &) { }

// 0x803946F0 | 624 bytes
void EIStaticModel::DrawShadow(ELevelDrawData &) { }

// 0x80394960 | 396 bytes
void EIStaticModel::AnimOrderTableCallback(ELevelDrawData &, EOrderTableData *) { }

// 0x80394AEC | 376 bytes
void EIStaticModel::ChangeShader(unsigned int, unsigned int) { }

// 0x80394C64 | 236 bytes
void EIStaticModel::ChangeShaderState(unsigned int) { }

// 0x80394D50 | 276 bytes
void EIStaticModel::UpdateShaders(void) { }

// 0x80394E64 | 140 bytes
void EIStaticModel::RebuildShaders(void) { }

// 0x80394EF0 | 100 bytes
void EIStaticModel::RealizeShaderTuning(void) { }

// 0x80394F54 | 268 bytes
void EIStaticModel::FindShaderContainingTexture(unsigned int) { }

// 0x80395060 | 292 bytes
void EIStaticModel::FindShaderSupportingDecal(void) { }

// 0x80395184 | 1164 bytes
void EIStaticModel::ReplaceBaseTexture(ERTexture *, unsigned int, ERTexture *) { }

// 0x80395610 | 544 bytes
void EIStaticModel::Clone(void) { }

// 0x80395830 | 52 bytes
void EIStaticModel::HasModifiableColor(void) { }

// 0x803958DC | 732 bytes
void EIStaticModel::DrawImmediate(ERC *, EAnimController *) { }

// 0x80395BB8 | 976 bytes
void EIStaticModel::DrawImmediateGhosted(ERC *, EAnimController *) { }

// 0x80395F88 | 416 bytes
void EIStaticModel::TagAsGrabbed(void) { }

// 0x80396128 | 40 bytes
void EIStaticModel::GetInstName(int &) { }

// 0x80397374 | 40 bytes
void EIStaticModel::New(void) { }

// 0x8039739C | 44 bytes
void EIStaticModel::Construct(EIStaticModel *) { }

// 0x803973EC | 64 bytes
void EIStaticModel::SafeDelete(void) { }

// 0x80397474 | 84 bytes
void EIStaticModel::RegisterType(unsigned short) { }

// 0x80397530 | 52 bytes
void EIStaticModel::operator delete(void *) { }

// 0x80397584 | 36 bytes
void EIStaticModel::IsSkydome(void) const { }

// 0x803975A8 | 136 bytes
void EIStaticModel::GetAnchorPos(EMat4 &, int) { }
