class CTilePt {
public:
    char m_x;
    char m_y;
    char m_level;

    void SetLevel(CTilePt &other);
};

void CTilePt::SetLevel(CTilePt &other) {
    m_level = other.m_level;
}
