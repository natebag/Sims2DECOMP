/* BitArray64::operator&=(BitArray64 &) at 0x8009B924 (40B) */

struct BitArray64_BA {
    unsigned int lo;
    unsigned int hi;
    BitArray64_BA& operator&=(const BitArray64_BA& other);
};

BitArray64_BA& BitArray64_BA::operator&=(const BitArray64_BA& other) {
    lo &= other.lo;
    hi &= other.hi;
    return *this;
}
