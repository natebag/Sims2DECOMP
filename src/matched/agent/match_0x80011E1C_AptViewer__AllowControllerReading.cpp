/* AptViewer::AllowControllerReading(bool) at 0x80011E1C (16B) */

struct AptViewer {
    char pad[0x3A4];
    int m_readControllerActive;

    int AllowControllerReading(int allow);
};

int AptViewer::AllowControllerReading(int allow) {
    int old = m_readControllerActive;
    m_readControllerActive = allow;
    return old;
}
