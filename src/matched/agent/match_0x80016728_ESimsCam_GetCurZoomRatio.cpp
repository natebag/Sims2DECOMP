// 0x80016728 ESimsCam::GetCurZoomRatio() (72B)

struct ESimsCamInner {
    char pad[40];
    float m_minZoom;   // offset 40
    float m_maxZoom;   // offset 44
};

struct ESimsCam {
    ESimsCamInner* m_inner;       // offset 0
    char pad[1092];
    float m_curZoom;              // offset 1096

    float GetCurZoomRatio();
};

float ESimsCam::GetCurZoomRatio() {
    ESimsCamInner* inner = this->m_inner;
    float curZ = this->m_curZoom;
    float minZ = inner->m_minZoom;
    float maxZ = inner->m_maxZoom;
    float ratio = (curZ - minZ) / (maxZ - minZ);
    if (ratio < 0.0f) return 0.0f;
    if (!(ratio > 1.0f)) return ratio;
    return 1.0f;
}
