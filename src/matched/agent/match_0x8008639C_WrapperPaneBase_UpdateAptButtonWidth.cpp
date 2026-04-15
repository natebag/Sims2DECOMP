// 0x8008639C (48B) WrapperPaneBase::UpdateAptButtonWidth(WrapperPaneBase::ButtonType)

struct Entry {
    char pad[4];
    unsigned int field_4;
};

struct WrapperPaneBase {
    char pad0[4];
    unsigned int m_mask;     // offset 4
    char pad1[56];
    Entry* m_entries[16];    // offset 64

    void UpdateAptButtonWidth(int bt);
};

void WrapperPaneBase::UpdateAptButtonWidth(int bt) {
    if ((m_mask & (256u << bt)) == 0) return;
    m_entries[bt]->field_4 |= (0x4080u << 16);
}
