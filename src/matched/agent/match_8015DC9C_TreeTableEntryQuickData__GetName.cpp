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
    BString2_GN* name = m_entry->m_name;
    if (!name) return 0;
    return name->m_str;
}
