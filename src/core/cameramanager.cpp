// cameramanager.cpp - CameraManager
// Part of the Sims 2 GC decompilation
// Original: u2_ngc_release_dvd(cameramanager.obj)
//
// Small functions (<=64 bytes) decompiled from the cameramanager object file.

#include "types.h"
#include "stub_classes.h"

// External functions
extern void EStorable_Delete(void* ptr);

//=============================================================================
// CameraManager
//=============================================================================
class CameraManager {
public:
    void* m_first;  // 0x00
    void* m_second; // 0x04

    // CameraManager constructor
    // Address: 0x8001EB3C, Size: 20
    CameraManager() {
        m_second = NULL;
        m_first = NULL;
    }

    // ~CameraManager
    // Address: 0x8001EB50, Size: 36
    // NON_MATCHING - conditional delete
    ~CameraManager();
};
