// 0x8001EAAC (8 bytes) — stw r4, 0x54C(r3); blr

class ESimsCam {
public:
    char _pad[0x54C];
    int m_forceFullScreen;

    void ForceFullScreen(bool val);
};

void ESimsCam::ForceFullScreen(bool val) {
    m_forceFullScreen = val;
}
