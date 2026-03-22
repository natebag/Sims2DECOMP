#if 0 // SKIP
// engcmemorycard_stubs.cpp - Stub implementations for Engcmemorycard
// Auto-generated from symbols.json - 40 functions
// These are stub implementations to register progress.
// Each function needs proper decompilation to match the original binary.

#include "types.h"
#include "stub_classes.h"

// 0x80509AF8 | 32 bytes
ENgcMemoryCard::ENgcMemoryCard(void) { }

// 0x80509B18 | 52 bytes
ENgcMemoryCard::~ENgcMemoryCard(void) { }

// 0x80509B4C | 24 bytes
void ENgcMemoryCard::IsCardOperationInProgress(void) { }

// 0x80509B64 | 16 bytes
void ENgcMemoryCard::BeginCardOperation(void) { }

// 0x80509B74 | 16 bytes
void ENgcMemoryCard::EndCardOperation(void) { }

// 0x80509B84 | 280 bytes
void ENgcMemoryCard::SetComments(wchar_t *, wchar_t *) { }

// 0x80509C9C | 412 bytes
void ENgcMemoryCard::InitMemoryCard(void) { }

// 0x80509E38 | 8 bytes
void ENgcMemoryCard::UnInitMemoryCard(void) { }

// 0x80509E40 | 1496 bytes
void ENgcMemoryCard::LoadDataChunkS(char *, unsigned int, unsigned int, unsigned int, void *) { }

// 0x8050A418 | 1492 bytes
void ENgcMemoryCard::LoadDataS(char *, unsigned int, unsigned int, void *) { }

// 0x8050A9EC | 8 bytes
void ENgcMemoryCard::OpenForIO(char *, unsigned int) { }

// 0x8050A9F4 | 8 bytes
void ENgcMemoryCard::CloseForIO(char *, unsigned int) { }

// 0x8050A9FC | 2184 bytes
void ENgcMemoryCard::SaveDataChunkS(char *, unsigned int, unsigned int, unsigned int, void *) { }

// 0x8050B284 | 2052 bytes
void ENgcMemoryCard::SaveDataS(char *, unsigned int, unsigned int, void *) { }

// 0x8050BA88 | 2216 bytes
void ENgcMemoryCard::CreateFileS(char *, unsigned int, unsigned int) { }

// 0x8050C330 | 1584 bytes
void ENgcMemoryCard::CheckAndWriteBannerAndIcon(char *, unsigned int) { }

// 0x8050C960 | 776 bytes
void ENgcMemoryCard::DeleteDataS(char *, unsigned int) { }

// 0x8050CC68 | 756 bytes
void ENgcMemoryCard::FormatCardS(unsigned int) { }

// 0x8050CF5C | 8 bytes
void ENgcMemoryCard::UnFormatCardS(unsigned int) { }

// 0x8050CF64 | 8 bytes
void ENgcMemoryCard::LoadDataA(char *, unsigned int, unsigned int, void *, EMC_Operation *) { }

// 0x8050CF6C | 8 bytes
void ENgcMemoryCard::SaveDataA(char *, unsigned int, unsigned int, void *, EMC_Operation *) { }

// 0x8050CF74 | 8 bytes
void ENgcMemoryCard::DeleteDataA(char *, unsigned int, unsigned int, EMC_Operation *) { }

// 0x8050CF7C | 8 bytes
void ENgcMemoryCard::FormatCardA(unsigned int, EMC_Operation *) { }

// 0x8050CF84 | 8 bytes
void ENgcMemoryCard::UnFormatCardA(unsigned int, EMC_Operation *) { }

// 0x8050CF8C | 8 bytes
void ENgcMemoryCard::UpdateOperation(EMC_Operation, bool &) { }

// 0x8050CF94 | 1132 bytes
void ENgcMemoryCard::GetFreeSpaceS(unsigned int, unsigned int &) { }

// 0x8050D400 | 1132 bytes
void ENgcMemoryCard::GetFreeFilesS(unsigned int, int &) { }

// 0x8050D86C | 108 bytes
void ENgcMemoryCard::IsSpaceAvailable(unsigned int, unsigned int, bool &) { }

// 0x8050D8D8 | 88 bytes
void ENgcMemoryCard::IsEnoughFiles(unsigned int, unsigned int, bool &) { }

// 0x8050D940 | 16 bytes
void ENgcMemoryCard::CheckForOverwriteSpace(unsigned int, unsigned int, EMC_SaveType, bool &) { }

// 0x8050D950 | 364 bytes
void ENgcMemoryCard::IsCardAvailable(unsigned int) { }

// 0x8050DABC | 352 bytes
void ENgcMemoryCard::IsWrongDevice(unsigned int) { }

// 0x8050DC1C | 160 bytes
void ENgcMemoryCard::AnyCardsPresent(int &) { }

// 0x8050DCBC | 936 bytes
void ENgcMemoryCard::IsCardFormated(unsigned int, bool &) { }

// 0x8050E064 | 1184 bytes
void ENgcMemoryCard::GetFileList(unsigned int, char *, unsigned int, char (*)[31]) { }

// 0x8050E504 | 8 bytes
void ENgcMemoryCard::GetFileListA(unsigned int, char *, unsigned int, char (*)[31], EMC_Operation *) { }

// 0x8050E50C | 4 bytes
void ENgcMemoryCard::SetupSaveTypes(EMC_SaveType, unsigned int) { }

// 0x8050E510 | 4 bytes
void ENgcMemoryCard::SetGameCode(char *) { }

// 0x8050E514 | 1184 bytes
void ENgcMemoryCard::DoesFileExist(char *, unsigned int, bool &) { }

// 0x8050E9B4 | 356 bytes
void ENgcMemoryCard::GetSectorSize(int, unsigned int &) { }
#endif
