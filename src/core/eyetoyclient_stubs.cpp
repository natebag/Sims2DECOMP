// EyeToyClient — stub implementations from symbol map
// Auto-generated. 118 functions.

// 0x800571B0 [172b]
void EyeToyClient::saveHeader(NghResFile::SaveRecord &) { }

// 0x80059EE0 [24b]
int EyeToyClient::GetBrightness(void) { }

// 0x80059C44 [84b]
int EyeToyClient::GetExposure(void) { }

// 0x80059DB8 [56b]
int EyeToyClient::GetHue(void) { }

// 0x80059D00 [24b]
int EyeToyClient::GetSaturation(void) { }

// 0x8005725C [244b]
void EyeToyClient::saveTexture(int, NghResFile::SaveRecord &) { }

// 0x80057350 [240b]
void EyeToyClient::Save(NghResFile::SectionID, NghResFile::SaveRecord &) { }

// 0x80057440 [4b]
void EyeToyClient::SaveComplete(NghResFile::SectionID, NghResFile::SaveRecord &) { }

// 0x80057444 [180b]
void EyeToyClient::loadHeader(NghResFile::SaveRecord &) { }

// 0x80059EF8 [160b]
void EyeToyClient::SetBrightness(float) { }

// 0x80059C98 [104b]
void EyeToyClient::SetExposure(float) { }

// 0x80059DF0 [240b]
void EyeToyClient::SetHue(float) { }

// 0x80059D18 [160b]
void EyeToyClient::SetSaturation(float) { }

// 0x800574F8 [8b]
void EyeToyClient::loadTexture_alloc(unsigned int, unsigned int) { }

// 0x80057500 [4b]
void EyeToyClient::loadTexture_dealloc(void *) { }

// 0x80057504 [288b]
void EyeToyClient::loadTexture(int, NghResFile::SaveRecord &) { }

// 0x80059520 [212b]
void EyeToyClient::WriteTextureToRepSlot(int, ETexture *, EyeToyClient::SlotImageType) { }

// 0x80057624 [240b]
void EyeToyClient::Load(NghResFile::SectionID, NghResFile::SaveRecord &) { }

// 0x80057714 [76b]
void EyeToyClient::LoadDefaultSettings(void) { }

// 0x80057760 [128b]
void EyeToyClient::FrameReadyCallback(char *, int) { }

// 0x800577E0 [96b]
void EyeToyClient::FindFirstConnectedEyeToy(void) { }

// 0x80057840 [212b]
void EyeToyClient::AcquireTexture(int, int, int) { }

// 0x80057914 [64b]
void EyeToyClient::ReleaseTexture(ETexture *) { }

// 0x80057954 [304b]
void EyeToyClient::AcquireRenderSurface(int, int, int) { }

// 0x80057A84 [64b]
void EyeToyClient::ReleaseRenderSurface(ERenderSurface *) { }

// 0x80057AC4 [1020b]
void EyeToyClient::CopyTextureToShader(ERShader *, ETexture *) { }

// 0x80057EC0 [1220b]
void EyeToyClient::CompositeFF_callback(ETexture *) { }

// 0x80058384 [124b]
void EyeToyClient::UpdateFunFrameLoading(void) { }

// 0x80058400 [900b]
void EyeToyClient::SetFilterPipeline(int) { }

// 0x80058784 [8b]
void EyeToyClient::SetUnplugCallback(void (*)(int)) { }

// 0x8005878C [48b]
void EyeToyClient::UnpluggedCallback(int) { }

// 0x800587BC [404b]
void EyeToyClient::Init(void) { }

// 0x80058950 [284b]
void EyeToyClient::Shutdown(void) { }

// 0x8005936C [180b]
void EyeToyClient::CloseSession(void) { }

// 0x80058A6C [164b]
void EyeToyClient::Update(float) { }

// 0x80058B10 [8b]
void EyeToyClient::MacroBlockDummyAllocator(unsigned int, unsigned int) { }

// 0x80058B18 [4b]
void EyeToyClient::MacroBlockDummyFree(void *) { }

// 0x80058B1C [1496b]
void EyeToyClient::Render(void) { }

// 0x80059FD0 [220b]
void EyeToyClient::Debug::SetCUIFilterPipeline(void) { }

// 0x800590F4 [8b]
int EyeToyClient::GetFunframeCount(void) { }

// 0x800590FC [8b]
int EyeToyClient::GetFilterCount(void) { }

