/* CTilePt::SetX(int) at 0x800B4D04 (12B) */

struct CTilePt {
    signed char m_x;
    signed char m_y;
    signed char m_level;

    int SetX(int x);
};

int CTilePt::SetX(int x) {
    m_x = x;
    return (signed char)x;
}
