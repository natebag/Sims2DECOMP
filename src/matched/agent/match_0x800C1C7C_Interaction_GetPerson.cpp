// 0x800C1C7C (8B) Interaction::GetPerson(void) const
// Getter for field at offset 0x8.

class Interaction {
public:
    char pad_000[0x8];
    int m_field_8;
    int GetPerson(void) const;
};

int Interaction::GetPerson(void) const {
    return m_field_8;
}
