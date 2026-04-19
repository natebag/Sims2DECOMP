/* BitArray64::operator^=(BitArray64 &) at 0x8009B94C (40B) */

struct BitArray64_XA {
    unsigned int lo;
    unsigned int hi;
    BitArray64_XA& operator^=(const BitArray64_XA& other);
};

BitArray64_XA& BitArray64_XA::operator^=(const BitArray64_XA& other) {
    lo ^= other.lo;
    hi ^= other.hi;
    return *this;
}