// 0x80059104 [8b]
int EyeToyClient::GetTargetSlotCount(void) { }

// 0x8005910C [608b]
void EyeToyClient::OpenSession(void) { }

// 0x80059420 [132b]
void EyeToyClient::ApplyPresetFilter(int) { }

// 0x800594A4 [124b]
void EyeToyClient::ApplyFunFrame(int) { }

// 0x800595F4 [84b]
void EyeToyClient::SaveSessionToSlot(int) { }

// 0x80059648 [8b]
int EyeToyClient::GetSessionTexture(void) { }

// 0x80059650 [52b]
void EyeToyClient::StartStream(void) { }

// 0x80059684 [52b]
void EyeToyClient::StopStream(void) { }

// 0x800596B8 [48b]
bool EyeToyClient::IsEyeToyHardwarePresent(void) { }

// 0x800596E8 [52b]
bool EyeToyClient::IsSessionEyeToyDisconnected(void) { }

// 0x8005971C [384b]
int EyeToyClient::GetRepSlotUnLockedBits(int) { }

// 0x8005989C [124b]
int EyeToyClient::GetFunFrameUnLockedBits(int) { }

// 0x80059918 [136b]
void EyeToyClient::DoesRepSlotHaveEyetoyImage(int) { }

// 0x800599A0 [124b]
int EyeToyClient::GetRepShaderGUID(int) { }

// 0x80059A1C [140b]
bool EyeToyClient::IsSlotOpenForCASImage(int, int) { }

// 0x80059AA8 [36b]
void EyeToyClient::SetRepTexture(int, ETexture *) { }

// 0x80059ACC [192b]
int EyeToyClient::GetRepTexture(int) { }

// 0x80059B8C [136b]
int EyeToyClient::GetRepShaderERTextureID(EyeToyClient::RepShaderMapping) { }

// 0x80059C14 [48b]
void EyeToyClient::RestoreDefaults(void) { }

// 0x80059F98 [24b]
int EyeToyClient::Debug::GetTierRepShaderCount(int) { }

// 0x80059FB0 [32b]
int EyeToyClient::Debug::GetTierNthRepShader(int, int) { }

// 0x8005A0AC [88b]
void EyeToyClient::Debug::WriteTGAToHost(ETexture *) { }

// 0x8005A104 [4b]
void EyeToyClient::Debug::WriteTGAToHost(short *, int, int) { }

// 0x8005A6E8 [32b]
void EyeToyClient::CUIParams::SetDefaults_None(ImageProcessingManager::FilterParams *) { }

// 0x8005A708 [32b]
void EyeToyClient::CUIParams::SetDefaults_BaseColorNeutral(ImageProcessingManager::FilterParams *) { }

// 0x8005A728 [60b]
void EyeToyClient::CUIParams::SetDefaults_BaseColorPlusHalf(ImageProcessingManager::FilterParams *) { }

// 0x8005A764 [84b]
void EyeToyClient::CUIParams::SetDefaults_BlendEdge(ImageProcessingManager::FilterParams *) { }

// 0x8005A868 [68b]
void EyeToyClient::CUIParams::SetDefaults_EdgePixel(ImageProcessingManager::FilterParams *) { }

// 0x8005A800 [52b]
void EyeToyClient::CUIParams::SetDefaults_Posterize(ImageProcessingManager::FilterParams *) { }

// 0x8005A834 [52b]
void EyeToyClient::CUIParams::SetDefaults_Solarize(ImageProcessingManager::FilterParams *) { }

// 0x8005A7B8 [72b]
void EyeToyClient::CUIParams::SetDefaults_HSV(ImageProcessingManager::FilterParams *) { }

// 0x8005A108 [1504b]
void EyeToyClient::CUIParams::UpdateWidgetValues(CUIWindow *, int, ImageProcessingManager::eFilter) { }

// 0x8005A8AC [852b]
void EyeToyClient::CUIParams::AddLabelSpinWidget(CUIWindow *, CUISpinState *, int, int, int, int, int, int, char *, char *, EVec3 &, bool) { }

// 0x8005AC00 [580b]
void EyeToyClient::CUIParams::AddBlendWidget(CUIWindow *, int, int, int, bool) { }

// 0x8005AE44 [244b]
void EyeToyClient::CUIParams::AddThreshWidget(CUIWindow *, int, int, int, bool) { }

