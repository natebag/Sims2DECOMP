// 0x803A2FF8 (48B) FTilePt::operator==(FTilePt&) const
// Compare y first; if differs, return 0; else compute (x==rhs.x) via xor/subfic/adde idiom.
// Single-exit accumulator pattern: r11=0 early; computed result also lives in r11; final or r3,r11,r11.

class FTilePt {
public:
    int m_x;
    int m_y;
    int operator==(const FTilePt& rhs) const;
};

int FTilePt::operator==(const FTilePt& rhs) const
{
    int r = 0;
    if (m_y == rhs.m_y) {
        r = (m_x == rhs.m_x);
    }
    return r;
}
