// 0x800A74DC (40 bytes)
// QuickStringSet::CreateInstance(void)
struct QuickStringSet {
    void** _vtable;   // 0x00
    int m_field_04;   // 0x04
    void* m_string;   // 0x08
    void* m_pDB;      // 0x0C
    int m_field_10;   // 0x10

    QuickStringSet(void);
    static QuickStringSet* CreateInstance(void);
};

QuickStringSet* QuickStringSet::CreateInstance(void) {
    return new QuickStringSet();
}
