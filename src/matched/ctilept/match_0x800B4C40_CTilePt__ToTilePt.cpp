// 0x800B4C40 CTilePt::ToTilePt(void) const (32B)
// FLAGS: -msdata=eabi -G 8

struct TilePt {
    int tp_x;
    int tp_y;
    inline TilePt(int x, int y) : tp_x(x), tp_y(y) {}
};

class CTilePt {
public:
    signed char m_x;
    signed char m_y;
    TilePt ToTilePt() const;
};

TilePt CTilePt::ToTilePt() const {
    return TilePt(m_x, m_y);
}
