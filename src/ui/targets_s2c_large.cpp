// targets_s2c_large.cpp - Large UI/APT functions (257-1024 bytes)
// Object file: targets_s2c.obj
// 214 functions, 104416 bytes

#include "types.h"
#include "stub_classes.h"

// ============================================================================
// ACTTarget::~ACTTarget(void) - 0x801A19B0 | 620 bytes
// ============================================================================
// NON_MATCHING
void ACTTarget__dtor_ACTTarget(void* self) {
    // Stack: 72 bytes
    // -> sub_8039BE60
    // -> UIScreenManager::UnloadUIScreen(UIScreenID)
    // -> GetVariableCommandTable::UnInstallAllCommands(CBFunctor1wRet<char *, char *> &)
    // -> SetVariableCommandTable::UnInstallAllCommands(CBFunctor2<char *, char *> &)
    // -> GetLocalizableCommandTable::UnInstallAllCommands(CBFunctor1wRet<char *, unsigned wchar_t *> &)
    // -> UIUpdateTable::UnInstallEntry(CBFunctor0 &)
    // ... and 8 more calls
    // Contains loop(s)

    // Release resources
    // __builtin_delete called for cleanup
    // Destroy members
}

// ============================================================================
// ACTTarget::SetVariable(char *, char *) - 0x801A1C1C | 288 bytes
// ============================================================================
// NON_MATCHING
void ACTTarget__SetVariable(void* self, char* p1, char* p2) {
    // Stack: 56 bytes
    // -> isdigit
    // -> strncmp
    // -> Sscanf(char *, char *,...)
    // -> strcmp
    // -> UIReflow::UIReflow(void)
    // -> UIReflow::ResetVisibility(char *, bool, int)
    // ... and 1 more calls

    // Setter
}

// ============================================================================
// ACTTarget::Update(void) - 0x801A1E58 | 916 bytes
// ============================================================================
// NON_MATCHING
void ACTTarget__Update(void* self) {
    // Stack: 96 bytes
    // -> InteractorModule::InteractorManager::GetSingleton(void)
    // -> InteractorModule::InteractorManager::IsInitialized(void)
    // -> InteractorModule::InteractorManager::GetPlayerInteractor(int, InteractorModule::InteractorType)
    // -> EGlobal::GetSelectedPerson(int)
    // -> ACTTarget::HideActionQueue(void)
    // -> ACTTarget::ShowActionQueue(void)
    // ... and 11 more calls
    // Contains loop(s)
    // Accesses globals via r13 (SDA)

    // Per-frame update
    // Iterates over elements
}

// ============================================================================
// ACTTarget::UpdateActionQueue(void) - 0x801A2204 | 440 bytes
// ============================================================================
// NON_MATCHING
void ACTTarget__UpdateActionQueue(void* self) {
    // Stack: 48 bytes
    // -> UIReflow::UIReflow(void)
    // -> UIReflow::OpenTweenBlock(char *, unsigned int, unsigned int, char *, int)
    // -> UIReflow::Tween_Alpha(unsigned int)
    // -> UIReflow::Tween_X(int)
    // -> UIReflow::Tween_Y(int)
    // -> UIReflow::SubmitTweenBlock(void)
    // ... and 3 more calls
    // Contains loop(s)

    // Per-frame update
    // Iterates over elements
}

// ============================================================================
// ACTTarget::AddAction(int, Interaction *, BString2 &, unsigned int, ERShader *, unsigned int) - 0x801A23C4 | 500 bytes
// ============================================================================
// NON_MATCHING
void ACTTarget__AddAction(void* self, int p1, void* p2, void* p3, int p4, void* p5, int p6) {
    // Stack: 72 bytes
    // -> Interaction::GetPerson(void) const
    // -> __builtin_new
    // -> BString2::BString2(void)
    // -> BString2::operator=(BString2 &)
    // -> sub_8039C304
    // -> EResource::AddRef(void)
    // Contains loop(s)

    // Add element
}

// ============================================================================
// ACTTarget::PlaceItem(ACTTarget::ACTRecord *, int, Interaction *, int, cXPerson *, BString2 &, unsigned int, ERShader *, unsigned int) - 0x801A25B8 | 624 bytes
// ============================================================================
// NON_MATCHING
void ACTTarget__PlaceItem(void* self, void* p1, int p2, void* p3, int p4, void* p5, void* p6, int p7, void* p8, int p9) {
    // Stack: 56 bytes
    // -> UI2D::InstallEntry(char *, ERShader *, char *, int)
    // -> UI2D::InstallEntry(char *, unsigned int, char *, int)
    // -> ACTTarget::DebugListValidation(void)
    // -> ACTTarget::ReOrderActionQueue(void)
    // -> UIReflow::UIReflow(void)
    // -> UIReflow::OpenReflowBlock(void)
    // ... and 13 more calls
    // Contains loop(s)

}

// ============================================================================
// ACTTarget::RemoveAction(int, Interaction *) - 0x801A2828 | 644 bytes
// ============================================================================
// NON_MATCHING
void ACTTarget__RemoveAction(void* self, int p1, void* p2) {
    // Stack: 72 bytes
    // -> Interaction::GetPerson(void) const
    // -> sub_8039BE60
    // -> ACTTarget::UpdateCancelModeWidgets(void)
    // -> ACTTarget::ExitCancelMode(void)
    // -> ACTTarget::DebugListValidation(void)
    // -> ACTTarget::ReOrderActionQueue(void)
    // Contains loop(s)
    // Uses floating point

    // Remove element
}

// ============================================================================
// ACTTarget::CancelCurrentObject(void) - 0x801A2E30 | 360 bytes
// ============================================================================
// NON_MATCHING
int ACTTarget__CancelCurrentObject(void* self) {
    // Stack: 24 bytes
    // -> ACTTarget::GetInteractionFromID(int)
    // -> Interaction::GetPerson(void) const
    // -> __builtin_new
    // -> UIAUDIO::UIAUDIO(void)
    // -> UIAUDIO::PlaySound(unsigned int)
    // -> ACTTarget::UpdateCancelModeWidgets(void)
    // ... and 1 more calls
    // Accesses globals via r13 (SDA)

    return 0;
}

// ============================================================================
// ACTTarget::UpdateCancelModeWidgets(void) - 0x801A2F98 | 264 bytes
// ============================================================================
// NON_MATCHING
void ACTTarget__UpdateCancelModeWidgets(void* self) {
    // Stack: 40 bytes
    // -> UIReflow::UIReflow(void)
    // -> UIReflow::OpenReflowBlock(void)
    // -> UIReflow::Reflow_Id(char *, int)
    // -> UIReflow::Reflow_Visibility(bool)
    // -> UIReflow::Reflow_X(int)
    // -> UIReflow::Reflow_Y(int)
    // ... and 3 more calls

    // Per-frame update
}

// ============================================================================
// BBHTarget::~BBHTarget(void) - 0x801A3788 | 388 bytes
// ============================================================================
// NON_MATCHING
void BBHTarget__dtor_BBHTarget(void* self) {
    // Stack: 16 bytes
    // -> UIScreenManager::UnloadUIScreen(UIScreenID)
    // -> GetVariableCommandTable::UnInstallAllCommands(CBFunctor1wRet<char *, char *> &)
    // -> SetVariableCommandTable::UnInstallAllCommands(CBFunctor2<char *, char *> &)
    // -> GetLocalizableCommandTable::UnInstallAllCommands(CBFunctor1wRet<char *, unsigned wchar_t *> &)
    // -> UIUpdateTable::UnInstallEntry(CBFunctor0 &)
    // -> UIDrawTable::UnInstallEntry(CBFunctor1<ERC *> &)
    // ... and 5 more calls

    // Release resources
    // __builtin_delete called for cleanup
    // Destroy members
}

// ============================================================================
// BBHTarget::GetLocalizable(char *) - 0x801A3A54 | 620 bytes
// ============================================================================
// NON_MATCHING
void* BBHTarget__GetLocalizable(void* self, char* p1) {
    // Stack: 56 bytes
    // -> isdigit
    // -> SimsAptMalloc(unsigned int)
    // -> strcmp
    // -> UIObjectBase::makeMoneyString(int, unsigned wchar_t *, bool)
    // -> EGlobal::GetPDAString(char *)
    // -> wcscpy
    // ... and 3 more calls
    // Accesses globals via r13 (SDA)

    // Getter
    return 0;
}

// ============================================================================
// BBHTarget::Update(void) - 0x801A3CC0 | 368 bytes
// ============================================================================
// NON_MATCHING
void BBHTarget__Update(void* self) {
    // Stack: 48 bytes
    // -> UIReflow::UIReflow(void)
    // -> UIReflow::OpenReflowBlock(void)
    // -> UIReflow::Reflow_Id(char *, int)
    // -> UIReflow::Reflow_Visibility(bool)
    // -> UIReflow::Reflow_FontSizeOverride(unsigned int)
    // -> UIReflow::SubmitReflowBlock(void)
    // ... and 6 more calls

    // Per-frame update
}

// ============================================================================
// CRDTarget::~CRDTarget(void) - 0x801A4848 | 444 bytes
// ============================================================================
// NON_MATCHING
void CRDTarget__dtor_CRDTarget(void* self) {
    // Stack: 16 bytes
    // -> CRDTarget::HidePhoto(void)
    // -> CRDTarget::EndCredits(void)
    // -> UIScreenManager::UnloadUIScreen(UIScreenID)
    // -> GetVariableCommandTable::UnInstallAllCommands(CBFunctor1wRet<char *, char *> &)
    // -> SetVariableCommandTable::UnInstallAllCommands(CBFunctor2<char *, char *> &)
    // -> GetLocalizableCommandTable::UnInstallAllCommands(CBFunctor1wRet<char *, unsigned wchar_t *> &)
    // ... and 7 more calls

    // Release resources
    // __builtin_delete called for cleanup
    // Destroy members
}

// ============================================================================
// CRDTarget::GetVariable(char *) - 0x801A4AE4 | 260 bytes
// ============================================================================
// NON_MATCHING
void* CRDTarget__GetVariable(void* self, char* p1) {
    // Stack: 24 bytes
    // -> isdigit
    // -> SimsAptMalloc(unsigned int)
    // -> strcmp
    // -> Sprintf(char *, char *,...)

    // Getter
    return 0;
}

// ============================================================================
// CRDTarget::Update(void) - 0x801A4C70 | 336 bytes
// ============================================================================
// NON_MATCHING
void CRDTarget__Update(void* self) {
    // Stack: 48 bytes
    // -> EGlobal::IsPlayerCheatOn(int) const
    // -> CRDTarget::ShowPhoto(void)
    // -> CRDTarget::HidePhoto(void)
    // -> UIReflow::UIReflow(void)
    // -> UIReflow::ResetPosition(char *, int, int, int)
    // -> UIReflow::~UIReflow(void)
    // Uses floating point

    // Per-frame update
}

// ============================================================================
// CRDTarget::ShowCredits(void) - 0x801A4DC0 | 300 bytes
// ============================================================================
// NON_MATCHING
void CRDTarget__ShowCredits(void* self) {
    // Stack: 40 bytes
    // -> EGlobal::IsPlayerCheatOn(int) const
    // -> UIScreenManager::LoadUIScreen(UIScreenID, UIScreenInputMode)
    // -> UIReflow::UIReflow(void)
    // -> UIReflow::OpenReflowBlock(void)
    // -> UIReflow::Reflow_Id(char *, int)
    // -> UIReflow::Reflow_Alpha(unsigned int)
    // ... and 6 more calls

}

// ============================================================================
// CSMTarget::~CSMTarget(void) - 0x801A6980 | 436 bytes
// ============================================================================
// NON_MATCHING
void CSMTarget__dtor_CSMTarget(void* self) {
    // Stack: 32 bytes
    // -> BString2::~BString2(void)
    // -> UIScreenManager::UnloadUIScreen(UIScreenID)
    // -> GetVariableCommandTable::UnInstallAllCommands(CBFunctor1wRet<char *, char *> &)
    // -> SetVariableCommandTable::UnInstallAllCommands(CBFunctor2<char *, char *> &)
    // -> GetLocalizableCommandTable::UnInstallAllCommands(CBFunctor1wRet<char *, unsigned wchar_t *> &)
    // -> UIUpdateTable::UnInstallEntry(CBFunctor0 &)
    // ... and 6 more calls
    // Contains loop(s)

    // Release resources
    // __builtin_delete called for cleanup
    // Destroy members
}

// ============================================================================
// CSMTarget::SetVariable(char *, char *) - 0x801A6B34 | 264 bytes
// ============================================================================
// NON_MATCHING
void CSMTarget__SetVariable(void* self, char* p1, char* p2) {
    // Stack: 48 bytes
    // -> isdigit
    // -> strcmp
    // -> UIReflow::UIReflow(void)
    // -> UIReflow::ResetVisibility(char *, bool, int)
    // -> UIReflow::~UIReflow(void)
    // Accesses globals via r13 (SDA)

    // Setter
}

// ============================================================================
// CSMTarget::GetLocalizable(char *) - 0x801A6CD4 | 300 bytes
// ============================================================================
// NON_MATCHING
void* CSMTarget__GetLocalizable(void* self, char* p1) {
    // Stack: 32 bytes
    // -> isdigit
    // -> SimsAptMalloc(unsigned int)
    // -> strncmp
    // -> Sscanf(char *, char *,...)
    // -> BString2::c_str(void) const
    // -> wcscpy
    // ... and 4 more calls

    // Getter
    return 0;
}

// ============================================================================
// CSPTarget::~CSPTarget(void) - 0x801A8A74 | 508 bytes
// ============================================================================
// NON_MATCHING
void CSPTarget__dtor_CSPTarget(void* self) {
    // Stack: 16 bytes
    // -> UIObjectBase::popAptButtonFilter(int, unsigned int)
    // -> UIScreenManager::UnloadUIScreen(UIScreenID)
    // -> GetVariableCommandTable::UnInstallAllCommands(CBFunctor1wRet<char *, char *> &)
    // -> SetVariableCommandTable::UnInstallAllCommands(CBFunctor2<char *, char *> &)
    // -> GetLocalizableCommandTable::UnInstallAllCommands(CBFunctor1wRet<char *, unsigned wchar_t *> &)
    // -> UIUpdateTable::UnInstallEntry(CBFunctor0 &)
    // ... and 9 more calls

    // Release resources
    // __builtin_delete called for cleanup
    // Destroy members
}

// ============================================================================
// CSPTarget::SetVariable(char *, char *) - 0x801A8C70 | 344 bytes
// ============================================================================
// NON_MATCHING
void CSPTarget__SetVariable(void* self, char* p1, char* p2) {
    // Stack: 24 bytes
    // -> isdigit
    // -> strcmp
    // -> HelpDialog::SpawnHelpDialog(int, char *, HelpDialogCallback *, bool, char *)
    // -> AtoI(char *)
    // -> CSPTarget::ChangeSelectedTab(CSPTarget::eTabs)

    // Setter
}

// ============================================================================
// CSPTarget::GetVariable(char *) - 0x801A8DC8 | 668 bytes
// ============================================================================
// NON_MATCHING
void* CSPTarget__GetVariable(void* self, char* p1) {
    // Stack: 40 bytes
    // -> isdigit
    // -> SimsAptMalloc(unsigned int)
    // -> strcmp
    // -> BString2::length(void) const
    // -> strncmp
    // -> Sscanf(char *, char *,...)
    // ... and 1 more calls

    // Getter
    return 0;
}

// ============================================================================
// CSPTarget::ChangeSelectedTab(CSPTarget::eTabs) - 0x801A991C | 328 bytes
// ============================================================================
// NON_MATCHING
void CSPTarget__ChangeSelectedTab(void* self, void* p1) {
    // Stack: 16 bytes
    // -> UI2D::InstallEntry(char *, unsigned int, char *, int)

}

// ============================================================================
// CSPTarget::InstallPromotionShaders(void) - 0x801AA0A0 | 360 bytes
// ============================================================================
// NON_MATCHING
void CSPTarget__InstallPromotionShaders(void* self) {
    // Stack: 40 bytes
    // -> get_blank_shader_id(void)
    // -> UI2D::InstallEntry(char *, unsigned int, char *, int)
    // Contains loop(s)

}

// ============================================================================
// CSPTarget::SetupSkills(cXPerson *) - 0x801AA208 | 388 bytes
// ============================================================================
// NON_MATCHING
void CSPTarget__SetupSkills(void* self, void* p1) {
    // Stack: 24 bytes

    // Setter
}

// ============================================================================
// CSPTarget::SetupPersonality(cXPerson *) - 0x801AA38C | 496 bytes
// ============================================================================
// NON_MATCHING
void CSPTarget__SetupPersonality(void* self, void* p1) {
    // Stack: 24 bytes
    // -> ComputeZodiacSign(short *)
    // -> GetZodiacName(short)
    // -> BString2::operator=(unsigned wchar_t *)
    // -> UI2D::InstallEntry(char *, unsigned int, char *, int)
    // -> get_blank_shader_id(void)
    // Contains loop(s)

    // Setter
}

