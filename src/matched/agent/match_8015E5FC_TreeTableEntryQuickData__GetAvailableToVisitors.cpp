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
    if (m_entry->m_flags & 1)
        return 1;
    return 0;
}
