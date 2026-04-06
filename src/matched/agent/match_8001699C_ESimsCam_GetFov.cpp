// ESimsCam::GetFov(void) - 0x8001699C (76 bytes)
// Calculates FOV based on current zoom ratio

class ESimsCam {
public:
    void* m_paramsPtr;   // 0 - points to camera params struct
    char pad[1092];      // 4
    float m_zoom;        // 1096 (0x448)
    // ... more fields
    
    float GetCurZoomRatio(void);
    float GetFov(void);
};

// Constants from SDA
extern float g_fovConstant1;  // -7396 (0x803d e3 1c)
extern float g_fovConstant2;  // implied from calculation

// ESimsCam layout - vtable at 0, then fields
// The code loads r11 from *(this+0) which is the vtable pointer
// Then loads from r11+0x60 and r11+0x64 - these are IN THE VTABLE
// So fovMin/fovMax are stored as constants in the vtable entries

// Actually looking again: lwz r11,0(r30) loads this->field0
// Then lfs f0,96(r11) loads from that pointer + 96
// So field0 points to a struct with fov values at offsets 96/100

struct FovParams {
    char pad[96];
    float fovMin;   // 96 (0x60)
    float fovMax;   // 100 (0x64)
};

float ESimsCam::GetFov(void) {
    float zoomRatio = GetCurZoomRatio();
    FovParams* params = (FovParams*)m_paramsPtr;  // r11 = this->field0
    
    // Interpolate FOV based on zoom ratio
    // f1 = fovMax * zoomRatio + fovMin * (1.0f - zoomRatio)
    return params->fovMax * zoomRatio + params->fovMin * (1.0f - zoomRatio);
}
