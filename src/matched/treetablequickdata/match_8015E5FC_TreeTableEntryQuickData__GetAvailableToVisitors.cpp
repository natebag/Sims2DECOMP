// 0x8015E5FC (28 bytes)
// TreeTableEntryQuickData::GetAvailableToVisitors(void) const

struct ITreeTableEntry_GATV {
    char _[16];
    int m_flags;
};

class TreeTableEntryQuickData_GATV {
    void* _vtable;
    ITreeTableEntry_GATV* m_entry;
public:
    int GetAvailableToVisitors() const;
};

int TreeTableEntryQuickData_GATV::GetAvailableToVisitors() const {
    ITreeTableEntry_GATV* entry = m_entry;
    int res = 0;
    int flags = entry->m_flags;
    if (flags & 1) res = 1;
    return res;
}
