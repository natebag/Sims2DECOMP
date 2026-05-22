// 0x8009BBB0 BitMatrix64::operator=(BitMatrix64 const&) (100B)

struct BitMatrix64 {
    int data[128];
    BitMatrix64& operator=(const BitMatrix64& other);
};

BitMatrix64& BitMatrix64::operator=(const BitMatrix64& other) {
    if (this == &other) return *this;
    __builtin_memcpy(this, &other, sizeof(BitMatrix64));
    return *this;
}
