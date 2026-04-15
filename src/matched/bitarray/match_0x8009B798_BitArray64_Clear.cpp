// 0x8009B798 BitArray64::Clear (20B) — zero two 4-byte fields
struct BitArray64 {
    int m_lo;
    int m_hi;
    void Clear();
};

void BitArray64::Clear() {
    *(long long*)this = 0LL;
}
