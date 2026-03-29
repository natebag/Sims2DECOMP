// 0x800A7C08 (24 bytes)
// QuickStringSet::GetID(void)
struct StringData {
    char pad[8];
    short m_id;   // 0x08
};

struct QuickStringSet {
    void** _vtable;     // 0x00
    int m_field_04;     // 0x04
    StringData* m_string; // 0x08

    int GetID(void);
};

int QuickStringSet::GetID(void) {
    StringData* s = m_string;
    if (s == 0) return 0;
    return s->m_id;
}
