#if 0 // SKIP
// eyetoyclient_stubs.cpp - Stub implementations for Eyetoyclient
// Auto-generated from symbols.json - 85 functions
// These are stub implementations to register progress.
// Each function needs proper decompilation to match the original binary.

#include "types.h"
#include "stub_classes.h"

// 0x800571B0 | 172 bytes
void EyeToyClient::saveHeader(int &) { }

// 0x8005725C | 244 bytes
void EyeToyClient::saveTexture(int, int &) { }

// 0x80057350 | 240 bytes
void EyeToyClient::Save(int, int &) { }

// 0x80057440 | 4 bytes
void EyeToyClient::SaveComplete(int, int &) { }

// 0x80057444 | 180 bytes
void EyeToyClient::loadHeader(int &) { }

// 0x800574F8 | 8 bytes
void EyeToyClient::loadTexture_alloc(unsigned int, unsigned int) { }

// 0x80057500 | 4 bytes
void EyeToyClient::loadTexture_dealloc(void *) { }

// 0x80057624 | 240 bytes
void EyeToyClient::Load(int, int &) { }

// 0x80057714 | 76 bytes
void EyeToyClient::LoadDefaultSettings(void) { }

// 0x80057760 | 128 bytes
void EyeToyClient::FrameReadyCallback(char *, int) { }

// 0x800577E0 | 96 bytes
void EyeToyClient::FindFirstConnectedEyeToy(void) { }

// 0x80057840 | 212 bytes
void EyeToyClient::AcquireTexture(int, int, int) { }

// 0x80057914 | 64 bytes
void EyeToyClient::ReleaseTexture(ETexture *) { }

// 0x80057954 | 304 bytes
void EyeToyClient::AcquireRenderSurface(int, int, int) { }

// 0x80057A84 | 64 bytes
void EyeToyClient::ReleaseRenderSurface(ERenderSurface *) { }

// 0x80057AC4 | 1020 bytes
void EyeToyClient::CopyTextureToShader(ERShader *, ETexture *) { }

// 0x80057EC0 | 1220 bytes
void EyeToyClient::CompositeFF_callback(ETexture *) { }

// 0x80058384 | 124 bytes
void EyeToyClient::UpdateFunFrameLoading(void) { }

// 0x80058400 | 900 bytes
void EyeToyClient::SetFilterPipeline(int) { }

// 0x80058784 | 8 bytes
void EyeToyClient::SetUnplugCallback(void (*)(int)) { }

// 0x8005878C | 48 bytes
void EyeToyClient::UnpluggedCallback(int) { }

// 0x800587BC | 404 bytes
void EyeToyClient::Init(void) { }

// 0x80058950 | 284 bytes
void EyeToyClient::Shutdown(void) { }

// 0x80058A6C | 164 bytes
void EyeToyClient::Update(float) { }

// 0x80058B10 | 8 bytes
void EyeToyClient::MacroBlockDummyAllocator(unsigned int, unsigned int) { }

// 0x80058B18 | 4 bytes
void EyeToyClient::MacroBlockDummyFree(void *) { }

// 0x80058B1C | 1496 bytes
void EyeToyClient::Render(void) { }

// 0x800590F4 | 8 bytes
void EyeToyClient::GetFunframeCount(void) { }

// 0x800590FC | 8 bytes
void EyeToyClient::GetFilterCount(void) { }

// 0x80059104 | 8 bytes
void EyeToyClient::GetTargetSlotCount(void) { }

// 0x8005910C | 608 bytes
void EyeToyClient::OpenSession(void) { }

// 0x8005936C | 180 bytes
void EyeToyClient::CloseSession(void) { }

// 0x80059420 | 132 bytes
void EyeToyClient::ApplyPresetFilter(int) { }

// 0x800594A4 | 124 bytes
void EyeToyClient::ApplyFunFrame(int) { }

// 0x80059520 | 212 bytes
void EyeToyClient::WriteTextureToRepSlot(int, ETexture *, int) { }

// 0x800595F4 | 84 bytes
void EyeToyClient::SaveSessionToSlot(int) { }

// 0x80059648 | 8 bytes
void EyeToyClient::GetSessionTexture(void) { }

// 0x80059650 | 52 bytes
void EyeToyClient::StartStream(void) { }

// 0x80059684 | 52 bytes
void EyeToyClient::StopStream(void) { }

// 0x800596B8 | 48 bytes
void EyeToyClient::IsEyeToyHardwarePresent(void) { }

// 0x800596E8 | 52 bytes
void EyeToyClient::IsSessionEyeToyDisconnected(void) { }

// 0x8005971C | 384 bytes
void EyeToyClient::GetRepSlotUnLockedBits(int) { }

// 0x8005989C | 124 bytes
void EyeToyClient::GetFunFrameUnLockedBits(int) { }

// 0x80059918 | 136 bytes
void EyeToyClient::DoesRepSlotHaveEyetoyImage(int) { }

// 0x800599A0 | 124 bytes
void EyeToyClient::GetRepShaderGUID(int) { }

