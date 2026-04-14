/* CTilePt::SetY(int) at 0x800B4D10 (12B) */

struct CTilePt {
    signed char m_x;
    signed char m_y;
    signed char m_level;

    int SetY(int y);
};

int CTilePt::SetY(int y) {
    m_y = y;
    return (signed char)y;
}