// ============================================================================
// E2ETarget::~E2ETarget(void) - 0x801ABCB8 | 592 bytes
// ============================================================================
// NON_MATCHING
void E2ETarget__dtor_E2ETarget(void* self) {
    // Stack: 24 bytes
    // -> UIObjectBase::popAptButtonFilter(int, unsigned int)
    // -> EyeToyClient::SetUnplugCallback(void (*)(int))
    // -> EyeToyClient::CloseSession(void)
    // -> MainHeap(void)
    // -> EAHeap::Free(void *)
    // -> UIScreenManager::UnloadUIScreen(UIScreenID)
    // ... and 26 more calls
    // Accesses globals via r13 (SDA)

    // Release resources
    // EAHeap::Free(void *) called for cleanup
    // __builtin_delete called for cleanup
    // Destroy members
}

// ============================================================================
// E2ETarget::GetVariable(char *) - 0x801AC38C | 620 bytes
// ============================================================================
// NON_MATCHING
void* E2ETarget__GetVariable(void* self, char* p1) {
    // Stack: 24 bytes
    // -> isdigit
    // -> SimsAptMalloc(unsigned int)
    // -> strcmp
    // -> Sprintf(char *, char *,...)
    // Uses floating point
    // Accesses globals via r13 (SDA)

    // Getter
    return 0;
}

// ============================================================================
// E2ETarget::GetLocalizable(char *) - 0x801AC5F8 | 868 bytes
// ============================================================================
// NON_MATCHING
void* E2ETarget__GetLocalizable(void* self, char* p1) {
    // Stack: 320 bytes
    // -> isdigit
    // -> strncpy
    // -> SimsAptMalloc(unsigned int)
    // -> strcmp
    // -> E2ETarget::GetText(char *)
    // -> wcscpy
    // ... and 6 more calls

    // Getter
    return 0;
}

// ============================================================================
// E2ETarget::E2ERenderCallback(ERC *, structDrawCBparams *) - 0x801ACA58 | 476 bytes
// ============================================================================
// NON_MATCHING
void E2ETarget__E2ERenderCallback(void* self, void* p1, void* p2) {
    // Stack: 72 bytes
    // -> EyeToyClient::GetSessionTexture(void)
    // Uses floating point
    // Accesses globals via r13 (SDA)

    // Render pass
    // Computes positions/transforms
}

// ============================================================================
// E2ETarget::SpawnNoEyeToyDialogBox(void) - 0x801ACC80 | 548 bytes
// ============================================================================
// NON_MATCHING
void E2ETarget__SpawnNoEyeToyDialogBox(void* self) {
    // Stack: 72 bytes
    // -> EGlobal::GetNewUIString(char *)
    // -> BString2::operator=(unsigned wchar_t *)
    // -> memcpy
    // -> UIDialog::SpawnDialog(void)

}

// ============================================================================
// E2ETarget::SetTopLevelState(char *, char *) - 0x801AD040 | 448 bytes
// ============================================================================
// NON_MATCHING
void E2ETarget__SetTopLevelState(void* self, char* p1, char* p2) {
    // Stack: 280 bytes
    // -> AtoI(char *)
    // -> E2ETarget::OnTopLevelStateChange(char *, char *)
    // Contains loop(s)

    // Setter
}

// ============================================================================
// E2ETarget::OnTopLevelStateChange(char *, char *) - 0x801AD200 | 376 bytes
// ============================================================================
// NON_MATCHING
void E2ETarget__OnTopLevelStateChange(void* self, char* p1, char* p2) {
    // Stack: 40 bytes
    // -> UIReflow::UIReflow(void)
    // -> UIReflow::OpenReflowBlock(void)
    // -> E2ETarget::SaveCurrentSettings(char *, char *)
    // -> UIReflow::Reflow_Id(char *, int)
    // -> UIReflow::Reflow_Visibility(bool)
    // -> EyeToyClient::StartStream(void)
    // ... and 5 more calls

}

// ============================================================================
// E2ETarget::OnXKeyPressed(char *, char *) - 0x801AD704 | 284 bytes
// ============================================================================
// NON_MATCHING
void E2ETarget__OnXKeyPressed(void* self, char* p1, char* p2) {
    // Stack: 272 bytes
    // -> Sprintf(char *, char *,...)
    // Accesses globals via r13 (SDA)

}

// ============================================================================
// E2ETarget::OnRightKeyPressed(char *, char *) - 0x801AD8A0 | 476 bytes
// ============================================================================
// NON_MATCHING
void E2ETarget__OnRightKeyPressed(void* self, char* p1, char* p2) {
    // Stack: 272 bytes
    // -> EyeToyClient::GetHue(void)
    // -> Sprintf(char *, char *,...)
    // -> EyeToyClient::GetSaturation(void)
    // -> EyeToyClient::GetBrightness(void)
    // -> EyeToyClient::GetExposure(void)
    // Uses floating point
    // Accesses globals via r13 (SDA)

}

// ============================================================================
// E2ETarget::OnLeftKeyPressed(char *, char *) - 0x801ADA7C | 468 bytes
// ============================================================================
// NON_MATCHING
void E2ETarget__OnLeftKeyPressed(void* self, char* p1, char* p2) {
    // Stack: 272 bytes
    // -> EyeToyClient::GetHue(void)
    // -> Sprintf(char *, char *,...)
    // -> E2ETarget::UpdateHue(char *, char *)
    // -> EyeToyClient::GetSaturation(void)
    // -> E2ETarget::UpdateSaturation(char *, char *)
    // -> EyeToyClient::GetBrightness(void)
    // ... and 6 more calls
    // Uses floating point

}

// ============================================================================
// E2ETarget::UpdateText(void) - 0x801ADC50 | 516 bytes
// ============================================================================
// NON_MATCHING
void E2ETarget__UpdateText(void* self) {
    // Stack: 40 bytes
    // -> UIReflow::UIReflow(void)
    // -> UIReflow::OpenReflowBlock(void)
    // -> UIReflow::Reflow_Id(char *, int)
    // -> UIReflow::Reflow_Visibility(bool)
    // -> UIReflow::SubmitReflowBlock(void)
    // -> UIReflow::~UIReflow(void)

    // Per-frame update
}

// ============================================================================
// E2ETarget::GetText(char *) - 0x801ADE54 | 508 bytes
// ============================================================================
// NON_MATCHING
void* E2ETarget__GetText(void* self, char* p1) {
    // Stack: 528 bytes
    // -> strcmp
    // -> wcscpy
    // -> wcslen
    // -> SimsAptMalloc(unsigned int)

    // Getter
    return 0;
}

// ============================================================================
// E2ETarget::UpdateShaders(char *, char *) - 0x801AE0C0 | 292 bytes
// ============================================================================
// NON_MATCHING
void E2ETarget__UpdateShaders(void* self, char* p1, char* p2) {
    // Stack: 16 bytes
    // -> strcmp
    // -> AtoI(char *)
    // -> UI2D::InstallEntry(char *, unsigned int, char *, int)
    // Accesses globals via r13 (SDA)

    // Per-frame update
}

// ============================================================================
// E2ETarget::LaunchSaveSettingsDialog(void) - 0x801AE2C4 | 592 bytes
// ============================================================================
// NON_MATCHING
void E2ETarget__LaunchSaveSettingsDialog(void* self) {
    // Stack: 80 bytes
    // -> EGlobal::GetNewUIString(char *)
    // -> BString2::operator=(unsigned wchar_t *)
    // -> memcpy
    // -> UIDialog::SpawnDialog(void)

    // Setter
}

// ============================================================================
// E2ETarget::SpawnSaveGameDialog(void) - 0x801AE5E0 | 600 bytes
// ============================================================================
// NON_MATCHING
void E2ETarget__SpawnSaveGameDialog(void* self) {
    // Stack: 80 bytes
    // -> EGlobal::GetNewUIString(char *)
    // -> BString2::operator=(unsigned wchar_t *)
    // -> EGlobal::GetMemCardString(char *)
    // -> memcpy
    // -> UIDialog::SpawnDialog(void)

    // Save/write data
}

// ============================================================================
// FAMTarget::~FAMTarget(void) - 0x801AFB4C | 352 bytes
// ============================================================================
// NON_MATCHING
void FAMTarget__dtor_FAMTarget(void* self) {
    // Stack: 16 bytes
    // -> FAMTarget::UnloadScreen(void)
    // -> GetVariableCommandTable::UnInstallAllCommands(CBFunctor1wRet<char *, char *> &)
    // -> SetVariableCommandTable::UnInstallAllCommands(CBFunctor2<char *, char *> &)
    // -> GetLocalizableCommandTable::UnInstallAllCommands(CBFunctor1wRet<char *, unsigned wchar_t *> &)
    // -> UIUpdateTable::UnInstallEntry(CBFunctor0 &)
    // -> UIDrawTable::UnInstallEntry(CBFunctor1<ERC *> &)
    // ... and 7 more calls

    // Release resources
    // __builtin_delete called for cleanup
    // Destroy members
}

// ============================================================================
// FAMTarget::SetVariable(char *, char *) - 0x801AFCD8 | 480 bytes
// ============================================================================
// NON_MATCHING
void FAMTarget__SetVariable(void* self, char* p1, char* p2) {
    // Stack: 24 bytes
    // -> isdigit
    // -> strcmp
    // -> FAMTarget::Shutdown(void)
    // -> FAMTarget::UpdateMenuState(char *, char *)
    // -> FAMTarget::SetCurrentChoice(char *)
    // -> FAMTarget::OnLeftKeyPressed(char *, char *)
    // ... and 5 more calls
    // Accesses globals via r13 (SDA)

    // Setter
}

// ============================================================================
// FAMTarget::GetVariable(char *) - 0x801B05E0 | 300 bytes
// ============================================================================
// NON_MATCHING
void* FAMTarget__GetVariable(void* self, char* p1) {
    // Stack: 32 bytes
    // -> isdigit
    // -> SimsAptMalloc(unsigned int)
    // -> strcmp
    // -> strncmp
    // -> AtoI(char *)
    // -> FAMTarget::GetLotForFamily(int)
    // ... and 1 more calls
    // Accesses globals via r13 (SDA)

    // Getter
    return 0;
}

// ============================================================================
// FAMTarget::UpdateOccupiedShaders(void) - 0x801B07B0 | 416 bytes
// ============================================================================
// NON_MATCHING
void FAMTarget__UpdateOccupiedShaders(void* self) {
    // Stack: 48 bytes
    // -> ObjSelector::GetThumbnail(ERShader **)
    // -> UI2D::InstallEntry(char *, ERShader *, char *, int)
    // -> EResource::DelRef(void)
    // -> UI2D::InstallEntry(char *, unsigned int, char *, int)
    // Contains loop(s)
    // Accesses globals via r13 (SDA)

    // Per-frame update
    // Iterates over elements
}

// ============================================================================
// FAMTarget::UpdateLotSelectShaders(void) - 0x801B0950 | 456 bytes
// ============================================================================
// NON_MATCHING
void FAMTarget__UpdateLotSelectShaders(void* self) {
    // Stack: 48 bytes
    // -> FAMTarget::ConvertSelectedLotIndexToActualGameIndex(int)
    // -> ObjSelector::GetThumbnail(ERShader **)
    // -> UI2D::InstallEntry(char *, ERShader *, char *, int)
    // -> EResource::DelRef(void)
    // -> UI2D::InstallEntry(char *, unsigned int, char *, int)
    // Contains loop(s)
    // Accesses globals via r13 (SDA)

    // Per-frame update
    // Iterates over elements
}

// ============================================================================
// FAMTarget::GetFamilyText(char *, unsigned wchar_t *) - 0x801B0B78 | 340 bytes
// ============================================================================
// NON_MATCHING
void* FAMTarget__GetFamilyText(void* self, char* p1, void* p2) {
    // Stack: 2368 bytes
    // -> strncpy
    // -> strcmp
    // -> AtoI(char *)
    // -> FAMTarget::ConvertSelectedFamilyIndexToActualGameIndex(int)
    // -> EGlobal::GetNewUIString(char *)
    // -> wcscpy
    // ... and 2 more calls
    // Accesses globals via r13 (SDA)

    // Getter
    return 0;
}

// ============================================================================
// FAMTarget::OnDialogSelection(int) - 0x801B0E70 | 520 bytes
// ============================================================================
// NON_MATCHING
void FAMTarget__OnDialogSelection(void* self, int p1) {
    // Stack: 24 bytes
    // -> FAMTarget::EvictFamily(void)
    // -> FAMTarget::GetFamilyInFamilyList(int)
    // -> FAMTarget::GoUpMenuTree(void)
    // -> FAMTarget::ConvertSelectedLotIndexToActualGameIndex(int)
    // -> __builtin_new
    // -> UIAUDIO::UIAUDIO(void)
    // ... and 5 more calls
    // Contains loop(s)
    // Accesses globals via r13 (SDA)

}

// ============================================================================
// FAMTarget::OnCancelKeyPressed(char *, char *) - 0x801B1158 | 644 bytes
// ============================================================================
// NON_MATCHING
void FAMTarget__OnCancelKeyPressed(void* self, char* p1, char* p2) {
    // Stack: 88 bytes
    // -> EGlobal::GetNewUIString(char *)
    // -> BString2::operator=(unsigned wchar_t *)
    // -> memcpy
    // -> UIDialog::SpawnDialog(void)
    // -> FAMTarget::GoUpMenuTree(void)

}

// ============================================================================
// FAMTarget::OnUpKeyPressed(char *, char *) - 0x801B13DC | 292 bytes
// ============================================================================
// NON_MATCHING
void FAMTarget__OnUpKeyPressed(void* self, char* p1, char* p2) {
    // Stack: 16 bytes
    // -> FAMTarget::GetNumberOfChoicesInState(FAMTarget::FAM_STATE)
    // -> FAMTarget::UpdateShaders(void)
    // -> FAMTarget::UpdateText(void)

}

// ============================================================================
// FAMTarget::OnDownKeyPressed(char *, char *) - 0x801B1500 | 320 bytes
// ============================================================================
// NON_MATCHING
void FAMTarget__OnDownKeyPressed(void* self, char* p1, char* p2) {
    // Stack: 16 bytes
    // -> FAMTarget::GetNumberOfChoicesInState(FAMTarget::FAM_STATE)
    // -> FAMTarget::UpdateShaders(void)
    // -> FAMTarget::UpdateText(void)

}

// ============================================================================
// FAMTarget::UpdateMenuState(FAMTarget::FAM_STATE) - 0x801B2608 | 908 bytes
// ============================================================================
// NON_MATCHING
void FAMTarget__UpdateMenuState(void* self, void* p1) {
    // Stack: 56 bytes
    // -> FAMTarget::GetFamilyInFamilyList(int)
    // -> sub_803B52BC
    // -> FAMTarget::UpdateMenuState(FAMTarget::FAM_STATE)
    // -> FAMTarget::ConvertSelectedLotIndexToActualGameIndex(int)
    // -> sub_803B54EC
    // -> FAMTarget::UpdateShaders(void)
    // ... and 1 more calls
    // Contains loop(s)
    // Accesses globals via r13 (SDA)

}

// ============================================================================
// FAMTarget::GoUpMenuTree(void) - 0x801B29F8 | 264 bytes
// ============================================================================
// NON_MATCHING
void FAMTarget__GoUpMenuTree(void* self) {
    // Stack: 32 bytes
    // -> sub_803B52BC
    // -> FAMTarget::UpdateMenuState(FAMTarget::FAM_STATE)

}

// ============================================================================
// FAMTarget::GetNameForFamilyInLotSelect(char *, unsigned wchar_t *) - 0x801B2B00 | 276 bytes
// ============================================================================
// NON_MATCHING
void* FAMTarget__GetNameForFamilyInLotSelect(void* self, char* p1, void* p2) {
    // Stack: 32 bytes
    // -> FAMTarget::ConvertSelectedLotIndexToActualGameIndex(int)
    // -> EGlobal::GetNewUIString(char *)
    // -> wcscpy
    // -> ObjSelector::GetUserLastName(void)
    // -> BString2::BString2(BString2 &, unsigned int, unsigned int)
    // -> BString2::c_str(void) const
    // ... and 1 more calls
    // Accesses globals via r13 (SDA)

    // Getter
    return 0;
}

// ============================================================================
// FAMTarget::UpdateFamilySelectShaders(void) - 0x801B2CD4 | 492 bytes
// ============================================================================
// NON_MATCHING
void FAMTarget__UpdateFamilySelectShaders(void* self) {
    // Stack: 56 bytes
    // -> FAMTarget::ConvertSelectedFamilyIndexToActualGameIndex(int)
    // -> ObjSelector::GetThumbnail(ERShader **)
    // -> UI2D::InstallEntry(char *, ERShader *, char *, int)
    // -> EResource::DelRef(void)
    // -> UI2D::InstallEntry(char *, unsigned int, char *, int)
    // Contains loop(s)
    // Accesses globals via r13 (SDA)

    // Per-frame update
    // Iterates over elements
}

