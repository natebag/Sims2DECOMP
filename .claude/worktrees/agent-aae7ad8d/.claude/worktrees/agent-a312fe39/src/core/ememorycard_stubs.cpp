// ememorycard_stubs.cpp - Stub implementations for Ememorycard
// Auto-generated from symbols.json - 11 functions
// These are stub implementations to register progress.
// Each function needs proper decompilation to match the original binary.

#include "types.h"
#include "stub_classes.h"

// 0x8050ED2C | 52 bytes
EMemoryCard::~EMemoryCard(void) { }

// 0x8050ED60 | 8 bytes
void EMemoryCard::OpenForIO(char *, unsigned int) { }

// 0x8050ED68 | 8 bytes
void EMemoryCard::CloseForIO(char *, unsigned int) { }

// 0x8050ED70 | 8 bytes
void EMemoryCard::GetFileRefCount(char *, unsigned int) { }

// 0x8050ED78 | 8 bytes
void EMemoryCard::LoadDataChunkS(char *, unsigned int, unsigned int, unsigned int, void *) { }

// 0x8050ED80 | 8 bytes
void EMemoryCard::SaveDataChunkS(char *, unsigned int, unsigned int, unsigned int, void *) { }

// 0x8050ED88 | 8 bytes
void EMemoryCard::CreateFileS(char *, unsigned int, unsigned int) { }

// 0x8050ED90 | 4 bytes
void EMemoryCard::SetMemCardCopyProtection(unsigned int) { }

// 0x8050ED94 | 8 bytes
void EMemoryCard::PollCards(bool) { }

// 0x8050ED9C | 8 bytes
void EMemoryCard::IsPolledCardAvailable(unsigned int) { }

// 0x8050EDA4 | 8 bytes
void EMemoryCard::IsWrongDevice(unsigned int) { }
