// 0x800A7C28 (56 bytes)
// QuickStringSet::GetDataID(void) const
// FLAGS: -felide-constructors
struct ObjectDataID {
    int m_id;
    short m_info;
    ObjectDataID(int id, short info);
};

struct QuickStringSet {
    void** _vtable;   // 0x00
    int m_field_04;   // 0x04
    void* m_string;   // 0x08
    void* m_pDB;      // 0x0C
    int m_field_10;   // 0x10

    ObjectDataID GetDataID(void) const;
};

ObjectDataID QuickStringSet::GetDataID(void) const {
    return ObjectDataID(-1, 0);
}
