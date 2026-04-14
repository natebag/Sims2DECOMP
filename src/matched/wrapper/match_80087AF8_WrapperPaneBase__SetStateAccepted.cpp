// 0x80087AF8 (12 bytes)
class WrapperPaneBase {
public:
    char pad[52];
    int m_state;

    void SetStateAccepted(void);
};

void WrapperPaneBase::SetStateAccepted(void) {
    m_state = 1;
}
