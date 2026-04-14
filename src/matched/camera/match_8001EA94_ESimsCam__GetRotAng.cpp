// 0x8001EA94 (8 bytes) — lfs f1, 0x44C(r3); blr

class ESimsCam {
public:
    char _pad[0x44C];
    float m_rotAng;

    float GetRotAng() const;
};

float ESimsCam::GetRotAng() const {
    return m_rotAng;
}
