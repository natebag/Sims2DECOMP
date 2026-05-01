// 0x8009BA04 BitArray64::CountBits(void) const (80B)

struct BitArray64 {
    long long m_bits;
    int IsSet(int idx) const;
    int CountBits() const;
};

int BitArray64::CountBits() const {
    int count = 0;
    int i = 0;
    do {
        count += IsSet(i);
        i++;
    } while (i <= 63);
    return count;
}
