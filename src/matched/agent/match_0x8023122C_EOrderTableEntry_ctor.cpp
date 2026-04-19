// 0x8023122C (20B) EOrderTableEntry::ctor — 8B zero-init POD
// volatile pointer forces mr r9,r3 save + stw order.

class EOrderTableEntry {
public:
    int m_field_0;
    int m_field_4;
    EOrderTableEntry(void);
};

EOrderTableEntry::EOrderTableEntry(void) {
    volatile int* p = (volatile int*)this;
    p[1] = 0;
    p[0] = 0;
}
