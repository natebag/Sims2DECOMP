// 0x802A9888 (68B) AptNativeHash::AptNativeHash(int)
//
// Hash-table ctor: zero-inits the table fields, sets the bucket count to n, and
// if n is not a power of two, rounds it up to the next power of two. Clean
// structural C++, leaf. Field-init source order is chosen so default scheduling
// hoists the last (m_16) store to the front, matching the DOL store order.

struct AptNativeHash {
    unsigned int m_capacity;  // 0x00
    unsigned int m_4;         // 0x04
    unsigned int m_8;         // 0x08
    unsigned int m_12;        // 0x0C
    unsigned int m_16;        // 0x10
    AptNativeHash(int n);
};

AptNativeHash::AptNativeHash(int n) {
    m_capacity = n;
    m_4 = 0;
    m_8 = 0;
    m_12 = 0;
    m_16 = 0;
    if ((n & (n - 1)) == 0)
        return;
    int p = 1;
    while (p < n)
        p <<= 1;
    m_capacity = p;
}
