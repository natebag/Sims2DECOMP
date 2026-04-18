// 0x801B8C3C (92B) H2DTarget::SpawnRewardMomentDialog(int, int)
extern void IncPause(bool);

struct H2DTarget {
    char pad[204];
    int m_flag1;      // 204 (0xCC)
    int pad2;         // 208 (0xD0)
    int m_fieldA;     // 212 (0xD4)
    int m_fieldB;     // 216 (0xD8)
    int m_flag2;      // 220 (0xDC)
    int SpawnRewardMomentDialog(int a, int b);
};

int H2DTarget::SpawnRewardMomentDialog(int a, int b) {
    if (m_flag1 != 0 || m_flag2 != 0) {
        return 0;
    }
    m_flag2 = 1;
    m_fieldA = a;
    m_fieldB = b;
    IncPause(false);
    return 1;
}