// ============================================================================
// FCMTarget::~FCMTarget(void) - 0x801B3B68 | 352 bytes
// ============================================================================
// NON_MATCHING
void FCMTarget__dtor_FCMTarget(void* self) {
    // Stack: 16 bytes
    // -> UIScreenManager::UnloadUIScreen(UIScreenID)
    // -> GetVariableCommandTable::UnInstallAllCommands(CBFunctor1wRet<char *, char *> &)
    // -> SetVariableCommandTable::UnInstallAllCommands(CBFunctor2<char *, char *> &)
    // -> GetLocalizableCommandTable::UnInstallAllCommands(CBFunctor1wRet<char *, unsigned wchar_t *> &)
    // -> UIUpdateTable::UnInstallEntry(CBFunctor0 &)
    // -> UIDrawTable::UnInstallEntry(CBFunctor1<ERC *> &)
    // ... and 6 more calls

    // Release resources
    // __builtin_delete called for cleanup
    // Destroy members
}

// ============================================================================
// FCMTarget::SetVariable(char *, char *) - 0x801B3CC8 | 264 bytes
// ============================================================================
// NON_MATCHING
void FCMTarget__SetVariable(void* self, char* p1, char* p2) {
    // Stack: 24 bytes
    // -> isdigit
    // -> strcmp
    // -> UIReflow::ResetVisibility(char *, bool, int)

    // Setter
}

// ============================================================================
// FCMTarget::Update(void) - 0x801B3EF0 | 264 bytes
// ============================================================================
// NON_MATCHING
void FCMTarget__Update(void* self) {
    // Stack: 16 bytes
    // -> UIReflow::OpenTweenBlock(char *, unsigned int, unsigned int, char *, int)
    // -> UIReflow::Tween_X(int)
    // -> UIReflow::Tween_Alpha(unsigned int)
    // -> UIReflow::SubmitTweenBlock(void)

    // Per-frame update
}

// ============================================================================
// FCMTarget::ShowFireCodeMeter(void) - 0x801B3FF8 | 448 bytes
// ============================================================================
// NON_MATCHING
void FCMTarget__ShowFireCodeMeter(void* self) {
    // Stack: 40 bytes
    // -> FCMTarget::GetFireCodeMeterLevel(void)
    // -> UIReflow::OpenReflowBlock(void)
    // -> UIReflow::Reflow_Id(char *, int)
    // -> UIReflow::Reflow_Visibility(bool)
    // -> UIReflow::Reflow_X(int)
    // -> UIReflow::Reflow_H(unsigned int)
    // ... and 3 more calls
    // Uses floating point

}

// ============================================================================
// FCMTarget::UpdateFireCodeMeter(void) - 0x801B41C4 | 600 bytes
// ============================================================================
// NON_MATCHING
void FCMTarget__UpdateFireCodeMeter(void* self) {
    // Stack: 40 bytes
    // -> FCMTarget::GetFireCodeMeterLevel(void)
    // -> FCMTarget::SetMeterHeight(int)
    // -> UIReflow::OpenTweenBlock(char *, unsigned int, unsigned int, char *, int)
    // -> UIReflow::Tween_H(unsigned int)
    // -> UIReflow::Tween_Y(int)
    // -> UIReflow::SubmitTweenBlock(void)
    // ... and 1 more calls
    // Uses floating point

    // Per-frame update
}

// ============================================================================
// G2DTarget::~G2DTarget(void) - 0x801B4BE8 | 436 bytes
// ============================================================================
// NON_MATCHING
void G2DTarget__dtor_G2DTarget(void* self) {
    // Stack: 16 bytes
    // -> G2DTarget::PopAptButtonFilters(void)
    // -> UIScreenManager::UnloadUIScreen(UIScreenID)
    // -> GetVariableCommandTable::UnInstallAllCommands(CBFunctor1wRet<char *, char *> &)
    // -> SetVariableCommandTable::UnInstallAllCommands(CBFunctor2<char *, char *> &)
    // -> GetLocalizableCommandTable::UnInstallAllCommands(CBFunctor1wRet<char *, unsigned wchar_t *> &)
    // -> UIUpdateTable::UnInstallEntry(CBFunctor0 &)
    // ... and 8 more calls
    // Accesses globals via r13 (SDA)

    // Release resources
    // __builtin_delete called for cleanup
    // Destroy members
}

// ============================================================================
// G2DTarget::GetVariable(char *) - 0x801B4D9C | 528 bytes
// ============================================================================
// NON_MATCHING
void* G2DTarget__GetVariable(void* self, char* p1) {
    // Stack: 32 bytes
    // -> isdigit
    // -> SimsAptMalloc(unsigned int)
    // -> strcmp
    // -> G2DTarget::PushAptButtonFilters(void)
    // -> UIDB::UIDBGetInt(char *)
    // -> UIDB::UIDBSetInt(char *, int)
    // ... and 12 more calls

    // Getter
    return 0;
}

// ============================================================================
// G2DTarget::GetLocalizable(char *) - 0x801B4FAC | 368 bytes
// ============================================================================
// NON_MATCHING
void* G2DTarget__GetLocalizable(void* self, char* p1) {
    // Stack: 24 bytes
    // -> isdigit
    // -> SimsAptMalloc(unsigned int)
    // -> strncmp
    // -> AtoI(char *)
    // -> sub_803B73A0
    // -> strcmp
    // ... and 5 more calls

    // Getter
    return 0;
}

// ============================================================================
// G2DTarget::SetVariable(char *, char *) - 0x801B511C | 756 bytes
// ============================================================================
// NON_MATCHING
void G2DTarget__SetVariable(void* self, char* p1, char* p2) {
    // Stack: 24 bytes
    // -> isdigit
    // -> strcmp
    // -> G2DTarget::CheckPlayerInput(char *)
    // -> __builtin_new
    // -> UIAUDIO::UIAUDIO(void)
    // -> UIAUDIO::PlaySound(unsigned int)
    // ... and 4 more calls
    // Uses floating point
    // Accesses globals via r13 (SDA)

    // Setter
}

// ============================================================================
// G2DTarget::ReflowButtonSelection(void) - 0x801B5410 | 788 bytes
// ============================================================================
// NON_MATCHING
void G2DTarget__ReflowButtonSelection(void* self) {
    // Stack: 32 bytes
    // -> UIReflow::OpenReflowBlock(void)
    // -> UIReflow::Reflow_Id(char *, int)
    // -> UIReflow::Reflow_Visibility(bool)
    // -> UIReflow::Reflow_ColorOverride(unsigned int)
    // -> UIReflow::SubmitReflowBlock(void)
    // Contains loop(s)

}

// ============================================================================
// G2DTarget::Update(void) - 0x801B5724 | 572 bytes
// ============================================================================
// NON_MATCHING
void G2DTarget__Update(void* self) {
    // Stack: 40 bytes
    // -> UIScreenManager::IsUIScreenUnloaded(UIScreenID)
    // -> G2DTarget::UnloadDialog(void)
    // -> G2DTarget::ExecuteSelectionCallback(int)
    // -> UIDB::UIDBSetInt(char *, int)
    // -> G2DTarget::SpawnDialog(UIDialog *)
    // -> UIReflow::UIReflow(void)
    // ... and 10 more calls
    // Uses floating point

    // Per-frame update
}

// ============================================================================
// G2DTarget::SpawnDialog(UIDialog *) - 0x801B5B14 | 804 bytes
// ============================================================================
// NON_MATCHING
void G2DTarget__SpawnDialog(void* self, void* p1) {
    // Stack: 40 bytes
    // -> BString2::compare(BString2 &, unsigned int, unsigned int) const
    // -> H2DTarget::IncPause(bool)
    // -> InteractorModule::InteractorManager::GetSingleton(void)
    // -> InteractorModule::InteractorManager::IsInitialized(void)
    // -> InteractorModule::InteractorManager::GetPlayerInteractor(int, InteractorModule::InteractorType)
    // -> G2DTarget::SetupDialogData(UIDialog *)
    // ... and 7 more calls
    // Contains loop(s)
    // Uses floating point
    // Accesses globals via r13 (SDA)

}

// ============================================================================
// G2DTarget::CalculateBackgroundSize(void) - 0x801B5E38 | 1020 bytes
// ============================================================================
// NON_MATCHING
void G2DTarget__CalculateBackgroundSize(void* self) {
    // Stack: 136 bytes
    // -> MainHeap(void)
    // -> EAHeap::MallocAligned(unsigned int, unsigned int, unsigned int, int)
    // -> BString2::c_str(void) const
    // -> AptParagraph::Build(EVec2 &, EVec2 &, float, EVec4 &, AptStringAlignment, unsigned wchar_t *)
    // -> AptParagraph::GetParagraphHeight(void)
    // -> BString2::length(void) const
    // ... and 1 more calls
    // Contains loop(s)
    // Uses floating point

}

// ============================================================================
// G2DTarget::UnloadDialog(void) - 0x801B690C | 340 bytes
// ============================================================================
// NON_MATCHING
void G2DTarget__UnloadDialog(void* self) {
    // Stack: 16 bytes
    // -> UIDB::UIDBSetInt(char *, int)
    // -> G2DTarget::PopAptButtonFilters(void)
    // -> BString2::erase(unsigned int, unsigned int)
    // -> UI2D::InstallEntry(char *, unsigned int, char *, int)
    // -> EResource::DelRef(void)
    // -> UIUpdateTable::UnInstallEntry(CBFunctor0 &)
    // ... and 1 more calls

}

// ============================================================================
// G2DTarget::SetupDialogData(UIDialog *) - 0x801B6CC0 | 832 bytes
// ============================================================================
// NON_MATCHING
void G2DTarget__SetupDialogData(void* self, void* p1) {
    // Stack: 24 bytes
    // -> sub_803B73A0
    // -> UIDB::UIDBGetInt(char *)
    // -> UIDB::UIDBSetInt(char *, int)
    // -> BString2::length(void) const
    // -> BString2::operator=(unsigned wchar_t *)
    // -> BString2::operator=(BString2 &)
    // ... and 2 more calls

    // Setter
}

// ============================================================================
// H2DTarget::~H2DTarget(void) - 0x801B7B18 | 920 bytes
// ============================================================================
// NON_MATCHING
void H2DTarget__dtor_H2DTarget(void* self) {
    // Stack: 32 bytes
    // -> H2DTarget::ReleasePause(bool)
    // -> AptViewer::PopAptButtonFilter(int, unsigned int)
    // -> UIScreenManager::UnloadUIScreen(UIScreenID)
    // -> GetVariableCommandTable::UnInstallAllCommands(CBFunctor1wRet<char *, char *> &)
    // -> SetVariableCommandTable::UnInstallAllCommands(CBFunctor2<char *, char *> &)
    // -> GetLocalizableCommandTable::UnInstallAllCommands(CBFunctor1wRet<char *, unsigned wchar_t *> &)
    // ... and 7 more calls
    // Contains loop(s)
    // Accesses globals via r13 (SDA)

    // Release resources
    // H2DTarget::ReleasePause(bool) called for cleanup
    // __builtin_delete called for cleanup
    // Destroy members
}

// ============================================================================
// H2DTarget::ShouldH2DBeVisible(int) const - 0x801B90CC | 280 bytes
// ============================================================================
// NON_MATCHING
void H2DTarget__ShouldH2DBeVisible_const(void* self, int p1) {
    // Stack: 8 bytes
    // -> CameraDirector::IsForceDisableHud(void)
    // Accesses globals via r13 (SDA)

}

// ============================================================================
// INGTarget::~INGTarget(void) - 0x801BA500 | 424 bytes
// ============================================================================
// NON_MATCHING
void INGTarget__dtor_INGTarget(void* self) {
    // Stack: 16 bytes
    // -> GetVariableCommandTable::UnInstallAllCommands(CBFunctor1wRet<char *, char *> &)
    // -> SetVariableCommandTable::UnInstallAllCommands(CBFunctor2<char *, char *> &)
    // -> GetLocalizableCommandTable::UnInstallAllCommands(CBFunctor1wRet<char *, unsigned wchar_t *> &)
    // -> UIUpdateTable::UnInstallEntry(CBFunctor0 &)
    // -> UIDrawTable::UnInstallEntry(CBFunctor1<ERC *> &)
    // -> UIUserDrawCBTable::UnInstallAllName(char *)
    // ... and 8 more calls

    // Release resources
    // __builtin_delete called for cleanup
    // Destroy members
}

// ============================================================================
// INGTarget::Update(void) - 0x801BB6C0 | 284 bytes
// ============================================================================
// NON_MATCHING
void INGTarget__Update(void* self) {
    // Stack: 16 bytes
    // -> INGTarget::end_dialog(bool)
    // -> __builtin_new
    // -> RCPTarget::RCPTarget(cRCPEventHandler *, int)
    // Uses floating point

    // Per-frame update
}

// ============================================================================
// INGTarget::end_dialog(bool) - 0x801BB7DC | 316 bytes
// ============================================================================
// NON_MATCHING
void INGTarget__end_dialog(void* self, int p1) {
    // Stack: 32 bytes
    // -> INGTarget::configure_object(short, Ingredient *, Ingredient *, Ingredient *, Ingredient *)
    // -> BBI::InventoryItems::GetItemByGuid(int, unsigned char) const
    // -> BBI::InventoryItem::GetItemCount(void) const
    // -> BBI::InventoryItems::RemoveItemsByGuid(int, int, unsigned char)
    // -> INGTarget::get_total_cost(unsigned int *) const
    // -> GetSimFunds(unsigned int)
    // ... and 2 more calls
    // Contains loop(s)

}

// ============================================================================
// INGTarget::update_current_items(unsigned int) - 0x801BB918 | 320 bytes
// ============================================================================
// NON_MATCHING
void INGTarget__update_current_items(void* self, int p1) {
    // Stack: 48 bytes
    // -> memset
    // -> INGTarget::get_ingredient_type(INGTarget::IngInfo &) const
    // Contains loop(s)

}

// ============================================================================
// INGTarget::create_edit_buffer(void) - 0x801BBF6C | 424 bytes
// ============================================================================
// NON_MATCHING
void INGTarget__create_edit_buffer(void* self) {
    // Stack: 328 bytes
    // -> memset
    // -> GetIngredientManager(void)
    // -> IngredientManager::GetIngredients(Ingredient **, unsigned int) const
    // -> BBI::InventoryItems::GetContainerSize(void) const
    // -> BBI::InventoryItems::GetItemAtIndex(int) const
    // -> BBI::InventoryItem::GetItemSubcategory(void) const
    // ... and 5 more calls
    // Contains loop(s)
    // Accesses globals via r13 (SDA)

}

// ============================================================================
// ITBTarget::~ITBTarget(void) - 0x801BD088 | 368 bytes
// ============================================================================
// NON_MATCHING
void ITBTarget__dtor_ITBTarget(void* self) {
    // Stack: 16 bytes
    // -> BString2::~BString2(void)
    // -> UIScreenManager::UnloadUIScreen(UIScreenID)
    // -> GetVariableCommandTable::UnInstallAllCommands(CBFunctor1wRet<char *, char *> &)
    // -> SetVariableCommandTable::UnInstallAllCommands(CBFunctor2<char *, char *> &)
    // -> GetLocalizableCommandTable::UnInstallAllCommands(CBFunctor1wRet<char *, unsigned wchar_t *> &)
    // -> UIUpdateTable::UnInstallEntry(CBFunctor0 &)
    // ... and 6 more calls

    // Release resources
    // __builtin_delete called for cleanup
    // Destroy members
}

// ============================================================================
// ITBTarget::SetVariable(char *, char *) - 0x801BD1F8 | 308 bytes
// ============================================================================
// NON_MATCHING
void ITBTarget__SetVariable(void* self, char* p1, char* p2) {
    // Stack: 40 bytes
    // -> isdigit
    // -> strcmp
    // -> UIReflow::UIReflow(void)
    // -> UIReflow::OpenTweenBlock(char *, unsigned int, unsigned int, char *, int)
    // -> UIReflow::Tween_Alpha(unsigned int)
    // -> UIReflow::SubmitTweenBlock(void)
    // ... and 1 more calls

    // Setter
}

// ============================================================================
// ITBTarget::Update(void) - 0x801BD490 | 992 bytes
// ============================================================================
// NON_MATCHING
void ITBTarget__Update(void* self) {
    // Stack: 40 bytes
    // -> UIReflow::UIReflow(void)
    // -> UIReflow::OpenReflowBlock(void)
    // -> UIReflow::Reflow_Id(char *, int)
    // -> UIReflow::Reflow_Visibility(bool)
    // -> UIReflow::Reflow_Alpha(unsigned int)
    // -> UIReflow::Reflow_W(unsigned int)
    // ... and 8 more calls

    // Per-frame update
}

