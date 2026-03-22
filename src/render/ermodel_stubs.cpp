// ermodel_stubs.cpp - Stub implementations for Ermodel
// Auto-generated from symbols.json - 82 functions
// These are stub implementations to register progress.
// Each function needs proper decompilation to match the original binary.

#include "types.h"

// 0x804E1AC8 | 552 bytes
ERModel::ERModel(void) { }

// 0x804E1CF0 | 224 bytes
ERModel::~ERModel(void) { }

// 0x804E1DD0 | 40 bytes
void ERModel::Refresh(EFile *) { }

// 0x804E1DF8 | 100 bytes
void ERModel::DelRefSubResources(void) { }

// 0x804E1E5C | 100 bytes
void ERModel::AddRefSubResources(void) { }

// 0x804E1EC0 | 156 bytes
void ERModel::TryIncrementSubResources(void) { }

// 0x804E1F5C | 164 bytes
void ERModel::ReadAttachmentVert(char *) { }

// 0x804E2000 | 1056 bytes
void ERModel::LoadModel(EFile *) { }

// 0x804E2420 | 272 bytes
void ERModel::FinishLoad(char) { }

// 0x804E2530 | 52 bytes
void ERModel::GetShaderCount(void) { }

// 0x804E2564 | 128 bytes
void ERModel::GetScaleMatrix(void) { }

// 0x804E25E4 | 72 bytes
void ERModel::DeallocateScaleMatrix(void) { }

// 0x804E262C | 220 bytes
void ERModel::CalcOrientedBoundSphere(EMat4 &, EBoundSphere &) { }

// 0x804E2708 | 108 bytes
void ERModel::DrawGeometry(ERC *) { }

// 0x804E2774 | 108 bytes
void ERModel::DrawAsShadow(ERC *) { }

// 0x804E27E0 | 108 bytes
void ERModel::DrawNormals(ERC *) { }

// 0x804E284C | 108 bytes
void ERModel::DrawWireFrame(ERC *) { }

// 0x804E28B8 | 8 bytes
void ERModel::GetLatticeCount(void) { }

// 0x804E28C0 | 8 bytes
void ERModel::GetDummyCount(void) { }

// 0x804E28C8 | 8 bytes
void ERModel::GetCameraCount(void) { }

// 0x804E28D0 | 108 bytes
void ERModel::Draw(ERC *) { }

// 0x804E293C | 544 bytes
void ERModel::DrawShadow(ERC *, float) { }

// 0x804E2B5C | 524 bytes
void ERModel::DrawShadowWithStencilInverted(ERC *) { }

// 0x804E2D68 | 612 bytes
void ERModel::DrawHierarchical(ERC *, EMat4 *, EACNodeState *, int) { }

// 0x804E2FCC | 172 bytes
void ERModel::GetWeldPos(EWeldVert *) { }

// 0x804E3078 | 144 bytes
void ERModel::SetWeldPos(EWeldVert *, EVec3 &) { }

// 0x804E3108 | 2868 bytes
void ERModel::WeldSharedVerts(ERModel *, float) { }

// 0x804E3C3C | 4 bytes
void ERModel::RebuildAfterWelding(void) { }

// 0x804E3C40 | 128 bytes
void ERModel::GenerateMorphTargetDeltas(ERModel *) { }

// 0x804E3CC0 | 200 bytes
void ERModel::RegisterMorphTarget(ERModel *, int) { }

// 0x804E3DF8 | 200 bytes
void ERModel::UnRegisterMorphTarget(int) { }

// 0x804E3F2C | 56 bytes
void ERModel::SetMorphTargetWeight(int, float) { }

// 0x804E3F64 | 112 bytes
void ERModel::ResetMorph(void) { }

// 0x804E3FD4 | 136 bytes
void ERModel::MorphTargets(void) { }

// 0x804E405C | 168 bytes
void ERModel::MorphLattices(void) { }

// 0x804E4104 | 120 bytes
void ERModel::ApplyMorph(void) { }

// 0x804E417C | 88 bytes
void ERModel::CleanMorphTargets(bool) { }

// 0x804E41D4 | 60 bytes
void ERModel::FreeAllMorphAndLatticeResource(bool) { }

// 0x804E4210 | 100 bytes
void ERModel::FreeStripResource(void) { }

