#ifndef CAMERAMANAGER_H
#define CAMERAMANAGER_H

#include "types.h"

// CameraManager - struct layout extracted from assembly analysis
// Estimated minimum size: 0x570 (1392 bytes)
// 4 known fields (0 named), 16 methods

class CameraManager {
public:
    // Constructors / Destructors
    CameraManager(void)  // 0x8004E490
    ~CameraManager(void);  // 0x8004E4C8

    // Methods
    void Initialize(void);  // 0x8004E518 (32B)
    void Shutdown(void);  // 0x8004E538 (32B)
    void Update(void);  // 0x8004E558 (308B)
    /* ? */ GetSingleton(void);  // 0x8004E68C (120B)
    void SetCamera(int, ESimsCam *);  // 0x8004E704 (192B)
    /* ? */ GetCamera(int);  // 0x8004E7C4 (192B)

    // ---- Field Layout (from assembly analysis) ----
    u32 m_field_000;  // 0x000 [R] (Update)
    u32 m_field_004;  // 0x004 [R] (Update)
    u8 _pad_008[0x114];  // 0x008
    u32 m_field_11C;  // 0x11C [R] (Update)
    u8 _pad_120[0x44C];  // 0x120
    u32 m_field_56C;  // 0x56C [R] (Update)
};

#endif // CAMERAMANAGER_H
