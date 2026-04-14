// 0x8009b768 BitArray64::operator=(BitArray64 &) (24B)

struct BitArray64 {
    int m_low;
    int m_high;
    BitArray64& operator=(BitArray64& other);
};

BitArray64& BitArray64::operator=(BitArray64& other) {
    long long* src = (long long*)&other;
    long long* dst = (long long*)this;
    *dst = *src;
    return *this;
}
