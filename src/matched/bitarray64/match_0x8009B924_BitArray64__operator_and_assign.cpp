// 0x8009B924 BitArray64::operator&=(BitArray64 &) (40b)

struct BitArray64_AND {
    long long data;
    BitArray64_AND& operator&=(const BitArray64_AND& other);
};

BitArray64_AND& BitArray64_AND::operator&=(const BitArray64_AND& other) {
    this->data &= other.data;
    return *this;
}
