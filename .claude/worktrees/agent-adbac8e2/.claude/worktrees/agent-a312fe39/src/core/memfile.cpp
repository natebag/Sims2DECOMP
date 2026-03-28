// memfile.cpp - Memory-backed file small functions
// From: memfile.obj
// Small functions (<=64 bytes) decompiled from this object

#include "core/memfile.h"
#include "core/stringbuffer.h"

// ============================================================================
// MemFile::ValidFile(void)
// 0x800A62F0 - 24 bytes
// Returns 1 if m_filePtr is non-null, 0 otherwise
// ============================================================================
// lwz r0,0x114(r3); li r3,1; cmpwi r0,0; bnelr-; li r3,0; blr
// NON_MATCHING - GCC uses branchless addic/subfe; original uses conditional branch
BOOL MemFile::ValidFile(void) {
    if (m_filePtr != 0) {
        return TRUE;
    }
    return FALSE;
}

// ============================================================================
// MemFile::SetFileName(StringBuffer &)
// 0x800A6474 - 64 bytes
// Erases current name, then appends from source
// ============================================================================
// stwu r1,-24(r1); mflr r0; stmw r29,12(r1); stw r0,28(r1)
// mr r30,r3; mr r29,r4; bl StringBuffer::erase
// mr r3,r30; mr r4,r29; li r5,-1
// bl StringBuffer::append(StringBuffer &, int)
// lwz r0,28(r1); mtlr r0; lmw r29,12(r1); addi r1,r1,24; blr
void MemFile::SetFileName(StringBuffer& name) {
    // 'this' treated as containing a StringBuffer at some offset
    // Calls erase() on self, then append(name, -1)
    // This is a member-to-member copy pattern
    // NON_MATCHING - need exact offset of embedded StringBuffer
    StringBuffer* self_name = (StringBuffer*)this;  // offset TBD
    self_name->erase();
    self_name->append(name, -1);
}

// ============================================================================
// MemFile::Read1(signed char *)
// 0x800A64B4 - 44 bytes
// Reads 1 byte by calling ReadBlock with size=1
// ============================================================================
// stwu r1,-16(r1); mflr r0; stw r0,20(r1)
// li r0,1; addi r5,r1,8; stw r0,8(r1)
// bl MemFile::ReadBlock
// lwz r0,20(r1); mtlr r0; addi r1,r1,16; blr
// NON_MATCHING - GCC uses different frame size (24 vs 16) and register allocation
void MemFile::Read1(signed char* out) {
    int size = 1;
    ReadBlock(out, &size);
}

// ============================================================================
// MemFile::Writable(void)
// 0x800A64E0 - 8 bytes
// Returns m_writable field at offset +0x10C
// ============================================================================
// lwz r3,0x10c(r3); blr
BOOL MemFile::Writable(void) {
    return m_writable;
}
