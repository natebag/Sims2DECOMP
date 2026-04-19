// 0x800C1C74 (8B) Interaction::GetStackObject(void) const
// Getter for field at offset 0xC.

class Interaction {
public:
    char pad_000[0xC];
    int m_field_C;
    int GetStackObject(void) const;
};

int Interaction::GetStackObject(void) const {
    return m_field_C;
}