// ============================================================================
// ITBTarget::SpawnIntroThoughtBalloon(UIDialog *) - 0x801BD8FC | 340 bytes
// ============================================================================
// NON_MATCHING
void ITBTarget__SpawnIntroThoughtBalloon(void* self, void* p1) {
    // Stack: 88 bytes
    // -> BString2::assign(BString2 &, unsigned int, unsigned int)
    // -> BString2::BString2(unsigned wchar_t *)
    // -> BString2::operator==(BString2 &) const
    // -> BString2::~BString2(void)
    // -> ITBTarget::HideIntroThoughtBalloon(void)
    // -> UIReflow::UIReflow(void)
    // ... and 4 more calls
    // Uses floating point

}

// ============================================================================
// K2YTarget::~K2YTarget(void) - 0x801BE304 | 348 bytes
// ============================================================================
// NON_MATCHING
void K2YTarget__dtor_K2YTarget(void* self) {
    // Stack: 16 bytes
    // -> GetVariableCommandTable::UnInstallAllCommands(CBFunctor1wRet<char *, char *> &)
    // -> SetVariableCommandTable::UnInstallAllCommands(CBFunctor2<char *, char *> &)
    // -> GetLocalizableCommandTable::UnInstallAllCommands(CBFunctor1wRet<char *, unsigned wchar_t *> &)
    // -> UIUpdateTable::UnInstallEntry(CBFunctor0 &)
    // -> UIDrawTable::UnInstallEntry(CBFunctor1<ERC *> &)
    // -> UIUserDrawCBTable::UnInstallAllName(char *)
    // ... and 4 more calls

    // Release resources
    // __builtin_delete called for cleanup
    // Destroy members
}

// ============================================================================
// K2YTarget::SetVariable(char *, char *) - 0x801BE56C | 688 bytes
// ============================================================================
// NON_MATCHING
void K2YTarget__SetVariable(void* self, char* p1, char* p2) {
    // Stack: 32 bytes
    // -> strcmp
    // -> K2YTarget::IsModeValid(void)
    // -> K2YTarget::GetName(void)
    // -> wcslen
    // -> __builtin_new
    // -> UIAUDIO::UIAUDIO(void)
    // ... and 3 more calls
    // Accesses globals via r13 (SDA)

    // Setter
}

// ============================================================================
// K2YTarget::GetVariable(char *) - 0x801BE81C | 740 bytes
// ============================================================================
// NON_MATCHING
void* K2YTarget__GetVariable(void* self, char* p1) {
    // Stack: 64 bytes
    // -> SimsAptMalloc(unsigned int)
    // -> strcmp
    // -> Snprintf(char *, unsigned int, char *,...)
    // -> K2YTarget::IsModeValid(void)
    // -> K2YTarget::GetName(void)
    // -> wcslen
    // ... and 6 more calls
    // Contains loop(s)
    // Uses floating point
    // Accesses globals via r13 (SDA)

    // Getter
    return 0;
}

// ============================================================================
// K2YTarget::GetLocalizable(char *) - 0x801BEB00 | 596 bytes
// ============================================================================
// NON_MATCHING
void* K2YTarget__GetLocalizable(void* self, char* p1) {
    // Stack: 48 bytes
    // -> isdigit
    // -> SimsAptMalloc(unsigned int)
    // -> strcmp
    // -> EGlobal::GetNewUIString(char *)
    // -> wcscpy
    // -> wcslen
    // ... and 2 more calls
    // Accesses globals via r13 (SDA)

    // Getter
    return 0;
}

// ============================================================================
// K2YTarget::GetKeybits(int, int) - 0x801BED54 | 492 bytes
// ============================================================================
// NON_MATCHING
void* K2YTarget__GetKeybits(void* self, int p1, int p2) {
    // Stack: 152 bytes
    // -> Snprintf(char *, unsigned int, char *,...)
    // -> strcat
    // -> BString2::BString2(void)
    // -> strcpy
    // -> EGlobal::GetNewUIString(char *)
    // -> BString2::operator=(unsigned wchar_t *)
    // ... and 3 more calls
    // Contains loop(s)

    // Getter
    return 0;
}

// ============================================================================
// M2MTarget::~M2MTarget(void) - 0x801BFCDC | 524 bytes
// ============================================================================
// NON_MATCHING
void M2MTarget__dtor_M2MTarget(void* self) {
    // Stack: 40 bytes
    // -> CASTarget::SetHandleInput(bool)
    // -> M2MTarget::UnloadDialog(void)
    // -> GetVariableCommandTable::UnInstallAllCommands(CBFunctor1wRet<char *, char *> &)
    // -> SetVariableCommandTable::UnInstallAllCommands(CBFunctor2<char *, char *> &)
    // -> GetLocalizableCommandTable::UnInstallAllCommands(CBFunctor1wRet<char *, unsigned wchar_t *> &)
    // -> UIUpdateTable::UnInstallEntry(CBFunctor0 &)
    // ... and 9 more calls
    // Contains loop(s)

    // Release resources
    // __builtin_delete called for cleanup
    // Destroy members
}

// ============================================================================
// M2MTarget::GetVariable(char *) - 0x801BFEE8 | 440 bytes
// ============================================================================
// NON_MATCHING
void* M2MTarget__GetVariable(void* self, char* p1) {
    // Stack: 40 bytes
    // -> isdigit
    // -> SimsAptMalloc(unsigned int)
    // -> strcmp
    // -> Sprintf(char *, char *,...)
    // -> strlen
    // Uses floating point

    // Getter
    return 0;
}

// ============================================================================
// M2MTarget::GetLocalizable(char *) - 0x801C00A0 | 588 bytes
// ============================================================================
// NON_MATCHING
void* M2MTarget__GetLocalizable(void* self, char* p1) {
    // Stack: 40 bytes
    // -> isdigit
    // -> SimsAptMalloc(unsigned int)
    // -> wcscpy
    // -> strcmp
    // -> EGlobal::GetMemCardString(char *)
    // -> BString2::operator=(unsigned wchar_t *)
    // ... and 7 more calls

    // Getter
    return 0;
}

// ============================================================================
// M2MTarget::SetVariable(char *, char *) - 0x801C02EC | 376 bytes
// ============================================================================
// NON_MATCHING
void M2MTarget__SetVariable(void* self, char* p1, char* p2) {
    // Stack: 16 bytes
    // -> isdigit
    // -> strcmp
    // -> M2MTarget::IsItemEnabled(int)
    // -> M2MTarget::OnSlotSelectItemSelected(int, M2MTarget::ResultStruct &)
    // -> UIDB::UIDBSetInt(char *, int)
    // -> M2MTarget::HideWidget(void)
    // ... and 2 more calls

    // Setter
}

// ============================================================================
// M2MTarget::ReflowButtonSelection(void) - 0x801C0464 | 320 bytes
// ============================================================================
// NON_MATCHING
void M2MTarget__ReflowButtonSelection(void* self) {
    // Stack: 32 bytes
    // -> M2MTarget::IsItemEnabled(int)
    // -> UIReflow::OpenReflowBlock(void)
    // -> UIReflow::Reflow_Id(char *, int)
    // -> UIReflow::Reflow_Visibility(bool)
    // -> UIReflow::Reflow_ColorOverride(unsigned int)
    // -> UIReflow::SubmitReflowBlock(void)
    // Contains loop(s)

}

// ============================================================================
// M2MTarget::Update(void) - 0x801C05A4 | 1020 bytes
// ============================================================================
// NON_MATCHING
void M2MTarget__Update(void* self) {
    // Stack: 24 bytes
    // -> G2DTarget::IsG2DSpawned(void)
    // -> M2MTarget::UpdateWidgetState(void)
    // -> UIScreenManager::IsUIScreenUnloaded(UIScreenID)
    // -> M2MTarget::UnloadDialog(void)
    // -> M2MTarget::SpawnContinueNoMemCardDialog(void)
    // -> M2MTarget::PrepareNewGame(void)
    // ... and 12 more calls

    // Per-frame update
}

// ============================================================================
// M2MTarget::SelectionCallback(int) - 0x801C09A0 | 764 bytes
// ============================================================================
// NON_MATCHING
void M2MTarget__SelectionCallback(void* self, int p1) {
    // Stack: 24 bytes
    // -> UIDB::UIDBGetInt(char *)
    // -> UIDB::UIDBSetInt(char *, int)
    // -> NghResFile::FlushAllData(void)
    // -> M2MTarget::HideWidget(void)
    // -> M2MTarget::DoesMemoryDeviceExist(void)
    // -> M2MTarget::ReturnFailureDestination(void)
    // ... and 1 more calls
    // Accesses globals via r13 (SDA)

    // Callback handler
}

// ============================================================================
// M2MTarget::OnSaveLoadSucceed(void) - 0x801C0D94 | 308 bytes
// ============================================================================
// NON_MATCHING
void M2MTarget__OnSaveLoadSucceed(void* self) {
    // Stack: 16 bytes
    // -> UIDB::UIDBSetInt(char *, int)
    // -> UIDB::UIDBGetInt(char *)
    // -> NghResFile::FlushAllData(void)
    // -> M2MTarget::HideWidget(void)
    // Accesses globals via r13 (SDA)

    // Load/parse data
}

// ============================================================================
// M2MTarget::OnSaveLoadFailed(void) - 0x801C0EC8 | 460 bytes
// ============================================================================
// NON_MATCHING
void M2MTarget__OnSaveLoadFailed(void* self) {
    // Stack: 16 bytes
    // -> M2MTarget::ReturnFailureDestination(void)
    // -> __builtin_new
    // -> M2MTarget::GetMemCardPort(void)
    // -> SaveGameTarget::SaveGameTarget(M2MTarget *, int, int)
    // -> M2MTarget::SpawnStartNGCNoMemCardDialog(void)
    // -> UIDB::UIDBSetInt(char *, int)

    // Load/parse data
}

// ============================================================================
// M2MTarget::SpawnNoSpaceDialog(void) - 0x801C115C | 332 bytes
// ============================================================================
// NON_MATCHING
void M2MTarget__SpawnNoSpaceDialog(void* self) {
    // Stack: 40 bytes
    // -> UIDialog::HideDialog(void)
    // -> EGlobal::GetMemCardString(char *)
    // -> BString2::operator=(unsigned wchar_t *)
    // -> UIDialog::SpawnDialog(void)

}

// ============================================================================
// M2MTarget::SpawnConfirmStartNewGameDialog(void) - 0x801C12A8 | 324 bytes
// ============================================================================
// NON_MATCHING
void M2MTarget__SpawnConfirmStartNewGameDialog(void* self) {
    // Stack: 40 bytes
    // -> EGlobal::GetMemCardString(char *)
    // -> BString2::operator=(unsigned wchar_t *)
    // -> UIDialog::SpawnDialog(void)

}

// ============================================================================
// M2MTarget::SpawnContinueNoMemCardDialog(void) - 0x801C13EC | 340 bytes
// ============================================================================
// NON_MATCHING
void M2MTarget__SpawnContinueNoMemCardDialog(void* self) {
    // Stack: 40 bytes
    // -> UIDialog::HideDialog(void)
    // -> M2MTarget::HideWidget(void)
    // -> EGlobal::GetMemCardString(char *)
    // -> BString2::operator=(unsigned wchar_t *)
    // -> UIDialog::SpawnDialog(void)

}

// ============================================================================
// M2MTarget::SpawnSaveBeforeQuitCASDialog(void) - 0x801C1540 | 364 bytes
// ============================================================================
// NON_MATCHING
void M2MTarget__SpawnSaveBeforeQuitCASDialog(void* self) {
    // Stack: 40 bytes
    // -> EGlobal::GetMemCardString(char *)
    // -> BString2::operator=(unsigned wchar_t *)
    // -> UIDialog::SpawnDialog(void)

    // Save/write data
}

// ============================================================================
// M2MTarget::SpawnSaveBeforeQuitGameDialog(void) - 0x801C16AC | 364 bytes
// ============================================================================
// NON_MATCHING
void M2MTarget__SpawnSaveBeforeQuitGameDialog(void* self) {
    // Stack: 40 bytes
    // -> EGlobal::GetMemCardString(char *)
    // -> BString2::operator=(unsigned wchar_t *)
    // -> UIDialog::SpawnDialog(void)

    // Save/write data
}

// ============================================================================
// M2MTarget::SpawnNoSaveBeforeQuitDialog(void) - 0x801C1818 | 324 bytes
// ============================================================================
// NON_MATCHING
void M2MTarget__SpawnNoSaveBeforeQuitDialog(void* self) {
    // Stack: 40 bytes
    // -> EGlobal::GetMemCardString(char *)
    // -> BString2::operator=(unsigned wchar_t *)
    // -> UIDialog::SpawnDialog(void)

    // Save/write data
}

// ============================================================================
// M2MTarget::SpawnStartNGCNoMemCardDialog(void) - 0x801C195C | 324 bytes
// ============================================================================
// NON_MATCHING
void M2MTarget__SpawnStartNGCNoMemCardDialog(void* self) {
    // Stack: 40 bytes
    // -> EGlobal::GetMemCardString(char *)
    // -> BString2::operator=(unsigned wchar_t *)
    // -> UIDialog::SpawnDialog(void)

}

// ============================================================================
// M2MTarget::GetItemTextMemCardSelect(int, unsigned wchar_t *) - 0x801C1AA0 | 328 bytes
// ============================================================================
// NON_MATCHING
void* M2MTarget__GetItemTextMemCardSelect(void* self, int p1, void* p2) {
    // Stack: 40 bytes
    // -> EGlobal::GetMemCardString(char *)
    // -> BString2::operator=(unsigned wchar_t *)
    // -> BString2::c_str(void) const
    // -> wcscpy

    // Getter
    return 0;
}

// ============================================================================
// M2MTarget::UpdateWidgetState(void) - 0x801C1F64 | 416 bytes
// ============================================================================
// NON_MATCHING
void M2MTarget__UpdateWidgetState(void* self) {
    // Stack: 32 bytes
    // -> M2MTarget::FillWidget(void)
    // -> UIDialog::HideDialog(void)
    // -> UIReflow::OpenReflowBlock(void)
    // -> UIReflow::Reflow_Id(char *, int)
    // -> UIReflow::Reflow_Visibility(bool)
    // -> UIReflow::SubmitReflowBlock(void)
    // ... and 2 more calls
    // Contains loop(s)

    // Per-frame update
    // Iterates over elements
}

// ============================================================================
// M2MTarget::SetCurrState(M2MTarget::WidgetState) - 0x801C2A74 | 780 bytes
// ============================================================================
// NON_MATCHING
void M2MTarget__SetCurrState(void* self, void* p1) {
    // Stack: 16 bytes
    // -> __builtin_new
    // -> M2MTarget::GetMemCardPort(void)
    // -> LoadGameTarget::LoadGameTarget(M2MTarget *, int, int)
    // -> SaveGameTarget::SaveGameTarget(M2MTarget *, int, int)
    // -> M2MTarget::ReturnFailureDestination(void)
    // -> UIDialog::HideDialog(void)
    // ... and 4 more calls

}

// ============================================================================
// MDITarget::~MDITarget(void) - 0x801C35DC | 344 bytes
// ============================================================================
// NON_MATCHING
void MDITarget__dtor_MDITarget(void* self) {
    // Stack: 16 bytes
    // -> MDITarget::DeleteAllModelessDialogs(void)
    // -> UIScreenManager::UnloadUIScreen(UIScreenID)
    // -> GetVariableCommandTable::UnInstallAllCommands(CBFunctor1wRet<char *, char *> &)
    // -> SetVariableCommandTable::UnInstallAllCommands(CBFunctor2<char *, char *> &)
    // -> GetLocalizableCommandTable::UnInstallAllCommands(CBFunctor1wRet<char *, unsigned wchar_t *> &)
    // -> UIUpdateTable::UnInstallEntry(CBFunctor0 &)
    // ... and 6 more calls

    // Release resources
    // MDITarget::DeleteAllModelessDialogs(void) called for cleanup
    // __builtin_delete called for cleanup
    // Destroy members
}

// ============================================================================
// MDITarget::GetVariable(char *) - 0x801C37E4 | 308 bytes
// ============================================================================
// NON_MATCHING
void* MDITarget__GetVariable(void* self, char* p1) {
    // Stack: 24 bytes
    // -> isdigit
    // -> SimsAptMalloc(unsigned int)
    // -> strcmp
    // -> Sprintf(char *, char *,...)

    // Getter
    return 0;
}

// ============================================================================
// MDITarget::GetLocalizable(char *) - 0x801C3918 | 268 bytes
// ============================================================================
// NON_MATCHING
void* MDITarget__GetLocalizable(void* self, char* p1) {
    // Stack: 24 bytes
    // -> isdigit
    // -> SimsAptMalloc(unsigned int)
    // -> strcmp
    // -> BString2::c_str(void) const
    // -> wcscpy
    // -> wcslen
    // ... and 2 more calls

    // Getter
    return 0;
}

