// 0x80307CB0 (12 bytes) - EVibrate::Disable(void)
// li r0, 0; stw r0, 0(r3); blr

class EVibrate {
public:
    int m_enabled; // 0x00
    void Disable();
};

void EVibrate::Disable() {
    m_enabled = 0;
}
