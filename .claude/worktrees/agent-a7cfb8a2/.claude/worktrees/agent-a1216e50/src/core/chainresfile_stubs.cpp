// chainresfile_stubs.cpp - Stub implementations for Chainresfile
// Auto-generated from symbols.json - 32 functions
// These are stub implementations to register progress.
// Each function needs proper decompilation to match the original binary.

#include "types.h"
#include "stub_classes.h"

// 0x801397A0 | 108 bytes
ChainResFile::ChainResFile(void) { }

// 0x8013980C | 152 bytes
ChainResFile::~ChainResFile(void) { }

// 0x80139940 | 208 bytes
void ChainResFile::RemoveFile(iResFile *) { }

// 0x80139A4C | 96 bytes
void ChainResFile::GetFile(short) { }

// 0x80139AAC | 148 bytes
void ChainResFile::Close(void) { }

// 0x80139B40 | 148 bytes
void ChainResFile::CloseForReopen(void) { }

// 0x80139BD4 | 148 bytes
void ChainResFile::Reopen(void) { }

// 0x80139C68 | 212 bytes
void ChainResFile::Update(void) { }

// 0x80139D3C | 148 bytes
void ChainResFile::Writable(void) { }

// 0x80139DD0 | 148 bytes
void ChainResFile::ValidFile(void) { }

// 0x80139F2C | 148 bytes
void ChainResFile::CountTypes(void) { }

// 0x80139FC0 | 620 bytes
void ChainResFile::BuildTypeVector(vector<int, allocator<int> > &) { }

// 0x8013A22C | 236 bytes
void ChainResFile::GetIndType(short) { }

// 0x8013A318 | 192 bytes
void ChainResFile::Count(int) { }

// 0x8013A3D8 | 216 bytes
void ChainResFile::GetByIDAndLanguage(int, short, char, void (*)(void *, int)) { }

// 0x8013A4EC | 208 bytes
void ChainResFile::GetByName(int, StringBuffer &, void (*)(void *, int)) { }

// 0x8013A5BC | 296 bytes
void ChainResFile::GetByIndex(int, short, void (*)(void *, int)) { }

// 0x8013A6E4 | 196 bytes
void ChainResFile::GetName(int *, StringBuffer &) { }

// 0x8013A7A8 | 200 bytes
void ChainResFile::GetResType(int *) { }

// 0x8013A870 | 196 bytes
void ChainResFile::GetID(int *, short *) { }

// 0x8013A934 | 192 bytes
void ChainResFile::IsLittleEndian(int *) { }

// 0x8013AAB8 | 192 bytes
void ChainResFile::FindUniqueName(int, StringBuffer &) { }

// 0x8013AB78 | 100 bytes
void ChainResFile::FindUniqueID(int) { }

// 0x8013ABDC | 188 bytes
void ChainResFile::Detach(int *) { }

// 0x8013ACBC | 196 bytes
void ChainResFile::SetID(int *, short) { }

// 0x8013ADBC | 540 bytes
void ChainResFile::AddWithLanguage(int *, int, short, StringBuffer &, char, bool) { }

// 0x8013AFD8 | 220 bytes
void ChainResFile::Write(int *) { }

// 0x8013B0B4 | 220 bytes
void ChainResFile::Remove(int *) { }

// 0x8013B190 | 244 bytes
void ChainResFile::SetInfo(int *, short, StringBuffer &, char) { }

// 0x8013B284 | 500 bytes
void ChainResFile::AddProhibitedType(iResFile *, unsigned int) { }

// 0x8013B478 | 504 bytes
void ChainResFile::AddExclusiveType(iResFile *, unsigned int) { }

// 0x8013B670 | 276 bytes
void ChainResFile::TypeWritable(unsigned int) { }
