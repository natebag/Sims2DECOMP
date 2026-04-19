// 0x8009B768 (24B) BitArray64::operator=(BitArray64 &)

struct BitArray64 {
    long long data;
    BitArray64& operator=(BitArray64& other);
};

BitArray64& BitArray64::operator=(BitArray64& other) {
    data = other.data;
    return *this;
}
