// 0x800C1D74 (8B) Interaction::GetTreeTabEntryIndex(void) const
// Getter for field at offset 0x14.

class Interaction {
public:
    char pad_000[0x14];
    int m_field_14;
    int GetTreeTabEntryIndex(void) const;
};

int Interaction::GetTreeTabEntryIndex(void) const {
    return m_field_14;
}
