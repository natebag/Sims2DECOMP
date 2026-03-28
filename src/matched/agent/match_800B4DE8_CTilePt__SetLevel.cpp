class CTilePt {
public:
    short m_xy;
    char m_level;

    void SetLevel(int level);
};

void CTilePt::SetLevel(int level) {
    m_level = level;
}
