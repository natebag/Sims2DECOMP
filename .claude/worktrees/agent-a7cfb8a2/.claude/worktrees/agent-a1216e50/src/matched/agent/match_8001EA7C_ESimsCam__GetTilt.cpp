// 0x8001EA7C (8 bytes) — lfs f1, 0x450(r3); blr

class ESimsCam {
public:
    char _pad[0x450];
    float m_tilt;

    float GetTilt() const;
};

float ESimsCam::GetTilt() const {
    return m_tilt;
}
