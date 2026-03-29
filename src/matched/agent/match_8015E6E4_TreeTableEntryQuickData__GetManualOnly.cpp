// 0x8015E6E4 (24 bytes)
// TreeTableEntryQuickData::GetManualOnly(void) const

struct ITreeTableEntry_GEMO {
    char _[22];
    short m_actionType;
};

class TreeTableEntryQuickData_GEMO {
    void* _vtable;
    ITreeTableEntry_GEMO* m_entry;
public:
    int GetManualOnly() const;
};

int TreeTableEntryQuickData_GEMO::GetManualOnly() const {
    return (m_entry->m_actionType > 99);
}
