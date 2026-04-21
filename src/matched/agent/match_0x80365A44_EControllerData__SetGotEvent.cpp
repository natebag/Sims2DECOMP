// 0x80365A44 (56B) EControllerData::SetGotEvent(unsigned int, bool)
// Twin of SetPressedFirst — only field offset differs (124 vs 128).

class EControllerData {
public:
    char pad[128];
    int m_gotEvent;  // offset 128
    void SetGotEvent(unsigned int n, bool val);
};

void EControllerData::SetGotEvent(unsigned int n, bool val) {
    if (val) {
        m_gotEvent |= (1u << n);
    } else {
        m_gotEvent &= ~(1u << n);
    }
}
