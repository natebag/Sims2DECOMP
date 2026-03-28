# Byte-Matching Plan: Prioritized Hit List

Generated from analysis of symbols.json + DOL binary.

## Executive Summary

- **Total code functions:** 18,459
- **Total code bytes:** 4,145,732 (4.0 MB)
- **Quick wins (Tiers 1-4):** 2,722 functions (14.7%) / 22,300 bytes (0.5%)
- **Estimated "free" matches:** ~1,976 functions need only a trivial one-liner
- **With 12-byte functions:** ~2,722 functions matchable in a single pass

The DOL and ELF share identical .text bytes, confirmed by binary comparison.
All 18,459 functions can be disassembled from either the ELF or DOL.

## Size Distribution

| Bucket | Count | % Funcs | Bytes | % Bytes |
|--------|------:|--------:|------:|--------:|
| 4b (1 instr) | 616 | 3.3% | 2,464 | 0.1% |
| 8b (2 instr) | 1,461 | 7.9% | 11,688 | 0.3% |
| 12b (3 instr) | 746 | 4.0% | 8,952 | 0.2% |
| 16b (4 instr) | 269 | 1.5% | 4,304 | 0.1% |
| 20b (5 instr) | 259 | 1.4% | 5,180 | 0.1% |
| 24-32b | 984 | 5.3% | 29,132 | 0.7% |
| 36-64b | 3,324 | 18.0% | 165,368 | 4.0% |
| 68-128b | 4,130 | 22.4% | 398,512 | 9.6% |
| 132-256b | 2,946 | 16.0% | 536,676 | 12.9% |
| 260-512b | 2,056 | 11.1% | 730,968 | 17.6% |
| 516-1024b | 1,054 | 5.7% | 743,856 | 17.9% |
| 1028b+ | 614 | 3.3% | 1,508,632 | 36.4% |

## Match Difficulty Tiers

### Tier 1: GUARANTEED -- Empty/Void Functions (blr only)

**614 functions** -- Just `blr` (return void). C++ equivalent: `void Foo() {}`

These are stub functions, empty virtual overrides, or no-op implementations. Every single one is a guaranteed byte-match with an empty function body.

<details>
<summary>All 614 blr-only functions (click to expand)</summary>

