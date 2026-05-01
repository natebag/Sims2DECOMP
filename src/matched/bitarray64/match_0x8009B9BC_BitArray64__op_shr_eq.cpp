// 0x8009B9BC BitArray64::operator>>=(int) (72B)

struct BitArray64 {
    long long m_bits;
    BitArray64& operator>>=(int n);
};

BitArray64& BitArray64::operator>>=(int n) {
    m_bits >>= n;
    return *this;
}
