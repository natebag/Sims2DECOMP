// 0x800B4C60 CTilePt::ToFTilePt(void) const (72B)
struct FTilePt {
    int fy;
    int fx;
    inline FTilePt() {}
    inline FTilePt(const FTilePt& o) : fy(o.fy), fx(o.fx) {}
};

class CTilePt {
public:
    signed char m_x;
    signed char m_y;
    FTilePt ToFTilePt() const;
};

FTilePt CTilePt::ToFTilePt() const {
    FTilePt r;
    *(volatile int*)&r.fx = (m_x << 4) | 8;
    *(volatile int*)&r.fy = (m_y << 4) | 8;
    return r;
}
