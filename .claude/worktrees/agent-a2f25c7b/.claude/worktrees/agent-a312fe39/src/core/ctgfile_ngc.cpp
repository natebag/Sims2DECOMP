// ctgfile_ngc.cpp - CTGFile / CTGFileImpl / CTGFileManager small functions
// From: ctgfile_ngc.obj
// Small functions (<=64 bytes) decompiled from this object

#include "core/ctgfile.h"
#include "core/stringbuffer.h"

// ============================================================================
// External references
// ============================================================================

// __builtin_delete - SN Systems runtime delete operator
extern "C" void __builtin_delete(void* ptr);

// C file I/O wrappers
extern "C" int efread(void* buffer, int count, int size, void* file);
extern "C" int efseek(void* file, int offset, int whence);
extern "C" int eftell(void* file);

// __static_initialization_and_destruction_0 for this TU
extern "C" void __static_initialization_and_destruction_0_ctgfile(int init, int priority);

// Vtable for CTGFile
extern "C" void* CTGFile_vtable[];   // at 0x8045ce60

// ============================================================================
// CTGFile::CTGFile(void)
// 0x8007d590 - 20 bytes
// Sets vtable pointer
// ============================================================================
CTGFile::CTGFile(void) {
    // Compiler sets vtable: *(void**)this = CTGFile_vtable;
}

// ============================================================================
// CTGFile::~CTGFile(void)
// 0x8007cd9c - 52 bytes
// Virtual destructor: sets vtable, conditionally deletes
// ============================================================================
// NON_MATCHING - GCC generates the scalar deleting destructor pattern
// automatically. The vtable reset and __in_charge check are compiler-generated.
CTGFile::~CTGFile(void) {
    // GCC auto-generates:
    //   *(void**)this = CTGFile_vtable;
    //   if (__in_charge & 1) __builtin_delete(this);
}

// ============================================================================
// CTGFileImpl::IsWritable(void)
// 0x8007cee8 - 8 bytes
// Always returns 0 (not writable on NGC)
// ============================================================================
int CTGFileImpl::IsWritable(void) {
    return 0;
}

// ============================================================================
// CTGFileImpl::Read(void *, int)
// 0x8007cef0 - 56 bytes
// Reads from file if handle is valid, returns bytes read
// ============================================================================
// NON_MATCHING - GCC reorders instructions vs SN Systems compiler.
// Original: sets r3=0 default before null check, then rearranges args for efread.
// GCC moves the mr r3,r4 before the branch and uses tail call optimization.
int CTGFileImpl::Read(void* buffer, int size) {
    if (m_fileHandle == 0) {
        return 0;
    }
    return efread(buffer, 1, size, m_fileHandle);
}

// ============================================================================
// CTGFileImpl::Write(void *, int)
// 0x8007cf28 - 8 bytes
// Always returns 0 (not writable on NGC)
// ============================================================================
int CTGFileImpl::Write(void* buffer, int size) {
    return 0;
}

// ============================================================================
// CTGFileImpl::Seek(int)
// 0x8007cf30 - 44 bytes
// Seeks to absolute position in file, returns 1
// ============================================================================
// NON_MATCHING - Instruction scheduling differs between SN Systems and GCC.
// Original: stw r0 before lwz r3; GCC schedules stw later.
int CTGFileImpl::Seek(int offset) {
    efseek(m_fileHandle, offset, 0);  // SEEK_SET = 0
    return 1;
}

// ============================================================================
// CTGFileImpl::SeekPastEnd(int)
// 0x8007cf5c - 44 bytes
// Seeks to position relative to... (same call as Seek but returns 0)
// Note: original uses same efseek with whence=0, but returns 0 instead of 1
// ============================================================================
// NON_MATCHING - Same instruction scheduling issue as Seek.
int CTGFileImpl::SeekPastEnd(int offset) {
    efseek(m_fileHandle, offset, 0);
    return 0;
}

// ============================================================================
// CTGFileImpl::Tell(void)
// 0x8007cf88 - 52 bytes
// Returns current file position, or 0 if no handle
// ============================================================================
// NON_MATCHING - GCC optimizes to tail call and removes stack frame.
// Original keeps stack frame, uses r0 for fileHandle, sets r3=0 default.
int CTGFileImpl::Tell(void) {
    if (m_fileHandle == 0) {
        return 0;
    }
    return eftell(m_fileHandle);
}

// ============================================================================
// CTGFileImpl::SetSize(int)
// 0x8007cfbc - 8 bytes
// Stubbed - always returns 0
// ============================================================================
int CTGFileImpl::SetSize(int size) {
    return 0;
}

// ============================================================================
// CTGFileImpl::Flush(void)
// 0x8007cfc4 - 8 bytes
// Stubbed - always returns 0
// ============================================================================
int CTGFileImpl::Flush(void) {
    return 0;
}

// ============================================================================
// CTGFileImpl::FlushCache(void)
// 0x8007cfcc - 8 bytes
// Returns 1 (success, cache is always "flushed" on NGC)
// ============================================================================
int CTGFileImpl::FlushCache(void) {
    return 1;
}

// ============================================================================
// CTGFileImpl::ReadByte(unsigned char *)
// 0x8007d064 - 56 bytes
// Reads 1 byte via vtable dispatch (read virtual function)
// ============================================================================
// NON_MATCHING - Uses vtable dispatch through this->vtable[offset].
// The original loads the vtable, gets the read function pointer at offset 72/76,
// adjusts 'this' by the vtable's "this" offset, and calls through function pointer.
// This pattern can't be directly expressed in C++ without matching vtable layout.
int CTGFileImpl::ReadByte(unsigned char* out) {
    return Read(out, 1);
}

