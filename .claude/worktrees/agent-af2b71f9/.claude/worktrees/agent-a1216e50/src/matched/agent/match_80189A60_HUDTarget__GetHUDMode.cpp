class HUDTarget {
public:
    char _pad[0xC8];
    unsigned short m_hudMode;

    int GetHUDMode(void) const;
};

int HUDTarget::GetHUDMode(void) const {
    if (m_hudMode != 0) {
        return 1;
    }
    return 0;
}
