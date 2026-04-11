// 0x800A76FC (92 bytes)
// QuickStringSet::GetLocString(int)
// FLAGS: -felide-constructors
struct StringBuffer {
    void** m_data;
};

struct WStrRef {
    void* m_ptr;
};

struct QuickStringSet {
    void** _vtable;
    StringBuffer* m_field_04;
    void* m_string;
    void* m_pDB;
    int m_field_10;

    WStrRef GetLocString(int idx) const;
};

WStrRef QuickStringSet::GetLocString(int idx) const {
    StringBuffer* info = m_field_04;
    if (info == 0) { WStrRef r = { m_pDB }; return r; }
    if (!(idx > 0)) { WStrRef r = { m_pDB }; return r; }
    void** data = info->m_data;
    int count = 0;
    if (data != 0) count = *((int*)data - 1);
    if (!(idx <= count)) { WStrRef r = { m_pDB }; return r; }
    WStrRef result;
    result.m_ptr = data[idx - 1];
    return result;
}
