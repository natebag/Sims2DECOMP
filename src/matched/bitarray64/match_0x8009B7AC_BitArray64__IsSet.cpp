// 0x8009B7AC (80B) BitArray64::IsSet(int) const

class BitArray64 {
public:
    int IsSet(int idx) const;
};

int BitArray64::IsSet(int idx) const {
    long long val = *(long long*)this;
    long long bit = (val >> idx) & 1LL;
    if (bit == 0) return 0;
    return 1;
}
