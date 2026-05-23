/* AptViewer::IsReadControllerActive(void) at 0x80011E58 (8B) */

struct AptViewer {
    char pad[0x3A4];
    int m_readControllerActive;

    int IsReadControllerActive(void);
};

int AptViewer::IsReadControllerActive(void) {
    return m_readControllerActive;
}
