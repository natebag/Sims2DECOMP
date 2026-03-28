// 0x8001EA84 (8 bytes) — stfs f1, 0x450(r3); blr

class ESimsCam {
public:
    char _pad[0x450];
    float m_tilt;

    void SetTilt(float val);
};

void ESimsCam::SetTilt(float val) {
    m_tilt = val;
}
