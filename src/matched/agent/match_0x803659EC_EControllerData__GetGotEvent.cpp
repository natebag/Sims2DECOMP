// 0x803659EC (32B) EControllerData::GetGotEvent(unsigned int) const
// Bit-test: (m_gotEvent & (1u << n)) != 0
// Twin of GetPressedFirst at 0x803659CC, only field offset differs (124 vs 128).

class EControllerData {
public:
    char pad[128];
    int m_gotEvent;  // offset 128
    bool GetGotEvent(unsigned int n) const;
};

bool EControllerData::GetGotEvent(unsigned int n) const {
    unsigned int mask = 1u << n;
    if (m_gotEvent & mask) return true;
    return false;
}
