// 0x800A75BC QuickStringSet::QuickStringSet (44b)
// Pattern: Vtable + fields + SDA external

extern int QuickStringSet_vtable[];
extern char QuickStringSet_sda_data[];

struct QuickStringSet {
    int* m_vt;      // offset 0
    int m_i4;       // offset 4
    int m_i8;       // offset 8
    int* m_sda_ptr; // offset 12
    int m_i16;      // offset 16
    QuickStringSet();
};

QuickStringSet::QuickStringSet() {
    QuickStringSet* p = this;
    p->m_vt = (int*)QuickStringSet_vtable;
    p->m_i8 = 0;
    p->m_sda_ptr = (int*)QuickStringSet_sda_data;
    p->m_i16 = 0;
    p->m_i4 = 0;
}
