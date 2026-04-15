// 0x80017070 ESimsCam::SetZoom(float) (44B)
// Store arg float at +1096, then call ApplyZoom with SDA constant

extern char g_defaultZoomFactor[16];  // non-SDA via 16-byte array

struct ESimsCam {
    char pad[1096];
    float m_zoom;
    void SetZoom(float z);
    void ApplyZoom(float z);
};

void ESimsCam::SetZoom(float z) {
    m_zoom = z;
    ApplyZoom(*(float*)g_defaultZoomFactor);
}
