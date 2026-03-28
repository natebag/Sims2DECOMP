/* CTilePt::Set(int, int) at 0x800B4D1C (12B) */

struct CTilePt {
    char m_x;
    char m_y;

    void Set(int x, int y);
};

void CTilePt::Set(int x, int y) {
    m_x = x;
    m_y = y;
}