| Function | Address |
|----------|---------|
| `ACTTarget::DebugListValidation(void)` | 0x801A2C30 |
| `ARSetSize` | 0x80375A58 |
| `AptActionInterpreter::_FunctionAptActionBitURShift(AptActionInterpreter *, AptActionInterpreter::LocalContextT *)` | 0x8027CEB4 |
| `AptActionInterpreter::_FunctionAptActionCharToAscii(AptActionInterpreter *, AptActionInterpreter::LocalContextT *)` | 0x80275EB4 |
| `AptActionInterpreter::_FunctionAptActionEnd(AptActionInterpreter *, AptActionInterpreter::LocalContextT *)` | 0x802729D4 |
| `AptActionInterpreter::_FunctionAptActionMBAsciiToChar(AptActionInterpreter *, AptActionInterpreter::LocalContextT *)` | 0x8027623C |
| `AptActionInterpreter::_FunctionAptActionMBCharToAscii(AptActionInterpreter *, AptActionInterpreter::LocalContextT *)` | 0x80276238 |
| `AptActionInterpreter::_FunctionAptActionMBLength(AptActionInterpreter *, AptActionInterpreter::LocalContextT *)` | 0x80275EB0 |
| `AptActionInterpreter::_FunctionAptActionMBSubString(AptActionInterpreter *, AptActionInterpreter::LocalContextT *)` | 0x80276234 |
| `AptActionInterpreter::_FunctionAptActionStopSounds(AptActionInterpreter *, AptActionInterpreter::LocalContextT *)` | 0x80272BC0 |
| `AptActionInterpreter::_FunctionAptActionStringLessThan(AptActionInterpreter *, AptActionInterpreter::LocalContextT *)` | 0x80275D1C |
| `AptActionInterpreter::_FunctionAptActionToggleQuality(AptActionInterpreter *, AptActionInterpreter::LocalContextT *)` | 0x80272BBC |
| `AptActionInterpreter::_FunctionAptActionWaitForFrame(AptActionInterpreter *, AptActionInterpreter::LocalContextT *)` | 0x8027DAD4 |
| `AptArray::ConvertAptValue(AptValue *)` | 0x80287EF0 |
| `AptAuxPCEorGL_FreeConstantTable(void *)` | 0x800097C0 |
| `AptCharacterInst::PreDestroy(void)` | 0x8028FAE4 |
| `AptCharacterInst::PreDestroy(void)` | 0x8029C418 |
| `AptCharacterInst::PreDestroy(void)` | 0x802C4C64 |
| `AptDebugPrintZombieVector(void)` | 0x8026BAB0 |
| `AptExtern::AddRef(char *, char *, int)` | 0x802B4534 |
| `AptExtern::Release(char *, char *, int)` | 0x802B4538 |
| `AptGC::Initialize(void)` | 0x8029C650 |
| `AptNone::AddRef(char *, char *, int)` | 0x802B4454 |
| `AptNone::Release(char *, char *, int)` | 0x802B4458 |
| `AptScriptFunctionBase::PreDestroy(void)` | 0x802B8208 |
| `AptScriptFunctionByteCodeBlock::SetArgument(AptValue *, int)` | 0x802B91B8 |
| `AptSetMousePosition(int, int)` | 0x8026AAE8 |
| `AptTextFormat::operator delete [](void *)` | 0x802B0000 |
| `AptValue::DestroyGCPointers(void)` | 0x802B42E4 |
| `AptValue::PreDestroy(void)` | 0x802B42E0 |
| `AptValue::c_array(void) const` | 0x802B4938 |
| `AptValue::c_boolean(void) const` | 0x802B4928 |
| `AptValue::c_cih(bool) const` | 0x802B4934 |
| `AptValue::c_date(void) const` | 0x802B4958 |
| `AptValue::c_float(void) const` | 0x802B490C |
| `AptValue::c_global(void) const` | 0x802B4944 |
| `AptValue::c_integer(void) const` | 0x802B4904 |
| `AptValue::c_key(void) const` | 0x802B4940 |
| `AptValue::c_loadvars(void) const` | 0x802B4970 |
| `AptValue::c_lookup(void) const` | 0x802B4900 |
| `AptValue::c_math(void) const` | 0x802B4948 |
| `AptValue::c_movieClip(void) const` | 0x802B4960 |
| `AptValue::c_nativefunction(void) const` | 0x802B4930 |
| `AptValue::c_object(void) const` | 0x802B4950 |
| `AptValue::c_prototype(void) const` | 0x802B4954 |
| `AptValue::c_register(void) const` | 0x802B4908 |
| `AptValue::c_scriptcolour(void) const` | 0x802B494C |
| `AptValue::c_scriptfunction(void) const` | 0x802B492C |
| `AptValue::c_sound(void) const` | 0x802B493C |
| `AptValue::c_stage(void) const` | 0x802B4974 |
| `AptValue::c_textformat(void) const` | 0x802B495C |
| `AptValue::c_xml(void) const` | 0x802B4968 |
| `AptValue::c_xmlattributes(void) const` | 0x802B496C |
| `AptValue::c_xmlnode(void) const` | 0x802B4964 |
| `AptValue::setHasClass(int)` | 0x802B4260 |
| `AptValueNoGC::RegisterReferences(void) const` | 0x80281D2C |
| `AptValueNoGC::RegisterReferences(void) const` | 0x802AEC44 |
| `AptValueNoGC::RegisterReferences(void) const` | 0x802B42F8 |
| `AptValueNoGC::RegisterReferences(void) const` | 0x802BB8DC |
| `AptValueNoGC::RegisterReferences(void) const` | 0x802BBB8C |
| `AptValueNoGC::RegisterReferences(void) const` | 0x802BBE48 |
| `AptViewer::Update(void)` | 0x80010640 |
| `AptXmlAttributes::operator delete [](void *)` | 0x802C4FE4 |
| `AptXmlNode::operator delete [](void *)` | 0x802BB69C |
| `BSplineVolume::Write(EStream &)` | 0x8030E1B4 |
| `BackgroundImpl::Update(void)` | 0x802E1E50 |
| `Behavior::GetNodeText(short, BehaviorNode *, StringBuffer &)` | 0x800AB8C0 |
| `CASBodyTarget::SetVariable(char *, char *)` | 0x80196A50 |
| `CASFashionTarget::RandomizeFashion(void)` | 0x8019B3F4 |
| `CASMiscTarget::SetVariable(char *, char *)` | 0x8019C1B0 |
| `CASTarget::DialogNoSelectionCallback(void)` | 0x801960F4 |
| `CDirtyXml::load(char *)` | 0x8023AFBC |
| `CDirtyXml::send(char *)` | 0x8023B050 |
| `CDirtyXml::sendAndLoad(char *, IAptXml *)` | 0x8023B054 |
| `CDirtyXml::setContentType(char *)` | 0x8023AF80 |
| `CDirtyXml::setDocTypeDecl(char *)` | 0x8023AF9C |
| `CDirtyXml::setIgnoreWhite(int)` | 0x8023AFB0 |
| `CDirtyXmlNode::appendChild(IAptXmlNode *)` | 0x8023A8F8 |
| `CDirtyXmlNode::cloneNode(int)` | 0x8023AA70 |
| `CDirtyXmlNode::insertBefore(IAptXmlNode *, IAptXmlNode *)` | 0x8023AAAC |
| `CDirtyXmlNode::removeNode(void)` | 0x8023AC38 |
| `CDirtyXmlNode::setAttribute(char *, char *)` | 0x8023AA00 |
| `CDirtyXmlNode::setNodeName(char *)` | 0x8023AB7C |
| `CDirtyXmlNode::setNodeValue(char *)` | 0x8023ABE0 |
| `CRDTarget::Draw(ERC *)` | 0x801A4C6C |
| `CRDTarget::UpdateCredits(void)` | 0x801A4F80 |
| `CSPTarget::Update(void)` | 0x801A9918 |
| `CSPTarget::onHelpDialogSelection(int)` | 0x801AA57C |
| `CTGDump::CTGDump(void)` | 0x800A5158 |
| `CTGDump::Shutdown(void)` | 0x800A5184 |
| `CTGDump::operator<<(char *)` | 0x800A5188 |
| `CTGFileManager::CTGFileManager(void)` | 0x8007D350 |
| `CTGFileManager::Shutdown(void)` | 0x8007D384 |
| `CUnlockDisplayObjectSim::Setup(void)` | 0x80079EAC |
| `CameraManager::Initialize(void)` | 0x8001EB78 |
| `CameraManager::Shutdown(void)` | 0x8001EB7C |
| `CasListener::HandleEventChangeFocus(CasEventChangeFocus &)` | 0x80161BB0 |
| `CasListener::HandleEventChangeSim(CasEventChangeSimS2C &)` | 0x80161BB4 |
| `CasListener::HandleEventInitSim(CasEventInitSim &)` | 0x80161BB8 |
| `CasListener::HandleEventMorphSim(CasEventMorphSimS2C &)` | 0x80161BC4 |
| `CasListener::HandleEventResetSim(CasEventResetSim &)` | 0x80161BBC |
| `CasListener::HandleEventResetSimDraw(CasEventResetSimDraw &)` | 0x80161BC8 |
| `CasListener::HandleEventStoreSim(CasEventStoreSim &)` | 0x80161BC0 |
| `CasNpcEditor::MakeDataset(UserDataSaveLoad)` | 0x80163D48 |
| `CasSimDescriptionS2C::WriteSimDescriptionToTextFile(__sFILE *, SimModel *)` | 0x8016A890 |
| `CreateASimBaseState::Draw(ERC *)` | 0x800898C0 |
| `DBClose` | 0x80267898 |
| `DBOpen` | 0x8026789C |
| `DStraceNull(...)` | 0x800F3C90 |
| `DefaultSwitchThreadCallback` | 0x80253258 |
| `DummyMode::Draw(ERC *)` | 0x800998C4 |
| `DummyMode::Init(int)` | 0x800998B8 |
| `DummyMode::Reset(int)` | 0x800998BC |
| `DummyMode::Update(void)` | 0x800998C0 |
| `E3DWindow::Cast3DWindow(void)` | 0x802E76A4 |
| `EA::Allocator::GeneralAllocator::AdjustHighFence(void)` | 0x802D9350 |
| `EA::Allocator::GeneralAllocator::TraceFunctionDefault(char *, void *)` | 0x802DA584 |
| `EAllocGroup::Validate(void)` | 0x80359F34 |
| `EApp::CleanupAfterMovie(void)` | 0x802E24B4 |
| `EApp::Init(void)` | 0x802E2978 |
| `EApp::SetupForMovie(void)` | 0x802E24B0 |
| `EApp::ShowInitialDisplay(void)` | 0x802E2974 |
| `EApp::Shutdown(void)` | 0x802E2990 |
| `EApp::Update(void)` | 0x802E297C |
| `EApp::UpdateAfterHotSync(void)` | 0x802E2980 |
| `EBitArray::Print(void)` | 0x802E00AC |
| `ECheats::Update(void)` | 0x80020D0C |
| `ECheats::WriteCheatsFile(void)` | 0x80020D08 |
| `EControllerManager::Shutdown(void)` | 0x8032344C |
| `EDatasetManager::ManageDasFile(char *)` | 0x80324598 |
| `EDebugMenuItem::ButtonPress(EDebugMenuButton)` | 0x803C4178 |
| `EDebugMenuItem::ButtonPress(EDebugMenuButton, float)` | 0x803C417C |
| `EDummyFile::Destroy(void)` | 0x800226C0 |
| `EEngine::Line(void)` | 0x802E2B48 |
| `EEngine::PrintBanner(void)` | 0x802E3238 |
| `EEngine::PrintConfiguration(void)` | 0x802E323C |
| `EEngine::Reboot(void)` | 0x802E38C0 |
| `EEngine::SignalShutdown(void)` | 0x802E38E4 |
| `EFixedString::ReleaseBuffer(void)` | 0x802C862C |
| `EGameState::PauseAllSounds(void)` | 0x80089E28 |
| `EGameState::ResumeAllSounds(void)` | 0x80089E2C |
| `EGlobal::FreeScratchHeap(void)` | 0x8003F0D0 |
| `EGlobal::PickUpInHouseObject(cXObject *)` | 0x80041218 |
| `EGlobal::PlaceObjectInHouse(cXObject *)` | 0x80041214 |
| `EGlobal::SetupScratchHeap(void)` | 0x8003F0CC |
| `EGlobalManagerClient::ManagedShutdown(void)` | 0x803C1CF8 |
| `EGraphics::ClearStencilBuffer(void)` | 0x802F2318 |
| `EGraphics::DiscardAllVram(void)` | 0x802F2314 |
| `EGraphics::DoSetupFrameBuffer(int)` | 0x802F11AC |
| `EGraphics::DoSwapBuffer(int)` | 0x802F11A8 |
| `EGraphics::DrawCensorRects(ERC *)` | 0x802F21C0 |
| `EGraphics::GrabFrameBufferChunk32(int, int, int, int, unsigned int *, int *)` | 0x802F2310 |
| `EGraphics::ManagedShutdown(void)` | 0x802F0F80 |
| `EGraphics::ProcessFrameEffects(void)` | 0x802F231C |
| `EGraphics::SelectFrameBuffer(int)` | 0x802F2368 |
| `EGraphics::Shutdown(void)` | 0x802F21AC |
| `EHouse::TriggerLightningEffect(void)` | 0x80024824 |
| `EIFloor::Update(void)` | 0x8004850C |
| `EILight::CalcFullIntensityLightOnPoint(EVec3 &, float &)` | 0x802280C8 |
| `EILight::LightingParameters(EVec3 &, float &, EVec3 &, EVec3 &)` | 0x802280C4 |
| `EILight::Setup(void)` | 0x802280CC |
| `EIWallPart::RealizeShaderTuning(void)` | 0x8003065C |
| `EInstance::AboutToBeRemovedFromLevel(ERLevel *)` | 0x802296FC |
| `EInstance::AddedToLevel(ERLevel *)` | 0x802296F8 |
| `EInstance::DoAnimation(void)` | 0x80229464 |
| `EInstance::DoLightingCalculation(void)` | 0x80229468 |
| `EInstance::Draw(ELevelDrawData &)` | 0x80229474 |
| `EInstance::DrawShadow(ELevelDrawData &)` | 0x8022947C |
| `EInstance::DrawStencil(ELevelDrawData &)` | 0x80229478 |
| `EInstance::DrawWireFrame(ERC *)` | 0x80229480 |
| `EInstance::GetOwner(void)` | 0x8022967C |
| `EInstance::GetShadowCenter(EVec3 &) const` | 0x8022965C |
| `EInstance::Init(void)` | 0x8022945C |
| `EInstance::ModifyColor(unsigned int)` | 0x802296EC |
| `EInstance::ReadInstanceData(EStream &, bool)` | 0x80229668 |
| `EInstance::RealizeShaderTuning(void)` | 0x80229740 |
| `EInstance::RebuildShaders(void)` | 0x80229488 |
| `EInstance::RegisterFloor(void)` | 0x802294A8 |
| `EInstance::RemovedFromLevel(ERLevel *)` | 0x80229700 |
| `EInstance::SetOrient(EMat4 &)` | 0x80229484 |
| `EInstance::Update(void)` | 0x80229460 |
| `ELiveMode::PauseAllSounds(void)` | 0x8008EF14 |
| `ELiveMode::ResumeAllSounds(void)` | 0x8008EF18 |
| `EMat4::Print(void) const` | 0x802CA640 |
| `EMemoryCard::SetMemCardCopyProtection(unsigned int)` | 0x803C76CC |
| `EMemoryMeterWin::Init(void)` | 0x80057998 |
| `EMemoryMeterWin::Reset(void)` | 0x8005799C |
| `EMemoryMeterWin::SetEvent(Panelstateman::PanelEvent, unsigned int)` | 0x80057C14 |
| `EMovie::Reset(void)` | 0x80364CE4 |
| `EMovie::Stop(void)` | 0x80364CE0 |
| `ENCamera::GetName(void)` | 0x8035D248 |
| `ENDummy::GetName(void)` | 0x802CC4B0 |
| `ENgcAudio::AddEvent(EA_EVENT, EMsgQueue &, unsigned int)` | 0x8032CC20 |
| `ENgcAudio::AudioAlarmHandler(OSAlarm *, OSContext *)` | 0x8032B9F0 |
| `ENgcAudio::Flush(bool)` | 0x8032CC1C |
| `ENgcAudio::RemoveEvent(EA_EVENT, EMsgQueue &, unsigned int)` | 0x8032CC24 |
| `ENgcClockMan::Init(void)` | 0x8032DA34 |
| `ENgcClockMan::Update(void)` | 0x8032DA38 |
| `ENgcControllerManager::Shutdown(void)` | 0x8032DD5C |
| `ENgcEngine::InitializeProfiler(void)` | 0x8032E638 |
| `ENgcGraphics::GetScreenShot(char *)` | 0x8032F630 |
| `ENgcMemoryCard::SetGameCode(char *)` | 0x80334894 |
| `ENgcMemoryCard::SetupSaveTypes(EMC_SaveType, unsigned int)` | 0x80334890 |
| `ENgcMovie::Reset(void)` | 0x8033549C |
| `ENgcRC::Debug(unsigned int, unsigned int)` | 0x8033B3AC |
| `ENgcRC::GeometrySetup(void)` | 0x8033ABAC |
| `ENgcRC::ParticleListInfo(EGEParticleListInfo *)` | 0x8033B3B0 |
| `ENgcRC::ScreenTriList(int, float *, float *, unsigned char *)` | 0x8033A1C0 |
| `ENgcRC::SetMipMap(float, int)` | 0x8033A480 |
| `ENgcRC::TriList(int, float *, float *, unsigned char *, signed char *, unsigned char *, bool)` | 0x8033A1BC |
| `ENgcRenderer::NoOp(EDLEntry *)` | 0x8034A778 |
| `ENgcRenderer::ShowPerfGraphs(bool)` | 0x8033B720 |
| `ENgcRenderer::TextureMatrix(EDLEntry *)` | 0x8034443C |
| `ENgcRenderer::VIPostRetraceCallback(unsigned long)` | 0x8033CDEC |
| `ENgcScheduler::RendFrameComplete(ESchedCommand *)` | 0x8034DBA8 |
| `ENgcScheduler::RenderingComplete(ESchedCommand *)` | 0x8034D9E4 |
| `ENgcScheduler::TextureLoadsComplete(ESchedCommand *)` | 0x8034D9E0 |
| `ENgcTextureBase::Invalidate(void)` | 0x8034FE38 |
| `ENgcTextureBase::UnswizzleImage(unsigned char *, int, int, unsigned char *)` | 0x80350618 |
| `ENgcTextureCMPR::SwizzleImage(unsigned char *, int, int, unsigned char *)` | 0x80351534 |
| `EQuat::Print(void)` | 0x802CCB00 |
| `ERC::EnableColorModulation(bool)` | 0x802F8DE4 |
| `ERC::LightsRadiosity(EVec3 &, EVec3 &, float)` | 0x802F9AB8 |
| `ERC::MipMapSetup(EGEVert *, bool, bool)` | 0x802F826C |
| `ERC::ParticleListEnd(unsigned int)` | 0x802F7074 |
| `ERC::ParticleListInfo(EGEParticleListInfo *)` | 0x802F7068 |
| `ERC::PointList(EGEVert *, int)` | 0x802F6D58 |
| `ERC::QuadList(EGEVert *, int)` | 0x802F6BE8 |
| `ERC::QuadList(int, float *, float *, unsigned char *, signed char *, bool)` | 0x802F6BEC |
| `ERC::SetAlphaPlane(float, EVec4, float, float)` | 0x802F9798 |
| `ERC::SetBlendModePass3(int, int, int, int, int)` | 0x802F8EC4 |
| `ERC::SetColorModulation(int, EVec4)` | 0x802F8DE0 |
| `ERC::SetDebugMarker(int)` | 0x802F9674 |
| `ERC::SetFog(float, float, EVec4)` | 0x802F979C |
| `ERC::SetTextureAlphaValue(unsigned char, unsigned char, unsigned char)` | 0x802F8EC8 |
| `ERC::TriFan(EGEVert *, int)` | 0x802F6BE0 |
| `ERC::TriList(EGEVert *, int)` | 0x802F6BE4 |
| `ERCharacter::PrintNodes(void)` | 0x80368B18 |
| `ERLevel::GroupWallInstances(void)` | 0x802337D0 |
| `ERLevel::ValidateInstanceInLevel(EInstance *)` | 0x80233364 |
| `ERModel::RebuildAfterWelding(void)` | 0x80319E84 |
| `ERQuickdata::LockImage(void)` | 0x8031B8F4 |
| `ERQuickdata::UnlockImage(void)` | 0x8031B8F0 |
| `EResPrefetchFile::Destroy(void)` | 0x80313078 |
| `EResource::AddRefSubResources(void)` | 0x80312344 |
| `EResource::DelRefSubResources(void)` | 0x80312340 |
| `EResource::DetachClone(void)` | 0x80312350 |
| `EResource::Init(void)` | 0x80312338 |
| `EResource::Refresh(EFile *)` | 0x8031233C |
| `EResource::SetCheckPoint(unsigned int)` | 0x803122B8 |
| `EResource::SetResName(char *)` | 0x803122A8 |
| `EResourceLoaderImpl::Update(void)` | 0x803104B0 |
| `EResourceManager::LogResourceLoad(EResource *)` | 0x80326C08 |
| `EResourceManager::PrintUnmanagedResources(void)` | 0x80326718 |
| `EResourceManager::ResourceDestructing(EResource *)` | 0x80327530 |
| `EResourceMap::PrintLoadedResources(char *)` | 0x80327EA0 |
| `EResourceMap::PrintResourceSizes(char *)` | 0x80327EA4 |
| `EResourceMap::RefreshResources(void)` | 0x80327EA8 |
| `EScratchBuffUser::AcquireBuffer(void *, unsigned int)` | 0x803C41D4 |
| `EScratchBuffUser::ReleasedBuffer(EScratchBuffUser *)` | 0x803C41D8 |
| `EShader::AddGeometryModes(unsigned int)` | 0x802FABF4 |
| `EShader::GetShaderDef(void) const` | 0x802FAB4C |
| `EShader::RemoveGeometryModes(unsigned int)` | 0x802FABF0 |
| `EShader::Select(ERC *, unsigned int)` | 0x802FAAA8 |
| `EShader::SetAlternateShader(EShader *)` | 0x802FAB48 |
| `EShader::SetShadowAlpha(float)` | 0x802FA9E4 |
| `EShader::UpdateMaterialCoefficients(void)` | 0x802FABD0 |
| `ESim::DoLightingCalculation(void)` | 0x800334F8 |
| `ESim::SetXOb(cXObject *)` | 0x80035308 |
| `ESimScratchPadMan::EmptyHeap(void)` | 0x8003545C |
| `ESims3DHead::Update(void)` | 0x8006D518 |
| `ESimsCam::CursorMoved(int, EVec3 &)` | 0x80019A00 |
| `EStorable::Load(EFile &)` | 0x803C148C |
| `EStorable::Read(EStream &)` | 0x803C1484 |
| `EStorable::Write(EStream &)` | 0x803C1488 |
| `ESubModelShader::DrawNormals(ERC *)` | 0x802FD24C |
| `ESubModelShader::DrawWireFrame(ERC *)` | 0x802FD250 |
| `ESubModelShader::MorphBreakUpStrip(TArray<ESMSStrip, TArrayERModelAllocator> &, TArray<ESMSStrip, TArrayERModelAllocator> &)` | 0x802FD254 |
| `ETexture::DisableMipmapping(void)` | 0x80365130 |
| `ETexture::Invalidate(void)` | 0x8036512C |
| `ETexture::Select(int)` | 0x80365078 |
| `ETexture::Unlock(void)` | 0x80365128 |
| `ETexture::Validate(void)` | 0x80365074 |
| `EThread::Main(void)` | 0x802D868C |
| `EThread::PrintAllThreads(void)` | 0x802E1800 |
| `EThread::ValidateAllStacks(void)` | 0x802E17F4 |
| `EThread::ValidateStack(void)` | 0x802E17F0 |
| `EVec4::Print(void)` | 0x80361F34 |
| `EWindow::InputCoordinatesChanged(void)` | 0x80300AFC |
| `EWindow::OutputCoordinatesChanged(void)` | 0x80300B00 |
| `EWindow::WindowMatrixChanged(void)` | 0x80300AF8 |
| `EXI2_EnableInterrupts` | 0x8026786C |
| `EXI2_Init` | 0x80267868 |
| `EXI2_Reserve` | 0x80267888 |
| `EXI2_Unreserve` | 0x8026788C |
| `Effects::FastParticleEmitter::InitPlatform(void)` | 0x80353090 |
| `Effects::GetFaceCameraRotation(ERC *, EMat4 &, EVec4 &, bool)` | 0x80352214 |
| `Effects::InitEffectsMath(void)` | 0x80352A10 |
| `EventPostRetraceCallback(unsigned long)` | 0x8032E6A4 |
| `EventPreRetraceCallback(unsigned long)` | 0x8032E6A8 |
| `EyeToyClient::Debug::WriteTGAToHost(short *, int, int)` | 0x80039510 |
| `EyeToyClient::MacroBlockDummyFree(void *)` | 0x800387BC |
| `EyeToyClient::SaveComplete(NghResFile::SectionID, NghResFile::SaveRecord &)` | 0x80037650 |
| `EyeToyClient::loadTexture_dealloc(void *)` | 0x80037710 |
| `EyeToyManager::CleanUpBufferBetaHack(void)` | 0x80328F58 |
| `EyeToyManager::ConvertInstanceIndexToHandle(int)` | 0x80328F50 |
| `EyeToyManager::NormalizeTexture(EyeToyManager::NormalizationParams *)` | 0x80328F54 |
| `FAMTarget::OnCancelDialog(void)` | 0x801B0E6C |
| `FAMTarget::OnCircleKeyPressed(char *, char *)` | 0x801B2604 |
| `FAMTarget::OnLeftKeyPressed(char *, char *)` | 0x801B075C |
| `FAMTarget::OnRightKeyPressed(char *, char *)` | 0x801B0760 |
| `FAMTarget::Shutdown(void)` | 0x801B070C |
| `FAMTarget::Update(void)` | 0x801B0710 |
| `FlashPiMenu::CleanUpAllMenus(void)` | 0x80039DE4 |
| `FlashPiMenu::Update(void)` | 0x80039DE0 |
| `GOLTarget::Draw(ERC *)` | 0x801EC098 |
| `GOLTarget::Update(void)` | 0x801EC094 |
| `GXSetTevClampMode` | 0x8038F964 |
| `GameData::StageOutputActualTimes(char *)` | 0x8003DC38 |
| `GameData::SystemPostUpdate(void)` | 0x8003CE78 |
| `GameEffectsManager::GameEffectsManager(void)` | 0x8003E008 |
| `GetVar_EYE_targetState::Handler(char *)` | 0x801E9484 |
| `GetVar_Legacy::Handler(char *)` | 0x801E9480 |
| `GetVar_SaveStatus::Handler(char *)` | 0x801E9488 |
| `H2DTarget::Draw(ERC *)` | 0x801B8480 |
| `HDDThread::InitAndRun(void)` | 0x80321E70 |
| `HDDThread::Main(void)` | 0x80321FC4 |
| `HDDThread::SpeedTest(void)` | 0x80321FC0 |
| `HUDTarget::DrawMotiveValues(ERC *, int)` | 0x801890C8 |
| `HUDTarget::OnHUDHide(void)` | 0x80188004 |
| `HUDTarget::OnHUDHideStart(void)` | 0x80188000 |
| `HUDTarget::OnHUDShow(void)` | 0x80187FFC |
| `IFFSlotDescList::SetStringSetID(int)` | 0x801452B4 |
| `INVTarget::CannotGrabToInventoryDialogZeroInputCallback(void)` | 0x801F14BC |
| `INVTarget::FireCodeDialogZeroInputCallback(void)` | 0x801F146C |
| `INVTarget::GetOnMsgInvShpCurrentCell(char *)` | 0x801F6950 |
| `INVTarget::GetOnMsgInvShpIsTabEnabled(char *)` | 0x801F714C |
| `INVTarget::InstallShoppingCategoryShaders(void)` | 0x801F60D4 |
| `INVTarget::SetOnMsgInvClose(char *)` | 0x801F4794 |
| `INVTarget::SetOnMsgInvShpQueryTab(char *)` | 0x801F500C |
| `ISimInstance::CleanupStuff(ERLevel *)` | 0x800569F0 |
| `ISimInstance::Create(cXObject *, EHouse *)` | 0x8005631C |
| `ISimInstance::CreateShadow(void)` | 0x80056328 |
| `ISimInstance::GetSimInstance(void)` | 0x80056A04 |
| `ISimInstance::InsertSubModelsInHouse(ERLevel *)` | 0x8005632C |
| `ISimInstance::OrentSubObject(cXObject *)` | 0x80056320 |
| `ISimInstance::PropigateFlagsToSubModels(void)` | 0x80056334 |
| `ISimInstance::RemoveSubModelsFromHouse(ERLevel *)` | 0x80056330 |
| `ISimInstance::SetCarryOrient(void)` | 0x8005633C |
| `ISimInstance::SetObjOrient(void)` | 0x80056324 |
| `ISimInstance::SetOutOfWorld(void)` | 0x80056338 |
| `ISimInstance::StartBurp(int)` | 0x80056340 |
| `ISimsObjectModel::SetOutOfWorld(void)` | 0x8004ED20 |
| `ISimsObjectModel::SetPosStatic(EVec3 &, float)` | 0x8004EB6C |
| `ISimsWallObjectModel::CreateShadow(void)` | 0x80051218 |
| `IconGroupImpl::GetLabel(StringBuffer &)` | 0x800BCB68 |
| `IconGroupImpl::LoadStrings(void)` | 0x800BCB6C |
| `ImageProcessingManager::DummyFree(void *)` | 0x8032A298 |
| `InLevelBaseState::dialog_zero_input_callback(void)` | 0x8008B5AC |
| `InteractorModule::Interactor::ExecuteObjectActionMenu(cXObject *)` | 0x80209514 |
| `InteractorModule::Interactor::OnCommandPressed(InteractorModule::InteractorInputManager::InteractorCommand, float)` | 0x802094EC |
| `InteractorModule::Interactor::StopInObjectMenu(void)` | 0x80209518 |
| `InteractorModule::Interactor::UpdateOverlapIntersection(InteractorModule::Interactor::OverlapData *)` | 0x80209510 |
| `InteractorModule::InteractorVisualizer::Draw(InteractorModule::SocialModeInteractor &)` | 0x802172F8 |
| `InteractorModule::ObjectManipulator::OnCommandPressed(InteractorModule::InteractorInputManager::InteractorCommand, float)` | 0x8021922C |
| `InteractorModule::ObjectManipulator::SetUIDebugName(cXObject *)` | 0x8021A030 |
| `InteractorModule::SocialModeInteractor::GetInteractorInfo(InteractorModule::InteractorInfo &)` | 0x8021F3D8 |
| `InteractorModule::SocialModeInteractor::OnCommandPressed(InteractorModule::InteractorInputManager::InteractorCommand, float)` | 0x8021F3DC |
| `InteractorModule::SocialModeInteractor::OnCommandReleased(InteractorModule::InteractorInputManager::InteractorCommand)` | 0x8021F3E0 |
| `InteractorModule::SocialModeInteractor::OnCommandUpdate(InteractorModule::InteractorInputManager::InteractorCommand, float)` | 0x8021F3E4 |
| `InteractorModule::WMNullFunc(...)` | 0x80224060 |
| `LDtraceNull(...)` | 0x800EE2B0 |
| `LiveModeInitState::Draw(ERC *)` | 0x8008C9BC |
| `LiveModeInitState::Shutdown(void)` | 0x8008BC24 |
| `LoadGameTarget::ImportLoad(NghResFile::SectionID, NghResFile::SaveRecord &)` | 0x8018AAF0 |
| `LoadGameTarget::ImportSave(NghResFile::SectionID, NghResFile::SaveRecord &)` | 0x8018CCBC |
| `LoadGameTarget::ImportSaveComplete(NghResFile::SectionID, NghResFile::SaveRecord &)` | 0x8018CCC0 |
| `LogPersonTracker::Print(void)` | 0x8013EDD0 |
| `LogPersonTracker::PrintHeader(void)` | 0x8013EDD4 |
| `M2MTarget::ZeroInputCallback(void)` | 0x801C0C9C |
| `MDITarget::UpdateModelessDialogs(void)` | 0x801C3C9C |
| `MIXQuit` | 0x8037BCB8 |
| `MLtraceNull(...)` | 0x800F30B8 |
| `MMUTarget::OnCancelDialog(void)` | 0x801C8788 |
| `MMUTarget::OnCancelDialog2(void)` | 0x801C8790 |
| `MMUTarget::OnDialog2Close(int)` | 0x801C878C |
| `MOTTarget::UpdateMotives(void)` | 0x801CBB74 |
| `MUStatesDisplay::Startup(void)` | 0x800931B0 |
| `MUStatesLoadGame::Draw(ERC *)` | 0x80091B84 |
| `MUStatesLoadHouse::Draw(ERC *)` | 0x80092018 |
| `MUStatesSaveExistingGame::Draw(ERC *)` | 0x80092B14 |
| `MotiveCurveSet::PrintMotiveGraph(__sFILE *, StringSet *)` | 0x800C2D88 |
| `MotiveCurveSet::PrintMotiveGraph(char *)` | 0x800C2D8C |
| `MoviePlayerEndgameMovieState::Draw(ERC *)` | 0x800587E8 |
| `NeighborhoodImpl::GetImpl(void)` | 0x800D194C |
| `NeighborhoodImpl::PostSim(void)` | 0x800CCD00 |
| `NeighborhoodImpl::UnloadHouse(void)` | 0x800D129C |
| `NewControlParms::Validate(void)` | 0x8001E878 |
| `NghResFile::Detach(Memory::HandleNode *)` | 0x800D3D68 |
| `NghResFile::FindUniqueName(int, StringBuffer &)` | 0x800D3D5C |
| `NghResFile::GetIndex(Memory::HandleNode *, short *)` | 0x800D3D58 |
| `NghResFile::GetName(Memory::HandleNode *, StringBuffer &)` | 0x800D3D3C |
| `NghResFile::Load(Memory::HandleNode *)` | 0x800D3D6C |
| `NghResFile::Remove(Memory::HandleNode *)` | 0x800D3F70 |
| `NghResFile::SetID(Memory::HandleNode *, short)` | 0x800D3D78 |
| `NghResFile::SetInfo(Memory::HandleNode *, short, StringBuffer &, char)` | 0x800D3F74 |
| `NghResFile::Update(void)` | 0x800D3BE0 |
| `NghResFile::Write(Memory::HandleNode *)` | 0x800D3F6C |
| `OPTTarget::Update(void)` | 0x801FC2AC |
| `OSNotifyLink` | 0x8024FE58 |
| `OSNotifyUnlink` | 0x8024FE5C |
| `ObjDefinition::Swizzle(void *, int)` | 0x800D942C |
| `ObjFnTableQuickData::SetCheckTreeID(ObjEntryPoint, short)` | 0x80110060 |
| `ObjFnTableQuickData::SetTreeID(ObjEntryPoint, short)` | 0x8011005C |
| `ObjSelector::ChangedDef(void)` | 0x801108EC |
| `ObjSelector::SetObjectName(char *)` | 0x801108E8 |
| `ObjectDataObjDefinition::ResetResData(void)` | 0x8015BF30 |
| `ObjectFolderImpl::CreatingResFile(iResFile *)` | 0x800EFDC4 |
| `ObjectFolderImpl::DeletingResFile(iResFile *)` | 0x800EFDC8 |
| `ObjectFolderImpl::ResumeObjectFiles(void)` | 0x800F179C |
| `ObjectFolderImpl::SuspendObjectFiles(void)` | 0x800F1798 |
| `ObjectModuleImpl::EnqueueObjectDialog(ObjSelector *, DialogParam *)` | 0x800F82C4 |
| `ObjectModuleImpl::EnqueueObjectDialog(cXObject *, StackElem *, DialogParam *)` | 0x800F82C0 |
| `ObjectModuleImpl::MotiveAccessed(cXPerson *, int, bool)` | 0x800F8554 |
| `ObjectModuleImpl::PersonalityAccessed(cXPerson *, int, bool)` | 0x800F8558 |
| `ObjectModuleImpl::RelationshipAccessed(cXObject *, cXObject *, int, bool)` | 0x800F855C |
| `ObjectModuleImpl::SkillAccessed(cXPerson *, int, bool)` | 0x800F8550 |
| `PAZBase::Update(void)` | 0x801D0B64 |
| `PAZBase::UpdateButtonVisibility(void)` | 0x801D0B70 |
| `PPMMutexDestroy(void *)` | 0x802D877C |
| `PRGTarget::UpdateShaders(void)` | 0x801DA620 |
| `PaneItem::CalculateSize(void)` | 0x803A07C8 |
| `PaneItem::Draw(ERC *, float)` | 0x803A0974 |
| `PaneItem::Shutdown(void)` | 0x803A07B8 |
| `PaneItem::Startup(void)` | 0x803A0970 |
| `PassiveInfluenceSystem::DoStream(ReconBuffer *, int)` | 0x80113F3C |
| `PreGameCasPlayer1State::Shutdown(void)` | 0x800949E8 |
| `PreGameCasPlayer1State::Startup(void)` | 0x800949E4 |
| `QuickDataBehaviorConstants::SetValueCount(int)` | 0x8015A06C |
| `QuickDataSlotDescList::SetStringSetID(int)` | 0x8014516C |
| `QuickResFile::Add(Memory::HandleNode *, int, short, StringBuffer &, bool)` | 0x80132C4C |
| `QuickResFile::AddWithLanguage(Memory::HandleNode *, int, short, StringBuffer &, char, bool)` | 0x80132C50 |
| `QuickResFile::Detach(Memory::HandleNode *)` | 0x80132C38 |
| `QuickResFile::Load(Memory::HandleNode *)` | 0x80132C3C |
| `QuickResFile::Remove(Memory::HandleNode *)` | 0x80132C58 |
| `QuickResFile::SetID(Memory::HandleNode *, short)` | 0x80132C48 |
| `QuickResFile::SetInfo(Memory::HandleNode *, short, StringBuffer &, char)` | 0x80132C5C |
| `QuickResFile::Update(void)` | 0x80132ABC |
| `QuickResFile::Write(Memory::HandleNode *)` | 0x80132C54 |
| `QuickStringSet::Copy(StringSet *)` | 0x800A761C |
| `QuickStringSet::InsertString(int, char *, char)` | 0x800A7770 |
| `QuickStringSet::RemoveString(int, char)` | 0x800A7774 |
| `QuickStringSet::SetDescription(int, char *, char)` | 0x800A7780 |
| `QuickStringSet::SetName(StringBuffer *)` | 0x800A77A8 |
| `QuickStringSet::SetString(int, char *, char)` | 0x800A7768 |
| `QuickStringSet::SetString(int, unsigned wchar_t *, char)` | 0x800A776C |
| `QuickStringSet::WriteAnsiToDB(void)` | 0x800A7C20 |
| `QuickStringSet::WriteWideToDB(void)` | 0x800A7C24 |
| `R2LTarget::Update(void)` | 0x801DBB98 |
| `R2LTarget::onHelpDialogSelection(int)` | 0x801DCE28 |
| `RCPTarget::Draw(ERC *)` | 0x801DE534 |
| `REffectsSequencer::AddRefSubResources(void)` | 0x8036AF40 |
| `REffectsSequencer::DelRefSubResources(void)` | 0x8036AF3C |
| `ReconObject::DoStream(ReconBuffer *, int)` | 0x80134768 |
| `RoomManager::InitLights(void)` | 0x80136FB0 |
| `SAnimator2::AlignCensorToCamera(EVec3 &, EVec3 &, E3DWindow *)` | 0x8006867C |
| `SAnimator2::Render(int)` | 0x8005C78C |
| `SAnimator2::ResetCensorship(void)` | 0x8005F4E0 |
| `SAnimator2::ResetSuits(void)` | 0x8005D120 |
| `SAnimator2::SetAnimDisplacements(float, float, float)` | 0x8005E7C8 |
| `SAnimator2::SetPixelated(int)` | 0x8005F4E4 |
| `SAnimatorNullFunc(...)` | 0x8005BD68 |
| `SCREENSHOTService` | 0x80351E10 |
| `SetUIStatusTextV(char *, __va_list_tag *)` | 0x800428D0 |
| `SimsMemCardWrap::XboxOnNoMemory(void)` | 0x800756B8 |
| `Slot::WriteSlot(SlotDescriptor *)` | 0x80142990 |
| `SlotLoader::GetSlotName(Slot *, BString &, int)` | 0x801445CC |
| `StateMachine::Reset(void)` | 0x80096B20 |
| `StateMachine::Startup(void)` | 0x80096AF8 |
| `StateMachineState::Draw(ERC *)` | 0x803A02C8 |
| `StateMachineState::DrawTopmost(ERC *)` | 0x803A0250 |
| `StateMachineState::Reset(void)` | 0x803A02C0 |
| `StateMachineState::Shutdown(void)` | 0x803A02BC |
| `StateMachineState::Startup(void)` | 0x803A024C |
| `StateMachineState::Update(float)` | 0x803A02C4 |
| `StateMachineState::ValidateHeap(bool)` | 0x80095B2C |
| `THPGXYuv2RgbSetup(_GXRenderModeObj *)` | 0x803363E0 |
| `TMtraceNull(...)` | 0x8003B2AC |
| `TMtraceNull(...)` | 0x800D7C1C |
| `TTabScratchEntry::GetActivationExtents(unsigned char &, unsigned char &, unsigned char &, unsigned char &) const` | 0x80149F48 |
| `TTabScratchEntry::GetActivationSubtile(unsigned char &, unsigned char &) const` | 0x80149F40 |
| `TTabScratchEntry::SetActivationExtents(unsigned char, unsigned char, unsigned char, unsigned char)` | 0x80149F4C |
| `TTabScratchEntry::SetActivationSubtile(unsigned char, unsigned char)` | 0x80149F44 |
| `TTabScratchEntry::SetName(BString2 &)` | 0x80149F1C |
| `TTabScratchEntry::SetOrderIndex(int)` | 0x80149F30 |
| `TTabScratchEntry::SetUseCustomActivation(bool)` | 0x80149F3C |
| `TheSimsEnterMainMenuState::Draw(ERC *)` | 0x800985F8 |
| `TheSimsEnterMainMenuState::DrawTopmost(ERC *)` | 0x800985FC |
| `TheSimsEnterMainMenuState::Shutdown(void)` | 0x80097FDC |
| `TheSimsMemCardCheckState::Shutdown(void)` | 0x800970E8 |
| `TheSimsMemCardCheckState::Update(float)` | 0x800970EC |
| `TrackDataReader::Trace(void) const` | 0x8011645C |
| `TreeSimImpl::AsTreeSim(void)` | 0x801492BC |
| `TreeSimImpl::AsTreeSim(void) const` | 0x801492C0 |
| `TreeSimImpl::StackJustPopped(void)` | 0x80148818 |
| `TreeTableAdQuickData::SetMax(int)` | 0x8015E5D4 |
| `TreeTableAdQuickData::SetMin(int)` | 0x8015E5D0 |
| `TreeTableAdQuickData::SetPersonalityAd(int)` | 0x8015E5CC |
| `TreeTableAdQuickData::SetRange(int)` | 0x8015E5D8 |
| `TreeTableAdQuickData::operator=(ITreeTableAd &)` | 0x8015E5C8 |
| `TreeTableEntryQuickData::SetActionTreeID(short)` | 0x8015E880 |
| `TreeTableEntryQuickData::SetActivationExtents(unsigned char, unsigned char, unsigned char, unsigned char)` | 0x8015E8A0 |
| `TreeTableEntryQuickData::SetActivationSubtile(unsigned char, unsigned char)` | 0x8015E89C |
| `TreeTableEntryQuickData::SetAd(int, ITreeTableAd &)` | 0x8015E87C |
| `TreeTableEntryQuickData::SetAllowConsecutive(bool)` | 0x8015E84C |
| `TreeTableEntryQuickData::SetAttenuation(ITreeTableEntry::Attenuation)` | 0x8015E888 |
| `TreeTableEntryQuickData::SetAutoFirstSelect(bool)` | 0x8015E864 |
| `TreeTableEntryQuickData::SetAutonomyThreshold(short)` | 0x8015E890 |
| `TreeTableEntryQuickData::SetAvailableToAdults(bool)` | 0x8015E854 |
| `TreeTableEntryQuickData::SetAvailableToChildrenDemo(bool)` | 0x8015E858 |
| `TreeTableEntryQuickData::SetAvailableToGhosts(bool)` | 0x8015E850 |
| `TreeTableEntryQuickData::SetAvailableToVisitingPlayers(bool)` | 0x8015E868 |
| `TreeTableEntryQuickData::SetAvailableToVisitors(bool)` | 0x8015E840 |
| `TreeTableEntryQuickData::SetCanJoin(bool)` | 0x8015E844 |
| `TreeTableEntryQuickData::SetCheckTreeID(short)` | 0x8015E884 |
| `TreeTableEntryQuickData::SetCustomAttenuation(float)` | 0x8015E88C |
| `TreeTableEntryQuickData::SetDebugOnly(bool)` | 0x8015E860 |
| `TreeTableEntryQuickData::SetIgnorePrefixTree(bool)` | 0x8015E86C |
| `TreeTableEntryQuickData::SetImmediate(bool)` | 0x8015E848 |
| `TreeTableEntryQuickData::SetJoinIndex(int)` | 0x8015E85C |
| `TreeTableEntryQuickData::SetMustRun(bool)` | 0x8015E870 |
| `TreeTableEntryQuickData::SetName(BString2 &)` | 0x8015E894 |
| `TreeTableEntryQuickData::SetOrderIndex(int)` | 0x8015E83C |
| `TreeTableEntryQuickData::SetUseCustomActivation(bool)` | 0x8015E898 |
| `TreeTableQuickData::SetIsTuned(bool)` | 0x8015E988 |
| `TreeTableQuickData::SetName(StringBuffer &)` | 0x8015E964 |
| `TreeTableQuickData::SetPrefixCheckTreeID(short)` | 0x8015E99C |
| `TreeTableQuickData::SwapEntries(int, int)` | 0x8015E948 |
| `UIDialog::DialogClosedCallback(void)` | 0x801E704C |
| `UIDialog::SelectionCallback(int)` | 0x801E7044 |
| `UIDialog::ZeroInputCallback(void)` | 0x801E7048 |
| `UIHDTV::UIHDTV(void)` | 0x8017B994 |
| `UIObjectBase::Draw(ERC *)` | 0x803A06B0 |
| `UIObjectBase::SetVariable(char *, char *)` | 0x803A06A0 |
| `UIObjectBase::Update(void)` | 0x803A06AC |
| `UIReflow::Debug_PrintBlock(void)` | 0x8017EDA4 |
| `UrbzCreditsState::Reset(void)` | 0x80098D2C |
| `VertexDataDeinitialization(void)` | 0x802FBA28 |
| `VertexDataInitialization(unsigned int, unsigned int, unsigned int, bool)` | 0x802FBA24 |
| `WXFTarget::Update(void)` | 0x801E62E8 |
| `WantFearManager::CaptureLog(bool)` | 0x8014BD04 |
| `Wrapper::WrapperCallFunction(char *)` | 0x80086AE8 |
| `Wrapper::WrapperRemoveMessageHandler(void)` | 0x80086988 |
| `Wrapper::WrapperReset(void)` | 0x8008698C |
| `Wrapper::WrapperRestoreMessageHandler(void)` | 0x80086984 |
| `Wrapper::WrapperUpdate(void)` | 0x80086990 |
| `WrapperPaneBase::Reset(void)` | 0x80087A64 |
| `XObjLang::GetNodeText(Behavior *, short, BehaviorNode *, StringBuffer &)` | 0x80152370 |
| `XObjLang::GetPrimName(short, StringBuffer &)` | 0x80152374 |
| `XObjLang::GetTreeTypeName(int, StringBuffer &)` | 0x8015236C |
| `XRoute::DoStream(ReconBuffer *, int)` | 0x801534C8 |
| `__ARQCallbackHack` | 0x803777DC |
| `__AXClQuit` | 0x80379204 |
| `__AXSPBQuit` | 0x80379EE4 |
| `__AXVPBQuit` | 0x8037AC20 |
| `__CARDDefaultApiCallback` | 0x8037EF30 |
| `__GXUpdateBPMask` | 0x8038F480 |
| `__empty` | 0x8024A8F8 |
| `__init_user` | 0x8023F8C4 |
| `__static_initialization_and_destruction_0` | 0x8000FDA4 |
| `__static_initialization_and_destruction_0` | 0x8023A4D4 |
| `_c2DArray::Swizzle(void *, int)` | 0x800D1B18 |
| `_freeFontTable(void)` | 0x80010078 |
| `_profileInit(void)` | 0x80268710 |
| `basic_string_ref2::throwlength(void)` | 0x800A0108 |
| `basic_string_ref2::throwrange(void)` | 0x800A010C |
| `basic_string_ref::throwlength(void)` | 0x8009BFAC |
| `basic_string_ref::throwrange(void)` | 0x8009BFB0 |
| `cBoxX::LoadQdataTables(void)` | 0x800AD898 |
| `cGZSndSys::preloadMusic(void)` | 0x800B9FB0 |
| `cGZSndSys::unloadMusic(void)` | 0x800B9FB4 |
| `cXMTObjectImpl::GetMTObjectImplementation(void)` | 0x800C7D5C |
| `cXObjectImpl::Backtrace(void)` | 0x8010D5AC |
| `cXObjectImpl::CastToObjectImpl(void)` | 0x800EAA44 |
| `cXObjectImpl::ForceLocation(void)` | 0x800DF224 |
| `cXObjectImpl::GetObjectImplementation(void)` | 0x800EB8DC |
| `cXObjectImpl::PreSave(void)` | 0x800DB168 |
| `cXObjectImpl::SetObjectProbe(ObjectProbe *)` | 0x800EAF34 |
| `cXPerson::CastToPerson(void)` | 0x8012C694 |
| `cXPersonImpl::CastToPersonImpl(void)` | 0x8012C6DC |
| `cXPersonImpl::ClearRecording(void)` | 0x8012B5DC |
| `cXPersonImpl::DebugDumpHappyScape(void)` | 0x801264C4 |
| `cXPersonImpl::GetJobSuitTex(StringBuffer &, StringBuffer &, StringBuffer &)` | 0x8012B5F0 |
| `cXPersonImpl::GetPersonImplementation(void)` | 0x8012C6E0 |
| `cXPersonImpl::LogEvent(char *, char *, char *)` | 0x8012B5E8 |
| `cXPersonImpl::StartRecording(int, int)` | 0x8012B5D4 |
| `cXPersonImpl::StopRecording(void)` | 0x8012B5D8 |
| `cXPersonImpl::Track(void)` | 0x8012B5EC |
| `cXPortalImpl::GetPortalImplementation(void)` | 0x8013280C |
| `command(char *, char *)` | 0x800065F0 |
| `debugAddSavedInput(AptSavedInputRecord *, int)` | 0x80006B78 |
| `debugSetScreenGrabPending(char *)` | 0x80006B74 |
| `defaultOptionalCommandChecker` | 0x8025C298 |
| `freeRenderingUnit(void *)` | 0x8000744C |
| `freeSound(void *)` | 0x8000742C |
| `getRealTimeClock(AptSysClock *, bool)` | 0x800067D4 |
| `hardwareInit(float, float)` | 0x80009420 |
| `myassert(char *, char *, unsigned int)` | 0x80007434 |
| `operator<<(CTGDump &, CTilePt &)` | 0x800B4DFC |
| `operator>>(EStream &, ESubModel &)` | 0x802FAE28 |
| `sendVariables(char *, char *, char *, char *, int)` | 0x800067C8 |
| `setBackgroundColour(unsigned int)` | 0x80007430 |
| `startSound(void *, char *)` | 0x80007428 |
| `startSoundStream(void *, int)` | 0x80007424 |

