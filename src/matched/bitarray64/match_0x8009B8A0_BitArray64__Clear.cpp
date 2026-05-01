// 0x8009B8A0 BitArray64::Clear(int) (92B)

struct BitArray64 {
    long long m_bits;
    void Clear(int idx);
};

void BitArray64::Clear(int idx) {
    m_bits &= ~((long long)1 << idx);
}
