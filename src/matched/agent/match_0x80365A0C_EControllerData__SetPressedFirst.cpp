// 0x80365A0C (56B) EControllerData::SetPressedFirst(unsigned int, bool)
// if (val) m_pressedFirst |= (1u << n); else m_pressedFirst &= ~(1u << n);
// Compiler emits `rotlw -2, r4` for the clear-path mask (= ~(1u << n)).

class EControllerData {
public:
    char pad[124];
    int m_pressedFirst;  // offset 124
    void SetPressedFirst(unsigned int n, bool val);
};

void EControllerData::SetPressedFirst(unsigned int n, bool val) {
    if (val) {
        m_pressedFirst |= (1u << n);
    } else {
        m_pressedFirst &= ~(1u << n);
    }
}