</details>

Plus **1 tail-call** functions (single `b` instruction).

### Tier 2: TRIVIAL -- Getters (8 bytes, X+blr)

**1165 functions** -- One instruction + blr. All trivial one-line return statements.

#### Return Constant (426 functions)

Pattern: `li r3, N; blr` -- C++: `return N;`

<details>
<summary>All 426 return-constant functions</summary>

| Function | Address | Returns |
|----------|---------|--------:|
| `ACTTarget::IsActionQueueAvailable(int) const` | 0x801A2B34 | 1 |
| `AMC_IsStub` | 0x80267890 | 1 |
| `ARGetBaseAddress` | 0x80375A5C | 16384 |
| `AnimTableImpl::GetEntryName(int)` | 0x800AAC2C | 0 |
| `AptAnimationPoolData::validateBIL(void)` | 0x8029E1F0 | 1 |
| `AptIsMouseOverButton(void)` | 0x8026B82C | 0 |
| `AptScriptFunctionByteCodeBlock::Duplicate(AptCIH *)` | 0x802B91BC | 0 |
| `AptScriptFunctionByteCodeBlock::GetNumArguments(void)` | 0x802B9188 | 0 |
| `AptTextFormat::operator new [](unsigned int)` | 0x802AFFF8 | 0 |
| `AptValue::ContainsNativeHashVirtual(void) const` | 0x802B4250 | 0 |
| `AptValue::GetNativeHashVirtual(void)` | 0x802B4248 | 0 |
| `AptValue::getHasClass(void) const` | 0x802B4258 | 0 |
| `AptValue::objectMemberLookup(AptValue *, EAStringC *) const` | 0x802B4264 | 0 |
| `AptValue::objectMemberSet(AptValue *, EAStringC *, AptValue *)` | 0x802B426C | 0 |
| `AptValueGC::IsGarbageCollected(void) const` | 0x80281D1C | 1 |
| `AptValueGC::IsGarbageCollected(void) const` | 0x80287DD0 | 1 |
| `AptValueGC::IsGarbageCollected(void) const` | 0x8028F9AC | 1 |
| `AptValueGC::IsGarbageCollected(void) const` | 0x802938B8 | 1 |
| `AptValueGC::IsGarbageCollected(void) const` | 0x80298BC0 | 1 |
| `AptValueGC::IsGarbageCollected(void) const` | 0x802A865C | 1 |
| `AptValueGC::IsGarbageCollected(void) const` | 0x802ABDC4 | 1 |
| `AptValueGC::IsGarbageCollected(void) const` | 0x802AEC34 | 1 |
| `AptValueGC::IsGarbageCollected(void) const` | 0x802AFC0C | 1 |
| `AptValueGC::IsGarbageCollected(void) const` | 0x802B42E8 | 1 |
| `AptValueGC::IsGarbageCollected(void) const` | 0x802B5C24 | 1 |
| `AptValueGC::IsGarbageCollected(void) const` | 0x802B6100 | 1 |
| `AptValueGC::IsGarbageCollected(void) const` | 0x802B78B0 | 1 |
| `AptValueGC::IsGarbageCollected(void) const` | 0x802B87FC | 1 |
| `AptValueGC::IsGarbageCollected(void) const` | 0x802BA21C | 1 |
| `AptValueGC::IsGarbageCollected(void) const` | 0x802BB634 | 1 |
| `AptValueGC::IsGarbageCollected(void) const` | 0x802C4F7C | 1 |
| `AptValueNoGC::IsGarbageCollected(void) const` | 0x80281D24 | 0 |
| `AptValueNoGC::IsGarbageCollected(void) const` | 0x802AEC3C | 0 |
| `AptValueNoGC::IsGarbageCollected(void) const` | 0x802B42F0 | 0 |
| `AptValueNoGC::IsGarbageCollected(void) const` | 0x802BB8D4 | 0 |
| `AptValueNoGC::IsGarbageCollected(void) const` | 0x802BBB84 | 0 |
| `AptValueNoGC::IsGarbageCollected(void) const` | 0x802BBE40 | 0 |
| `AptValueWithHash::ContainsNativeHashVirtual(void) const` | 0x802B4178 | 1 |
| `AptViewer::ReadController(int, bool, int, bool)` | 0x80010D68 | 0 |
| `AptViewer::UIOn(void)` | 0x80011E14 | 1 |
| `AptXmlAttributes::operator new [](unsigned int)` | 0x802C4FDC | 0 |
| `AptXmlNode::operator new [](unsigned int)` | 0x802BB694 | 0 |
| `BBI::InventoryItems::GetContainerSize(void) const` | 0x8004AA5C | 36 |
| `BString2::eos(void)` | 0x800A0C70 | 0 |
| `BString::eos(void)` | 0x8009CAD8 | 0 |
| `BeingReset(void)` | 0x8014160C | 0 |
| `CDirtyXml::contentType(void)` | 0x8023AF78 | 0 |
| `CDirtyXml::createElement(char *)` | 0x8023AF84 | 0 |
| `CDirtyXml::createTextNode(char *)` | 0x8023AF8C | 0 |
| `CDirtyXml::docTypeDecl(void)` | 0x8023AF94 | 0 |
| `CDirtyXml::getBytesLoaded(void)` | 0x8023AFA8 | 0 |
| `CDirtyXml::getBytesTotal(void)` | 0x8023AFA0 | 0 |
| `CDirtyXml::isIgnoreWhite(void)` | 0x8023AFB4 | 1 |
| `CDirtyXml::isLoaded(void)` | 0x8023AFC0 | 1 |
| `CDirtyXml::status(void)` | 0x8023B058 | 1 |
| `CDirtyXmlNode::toString(void)` | 0x8023AC3C | 0 |
| `CTGFileImpl::Flush(void)` | 0x8007CFC4 | 0 |
| `CTGFileImpl::FlushCache(void)` | 0x8007CFCC | 1 |
| `CTGFileImpl::IsWritable(void)` | 0x8007CEE8 | 0 |
| `CTGFileImpl::SetSize(int)` | 0x8007CFBC | 0 |
| `CTGFileImpl::Write(void *, int)` | 0x8007CF28 | 0 |
| `CTGFileManager::CopyFile(char *, char *)` | 0x8007D4DC | 1 |
| `CTGFileManager::CreateFile(char *)` | 0x8007D4C4 | 1 |
| `CTGFileManager::DeleteFile(char *)` | 0x8007D4CC | 1 |
| `CTGFileManager::Init(void)` | 0x8007D37C | 1 |
| `CTGFileManager::MoveFile(char *, char *)` | 0x8007D4D4 | 1 |
| `CUnlockDisplayObjectSim::IsAdult(void)` | 0x80079F84 | 1 |
| `CasScene::GetRoomFromCameraAngle(unsigned int) const` | 0x801672C0 | 0 |
| `CasSceneGamecube::GetRoomFromCameraAngle(unsigned int) const` | 0x80175784 | 0 |
| `CasScenePersonal::GetRoomFromCameraAngle(unsigned int) const` | 0x8017592C | 0 |
| `Commander::DoCommand(short, int)` | 0x800B42B4 | 0 |
| `DMAHeapFreeMemory(EA::Allocator::GeneralAllocator *, unsigned int, unsigned int, void *)` | 0x803278EC | 0 |
| `DVDCloseDir` | 0x8025BF84 | 1 |
| `DumpObjectFolder(char *)` | 0x801D1A08 | 0 |
| `EA::Allocator::GeneralAllocator::ChunkMatchesLowHigh(int, EA::Allocator::GeneralAllocator::Chunk *, unsigned int) const` | 0x802D93A8 | 1 |
| `EA::Allocator::GeneralAllocator::GetPageSize(void)` | 0x802D8FA8 | 4096 |
| `EAStringC::FindOneOf(char *) const` | 0x802BCC90 | 0 |
| `EAStringC::Insert(int, char *)` | 0x802BCE38 | 0 |
| `EAStringC::Insert(int, char)` | 0x802BCE40 | 0 |
| `EAStringC::ReverseFind(char) const` | 0x802BCC98 | 0 |
| `EAmbientScoreManager::CanCache(EResource *)` | 0x80322CC4 | 1 |
| `EAnimManager::CanCache(EResource *)` | 0x80322E48 | 1 |
| `EApp::GetEventTableSize(void)` | 0x802E2944 | 8 |
| `EApp::GetPrefetchBlockSize(void)` | 0x802E2934 | 0 |
| `EApp::GetScratchBuffSize(void)` | 0x802E293C | 0 |
| `EAudioSampleManager::CanCache(EResource *)` | 0x8032D98C | 1 |
| `ECharacterManager::CanCache(EResource *)` | 0x8032333C | 1 |
| `EController::HasVibration(void) const` | 0x80304434 | 0 |
| `EControllerManager::GetControllerCount(void)` | 0x80323AF0 | 4 |
| `EDatasetManager::CanCache(EResource *)` | 0x8032494C | 1 |
| `EDummyFile::Flush(void)` | 0x800226A8 | 1 |
| `EDummyFile::GetLastError(void) const` | 0x800226B0 | 0 |
| `EDummyFile::GetSystemHandle(void) const` | 0x800226B8 | 0 |
| `EEdithTreeSetMan::CanCache(EResource *)` | 0x80324B74 | 1 |
| `EEngine::ManagedStartup(void)` | 0x802E38E8 | 1 |
| `EFenceWall::IsWallsOpaque(int)` | 0x8039E4B0 | 0 |
| `EFile::Allocate(unsigned int &)` | 0x802C6904 | 0 |
| `EFileSystem::HDDIsUnformatted(void)` | 0x802C7110 | 0 |
| `EFileSystem::InitHDD(bool, char *)` | 0x802C70B4 | 0 |
| `EFileSystem::InitHDDFileSystem(void)` | 0x802C70AC | 1 |
| `EFlashManager::CanCache(EResource *)` | 0x80324D00 | 1 |
| `EGameState::InTransportMode(void)` | 0x80089E20 | 0 |
| `EGlobal::GetNameFromProp(PropRef *)` | 0x80042284 | 0 |
| `EGlobal::GetPropFromName(char *)` | 0x8004227C | 0 |
| `EGlobal::GetSkillFromName(char *)` | 0x8004219C | 0 |
| `EGlobal::IsBuildHouseMode(void)` | 0x800420AC | 0 |
| `EGlobalManagerClient::ManagedStartup(void)` | 0x803C1CF0 | 1 |
| `EGraphics::GetDepthBufferTexture(void)` | 0x802F21CC | 0 |
| `EGraphics::GetFrameBufferTexture(int)` | 0x802F21C4 | 0 |
| `EGraphics::GetLargestAvailableTextureMemoryBlock(void)` | 0x802F21F4 | -1 |
| `EGraphics::GetMaxTextureXSize(void)` | 0x802F22F8 | 1024 |
| `EGraphics::GetMaxTextureYSize(void)` | 0x802F2300 | 1024 |
| `EGraphics::ManagedStartup(void)` | 0x802F2360 | 1 |
| `EGraphics::NeedFlushToDestroy(EDL *)` | 0x802F21D4 | 1 |
| `EGraphics::NeedFlushToDestroy(EMovie *)` | 0x802F21EC | 1 |
| `EGraphics::NeedFlushToDestroy(ERenderSurface *)` | 0x802F21E4 | 1 |
| `EGraphics::NeedFlushToDestroy(EShader *)` | 0x802F21FC | 1 |
| `EGraphics::NeedFlushToDestroy(ETexture *)` | 0x802F21DC | 1 |
| `EIAmbLight::GetLightType(void)` | 0x80226FD8 | 1 |
| `EIDirLight::GetLightType(void)` | 0x802274D4 | 2 |
| `EIFenceWall::IsOpaque(void)` | 0x80030898 | 0 |
| `EILight::GetLightType(void)` | 0x802280D0 | 0 |
| `EIPointLight::GetLightType(void)` | 0x8022A61C | 3 |
| `EIPortalPointLight::GetLightType(void)` | 0x8022B0F4 | 4 |
| `EIPortalPointLight::IsPointLight(void)` | 0x8022B104 | 1 |
| `EInstance::CanReloadInstanceData(void)` | 0x8022966C | 0 |
| `EInstance::GetModifiableColor(unsigned int)` | 0x802296F0 | 0 |
| `EInstance::GetNumRoomID(void)` | 0x80229680 | 0 |
| `EInstance::GetRoomID(unsigned int)` | 0x80229688 | 0 |
| `EInstance::GetUpdatePriority(void)` | 0x802294A0 | 50 |
| `EInstance::HasModifiableColor(void)` | 0x802296E4 | 0 |
| `EInstance::VisibilityTest(E3DWindow &)` | 0x8022946C | 1 |
| `EMemoryBufferWriteStream::Read(void *, int)` | 0x802E0EF0 | 0 |
| `EMemoryCard::CloseForIO(char *, unsigned int)` | 0x803C76A4 | 1 |
| `EMemoryCard::CreateFileS(char *, unsigned int, unsigned int)` | 0x803C76C4 | 1 |
| `EMemoryCard::GetFileRefCount(char *, unsigned int)` | 0x803C76AC | 0 |
| `EMemoryCard::IsPolledCardAvailable(unsigned int)` | 0x803C76D8 | 1 |
| `EMemoryCard::IsWrongDevice(unsigned int)` | 0x803C76E0 | 0 |
| `EMemoryCard::LoadDataChunkS(char *, unsigned int, unsigned int, unsigned int, void *)` | 0x803C76B4 | 1 |
| `EMemoryCard::OpenForIO(char *, unsigned int)` | 0x803C769C | 1 |
| `EMemoryCard::PollCards(bool)` | 0x803C76D0 | 1 |
| `EMemoryCard::SaveDataChunkS(char *, unsigned int, unsigned int, unsigned int, void *)` | 0x803C76BC | 1 |
| `EMemoryReadStream::Write(void *, int)` | 0x802E0EBC | 0 |
| `EMemoryWriteStream::Read(void *, int)` | 0x802E0F00 | 0 |
| `EModelManager::CanCache(EResource *)` | 0x80324FF8 | 1 |
| `EMovie::IsFinished(void)` | 0x80364CE8 | 1 |
| `EMovie::Load(EFile *, unsigned int, unsigned int, unsigned int)` | 0x80364CCC | 0 |
| `ENgcAudio::GetIndexFromVoice(EVoice *)` | 0x8032BEDC | 0 |
| `ENgcAudio::GetVoiceFromIndex(unsigned char)` | 0x8032BEE4 | 0 |
| `ENgcController::HasVibration(void) const` | 0x803C711C | 1 |
| `ENgcFile::Flush(void)` | 0x802E1BE4 | 1 |
| `ENgcFile::GetLastError(void) const` | 0x802E1BEC | 0 |
| `ENgcFile::Write(void *, unsigned int)` | 0x802E1B78 | 0 |
| `ENgcMemoryCard::CloseForIO(char *, unsigned int)` | 0x80330D78 | 1 |
| `ENgcMemoryCard::DeleteDataA(char *, unsigned int, unsigned int, EMC_Operation *)` | 0x803332F8 | 0 |
| `ENgcMemoryCard::FormatCardA(unsigned int, EMC_Operation *)` | 0x80333300 | 0 |
| `ENgcMemoryCard::GetFileListA(unsigned int, char *, unsigned int, char (*)[31], EMC_Operation *)` | 0x80334888 | 1 |
| `ENgcMemoryCard::LoadDataA(char *, unsigned int, unsigned int, void *, EMC_Operation *)` | 0x803332E8 | 0 |
| `ENgcMemoryCard::OpenForIO(char *, unsigned int)` | 0x80330D70 | 1 |
| `ENgcMemoryCard::SaveDataA(char *, unsigned int, unsigned int, void *, EMC_Operation *)` | 0x803332F0 | 0 |
| `ENgcMemoryCard::UnFormatCardA(unsigned int, EMC_Operation *)` | 0x80333308 | 0 |
| `ENgcMemoryCard::UnFormatCardS(unsigned int)` | 0x803332E0 | 0 |
| `ENgcMemoryCard::UnInitMemoryCard(void)` | 0x803301BC | 1 |
| `ENgcMemoryCard::UpdateOperation(EMC_Operation, bool &)` | 0x80333310 | 0 |
| `ENgcSNFile::Flush(void)` | 0x802D8088 | 1 |
| `ENgcSNFile::GetLastError(void) const` | 0x802D8090 | 0 |
| `ENgcScheduler::GetLastRetraceCount(void)` | 0x8034D9E8 | 1 |
| `ENgcTextureBase::GetTEVStageCount(void)` | 0x80350470 | 1 |
| `ENgcTextureBase::GetTEXCount(void)` | 0x80350478 | 1 |
| `ENgcTextureC4_32::GetTEVStageCount(void)` | 0x80350C10 | 2 |
| `ENgcTextureC4_32::GetTEXCount(void)` | 0x80350C18 | 2 |
| `ENgcTextureC8_32::GetTEVStageCount(void)` | 0x80351420 | 2 |
| `ENgcTextureC8_32::GetTEXCount(void)` | 0x80351428 | 2 |
| `EQuickdataManager::CanCache(EResource *)` | 0x80325580 | 1 |
| `ERC::AllocVertexData(unsigned int)` | 0x802F9B0C | 0 |
| `ERC::ParticleListBegin(unsigned int, unsigned int)` | 0x802F706C | 0 |
| `ERenderer::GetCurrentTexture(int)` | 0x80364DA4 | 0 |
| `EResPrefetchFile::Flush(void)` | 0x803131B0 | 1 |
| `EResPrefetchFile::GetLastError(void) const` | 0x803131B8 | 0 |
| `EResPrefetchFile::GetSystemHandle(void) const` | 0x803131C0 | 0 |
| `EResPrefetchFile::Write(void *, unsigned int)` | 0x803131A8 | 0 |
| `EResource::GetCheckPoint(void)` | 0x803122BC | 0 |
| `EResource::IsSafeToDelete(void)` | 0x8031226C | 1 |
| `EResource::TryIncrementSubResources(void)` | 0x80312348 | 1 |
| `EResourceManager::CanCache(void)` | 0x80327ED4 | 0 |
| `EResourceManager::GetOverriddenFile(unsigned int, unsigned int &)` | 0x803276FC | 0 |
| `ESemaphore::GetObject(int)` | 0x802D7854 | 0 |
| `EShaderManager::CanCache(EResource *)` | 0x80328314 | 1 |
| `ESimsApp::GetDefaultLanguage(void)` | 0x800044C0 | 0 |
| `ESimsApp::GetEventTableSize(void)` | 0x8000638C | 0 |
| `ESoundEventManager::CanCache(EResource *)` | 0x80328498 | 1 |
| `ESoundTrackDataManager::CanCache(EResource *)` | 0x803285F8 | 1 |
| `EStream::GetFile(void)` | 0x802D21F8 | 0 |
| `ESubModel::GetCompositeShaderFlags(void)` | 0x802FAE20 | 0 |
| `ETexture::Lock(void)` | 0x80365120 | 1 |
| `ETexture::UpdateMipLevel(int, int &, int &)` | 0x80365134 | 0 |
| `ETexture::UpdatePalette(void)` | 0x8036513C | 0 |
| `ETextureManager::CanCache(EResource *)` | 0x80328790 | 1 |
| `EThread::GetStackUsage(void)` | 0x802E17F8 | 0 |
| `EVibrate::UpdateVibration(void)` | 0x8030833C | 1 |
| `EWindow::Cast3DWindow(void)` | 0x80300B04 | 0 |
| `EXI2_Poll` | 0x80267870 | 0 |
| `EXI2_ReadN` | 0x80267878 | 0 |
| `EXI2_WriteN` | 0x80267880 | 0 |
| `Effects::EffectsManager::CreateEffect(REffectsSequencer &, Effects::Effect::ClientParams *)` | 0x80352710 | 0 |
| `Effects::EffectsManager::Shutdown(void)` | 0x803523C8 | 1 |
| `Effects::FastParticleEmitter::GetTotalPacketsInPool(void)` | 0x803549E0 | 0 |
| `Effects::GetDefaultRenderContext(void)` | 0x8035220C | 0 |
| `EffectsAttachmentManager::CanCache(EResource *)` | 0x803288F8 | 1 |
| `EffectsAttachmentManager::GetRow(int)` | 0x80328844 | 0 |
| `EffectsPreRenderVisitor::Visit(Effects::Effect &)` | 0x8003E188 | 1 |
| `EffectsPreRenderVisitor::Visit(Effects::EffectsSequencer &)` | 0x8003E190 | 1 |
| `Emitter::VisibilityTest(E3DWindow &)` | 0x802389D4 | 0 |
| `EyeToyClient::GetFilterCount(void)` | 0x80038CE0 | 5 |
| `EyeToyClient::GetFunframeCount(void)` | 0x80038CD8 | 12 |
| `EyeToyClient::GetTargetSlotCount(void)` | 0x80038CE8 | 5 |
| `EyeToyManager::GetPhysicalConnectionCount(void)` | 0x80328CDC | 0 |
| `EyeToyManager::IsPhysicallyConnected(int)` | 0x80328CD4 | 0 |
| `FamilyImpl::GetGoalAndUnlockData(void)` | 0x800B6C90 | 0 |
| `FamilyImpl::GetInventory(void)` | 0x800B6C88 | 0 |
| `FamilyImpl::GetStatRef(int, short **)` | 0x800B6CA0 | 0 |
| `FamilyImpl::GetStatValue(int) const` | 0x800B6C98 | 0 |
| `FamilyImpl::MyDoCommand(short, int)` | 0x800B6810 | 0 |
| `FloatConstantsQuickData::GetDataSourceType(void) const` | 0x800B7174 | 1 |
| `FloatConstantsQuickData::GetResourceName(StringBuffer &) const` | 0x800B71F4 | 0 |
| `FloatConstantsQuickData::LoadFromIndex(unsigned int, int)` | 0x800B71EC | 0 |
| `FloatConstantsQuickData::LoadOnlyNameAndIDFromIndex(unsigned int, int)` | 0x800B7204 | 0 |
| `FloatConstantsQuickData::SaveDataByID(ObjectDataID &)` | 0x800B70FC | 0 |
| `FloatConstantsQuickData::SetResourceName(StringBuffer &)` | 0x800B71FC | 0 |
| `GameTime::CountDaysInMonth(int, int)` | 0x80147088 | 30 |
| `GameTime::CountDaysInYear(int)` | 0x80147090 | 360 |
| `GetSpaceRequiredForPs2HDDSave(void)` | 0x80075B08 | 0 |
| `GetUIStatusText(void)` | 0x80042920 | 0 |
| `IFFBehaviorConstants::GetDataSourceType(void) const` | 0x8015A8A8 | 2 |
| `IFFBehaviorTree::GetDataSourceType(void) const` | 0x8015B9A4 | 2 |
| `IFFSlotDescList::GetDataSourceType(void) const` | 0x801452B8 | 2 |
| `IFFSlotDescList::GetStringSetID(void) const` | 0x801452AC | 0 |
| `ISimInstance::GetShadow(void)` | 0x80056344 | 0 |
| `ISimInstance::IsMultiTilePart(void)` | 0x80056A08 | 0 |
| `InfluenceMap::ValidateMissing(cXObject *)` | 0x800492E0 | 1 |
| `InitHeap` | 0x802E3A34 | 1 |
| `Interaction::SetShader(EActionIcon *) const` | 0x800C2000 | 0 |
| `InteractorModule::Interactor::ChooseAction(Interaction *)` | 0x8020951C | 0 |
| `InteractorModule::InteractorVisualizer::CreateResources(InteractorModule::DirectInteractor &)` | 0x80217130 | 1 |
| `InteractorModule::InteractorVisualizer::CreateResources(InteractorModule::SocialModeInteractor &)` | 0x8021728C | 1 |
| `InteractorModule::InteractorVisualizer::DestroyResources(InteractorModule::DirectInteractor &)` | 0x80217138 | 1 |
| `InteractorModule::InteractorVisualizer::DestroyResources(InteractorModule::SocialModeInteractor &)` | 0x80217294 | 1 |
| `InvalidatePS2SavedGame(int)` | 0x80074E20 | 1 |
| `IsObjectLockedByGUID(int, int)` | 0x801ECCB8 | 0 |
| `Language::GetSwizzler(void)` | 0x803A2B98 | 0 |
| `Language::IsSingleExit(BehaviorNode *)` | 0x803A2B90 | 0 |
| `M2MTarget::IsItemEnabledSaveGameSelect(int)` | 0x801C1D00 | 0 |
| `NGCGetLanguage(void)` | 0x80006024 | 0 |
| `Neighbor::GetLatestPersDataVersion(void)` | 0x800C9794 | 8 |
| `NeighborhoodImpl::GetHouseNumberForLevel(int)` | 0x800CDD38 | 0 |
| `NghResFile::Close(void)` | 0x800D3BD8 | 0 |
| `NghResFile::CloseForReopen(void)` | 0x800D3BC8 | 0 |
| `NghResFile::CountTypes(void)` | 0x800D3C20 | 0 |
| `NghResFile::Delete(StringBuffer &)` | 0x800D3BB8 | 0 |
| `NghResFile::FindUniqueID(int)` | 0x800D3D60 | 0 |
| `NghResFile::GetByName(int, StringBuffer &, void (*)(void *, int))` | 0x800D3CC8 | 0 |
| `NghResFile::GetIndType(short)` | 0x800D3C28 | 0 |
| `NghResFile::GetResType(Memory::HandleNode *)` | 0x800D3D40 | 0 |
| `NghResFile::IsLittleEndian(Memory::HandleNode *)` | 0x800D3D70 | 1 |
| `NghResFile::Open(StringBuffer &)` | 0x800D3BC0 | 0 |
| `NghResFile::Reopen(void)` | 0x800D3BD0 | 0 |
| `NghResFile::ValidFile(void)` | 0x800D3C18 | 1 |
| `NghResFile::Writable(void)` | 0x800D3BE4 | 0 |
| `ObjFnTableQuickData::GetDataSourceType(void) const` | 0x8010FFCC | 1 |
| `ObjFnTableQuickData::GetResourceName(StringBuffer &) const` | 0x80110240 | 0 |
| `ObjFnTableQuickData::LoadFromIndex(unsigned int, int)` | 0x80110330 | 0 |
| `ObjFnTableQuickData::LoadOnlyNameAndIDFromIndex(unsigned int, int)` | 0x80110338 | 0 |
| `ObjFnTableQuickData::SaveDataByID(ObjectDataID &)` | 0x80110238 | 0 |
| `ObjFnTableQuickData::SetResourceName(StringBuffer &)` | 0x80110248 | 0 |
| `ObjectDataBehaviorConstants::SetResourceName(StringBuffer &)` | 0x80159DDC | 0 |
| `ObjectDataFactoryDatabase<FloatConstants>::GetDataSourceType(void) const` | 0x803AECB8 | 4 |
| `ObjectDataFactoryDatabase<FloatConstants>::operator()(void) const` | 0x8015BAB4 | 0 |
| `ObjectDataFactoryDatabase<ITreeTable>::GetDataSourceType(void) const` | 0x803AEC88 | 4 |
| `ObjectDataFactoryDatabase<ITreeTable>::operator()(void) const` | 0x8015BAEC | 0 |
| `ObjectDataFactoryDatabase<ObjFnTable>::GetDataSourceType(void) const` | 0x803AECA0 | 4 |
| `ObjectDataFactoryDatabase<ObjFnTable>::operator()(void) const` | 0x8015BA84 | 0 |
| `ObjectDataFactoryDatabase<StringSet>::GetDataSourceType(void) const` | 0x803AECD0 | 4 |
| `ObjectDataFactoryDatabase<StringSet>::operator()(void) const` | 0x8015BA54 | 0 |
| `ObjectDataFactoryIFF<FloatConstants>::GetDataSourceType(void) const` | 0x803AECC0 | 2 |
| `ObjectDataFactoryIFF<FloatConstants>::operator()(void) const` | 0x8015BAAC | 0 |
| `ObjectDataFactoryIFF<ITreeTable>::GetDataSourceType(void) const` | 0x803AEC90 | 2 |
| `ObjectDataFactoryIFF<ITreeTable>::operator()(void) const` | 0x8015BAE4 | 0 |
| `ObjectDataFactoryIFF<ObjFnTable>::GetDataSourceType(void) const` | 0x803AECA8 | 2 |
| `ObjectDataFactoryIFF<ObjFnTable>::operator()(void) const` | 0x8015BA7C | 0 |
| `ObjectDataFactoryIFF<StringSet>::GetDataSourceType(void) const` | 0x803AECD8 | 2 |
| `ObjectDataFactoryIFF<StringSet>::operator()(void) const` | 0x8015BA4C | 0 |
| `ObjectDataFactoryQuickData<FloatConstants>::GetDataSourceType(void) const` | 0x803AECC8 | 1 |
| `ObjectDataFactoryQuickData<ITreeTable>::GetDataSourceType(void) const` | 0x803AEC98 | 1 |
| `ObjectDataFactoryQuickData<ObjFnTable>::GetDataSourceType(void) const` | 0x803AECB0 | 1 |
| `ObjectDataFactoryQuickData<StringSet>::GetDataSourceType(void) const` | 0x803AECE0 | 1 |
| `ObjectDataObjDefinition::LoadFromDBByID(unsigned int, short)` | 0x8015C6F8 | 0 |
| `ObjectDataObjDefinition::SaveToDB(unsigned int, short, StringBuffer &)` | 0x8015C700 | 0 |
| `ObjectDataObjDefinition::SetResDataName(unsigned int, short, char *)` | 0x8015C110 | 0 |
| `ObjectFolderImpl::DoCommand(short, int)` | 0x800F17A0 | 1 |
| `ObjectFolderImpl::IsBehaviorWriteable(unsigned int)` | 0x800F207C | 0 |
| `ObjectFolderImpl::IsNamespaceWriteable(unsigned int)` | 0x800F2074 | 0 |
| `OptionsRecon::ReadFromMemoryCard(char *, unsigned char)` | 0x80058E54 | 0 |
| `OptionsRecon::WriteToMemoryCard(char *, unsigned char)` | 0x80058D24 | 0 |
| `PCTTarget::get_motive_rating_label(unsigned int, unsigned wchar_t *) const` | 0x801D613C | 1 |
| `PCTTarget::refresh_text_field(char *, unsigned int)` | 0x801D61AC | 1 |
| `PCTTarget::set_control_visible(char *, bool)` | 0x801D61B4 | 1 |
| `PCwriteAsyncInit` | 0x8023FA20 | -1 |
| `ParticleManager::CanCache(EResource *)` | 0x8032B714 | 1 |
| `PassiveInfluenceMap::ValidateMissing(PassiveInfluenceItem *)` | 0x80113DA8 | 1 |
| `PassiveInfluenceObject::GetType(void)` | 0x803A8CB8 | 1 |
| `PassiveInfluencePerson::GetType(void)` | 0x803A8B50 | 0 |
| `PassiveInfluenceTarget::GetType(void)` | 0x803A8EEC | 2 |
| `PropTableImpl::GetEntryName(int)` | 0x801329AC | 0 |
| `QuickDataBehaviorConstants::GetDataSourceType(void) const` | 0x8015A7F8 | 1 |
| `QuickDataBehaviorConstants::LoadOnlyNameAndIDFromIndex(unsigned int, int)` | 0x8015A800 | 0 |
| `QuickDataBehaviorConstants::SaveDataByID(ObjectDataID &)` | 0x8015A7F0 | 0 |
| `QuickDataSlotDescList::AddSlot(SlotDescriptor &)` | 0x8014512C | 0 |
| `QuickDataSlotDescList::GetDataSourceType(void) const` | 0x80145178 | 1 |
| `QuickDataSlotDescList::GetStringSetID(void) const` | 0x80145164 | 0 |
| `QuickDataSlotDescList::LoadOnlyNameAndIDFromIndex(unsigned int, int)` | 0x80145180 | 0 |
| `QuickDataSlotDescList::RemoveSlot(int)` | 0x80145134 | 0 |
| `QuickDataSlotDescList::SaveDataByID(ObjectDataID &)` | 0x80145170 | 0 |
| `QuickDataSoundInfo::GetDataSourceType(void) const` | 0x80145944 | 1 |
| `QuickDataSoundInfo::LoadFromIndex(unsigned int, int)` | 0x80145934 | 0 |
| `QuickDataSoundInfo::LoadOnlyNameAndIDFromIndex(unsigned int, int)` | 0x8014594C | 0 |
| `QuickDataSoundInfo::SaveDataByID(ObjectDataID &)` | 0x8014593C | 0 |
| `QuickResFile::Close(void)` | 0x80132AB4 | 0 |
| `QuickResFile::CloseForReopen(void)` | 0x80132AA4 | 0 |
| `QuickResFile::Count(int)` | 0x80132B98 | 0 |
| `QuickResFile::CountTypes(void)` | 0x80132B88 | 0 |
| `QuickResFile::Create(StringBuffer &)` | 0x80132A54 | -95 |
| `QuickResFile::Delete(StringBuffer &)` | 0x80132A5C | -95 |
| `QuickResFile::FindUniqueID(int)` | 0x80132C30 | 0 |
| `QuickResFile::GetByID(int, short, void (*)(void *, int))` | 0x80132BA0 | 0 |
| `QuickResFile::GetByIDAndLanguage(int, short, char, void (*)(void *, int))` | 0x80132BB8 | 0 |
| `QuickResFile::GetByIndex(int, short, void (*)(void *, int))` | 0x80132BB0 | 0 |
| `QuickResFile::GetByName(int, StringBuffer &, void (*)(void *, int))` | 0x80132BA8 | 0 |
| `QuickResFile::GetIndType(short)` | 0x80132B90 | 0 |
| `QuickResFile::GetLanguage(Memory::HandleNode *)` | 0x80132C04 | 0 |
| `QuickResFile::GetResType(Memory::HandleNode *)` | 0x80132BE4 | 0 |
| `QuickResFile::IsLittleEndian(Memory::HandleNode *)` | 0x80132C40 | 0 |
| `QuickResFile::Reopen(void)` | 0x80132AAC | 0 |
| `QuickResFile::Writable(void)` | 0x80132AC0 | 0 |
| `QuickStringSet::GetDataSourceType(void) const` | 0x800A7CC4 | 1 |
| `QuickStringSet::GetDescription(int, char)` | 0x800A7778 | 0 |
| `QuickStringSet::GetResourceName(StringBuffer &) const` | 0x800A7CB4 | 0 |
| `QuickStringSet::LoadDef(bool, bool)` | 0x800A7BF8 | 0 |
| `QuickStringSet::LoadFromIndex(unsigned int, int)` | 0x800A7CA4 | 0 |
| `QuickStringSet::LoadOnlyNameAndIDFromIndex(unsigned int, int)` | 0x800A7CCC | 0 |
| `QuickStringSet::Save(iResFile *, short)` | 0x800A7BF0 | 0 |
| `QuickStringSet::Save(void)` | 0x800A7C00 | 0 |
| `QuickStringSet::SaveDataByID(ObjectDataID &)` | 0x800A7CAC | 0 |
| `QuickStringSet::SetResourceName(StringBuffer &)` | 0x800A7CBC | 0 |
| `RELTarget::GetCrew(int)` | 0x802012E4 | 0 |
| `RELTarget::GetFace(int)` | 0x802012DC | 6 |
| `REffectsSequencer::TryIncrementSubResources(void)` | 0x8036AF44 | 1 |
| `ReadUARTN` | 0x80258844 | 4 |
| `RelMatrixImpl::Init(void)` | 0x80134B18 | 1 |
| `ResourceBehaviorTree::GetDataSourceType(void) const` | 0x8015B99C | 8 |
| `ResourceBehaviorTree::SaveDataByID(ObjectDataID &)` | 0x8015B06C | 0 |
| `SAnimator2::IsInterruptable(void)` | 0x8005EDB4 | 1 |
| `SAnimator2::StartParticleEffectFromEdithPrimitive(unsigned int, unsigned int)` | 0x8006559C | 0 |
| `SAnimator2::removeCostume(void)` | 0x800676E4 | 1 |
| `SimModel::VerifyRequiredModels(void) const` | 0x800714C4 | 1 |
| `SlotLoader::Save(short, vector<ObjectSlot, allocator<ObjectSlot> > *, vector<RoutingSlot, allocator<RoutingSlot> > *, vector<SpriteSlot, allocator<SpriteSlot> > *, cXObject *)` | 0x801445C4 | 1 |
| `SpriteSlot::GetTicksPerFrame(void)` | 0x80145364 | 12 |
| `TTabScratchEntry::CountAds(void) const` | 0x80149D90 | 16 |
| `TTabScratchEntry::GetOrderIndex(void) const` | 0x80149F28 | 0 |
| `TTabScratchEntry::GetUseCustomActivation(void) const` | 0x80149F34 | 0 |
| `TreeTableEntryQuickData::CountAds(void) const` | 0x8015E6FC | 16 |
| `TreeTableEntryQuickData::GetAd(int)` | 0x8015E874 | 0 |
| `TreeTableQuickData::AddEntry(short, short)` | 0x8015E98C | 0 |
| `TreeTableQuickData::AreOrderIndicesValid(void) const` | 0x8015E968 | 1 |
| `TreeTableQuickData::GetDataSourceType(void) const` | 0x8015E020 | 1 |
| `TreeTableQuickData::GetEntryByIndex(int)` | 0x8015E954 | 0 |
| `TreeTableQuickData::GetIsTuned(void) const` | 0x8015E980 | 0 |
| `TreeTableQuickData::GetNthEntry(int)` | 0x8015E94C | 0 |
| `TreeTableQuickData::GetNthOrderedEntry(int)` | 0x8015E95C | 0 |
| `TreeTableQuickData::GetResourceName(StringBuffer &) const` | 0x8015E8B4 | 0 |
| `TreeTableQuickData::LoadFromIndex(unsigned int, int)` | 0x8015E8AC | 0 |
| `TreeTableQuickData::LoadOnlyNameAndIDFromIndex(unsigned int, int)` | 0x8015E8C4 | 0 |
| `TreeTableQuickData::RemoveEntry(ITreeTableEntry *)` | 0x8015E994 | 0 |
| `TreeTableQuickData::Save(unsigned int, short)` | 0x8015E970 | -45 |
| `TreeTableQuickData::Save(void)` | 0x8015E978 | -45 |
| `TreeTableQuickData::SaveDataByID(ObjectDataID &)` | 0x8015E018 | 0 |
| `TreeTableQuickData::SetResourceName(StringBuffer &)` | 0x8015E8BC | 0 |
| `UIObjectBase::GetLocalizable(char *)` | 0x803A05E8 | 0 |
| `UIObjectBase::GetVariable(char *)` | 0x803A06A4 | 0 |
| `UIScreenManager::process_cheats(UIScreenID)` | 0x8017F87C | 1 |
| `XObjLang::CountPrimitives(void)` | 0x80152380 | 0 |
| `XObjLang::GetMaxConstants(void)` | 0x801523A4 | 128 |
| `XObjLang::GetSwizzler(void)` | 0x80152388 | 0 |
| `XObjLang::IsSingleExit(BehaviorNode *)` | 0x80152378 | 0 |
| `_AptValidate(void)` | 0x802693E0 | 1 |
| `__CARDIsOpened` | 0x80383C70 | 0 |
| `__TRK_write_console` | 0x8036CF48 | 0 |
| `__ai_src_get_time` | 0x80267860 | 0 |
| `__read_console` | 0x8036CF40 | 0 |
| `basic_string_ref2::eos(void)` | 0x800A0754 | 0 |
| `basic_string_ref::eos(void)` | 0x8009C608 | 0 |
| `cFixedWorldImpl::GetMaxSize(void) const` | 0x80151C40 | 64 |
| `cGZMusic::GetFrequency(void)` | 0x800BB184 | 22050 |
| `cGZMusic::GetPan(void)` | 0x800BB0D0 | 512 |
| `cGZMusic::Init(void)` | 0x800BABF8 | 1 |
| `cGZMusic::Load(void)` | 0x800BAEAC | 1 |
| `cGZMusic::SetFrequency(int)` | 0x800BB18C | 1 |
| `cGZMusic::SetPosition(unsigned int)` | 0x800BB194 | 1 |
| `cGZMusic::Unload(void)` | 0x800BAEB4 | 1 |
| `cGZSnd::GetFrequency(void)` | 0x800BA8DC | 22050 |
| `cGZSnd::Init(void)` | 0x800BA090 | 1 |
| `cGZSnd::Load(void)` | 0x800BA658 | 1 |
| `cGZSnd::SetFrequency(int)` | 0x800BA8E4 | 1 |
| `cGZSnd::SetPosition(unsigned int)` | 0x800BA8EC | 1 |
| `cGZSnd::Unload(void)` | 0x800BA660 | 1 |
| `cHitMan::StartCallbackTimer(void)` | 0x80116DEC | 0 |
| `cHitMan::StopCallbackTimer(void)` | 0x80116DF4 | 0 |
| `cXObject::GetGlobalInitTreeID(void)` | 0x800D961C | 271 |
| `cXObject::GetGlobalMainTreeID(void)` | 0x800D9624 | 391 |
| `cXObjectImpl::GetObjectProbe(void)` | 0x800EAF2C | 0 |
| `cXObjectImpl::IsBeingDraggedAround(void)` | 0x800E1784 | 0 |
| `cXPersonImpl::TickRecording(void)` | 0x8012B5E0 | 0 |
| `getBytesLoaded(char *, AptGetBytesEnum)` | 0x800067E0 | 0 |
| `getBytesTotal(char *, AptGetBytesEnum)` | 0x800067D8 | 0 |
| `getEncoderType` | 0x80261E64 | 1 |
| `loadSound(void *, int, char *)` | 0x8000741C | 0 |
| `pointHitTest(float, float, void *)` | 0x800067CC | 0 |