// ============================================================================
// MDITarget::Update(void) - 0x801C3A24 | 608 bytes
// ============================================================================
// NON_MATCHING
void MDITarget__Update(void* self) {
    // Stack: 64 bytes
    // -> UIReflow::UIReflow(void)
    // -> UIReflow::ResetVisibility(char *, bool, int)
    // -> UIReflow::OpenTweenBlock(char *, unsigned int, unsigned int, char *, int)
    // -> UIReflow::Tween_Alpha(unsigned int)
    // -> UIReflow::SubmitTweenBlock(void)
    // -> UIReflow::~UIReflow(void)
    // ... and 8 more calls
    // Uses floating point

    // Per-frame update
}

// ============================================================================
// MMUTarget::~MMUTarget(void) - 0x801C5830 | 432 bytes
// ============================================================================
// NON_MATCHING
void MMUTarget__dtor_MMUTarget(void* self) {
    // Stack: 24 bytes
    // -> CRDTarget::HideCredits(void)
    // -> UIScreenManager::UnloadUIScreen(UIScreenID)
    // -> GetVariableCommandTable::UnInstallAllCommands(CBFunctor1wRet<char *, char *> &)
    // -> SetVariableCommandTable::UnInstallAllCommands(CBFunctor2<char *, char *> &)
    // -> GetLocalizableCommandTable::UnInstallAllCommands(CBFunctor1wRet<char *, unsigned wchar_t *> &)
    // -> UIUpdateTable::UnInstallEntry(CBFunctor0 &)
    // ... and 8 more calls
    // Accesses globals via r13 (SDA)

    // Release resources
    // __builtin_delete called for cleanup
    // Destroy members
}

// ============================================================================
// MMUTarget::SetVariable(char *, char *) - 0x801C59F4 | 988 bytes
// ============================================================================
// NON_MATCHING
void MMUTarget__SetVariable(void* self, char* p1, char* p2) {
    // Stack: 24 bytes
    // -> isdigit
    // -> strcmp
    // -> MMUTarget::UpdateDevMenuState(char *, char *)
    // -> MMUTarget::OnNGHSelect(char *, char *)
    // -> AtoI(char *)
    // -> MMUTarget::LaunchLot(int)
    // ... and 16 more calls
    // Accesses globals via r13 (SDA)

    // Setter
}

// ============================================================================
// MMUTarget::GetVariable(char *) - 0x801C5DD0 | 432 bytes
// ============================================================================
// NON_MATCHING
void* MMUTarget__GetVariable(void* self, char* p1) {
    // Stack: 24 bytes
    // -> isdigit
    // -> SimsAptMalloc(unsigned int)
    // -> strcmp
    // -> MMUTarget::GetNumberOfControllers(void)
    // -> MMUTarget::GetNumberOfChoicesInState(MMUTarget::MMU_MENU_STATE)
    // -> Sprintf(char *, char *,...)
    // Accesses globals via r13 (SDA)

    // Getter
    return 0;
}

// ============================================================================
// MMUTarget::Update(void) - 0x801C63C4 | 268 bytes
// ============================================================================
// NON_MATCHING
void MMUTarget__Update(void* self) {
    // Stack: 24 bytes
    // -> MMUTarget::GoUpMenuTree(char *, char *)
    // -> EControllerManager::GetPlayerController(unsigned int)
    // -> EControllerManager::GetPlayerMapped(unsigned int)
    // -> EController::GetBtnPressedMask(unsigned int)
    // -> EController::GetBtnDownMask(unsigned int)
    // -> EController::GetCmdResult(unsigned int, unsigned int, unsigned int, bool)
    // ... and 2 more calls
    // Accesses globals via r13 (SDA)

    // Per-frame update
}

// ============================================================================
// MMUTarget::Draw(ERC *) - 0x801C64D0 | 372 bytes
// ============================================================================
// NON_MATCHING
void MMUTarget__Draw(void* self, void* p1) {
    // Stack: 296 bytes
    // -> strcat
    // -> ERFont::Select(ERC *)
    // -> ERFont::SetSize(float, float, bool)
    // -> ERFont::Draw(ERC *, char *, EVec2 &, EFontAlignX, EFontAlignY, EVec2 *, EMat4 *, EFontMatrixType, fontFXcommand *, bool)
    // Uses floating point

    // Render pass
    // Computes positions/transforms
}

// ============================================================================
// MMUTarget::UpdateNGHListItems(void) - 0x801C679C | 332 bytes
// ============================================================================
// NON_MATCHING
void MMUTarget__UpdateNGHListItems(void* self) {
    // Stack: 336 bytes
    // -> UIReflow::UIReflow(void)
    // -> UIReflow::OpenReflowBlock(void)
    // -> memset
    // -> Sprintf(char *, char *,...)
    // -> strcat
    // -> UIReflow::Reflow_Id(char *, int)
    // ... and 4 more calls
    // Contains loop(s)

    // Per-frame update
    // Iterates over elements
}

// ============================================================================
// MMUTarget::UpdateLotListItems(void) - 0x801C68E8 | 292 bytes
// ============================================================================
// NON_MATCHING
void MMUTarget__UpdateLotListItems(void* self) {
    // Stack: 336 bytes
    // -> UIReflow::UIReflow(void)
    // -> UIReflow::OpenReflowBlock(void)
    // -> memset
    // -> Sprintf(char *, char *,...)
    // -> strcat
    // -> UIReflow::Reflow_Id(char *, int)
    // ... and 4 more calls
    // Contains loop(s)

    // Per-frame update
    // Iterates over elements
}

// ============================================================================
// MMUTarget::GetNGHListItemName(char *) - 0x801C6A0C | 328 bytes
// ============================================================================
// NON_MATCHING
void* MMUTarget__GetNGHListItemName(void* self, char* p1) {
    // Stack: 280 bytes
    // -> strcmp
    // -> strcpy
    // -> SimsAptMalloc(unsigned int)
    // -> strlen
    // -> UTF8ToUCS2(char *, int, unsigned wchar_t *)
    // -> wcslen
    // ... and 2 more calls

    // Getter
    return 0;
}

// ============================================================================
// MMUTarget::EnterLot(int) - 0x801C6BFC | 404 bytes
// ============================================================================
// NON_MATCHING
void MMUTarget__EnterLot(void* self, int p1) {
    // Stack: 40 bytes
    // -> GameData::SetTwoPlayerMode(bool)
    // -> UIDB::UIDBSetInt(char *, int)
    // -> EGlobal::GetNewUIString(char *)
    // -> UIDB::UIDBSetString(char *, unsigned wchar_t *)
    // -> ESimsApp::SetStartLot(int)
    // -> UIObjectBase::UIRouter_FlowGoto(char *)

}

// ============================================================================
// SetupCAS(void) - 0x801C6FC4 | 300 bytes
// ============================================================================
// NON_MATCHING
void SetupCAS(void) {
    // Stack: 32 bytes
    // -> UIDB::UIDBSetInt(char *, int)
    // -> EGlobal::GetNewUIString(char *)
    // -> UIDB::UIDBSetString(char *, unsigned wchar_t *)

    // Setter
}

// ============================================================================
// MMUTarget::UpdateText(void) - 0x801C7998 | 1000 bytes
// ============================================================================
// NON_MATCHING
void MMUTarget__UpdateText(void* self) {
    // Stack: 64 bytes
    // -> UIReflow::UIReflow(void)
    // -> UIReflow::OpenReflowBlock(void)
    // -> UIReflow::Reflow_Id(char *, int)
    // -> UIReflow::Reflow_Visibility(bool)
    // -> UIReflow::SubmitReflowBlock(void)
    // -> UIReflow::~UIReflow(void)
    // ... and 1 more calls

    // Per-frame update
}

// ============================================================================
// MMUTarget::UpdateMenuState(char *, char *) - 0x801C7D80 | 420 bytes
// ============================================================================
// NON_MATCHING
void MMUTarget__UpdateMenuState(void* self, char* p1, char* p2) {
    // Stack: 40 bytes
    // -> AtoI(char *)
    // -> MMUTarget::UpdateText(void)
    // -> __builtin_new
    // -> CRDTarget::CRDTarget(void)
    // -> CRDTarget::ShowCredits(void)
    // -> MMUTarget::GetNumberOfControllers(void)
    // ... and 3 more calls

    // Per-frame update
}

// ============================================================================
// MMUTarget::GoUpMenuTree(char *, char *) - 0x801C7F24 | 416 bytes
// ============================================================================
// NON_MATCHING
void MMUTarget__GoUpMenuTree(void* self, char* p1, char* p2) {
    // Stack: 296 bytes
    // -> sub_803B5A08
    // -> EControllerManager::UnmapPlayer(unsigned int)
    // -> AptViewer::AllowControllerReading(bool)
    // -> cSoundPlayer::ResumeSounds(void)
    // -> Sprintf(char *, char *,...)
    // Accesses globals via r13 (SDA)

}

// ============================================================================
// MMUTarget::GetNumberOfControllers(void) - 0x801C80C4 | 284 bytes
// ============================================================================
// NON_MATCHING
int MMUTarget__GetNumberOfControllers(void* self) {
    // Stack: 16 bytes
    // -> EControllerManager::GetController(unsigned int)
    // Accesses globals via r13 (SDA)

    // Getter
    return 0;
}

// ============================================================================
// MMUTarget::IncrementChoice(char *, char *) - 0x801C8228 | 316 bytes
// ============================================================================
// NON_MATCHING
void MMUTarget__IncrementChoice(void* self, char* p1, char* p2) {
    // Stack: 272 bytes
    // -> Sprintf(char *, char *,...)

}

// ============================================================================
// MMUTarget::DecrementChoice(char *, char *) - 0x801C8420 | 304 bytes
// ============================================================================
// NON_MATCHING
void MMUTarget__DecrementChoice(void* self, char* p1, char* p2) {
    // Stack: 272 bytes
    // -> Sprintf(char *, char *,...)

}

// ============================================================================
// MODTarget::~MODTarget(void) - 0x801C9178 | 376 bytes
// ============================================================================
// NON_MATCHING
void MODTarget__dtor_MODTarget(void* self) {
    // Stack: 16 bytes
    // -> UIScreenManager::UnloadUIScreen(UIScreenID)
    // -> GetVariableCommandTable::UnInstallAllCommands(CBFunctor1wRet<char *, char *> &)
    // -> SetVariableCommandTable::UnInstallAllCommands(CBFunctor2<char *, char *> &)
    // -> GetLocalizableCommandTable::UnInstallAllCommands(CBFunctor1wRet<char *, unsigned wchar_t *> &)
    // -> UIUpdateTable::UnInstallEntry(CBFunctor0 &)
    // -> UIDrawTable::UnInstallEntry(CBFunctor1<ERC *> &)
    // ... and 6 more calls

    // Release resources
    // __builtin_delete called for cleanup
    // Destroy members
}

// ============================================================================
// MODTarget::SetVariable(char *, char *) - 0x801C92F0 | 260 bytes
// ============================================================================
// NON_MATCHING
void MODTarget__SetVariable(void* self, char* p1, char* p2) {
    // Stack: 48 bytes
    // -> isdigit
    // -> strcmp
    // -> UIReflow::UIReflow(void)
    // -> UIReflow::ResetVisibility(char *, bool, int)
    // -> UIReflow::~UIReflow(void)
    // Accesses globals via r13 (SDA)

    // Setter
}

// ============================================================================
// MODTarget::GetLocalizable(char *) - 0x801C94C0 | 276 bytes
// ============================================================================
// NON_MATCHING
void* MODTarget__GetLocalizable(void* self, char* p1) {
    // Stack: 24 bytes
    // -> isdigit
    // -> SimsAptMalloc(unsigned int)
    // -> strcmp
    // -> UIObjectBase::makeMoneyString(int, unsigned wchar_t *, bool)
    // -> wcslen
    // -> UIQDTarget::UIQDSubstitutionStrings(unsigned wchar_t *)
    // ... and 2 more calls
    // Accesses globals via r13 (SDA)

    // Getter
    return 0;
}

// ============================================================================
// MODTarget::UpdateMood(void) - 0x801C9AFC | 392 bytes
// ============================================================================
// NON_MATCHING
void MODTarget__UpdateMood(void* self) {
    // Stack: 544 bytes
    // -> MODTarget::SetWarning(MODTarget::eSidePanelId, bool, bool)
    // -> StringBuffer2::StringBuffer2(unsigned wchar_t *, unsigned int)
    // -> GetMoneyString(int, StackString2<256> &, bool)
    // -> StringBuffer2::c_str(void) const
    // -> UIDB::UIDBSetString(char *, unsigned wchar_t *)
    // -> UIReflow::ResetFontSizeOverride(char *, unsigned int, int)
    // Accesses globals via r13 (SDA)

    // Per-frame update
}

// ============================================================================
// MODTarget::SelectDpadArrow(MODTarget::eSidePanelId) - 0x801C9C8C | 448 bytes
// ============================================================================
// NON_MATCHING
void MODTarget__SelectDpadArrow(void* self, void* p1) {
    // Stack: 24 bytes
    // -> UIReflow::OpenReflowBlock(void)
    // -> UIReflow::Reflow_Id(char *, int)
    // -> UIReflow::Reflow_Visibility(bool)
    // -> UIReflow::Reflow_SwfAnimation(char *)
    // -> UIReflow::SubmitReflowBlock(void)

}

// ============================================================================
// MODTarget::SelectDpadButton(MODTarget::eSidePanelId) - 0x801C9E4C | 924 bytes
// ============================================================================
// NON_MATCHING
void MODTarget__SelectDpadButton(void* self, void* p1) {
    // Stack: 32 bytes
    // -> UIReflow::OpenReflowBlock(void)
    // -> UIReflow::Reflow_Id(char *, int)
    // -> UIReflow::Reflow_Visibility(bool)
    // -> UIReflow::Reflow_SwfAnimation(char *)
    // -> UIReflow::SubmitReflowBlock(void)

}

// ============================================================================
// MODTarget::SetWarning(MODTarget::eSidePanelId, bool, bool) - 0x801CA1E8 | 612 bytes
// ============================================================================
// NON_MATCHING
void MODTarget__SetWarning(void* self, void* p1, int p2, int p3) {
    // Stack: 24 bytes
    // -> UIReflow::OpenReflowBlock(void)
    // -> UIReflow::Reflow_Id(char *, int)
    // -> MODTarget::TriggerAspirationChestDisplay(void)
    // -> UIReflow::Reflow_SwfAnimation(char *)
    // -> UIReflow::SubmitReflowBlock(void)

}

// ============================================================================
// MODTarget::SetMeterValue(float, bool) - 0x801CA44C | 508 bytes
// ============================================================================
// NON_MATCHING
void MODTarget__SetMeterValue(void* self, float p1, int p2) {
    // Stack: 48 bytes
    // -> floorf
    // -> __builtin_new
    // -> UIAUDIO::UIAUDIO(void)
    // -> UIAUDIO::PlaySound(unsigned int)
    // -> UIReflow::OpenReflowBlock(void)
    // -> UIReflow::Reflow_Id(char *, int)
    // ... and 3 more calls
    // Uses floating point
    // Accesses globals via r13 (SDA)

    // Setter
}

// ============================================================================
// MODTarget::SetDpadIcons(MODTarget::eSidePanelIcon) - 0x801CA648 | 768 bytes
// ============================================================================
// NON_MATCHING
void MODTarget__SetDpadIcons(void* self, void* p1) {
    // Stack: 24 bytes
    // -> MODTarget::SelectDpadArrow(MODTarget::eSidePanelId)
    // -> MODTarget::SelectDpadButton(MODTarget::eSidePanelId)
    // -> UIReflow::OpenReflowBlock(void)
    // -> UIReflow::Reflow_Id(char *, int)
    // -> UIReflow::Reflow_Visibility(bool)
    // -> UIReflow::SubmitReflowBlock(void)
    // ... and 1 more calls

}

// ============================================================================
// MOTTarget::~MOTTarget(void) - 0x801CB5A4 | 364 bytes
// ============================================================================
// NON_MATCHING
void MOTTarget__dtor_MOTTarget(void* self) {
    // Stack: 16 bytes
    // -> UIScreenManager::UnloadUIScreen(UIScreenID)
    // -> GetVariableCommandTable::UnInstallAllCommands(CBFunctor1wRet<char *, char *> &)
    // -> SetVariableCommandTable::UnInstallAllCommands(CBFunctor2<char *, char *> &)
    // -> GetLocalizableCommandTable::UnInstallAllCommands(CBFunctor1wRet<char *, unsigned wchar_t *> &)
    // -> UIUpdateTable::UnInstallEntry(CBFunctor0 &)
    // -> UIDrawTable::UnInstallEntry(CBFunctor1<ERC *> &)
    // ... and 5 more calls

    // Release resources
    // __builtin_delete called for cleanup
    // Destroy members
}

// ============================================================================
// MOTTarget::SetVariable(char *, char *) - 0x801CB710 | 280 bytes
// ============================================================================
// NON_MATCHING
void MOTTarget__SetVariable(void* self, char* p1, char* p2) {
    // Stack: 48 bytes
    // -> isdigit
    // -> strcmp
    // -> UIReflow::UIReflow(void)
    // -> UIReflow::ResetVisibility(char *, bool, int)
    // -> UIReflow::~UIReflow(void)
    // Accesses globals via r13 (SDA)

    // Setter
}

