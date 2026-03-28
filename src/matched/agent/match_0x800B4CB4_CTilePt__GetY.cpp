/* CTilePt::GetY(void) const at 0x800B4CB4 (12B) */

struct CTilePt {
    signed char m_x;
    signed char m_y;
    signed char m_level;

    int GetY(void) const;
};

int CTilePt::GetY(void) const {
    return m_y;
}