// ============================================================================
// CTGFileImpl::WriteByte(unsigned char)
// 0x8007d09c - 64 bytes
// Writes 1 byte via vtable dispatch (write virtual function)
// ============================================================================
// NON_MATCHING - Same vtable dispatch pattern as ReadByte but for write.
// Stores byte to stack, then dispatches through vtable write entry at offset 80/84.
int CTGFileImpl::WriteByte(unsigned char val) {
    return Write(&val, 1);
}

// ============================================================================
// CTGFileImpl::ReadInteger(int *)
// 0x8007d0dc - 56 bytes
// Reads 4 bytes (int) via vtable dispatch
// ============================================================================
// NON_MATCHING - Same vtable dispatch pattern as ReadByte with size=4
int CTGFileImpl::ReadInteger(int* out) {
    return Read(out, 4);
}

// ============================================================================
// CTGFileImpl::WriteInteger(int)
// 0x8007d114 - 64 bytes
// Writes 4 bytes (int) via vtable dispatch
// ============================================================================
// NON_MATCHING - Same vtable dispatch pattern, stores int to stack then writes
int CTGFileImpl::WriteInteger(int val) {
    return Write(&val, 4);
}

// ============================================================================
// CTGFileImpl::ReadFloat(float *)
// 0x8007d154 - 56 bytes
// Reads 4 bytes (float) via vtable dispatch
// ============================================================================
// NON_MATCHING - Same vtable dispatch pattern as ReadInteger
int CTGFileImpl::ReadFloat(float* out) {
    return Read(out, 4);
}

// ============================================================================
// CTGFileImpl::WriteFloat(float)
// 0x8007d18c - 64 bytes
// Writes 4 bytes (float) via vtable dispatch
// ============================================================================
// NON_MATCHING - Same vtable dispatch pattern, stores float to stack then writes
int CTGFileImpl::WriteFloat(float val) {
    return Write(&val, 4);
}

// ============================================================================
// CTGFileImpl::GetName(void)
// 0x8007d5a4 - 36 bytes
// Returns the filename as C string from the embedded StringBuffer at offset 0x04
// Calls StringBuffer::c_str() on the StringBuffer member
// ============================================================================
// NON_MATCHING - The original does: addi r3, r3, 4; bl StringBuffer::c_str
// This adjusts 'this' to point to the StringBuffer member, then calls c_str.
// Our layout may not match the exact offset.
const char* CTGFileImpl::GetName(void) {
    // Original: return ((StringBuffer*)(((char*)this) + 4))->c_str();
    // The StringBuffer member is at offset 0x04 in CTGFileImpl
    StringBuffer* nameBuf = (StringBuffer*)(((char*)this) + 4);
    return nameBuf->c_str();
}

// ============================================================================
// CTGFileManager::CTGFileManager(void)
// 0x8007d350 - 4 bytes
// Empty constructor
// ============================================================================
CTGFileManager::CTGFileManager(void) {
    // empty
}

// ============================================================================
// CTGFileManager::~CTGFileManager(void)
// 0x8007d354 - 40 bytes
// Destructor: conditionally deletes
// ============================================================================
// NON_MATCHING - GCC scalar deleting destructor pattern
CTGFileManager::~CTGFileManager(void) {
    // GCC auto-generates: if (__in_charge & 1) __builtin_delete(this);
}

// ============================================================================
// CTGFileManager::Init(void)
// 0x8007d37c - 8 bytes
// Returns 1 (success)
// ============================================================================
int CTGFileManager::Init(void) {
    return 1;
}

// ============================================================================
// CTGFileManager::Shutdown(void)
// 0x8007d384 - 4 bytes
// No-op
// ============================================================================
void CTGFileManager::Shutdown(void) {
    // empty
}

// ============================================================================
// CTGFileManager::ReleaseFile(CTGFile *)
// 0x8007d484 - 64 bytes
// Releases a file by calling its virtual destructor with delete flag (3)
// ============================================================================
// NON_MATCHING - Uses vtable dispatch to call the destructor.
// Loads vtable from file->vtable[0], gets dtor at offset 8/12,
// adjusts 'this', calls dtor with flag=3 (in-charge + delete).
void CTGFileManager::ReleaseFile(CTGFile* file) {
    if (file != 0) {
        delete file;
    }
}

// ============================================================================
// CTGFileManager::CreateFile(char *)
// 0x8007d4c4 - 8 bytes
// Stubbed - always returns 1 (success)
// ============================================================================
int CTGFileManager::CreateFile(char* path) {
    return 1;
}

// ============================================================================
// CTGFileManager::DeleteFile(char *)
// 0x8007d4cc - 8 bytes
// Stubbed - always returns 1 (success)
// ============================================================================
int CTGFileManager::DeleteFile(char* path) {
    return 1;
}

// ============================================================================
// CTGFileManager::MoveFile(char *, char *)
// 0x8007d4d4 - 8 bytes
// Stubbed - always returns 1 (success)
// ============================================================================
int CTGFileManager::MoveFile(char* src, char* dst) {
    return 1;
}

// ============================================================================
// CTGFileManager::CopyFile(char *, char *)
// 0x8007d4dc - 8 bytes
// Stubbed - always returns 1 (success)
// ============================================================================
int CTGFileManager::CopyFile(char* src, char* dst) {
    return 1;
}
