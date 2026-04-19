// 0x8009B768 (24B) BitArray64::operator=(BitArray64 &)
// long long forces r11/r12 pair load scheduling

struct BitArray64 {
    long long data;
    BitArray64& operator=(BitArray64& other);
};

BitArray64& BitArray64::operator=(BitArray64& other) {
    data = other.data;
    return *this;
}
