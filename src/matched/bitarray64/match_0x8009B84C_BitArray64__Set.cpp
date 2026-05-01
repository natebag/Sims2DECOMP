// 0x8009B84C BitArray64::Set(int) (84B)

struct BitArray64 {
    long long m_bits;
    void Set(int idx);
};

void BitArray64::Set(int idx) {
    m_bits |= (long long)1 << idx;
}
