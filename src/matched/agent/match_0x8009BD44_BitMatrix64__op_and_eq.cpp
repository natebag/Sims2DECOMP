// BitMatrix64::operator&=(BitMatrix64 &) at 0x8009BD44 (84B)

class BitArray64 {
public:
    BitArray64& operator&=(BitArray64& rhs);
    char data[8];
};

class BitMatrix64 {
public:
    BitMatrix64& operator&=(BitMatrix64& rhs);
private:
    BitArray64 m_rows[64];
};

BitMatrix64& BitMatrix64::operator&=(BitMatrix64& rhs) {
    BitArray64* src = rhs.m_rows;
    BitArray64* end = &rhs.m_rows[63];
    BitArray64* dst = m_rows;
    do {
        *dst &= *src;
        ++src;
        ++dst;
    } while ((int)src <= (int)end);
    return *this;
}