</details>

#### Load Word Getter (543 functions)

Pattern: `lwz r3, offset(rX); blr` -- C++: `return this->field;` or `return *ptr;`

<details>
<summary>All 543 lwz-getter functions</summary>

| Function | Address | Source Reg | Offset |
|----------|---------|-----------|-------:|
| `ACTTarget::IsActionQueueActive(void)` | 0x801A23BC | this (r3) | 208 |
| `AICheckInit` | 0x80266F94 | r13 (SDA) | -23120 |
| `ARCheckInit` | 0x80375980 | r13 (SDA) | -22340 |
| `ARGetInternalSize` | 0x80375A6C | r13 (SDA) | -22360 |
| `ARGetSize` | 0x80375A64 | r13 (SDA) | -22364 |
| `ARQCheckInit` | 0x80377CF4 | r13 (SDA) | -22292 |
| `ARQGetChunkSize` | 0x80377CEC | r13 (SDA) | -22296 |
| `AXGetDspCycles` | 0x8037B9A8 | r13 (SDA) | -22100 |
| `AXGetMaxDspCycles` | 0x8037B9A0 | r13 (SDA) | -22104 |
| `AXGetMode` | 0x8037921C | r13 (SDA) | -22208 |
| `ActionMenu::MenuItem::GetNext(void)` | 0x80183248 | this (r3) | 96 |
| `ActionMenu::MenuItem::GetNextConst(void) const` | 0x80183250 | this (r3) | 96 |
| `ActionMenu::MenuItem::GetSubMenu(void)` | 0x80183258 | this (r3) | 92 |
| `AmbientScorePlayer::GetAmbientScore(void)` | 0x800A8B24 | this (r3) | 8 |
| `AmbientScorePlayer::GetNumPlaying(void)` | 0x800A8B2C | this (r3) | 16 |
| `AmbientScorePlayer::GetVolume(void)` | 0x800A8B1C | this (r3) | 20 |
| `AmbientSoundPlayer::GetAmbientSound(void)` | 0x800AA9B4 | this (r3) | 4 |
| `AptActionInterpreter::cbCallMethod_ASSetPropFlags(AptValue *, int)` | 0x8026F4B8 | r13 (SDA) | -22936 |
| `AptAnimationPoolData::GetActionPool(void)` | 0x80293950 | this (r3) | 152 |
| `AptAnimationPoolData::GetActionPool(void)` | 0x8029E268 | this (r3) | 152 |
| `AptAnimationPoolData::GetActionPool(void)` | 0x802A9880 | this (r3) | 152 |
| `AptArray::length(void)` | 0x80287E40 | this (r3) | 44 |
| `AptBoolean::GetBool(void) const` | 0x802BBAD8 | this (r3) | 12 |
| `AptCIH::getAnimationInst(void) const` | 0x80293B38 | this (r3) | 76 |
| `AptCIH::getButtonInst(void) const` | 0x80293B30 | this (r3) | 76 |
| `AptCIH::getCharacterInst(void) const` | 0x80293B48 | this (r3) | 76 |
| `AptCIH::getMorphInst(void) const` | 0x80293B28 | this (r3) | 76 |
| `AptCIH::getShapeInst(void) const` | 0x80293B40 | this (r3) | 76 |
| `AptCIH::getSpriteInst(void) const` | 0x80293B08 | this (r3) | 76 |
| `AptCIH::getSpriteInstBase(void) const` | 0x80293B10 | this (r3) | 76 |
| `AptCIH::getStaticTextInst(void) const` | 0x80293B20 | this (r3) | 76 |
| `AptCIH::getTextInst(void) const` | 0x80293B18 | this (r3) | 76 |
| `AptDate::sMethod_UTC(AptValue *, int)` | 0x80296888 | r13 (SDA) | -22936 |
| `AptDisplayList::getState(void)` | 0x8029B9EC | this (r3) | 0 |
| `AptFile::GetMainCharacter(void) const` | 0x802A17F0 | this (r3) | 16 |
| `AptGetSwfVersion(void)` | 0x8026BAA8 | r13 (SDA) | -27572 |
| `AptInteger::GetInt(void) const` | 0x802BC044 | this (r3) | 12 |
| `AptPrototype::GetSuperConstructor(void) const` | 0x802B6218 | this (r3) | 32 |
| `AptScriptFunctionByteCodeBlock::GetByteCodeBase(void)` | 0x802B9190 | this (r3) | 52 |
| `AptScriptFunctionByteCodeBlock::GetByteCodeSize(void)` | 0x802B9198 | this (r3) | 56 |
| `AptScriptFunctionByteCodeBlock::GetName(void) const` | 0x802B9180 | this (r3) | 60 |
| `AptSound::sMethod_stop(AptValue *, int)` | 0x802ABB50 | r13 (SDA) | -22936 |
| `AptStage::sMethod_addListener(AptValue *, int)` | 0x802A864C | r13 (SDA) | -22936 |
| `AptStage::sMethod_removeListener(AptValue *, int)` | 0x802A8654 | r13 (SDA) | -22936 |
| `AptString::GetNext(void) const` | 0x802AED0C | this (r3) | 16 |
| `AptString::sMethod_lastIndexOf(AptValue *, int)` | 0x802AD0D4 | r13 (SDA) | -22936 |
| `AptValueFactory::CreateUndefined(void)` | 0x802B5124 | r13 (SDA) | -22936 |
| `AptViewer::IsReadControllerActive(void)` | 0x80011E58 | this (r3) | 932 |
| `AptXmlNode::sMethod_appendChild(AptValue *, int)` | 0x802BB338 | r13 (SDA) | -22936 |
| `AptXmlNode::sMethod_cloneNode(AptValue *, int)` | 0x802BB340 | r13 (SDA) | -22936 |
| `AptXmlNode::sMethod_insertBefore(AptValue *, int)` | 0x802BB4D4 | r13 (SDA) | -22936 |
| `AptXmlNode::sMethod_removeNode(AptValue *, int)` | 0x802BB4DC | r13 (SDA) | -22936 |
| `ArcCopier::IsTerminatingCopy(void)` | 0x8032171C | r13 (SDA) | -26640 |
| `ArcFileInfo::GetCopiedSize(void)` | 0x80321DB4 | this (r3) | 12 |
| `ArcFileInfo::GetName(void)` | 0x80321DA4 | this (r3) | 0 |
| `ArcFileInfo::GetSourceLen(void)` | 0x80321DAC | this (r3) | 8 |
| `AwarenessManager::GetAwareOfObject(void)` | 0x80014250 | this (r3) | 28 |
| `AwarenessManager::GetAwarenessAction(void)` | 0x80014248 | this (r3) | 24 |
| `AwarenessManager::GetStateFlags(void)` | 0x80014280 | this (r3) | 0 |
| `BBHTarget::IsBuildBuyHUDActive(void)` | 0x801A3E94 | this (r3) | 136 |
| `BBI::InventoryItem::GetItemGuid(void) const` | 0x8004A20C | this (r3) | 4 |
| `BSplineVolume::GetID(void)` | 0x8030F3BC | this (r3) | 128 |
| `Behavior::GetGlobNamespaceID(void)` | 0x800AB558 | r13 (SDA) | -31848 |
| `Behavior::GetLanguage(void)` | 0x800AD120 | this (r3) | 8 |
| `Behavior::GetOwner(void)` | 0x800AD118 | this (r3) | 4 |
| `CASGeneticsTarget::GetCasGenetics(void)` | 0x801A08B8 | this (r3) | 148 |
| `CASRoommateTarget::GetSelectedSlot(void) const` | 0x801A0934 | this (r3) | 144 |
| `CASTarget::GetCurPartUIFocus(void)` | 0x801A0808 | this (r3) | 164 |
| `CASTarget::GetCurrentSimNumber(void)` | 0x801A0810 | this (r3) | 4940 |
| `CASTarget::GetGeneticsTarget(void)` | 0x801A08A8 | this (r3) | 4976 |
| `CASTarget::GetNPCEditor(void)` | 0x801A08B0 | this (r3) | 4948 |
| `CASTarget::GetPrevUIFocus(void)` | 0x801A0800 | this (r3) | 160 |
| `CASTarget::IsShuttingdown(void)` | 0x801A07F8 | this (r3) | 5680 |
| `CDirtyXmlNode::nodeType(void)` | 0x8023AB80 | this (r3) | 8 |
| `CDirtyXmlNode::parentNode(void)` | 0x8023ABE4 | this (r3) | 12 |
| `CLoadingScreen::GetMode(void) const` | 0x800578A4 | this (r3) | 852 |
| `CSMTarget::IsCSIMActive(void)` | 0x801A7674 | this (r3) | 136 |
| `CUnlockDisplay::DonePreloadObject(void)` | 0x80078FFC | this (r3) | 1104 |
| `CUnlockDisplay::IsDone(void)` | 0x80078FDC | this (r3) | 1116 |
| `CUnlockDisplayObject::GetModel(void)` | 0x800799C4 | this (r3) | 20 |
| `CUnlockDisplayObject::GetType(void)` | 0x80079C68 | this (r3) | 4 |
| `CUnlockDisplayObject::HasDrawn(void)` | 0x80079C60 | this (r3) | 124 |
| `CUnlockDisplayObject::IsDone(void)` | 0x80079C2C | this (r3) | 120 |
| `CUnlockDisplayObject::IsReady(void)` | 0x80079C18 | this (r3) | 116 |
| `CUnlockDisplayObject::IsSimple(void)` | 0x80079A54 | this (r3) | 128 |
| `CameraDirector::GetFrameEffectsManager(void)` | 0x8001CAF8 | this (r3) | 720 |
| `CameraMotionSystem::GetMotionType(void)` | 0x800160B0 | this (r3) | 0 |
| `CareersImpl::GetSuit(Job &, bool)` | 0x800B1B4C | r4 | 104 |
| `CasListener::GetMediator(void) const` | 0x80161BA8 | this (r3) | 0 |
| `CasMediator::GetNumListeners(void) const` | 0x80162028 | this (r3) | 8 |
| `CasScene::Get3DWindow(void) const` | 0x801672B8 | this (r3) | 2840 |
| `CasScene::GetAmbientScoreName(void) const` | 0x801672C8 | r13 (SDA) | -31572 |
| `CasSceneDefault::GetSceneName(void) const` | 0x801755A4 | r13 (SDA) | -31556 |
| `CasSceneGamecube::GetSceneName(void) const` | 0x80175764 | r13 (SDA) | -31552 |
| `CasScenePersonal::GetSceneName(void) const` | 0x8017590C | r13 (SDA) | -31548 |
| `CasSimRenderer::GetPositionNum(void) const` | 0x8016FB54 | this (r3) | 532 |
| `Commander::GetNext(void)` | 0x800B43E4 | this (r3) | 0 |
| `Commander::GetType(void)` | 0x800B43DC | this (r3) | 4 |
| `DSPCheckInit` | 0x8037E388 | r13 (SDA) | -22056 |
| `DVDResetRequired` | 0x8025F5B8 | r13 (SDA) | -23424 |
| `DialogPaneBase::GetBodyTextItem(void)` | 0x80088D28 | this (r3) | 100 |
| `DialogPaneBase::GetTitleTextItem(void)` | 0x80088D20 | this (r3) | 96 |
| `DlgWrapper::GetDialogPane(void)` | 0x8007E5E8 | this (r3) | 172 |
| `DlgWrapper::GetFont(void)` | 0x8007E5E0 | this (r3) | 168 |
| `DlgWrapper::IsAptDrawable(void)` | 0x8007F06C | this (r3) | 180 |
| `E2ETarget::GetTopLevelState(void)` | 0x801E7088 | this (r3) | 216 |
| `EAHeap::GetCurrentCheckPoint(void)` | 0x802D09D4 | r13 (SDA) | -26860 |
| `EApp::GetGameState(void) const` | 0x802E2954 | this (r3) | 1128 |
| `EApp::GetMenuOwner(void) const` | 0x802E2964 | this (r3) | 1132 |
| `EBitArray::GetBuffer(void)` | 0x802E0914 | this (r3) | 0 |
| `EBitArray::GetSize(void) const` | 0x802E076C | this (r3) | 4 |
| `EController::GetId(void)` | 0x8030588C | this (r3) | 0 |
| `EController::GetStatus(void)` | 0x80305894 | this (r3) | 4 |
| `EController::IsControlFake(void)` | 0x80304D10 | this (r3) | 428 |
| `EDL::GetStart(void)` | 0x80363378 | this (r3) | 72 |
| `EDL::GetVertCount(void)` | 0x80363408 | this (r3) | 84 |
| `EDataHeader::GetName(void)` | 0x8035B320 | this (r3) | 0 |
| `EDatasetManager::GetLoadingEnabled(void)` | 0x80324850 | r13 (SDA) | -26632 |
| `EDummyFile::Tell(void) const` | 0x800226A0 | this (r3) | 44 |
| `EEngine::CanReset(void)` | 0x802E38DC | this (r3) | 12 |
| `EEngine::GetCurrentLevel(void)` | 0x802E38CC | this (r3) | 48 |
| `EFile::GetAccessMode(void) const` | 0x802C6914 | this (r3) | 12 |
| `EFile::GetDeviceType(void) const` | 0x802C691C | this (r3) | 16 |
| `EFile::GetIOMode(void) const` | 0x802C690C | this (r3) | 8 |
| `EFile::GetLength(void) const` | 0x802C6944 | this (r3) | 20 |
| `EFile::GetName(void) const` | 0x802C6934 | this (r3) | 32 |
| `EFile::GetPath(void) const` | 0x802C692C | this (r3) | 28 |
| `EFileSystem::FileCreator::GetCreatorCB(void) const` | 0x802C6C74 | this (r3) | 0 |
| `EFileSystem::GetDefaultType(void) const` | 0x802C7118 | this (r3) | 16 |
| `EFileSystem::HDDSaveStatus(void)` | 0x802C7108 | this (r3) | 32 |
| `EFileSystem::HDDStatus(void)` | 0x802C70D0 | this (r3) | 24 |
| `EFileSystem::HDDTmpStatus(void)` | 0x802C70EC | this (r3) | 28 |
| `EGlobal::GetCam(void)` | 0x8003FA1C | this (r3) | 208 |
| `EGlobal::ListenForController(void)` | 0x80042194 | this (r3) | 1144 |
| `EGraphics::FrameBufferClearFlag(void)` | 0x802F21B0 | this (r3) | 12 |
| `EGraphics::FrameBufferClearRequestFlag(void)` | 0x802F21B8 | this (r3) | 16 |
| `EGraphics::GetActualScreenXSize(void)` | 0x802F22C8 | this (r3) | 24 |
| `EGraphics::GetActualScreenYSize(void)` | 0x802F22D0 | this (r3) | 28 |
| `EGraphics::GetCoordinateSystem(void)` | 0x802F221C | this (r3) | 152 |
| `EGraphics::GetScreenXOffset(void)` | 0x802F22E8 | this (r3) | 32 |
| `EGraphics::GetScreenXSize(void)` | 0x802F2238 | this (r3) | 24 |
| `EGraphics::GetScreenYOffset(void)` | 0x802F22F0 | this (r3) | 36 |
| `EGraphics::GetScreenYSize(void)` | 0x802F2240 | this (r3) | 28 |
| `EGraphics::IsEnableFrameEffects(void)` | 0x802F2350 | this (r3) | 800 |
| `EGraphics::IsFirstPassRenderOnly(void)` | 0x802F2340 | this (r3) | 796 |
| `EGraphics::IsInsideBeginEnd(void)` | 0x802F2358 | this (r3) | 4 |
| `EILight::HaveLightsChanged(void)` | 0x802281BC | r13 (SDA) | -28500 |
| `EILight::IsEnabled(void)` | 0x802281A0 | this (r3) | 136 |
| `EIPointLight::GetRoomId(void)` | 0x8022A64C | this (r3) | 192 |
| `EIPortalPointLight::GetPortal(void)` | 0x8022B0FC | this (r3) | 212 |
| `EIPortalPointLight::GetRoomId(void)` | 0x8022B10C | this (r3) | 192 |
| `EIStaticModel::GetModel(void)` | 0x8022E27C | this (r3) | 288 |
| `EIStaticModel::GetModelId(void)` | 0x8022E274 | this (r3) | 272 |
| `EIStaticModel::GetModifiableColor(void)` | 0x8022DAE8 | this (r3) | 276 |
| `EIStaticSubModel::GetModifiableColor(void)` | 0x8022F590 | this (r3) | 148 |
| `EInstance::GetContext(void)` | 0x80229224 | r13 (SDA) | -28496 |
| `EInstance::GetLevel(void)` | 0x80229674 | this (r3) | 4 |
| `EInstance::GetOtherSideData(void)` | 0x802295F0 | this (r3) | 36 |
| `EInstance::GetOtherSideFn(void)` | 0x802295F8 | this (r3) | 32 |
| `EInstance::GetPortalType(void)` | 0x802295CC | this (r3) | 20 |
| `EInstance::GetShadowOwner(void)` | 0x8022971C | this (r3) | 24 |
| `EInstance::GetThisSideData(void)` | 0x802295E0 | this (r3) | 40 |
| `EInstance::GetThisSideFn(void)` | 0x802295E8 | this (r3) | 28 |
| `EInstance::IsWall(void)` | 0x80229724 | this (r3) | 16 |
| `ELiveMode::GetIntroCameraState(void)` | 0x80090068 | this (r3) | 12 |
| `ELiveMode::InTransportMode(void)` | 0x80090038 | this (r3) | 40 |
| `ELiveMode::IsInitialized(void)` | 0x80090098 | this (r3) | 48 |
| `EMemoryBufferWriteStream::GetPos(void) const` | 0x802E0EE8 | this (r3) | 32 |
| `EMemoryReadStream::GetPos(void) const` | 0x802E0EB4 | this (r3) | 32 |
| `EMemoryWriteStream::GetPos(void) const` | 0x802E0EF8 | this (r3) | 28 |
| `ENCamera::GetID(void)` | 0x8035D24C | this (r3) | 64 |
| `ENCamera::GetKeys(void)` | 0x8035D254 | this (r3) | 68 |
| `ENDummy::GetID(void)` | 0x802CC4B4 | this (r3) | 64 |
| `ENDummy::GetKeys(void)` | 0x802CC4BC | this (r3) | 68 |
| `ENgcAudio::IsPausedDueToDiscError(void)` | 0x8032CB0C | this (r3) | 56 |
| `ENgcEngine::IsResetting(void)` | 0x8032E884 | r13 (SDA) | -26472 |
| `ENgcFile::Tell(void) const` | 0x802E1BDC | this (r3) | 104 |
| `ENgcRenderSurface::GetTexture(void)` | 0x8034C314 | this (r3) | 40 |
| `ENgcRenderer::GetFrameEffectsScratchMemory(void)` | 0x80349FD4 | this (r3) | 17996 |
| `ENgcRenderer::GetNextExternalFrameBuffer(void)` | 0x80349F44 | this (r3) | 844 |
| `ENgcRenderer::GetRenderStateCache(void)` | 0x80349F3C | this (r3) | 1240 |
| `ENgcSNFile::GetSystemHandle(void) const` | 0x802D8098 | this (r3) | 44 |
| `ENgcSNFile::Tell(void) const` | 0x802D8080 | this (r3) | 48 |
| `ENgcTextureBase::UpdatePalette(void)` | 0x80350238 | this (r3) | 144 |
| `EQuickdataManager::GetCurrentLanguage(void) const` | 0x80325588 | this (r3) | 3360 |
| `ERBinary::GetData(void)` | 0x8036860C | this (r3) | 20 |
| `ERBinary::GetDataSize(void)` | 0x80368614 | this (r3) | 24 |
| `EREdithTreeSet::GetNumTrees(void)` | 0x8030FC5C | this (r3) | 24 |
| `ERLevel::IsDrawingOrderTable(void)` | 0x80238290 | r13 (SDA) | -28428 |
| `ERModel::AreMatsInDLs(void)` | 0x8031B448 | this (r3) | 140 |
| `ERModel::DontCull(void)` | 0x8031B460 | this (r3) | 44 |
| `ERModel::DontFrontPlaneFade(void)` | 0x8031B450 | this (r3) | 36 |
| `ERModel::DontInterestFade(void)` | 0x8031B458 | this (r3) | 40 |
| `ERModel::GetCameraCount(void)` | 0x80318B10 | this (r3) | 300 |
| `ERModel::GetDummyCount(void)` | 0x80318B08 | this (r3) | 288 |
| `ERModel::GetLatticeCount(void)` | 0x80318B00 | this (r3) | 276 |
| `ERModel::GetNumAttachmentVerts(void)` | 0x8031B484 | this (r3) | 312 |
| `ERModel::GetNumLightPos(void)` | 0x8031B48C | this (r3) | 320 |
| `ERModel::GetNumMorphBases(void)` | 0x8031A628 | this (r3) | 264 |
| `ERModel::IsHierarchical(void)` | 0x8031B428 | this (r3) | 20 |
| `ERModel::IsLattice(void)` | 0x8031B440 | this (r3) | 52 |
| `ERModel::IsMorphTarget(void)` | 0x8031B438 | this (r3) | 56 |
| `ERModel::IsWall(void)` | 0x8031B468 | this (r3) | 48 |
| `ERModel::IsWeldable(void)` | 0x8031B430 | this (r3) | 32 |
| `ERQuickdata::GetImage(void) const` | 0x8031C62C | this (r3) | 20 |
| `ERQuickdata::GetImageSize(void) const` | 0x8031C634 | this (r3) | 24 |
| `ERSampledata::GetSampleHeader(void) const` | 0x80338324 | this (r3) | 20 |
| `ERSampledata::GetSampleHeader2(void) const` | 0x8033832C | this (r3) | 24 |
| `ERTQuantize4D::GetPaletteSize(void)` | 0x8035FF48 | this (r3) | 4132 |
| `ERTQuantize::GetFullPaletteSize(void)` | 0x802CF964 | this (r3) | 4248 |
| `ERTQuantize::GetPaletteSize(void)` | 0x802CF95C | this (r3) | 4264 |
| `ERenderSurface::GetFlags(void)` | 0x80364F5C | this (r3) | 8 |
| `ERenderSurface::GetXSize(void)` | 0x80364EB8 | this (r3) | 0 |
| `ERenderSurface::GetYSize(void)` | 0x80364EC0 | this (r3) | 4 |
| `EResPrefetchFile::GetResMan(void)` | 0x80313338 | this (r3) | 44 |
| `EResPrefetchFile::Tell(void) const` | 0x803131C8 | this (r3) | 64 |
| `EResource::GetResId(void) const` | 0x80312274 | this (r3) | 8 |
| `EResourceLoaderImpl::AreLoadsPaused(void)` | 0x80311CC8 | this (r3) | 1000 |
| `EResourceManager::IsInitialized(void)` | 0x80327ECC | this (r3) | 72 |
| `EResourceMap::GetMaxEntries(void)` | 0x80327EB4 | this (r3) | 8 |
| `EResourceMap::GetMaxLoaded(void)` | 0x80327EBC | this (r3) | 12 |
| `EResourceMap::GetMaxUsed(void)` | 0x80327EC4 | this (r3) | 16 |
| `EResourceMap::GetNumEntries(void)` | 0x80327EAC | this (r3) | 4 |
| `EResourceMap::GetSize(void)` | 0x80327E30 | this (r3) | 4 |
| `ESemaphore::GetCurrentCount(void)` | 0x802D79F8 | this (r3) | 12 |
| `ESemaphore::GetMaxCount(void)` | 0x802D7A00 | this (r3) | 8 |
| `EShader::GetShaderUpdate(void) const` | 0x802FAB74 | this (r3) | 232 |
| `EShader::GetSurfaceProperties(void) const` | 0x802FAAEC | this (r3) | 4 |
| `ESim::GetIsChangingOutfit(void)` | 0x80035374 | this (r3) | 984 |
| `ESim::GetIsModelLoaded(void)` | 0x8003536C | this (r3) | 1592 |
| `ESim::GetPerson(void)` | 0x80035314 | this (r3) | 976 |
| `ESim::GetPlumbBobState(void)` | 0x8003535C | this (r3) | 1004 |
| `ESim::GetShadow(void)` | 0x8003530C | this (r3) | 992 |
| `ESim::GetSimHead(void)` | 0x80035330 | this (r3) | 1576 |
| `ESim::GetSimModel(void)` | 0x80035338 | this (r3) | 1596 |
| `ESimsApp::GetStartLot(void)` | 0x80003FDC | r13 (SDA) | -32752 |
| `ESimsCam::GetControllerFilterId(void) const` | 0x8001ADA0 | this (r3) | 1376 |
| `ESimsCam::GetMode(void) const` | 0x8001EA9C | this (r3) | 972 |
| `ESimsCam::GetPlayerId(void)` | 0x8001EAA4 | this (r3) | 4 |
| `ESimsCam::GetRoomWallsOpaque(void)` | 0x8001EACC | this (r3) | 1352 |
| `ESimsCam::GetbMoved(void) const` | 0x8001EA8C | this (r3) | 8 |
| `ESimsCam::IsForceFullScreen(void)` | 0x8001EAB4 | this (r3) | 1356 |
| `ESpriteRender::GetMarked(void)` | 0x80036E78 | this (r3) | 0 |
| `ESpriteRender::GetMarkedAsNew(void)` | 0x80036E80 | this (r3) | 4 |
| `ESpriteRender::GetObject(void)` | 0x80036E70 | this (r3) | 8 |
| `EStream::IsStreamingStructure(void)` | 0x802D283C | this (r3) | 0 |
| `EString2::operator unsigned wchar_t *(void) const` | 0x803C2F10 | this (r3) | 0 |
| `EString::operator char *(void) const` | 0x803B0A6C | this (r3) | 0 |
| `ETexture::GetFlags(void)` | 0x80365118 | this (r3) | 8 |
| `EThread::GetStack(void)` | 0x802D858C | this (r3) | 796 |
| `EThread::GetStackSize(void)` | 0x802D8594 | this (r3) | 800 |
| `EThread::GetThreadName(void)` | 0x802D8684 | this (r3) | 812 |
| `EVibrate::IsOn(void)` | 0x80307CBC | this (r3) | 0 |
| `EVisInfoDecomp::GetBitCount(void)` | 0x8036212C | this (r3) | 8 |
| `EWindow::GetCurrent3DWindow(void)` | 0x80300AF0 | r13 (SDA) | -26704 |
| `EWindow::GetCurrentWindow(void)` | 0x80300AE8 | r13 (SDA) | -26708 |
| `EdithDialogPrimitive::GetModalDialogResult(void) const` | 0x800B5F20 | this (r3) | 136 |
| `Emitter::Get(void)` | 0x8023869C | this (r3) | 124 |
| `EyeToyClient::GetSessionTexture(void)` | 0x80038F40 | r13 (SDA) | -32536 |
| `EyeToyClient::MacroBlockDummyAllocator(unsigned int, unsigned int)` | 0x800387B4 | r13 (SDA) | -32540 |
| `EyeToyClient::loadTexture_alloc(unsigned int, unsigned int)` | 0x80037708 | r13 (SDA) | -25032 |
| `FCMTarget::IsFireCodeMeterActive(void)` | 0x801B4458 | this (r3) | 136 |
| `FamilyImpl::GetCreationOrder(void)` | 0x800B6B28 | this (r3) | 16 |
| `FamilyImpl::GetFunds(void)` | 0x800B6B38 | this (r3) | 20 |
| `FamilyImpl::GetHouseNumber(void)` | 0x800B6B18 | this (r3) | 12 |
| `FamilyImpl::GetHouseValue(void)` | 0x800B6B60 | this (r3) | 24 |
| `FamilyImpl::GetNumber(void)` | 0x800B6B08 | this (r3) | 8 |
| `FastAllocPool::GetAlignment(void) const` | 0x802D7220 | this (r3) | 16 |
| `FastAllocPool::GetBlockSize(void) const` | 0x802D7240 | this (r3) | 12 |
| `FastAllocPool::GetPoolBlocks(void) const` | 0x802D7248 | this (r3) | 8 |
| `FastAllocPool::GetPoolStart(void) const` | 0x802D7228 | this (r3) | 0 |
| `FlowGotoTarget::GetStateRequest(void)` | 0x8017B980 | this (r3) | 132 |
| `FrameEffectsManager::BloomObject(void)` | 0x80357970 | this (r3) | 4 |
| `FrameEffectsManager::DepthOfFieldObject(void)` | 0x80357978 | this (r3) | 8 |
| `FrameEffectsManager::MotionBlurObject(void)` | 0x80357968 | this (r3) | 0 |
| `FreeResourceManager::GetUnreferencedResourceCount(void)` | 0x803293F0 | this (r3) | 3232 |
| `G2DTarget::IsG2DActive(void)` | 0x801B5A04 | this (r3) | 136 |
| `G2DTarget::IsG2DSpawned(void)` | 0x801B5A0C | this (r3) | 132 |
| `G2DTarget::IsInitComplete(void)` | 0x801E7050 | r13 (SDA) | -30368 |
| `GDGetOverflowCallback` | 0x8039ABD4 | r13 (SDA) | -21540 |
| `GXGetCPUFifo` | 0x80389158 | r13 (SDA) | -21960 |
| `GXGetCurrentGXThread` | 0x80389150 | r13 (SDA) | -21952 |
| `GXGetFifoBase` | 0x80388D64 | this (r3) | 0 |
| `GXGetFifoSize` | 0x80388D6C | this (r3) | 8 |
| `GXGetGPFifo` | 0x80389160 | r13 (SDA) | -21956 |
| `GXGetOverflowCount` | 0x80389168 | r13 (SDA) | -21936 |
| `GXGetTexObjFmt` | 0x8038D99C | this (r3) | 20 |
| `GXGetTexObjTlut` | 0x8038DBAC | this (r3) | 24 |
| `GXGetTexObjUserData` | 0x8038D900 | this (r3) | 16 |
| `GameData::GetBuildBuyPlayer(void) const` | 0x8003DDA0 | this (r3) | 296 |
| `GetNumNghSubSections(NghLayout *)` | 0x800D26F8 | this (r3) | 12 |
| `GetSRandSeed(void)` | 0x800A64E8 | r13 (SDA) | -24584 |
| `GlobalConstantsClient::GetFileID(void)` | 0x800EC07C | r13 (SDA) | -31848 |
| `H2DTarget::GetPausePlayer(void)` | 0x801B8A38 | this (r3) | 208 |
| `HouseImpl::GetFamily(void)` | 0x800BC984 | this (r3) | 20 |
| `HouseImpl::GetFurnishingsScoreCurve(void)` | 0x800BC994 | this (r3) | 32 |
| `HouseImpl::GetSizeScoreCurve(void)` | 0x800BC98C | this (r3) | 28 |
| `HouseStats::GetLotSize(void)` | 0x800BC974 | this (r3) | 20 |
| `HouseStats::GetNumBathrooms(void)` | 0x800BC964 | this (r3) | 12 |
| `HouseStats::GetNumBedrooms(void)` | 0x800BC95C | this (r3) | 8 |
| `HouseStats::GetNumLevels(void)` | 0x800BC96C | this (r3) | 16 |
| `HouseStats::GetObjectCount(void)` | 0x800BC97C | this (r3) | 36 |
| `HouseStats::GetSquareFeet(void)` | 0x800BC454 | this (r3) | 0 |
| `IFFResFile2::Writable(void)` | 0x800BEA00 | this (r3) | 284 |
| `INTTarget::IsInterestMeterActive(void)` | 0x801F8E8C | this (r3) | 136 |
| `ISimInstance::GetCursFlags(void)` | 0x800569FC | this (r3) | 812 |
| `ISimInstance::GetFlags(void)` | 0x80056A10 | this (r3) | 812 |
| `ISimInstance::GetXOb(void)` | 0x80056354 | this (r3) | 808 |
| `ISimsObjectModel::GetILight(void)` | 0x80053E38 | this (r3) | 1120 |
| `ISimsObjectModel::GetShadow(void)` | 0x80053D9C | this (r3) | 1100 |
| `ITBTarget::IsIntroThoughtBalloonActive(void)` | 0x801BD8F4 | this (r3) | 136 |
| `IconItem::GetShader(void)` | 0x800878BC | this (r3) | 48 |
| `ImageProcessingManager::LinkTexture(unsigned int, unsigned int)` | 0x8032A290 | r13 (SDA) | -26592 |
| `Interaction::GetFlags(void) const` | 0x800C1FF0 | this (r3) | 60 |
| `Interaction::GetID(void) const` | 0x800C1DA4 | this (r3) | 56 |
| `Interaction::GetIconObject(void) const` | 0x800C1C84 | this (r3) | 16 |
| `Interaction::GetLocalVars(void)` | 0x800C1D64 | this (r3) | 36 |
| `Interaction::GetLocalVarsCount(void)` | 0x800C1D6C | this (r3) | 32 |
| `Interaction::GetPerson(void) const` | 0x800C1C7C | this (r3) | 8 |
| `Interaction::GetPriority(void) const` | 0x800C1D7C | this (r3) | 40 |
| `Interaction::GetStackObject(void) const` | 0x800C1C74 | this (r3) | 12 |
| `Interaction::GetTreeTabEntryIndex(void) const` | 0x800C1D74 | this (r3) | 20 |
| `Interaction::GetType(void)` | 0x800C1D44 | this (r3) | 4 |
| `InteractorModule::DirectInteractor::GetControlStatus(void)` | 0x80206118 | this (r3) | 100 |
| `InteractorModule::DirectInteractor::IsAutonomous(void)` | 0x8020612C | this (r3) | 128 |
| `InteractorModule::FloorPainter::IsInPlaceMode(void)` | 0x802091A4 | this (r3) | 164 |
| `InteractorModule::Interactor::GetAttachedCamera(void)` | 0x802092AC | this (r3) | 4 |
| `InteractorModule::Interactor::GetDrawState(void)` | 0x802095DC | this (r3) | 76 |
| `InteractorModule::Interactor::GetPlayerId(void)` | 0x802095CC | this (r3) | 0 |
| `InteractorModule::InteractorInputManager::InstanceData::GetControllerFilterId(void) const` | 0x8020AAE8 | this (r3) | 20 |
| `InteractorModule::InteractorManager::GetInputManager(void)` | 0x8020B690 | r13 (SDA) | -28512 |
| `InteractorModule::InteractorManager::GetVisualizer(void)` | 0x8020B698 | r13 (SDA) | -28508 |
| `InteractorModule::InteractorManager::IsInitialized(void)` | 0x8020B6A0 | this (r3) | 0 |
| `InteractorModule::ObjectManipulator::GetIsCursorModelEnabled(void) const` | 0x8021A03C | this (r3) | 168 |
| `InteractorModule::SocialModeInteractor::GetTimout(void)` | 0x8021F588 | this (r3) | 108 |
| `K2YTarget::GetMode(void)` | 0x801E7098 | r13 (SDA) | -30256 |
| `LoadGameTarget::GetResult(void)` | 0x8018AAE8 | this (r3) | 268 |
| `LoadingScreenStateMachine::GetLoadingScreen(void)` | 0x80090E04 | this (r3) | 152 |
| `LoadingScreenStateMachine::GetSingleton(void)` | 0x80090F74 | r13 (SDA) | -32160 |
| `LoadingScreenStateMachine::IsLoadComplete(void)` | 0x80090E18 | this (r3) | 164 |
| `M2MTarget::GetDevice(void)` | 0x801C1108 | this (r3) | 268 |
| `M2MTarget::GetPlayerNum(void)` | 0x801E7090 | this (r3) | 400 |
| `M2MTarget::GetSaveGameID(void)` | 0x801C113C | this (r3) | 272 |
| `MDITarget::CountModelessDialogs(void)` | 0x801C3DF0 | this (r3) | 136 |
| `MDITarget::IsModelessDialogActive(void)` | 0x801C3CA0 | this (r3) | 148 |
| `MIXGetDvdStreamFader` | 0x8037D1A0 | r13 (SDA) | -22068 |
| `MIXGetSoundMode` | 0x8037BCC4 | r13 (SDA) | -22064 |
| `MMUTarget::GetCurrentGameplayChoice(void) const` | 0x801E7080 | this (r3) | 184 |
| `MMUTarget::GetCurrentMainScreenChoice(void) const` | 0x801E7078 | this (r3) | 164 |
| `MMUTarget::GetSingleton(void)` | 0x801C59E0 | r13 (SDA) | -30180 |
| `MODTarget::IsMoodActive(void)` | 0x801C9C84 | this (r3) | 136 |
| `MOTTarget::IsMotivesActive(void)` | 0x801CBFC0 | this (r3) | 136 |
| `MUStateMachine::GetCurRequest(void)` | 0x800939C0 | r13 (SDA) | -21368 |
| `MUStateMachine::GetHouseNumber(void)` | 0x80093BCC | r13 (SDA) | -21360 |
| `MUStateMachine::GetMUWrapper(void)` | 0x80093BD4 | this (r3) | 152 |
| `MUWrapper::GetFont(void)` | 0x80083964 | this (r3) | 164 |
| `MemFile::Writable(void)` | 0x800A64E0 | this (r3) | 268 |
| `NamespaceSelector::GetTreeSetResource(void)` | 0x800C8860 | this (r3) | 48 |
| `Neighbor::GetGUID(void)` | 0x800C9A8C | this (r3) | 8 |
| `Neighbor::GetRelations(void) const` | 0x800C90B4 | this (r3) | 16 |
| `NeighborhoodImpl::GetHouseNumber(void)` | 0x800D1294 | this (r3) | 112 |
| `NghResFile::GetSourceType(void) const` | 0x800D93CC | this (r3) | 32 |
| `NghResFile::GetStoreChecksum(void)` | 0x800D8EE8 | this (r3) | 396 |
| `OSGetArenaHi` | 0x8024C760 | r13 (SDA) | -23680 |
| `OSGetArenaLo` | 0x8024C768 | r13 (SDA) | -27920 |
| `OSGetSemaphoreCount` | 0x80371A90 | this (r3) | 0 |
| `OSGetThreadPriority` | 0x802548F0 | this (r3) | 724 |
| `ObjSelector::GetSimDescription(void) const` | 0x803A5208 | this (r3) | 140 |
| `ObjectDataObjDefinition::GetData(void)` | 0x8015CA34 | this (r3) | 28 |
| `ObjectDataObjDefinition::GetData(void) const` | 0x8015CA3C | this (r3) | 28 |
| `ObjectFolderImpl::GetObjectsDatabase(void)` | 0x800F29F0 | this (r3) | 1680 |
| `ObjectModuleImpl::GetFolder(void)` | 0x800F9928 | r13 (SDA) | -21508 |
| `ObjectModuleImpl::GetSim(void)` | 0x800F9980 | r13 (SDA) | -21496 |
| `ObjectSlot::GetHeight(void)` | 0x80145328 | this (r3) | 8 |
| `PADGetSpec` | 0x80266280 | r13 (SDA) | -27640 |
| `PAZBase::GetPausePlayer(void)` | 0x801D0B68 | this (r3) | 132 |
| `PPMMutexGetLockCount(void *)` | 0x802D87E4 | this (r3) | 12 |
| `PassiveInfluenceObject::GetObject(void)` | 0x803A8CB0 | this (r3) | 4 |
| `PassiveInfluencePerson::GetObject(void)` | 0x803A8B48 | this (r3) | 4 |
| `PassiveInfluenceTarget::GetObject(void)` | 0x803A8EE4 | this (r3) | 4 |
| `PlayerFamilyImpl::GetTotalAspirationScore(void) const` | 0x8012D1C4 | this (r3) | 3424 |
| `REffectsEmitter::GetEmitterInitData(void)` | 0x8036AD78 | this (r3) | 20 |
| `REffectsEmitter::GetParticleBirthData(void)` | 0x8036AD80 | this (r3) | 24 |
| `REffectsEmitter::GetTexture(void)` | 0x8036AD88 | this (r3) | 28 |
| `REffectsEmitter::Refreshed(void)` | 0x8036AD90 | this (r3) | 32 |
| `RParticle::GetData(void)` | 0x8036C308 | this (r3) | 20 |
| `Room::IsPool(void)` | 0x801386D4 | this (r3) | 148 |
| `RoomManager::GetRoomManager(void)` | 0x8013884C | r13 (SDA) | -31676 |
| `RoutingSlot::GetFacingDirection(void) const` | 0x80145540 | this (r3) | 52 |
| `RoutingSlot::GetMaxDist(void) const` | 0x80145588 | this (r3) | 40 |
| `RoutingSlot::GetMinDist(void) const` | 0x80145580 | this (r3) | 36 |
| `RoutingSlot::GetOptimalDist(void) const` | 0x80145590 | this (r3) | 44 |
| `RoutingSlot::GetResolution(void) const` | 0x80145598 | this (r3) | 56 |
| `RoutingSlot::GetSnapTargetSlot(void) const` | 0x801455B8 | this (r3) | 32 |
| `SAnimator2::GetAnimState(void)` | 0x800690E8 | this (r3) | 44 |
| `SAnimator2::GetAwareOfObject(void)` | 0x80068A40 | this (r3) | 1596 |
| `SAnimator2::GetFollowMode(void)` | 0x800690F0 | this (r3) | 24 |
| `SAnimator2::GetHeadBoneIndex(void)` | 0x800691DC | this (r3) | 1552 |
| `SAnimator2::GetLastCostume(void)` | 0x80069220 | this (r3) | 304 |
| `SAnimator2::GetNormalSimDescription(void) const` | 0x80069164 | this (r3) | 1540 |
| `SAnimator2::GetPelvisBoneIndex(void)` | 0x800691E4 | this (r3) | 1556 |
| `SAnimator2::GetPerson(void)` | 0x800690D8 | this (r3) | 4 |
| `SAnimator2::GetRightHandBoneIndex(void)` | 0x800691D4 | this (r3) | 1548 |
| `SAnimator2::GetSim(void)` | 0x800690E0 | this (r3) | 8 |
| `SAnimator2::GetTorsoBoneIndex(void)` | 0x800691EC | this (r3) | 1560 |
| `SKLTarget::IsSkillsActive(void)` | 0x801E19BC | this (r3) | 136 |
| `SaveGameTarget::GetResult(void)` | 0x8018DE08 | this (r3) | 272 |
| `SimpleReconObject<CasCostumes>::GetType(void)` | 0x803B05FC | this (r3) | 8 |
| `SimpleReconObject<CasGenetics>::GetType(void)` | 0x803B0AB8 | this (r3) | 8 |
| `SimpleReconObject<FamilyImpl>::GetType(void)` | 0x803A3608 | this (r3) | 8 |
| `SimpleReconObject<HouseImpl>::GetType(void)` | 0x803A386C | this (r3) | 8 |
| `SimpleReconObject<IFFResMap>::GetType(void)` | 0x803A4C04 | this (r3) | 8 |
| `SimpleReconObject<NeighborhoodImpl>::GetType(void)` | 0x803A61B0 | this (r3) | 8 |
| `SimpleReconObject<ObjectFolderImpl>::GetType(void)` | 0x803A8258 | this (r3) | 8 |
| `SimpleReconObject<ObjectModuleImpl>::GetType(void)` | 0x803A8694 | this (r3) | 8 |
| `SimpleReconObject<ObjectSaveIDTable>::GetType(void)` | 0x8039F5E0 | this (r3) | 8 |
| `SimpleReconObject<ObjectSaveTypeTable2>::GetType(void)` | 0x8039E330 | this (r3) | 8 |
| `SimpleReconObject<ObjectSaveTypeTable3>::GetType(void)` | 0x8039F60C | this (r3) | 8 |
| `SimpleReconObject<ObjectSaveTypeTable>::GetType(void)` | 0x803A8284 | this (r3) | 8 |
| `SimpleReconObject<OptionsRecon>::GetType(void)` | 0x803A051C | this (r3) | 8 |
| `SimpleReconObject<ReconStreamPtrVector<Neighbor> >::GetType(void)` | 0x8039F440 | this (r3) | 8 |
| `SimpleReconObject<ReconStreamVector<SlotDescriptor> >::GetType(void)` | 0x803ADF60 | this (r3) | 8 |
| `SimpleReconObject<ThumbnailLoader>::GetType(void)` | 0x803A82B0 | this (r3) | 8 |
| `SimpleReconObject<UserDataSaveLoad>::GetType(void)` | 0x8039F46C | this (r3) | 8 |
| `SimpleReconObject<cSimulator>::GetType(void)` | 0x8039F4AC | this (r3) | 8 |
| `SpriteSlot::GetBalloonSpriteID(void) const` | 0x80145410 | this (r3) | 60 |
| `SpriteSlot::GetCurrentFrame(void) const` | 0x80145420 | this (r3) | 48 |
| `SpriteSlot::GetOptions(void) const` | 0x80145440 | this (r3) | 72 |
| `SpriteSlot::GetOverlaySpriteID(void) const` | 0x80145418 | this (r3) | 64 |
| `SpriteSlot::GetPPerson(void)` | 0x80145428 | this (r3) | 100 |
| `SpriteSlot::GetPriority(void) const` | 0x80145438 | this (r3) | 68 |
| `SpriteSlot::GetShowOverInactivePeople(void) const` | 0x80145454 | this (r3) | 96 |
| `SpriteSlot::GetSpriteID(void) const` | 0x80145408 | this (r3) | 24 |
| `StackElem::GetIgnoreDataBreakPoint(void) const` | 0x801491AC | this (r3) | 12 |
| `StateMachine::GetMachineId(void) const` | 0x80096B24 | this (r3) | 28 |
| `StateMachine::GetManager(void) const` | 0x80096B2C | this (r3) | 32 |
| `StateMachine::GetReturnVal(void) const` | 0x80096B3C | this (r3) | 144 |
| `StateMachine::IsEnabled(void)` | 0x80096B80 | this (r3) | 148 |
| `StateMachine::IsPausedUpdate(void)` | 0x80096B88 | this (r3) | 36 |
| `StringBuffer2::buffer(void)` | 0x800A6E70 | this (r3) | 0 |
| `StringBuffer2::c_str(void) const` | 0x800A6E68 | this (r3) | 0 |
| `StringBuffer2::capacity(void) const` | 0x800A6D1C | this (r3) | 4 |
| `StringBuffer::buffer(void)` | 0x800A6720 | this (r3) | 0 |
| `StringBuffer::c_str(void) const` | 0x800A6718 | this (r3) | 0 |
| `StringBuffer::capacity(void) const` | 0x800A65E4 | this (r3) | 4 |
| `THREADPOLL_MU_IsComplete(void)` | 0x80091654 | r13 (SDA) | -24652 |
| `TTabScratchEntry::GetAttenuation(void) const` | 0x80149E98 | this (r3) | 264 |
| `TextBaseItem::GetColor(void)` | 0x80087198 | this (r3) | 68 |
| `TextBaseItem::GetFont(void) const` | 0x80087354 | this (r3) | 80 |
| `TextBaseItem::GetStyle(void) const` | 0x800873A4 | this (r3) | 108 |
| `TextBaseItem::GetText(void) const` | 0x8008730C | this (r3) | 32 |
| `Timer_GetTicks(void)` | 0x800770D4 | r13 (SDA) | -24900 |
| `Timer_GetTotalTicks(void)` | 0x800770DC | r13 (SDA) | -24896 |
| `TreeSim::BreakOnCallTreeStringFailure(void)` | 0x8014927C | r13 (SDA) | -31632 |
| `TreeSim::GetBaseISimInstance(void)` | 0x8014920C | this (r3) | 16 |
| `TreeSim::GetESimPerson(void)` | 0x8014921C | this (r3) | 20 |
| `TreeSim::GetMaxIterations(void)` | 0x8014922C | r13 (SDA) | -31652 |
| `TreeSim::GetPerson(void) const` | 0x80149204 | this (r3) | 4 |
| `TreeSim::IsBreakForPrimTimeOn(void)` | 0x8014923C | r13 (SDA) | -31648 |
| `TreeSim::IsExecutingInMainSim(void)` | 0x8014928C | r13 (SDA) | -31656 |
| `TreeSim::TraceOnPrimTimeBreak(void)` | 0x8014926C | r13 (SDA) | -31636 |
| `TreeSimImpl::GetIterations(void)` | 0x80149294 | this (r3) | 4 |
| `TreeSimImpl::GetLastResult(void)` | 0x8014929C | this (r3) | 44 |
| `TreeTableAdQuickData::GetImplementation(void) const` | 0x8015E5DC | this (r3) | 4 |
| `TreeTableEntryQuickData::GetImplementation(void) const` | 0x8015E8A4 | this (r3) | 4 |
| `TreeTableQuickData::GetImplementation(void) const` | 0x8015E9A0 | this (r3) | 4 |
| `VIGetCurrentFrameBuffer` | 0x80264240 | r13 (SDA) | -23204 |
| `VIGetNextFrameBuffer` | 0x80264238 | r13 (SDA) | -23208 |
| `VIGetRetraceCount` | 0x80264430 | r13 (SDA) | -23284 |
| `VMGetARAMBase` | 0x80392264 | r13 (SDA) | -25224 |
| `VMGetARAMSize` | 0x8039225C | r13 (SDA) | -21888 |
| `VMGetPageReplacementPolicy` | 0x80392750 | r13 (SDA) | -25212 |
| `VMIsInitialized` | 0x803921A4 | r13 (SDA) | -21876 |
| `WAFTarget::IsWantsAndFearsActive(void)` | 0x801E38F8 | this (r3) | 136 |
| `WrapperPaneBase::GetAcceptButton(void)` | 0x800885B8 | this (r3) | 64 |
| `WrapperPaneBase::GetAlt1Button(void)` | 0x80088980 | this (r3) | 72 |
| `WrapperPaneBase::GetBackgroundShader(void)` | 0x80088200 | this (r3) | 24 |
| `WrapperPaneBase::GetDeclineButton(void)` | 0x8008879C | this (r3) | 68 |
| `WrapperPaneBase::GetPaneId(void)` | 0x80087A5C | this (r3) | 0 |
| `WrapperPaneBase::GetState(void) const` | 0x80087B1C | this (r3) | 52 |
| `XObjLang::GetSelector(void)` | 0x80152824 | this (r3) | 4 |
| `__AXGetCommandListCycles` | 0x80378AD4 | r13 (SDA) | -22216 |
| `__AXGetNumVoices` | 0x80379F7C | r13 (SDA) | -22096 |
| `__CARDGetDirBlock` | 0x80380F28 | this (r3) | 132 |
| `__CARDGetFatBlock` | 0x80380B24 | this (r3) | 136 |
| `__DSPGetCurrentTask` | 0x8037E62C | r13 (SDA) | -22016 |
| `__VMGetMRAMBase` | 0x8039226C | r13 (SDA) | -21892 |
| `__VMGetNumPagesInMRAM` | 0x80392254 | r13 (SDA) | -21884 |
| `__errno` | 0x8036EE20 | r13 (SDA) | -27948 |
| `_constructorObject(AptValue *, int)` | 0x802B0E44 | r13 (SDA) | -22936 |
| `cFixedWorldImpl::GetFloorLayer(void)` | 0x8014CDC4 | this (r3) | 44 |
| `cFixedWorldImpl::GetInfluenceMap(void)` | 0x8015235C | this (r3) | 60 |
| `cFixedWorldImpl::GetPassiveInfluenceMap(void)` | 0x80152364 | this (r3) | 64 |
| `cFixedWorldImpl::GetWalls(void)` | 0x8014CDCC | this (r3) | 56 |
| `cFixedWorldImpl::GetXSize(void) const` | 0x80151C30 | this (r3) | 20 |
| `cFixedWorldImpl::GetYSize(void) const` | 0x80151C38 | this (r3) | 24 |
| `cGZMusic::GetVolume(void)` | 0x800BAEBC | this (r3) | 20 |
| `cGZMusic::IsPlaying(void)` | 0x800BADA4 | this (r3) | 8 |
| `cGZSnd::GetPan(void)` | 0x800BA81C | this (r3) | 36 |
| `cGZSnd::GetVolume(void)` | 0x800BA668 | this (r3) | 32 |
| `cSimulatorImpl::GetArchValue(void)` | 0x80141B20 | this (r3) | 140 |
| `cSimulatorImpl::GetLotValue(void)` | 0x80141B10 | this (r3) | 132 |
| `cSimulatorImpl::GetObjectsValue(void)` | 0x80141B58 | this (r3) | 136 |
| `cSimulatorImpl::GetPassiveInfluenceSystem(void)` | 0x80141BA0 | this (r3) | 372 |
| `cSimulatorImpl::GetProbe(void)` | 0x80141B90 | this (r3) | 148 |
| `cSimulatorImpl::GetTicks(void)` | 0x80141AC8 | this (r3) | 124 |
| `cSimulatorImpl::IsStalled(void)` | 0x8014131C | this (r3) | 156 |
| `cTrack::InstanceId(void)` | 0x80119DC0 | this (r3) | 4 |
| `cTrack::IsPlaying(void)` | 0x80119DC8 | this (r3) | 52 |
| `cXObject::GetAutoCenter(void)` | 0x800D95FC | r13 (SDA) | -31904 |
| `cXObject::GetAutoReset(void)` | 0x800D960C | r13 (SDA) | -31900 |
| `cXObject::GetFreeWill(void)` | 0x800D95F4 | r13 (SDA) | -31912 |
| `cXObject::GetPersonWidth(void)` | 0x800D95EC | r13 (SDA) | -31916 |
| `cXObjectImpl::GetAutoCenter(void)` | 0x800EABCC | r13 (SDA) | -31904 |
| `cXObjectImpl::GetAutoReset(void)` | 0x800EABDC | r13 (SDA) | -31900 |
| `cXObjectImpl::GetDef(void)` | 0x800EB2CC | this (r3) | 136 |
| `cXObjectImpl::GetFreeWill(void)` | 0x800EABC4 | r13 (SDA) | -31912 |
| `cXObjectImpl::GetLevel(void) const` | 0x800E2AC4 | this (r3) | 128 |
| `cXObjectImpl::GetModule(void)` | 0x800EB10C | this (r3) | 88 |
| `cXObjectImpl::GetNextImpl(void)` | 0x800EB844 | this (r3) | 92 |
| `cXObjectImpl::GetNumAttr(void)` | 0x800EAA3C | this (r3) | 12 |
| `cXObjectImpl::GetRelMatrix(void)` | 0x800EB3EC | this (r3) | 96 |
| `cXObjectImpl::GetSelector(void)` | 0x800EB328 | this (r3) | 140 |
| `cXObjectImpl::GetSelector(void) const` | 0x800EB330 | this (r3) | 140 |
| `cXObjectImpl::GetSpriteSlot(void)` | 0x800DE780 | this (r3) | 176 |
| `cXObjectImpl::GetSyncObject(void)` | 0x800EAB38 | this (r3) | 220 |
| `cXObjectImpl::WaitingForSync(void)` | 0x800EAB4C | this (r3) | 228 |
| `cXPersonImpl::GetLastMotiveUpdateTick(void)` | 0x8012CA00 | this (r3) | 1336 |
| `cXPersonImpl::GetMotiveEffects(void)` | 0x8012C988 | this (r3) | 1032 |
| `cXPersonImpl::GetRecordCurTicks(void)` | 0x8012C9C0 | this (r3) | 1084 |
| `cXPersonImpl::GetRecordDuration(void)` | 0x8012C998 | this (r3) | 1076 |
| `cXPersonImpl::GetRecordMaxDuration(void)` | 0x8012C9A8 | this (r3) | 1080 |
| `cXPersonImpl::GetRecordSkill(void)` | 0x8012C9D0 | this (r3) | 1096 |
| `cXPersonImpl::GetRecordStartTicks(void)` | 0x8012C9B8 | this (r3) | 1088 |
| `cXPersonImpl::GetRecordTicksElapsed(void)` | 0x8012C9C8 | this (r3) | 1092 |
| `cXPersonImpl::GetRecording(void)` | 0x8012C990 | this (r3) | 1072 |
| `cXPersonImpl::GetSAnimator(void) const` | 0x8012C7EC | this (r3) | 1012 |
| `cXPersonImpl::IgnoringObject(void)` | 0x8012CA10 | this (r3) | 1340 |
| `cXPersonImpl::IsFirstPlayerInSocialMode(void)` | 0x8012CA4C | this (r3) | 1348 |
| `cXPersonImpl::IsSecondPlayerInSocialMode(void)` | 0x8012CA44 | this (r3) | 1352 |
| `cXPersonImpl::IsWaitingForSocialMode(void)` | 0x8012CA54 | this (r3) | 1356 |
| `iResFile::GetError(void)` | 0x80135624 | this (r3) | 4 |
| `iResFile::GetResFileData(void) const` | 0x801358B8 | this (r3) | 8 |

