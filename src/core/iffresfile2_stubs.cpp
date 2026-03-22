// iffresfile2_stubs.cpp - Stub implementations for Iffresfile2
// Auto-generated from symbols.json - 38 functions
// These are stub implementations to register progress.
// Each function needs proper decompilation to match the original binary.

#include "types.h"

// 0x8014E150 | 112 bytes
IFFResFile2::IFFResFile2(void) { }

// 0x8014E1C0 | 112 bytes
IFFResFile2::~IFFResFile2(void) { }

// 0x8014E230 | 1036 bytes
void IFFResFile2::Open(StringBuffer &) { }

// 0x8014E63C | 240 bytes
void IFFResFile2::Create(StringBuffer &) { }

// 0x8014E72C | 216 bytes
void IFFResFile2::ClearMap(StringBuffer &) { }

// 0x8014E804 | 340 bytes
void IFFResFile2::WriteHeader(MemFile *, int) { }

// 0x8014E958 | 96 bytes
void IFFResFile2::Delete(StringBuffer &) { }

// 0x8014E9B8 | 712 bytes
void IFFResFile2::Close(void) { }

// 0x8014EC80 | 104 bytes
void IFFResFile2::CloseForReopen(void) { }

// 0x8014ECE8 | 152 bytes
void IFFResFile2::Reopen(void) { }

// 0x8014ED80 | 308 bytes
void IFFResFile2::Update(void) { }

// 0x8014EF04 | 136 bytes
void IFFResFile2::CountTypes(void) { }

// 0x8014EF8C | 160 bytes
void IFFResFile2::GetIndType(short) { }

// 0x8014F02C | 144 bytes
void IFFResFile2::Count(int) { }

// 0x8014F0BC | 272 bytes
void IFFResFile2::GetByIDAndLanguage(int, short, char, void (*)(void *, int)) { }

// 0x8014F208 | 272 bytes
void IFFResFile2::GetByName(int, StringBuffer &, void (*)(void *, int)) { }

// 0x8014F318 | 264 bytes
void IFFResFile2::GetByIndex(int, short, void (*)(void *, int)) { }

// 0x8014F420 | 188 bytes
void IFFResFile2::GetName(Memory::HandleNode *, StringBuffer &) { }

// 0x8014F590 | 176 bytes
void IFFResFile2::GetResType(Memory::HandleNode *) { }

// 0x8014F640 | 176 bytes
void IFFResFile2::GetID(Memory::HandleNode *, short *) { }

// 0x8014F778 | 272 bytes
void IFFResFile2::FindUniqueName(int, StringBuffer &) { }

// 0x8014F888 | 152 bytes
void IFFResFile2::FindUniqueID(int) { }

// 0x8014F920 | 228 bytes
void IFFResFile2::Detach(Memory::HandleNode *) { }

// 0x8014FA04 | 128 bytes
void IFFResFile2::Load(Memory::HandleNode *) { }

// 0x8014FA84 | 192 bytes
void IFFResFile2::IsLittleEndian(Memory::HandleNode *) { }

// 0x8014FB44 | 180 bytes
void IFFResFile2::SetID(Memory::HandleNode *, short) { }

// 0x8014FBF8 | 416 bytes
void IFFResFile2::AddWithLanguage(Memory::HandleNode *, int, short, StringBuffer &, char, bool) { }

// 0x8014FDD4 | 736 bytes
void IFFResFile2::Write(Memory::HandleNode *) { }

// 0x801500B4 | 268 bytes
void IFFResFile2::Remove(Memory::HandleNode *) { }

// 0x801501C0 | 440 bytes
void IFFResFile2::SetInfo(Memory::HandleNode *, short, StringBuffer &, char) { }

// 0x80150378 | 480 bytes
void IFFResFile2::LoadNode(IFFResNode *, void (*)(void *, int), int) { }

// 0x80150558 | 124 bytes
void IFFResFile2::LowLevelRemove(IFFResNode *) { }

// 0x801505D4 | 124 bytes
void IFFResFile2::InvalBlockHeader(int) { }

// 0x80150650 | 672 bytes
void IFFResFile2::NewBlockHeader(IFFHeader *, unsigned int, int *) { }

// 0x801508F0 | 100 bytes
void IFFResFile2::GetBlockHeader(IFFHeader *, int) { }

// 0x80150954 | 136 bytes
void IFFResFile2::SetBlockHeader(IFFHeader *, int) { }

// 0x801509DC | 220 bytes
void IFFResFile2::MoveBlock(unsigned int, unsigned int, unsigned int, unsigned char *) { }

// 0x80150AB8 | 256 bytes
void IFFResFile2::Defrag(void) { }
