// 0x8009B780 BitArray64::BitArray64(long long&) (24b)

struct BitArray64 {
    long long data;
    BitArray64(long long& p2);
};

BitArray64::BitArray64(long long& p2) {
    data = p2;
}