</details>

#### Load Float Getter (61 functions)

Pattern: `lfs fX, offset(rX); blr` -- C++: `return this->float_field;`

#### Move Register (38 functions)

Pattern: `mr r3, rX; blr` -- C++: `return param;`

#### Address-of / Offset Getter (74 functions)

Pattern: `addi r3, rX, N; blr` -- C++: `return &this->field;`

#### Load Byte Getter (12 functions)

Pattern: `lbz r3, offset(rX); blr` -- C++: `return this->byte_field;`

#### Load Halfword Getter (11 functions)

Pattern: `lhz r3, offset(rX); blr` -- C++: `return this->short_field;`

### Tier 3: TRIVIAL -- Setters (8 bytes, stw/stfs+blr)

**196 functions** -- Store + return. C++: `void Set(T v) { field = v; }`

- Store word + blr: 170 functions
- Store float + blr: 26 functions

### Tier 4: EASY -- 12-byte Functions Ending in blr

**746 functions** -- 3 instructions ending in blr.
Common patterns: load a field from a struct member, boolean flag checks, simple delegation (load + call via indirect), or two-step getters.

These require reading the disassembly to understand the pattern but are still straightforward to match.

### Tier 5: STRAIGHTFORWARD -- Other Small Functions (4-16b, non-trivial patterns)

