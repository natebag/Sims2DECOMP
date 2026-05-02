// 0x8009BB4C (100B) BitMatrix64::~BitMatrix64(void)
// Variant L: array dtor — backward-iterating destruction of 64 BitArray64 elements,
// with null-this guard.

void BitArray64_dtor(void* obj, int flag);
void __builtin_delete(void* p);

struct BitArray64 {
    char data[8];
};

struct BitMatrix64 {
    BitArray64 m_arr[64];
    void dtor(int flag);
};

void BitMatrix64::dtor(int flag) {
    if (this != 0) {
        BitArray64* p = m_arr + 64;
        if (m_arr != p) {
            do {
                p--;
                BitArray64_dtor(p, 0);
            } while (m_arr != p);
        }
    }
    if (flag & 1) {
        __builtin_delete(this);
    }
}