// ============================================================================
// MOTTarget::Update(void) - 0x801CB944 | 532 bytes
// ============================================================================
// NON_MATCHING
void MOTTarget__Update(void* self) {
    // Stack: 40 bytes
    // -> UIReflow::UIReflow(void)
    // -> UIReflow::OpenReflowBlock(void)
    // -> UIReflow::Reflow_Id(char *, int)
    // -> UIReflow::Reflow_Visibility(bool)
    // -> UIReflow::Reflow_X(int)
    // -> UIReflow::SubmitReflowBlock(void)
    // ... and 5 more calls
    // Accesses globals via r13 (SDA)

    // Per-frame update
}

// ============================================================================
// MOTTarget::ReadMotiveBar(int) - 0x801CBFC8 | 464 bytes
// ============================================================================
// NON_MATCHING
void MOTTarget__ReadMotiveBar(void* self, int p1) {
    // Stack: 32 bytes
    // -> floorf
    // Uses floating point

    // Load/parse data
}

// ============================================================================
// MOTTarget::ResetRealMotiveValues(void) - 0x801CC198 | 264 bytes
// ============================================================================
// NON_MATCHING
void MOTTarget__ResetRealMotiveValues(void* self) {
    // Stack: 56 bytes
    // Contains loop(s)
    // Uses floating point

    // Reset state to defaults
}

// ============================================================================
// O2TTarget::~O2TTarget(void) - 0x801CD3DC | 444 bytes
// ============================================================================
// NON_MATCHING
void O2TTarget__dtor_O2TTarget(void* self) {
    // Stack: 16 bytes
    // -> UIObjectBase::popAptButtonFilter(int, unsigned int)
    // -> UIScreenManager::UnloadUIScreen(UIScreenID)
    // -> GetVariableCommandTable::UnInstallAllCommands(CBFunctor1wRet<char *, char *> &)
    // -> SetVariableCommandTable::UnInstallAllCommands(CBFunctor2<char *, char *> &)
    // -> GetLocalizableCommandTable::UnInstallAllCommands(CBFunctor1wRet<char *, unsigned wchar_t *> &)
    // -> UIUpdateTable::UnInstallEntry(CBFunctor0 &)
    // ... and 8 more calls
    // Accesses globals via r13 (SDA)

    // Release resources
    // __builtin_delete called for cleanup
    // Destroy members
}

// ============================================================================
// O2TTarget::SpawnSaveSettingsDialog(void) - 0x801CEC90 | 600 bytes
// ============================================================================
// NON_MATCHING
void O2TTarget__SpawnSaveSettingsDialog(void* self) {
    // Stack: 80 bytes
    // -> EGlobal::GetNewUIString(char *)
    // -> BString2::operator=(unsigned wchar_t *)
    // -> memcpy
    // -> UIDialog::SpawnDialog(void)

    // Setter
}

// ============================================================================
// O2TTarget::UpdateText(void) - 0x801CF3C0 | 836 bytes
// ============================================================================
// NON_MATCHING
void O2TTarget__UpdateText(void* self) {
    // Stack: 72 bytes
    // -> UIReflow::UIReflow(void)
    // -> UIReflow::OpenReflowBlock(void)
    // -> UIReflow::Reflow_Id(char *, int)
    // -> UIReflow::Reflow_ColorOnlyOverride(unsigned int)
    // -> UIReflow::SubmitReflowBlock(void)
    // -> UIReflow::~UIReflow(void)

    // Per-frame update
}

// ============================================================================
// O2TTarget::SpawnQuitDialogBox(void) - 0x801CF780 | 736 bytes
// ============================================================================
// NON_MATCHING
void O2TTarget__SpawnQuitDialogBox(void* self) {
    // Stack: 2128 bytes
    // -> EGlobal::GetNewUIString(char *)
    // -> wcscpy
    // -> BString2::operator=(unsigned wchar_t *)
    // -> EGlobal::GetMemCardString(char *)
    // -> memcpy
    // -> UIDialog::SpawnDialog(void)
    // ... and 1 more calls

}

// ============================================================================
// O2TTarget::UpdateShaders(char *, char *) - 0x801CFD30 | 532 bytes
// ============================================================================
// NON_MATCHING
void O2TTarget__UpdateShaders(void* self, char* p1, char* p2) {
    // Stack: 16 bytes
    // -> AtoI(char *)
    // -> UI2D::InstallEntry(char *, unsigned int, char *, int)

    // Per-frame update
}

// ============================================================================
// PAZBase::~PAZBase(void) - 0x801D0190 | 392 bytes
// ============================================================================
// NON_MATCHING
void PAZBase__dtor_PAZBase(void* self) {
    // Stack: 24 bytes
    // -> UIScreenManager::UnloadUIScreen(UIScreenID)
    // -> GetVariableCommandTable::UnInstallAllCommands(CBFunctor1wRet<char *, char *> &)
    // -> SetVariableCommandTable::UnInstallAllCommands(CBFunctor2<char *, char *> &)
    // -> GetLocalizableCommandTable::UnInstallAllCommands(CBFunctor1wRet<char *, unsigned wchar_t *> &)
    // -> UIUpdateTable::UnInstallEntry(CBFunctor0 &)
    // -> UIDrawTable::UnInstallEntry(CBFunctor1<ERC *> &)
    // ... and 6 more calls

    // Release resources
    // __builtin_delete called for cleanup
    // Destroy members
}

// ============================================================================
// PAZBase::GetVariable(char *) - 0x801D0864 | 528 bytes
// ============================================================================
// NON_MATCHING
void* PAZBase__GetVariable(void* self, char* p1) {
    // Stack: 24 bytes
    // -> SimsAptMalloc(unsigned int)
    // -> strcmp
    // -> Sprintf(char *, char *,...)
    // -> EGlobal::IsPlayerInSocialMode(int)
    // -> strcpy
    // Accesses globals via r13 (SDA)

    // Getter
    return 0;
}

// ============================================================================
// PAZBase::ConfigureAndLoad(int, char **, PAZItemInfo *, unsigned int) - 0x801D0B74 | 864 bytes
// ============================================================================
// NON_MATCHING
void PAZBase__ConfigureAndLoad(void* self, int p1, char* p2, void* p3, int p4) {
    // Stack: 16 bytes
    // -> GetVariableCommandTable::InstallCommand(char *, CBFunctor1wRet<char *, char *> &)
    // -> SetVariableCommandTable::InstallCommand(char *, CBFunctor2<char *, char *> &)
    // -> GetLocalizableCommandTable::InstallCommand(char *, CBFunctor1wRet<char *, unsigned wchar_t *> &)
    // -> UIScreenManager::LoadUIScreen(UIScreenID, UIScreenInputMode)
    // -> UIObjectBase::pushAptButtonFilterALL(int, char *)
    // -> UIUpdateTable::InstallEntry(UIUpdateTable::UpdateTablePriority, CBFunctor0 &, char *)
    // ... and 1 more calls

    // Load/parse data
}

// ============================================================================
// PAZBase::on_user_set_selection_index(int) - 0x801D0ED4 | 364 bytes
// ============================================================================
// NON_MATCHING
void PAZBase__on_user_set_selection_index(void* self, int p1) {
    // Stack: 80 bytes
    // -> Sprintf(char *, char *,...)
    // Uses floating point
    // Accesses globals via r13 (SDA)

}

// ============================================================================
// PCTTarget::cCellInfo::Init(ObjSelector *, IGoalUnlock *) - 0x801D1F54 | 288 bytes
// ============================================================================
// NON_MATCHING
void PCTTarget__cCellInfo__Init(void* self, void* p1, void* p2) {
    // Stack: 24 bytes
    // -> ObjSelector::GetGUID(void) const
    // -> GetResDataFromSelector(ObjSelector *)

    // Initialize subsystem
}

// ============================================================================
// PCTTarget::cCellInfo::GetName(unsigned wchar_t *) const - 0x801D21F4 | 264 bytes
// ============================================================================
// NON_MATCHING
void* PCTTarget__cCellInfo__GetName_const(void* self, void* p1) {
    // Stack: 24 bytes
    // -> ObjSelector::GetMasterSelector(void)
    // -> ObjSelector::GetCatalogName(void)
    // -> wcscpy

    // Getter
    return 0;
}

// ============================================================================
// PCTTarget::~PCTTarget(void) - 0x801D3334 | 740 bytes
// ============================================================================
// NON_MATCHING
void PCTTarget__dtor_PCTTarget(void* self) {
    // Stack: 32 bytes
    // -> GetVariableCommandTable::UnInstallAllCommands(CBFunctor1wRet<char *, char *> &)
    // -> SetVariableCommandTable::UnInstallAllCommands(CBFunctor2<char *, char *> &)
    // -> GetLocalizableCommandTable::UnInstallAllCommands(CBFunctor1wRet<char *, unsigned wchar_t *> &)
    // -> UIUpdateTable::UnInstallEntry(CBFunctor0 &)
    // -> UIDrawTable::UnInstallEntry(CBFunctor1<ERC *> &)
    // -> UIUserDrawCBTable::UnInstallAllName(char *)
    // ... and 12 more calls
    // Contains loop(s)
    // Uses floating point

    // Release resources
    // __builtin_vec_delete called for cleanup
    // __builtin_delete called for cleanup
    // Destroy members
}

// ============================================================================
// PCTTarget::Update(void) - 0x801D464C | 856 bytes
// ============================================================================
// NON_MATCHING
void PCTTarget__Update(void* self) {
    // Stack: 96 bytes
    // -> ActionMenu::Run(void)
    // -> BBHTarget::IsBuildBuyHUDActive(void)
    // -> BBHTarget::UpdateBuildBuyHUD(void)
    // -> EGlobal::GetNewUIString(char *)
    // -> BString2::operator=(unsigned wchar_t *)
    // -> memcpy
    // ... and 2 more calls

    // Per-frame update
}

// ============================================================================
// PCTTarget::on_tab_changed(void) - 0x801D4A2C | 368 bytes
// ============================================================================
// NON_MATCHING
void PCTTarget__on_tab_changed(void* self) {
    // Stack: 32 bytes
    // -> __builtin_vec_delete
    // -> PCTTarget::on_tab_changed_objects(void)
    // -> PCTTarget::on_tab_changed_wall(void)
    // -> PCTTarget::on_tab_changed_wallpaper(void)
    // -> PCTTarget::on_tab_changed_floor(void)
    // -> UI2D::InstallEntry(char *, unsigned int, char *, int)
    // ... and 2 more calls
    // Contains loop(s)

}

// ============================================================================
// PCTTarget::on_tab_changed_objects(void) - 0x801D4C54 | 392 bytes
// ============================================================================
// NON_MATCHING
void PCTTarget__on_tab_changed_objects(void* self) {
    // Stack: 32 bytes
    // -> filter_object(PCTTarget::PCTTabInfo *, ObjSelector *)
    // -> __builtin_vec_new
    // -> PCTTarget::cCellInfo::cCellInfo(void)
    // -> PCTTarget::cCellInfo::Init(ObjSelector *, IGoalUnlock *)
    // -> qsort
    // Contains loop(s)

}

// ============================================================================
// PCTTarget::on_tab_changed_wall(void) - 0x801D4DDC | 428 bytes
// ============================================================================
// NON_MATCHING
void PCTTarget__on_tab_changed_wall(void* self) {
    // Stack: 32 bytes
    // -> __builtin_vec_new
    // -> PCTTarget::cCellInfo::cCellInfo(void)
    // -> memset
    // -> EGlobal::GetNewUIString(char *)
    // -> PCTTarget::cCellInfo::Init(int, FenceData *)
    // -> qsort
    // Contains loop(s)
    // Accesses globals via r13 (SDA)

}

// ============================================================================
// PCTTarget::on_tab_changed_wallpaper(void) - 0x801D4FC8 | 388 bytes
// ============================================================================
// NON_MATCHING
void PCTTarget__on_tab_changed_wallpaper(void* self) {
    // Stack: 32 bytes
    // -> filter_wallpaper(WallTile *)
    // -> __builtin_vec_new
    // -> PCTTarget::cCellInfo::cCellInfo(void)
    // -> PCTTarget::cCellInfo::Init(int, WallTile *)
    // -> qsort
    // Contains loop(s)

}

// ============================================================================
// PCTTarget::on_tab_changed_floor(void) - 0x801D51A0 | 464 bytes
// ============================================================================
// NON_MATCHING
void PCTTarget__on_tab_changed_floor(void* self) {
    // Stack: 32 bytes
    // -> EHouse::GetHouseName(void)
    // -> EGlobal::GetHouseGrassShaderId(char *)
    // -> filter_floor(int, unsigned int, FloorTile *)
    // -> __builtin_vec_new
    // -> PCTTarget::cCellInfo::cCellInfo(void)
    // -> PCTTarget::cCellInfo::Init(int, FloorTile *)
    // ... and 1 more calls
    // Contains loop(s)

}

// ============================================================================
// PCTTarget::on_PCT_EnterPlaceMode(void) - 0x801D597C | 772 bytes
// ============================================================================
// NON_MATCHING
void PCTTarget__on_PCT_EnterPlaceMode(void* self) {
    // Stack: 80 bytes
    // -> PCTTarget::get_cell_info_at_gridindex(unsigned int) const
    // -> GetFireCodeValue(bool)
    // -> ERoomWall::GetWallMeterValue(int &)
    // -> EIFenceWall::GetFenceMeterValue(void)
    // -> EGlobal::GetNewUIString(char *)
    // -> BString2::operator=(unsigned wchar_t *)
    // ... and 4 more calls
    // Uses floating point

}

// ============================================================================
// PCTTarget::update_grid_shaders(void) - 0x801D5D28 | 272 bytes
// ============================================================================
// NON_MATCHING
void PCTTarget__update_grid_shaders(void* self) {
    // Stack: 32 bytes
    // -> PCTTarget::get_cell_info_array_index(unsigned int) const
    // -> UI2D::InstallEntry(char *, unsigned int, char *, int)
    // Contains loop(s)

}

// ============================================================================
// PCTTarget::update_object_shader(void) - 0x801D5E38 | 288 bytes
// ============================================================================
// NON_MATCHING
void PCTTarget__update_object_shader(void* self) {
    // Stack: 32 bytes
    // -> PCTTarget::get_cell_info_array_index(unsigned int) const
    // -> FindSelectorContainingResData(ObjSelector *)
    // -> GetObjSelector3dDisplayInfo(ObjSelector *, ObjectDefinition &)
    // -> UI3D::InstallEntry(char *, unsigned int, unsigned int, unsigned int, char *, int)
    // -> UI2D::InstallEntry(char *, unsigned int, char *, int)

}

// ============================================================================
// PCTTarget::calc_motive_ratings(void) - 0x801D5F58 | 484 bytes
// ============================================================================
// NON_MATCHING
void PCTTarget__calc_motive_ratings(void* self) {
    // Stack: 64 bytes
    // -> memset
    // -> PCTTarget::get_cell_info_array_index(unsigned int) const
    // -> ObjSelector::GetMasterSelector(void)
    // -> sub_8039C304
    // -> ObjSelector::GetCatalogRating(int)
    // -> IsSkillCatalogRating(int)
    // ... and 4 more calls
    // Contains loop(s)

}

// ============================================================================
// PCTTarget::enter_tool_mode(PCTTarget::ePCTType, bool) - 0x801D6560 | 708 bytes
// ============================================================================
// NON_MATCHING
void PCTTarget__enter_tool_mode(void* self, void* p1, int p2) {
    // Stack: 96 bytes
    // -> BBHTarget::SetCurrentPrice(int)
    // -> BBHTarget::SetSellingPig(bool)
    // -> play_sound(unsigned int)
    // -> BBHTarget::SetBBHMode(BBHTarget::eBBHMode)
    // -> PCTTarget::start_action_menu(void)
    // -> InteractorModule::InteractorManager::GetSingleton(void)
    // ... and 7 more calls
    // Contains loop(s)
    // Uses floating point

}

// ============================================================================
// PCTTarget::sell_dialog_selection_callback(int) - 0x801D6E68 | 288 bytes
// ============================================================================
// NON_MATCHING
void PCTTarget__sell_dialog_selection_callback(void* self, int p1) {
    // Stack: 24 bytes
    // -> InteractorModule::InteractorManager::GetSingleton(void)
    // -> InteractorModule::InteractorManager::GetPlayerInteractor(int, InteractorModule::InteractorType)
    // -> InteractorModule::ObjectManipulator::GetPlacementObject(void)
    // -> play_sound(unsigned int)
    // -> GetSimFunds(unsigned int)
    // -> SetSimFunds(unsigned int, int)
    // ... and 6 more calls

}

// ============================================================================
// PCTTarget::enter_place_tombstone_mode(void) - 0x801D6F88 | 456 bytes
// ============================================================================
// NON_MATCHING
void PCTTarget__enter_place_tombstone_mode(void* self) {
    // Stack: 112 bytes
    // -> PCTTarget::set_dialog_visible(bool)
    // -> InteractorModule::InteractorManager::GetSingleton(void)
    // -> InteractorModule::InteractorManager::IsValidPlayerId(int) const
    // -> __builtin_new
    // -> PCTTarget::setup_interactor_camera(bool)
    // -> BBHTarget::SetBBHMode(BBHTarget::eBBHMode)
    // Contains loop(s)

}

