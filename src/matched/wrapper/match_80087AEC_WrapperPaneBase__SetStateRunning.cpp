// 0x80087AEC (12 bytes)
class WrapperPaneBase {
public:
    char pad[52];
    int m_state;

    void SetStateRunning(void);
};

void WrapperPaneBase::SetStateRunning(void) {
    m_state = 0;
}
