/* CTilePt::SetLevel(int) at 0x800B4DE8 (8B) */

struct CTilePt {
    char m_x;
    char m_y;
    char m_level;

    void SetLevel(int level);
};

void CTilePt::SetLevel(int level) {
    m_level = level;
}
