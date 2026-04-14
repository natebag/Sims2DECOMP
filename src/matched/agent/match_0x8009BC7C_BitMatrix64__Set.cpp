// BitMatrix64::Set(CTilePt &) at 0x8009BC7C (80B)

class CTilePt {
public:
    int GetX() const;
    int GetY() const;
};

class BitArray64 {
public:
    void Set(int);
    char data[8];
};

class BitMatrix64 {
public:
    void Set(CTilePt& pt);
private:
    BitArray64 m_rows[8];
};

void BitMatrix64::Set(CTilePt& pt) {
    int y = pt.GetY();
    BitArray64* row = m_rows + y;
    int x = pt.GetX();
    row->Set(x);
}
