// 0x80189A34 HUDTarget::GetJobBarCount (28B)

struct HUDTarget {
    char pad[202];
    unsigned short m_field202;
    int GetJobBarCount();
};

int HUDTarget::GetJobBarCount() {
    unsigned short v = m_field202;
    if (v != 0) return v + 2;
    return 5;
}
