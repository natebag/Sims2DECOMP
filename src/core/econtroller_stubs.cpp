// econtroller_stubs.cpp - Stub implementations for Econtroller
// Auto-generated from symbols.json - 51 functions
// These are stub implementations to register progress.
// Each function needs proper decompilation to match the original binary.

#include "types.h"

// 0x804ACA54 | 324 bytes
EController::EController(void) { }

// 0x804ACB98 | 120 bytes
EController::~EController(void) { }

// 0x804ACC10 | 92 bytes
void EController::Update(void) { }

// 0x804ACC6C | 368 bytes
void EController::UpdateAutoRepeat(void) { }

// 0x804ACE4C | 68 bytes
void EController::SetCommandMap(EBtnToCmdAssoc *, int) { }

// 0x804ACED0 | 312 bytes
void EController::IsInUse(void) { }

// 0x804AD070 | 112 bytes
void EController::VibrateMotorOne(float) { }

// 0x804AD130 | 112 bytes
void EController::VibrateMotorTwo(float) { }

// 0x804AD1F0 | 132 bytes
void EController::VibrateAll(float, float) { }

// 0x804AD3EC | 116 bytes
void EController::StopVibration(void) { }

// 0x804AD460 | 188 bytes
void EController::UpdateVibration(void) { }

// 0x804AD51C | 92 bytes
void EController::PauseMotors(void) { }

// 0x804AD578 | 72 bytes
void EController::ResumeMotors(void) { }

// 0x804AD5E4 | 296 bytes
void EController::UpdateButtonData(unsigned int) { }

// 0x804AD70C | 136 bytes
void EController::UpdateStickData(int, int, float) { }

// 0x804AD794 | 188 bytes
void EController::AddPressedEventData(unsigned int) { }

// 0x804AD850 | 188 bytes
void EController::AddReleasedEventData(unsigned int) { }

// 0x804AD924 | 204 bytes
void EController::GetStick(int, int, unsigned int) { }

// 0x804AD9F0 | 100 bytes
void EController::IsStickFiltered(int, int, unsigned int) { }

// 0x804ADA54 | 196 bytes
void EController::StickMoved(int, float, unsigned int) { }

// 0x804ADB18 | 204 bytes
void EController::GetLastStick(int, int, unsigned int) { }

// 0x804ADBF4 | 68 bytes
void EController::GetBtnResult(unsigned int, bool, unsigned int) { }

// 0x804ADC98 | 148 bytes
void EController::FindFirstCommand(unsigned int) { }

// 0x804ADD2C | 204 bytes
void EController::GetCmdResult(unsigned int, unsigned int, unsigned int, bool) { }

// 0x804ADDF8 | 240 bytes
void EController::AddFilter(unsigned int, char *, int) { }

// 0x804ADEE8 | 188 bytes
void EController::RemoveFilter(unsigned int) { }

// 0x804ADFA4 | 252 bytes
void EController::MoveFilterToTop(unsigned int) { }

// 0x804AE0A0 | 68 bytes
void EController::SetFilter(unsigned int, unsigned int) { }

// 0x804AE0E4 | 68 bytes
void EController::AddCmdToFilter(unsigned int, unsigned int) { }

// 0x804AE128 | 92 bytes
void EController::AddCmdsToFilter(unsigned int, unsigned int *, int) { }

// 0x804AE184 | 68 bytes
void EController::RemoveCmdFromFilter(unsigned int, unsigned int) { }

// 0x804AE1C8 | 76 bytes
void EController::AddBtnToFilter(unsigned int, unsigned int) { }

// 0x804AE214 | 76 bytes
void EController::RemoveBtnFromFilter(unsigned int, unsigned int) { }

// 0x804AE260 | 88 bytes
void EController::GetCmdButtonMask(unsigned int) { }

// 0x804AE2B8 | 68 bytes
void EController::GetFilterIndex(unsigned int) { }

// 0x804AE2FC | 120 bytes
void EController::GetFilterMask(unsigned int) { }

// 0x804AE4A4 | 96 bytes
void EController::GetCmdDown(unsigned int, unsigned int) { }

// 0x804AE504 | 96 bytes
void EController::GetCmdPressed(unsigned int, unsigned int) { }

// 0x804AE564 | 96 bytes
void EController::GetCmdReleased(unsigned int, unsigned int) { }

// 0x804AE5C4 | 96 bytes
void EController::GetCmdUp(unsigned int, unsigned int) { }

// 0x804AE624 | 96 bytes
void EController::GetCmdRepeat(unsigned int, unsigned int) { }

// 0x804AE684 | 72 bytes
void EController::GetBtnDown(unsigned int, unsigned int) { }

// 0x804AE6CC | 72 bytes
void EController::GetBtnDownAny(unsigned int, unsigned int) { }

// 0x804AE714 | 72 bytes
void EController::GetBtnUp(unsigned int, unsigned int) { }

// 0x804AE75C | 72 bytes
void EController::GetBtnUpAny(unsigned int, unsigned int) { }

// 0x804AE7A4 | 72 bytes
void EController::GetBtnPressed(unsigned int, unsigned int) { }

// 0x804AE7EC | 72 bytes
void EController::GetBtnPressedAny(unsigned int, unsigned int) { }

// 0x804AE834 | 72 bytes
void EController::GetBtnReleased(unsigned int, unsigned int) { }

// 0x804AE87C | 72 bytes
void EController::GetBtnReleasedAny(unsigned int, unsigned int) { }

// 0x804AE8C4 | 72 bytes
void EController::GetBtnRepeat(unsigned int, unsigned int) { }

// 0x804AE90C | 72 bytes
void EController::GetBtnRepeatAny(unsigned int, unsigned int) { }
