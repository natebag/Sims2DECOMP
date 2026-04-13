/* Interaction::GetTreeTabEntryIndex(void) const - 0x800C1D74 (8 bytes) */

struct Interaction {
    char m_pad[0x14];
    int m_treeTabEntryIndex;

    int GetTreeTabEntryIndex(void) const;
};

int Interaction::GetTreeTabEntryIndex(void) const {
    return m_treeTabEntryIndex;
}