// ============================================================================
// PCTTarget::enter_place_mode(PCTTarget::cCellInfo *) - 0x801D7150 | 620 bytes
// ============================================================================
// NON_MATCHING
void PCTTarget__enter_place_mode(void* self, void* p1) {
    // Stack: 112 bytes
    // -> BBHTarget::ShowBuildBuyHUD(void)
    // -> BBHTarget::SetSellingPig(bool)
    // -> play_sound(unsigned int)
    // -> BBHTarget::SetBBHMode(BBHTarget::eBBHMode)
    // -> ObjSelector::GetGUID(void) const
    // -> InteractorModule::InteractorManager::GetSingleton(void)
    // ... and 6 more calls
    // Contains loop(s)

}

// ============================================================================
// PCTTarget::PlaceModeCallback(InteractorModule::Interactor::CallbackData *) - 0x801D745C | 880 bytes
// ============================================================================
// NON_MATCHING
void PCTTarget__PlaceModeCallback(void* self, void* p1) {
    // Stack: 48 bytes
    // -> InteractorModule::InteractorManager::GetSingleton(void)
    // -> InteractorModule::InteractorManager::ChangeActiveInteractorToNull(int)
    // -> PCTTarget::set_dialog_visible(bool)
    // -> SetUIStatusText(char *,...)
    // -> play_sound(unsigned int)
    // -> ObjSelector::GetMasterSelector(void)
    // ... and 6 more calls
    // Contains loop(s)
    // Uses floating point
    // Accesses globals via r13 (SDA)

    // Callback handler
}

// ============================================================================
// PCTTarget::enter_wall_mode(PCTTarget::cCellInfo *, bool) - 0x801D77CC | 644 bytes
// ============================================================================
// NON_MATCHING
void PCTTarget__enter_wall_mode(void* self, void* p1, int p2) {
    // Stack: 96 bytes
    // -> GetSimFunds(unsigned int)
    // -> PCTTarget::cCellInfo::GetPrice(void) const
    // -> BBHTarget::SetBBHMode(BBHTarget::eBBHMode)
    // -> PCTTarget::setup_interactor_camera(bool)
    // -> InteractorModule::InteractorManager::GetSingleton(void)
    // -> InteractorModule::InteractorManager::IsValidPlayerId(int) const
    // ... and 1 more calls
    // Contains loop(s)
    // Accesses globals via r13 (SDA)

}

// ============================================================================
// PCTTarget::WallManipulatorCallback(InteractorModule::Interactor::CallbackData *) - 0x801D7A50 | 604 bytes
// ============================================================================
// NON_MATCHING
void PCTTarget__WallManipulatorCallback(void* self, void* p1) {
    // Stack: 40 bytes
    // -> InteractorModule::InteractorManager::GetSingleton(void)
    // -> InteractorModule::InteractorManager::ChangeActiveInteractorToNull(int)
    // -> PCTTarget::set_dialog_visible(bool)
    // -> play_sound(unsigned int)
    // -> PCTTarget::enter_wallpaper_mode(PCTTarget::cCellInfo *, bool)
    // -> PCTTarget::calc_wall_value(InteractorModule::Interactor::CallbackData *)
    // ... and 6 more calls
    // Uses floating point
    // Accesses globals via r13 (SDA)

    // Callback handler
}

// ============================================================================
// PCTTarget::enter_wallpaper_mode(PCTTarget::cCellInfo *, bool) - 0x801D7DA0 | 568 bytes
// ============================================================================
// NON_MATCHING
void PCTTarget__enter_wallpaper_mode(void* self, void* p1, int p2) {
    // Stack: 96 bytes
    // -> GetSimFunds(unsigned int)
    // -> PCTTarget::cCellInfo::GetPrice(void) const
    // -> BBHTarget::SetBBHMode(BBHTarget::eBBHMode)
    // -> PCTTarget::setup_interactor_camera(bool)
    // -> InteractorModule::InteractorManager::GetSingleton(void)
    // -> InteractorModule::InteractorManager::IsValidPlayerId(int) const
    // ... and 1 more calls
    // Contains loop(s)

}

// ============================================================================
// PCTTarget::WallPainterCallback(InteractorModule::Interactor::CallbackData *) - 0x801D8088 | 532 bytes
// ============================================================================
// NON_MATCHING
void PCTTarget__WallPainterCallback(void* self, void* p1) {
    // Stack: 40 bytes
    // -> InteractorModule::InteractorManager::GetSingleton(void)
    // -> InteractorModule::InteractorManager::ChangeActiveInteractorToNull(int)
    // -> PCTTarget::set_dialog_visible(bool)
    // -> play_sound(unsigned int)
    // -> PCTTarget::calc_wallpaper_value(InteractorModule::Interactor::CallbackData *)
    // -> GetSimFunds(unsigned int)
    // ... and 6 more calls
    // Contains loop(s)
    // Uses floating point

    // Callback handler
}

// ============================================================================
// PCTTarget::enter_floor_mode(PCTTarget::cCellInfo *, bool) - 0x801D829C | 560 bytes
// ============================================================================
// NON_MATCHING
void PCTTarget__enter_floor_mode(void* self, void* p1, int p2) {
    // Stack: 96 bytes
    // -> GetSimFunds(unsigned int)
    // -> PCTTarget::cCellInfo::GetPrice(void) const
    // -> BBHTarget::SetBBHMode(BBHTarget::eBBHMode)
    // -> PCTTarget::setup_interactor_camera(bool)
    // -> InteractorModule::InteractorManager::GetSingleton(void)
    // -> InteractorModule::InteractorManager::IsValidPlayerId(int) const
    // ... and 1 more calls
    // Contains loop(s)

}

// ============================================================================
// PCTTarget::FloorPainterCallback(InteractorModule::Interactor::CallbackData *) - 0x801D84CC | 400 bytes
// ============================================================================
// NON_MATCHING
void PCTTarget__FloorPainterCallback(void* self, void* p1) {
    // Stack: 24 bytes
    // -> InteractorModule::InteractorManager::GetSingleton(void)
    // -> InteractorModule::InteractorManager::ChangeActiveInteractorToNull(int)
    // -> PCTTarget::set_dialog_visible(bool)
    // -> SetUIStatusText(char *,...)
    // -> play_sound(unsigned int)
    // -> PCTTarget::enter_wall_mode(PCTTarget::cCellInfo *, bool)
    // ... and 6 more calls
    // Contains loop(s)

    // Callback handler
}

// ============================================================================
// PRGTarget::~PRGTarget(void) - 0x801D9098 | 400 bytes
// ============================================================================
// NON_MATCHING
void PRGTarget__dtor_PRGTarget(void* self) {
    // Stack: 16 bytes
    // -> UIObjectBase::popAptButtonFilter(int, unsigned int)
    // -> UIScreenManager::UnloadUIScreen(UIScreenID)
    // -> GetVariableCommandTable::UnInstallAllCommands(CBFunctor1wRet<char *, char *> &)
    // -> SetVariableCommandTable::UnInstallAllCommands(CBFunctor2<char *, char *> &)
    // -> GetLocalizableCommandTable::UnInstallAllCommands(CBFunctor1wRet<char *, unsigned wchar_t *> &)
    // -> UIUpdateTable::UnInstallEntry(CBFunctor0 &)
    // ... and 6 more calls

    // Release resources
    // __builtin_delete called for cleanup
    // Destroy members
}

// ============================================================================
// PRGTarget::GetTotalSkillPoints(void) - 0x801D9604 | 472 bytes
// ============================================================================
// NON_MATCHING
int PRGTarget__GetTotalSkillPoints(void* self) {
    // Stack: 40 bytes
    // -> Player::GetPrimaryNeighbor(void)

    // Getter
    return 0;
}

// ============================================================================
// PRGTarget::GetMaxedSkills(void) - 0x801D97DC | 360 bytes
// ============================================================================
// NON_MATCHING
void* PRGTarget__GetMaxedSkills(void* self) {
    // Stack: 24 bytes
    // -> Player::GetPrimaryNeighbor(void)

    // Getter
    return 0;
}

// ============================================================================
// R2LTarget::~R2LTarget(void) - 0x801DAF90 | 668 bytes
// ============================================================================
// NON_MATCHING
void R2LTarget__dtor_R2LTarget(void* self) {
    // Stack: 48 bytes
    // -> EResource::DelRef(void)
    // -> BString2::~BString2(void)
    // -> __builtin_vec_delete
    // -> UIObjectBase::popAptButtonFilter(int, unsigned int)
    // -> UIScreenManager::UnloadUIScreen(UIScreenID)
    // -> GetVariableCommandTable::UnInstallAllCommands(CBFunctor1wRet<char *, char *> &)
    // ... and 12 more calls
    // Contains loop(s)

    // Release resources
    // __builtin_vec_delete called for cleanup
    // __builtin_delete called for cleanup
    // Destroy members
}

// ============================================================================
// R2LTarget::SetVariable(char *, char *) - 0x801DB22C | 776 bytes
// ============================================================================
// NON_MATCHING
void R2LTarget__SetVariable(void* self, char* p1, char* p2) {
    // Stack: 40 bytes
    // -> isdigit
    // -> strcmp
    // -> AtoI(char *)
    // -> R2LTarget::ChangeSelection(int)
    // -> R2LTarget::SpawnSummaryDialog(void)
    // -> R2LTarget::ScrollRightEnabled(void)
    // ... and 4 more calls

    // Setter
}

// ============================================================================
// R2LTarget::GetVariable(char *) - 0x801DB534 | 400 bytes
// ============================================================================
// NON_MATCHING
void* R2LTarget__GetVariable(void* self, char* p1) {
    // Stack: 24 bytes
    // -> isdigit
    // -> SimsAptMalloc(unsigned int)
    // -> strcmp
    // -> R2LTarget::ScrollLeftEnabled(void)
    // -> R2LTarget::ScrollRightEnabled(void)
    // -> Sprintf(char *, char *,...)

    // Getter
    return 0;
}

// ============================================================================
// R2LTarget::SpawnSummaryDialog(void) - 0x801DBB9C | 676 bytes
// ============================================================================
// NON_MATCHING
void R2LTarget__SpawnSummaryDialog(void* self) {
    // Stack: 88 bytes
    // -> EGlobal::GetNewUIString(char *)
    // -> BString2::operator=(unsigned wchar_t *)
    // -> EGlobal::GetPDAString(char *)
    // -> memcpy
    // -> UIDialog::SpawnDialog(void)

}

// ============================================================================
// R2LTarget::SetupRelationships(void) - 0x801DBE40 | 884 bytes
// ============================================================================
// NON_MATCHING
void R2LTarget__SetupRelationships(void* self) {
    // Stack: 72 bytes
    // -> HoodManager::GetRelatedPeople(int, cXPerson *, void *)
    // -> Neighbor::GetGUID(void)
    // -> __builtin_vec_new
    // -> BString2::BString2(void)
    // -> Neighbor::GetRelationship(Neighbor *, int *)
    // -> ObjSelector::GetUserName(void)
    // ... and 7 more calls
    // Contains loop(s)
    // Accesses globals via r13 (SDA)

    // Setter
}

// ============================================================================
// RCPTarget::~RCPTarget(void) - 0x801DD904 | 408 bytes
// ============================================================================
// NON_MATCHING
void RCPTarget__dtor_RCPTarget(void* self) {
    // Stack: 16 bytes
    // -> GetVariableCommandTable::UnInstallAllCommands(CBFunctor1wRet<char *, char *> &)
    // -> SetVariableCommandTable::UnInstallAllCommands(CBFunctor2<char *, char *> &)
    // -> GetLocalizableCommandTable::UnInstallAllCommands(CBFunctor1wRet<char *, unsigned wchar_t *> &)
    // -> UIUpdateTable::UnInstallEntry(CBFunctor0 &)
    // -> UIDrawTable::UnInstallEntry(CBFunctor1<ERC *> &)
    // -> UIUserDrawCBTable::UnInstallAllName(char *)
    // ... and 7 more calls

    // Release resources
    // __builtin_delete called for cleanup
    // Destroy members
}

// ============================================================================
// sum_attribute(int, RCPTarget::Recipe *) - 0x801DDA9C | 308 bytes
// ============================================================================
// NON_MATCHING
void sum_attribute(void* self, int p1, void* p2) {
    // Stack: 40 bytes
    // -> GetIngredientManager(void)
    // -> IngredientManager::GetIngredient(short) const
    // Contains loop(s)

}

// ============================================================================
// RCPTarget::make_recipe_text(RCPTarget::Recipe *, BString2 &) - 0x801DDBD0 | 444 bytes
// ============================================================================
// NON_MATCHING
void RCPTarget__make_recipe_text(void* self, void* p1, void* p2) {
    // Stack: 568 bytes
    // -> BString2::erase(unsigned int, unsigned int)
    // -> sum_attribute(int, RCPTarget::Recipe *)
    // -> EGlobal::GetNewUIString(char *)
    // -> BString2::append(unsigned wchar_t *)
    // -> UIObjectBase::makeNumberString(int, unsigned wchar_t *)

}

// ============================================================================
// RCPTarget::GetVariable(char *) - 0x801DE1E8 | 324 bytes
// ============================================================================
// NON_MATCHING
void* RCPTarget__GetVariable(void* self, char* p1) {
    // Stack: 24 bytes
    // -> SimsAptMalloc(unsigned int)
    // -> strcmp
    // -> Sprintf(char *, char *,...)
    // -> strlen

    // Getter
    return 0;
}

// ============================================================================
// RCPTarget::GetLocalizable(char *) - 0x801DE32C | 392 bytes
// ============================================================================
// NON_MATCHING
void* RCPTarget__GetLocalizable(void* self, char* p1) {
    // Stack: 8224 bytes
    // -> memset
    // -> strncmp
    // -> AtoI(char *)
    // -> UIObjectBase::makeNumberString(int, unsigned wchar_t *)
    // -> GetRecipeName(RCPTarget::Recipe *)
    // -> strcmp
    // ... and 5 more calls
    // Contains loop(s)

    // Getter
    return 0;
}

// ============================================================================
// RCPTarget::init_recipes(void) - 0x801DE538 | 444 bytes
// ============================================================================
// NON_MATCHING
void RCPTarget__init_recipes(void* self) {
    // Stack: 48 bytes
    // -> GetIngredientManager(void)
    // -> IngredientManager::GetIngredient(short) const
    // -> IngredientManager::MixIngredients(short, short, short, short) const
    // Contains loop(s)
    // Accesses globals via r13 (SDA)

}

// ============================================================================
// RCPTarget::install_ing_shaders(void) - 0x801DE85C | 956 bytes
// ============================================================================
// NON_MATCHING
void RCPTarget__install_ing_shaders(void* self) {
    // Stack: 80 bytes
    // -> GetIngredientManager(void)
    // -> UI2D::InstallEntry(char *, unsigned int, char *, int)
    // -> IngredientManager::GetIngredient(short) const
    // -> RCPTarget::get_plus_shaders(RCPTarget::Recipe &, unsigned int &, unsigned int &)
    // -> RCPTarget::get_proc_shaders(RCPTarget::Recipe &, unsigned int &, unsigned int &)
    // Contains loop(s)

}

// ============================================================================
// RCPTarget::get_proc_shaders(RCPTarget::Recipe &, unsigned int &, unsigned int &) - 0x801DECB4 | 308 bytes
// ============================================================================
// NON_MATCHING
void RCPTarget__get_proc_shaders(void* self, void* p1, int p2, int p3) {

}

// ============================================================================
// RMDTarget::~RMDTarget(void) - 0x801DF648 | 496 bytes
// ============================================================================
// NON_MATCHING
void RMDTarget__dtor_RMDTarget(void* self) {
    // Stack: 32 bytes
    // -> UIObjectBase::popAptButtonFilter(int, unsigned int)
    // -> H2DTarget::ReleasePause(bool)
    // -> UI3D::UnInstallEntry(char *)
    // -> UIScreenManager::UnloadUIScreen(UIScreenID)
    // -> GetVariableCommandTable::UnInstallAllCommands(CBFunctor1wRet<char *, char *> &)
    // -> SetVariableCommandTable::UnInstallAllCommands(CBFunctor2<char *, char *> &)
    // ... and 9 more calls
    // Contains loop(s)
    // Accesses globals via r13 (SDA)

    // Release resources
    // H2DTarget::ReleasePause(bool) called for cleanup
    // __builtin_delete called for cleanup
    // Destroy members
}

