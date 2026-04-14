// BitMatrix64::IsSet(CTilePt &) const at 0x8009BC2C (80B)

class CTilePt {
public:
    int GetX() const;
    int GetY() const;
};

class BitArray64 {
public:
    int IsSet(int) const;
    char data[8];
};

class BitMatrix64 {
public:
    int IsSet(CTilePt& pt) const;
private:
    BitArray64 m_rows[8];
};

int BitMatrix64::IsSet(CTilePt& pt) const {
    int y = pt.GetY();
    const BitArray64* row = m_rows + y;
    int x = pt.GetX();
    return row->IsSet(x);
}
