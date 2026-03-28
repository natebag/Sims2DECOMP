class CASTarget {
public:
    char _pad[0x1630];
    int m_isShuttingDown;

    int IsShuttingdown();
};

int CASTarget::IsShuttingdown() {
    return m_isShuttingDown;
}
