// 0x80011E58 (8 bytes) — lwz r3, 0x3A4(r3); blr

class AptViewer {
public:
    char _pad[0x3A4];
    int m_readControllerActive;

    int IsReadControllerActive();
};

int AptViewer::IsReadControllerActive() {
    return m_readControllerActive;
}
