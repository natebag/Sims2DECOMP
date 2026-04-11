// ESimsCam::ApplyZoom(float) - 0x80016FFC (116 bytes)

class ESimsCam {
public:
    void* m_paramsPtr;   // 0
    char pad[1092];      // 4
    float m_zoom;        // 1096 (0x448)
    char pad2[4];        // 1100
    float m_tilt;        // 1104 (0x450)
    
    void ApplyZoom(float delta);
    float CalcTiltFromZoom(void);
};

struct ZoomParams {
    char pad[40];
    float zoomMin;   // 40
    float zoomMax;   // 44
};

void ESimsCam::ApplyZoom(float delta) {
    volatile void** ptr = (volatile void**)&m_paramsPtr;
    ZoomParams* params = (ZoomParams*)*ptr;
    
    m_zoom -= delta;
    
    // Clamp m_zoom between zoomMin and zoomMax
    if (m_zoom < params->zoomMin) {
        m_zoom = params->zoomMin;
    } else if (m_zoom > params->zoomMax) {
        m_zoom = params->zoomMax;
    }
    
    // Calculate tilt from zoom
    m_tilt = CalcTiltFromZoom();
}
