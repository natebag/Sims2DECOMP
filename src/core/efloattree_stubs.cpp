// efloattree_stubs.cpp - Stub implementations for Efloattree
// Auto-generated from symbols.json - 17 functions
// These are stub implementations to register progress.
// Each function needs proper decompilation to match the original binary.

#include "types.h"
#include "stub_classes.h"

// 0x8045F028 | 32 bytes
EFloatTree::EFloatTree(void) { }

// 0x8045F094 | 124 bytes
void EFloatTree::RotateLeft(EFloatTreeNode *) { }

// 0x8045F110 | 124 bytes
void EFloatTree::RotateRight(EFloatTreeNode *) { }

// 0x8045F18C | 328 bytes
void EFloatTree::InsertFixup(EFloatTreeNode *) { }

// 0x8045F2D4 | 40 bytes
void* EFloatTree::operator[](float) const { }

// 0x8045F364 | 68 bytes
void EFloatTree::FindKeyOrParent(float) const { }

// 0x8045F3A8 | 64 bytes
void EFloatTree::FindParent(float) const { }

// 0x8045F3E8 | 108 bytes
void EFloatTree::SetValue(float, unsigned int) { }

// 0x8045F454 | 136 bytes
void EFloatTree::Insert(float, unsigned int, bool) { }

// 0x8045F4DC | 344 bytes
void EFloatTree::InsertAt(EFloatTreeNode *, float, unsigned int) { }

// 0x8045F634 | 476 bytes
void EFloatTree::RemoveFixup(EFloatTreeNode *) { }

// 0x8045F810 | 72 bytes
void EFloatTree::Remove(float) { }

// 0x8045FA38 | 84 bytes
void EFloatTree::Find(float, unsigned int *) const { }

// 0x8045FA8C | 96 bytes
void EFloatTree::RemoveAll(void) { }

// 0x8045FAEC | 40 bytes
void EFloatTree::GetSize(void) const { }

// 0x8045FB14 | 136 bytes
void EFloatTree::SetValues(EFloatTree &, bool) { }

// 0x8045FB9C | 68 bytes
void EFloatTree::operator=(EFloatTree &) { }
