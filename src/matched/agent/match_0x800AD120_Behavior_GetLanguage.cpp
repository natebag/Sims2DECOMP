// 0x800AD120 (8B) Behavior::GetLanguage(void)
// Getter for field at offset 0x8.

class Behavior {
public:
    char pad_000[0x8];
    int m_field_8;
    int GetLanguage(void);
};

int Behavior::GetLanguage(void) {
    return m_field_8;
}
