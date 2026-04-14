// 0x8015DC9C (28 bytes)
// TreeTableEntryQuickData::GetName(void) const

struct BString2_GN {
    char* m_str;
};

struct ITreeTableEntry_GN {
    char _[28];
    BString2_GN* m_name;
};

class TreeTableEntryQuickData_GN {
    void* _vtable;
    ITreeTableEntry_GN* m_entry;
public:
    char* GetName() const;
};

char* TreeTableEntryQuickData_GN::GetName() const {
    ITreeTableEntry_GN* entry = m_entry;
    char* res = 0;
    BString2_GN* name = entry->m_name;
    if (name) res = name->m_str;
    return res;
}