**370 functions** -- Small but with non-blr endings or unusual patterns. May include conditional branches, multiple fields, or small logic. Require individual analysis but are still quick to match.

### Tier 6: MODERATE -- Medium Functions (20-64 bytes)

**4567 functions** (199,680 bytes)

These are 5-16 instruction functions. Common patterns:
- Simple wrappers: prologue, call, epilogue
- Multi-field setters: set 2-3 struct members
- Switch dispatch: small switch/case on an enum
- Constructors: vtable setup + member init

Of these, **4558** end with blr (well-formed standalone functions).

### Tier 7: COMPLEX -- Large Functions (65+ bytes)

**10800 functions** (3,918,644 bytes, 94.5% of all code)

These require full decompilation effort: understanding control flow, data structures, and compiler idioms. Most of the actual game logic lives here.

## Summary Table

| Tier | Description | Count | % | Bytes | Effort |
|------|-------------|------:|--:|------:|--------|
| 1 | blr / tail-call | 615 | 3.3% | 2,460 | Zero -- write empty body |
| 2 | Trivial getter (8b) | 1,165 | 6.3% | 9,320 | One-liner return |
| 3 | Trivial setter (8b) | 196 | 1.1% | 1,568 | One-liner assignment |
| 4 | Easy 3-instr (12b) | 746 | 4.0% | 8,952 | Read disasm, write 1-2 lines |
| 5 | Other small (4-16b) | 370 | 2.0% | 5,108 | Individual analysis, quick |
| 6 | Medium (20-64b) | 4,567 | 24.7% | 199,680 | ~5-15 min each |
| 7 | Large (65b+) | 10,800 | 58.5% | 3,918,644 | Full decompilation |
| | **Total** | **18,459** | | **4,145,732** | |

