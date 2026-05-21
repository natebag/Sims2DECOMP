// 0x8009BE40 BitMatrix64::operator<<=(int) (80B)
// TRIAGE — twin of BitMatrix64::CountBits @ 0x8009BEE0

class BitArray64 {
public:
    BitArray64& operator<<=(int n);
};

class BitMatrix64 {
public:
    BitMatrix64& operator<<=(int n);
};

BitMatrix64& BitMatrix64::operator<<=(int n) {
    BitArray64* p = (BitArray64*)this;
    BitArray64* end = (BitArray64*)((char*)this + 504);
    do {
        *p <<= n;
        p = (BitArray64*)((char*)p + 8);
    } while ((int)p <= (int)end);
    return *this;
}
