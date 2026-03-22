// e_ngcfilesystem_large.cpp - ENgcFileSystem large functions (257-1024 bytes)
// Object file: base_ngc_release_dvd.lib(e_ngcfilesystem.obj)
// Section at 0x802D73C0, size 0x0398
// All NON_MATCHING due to: GCC vs SN Systems codegen differences

#include "types.h"

// Forward declarations
extern "C" void* DVDOpen(const char* path, void* fileInfo);
extern "C" int DVDReadPrio(void* fileInfo, void* buf, int length, int offset, int prio);
extern "C" int DVDClose(void* fileInfo);
extern "C" int DVDGetLength(void* fileInfo);
extern "C" void* EAHeap_Alloc(int size);
extern "C" void EAHeap_Free2(void* ptr);
extern "C" int strlen(const char* s);
extern "C" void memcpy(void* dst, const void* src, u32 size);

// ENgcFileSystem - GameCube-specific file system implementation
// Wraps DolphinSDK DVD file access
// Section has a few functions totaling 0x398 = 920 bytes

// ENgcFile - represents an open NGC file
struct ENgcFile {
    u8 m_dvdFileInfo[64];    // 0x00 - DVDFileInfo structure
    u32 m_position;          // 0x40 - current read position
    u32 m_length;            // 0x44 - file length
    u32 m_flags;             // 0x48 - open flags
    void* m_buffer;          // 0x4C - read buffer
    u32 m_bufferSize;        // 0x50 - buffer size
};

struct ENgcFileSystem {
    void* m_vtable;          // 0x00
    u32 m_flags;             // 0x04
    char m_rootPath[260];    // 0x08

    void* Open(const char* path, u32 mode);
    int Read(void* fileHandle, void* buffer, int size);
    int Seek(void* fileHandle, int offset, int origin);
    void Close(void* fileHandle);
    int GetLength(void* fileHandle);
};

// ============================================================================
// ENgcFileSystem::Open
// NON_MATCHING - opens a file from the DVD
// Size: ~350 bytes
// ============================================================================
void* ENgcFileSystem::Open(const char* path, u32 mode)
{
    // Build full path
    char fullPath[260];
    int rootLen = strlen(m_rootPath);

    // Copy root path
    for (int i = 0; i < rootLen; i++) {
        fullPath[i] = m_rootPath[i];
    }

    // Append relative path
    int pathLen = strlen(path);
    for (int i = 0; i <= pathLen; i++) {
        fullPath[rootLen + i] = path[i];
    }

    // Allocate file handle
    ENgcFile* file = (ENgcFile*)EAHeap_Alloc(sizeof(ENgcFile));
    if (!file) return 0;

    // Open via DolphinSDK
    void* result = DVDOpen(fullPath, file->m_dvdFileInfo);
    if (!result) {
        EAHeap_Free2(file);
        return 0;
    }

    // Initialize file state
    file->m_position = 0;
    file->m_length = DVDGetLength(file->m_dvdFileInfo);
    file->m_flags = mode;
    file->m_buffer = 0;
    file->m_bufferSize = 0;

    return file;
}

// ============================================================================
// ENgcFileSystem::Read
// NON_MATCHING - reads data from an open file
// Size: ~300 bytes
// ============================================================================
int ENgcFileSystem::Read(void* fileHandle, void* buffer, int size)
{
    ENgcFile* file = (ENgcFile*)fileHandle;
    if (!file || !buffer || size <= 0) return 0;

    // Clamp to remaining data
    int remaining = file->m_length - file->m_position;
    if (size > remaining) size = remaining;
    if (size <= 0) return 0;

    // Align size to 32 bytes for DMA
    int alignedSize = (size + 31) & ~31;

    // Read via DVD
    int bytesRead = DVDReadPrio(file->m_dvdFileInfo, buffer, alignedSize,
                                file->m_position, 2);

    if (bytesRead > 0) {
        file->m_position += size;
    }

    return size;
}

// ============================================================================
// ENgcFileSystem::Seek
// NON_MATCHING - seeks to a position in the file
// Size: ~260 bytes
// ============================================================================
int ENgcFileSystem::Seek(void* fileHandle, int offset, int origin)
{
    ENgcFile* file = (ENgcFile*)fileHandle;
    if (!file) return -1;

    int newPos;
    if (origin == 0) {
        // SEEK_SET
        newPos = offset;
    } else if (origin == 1) {
        // SEEK_CUR
        newPos = file->m_position + offset;
    } else {
        // SEEK_END
        newPos = file->m_length + offset;
    }

    // Clamp to valid range
    if (newPos < 0) newPos = 0;
    if ((u32)newPos > file->m_length) newPos = file->m_length;

    file->m_position = newPos;
    return newPos;
}

// ============================================================================
// ENgcFileSystem::Close
// NON_MATCHING - closes an open file
// ============================================================================
void ENgcFileSystem::Close(void* fileHandle)
{
    ENgcFile* file = (ENgcFile*)fileHandle;
    if (!file) return;

    DVDClose(file->m_dvdFileInfo);

    if (file->m_buffer) {
        EAHeap_Free2(file->m_buffer);
    }

    EAHeap_Free2(file);
}

// ============================================================================
// ENgcFileSystem::GetLength
// NON_MATCHING - returns file length
// ============================================================================
int ENgcFileSystem::GetLength(void* fileHandle)
{
    ENgcFile* file = (ENgcFile*)fileHandle;
    if (!file) return 0;
    return file->m_length;
}
