// 0x80030654 (8 bytes) — stw r4, 0x3B0(r3); blr

class EIWallPart {
public:
    char _pad[0x3B0];
    int m_forceFadeOff;

    void SetForceFadeOff(bool val);
};

void EIWallPart::SetForceFadeOff(bool val) {
    m_forceFadeOff = val;
}
