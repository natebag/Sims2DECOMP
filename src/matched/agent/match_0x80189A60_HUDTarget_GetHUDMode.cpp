// 0x80189A60 HUDTarget::GetHUDMode (24b)
struct HUDTarget {
    char pad[0xC8];
    unsigned short m_mode;
    int GetHUDMode() const;
};

int HUDTarget::GetHUDMode() const {
    int result = 1;
    if (m_mode != 0) return result;
    result = 0;
    return result;
}
