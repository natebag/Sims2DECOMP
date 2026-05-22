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
    ZoomParams* params = (ZoomParams*)m_paramsPtr;
    float zoomMax = params->zoomMax;

    m_zoom -= delta;

    float zoomMin = params->zoomMin;
    float clamped;
    if (m_zoom < zoomMin) {
        clamped = zoomMin;
    } else {
        clamped = zoomMax;
        if (m_zoom <= zoomMax)
            clamped = m_zoom;
    }
    m_zoom = clamped;
    m_tilt = CalcTiltFromZoom();
}
