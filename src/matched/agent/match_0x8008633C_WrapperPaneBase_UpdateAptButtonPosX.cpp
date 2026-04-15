// 0x8008633C (48B) WrapperPaneBase::UpdateAptButtonPosX(WrapperPaneBase::ButtonType)

struct Entry {
    char pad[4];
    unsigned int field_4;
};

struct WrapperPaneBase {
    char pad0[4];
    unsigned int m_mask;     // offset 4
    char pad1[56];
    Entry* m_entries[16];    // offset 64

    void UpdateAptButtonPosX(int bt);
};

void WrapperPaneBase::UpdateAptButtonPosX(int bt) {
    if ((m_mask & (256u << bt)) == 0) return;
    m_entries[bt]->field_4 |= (0x1080u << 16);
}
