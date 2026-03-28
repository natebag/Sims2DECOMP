/* CTilePt::GetRow(void) const at 0x800B49EC (24B) */

struct CTilePt {
    signed char m_x;
    signed char m_y;

    int GetRow(void) const;
};

int CTilePt::GetRow(void) const {
    return (int)m_x + (int)m_y;
}
