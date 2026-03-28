#ifndef ENCAMERA_H
#define ENCAMERA_H

#include "types.h"

// ENCamera - struct layout extracted from assembly analysis
// Estimated minimum size: 0x60 (96 bytes)
// 9 known fields (7 named), 27 methods

class ENCamera {
public:
    // Constructors / Destructors
    ENCamera(void)  // 0x808FE4A4
    ~ENCamera(void);  // 0x808FE50C

    // Methods
    void operator=(ENCamera &);  // 0x8085FC68 (168B)
    void Write(EStream &);  // 0x808FE578 (344B)
    void Read(EStream &);  // 0x808FE6D0 (652B)
    void Read(unsigned char *);  // 0x808FE95C (852B)
    void SetCameraPoint(int, ENCameraPoint);  // 0x808FEDB8 (152B)
    void SetName(char *);  // 0x808FF7E4 (68B)
    void SetID(int);  // 0x808FF828 (40B)
    void SetKeys(int);  // 0x808FF850 (76B)
    /* ? */ GetName(void);  // 0x808FF89C (40B)
    /* ? */ GetID(void);  // 0x808FF8C4 (44B)
    /* ? */ GetKeys(void);  // 0x808FF8F0 (44B)
    /* ? */ GetCameraPoint(int);  // 0x808FF9D0 (100B)

    // ---- Field Layout (from assembly analysis) ----
    u8 m_cameraPoint;  // 0x000 [W] (ENCamera, GetCameraPoint)
    u8 _pad_001[3];  // 0x001
    f32 m_cameraPoint_004;  // 0x004 [R/W] (GetCameraPoint, SetCameraPoint)
    u8 _pad_008[0x38];  // 0x008
    u32 m_field_040;  // 0x040 [R/W] (ENCamera, Write)
    u32 m_field_044;  // 0x044 [R/W] (ENCamera, Read, Write)
    u32 m_cameraPoint_048;  // 0x048 [R] (Read, SetCameraPoint, Write)
    u8 _pad_04C[4];  // 0x04C
    f32 m_cameraPoint_050;  // 0x050 [W] (GetCameraPoint)
    f32 m_cameraPoint_054;  // 0x054 [W] (ENCamera, GetCameraPoint, ~ENCamera)
    f32 m_cameraPoint_058;  // 0x058 [W] (GetCameraPoint)
    f32 m_cameraPoint_05C;  // 0x05C [W] (GetCameraPoint)
};

#endif // ENCAMERA_H
