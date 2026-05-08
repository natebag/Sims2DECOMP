// 0x8009B94C BitArray64::operator^=(BitArray64 &) (40b)

struct BitArray64_XOR {
    long long data;
    BitArray64_XOR& operator^=(const BitArray64_XOR& other);
};

BitArray64_XOR& BitArray64_XOR::operator^=(const BitArray64_XOR& other) {
    this->data ^= other.data;
    return *this;
}
