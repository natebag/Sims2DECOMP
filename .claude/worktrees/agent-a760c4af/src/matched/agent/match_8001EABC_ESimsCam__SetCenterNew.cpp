// 0x8001EABC (8 bytes) — stw r4, 0x540(r3); blr

class ESimsCam {
public:
    char _pad[0x540];
    int m_centerNew;

    void SetCenterNew(bool val);
};

void ESimsCam::SetCenterNew(bool val) {
    m_centerNew = val;
}
