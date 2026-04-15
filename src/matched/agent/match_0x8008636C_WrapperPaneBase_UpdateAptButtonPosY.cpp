// 0x8008636C (48B) WrapperPaneBase::UpdateAptButtonPosY(WrapperPaneBase::ButtonType)

struct Entry {
    char pad[4];
    unsigned int field_4;
};

struct WrapperPaneBase {
    char pad0[4];
    unsigned int m_mask;     // offset 4
    char pad1[56];
    Entry* m_entries[16];    // offset 64

    void UpdateAptButtonPosY(int bt);
};

void WrapperPaneBase::UpdateAptButtonPosY(int bt) {
    if ((m_mask & (256u << bt)) == 0) return;
    m_entries[bt]->field_4 |= (0x2080u << 16);
}
