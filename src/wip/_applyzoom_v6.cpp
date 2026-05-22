// ESimsCam::ApplyZoom(float) - 0x80016FFC (116 bytes)

class ESimsCam {
public:
    void* m_paramsPtr;   // 0
    char pad[1092];      // 4
    float m_zoom;        // 1096 (0x448)
    char pad2[4];        // 1100
    float m_tilt;        // 1104 (0x450)

    void ApplyZoom(float delta);
    float CalcTiltFromZoom(float zoom);
};

struct ZoomParams {
    char pad[40];
    float zoomMin;   // 40
    float zoomMax;   // 44
};

void ESimsCam::ApplyZoom(float delta) {
    ZoomParams* params = (ZoomParams*)m_paramsPtr;
    float zoom = m_zoom;
    float zoomMax = params->zoomMax;
    zoom -= delta;
    m_zoom = zoom;

    float zoomMin = params->zoomMin;
    float clamped;
    if (zoom < zoomMin) {
        clamped = zoomMin;
        goto store;
    }
    clamped = zoomMax;
    if (zoom > zoomMax) goto store;
    clamped = zoom;
store:
    m_zoom = clamped;
    m_tilt = CalcTiltFromZoom(clamped);
}
