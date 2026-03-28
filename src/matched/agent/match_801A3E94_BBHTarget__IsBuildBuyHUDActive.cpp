class BBHTarget {
public:
    char _pad[0x88];
    int m_isActive;

    int IsBuildBuyHUDActive();
};

int BBHTarget::IsBuildBuyHUDActive() {
    return m_isActive;
}
