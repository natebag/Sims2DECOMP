// 0x8009BEE0 BitMatrix64::CountBits(void) const (76B)

class BitArray64 {
public:
    int CountBits() const;
};

class BitMatrix64 {
public:
    int CountBits() const;
};

int BitMatrix64::CountBits() const {
    int total = 0;
    const BitArray64* p = (const BitArray64*)this;
    const BitArray64* end = (const BitArray64*)((const char*)this + 504);
    do {
        total += p->CountBits();
        p = (const BitArray64*)((const char*)p + 8);
    } while ((int)p <= (int)end);
    return total;
}
