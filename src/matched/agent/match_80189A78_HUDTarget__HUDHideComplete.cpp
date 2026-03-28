class HUDTarget {
public:
    char _pad[0xE8];
    unsigned char m_hideInProgress;

    int HUDHideComplete(void) const;
};

int HUDTarget::HUDHideComplete(void) const {
    return !m_hideInProgress;
}