// 0x804E4274 | 100 bytes
void ERModel::FreeMorphStripResource(void) { }

// 0x804E42D8 | 76 bytes
void ERModel::SetLatticeWeight(int, int, float) { }

// 0x804E4324 | 144 bytes
void ERModel::ResetLatticeWeights(void) { }

// 0x804E43B4 | 44 bytes
void ERModel::GetNumMorphLattice(int) { }

// 0x804E43E0 | 8 bytes
void ERModel::GetNumMorphBases(void) { }

// 0x804E43E8 | 104 bytes
void ERModel::ParameterizeVerts(void) { }

// 0x804E4450 | 100 bytes
void ERModel::FreeMorphResource(void) { }

// 0x804E44B4 | 120 bytes
void ERModel::HasModifiableColor(void) { }

// 0x804E452C | 136 bytes
void ERModel::GetModifiableColor(unsigned int) { }

// 0x804E45B4 | 80 bytes
void ERModel::GetAttachmentID(unsigned char, signed char &) { }

// 0x804E4604 | 116 bytes
void ERModel::DrawAttachment(ERC *, ERModel *, EMat4 *, int, float) { }

// 0x804E4678 | 164 bytes
void ERModel::GetAttachmentMatrix(EMat4 &, ERModel *, EMat4 *, int, float) { }

// 0x804E4E78 | 164 bytes
void ERModel::TransformModelUV(EVec2 &, EVec2 &, unsigned int, EVec2 &, EVec2 &) { }

// 0x804E7610 | 40 bytes
void ERModel::New(void) { }

// 0x804E7638 | 44 bytes
void ERModel::Construct(ERModel *) { }

// 0x804E7664 | 36 bytes
void ERModel::Destruct(ERModel *) { }

// 0x804E7688 | 64 bytes
void ERModel::SafeDelete(void) { }

// 0x804E76D4 | 12 bytes
void ERModel::GetTypeName(void) const { }

// 0x804E76E0 | 12 bytes
void ERModel::GetTypeKey(void) const { }

// 0x804E76EC | 12 bytes
void ERModel::GetTypeVersion(void) const { }

// 0x804E7704 | 12 bytes
void ERModel::GetReadVersion(void) { }

// 0x804E7710 | 84 bytes
void ERModel::RegisterType(unsigned short) { }

// 0x804E7764 | 32 bytes
void ERModel::CreateCopy(void) const { }

// 0x804E7784 | 48 bytes
void* ERModel::operator new(unsigned int) { }

// 0x804E77BC | 44 bytes
void ERModel::operator delete(void *) { }

// 0x804E77E8 | 52 bytes
void ERModel::CalcOrientedBoundBox(EMat4 &, EBound3 &) { }

// 0x804E781C | 16 bytes
void ERModel::GetLattice(int) { }

// 0x804E782C | 16 bytes
void ERModel::GetDummy(int) { }

// 0x804E783C | 16 bytes
void ERModel::GetCamera(int) { }

// 0x804E784C | 8 bytes
void ERModel::IsHierarchical(void) { }

// 0x804E7854 | 8 bytes
void ERModel::IsWeldable(void) { }

// 0x804E785C | 8 bytes
void ERModel::IsMorphTarget(void) { }

// 0x804E7864 | 8 bytes
void ERModel::IsLattice(void) { }

// 0x804E786C | 8 bytes
void ERModel::AreMatsInDLs(void) { }

// 0x804E7874 | 8 bytes
void ERModel::DontFrontPlaneFade(void) { }

// 0x804E787C | 8 bytes
void ERModel::DontInterestFade(void) { }

// 0x804E7884 | 8 bytes
void ERModel::DontCull(void) { }

// 0x804E788C | 8 bytes
void ERModel::IsWall(void) { }

// 0x804E7894 | 8 bytes
void ERModel::GetAttachmentColor(void) { }

// 0x804E789C | 12 bytes
void ERModel::ClearAttachmentID(void) { }

// 0x804E78A8 | 8 bytes
void ERModel::GetNumAttachmentVerts(void) { }

// 0x804E78B0 | 8 bytes
void ERModel::GetNumLightPos(void) { }

// 0x804E78B8 | 8 bytes
void ERModel::GetLightPos(void) { }
