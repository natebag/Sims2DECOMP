// loadgametarget_stubs.cpp - Stub implementations for Loadgametarget
// Auto-generated from symbols.json - 35 functions
// These are stub implementations to register progress.
// Each function needs proper decompilation to match the original binary.

#include "types.h"

// 0x8028D678 | 2036 bytes
LoadGameTarget::LoadGameTarget(M2MTarget *, int, int) { }

// 0x8028DE6C | 388 bytes
LoadGameTarget::~LoadGameTarget(void) { }

// 0x8028DFF0 | 868 bytes
void LoadGameTarget::SelectionCallback(int) { }

// 0x8028E354 | 188 bytes
void LoadGameTarget::ZeroInputCallback(void) { }

// 0x8028E410 | 1224 bytes
void LoadGameTarget::Update(void) { }

// 0x8028E8D8 | 8 bytes
void LoadGameTarget::GetResult(void) { }

// 0x8028E8E0 | 4 bytes
void LoadGameTarget::ImportLoad(NghResFile::SectionID, NghResFile::SaveRecord &) { }

// 0x8028E8E4 | 1132 bytes
void LoadGameTarget::PerformMemoryCardChecks(void) { }

// 0x8028ED50 | 364 bytes
void LoadGameTarget::PerformLoad(void) { }

// 0x8028EEBC | 356 bytes
void LoadGameTarget::SpawnCheckingDialog(void) { }

// 0x8028F020 | 628 bytes
void LoadGameTarget::SpawnWrongDeviceDialog(void) { }

// 0x8028F294 | 668 bytes
void LoadGameTarget::SpawnCardDamagedDialog(void) { }

// 0x8028F530 | 620 bytes
void LoadGameTarget::SpawnCardCorruptDialog(void) { }

// 0x8028F79C | 620 bytes
void LoadGameTarget::SpawnWrongSaveDialog(void) { }

// 0x8028FA08 | 428 bytes
void LoadGameTarget::SpawnNoSaveDialog(void) { }

// 0x8028FBB4 | 472 bytes
void LoadGameTarget::SpawnLoadConfirmDialog(void) { }

// 0x8028FD8C | 348 bytes
void LoadGameTarget::SpawnLoadingDialog(void) { }

// 0x8028FEE8 | 300 bytes
void LoadGameTarget::SpawnLoadSucceededDialog(void) { }

// 0x80290014 | 620 bytes
void LoadGameTarget::SpawnLoadFailedDialog(void) { }

// 0x80290280 | 432 bytes
void LoadGameTarget::SpawnMemCardRemovedDialog(void) { }

// 0x80290430 | 300 bytes
void LoadGameTarget::SpawnSameCardDialog(void) { }

// 0x8029055C | 340 bytes
void LoadGameTarget::SpawnFormatDecideDialog(void) { }

// 0x802906B0 | 340 bytes
void LoadGameTarget::SpawnFormatConfirmDialog(void) { }

// 0x80290804 | 224 bytes
void LoadGameTarget::SpawnFormattingDialog(void) { }

// 0x802908E4 | 340 bytes
void LoadGameTarget::SpawnFormatCancelDialog(void) { }

// 0x80290A38 | 532 bytes
void LoadGameTarget::SpawnFormatFailDialog(void) { }

// 0x80290C4C | 292 bytes
void LoadGameTarget::SpawnFormatSuccessDialog(void) { }

// 0x80290D70 | 532 bytes
void LoadGameTarget::BackgroundPerformLoad(void) { }

// 0x80290F84 | 152 bytes
void LoadGameTarget::BGCall_PerformLoad(void) { }

// 0x8029101C | 188 bytes
void LoadGameTarget::BGExec_PerformLoad(void *) { }

// 0x802915E8 | 96 bytes
void LoadGameTarget::ImportSave(NghResFile::SectionID, NghResFile::SaveRecord &) { }

// 0x80291648 | 96 bytes
void LoadGameTarget::ImportSaveComplete(NghResFile::SectionID, NghResFile::SaveRecord &) { }

// 0x802916A8 | 36 bytes
void LoadGameTarget::GetDevice(void) { }

// 0x802916CC | 12 bytes
void LoadGameTarget::GetPlayerNum(void) { }

// 0x802916D8 | 36 bytes
void LoadGameTarget::GetSaveGameID(void) { }
