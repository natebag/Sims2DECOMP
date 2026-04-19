// 0x800C1D44 (8B) Interaction::GetType(void)
// Getter for field at offset 0x4.

class Interaction {
public:
    char pad_000[0x4];
    int m_field_4;
    int GetType(void);
};

int Interaction::GetType(void) {
    return m_field_4;
}
