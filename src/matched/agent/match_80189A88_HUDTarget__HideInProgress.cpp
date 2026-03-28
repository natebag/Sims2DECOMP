class HUDTarget {
public:
    char _pad[0xE8];
    unsigned char m_hideState;

    int HideInProgress(void) const;
};

int HUDTarget::HideInProgress(void) const {
    return m_hideState == 1;
}
