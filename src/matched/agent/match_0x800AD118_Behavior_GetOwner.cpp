// 0x800AD118 (8B) Behavior::GetOwner(void)
// Getter for field at offset 0x4.

class Behavior {
public:
    char pad_000[0x4];
    int m_field_4;
    int GetOwner(void);
};

int Behavior::GetOwner(void) {
    return m_field_4;
}