// 0x8005AF38 [420b]
void EyeToyClient::CUIParams::AddBaseColorWidgets(CUIWindow *, int, int, int, bool) { }

// 0x8005B0DC [520b]
void EyeToyClient::CUIParams::AddHSVWidgets(CUIWindow *, int, int, int, bool) { }

// 0x8005B2E4 [652b]
void EyeToyClient::CUIParams::AddStageWidgets(CUIWindow *, int, int, int, int) { }

// 0x8005B570 [440b]
void EyeToyClient::CUIParams::UpdateStageLines(CUIWindow *, int, int) { }

// 0x8005B728 [176b]
void EyeToyClient::CUIParams::AddFunFrameWidgets(CUIWindow *, int, int) { }

// 0x8005B7D8 [436b]
void EyeToyClient::CUIParams::SetupWindow(CUIWindow *) { }

// 0x8005B98C [364b]
void EyeToyClient::CUIParams::UpdateParamData(ImageProcessingManager::FilterParams *, int, float) { }

// 0x8005BAF8 [1308b]
void EyeToyClient::CUIParams::WindowNotify(CUIWindow *, int) { }

// 0x8005C8F0 [84b]
EyeToyClient::CUIParams::~CUIParams(void) { }

// 0x8005C944 [12b]
int EyeToyClient::CUIParams::GetWindowName(void) { }

// 0x8005C8B4 [60b]
void EyeToyClient::CUIParams::CUIParams(void) { }

// 0x80593AE8 [128b]
void EyeToyClient::CUIParams virtual table() { }

// 0x806A65C4 [120b]
void EyeToyClient::CUIParams::filterInfo() { }

// 0x806A6588 [60b]
void EyeToyClient::repShaderTable() { }

// 0x806EF4DC [16b]
void EyeToyClient::repShaders_tier1() { }

// 0x806EF4EC [24b]
void EyeToyClient::repShaders_tier2() { }

// 0x806EF504 [40b]
void EyeToyClient::repShaders_tier3() { }

// 0x806EF52C [32b]
void EyeToyClient::repShaders_tier4() { }

// 0x806EF54C [40b]
void EyeToyClient::repShaders_tier5() { }

// 0x806EF66C [28b]
void EyeToyClient::mLoadSaveHeader() { }

// 0x806EF574 [48b]
void EyeToyClient::FunFrameShaderGUIDs() { }

// 0x806EF4B8 [36b]
void EyeToyClient::systemHSVdesc() { }

// 0x806EF5A4 [180b]
void EyeToyClient::Params::filterDesc() { }

// 0x806EF658 [20b]
void EyeToyClient::s_filterParams() { }

// 0x8078D0E4 [4b]
void EyeToyClient::Debug::blUseCUIFilterPipeline() { }

// 0x8078D0E8 [4b]
void EyeToyClient::hInstance() { }

// 0x8078D0EC [4b]
void EyeToyClient::pLockedEyeToyImageData() { }

// 0x8078D0F0 [4b]
void EyeToyClient::effectiveFunFrameIndex() { }

// 0x8078D0F4 [4b]
void EyeToyClient::desiredFunFrameIndex() { }

// 0x8078D0F8 [4b]
void EyeToyClient::funframesEligibleForFilterFlags() { }

// 0x8078D0FC [4b]
void EyeToyClient::filterPresetIndex() { }

// 0x8078D100 [4b]
void EyeToyClient::blFilterPipeLineNeedsUpdate() { }

// 0x8078D104 [4b]
void EyeToyClient::blSessionOpen() { }

// 0x8078D108 [4b]
void EyeToyClient::nFoundEyeToyIndex() { }

// 0x8078D10C [4b]
void EyeToyClient::pAllocImageData() { }

// 0x8078D110 [4b]
void EyeToyClient::pTargetTexture() { }

// 0x8078D114 [4b]
void EyeToyClient::pFunFrameERShader() { }

// 0x8078D118 [4b]
void EyeToyClient::fnUnpluggedCallback() { }

// 0x8078D11C [4b]
void EyeToyClient::Params::iFunFrameStage() { }

// 0x8078F7AC [4b]
void EyeToyClient::mpSaveRecPtr() { }

// 0x8078F7A4 [8b]
void EyeToyClient::loadSettingsCache() { }

// 0x8078F7A0 [4b]
void EyeToyClient::pEyeToyTexture128x128() { }

