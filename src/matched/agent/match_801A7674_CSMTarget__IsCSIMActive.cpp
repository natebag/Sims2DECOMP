class CSMTarget {
public:
    char _pad[0x88];
    int m_isActive;

    int IsCSIMActive();
};

int CSMTarget::IsCSIMActive() {
    return m_isActive;
}