// ============================================================================
// RMDTarget::SetVariable(char *, char *) - 0x801DF838 | 348 bytes
// ============================================================================
// NON_MATCHING
void RMDTarget__SetVariable(void* self, char* p1, char* p2) {
    // Stack: 40 bytes
    // -> isdigit
    // -> strcmp
    // -> RMDTarget::StartHideTween(void)
    // -> UIReflow::UIReflow(void)
    // -> UIReflow::OpenReflowBlock(void)
    // -> UIReflow::Reflow_Id(char *, int)
    // ... and 5 more calls
    // Accesses globals via r13 (SDA)

    // Setter
}

// ============================================================================
// RMDTarget::UnloadDialog(void) - 0x801DFFA4 | 424 bytes
// ============================================================================
// NON_MATCHING
void RMDTarget__UnloadDialog(void* self) {
    // Stack: 24 bytes
    // -> UIObjectBase::popAptButtonFilter(int, unsigned int)
    // -> H2DTarget::ReleasePause(bool)
    // -> GetVariableCommandTable::UnInstallAllCommands(CBFunctor1wRet<char *, char *> &)
    // -> SetVariableCommandTable::UnInstallAllCommands(CBFunctor2<char *, char *> &)
    // -> GetLocalizableCommandTable::UnInstallAllCommands(CBFunctor1wRet<char *, unsigned wchar_t *> &)
    // -> UIUpdateTable::UnInstallEntry(CBFunctor0 &)
    // ... and 7 more calls
    // Contains loop(s)

}

// ============================================================================
// SKLTarget::~SKLTarget(void) - 0x801E0DC8 | 364 bytes
// ============================================================================
// NON_MATCHING
void SKLTarget__dtor_SKLTarget(void* self) {
    // Stack: 16 bytes
    // -> UIScreenManager::UnloadUIScreen(UIScreenID)
    // -> GetVariableCommandTable::UnInstallAllCommands(CBFunctor1wRet<char *, char *> &)
    // -> SetVariableCommandTable::UnInstallAllCommands(CBFunctor2<char *, char *> &)
    // -> GetLocalizableCommandTable::UnInstallAllCommands(CBFunctor1wRet<char *, unsigned wchar_t *> &)
    // -> UIUpdateTable::UnInstallEntry(CBFunctor0 &)
    // -> UIDrawTable::UnInstallEntry(CBFunctor1<ERC *> &)
    // ... and 5 more calls

    // Release resources
    // __builtin_delete called for cleanup
    // Destroy members
}

// ============================================================================
// SKLTarget::SetVariable(char *, char *) - 0x801E0F34 | 280 bytes
// ============================================================================
// NON_MATCHING
void SKLTarget__SetVariable(void* self, char* p1, char* p2) {
    // Stack: 48 bytes
    // -> isdigit
    // -> strcmp
    // -> UIReflow::UIReflow(void)
    // -> UIReflow::ResetVisibility(char *, bool, int)
    // -> UIReflow::~UIReflow(void)
    // Accesses globals via r13 (SDA)

    // Setter
}

// ============================================================================
// SKLTarget::GetLocalizable(char *) - 0x801E10E4 | 808 bytes
// ============================================================================
// NON_MATCHING
void* SKLTarget__GetLocalizable(void* self, char* p1) {
    // Stack: 24 bytes
    // -> isdigit
    // -> SimsAptMalloc(unsigned int)
    // -> strcmp
    // -> UIObjectBase::makeNumberString(int, unsigned wchar_t *)
    // -> wcslen
    // -> UIQDTarget::UIQDSubstitutionStrings(unsigned wchar_t *)
    // ... and 2 more calls
    // Accesses globals via r13 (SDA)

    // Getter
    return 0;
}

// ============================================================================
// SKLTarget::Update(void) - 0x801E140C | 540 bytes
// ============================================================================
// NON_MATCHING
void SKLTarget__Update(void* self) {
    // Stack: 40 bytes
    // -> UIReflow::UIReflow(void)
    // -> UIReflow::OpenReflowBlock(void)
    // -> UIReflow::Reflow_Id(char *, int)
    // -> UIReflow::Reflow_Visibility(bool)
    // -> UIReflow::Reflow_X(int)
    // -> UIReflow::SubmitReflowBlock(void)
    // ... and 5 more calls
    // Accesses globals via r13 (SDA)

    // Per-frame update
}

// ============================================================================
// SKLTarget::UpdateSkillsBar(void) - 0x801E1644 | 888 bytes
// ============================================================================
// NON_MATCHING
void SKLTarget__UpdateSkillsBar(void* self) {
    // Stack: 136 bytes
    // -> UIReflow::UIReflow(void)
    // -> UIReflow::OpenReflowBlock(void)
    // -> Sprintf(char *, char *,...)
    // -> UIReflow::Reflow_Id(char *, int)
    // -> UIReflow::Reflow_FontSizeOverride(unsigned int)
    // -> UIReflow::Reflow_SwfAnimation(char *)
    // ... and 3 more calls
    // Contains loop(s)

    // Per-frame update
    // Iterates over elements
}

// ============================================================================
// WAFTarget::~WAFTarget(void) - 0x801E2D10 | 432 bytes
// ============================================================================
// NON_MATCHING
void WAFTarget__dtor_WAFTarget(void* self) {
    // Stack: 24 bytes
    // -> UIScreenManager::UnloadUIScreen(UIScreenID)
    // -> GetVariableCommandTable::UnInstallAllCommands(CBFunctor1wRet<char *, char *> &)
    // -> SetVariableCommandTable::UnInstallAllCommands(CBFunctor2<char *, char *> &)
    // -> GetLocalizableCommandTable::UnInstallAllCommands(CBFunctor1wRet<char *, unsigned wchar_t *> &)
    // -> UIUpdateTable::UnInstallEntry(CBFunctor0 &)
    // -> UIDrawTable::UnInstallEntry(CBFunctor1<ERC *> &)
    // ... and 7 more calls
    // Contains loop(s)
    // Accesses globals via r13 (SDA)

    // Release resources
    // __builtin_delete called for cleanup
    // Destroy members
}

// ============================================================================
// WAFTarget::SetVariable(char *, char *) - 0x801E2EC0 | 520 bytes
// ============================================================================
// NON_MATCHING
void WAFTarget__SetVariable(void* self, char* p1, char* p2) {
    // Stack: 24 bytes
    // -> isdigit
    // -> strcmp
    // -> UIReflow::ResetVisibility(char *, bool, int)
    // -> WAFTarget::OnShow(void)
    // -> UIReflow::OpenReflowBlock(void)
    // -> UIReflow::Reflow_Id(char *, int)
    // ... and 5 more calls
    // Accesses globals via r13 (SDA)

    // Setter
}

// ============================================================================
// WAFTarget::GetLocalizable(char *) - 0x801E3160 | 280 bytes
// ============================================================================
// NON_MATCHING
void* WAFTarget__GetLocalizable(void* self, char* p1) {
    // Stack: 32 bytes
    // -> isdigit
    // -> SimsAptMalloc(unsigned int)
    // -> strncmp
    // -> Sscanf(char *, char *,...)
    // -> SimsAptFree(void *)
    // -> BString2::c_str(void) const
    // ... and 3 more calls

    // Getter
    return 0;
}

// ============================================================================
// WAFTarget::Update(void) - 0x801E3278 | 764 bytes
// ============================================================================
// NON_MATCHING
void WAFTarget__Update(void* self) {
    // Stack: 64 bytes
    // -> WAFTarget::GlowEffectAwayStart(void)
    // -> UIReflow::UIReflow(void)
    // -> UIReflow::OpenReflowBlock(void)
    // -> UIReflow::Reflow_Id(char *, int)
    // -> UIReflow::Reflow_Visibility(bool)
    // -> UIReflow::Reflow_X(int)
    // ... and 7 more calls
    // Contains loop(s)
    // Uses floating point
    // Accesses globals via r13 (SDA)

    // Per-frame update
    // Iterates over elements
}

// ============================================================================
// WAFTarget::UpdateWantsAndFears(void) - 0x801E3590 | 872 bytes
// ============================================================================
// NON_MATCHING
void WAFTarget__UpdateWantsAndFears(void* self) {
    // Stack: 72 bytes
    // -> WAFTarget::UpdateAspirationMeter(void)
    // -> WAFTarget::MapGameAspirationValueToMeterValue(float)
    // -> WAFTarget::SetAspirationMeterHeight(int)
    // -> WAFTarget::BeginMeterTween(void)
    // -> UIReflow::OpenReflowBlock(void)
    // -> UIReflow::Reflow_Id(char *, int)
    // ... and 8 more calls
    // Contains loop(s)
    // Uses floating point
    // Accesses globals via r13 (SDA)

    // Per-frame update
    // Iterates over elements
}

// ============================================================================
// WAFTarget::NewWantsAndFearsIcon(int, unsigned int, unsigned int, WAFTarget::eWAFIconAnim, Neighbor *) - 0x801E3900 | 924 bytes
// ============================================================================
// NON_MATCHING
void WAFTarget__NewWantsAndFearsIcon(void* self, int p1, int p2, int p3, void* p4, void* p5) {
    // Stack: 72 bytes
    // -> WantFear::Bookmark::GetType(void) const
    // -> WantFear::Bookmark::GetText(BString2 &, Neighbor *, bool) const
    // -> Sprintf(char *, char *,...)
    // -> __builtin_new
    // -> UIAUDIO::UIAUDIO(void)
    // -> UIAUDIO::PlaySound(unsigned int)
    // ... and 9 more calls
    // Uses floating point
    // Accesses globals via r13 (SDA)

}

// ============================================================================
// WAFTarget::StartAnimation(int) - 0x801E3C9C | 452 bytes
// ============================================================================
// NON_MATCHING
void WAFTarget__StartAnimation(void* self, int p1) {
    // Stack: 40 bytes
    // -> UIReflow::ResetSwfAnimation(char *, char *, int)
    // -> UIReflow::OpenReflowBlock(void)
    // -> UIReflow::Reflow_Id(char *, int)
    // -> UIReflow::Reflow_SwfFile(char *)
    // -> UIReflow::Reflow_Visibility(bool)
    // -> UIReflow::SubmitReflowBlock(void)
    // ... and 4 more calls
    // Uses floating point
    // Accesses globals via r13 (SDA)

}

// ============================================================================
// WAFTarget::FinishSettingIcon(int) - 0x801E3E60 | 336 bytes
// ============================================================================
// NON_MATCHING
void WAFTarget__FinishSettingIcon(void* self, int p1) {
    // Stack: 56 bytes
    // -> UIReflow::OpenReflowBlock(void)
    // -> UIReflow::Reflow_Id(char *, int)
    // -> UIReflow::Reflow_SwfFile(char *)
    // -> UIReflow::Reflow_Visibility(bool)
    // -> Sprintf(char *, char *,...)
    // -> UIReflow::SubmitReflowBlock(void)
    // ... and 1 more calls
    // Uses floating point

    // Setter
}

// ============================================================================
// WAFTarget::BeginBottomBarTween(void) - 0x801E4140 | 516 bytes
// ============================================================================
// NON_MATCHING
void WAFTarget__BeginBottomBarTween(void* self) {
    // Stack: 32 bytes
    // -> UIReflow::OpenTweenBlock(char *, unsigned int, unsigned int, char *, int)
    // -> UIReflow::Tween_ColorOnlyOverride(unsigned int)
    // -> UIReflow::SubmitTweenBlock(void)
    // -> UIReflow::OpenReflowBlock(void)
    // -> UIReflow::Reflow_Id(char *, int)
    // -> UIReflow::Reflow_Visibility(bool)
    // ... and 3 more calls
    // Uses floating point

}

// ============================================================================
// WAFTarget::BeginTopBarTween(void) - 0x801E4344 | 516 bytes
// ============================================================================
// NON_MATCHING
void WAFTarget__BeginTopBarTween(void* self) {
    // Stack: 48 bytes
    // -> UIReflow::OpenReflowBlock(void)
    // -> UIReflow::Reflow_Id(char *, int)
    // -> UIReflow::Reflow_Visibility(bool)
    // -> UIReflow::Reflow_Y(int)
    // -> UIReflow::SubmitReflowBlock(void)
    // -> WAFTarget::CalculateTweenTargetPosition(void)
    // ... and 3 more calls
    // Uses floating point
    // Accesses globals via r13 (SDA)

}

// ============================================================================
// WAFTarget::GlowEffectStart(void) - 0x801E4858 | 280 bytes
// ============================================================================
// NON_MATCHING
void WAFTarget__GlowEffectStart(void* self) {
    // Stack: 16 bytes
    // -> UIReflow::OpenTweenBlock(char *, unsigned int, unsigned int, char *, int)
    // -> UIReflow::Tween_Alpha(unsigned int)
    // -> UIReflow::SubmitTweenBlock(void)
    // Contains loop(s)
    // Uses floating point
    // Accesses globals via r13 (SDA)

}

// ============================================================================
// WAFTarget::UpdateAspirationMeter(void) - 0x801E4BBC | 872 bytes
// ============================================================================
// NON_MATCHING
void WAFTarget__UpdateAspirationMeter(void* self) {
    // Stack: 48 bytes
    // -> WAFTarget::MapGameAspirationValueToMeterValue(float)
    // -> UIReflow::OpenReflowBlock(void)
    // -> UIReflow::Reflow_Id(char *, int)
    // -> UIReflow::Reflow_Y(int)
    // -> UIReflow::SubmitReflowBlock(void)
    // -> UIReflow::OpenTweenBlock(char *, unsigned int, unsigned int, char *, int)
    // ... and 3 more calls
    // Uses floating point

    // Per-frame update
}

// ============================================================================
// WXFTarget::~WXFTarget(void) - 0x801E5B14 | 424 bytes
// ============================================================================
// NON_MATCHING
void WXFTarget__dtor_WXFTarget(void* self) {
    // Stack: 16 bytes
    // -> UIObjectBase::popAptButtonFilter(int, unsigned int)
    // -> UIScreenManager::UnloadUIScreen(UIScreenID)
    // -> GetVariableCommandTable::UnInstallAllCommands(CBFunctor1wRet<char *, char *> &)
    // -> SetVariableCommandTable::UnInstallAllCommands(CBFunctor2<char *, char *> &)
    // -> GetLocalizableCommandTable::UnInstallAllCommands(CBFunctor1wRet<char *, unsigned wchar_t *> &)
    // -> UIUpdateTable::UnInstallEntry(CBFunctor0 &)
    // ... and 7 more calls

    // Release resources
    // __builtin_delete called for cleanup
    // Destroy members
}

// ============================================================================
// WXFTarget::SetVariable(char *, char *) - 0x801E5CBC | 288 bytes
// ============================================================================
// NON_MATCHING
void WXFTarget__SetVariable(void* self, char* p1, char* p2) {
    // Stack: 24 bytes
    // -> strcmp
    // -> WXFTarget::Shutdown(void)
    // -> WXFTarget::OnCancelKeyPressed(char *, char *)
    // -> WXFTarget::UpdateMenuState(char *, char *)
    // -> WXFTarget::OnLeftKeyPressed(char *, char *)
    // -> WXFTarget::OnRightKeyPressed(char *, char *)
    // ... and 1 more calls
    // Accesses globals via r13 (SDA)

    // Setter
}

// ============================================================================
// WXFTarget::GetLocalizable(char *) - 0x801E5DDC | 952 bytes
// ============================================================================
// NON_MATCHING
void* WXFTarget__GetLocalizable(void* self, char* p1) {
    // Stack: 336 bytes
    // -> strncpy
    // -> SimsAptMalloc(unsigned int)
    // -> strcmp
    // -> EGlobal::GetPDAString(char *)
    // -> WXFTarget::UpdateWAFText(char *)
    // -> wcscpy
    // ... and 5 more calls

    // Getter
    return 0;
}

// ============================================================================
// WXFTarget::GetVariable(char *) - 0x801E6194 | 264 bytes
// ============================================================================
// NON_MATCHING
void* WXFTarget__GetVariable(void* self, char* p1) {
    // Stack: 24 bytes
    // -> SimsAptMalloc(unsigned int)
    // -> strcmp
    // -> WXFTarget::GetAspirationIcon(void)
    // -> Sprintf(char *, char *,...)

    // Getter
    return 0;
}

// ============================================================================
// WXFTarget::UpdateWAFText(char *) - 0x801E6BD8 | 536 bytes
// ============================================================================
// NON_MATCHING
void WXFTarget__UpdateWAFText(void* self, char* p1) {
    // Stack: 56 bytes
    // -> UIReflow::UIReflow(void)
    // -> UIReflow::ResetVisibility(char *, bool, int)
    // -> strcmp
    // -> BString2::BString2(void)
    // -> WantFear::Bookmark::GetText(BString2 &, Neighbor *, bool) const
    // -> BString2::c_str(void) const
    // ... and 5 more calls
    // Accesses globals via r13 (SDA)

    // Per-frame update
}

// ============================================================================
// UIDialog::UIDialog(void) - 0x801E6F2C | 280 bytes
// ============================================================================
// NON_MATCHING
void UIDialog__UIDialog(void* self) {
    // Stack: 40 bytes
    // -> BString2::BString2(void)
    // -> BString2::operator=(unsigned wchar_t *)

    // Initialize members
    // Object size >= 0x84
}
