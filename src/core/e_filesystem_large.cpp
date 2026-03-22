#if 0 // SKIP
// e_filesystem_large.cpp - EFileSystem large functions (257-1024 bytes)
// Object file: base_ngc_release_dvd.lib(e_filesystem.obj)
// All NON_MATCHING due to: GCC vs SN Systems codegen differences

#include "types.h"
#include "stub_classes.h"

// Forward declarations
struct EFile {
    enum DeviceType { DEVICE_DEFAULT = 0, DEVICE_DVD = 1, DEVICE_MEMCARD = 2 };
    enum AccessMode { ACCESS_READ = 0, ACCESS_WRITE = 1, ACCESS_READWRITE = 2 };
};

// EFileSystem::FileCreator callback function pointer type
typedef void* (*FileCreatorFn)(void* ctx, char* fullPath, char* relPath,
    EFile::DeviceType device, EFile::AccessMode mode, unsigned int flags);

// EFileSystem path helper functions
extern "C" void EFileSystem_InitPath(void* path, void* buffer, int bufSize);
extern "C" void EFileSystem_SetPath(void* path, char* str);
extern "C" void EFileSystem_CombinePaths(void* pathOut, void* pathIn);
extern "C" void* EFileSystem_FindCreator(void* self, char* path, void* outPath);
extern "C" void EFileSystem_AddFile(void* self, void* fileRef);

struct EFileSystem {
    void* m_vtable;          // 0x00
    u8 pad04[0x0C];          // 0x04
    void* m_defaultDevice;   // 0x10
    u32 m_numCreators;       // 0x14

    bool Access(char* path, char* relPath, EFile::DeviceType device, EFile::AccessMode mode);
    bool Create(EFile*& outFile, char* path, char* relPath,
                EFile::DeviceType device, EFile::AccessMode mode, unsigned int flags);
};

// ============================================================================
// EFileSystem::Access(char*, char*, EFile::DeviceType, EFile::AccessMode)
// Address: 0x802C6D44
// Size: 356 bytes
// NON_MATCHING - checks if a file can be accessed
// ============================================================================
bool EFileSystem::Access(char* path, char* relPath, EFile::DeviceType device, EFile::AccessMode mode)
{
    u8* self = (u8*)this;
    void* defaultDev = m_defaultDevice;

    // Build full path
    u8 pathBuf[0x310];
    u8 pathObj[0x110];
    u8 fullPathObj[0x110];

    // Init path objects
    EFileSystem_InitPath(pathObj, (u8*)pathObj + 8, 260);

    // Combine relative path
    EFileSystem_SetPath(pathObj, relPath);

    // Get full path by resolving against mount points
    u8 resolvedPath[0x110];
    EFileSystem_InitPath(resolvedPath, (u8*)resolvedPath + 8, 260);
    EFileSystem_CombinePaths(pathObj, resolvedPath);

    // Find file creator for this path
    u8 combinedPath[0x110];
    EFileSystem_InitPath(combinedPath, (u8*)combinedPath + 8, 260);
    EFileSystem_SetPath(combinedPath, (char*)resolvedPath);

    // Look up the file creator callback
    void* creator = EFileSystem_FindCreator(self, (char*)defaultDev, (u8*)pathBuf + 0x00);

    bool result = false;
    *(u32*)(pathBuf + 0x304) = 0; // output file handle

    if (creator) {
        // Call creator with access-check mode
        FileCreatorFn fn = (FileCreatorFn)creator;
        void* file = fn(0, relPath, path, defaultDev != 0 ? EFile::DEVICE_DVD : device,
                       EFile::ACCESS_READ, 0);

        result = true;
        if (file == 0) {
            result = false;
        } else {
            // File exists, add reference
            EFileSystem_AddFile(self, (u8*)pathBuf + 0x304);
        }
    }

    return result;
}

// ============================================================================
// EFileSystem::Create(EFile*&, char*, char*, EFile::DeviceType, EFile::AccessMode, unsigned int)
// Address: 0x802C6EA8
// Size: 344 bytes
// NON_MATCHING - creates/opens a file
// ============================================================================
bool EFileSystem::Create(EFile*& outFile, char* path, char* relPath,
                         EFile::DeviceType device, EFile::AccessMode mode, unsigned int flags)
{
    u8* self = (u8*)this;

    // Check if file system is initialized
    u32 initFlag = *(u32*)(self + 0x14);
    if (initFlag == 0) {
        // Call virtual init
        void** vtable = *(void***)self;
        // NON_MATCHING: vtable dispatch for init
    }

    // Resolve path
    u8 pathBuf[0x310];
    bool found = false;

    // Check if device is default
    if (device == (int)0x80000000) {
        device = (EFile::DeviceType)(u32)m_defaultDevice;
    }

    // Build full path
    u8 pathObj[0x110];
    EFileSystem_InitPath(pathObj, (u8*)pathObj + 8, 260);
    EFileSystem_SetPath(pathObj, relPath);

    u8 resolvedPath[0x110];
    EFileSystem_InitPath(resolvedPath, (u8*)resolvedPath + 8, 260);
    EFileSystem_CombinePaths(pathObj, resolvedPath);

    u8 combinedPath[0x110];
    EFileSystem_InitPath(combinedPath, (u8*)combinedPath + 8, 260);
    EFileSystem_SetPath(combinedPath, (char*)resolvedPath);

    // Find creator
    void* creator = EFileSystem_FindCreator(self, (char*)m_defaultDevice, (u8*)pathBuf + 0x00);

    outFile = 0;

    if (creator) {
        FileCreatorFn fn = (FileCreatorFn)creator;
        void* file = fn(0, relPath, path, device, mode, flags);
        outFile = (EFile*)file;
        found = (file != 0);
    }

    return found;
}

// ============================================================================
// TArray<EFileSystem::FileCreator, TArrayDefaultAllocator>::SetSize(int, int)
// Address: 0x803C19EC
// Size: 300 bytes
// NON_MATCHING - template array resize for FileCreator
// ============================================================================
// Standard TArray::SetSize implementation - resizes internal buffer
// See ea_containers.cpp for the general pattern
#endif
