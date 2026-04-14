// 0x800A752C (40 bytes)
// StringSet::CreateInstance(void)
struct QuickStringSet {
    void** _vtable;   // 0x00
    int m_field_04;   // 0x04
    void* m_string;   // 0x08
    void* m_pDB;      // 0x0C
    int m_field_10;   // 0x10

    QuickStringSet(void);
};

struct StringSet {
    void** _vtable;   // 0x00
    int m_field_04;   // 0x04
    void* m_string;   // 0x08
    void* m_pDB;      // 0x0C
    int m_field_10;   // 0x10

    static StringSet* CreateInstance(void);
};

StringSet* StringSet::CreateInstance(void) {
    return (StringSet*)new QuickStringSet();
}
