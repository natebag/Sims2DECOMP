// iffresmap_stubs.cpp - Stub implementations for Iffresmap
// Auto-generated from symbols.json - 16 functions
// These are stub implementations to register progress.
// Each function needs proper decompilation to match the original binary.

#include "types.h"

// 0x8014D14C | 200 bytes
void IFFResMap::UpdateOffset(int, int) { }

// 0x8014D214 | 732 bytes
void IFFResMap::GetResList(unsigned int, bool) { }

// 0x8014D4F0 | 792 bytes
void IFFResMap::MakeNewNode(unsigned int) { }

// 0x8014D808 | 160 bytes
void IFFResMap::GetNode(unsigned int, int, void (*)(void *, int)) { }

// 0x8014D8A8 | 232 bytes
void IFFResMap::GetNodeWithLanguage(unsigned int, int, char, void (*)(void *, int)) { }

// 0x8014DAB0 | 144 bytes
void IFFResMap::GetIndNode(unsigned int, int, void (*)(void *, int)) { }

// 0x8014DB40 | 512 bytes
void IFFResMap::RemoveNode(IFFResNode *) { }

// 0x8014DD60 | 68 bytes
void IFFResMap::GetIndexedType(int) { }

// 0x8014DDA4 | 96 bytes
void IFFResMap::CountNodes(unsigned int) { }

// 0x8014DE04 | 156 bytes
void IFFResMap::FreeAllHandles(void) { }

// 0x8014DEA0 | 168 bytes
void IFFResMap::RemoveAllNodes(void) { }

// 0x8014DF48 | 248 bytes
void IFFResMap::RemoveAllNodesOfType(unsigned int) { }

// 0x8014E040 | 72 bytes
void IFFResMap::GetLastSwizzleProc(unsigned int) { }

// 0x8014E088 | 116 bytes
void IFFResMap::GetHighestID(unsigned int, short) { }

// 0x8014E0FC | 84 bytes
void IFFResMap::DoStream(ReconBuffer *, int) { }

// 0x80152B0C | 240 bytes
IFFResMap::~IFFResMap(void) { }
