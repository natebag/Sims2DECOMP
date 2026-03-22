// e_simsdataman.cpp - ESimsDataManager, EDummyFile
// Part of the Sims 2 GC decompilation
// Original: u2_ngc_release_dvd(e_simsdataman.obj)
//
// Small functions (<=64 bytes) decompiled from the e_simsdataman object file.
// ESimsDataManager manages game data loading/saving.
// EDummyFile is a no-op file implementation.

#include "types.h"
#include "stub_classes.h"

//=============================================================================
// EDummyFile - dummy file that does nothing
//=============================================================================
class EDummyFile {
public:
    // Read - returns 0
    // Address: 0x80022684, Size: 8
    int Read(void*, unsigned int) { return 0; }

    // Write - returns 0
    // Address: 0x8002268C, Size: 8
    int Write(void*, unsigned int) { return 0; }

    // Seek - returns 0
    // Address: 0x80022694, Size: 12
    int Seek(int, int) { return 0; }

    // Tell - returns 0
    // Address: 0x800226A0, Size: 8
    int Tell() const { return 0; }

    // Flush - returns 0
    // Address: 0x800226A8, Size: 8
    int Flush() { return 0; }

    // GetLastError - returns 0
    // Address: 0x800226B0, Size: 8
    int GetLastError() const { return 0; }

    // GetSystemHandle - returns 0
    // Address: 0x800226B8, Size: 8
    void* GetSystemHandle() const { return 0; }

    // Destroy - empty
    // Address: 0x800226C0, Size: 4
    void Destroy() {}
};

//=============================================================================
// ESimsDataManager
//=============================================================================
class ESimsDataManager {
public:
    // ~ESimsDataManager
    // Address: 0x80022F70, Size: 56
    // NON_MATCHING - vtable setup and destructor chain
    ~ESimsDataManager();

    // FlushCommands
    // Address: 0x800235B0, Size: 56
    // NON_MATCHING - command queue processing
    void FlushCommands();
};
