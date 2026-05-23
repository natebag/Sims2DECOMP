// INGTarget::get_current_inginfo(void) - 0x801BBB60 (72 bytes)
//
// Tech #73 application — anti-tail-merge source-coax recipe instance #3.
// Structure: 4 return paths with last-test-as-beqlr (matches EBitArray::Get pattern).
//   - count > 11           → inline `li r3,0; blr`
//   - m_array[count] == 0  → tail `li r3,0; blr`
//   - ig->m_first == 0     → preset+beqlr (last test, fall-through tail)
//   - else                 → mr r3,r9; blr (return ig)
//
// FLAGS: -msdata=eabi -G 8

struct IngInfo {
    int m_first;
};

struct INGTarget {
    char pad_0[0x1B0];
    IngInfo* m_array[12];
    char pad_after[0x44C - 0x1B0 - 12 * 4];
    unsigned int m_count;

    IngInfo* get_current_inginfo();
};

IngInfo* INGTarget::get_current_inginfo() {
    if (m_count > 11) return 0;
    IngInfo* ig = m_array[m_count];
    if (ig == 0) return 0;
    if (ig->m_first == 0) return 0;
    return ig;
}
