// 0x8001EAB4 (8 bytes) — lwz r3, 0x54C(r3); blr

class ESimsCam {
public:
    char _pad[0x54C];
    int m_forceFullScreen;

    int IsForceFullScreen();
};

int ESimsCam::IsForceFullScreen() {
    return m_forceFullScreen;
}
