// 0x80189A9C HUDTarget::IsHUDVisible() const (20B)

class HUDTarget {
public:
    char pad[0xE8];
    char m_globalVisibility;
    int IsHUDVisible() const;
};

int HUDTarget::IsHUDVisible() const {
    return m_globalVisibility == 2;
}
