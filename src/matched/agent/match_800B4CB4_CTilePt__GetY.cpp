class CTilePt {
public:
    signed char m_x;
    signed char m_y;

    int GetY(void) const;
};

int CTilePt::GetY(void) const {
    return m_y;
}
