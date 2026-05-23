// 0x80188DBC HUDTarget::IsMenuAvailable(int) const (120B)

extern int GetTutorialLocks(int mode);

class HUDTarget {
public:
    char pad[0xEC];
    int m_EC[4];
    int IsMenuAvailable(int idx) const;
    int ShouldHUDBeVisible(int idx) const;
};

int HUDTarget::IsMenuAvailable(int idx) const {
    int mode = m_EC[idx];
    int result = 0;
    int locks = GetTutorialLocks(mode);
    if ((locks & 2) == 0) {
        unsigned char b = *((char*)this + idx * 180 + 0x749);
        if (b == 1) {
            if (((HUDTarget*)this)->ShouldHUDBeVisible(idx)) {
                result = 1;
            }
        }
    }
    return result;
}
