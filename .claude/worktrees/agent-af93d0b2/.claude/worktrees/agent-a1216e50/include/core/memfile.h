#ifndef MEMFILE_H
#define MEMFILE_H

#include "types.h"

// Forward declarations
class StringBuffer;

// ============================================================================
// MemFile - Memory-backed file I/O
// From: memfile.obj
// Layout: ~280 bytes
//   +0x000: base file fields
//   +0x10C: m_writable (u32)
//   +0x114: m_filePtr (void*)
// ============================================================================
class MemFile {
public:
    MemFile(void);
    ~MemFile(void);

    BOOL ValidFile(void);        // returns m_filePtr != NULL
    BOOL Writable(void);         // returns m_writable

    void Open(StringBuffer& name);
    void Close(void);
    void Flush(void);

    void Create(StringBuffer& name);
    void Delete(StringBuffer& name);

    void ReadBlock(void* buffer, int* size);
    void Read1(signed char* out);
    void WriteBlock(void* buffer, int* size);

    void SetPos(int pos);
    void GetFileSize(int* size);
    void SetFileSize(int size);

    void GetFileName(StringBuffer& name);
    void SetFileName(StringBuffer& name);

private:
    u8 m_data[0x10C];      // 0x00
    u32 m_writable;         // 0x10C
    u8 m_pad110[0x08];      // 0x110
    void* m_filePtr;        // 0x114
};

#endif // MEMFILE_H
