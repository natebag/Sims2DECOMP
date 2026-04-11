// ESimsCam::SetFov(float) - 0x800169E8 (52 bytes)
// Inverse of GetFov - calculates zoom from FOV

class ESimsCam {
public:
    void* m_paramsPtr;   // 0 - points to camera params struct
    char pad[1092];      // 4
    float m_zoom;        // 1096 (0x448)
    
    void SetFov(float fov);
};

struct FovParams {
    char pad[40];
    float zoomMin;   // 40 (0x28)
    float zoomMax;   // 44 (0x2c)
    char pad2[48];
    float fovMin;    // 96 (0x60)
    float fovMax;    // 100 (0x64)
};

void ESimsCam::SetFov(float fov) {
    FovParams* params = (FovParams*)m_paramsPtr;
    
    // Inverse interpolation: zoom = zoomMin + (zoomMax - zoomMin) * ((fov - fovMin) / (fovMax - fovMin))
    float t = (fov - params->fovMin) / (params->fovMax - params->fovMin);
    m_zoom = params->zoomMin + t * (params->zoomMax - params->zoomMin);
}
