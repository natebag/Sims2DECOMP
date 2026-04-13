struct BitArray64 {
    long long data;
    BitArray64& operator|=(const BitArray64& other);
};

BitArray64& BitArray64::operator|=(const BitArray64& other) {
    this->data |= other.data;
    return *this;
}
