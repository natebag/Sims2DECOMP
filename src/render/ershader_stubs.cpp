// ershader_stubs.cpp - Stub implementations for Ershader
// Auto-generated from symbols.json - 66 functions
// These are stub implementations to register progress.
// Each function needs proper decompilation to match the original binary.

#include "types.h"
#include "stub_classes.h"

// 0x804E8D60 | 212 bytes
ERShader::ERShader(void) { }

// 0x804E8E34 | 124 bytes
ERShader::~ERShader(void) { }

// 0x804E8EB0 | 256 bytes
void ERShader::Deallocate(void) { }

// 0x804E8FB0 | 340 bytes
void ERShader::DelRefSubResources(void) { }

// 0x804E9104 | 160 bytes
void ERShader::DeallocateIncomingShader(void) { }

// 0x804E91A4 | 728 bytes
void ERShader::AddRefSubResources(void) { }

// 0x804E947C | 1056 bytes
void ERShader::TryIncrementSubResources(void) { }

// 0x804E989C | 776 bytes
void ERShader::CreateEShaderForTexture(ETexture *) { }

// 0x804E9BA4 | 64 bytes
void ERShader::Refresh(EFile *) { }

// 0x804E9BE4 | 548 bytes
void ERShader::Load(EFile &) { }

// 0x804E9E08 | 1492 bytes
void ERShader::Clone(unsigned int) { }

// 0x804EA3DC | 8 bytes
void ERShader::SetDefaultShaderState(int) { }

// 0x804EA3E4 | 780 bytes
void ERShader::DoLoadMultiShader(char *, EShaderDef &) { }

// 0x804EA6F0 | 208 bytes
void ERShader::SetCurrentShaderForState(unsigned char) { }

// 0x804EA7C0 | 180 bytes
void ERShader::ChangeCurrentShader(ERShader *) { }

// 0x804EA874 | 120 bytes
void ERShader::GetMultiShaderStateID(int) { }

// 0x804EA8EC | 224 bytes
void ERShader::SetShaderASyncForState(int) { }

// 0x804EA9CC | 1484 bytes
void ERShader::DoLoad(EFile &, EShaderDef &) { }

// 0x804EAF98 | 1664 bytes
void ERShader::OldLoad(EFile &, EShaderDef &) { }

// 0x804EB618 | 304 bytes
void ERShader::CopyShedData(EShaderDef &, char *) { }

// 0x804EB748 | 228 bytes
void ERShader::CopyIntermediateShedData(EShaderDef &, char *) { }

// 0x804EB82C | 196 bytes
void ERShader::AddToUpdateList(void) { }

// 0x804EB8F0 | 220 bytes
void ERShader::RemoveFromUpdateList(void) { }

// 0x804EB9CC | 748 bytes
void ERShader::Update(float, int, int, int) { }

// 0x804EBCB8 | 304 bytes
void ERShader::HasCommonTexture(ERShader *, ERShader *) { }

// 0x804EBDE8 | 32 bytes
void ERShader::UpdateWeatherShader(int) { }

// 0x804EBE08 | 68 bytes
void ERShader::UpdateTimeOfDayShader(void) { }

// 0x804EBE4C | 160 bytes
void ERShader::InterpolateShaders(float) { }

// 0x804EBEEC | 1220 bytes
void ERShader::BlendCurrentShader(float) { }

// 0x804EC3B0 | 712 bytes
void ERShader::UpdateAll(float, int, int, int) { }

// 0x804EC678 | 676 bytes
void ERShader::InitDayNightShaders(int, int) { }

// 0x804EC91C | 160 bytes
void ERShader::SetDayNightShaderToClosestTime(int, int) { }

// 0x804EC9BC | 272 bytes
void ERShader::ReplaceTexture(ERTexture *, int) { }

// 0x804ECACC | 252 bytes
void ERShader::SwapTexture(ERTexture *, int) { }

// 0x804ECBC8 | 192 bytes
void ERShader::HasTexture(unsigned int) { }

// 0x804ED57C | 40 bytes
void ERShader::New(void) { }

// 0x804ED5A4 | 44 bytes
void ERShader::Construct(ERShader *) { }

// 0x804ED5D0 | 36 bytes
void ERShader::Destruct(ERShader *) { }

// 0x804ED5F4 | 64 bytes
void ERShader::SafeDelete(void) { }

// 0x804ED640 | 12 bytes
void ERShader::GetTypeName(void) const { }

// 0x804ED64C | 12 bytes
void ERShader::GetTypeKey(void) const { }

// 0x804ED658 | 12 bytes
void ERShader::GetTypeVersion(void) const { }

// 0x804ED670 | 12 bytes
void ERShader::GetReadVersion(void) { }

// 0x804ED67C | 84 bytes
void ERShader::RegisterType(unsigned short) { }

// 0x804ED6D0 | 32 bytes
void ERShader::CreateCopy(void) const { }

// 0x804ED6F0 | 48 bytes
void* ERShader::operator new(unsigned int) { }

// 0x804ED728 | 44 bytes
void ERShader::operator delete(void *) { }

// 0x804ED754 | 44 bytes
void ERShader::GetShader(void) { }

// 0x804ED780 | 136 bytes
void ERShader::SetSupportDecal(bool) { }

// 0x804ED808 | 72 bytes
void ERShader::GetSupportDecal(void) { }

// 0x804ED850 | 12 bytes
void ERShader::IsDayNightShader(void) { }

// 0x804ED85C | 16 bytes
void ERShader::GetRTextureForRenderPass(int) { }

// 0x804ED86C | 60 bytes
void ERShader::GetCurrentShader(void) { }

// 0x804ED8A8 | 20 bytes
void ERShader::SupportsMultiShaderStates(void) { }

// 0x804ED8BC | 60 bytes
void ERShader::GetStateCount(void) { }

// 0x804ED8F8 | 84 bytes
void ERShader::GetState(unsigned int) { }

// 0x804ED94C | 8 bytes
void ERShader::GetCurrentGraphicsState(void) { }

// 0x804ED954 | 12 bytes
void ERShader::IsStateChangePending(void) { }

// 0x804ED960 | 12 bytes
void ERShader::IsMultiShader(void) const { }

// 0x804ED96C | 72 bytes
void ERShader::IsMultiTextureShader(void) { }

// 0x804ED9B4 | 40 bytes
void ERShader::DetachClone(void) { }

// 0x804ED9DC | 40 bytes
void ERShader::GetTimeState(void) { }

// 0x804EDA04 | 96 bytes
void ERShader::Select(ERC *, unsigned int) { }

// 0x804EDA64 | 96 bytes
void ERShader::SelectForShadowMask(ERC *) { }

// 0x804EDAC4 | 60 bytes
void ERShader::CanColorBeModified(void) { }

// 0x804EDB00 | 48 bytes
void ERShader::GetModifiableColor(unsigned int) { }
