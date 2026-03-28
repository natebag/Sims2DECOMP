// 0x80087AE4 (8 bytes)
class WrapperPaneBase {
public:
    char pad[52];
    int m_state;

    void SetState(int state);
};

void WrapperPaneBase::SetState(int state) {
    m_state = state;
}
