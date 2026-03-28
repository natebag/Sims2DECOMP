#ifndef CTGFILE_H
#define CTGFILE_H

#include "types.h"

// Forward declarations
class StringBuffer;

// CTGFile - Base file interface with vtable
// From: ctgfile_ngc.obj
// Layout:
//   0x00: void* vtable
class CTGFile {
public:
    CTGFile(void);
    virtual ~CTGFile(void);
};

// CTGFileImpl - NGC file implementation wrapping C file I/O
// From: ctgfile_ngc.obj
// Inherits from CTGFile (has vtable at 0x00)
// Layout:
//   0x00: void* vtable (inherited)
//   0x04: StringBuffer m_name (8 bytes: ptr + capacity)
//   ...
//   0x110: void* m_fileHandle (FILE*)
class CTGFileImpl : public CTGFile {
public:
    // File operations
    int IsWritable(void);
    int Read(void* buffer, int size);
    int Write(void* buffer, int size);
    int Seek(int offset);
    int SeekPastEnd(int offset);
    int Tell(void);
    int SetSize(int size);
    int Flush(void);
    int FlushCache(void);

    // Typed read/write via vtable dispatch
    int ReadByte(unsigned char* out);
    int WriteByte(unsigned char val);
    int ReadInteger(int* out);
    int WriteInteger(int val);
    int ReadFloat(float* out);
    int WriteFloat(float val);

    // Get filename
    const char* GetName(void);

private:
    // StringBuffer at offset 0x04 (used for name)
    char _pad[0x10C];      // padding to 0x110
    void* m_fileHandle;     // offset 0x110 - FILE*
};

// CTGFileManager - File manager singleton
// From: ctgfile_ngc.obj
// All operations are stubs on NGC (return success or no-op)
class CTGFileManager {
public:
    CTGFileManager(void);
    ~CTGFileManager(void);

    int Init(void);
    void Shutdown(void);

    // File operations (all stubbed on NGC)
    void ReleaseFile(CTGFile* file);
    int CreateFile(char* path);
    int DeleteFile(char* path);
    int MoveFile(char* src, char* dst);
    int CopyFile(char* src, char* dst);
};

#endif // CTGFILE_H
