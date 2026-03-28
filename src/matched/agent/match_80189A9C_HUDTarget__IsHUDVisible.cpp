class HUDTarget {
public:
    char _pad[0xE8];
    unsigned char m_hideState;

    int IsHUDVisible(void) const;
};

int HUDTarget::IsHUDVisible(void) const {
    return m_hideState == 2;
}
