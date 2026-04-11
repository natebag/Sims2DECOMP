// 0x8009B728 BitArray64::BitArray64(BitArray64&) (24b)

struct BitArray64 {
    long long data;
    BitArray64(BitArray64& p2);
};

BitArray64::BitArray64(BitArray64& p2) {
    data = p2.data;
}
