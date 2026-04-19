// 0x80162028 (8B) CasMediator::GetNumListeners(void) const
// Getter for field at offset 0x8.

class CasMediator {
public:
    char pad_000[0x8];
    int m_field_8;
    int GetNumListeners(void) const;
};

int CasMediator::GetNumListeners(void) const {
    return m_field_8;
}
