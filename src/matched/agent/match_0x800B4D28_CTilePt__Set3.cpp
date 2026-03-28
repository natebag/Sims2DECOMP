/* CTilePt::Set(int, int, int) at 0x800B4D28 (16B) */

struct CTilePt {
    char m_x;
    char m_y;
    char m_level;

    void Set(int x, int y, int level);
};

void CTilePt::Set(int x, int y, int level) {
    m_x = x;
    m_y = y;
    m_level = level;
}
