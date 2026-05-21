// 0x80188DBC HUDTarget::IsMenuAvailable(int) const (120B)

extern int GetTutorialLocks(int);

class HUDTarget {
public:
    char _pad0[236];
    int m_menuTable[1];
    char _pad236[1865 - 240];
    unsigned char m_menuFlag[1];

    int ShouldHUDBeVisible(int) const;
    int IsMenuAvailable(int) const;
};

int HUDTarget::IsMenuAvailable(int idx) const {
    int param = m_menuTable[idx];
    int result = 0;
    int locks = GetTutorialLocks(param);
    if ((locks & 2) != 0) goto end;
    if (((unsigned char*)this)[idx * 180 + 1865] != 1) goto end;
    if (ShouldHUDBeVisible(idx) == 0) goto end;
    result = 1;
end:
    return result;
}
