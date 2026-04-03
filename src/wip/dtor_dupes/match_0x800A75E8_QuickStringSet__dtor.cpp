// 0x800A75E8 (52 bytes)
// QuickStringSet::~QuickStringSet(void)
extern void* QuickStringSet_dtor_vtable[];

struct QuickStringSet {
    void** _vtable;   // 0x00
    int m_field_04;   // 0x04
    void* m_string;   // 0x08
    void* m_pDB;      // 0x0C
    int m_field_10;   // 0x10

    ~QuickStringSet(void);
};

QuickStringSet::~QuickStringSet(void) {
    _vtable = QuickStringSet_dtor_vtable;
}