## Recommended Attack Order

### Phase 1: Free Wins (Tiers 1-3) -- ~2,776 functions

Write a script that auto-generates C++ stubs for all Tier 1-3 functions.
These need zero human analysis:

```cpp
// Tier 1: blr-only (614 functions)
void ACTTarget::DebugListValidation() {}

// Tier 2: return constant (426 functions)
int ESimsApp::GetDefaultLanguage() { return 0; }
bool AptViewer::UIOn() { return true; }

// Tier 2: return field (543 functions)
int ESim::GetShadow() { return m_shadow; } // lwz r3,992(r3)

// Tier 3: setter (196 functions)
void ESim::SetField(int v) { m_field = v; } // stw r4,offset(r3)
```

### Phase 2: Easy Picks (Tier 4) -- ~746 functions

Run `tools/disasm.py` on each, identify the 3-instruction pattern, write the 1-2 line C++ body. ~2-5 minutes per function.

### Phase 3: Small Logic (Tier 5) -- ~370 functions

Similar to Phase 2 but may need conditional logic or multi-step operations.

### Phase 4: Medium Functions (Tier 6) -- ~4,567 functions

Start with functions that have clear prologue/epilogue patterns. Focus on high-value source files first:

| Source File | Trivial | Total | Priority |
|------------|--------:|------:|----------|
| targets_s2c.obj | 96 | 934 | HIGH |
| wrapper.obj | 69 | 258 | HIGH |
| treetablequickdata.obj | 65 | 122 | HIGH |
| slots.obj | 56 | 149 | HIGH |
| e_instance.obj | 56 | 98 | HIGH |
| libaptz.a(AptValue.cpp.obj) | 52 | 130 | HIGH |
| object.obj | 51 | 242 | HIGH |
| person.obj | 49 | 221 | HIGH |
| engine_ngc_release_dvd.lib(e_graphics.obj) | 44 | 93 | HIGH |
| iobject.obj | 41 | 191 | HIGH |
| treetab.obj | 40 | 88 | HIGH |
| base.a(PPCArch.o) | 38 | 44 | HIGH |
| sanimator2.obj | 37 | 229 | HIGH |
| treesim.obj | 34 | 81 | HIGH |
| interaction.obj | 32 | 65 | HIGH |
| nghresfile.obj | 32 | 136 | HIGH |
| mustates.obj | 31 | 98 | HIGH |
| quickresfile.obj | 28 | 37 | MEDIUM |
| camera.obj | 27 | 164 | MEDIUM |
| isiminstance.obj | 27 | 51 | MEDIUM |

### Phase 5: Full Decomp (Tier 7) -- ~10,800 functions

The bulk of the work. Follow the milestone plan in CLAUDE.md. Focus on one system at a time (memory, boot, main loop, etc.).

## Tool Usage

### Disassemble a function
```bash
python tools/disasm.py "ESimsApp::GetStartLot"
```

### Match helper (shows disasm + suggests C++)
```bash
python tools/match_function.py "ESimsApp::GetStartLot"
```

### List functions in a class
```bash
python tools/disasm.py --list "ESim::"
```
