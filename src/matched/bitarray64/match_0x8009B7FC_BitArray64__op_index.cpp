// 0x8009B7FC (80B) BitArray64::operator[](int) const
// Twin of IsSet — same byte pattern

class BitArray64 {
public:
    int operator[](int idx) const;
};

int BitArray64::operator[](int idx) const {
    long long val = *(long long*)this;
    long long bit = (val >> idx) & 1LL;
    if (bit == 0) return 0;
    return 1;
}
