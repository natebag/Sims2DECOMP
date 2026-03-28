/* CTilePt::GetColumn(void) const at 0x800B4A04 (24B) */

struct CTilePt {
    signed char m_x;
    signed char m_y;

    int GetColumn(void) const;
};

int CTilePt::GetColumn(void) const {
    return (int)m_x - (int)m_y;
}
