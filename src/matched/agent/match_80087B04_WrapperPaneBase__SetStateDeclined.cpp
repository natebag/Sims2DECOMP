// 0x80087B04 (12 bytes)
class WrapperPaneBase {
public:
    char pad[52];
    int m_state;

    void SetStateDeclined(void);
};

void WrapperPaneBase::SetStateDeclined(void) {
    m_state = 2;
}