// 0x80059A1C | 140 bytes
void EyeToyClient::IsSlotOpenForCASImage(int, int) { }

// 0x80059AA8 | 36 bytes
void EyeToyClient::SetRepTexture(int, ETexture *) { }

// 0x80059ACC | 192 bytes
void EyeToyClient::GetRepTexture(int) { }

// 0x80059B8C | 136 bytes
void EyeToyClient::GetRepShaderERTextureID(int) { }

// 0x80059C14 | 48 bytes
void EyeToyClient::RestoreDefaults(void) { }

// 0x80059C44 | 84 bytes
void EyeToyClient::GetExposure(void) { }

// 0x80059C98 | 104 bytes
void EyeToyClient::SetExposure(float) { }

// 0x80059D00 | 24 bytes
void EyeToyClient::GetSaturation(void) { }

// 0x80059D18 | 160 bytes
void EyeToyClient::SetSaturation(float) { }

// 0x80059DB8 | 56 bytes
void EyeToyClient::GetHue(void) { }

// 0x80059DF0 | 240 bytes
void EyeToyClient::SetHue(float) { }

// 0x80059EE0 | 24 bytes
void EyeToyClient::GetBrightness(void) { }

// 0x80059EF8 | 160 bytes
void EyeToyClient::SetBrightness(float) { }

// 0x80059F98 | 24 bytes
void EyeToyClient::Debug::GetTierRepShaderCount(int) { }

// 0x80059FB0 | 32 bytes
void EyeToyClient::Debug::GetTierNthRepShader(int, int) { }

// 0x80059FD0 | 220 bytes
void EyeToyClient::Debug::SetCUIFilterPipeline(void) { }

// 0x8005A0AC | 88 bytes
void EyeToyClient::Debug::WriteTGAToHost(ETexture *) { }

// 0x8005A108 | 1504 bytes
void EyeToyClient::CUIParams::UpdateWidgetValues(CUIWindow *, int, int) { }

// 0x8005A6E8 | 32 bytes
void EyeToyClient::CUIParams::SetDefaults_None(int *) { }

// 0x8005A708 | 32 bytes
void EyeToyClient::CUIParams::SetDefaults_BaseColorNeutral(int *) { }

// 0x8005A728 | 60 bytes
void EyeToyClient::CUIParams::SetDefaults_BaseColorPlusHalf(int *) { }

// 0x8005A764 | 84 bytes
void EyeToyClient::CUIParams::SetDefaults_BlendEdge(int *) { }

// 0x8005A7B8 | 72 bytes
void EyeToyClient::CUIParams::SetDefaults_HSV(int *) { }

// 0x8005A800 | 52 bytes
void EyeToyClient::CUIParams::SetDefaults_Posterize(int *) { }

// 0x8005A834 | 52 bytes
void EyeToyClient::CUIParams::SetDefaults_Solarize(int *) { }

// 0x8005A868 | 68 bytes
void EyeToyClient::CUIParams::SetDefaults_EdgePixel(int *) { }

// 0x8005A8AC | 852 bytes
void EyeToyClient::CUIParams::AddLabelSpinWidget(CUIWindow *, CUISpinState *, int, int, int, int, int, int, char *, char *, EVec3 &, bool) { }

// 0x8005AC00 | 580 bytes
void EyeToyClient::CUIParams::AddBlendWidget(CUIWindow *, int, int, int, bool) { }

// 0x8005AE44 | 244 bytes
void EyeToyClient::CUIParams::AddThreshWidget(CUIWindow *, int, int, int, bool) { }

// 0x8005AF38 | 420 bytes
void EyeToyClient::CUIParams::AddBaseColorWidgets(CUIWindow *, int, int, int, bool) { }

// 0x8005B0DC | 520 bytes
void EyeToyClient::CUIParams::AddHSVWidgets(CUIWindow *, int, int, int, bool) { }

// 0x8005B2E4 | 652 bytes
void EyeToyClient::CUIParams::AddStageWidgets(CUIWindow *, int, int, int, int) { }

// 0x8005B570 | 440 bytes
void EyeToyClient::CUIParams::UpdateStageLines(CUIWindow *, int, int) { }

// 0x8005B728 | 176 bytes
void EyeToyClient::CUIParams::AddFunFrameWidgets(CUIWindow *, int, int) { }

// 0x8005B7D8 | 436 bytes
void EyeToyClient::CUIParams::SetupWindow(CUIWindow *) { }

// 0x8005B98C | 364 bytes
void EyeToyClient::CUIParams::UpdateParamData(int *, int, float) { }

// 0x8005BAF8 | 1308 bytes
void EyeToyClient::CUIParams::WindowNotify(CUIWindow *, int) { }

// 0x8005C8B4 | 60 bytes
EyeToyClient::CUIParams::CUIParams(void) { }

// 0x8005C8F0 | 84 bytes
EyeToyClient::CUIParams::~CUIParams(void) { }

// 0x8005C944 | 12 bytes
void EyeToyClient::CUIParams::GetWindowName(void) { }
#endif
