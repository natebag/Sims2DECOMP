// 0x800A7504 (40 bytes)
// QuickStringSet::CreateInstance(ObjectDataID &)
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
    static QuickStringSet* CreateInstance(ObjectDataID& id);
};

QuickStringSet* QuickStringSet::CreateInstance(ObjectDataID& id) {
    return new QuickStringSet();
}
