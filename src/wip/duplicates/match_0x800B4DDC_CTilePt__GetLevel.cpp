/* CTilePt::GetLevel(void) const at 0x800B4DDC (12B) */

struct CTilePt {
    signed char m_x;
    signed char m_y;
    signed char m_level;

    int GetLevel(void) const;
};

int CTilePt::GetLevel(void) const {
    return m_level;
}
