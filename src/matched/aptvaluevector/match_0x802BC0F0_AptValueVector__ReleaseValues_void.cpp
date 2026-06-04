// 0x802BC0F0 (128B) AptValueVector::ReleaseValues(void)
//
// Drains the GC value vector top-down. For each popped value: if its 12-bit
// refcount field (m_flags bits 14..25) is still nonzero, just clear the GC
// use-mark bit (0x20000000) and keep it; otherwise dispatch its slot-3 destroy
// virtual (vt+0x18). Clean structural C++.

struct AptValueObjHead {
    unsigned int m_flags;    // 0x00
    unsigned int m_field04;  // 0x04
};

struct AptValueObj : public AptValueObjHead {
    virtual void v1();
    virtual void v2();
    virtual void v3();   // vt+0x18
};

struct AptValueVector {
    int           m_field00;  // 0x00
    int           m_count;    // 0x04
    AptValueObj** m_data;     // 0x08
    void ReleaseValues();
};

void AptValueVector::ReleaseValues() {
    while (m_count != 0) {
        m_count--;
        AptValueObj* v = m_data[m_count];
        unsigned int flags = v->m_flags;
        if (((flags >> 14) & 0xFFF) != 0) {
            v->m_flags = flags & ~0x20000000;
        } else {
            v->v3();
        }
    }
}
