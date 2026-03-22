// uiaudio_stubs.cpp - Stub implementations for Uiaudio
// Auto-generated from symbols.json - 16 functions
// These are stub implementations to register progress.
// Each function needs proper decompilation to match the original binary.

#include "types.h"

// 0x8026E208 | 280 bytes
UIAUDIO::UIAUDIO(void) { }

// 0x8026E320 | 268 bytes
UIAUDIO::~UIAUDIO(void) { }

// 0x8026E42C | 104 bytes
void UIAUDIO::AddEntry(char *, unsigned int, char *) { }

// 0x8026E494 | 152 bytes
void UIAUDIO::RemoveEntry(UIAUDIO::UIAUDIORecord *) { }

// 0x8026E52C | 232 bytes
void UIAUDIO::InstallEntry(char *, unsigned int, char *) { }

// 0x8026E614 | 188 bytes
void UIAUDIO::UnInstallEntry(char *) { }

// 0x8026E6D0 | 96 bytes
void UIAUDIO::UnInstallAllEntries(char *) { }

// 0x8026E730 | 96 bytes
void UIAUDIO::ContainsEntry(char *) { }

// 0x8026E790 | 208 bytes
void UIAUDIO::GetSound(char *) { }

// 0x8026E860 | 344 bytes
void UIAUDIO::PlaySound(unsigned int) { }

// 0x8026E9B8 | 68 bytes
void UIAUDIO::Update(void) { }

// 0x8026E9FC | 456 bytes
void UIAUDIO::UpdateAudioLoad(int) { }

// 0x8026EBC4 | 148 bytes
void UIAUDIO::StopSound(int) { }

// 0x8026EC58 | 52 bytes
UIAUDIO::UIAUDIORecord::~UIAUDIORecord(void) { }

// 0x8026EC8C | 60 bytes
void UIAUDIO::Instance(void) { }

// 0x8026ECC8 | 76 bytes
void UIAUDIO::Shutdown(void) { }
