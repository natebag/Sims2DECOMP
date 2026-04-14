// 0x8001EA74 (8 bytes) — lfs f1, 0x448(r3); blr

class ESimsCam {
public:
    char _pad[0x448];
    float m_zoom;

    float GetZoom() const;
};

float ESimsCam::GetZoom() const {
    return m_zoom;
}
