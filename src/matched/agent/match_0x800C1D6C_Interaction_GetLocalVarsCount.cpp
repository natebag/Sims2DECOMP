// 0x800C1D6C (8B) Interaction::GetLocalVarsCount(void)
// Getter for field at offset 0x20.

class Interaction {
public:
    char pad_000[0x20];
    int m_field_20;
    int GetLocalVarsCount(void);
};

int Interaction::GetLocalVarsCount(void) {
    return m_field_20;
}
