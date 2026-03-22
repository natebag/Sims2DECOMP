// esim_stubs.cpp - Stub implementations for Esim
// Auto-generated from symbols.json - 73 functions
// These are stub implementations to register progress.
// Each function needs proper decompilation to match the original binary.

#include "types.h"
#include "stub_classes.h"

// 0x8004ABB8 | 1460 bytes
ESim::ESim(cXPerson *) { }

// 0x8004B16C | 596 bytes
ESim::~ESim(void) { }

// 0x8004B3C0 | 152 bytes
void ESim::DeletePlayerCachedModel(void) { }

// 0x8004B458 | 492 bytes
void ESim::ReadModelFromCache(void) { }

// 0x8004B644 | 952 bytes
void ESim::TransferModelToCache(void) { }

// 0x8004B9FC | 36 bytes
void ESim::flushQueuedCostumeModels(void) { }

// 0x8004BA20 | 56 bytes
void ESim::IsMale(void) { }

// 0x8004BA58 | 36 bytes
void ESim::IsFemale(void) { }

// 0x8004BA7C | 56 bytes
void ESim::IsAdult(void) { }

// 0x8004BAB4 | 56 bytes
void ESim::IsChild(void) { }

// 0x8004BAEC | 56 bytes
void ESim::IsDog(void) { }

// 0x8004BB24 | 56 bytes
void ESim::IsCat(void) { }

// 0x8004BB5C | 56 bytes
void ESim::IsMonkey(void) { }

// 0x8004BB94 | 56 bytes
void ESim::IsPet(void) { }

// 0x8004BBCC | 2340 bytes
void ESim::initModel(void) { }

// 0x8004C4F0 | 536 bytes
void ESim::DrawPlumbBob(ERC *) { }

// 0x8004C708 | 916 bytes
void ESim::UpdateSkillMeter(EVec3 &, EVec3 &) { }

// 0x8004CA9C | 1332 bytes
void ESim::DrawSkillMeter(ERC *) { }

// 0x8004CFD0 | 652 bytes
void ESim::SetPlumbBobState(unsigned int) { }

// 0x8004D25C | 340 bytes
void ESim::PropOrderTableCallback(ELevelDrawData &, EOrderTableData *) { }

// 0x8004D3B0 | 380 bytes
void ESim::SimOrderTableCallback(ELevelDrawData &, EOrderTableData *) { }

// 0x8004D52C | 204 bytes
void ESim::CensorOrderTableCallback(ELevelDrawData &, EOrderTableData *) { }

// 0x8004D6BC | 60 bytes
void ESim::DrawSimModel(ERC *, EMat4 *, unsigned int) { }

// 0x8004D6F8 | 280 bytes
void ESim::ServiceNpcOrderTableCallback(ELevelDrawData &, EOrderTableData *) { }

// 0x8004D810 | 384 bytes
void ESim::DrawSimAndNpcCommonItems(ERC *) { }

// 0x8004D990 | 156 bytes
void ESim::SkillMeterOrderTableCallback(ELevelDrawData &, EOrderTableData *) { }

// 0x8004DA2C | 744 bytes
void ESim::DrawCursorHighLight(ERC *) { }

// 0x8004DD14 | 68 bytes
void ESim::DoAnimation(void) { }

// 0x8004DD58 | 4 bytes
void ESim::DoLightingCalculation(void) { }

// 0x8004DD5C | 3064 bytes
void ESim::Draw(ELevelDrawData &) { }

// 0x8004E954 | 784 bytes
void ESim::Update(void) { }

// 0x8004EC64 | 228 bytes
void ESim::VisibilityTest(E3DWindow &) { }

// 0x8004ED48 | 152 bytes
void ESim::SetAnim(char *) { }

// 0x8004EDE0 | 332 bytes
void ESim::UpdateShowerCurtain(void) { }

// 0x8004EF2C | 1012 bytes
void ESim::UpdateSkinChange(void) { }

// 0x8004F320 | 224 bytes
void ESim::CreateSkinAsync(void) { }

// 0x8004F400 | 116 bytes
void ESim::CompositeSkin(void) { }

// 0x8004F474 | 212 bytes
void ESim::CreateThumbnail(void) { }

// 0x8004F548 | 156 bytes
void ESim::UpdateRepShaders(int) { }

// 0x8004F5E4 | 192 bytes
void ESim::RefreshSkin(void) { }

// 0x8004F6A4 | 132 bytes
void ESim::tProcessCommand(unsigned int) { }

// 0x8004F728 | 124 bytes
void ESim::HasQueuedOperation(void) { }

// 0x8004F7A4 | 152 bytes
void ESim::UpdateQueuedOperation(void) { }

// 0x8004F83C | 152 bytes
void ESim::GetScaler(void) { }

// 0x8004F8D4 | 92 bytes
void ESim::DrawSim(bool) { }

// 0x8004F930 | 272 bytes
void ESim::GetObCenter(void) { }

// 0x8004FA40 | 56 bytes
void ESim::GetPlayerIndex(void) { }

// 0x8004FA78 | 36 bytes
void ESim::UpdatePlumbBob(void) { }

// 0x8004FA9C | 296 bytes
void ESim::UpdateShadow(void) { }

// 0x8004FBC4 | 436 bytes
void ESim::UpdateGhostParticleEffect(void) { }

// 0x8004FD78 | 104 bytes
void ESim::ChangeCostume(void) { }

// 0x80051594 | 84 bytes
void ESim::New(void) { }

// 0x800515E8 | 32 bytes
void ESim::Construct(ESim *) { }

// 0x80051608 | 36 bytes
void ESim::Destruct(ESim *) { }

// 0x8005162C | 64 bytes
void ESim::SafeDelete(void) { }

// 0x80051678 | 12 bytes
void ESim::GetTypeName(void) const { }

// 0x80051684 | 12 bytes
void ESim::GetTypeKey(void) const { }

// 0x80051690 | 12 bytes
void ESim::GetTypeVersion(void) const { }

// 0x800516A8 | 12 bytes
void ESim::GetReadVersion(void) { }

// 0x800516B4 | 84 bytes
void ESim::RegisterType(unsigned short) { }

// 0x80051708 | 32 bytes
void ESim::CreateCopy(void) const { }

// 0x80051884 | 84 bytes
void ESim::SetXOb(cXObject *) { }

// 0x800518D8 | 8 bytes
void ESim::GetShadow(void) { }

// 0x800518E0 | 8 bytes
void ESim::GetPerson(void) { }

// 0x800518E8 | 20 bytes
void ESim::GetModelPart(int) { }

// 0x800518FC | 8 bytes
void ESim::GetSimHead(void) { }

// 0x80051904 | 8 bytes
void ESim::GetSimModel(void) { }

// 0x8005190C | 12 bytes
void ESim::SetVanityDraw(bool, unsigned int) { }

// 0x80051918 | 16 bytes
void ESim::UseVanityDraw(unsigned int *) { }

// 0x80051928 | 8 bytes
void ESim::GetPlumbBobState(void) { }

// 0x80051930 | 8 bytes
void ESim::SetSkillmeterValue(float) { }

// 0x80051938 | 8 bytes
void ESim::GetIsModelLoaded(void) { }

// 0x80051940 | 8 bytes
void ESim::GetIsChangingOutfit(void) { }
