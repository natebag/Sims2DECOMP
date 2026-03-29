// 0x800A7554 (40 bytes)
// StringSet::CreateInstance(ObjectDataID &)
struct ObjectDataID {
    int m_id;
    short m_info;
};

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

    static StringSet* CreateInstance(ObjectDataID& id);
};

StringSet* StringSet::CreateInstance(ObjectDataID& id) {
    return (StringSet*)new QuickStringSet();
}
