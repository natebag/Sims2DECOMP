class CTilePt {
public:
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
