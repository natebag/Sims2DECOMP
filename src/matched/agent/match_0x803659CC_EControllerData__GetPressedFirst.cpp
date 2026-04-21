// 0x803659CC (32B) EControllerData::GetPressedFirst(unsigned int) const
// Bit-test: (m_pressedFirst & (1u << n)) != 0
// `li r3,1; and.; bnelr; li r3,0; blr` is the SN early-return-bool pattern.

class EControllerData {
public:
    char pad[124];
    int m_pressedFirst;  // offset 124
    bool GetPressedFirst(unsigned int n) const;
};

bool EControllerData::GetPressedFirst(unsigned int n) const {
    unsigned int mask = 1u << n;
    if (m_pressedFirst & mask) return true;
    return false;
}
