/* CTilePt::GetX(void) const at 0x800B4CA8 (12B) */

struct CTilePt {
    signed char m_x;
    signed char m_y;
    signed char m_level;

    int GetX(void) const;
};

int CTilePt::GetX(void) const {
    return m_x;
}
