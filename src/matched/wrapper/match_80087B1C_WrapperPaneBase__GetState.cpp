// 0x80087B1C (8 bytes)
class WrapperPaneBase {
public:
    char pad[52];
    int m_state;

    int GetState(void) const;
};

int WrapperPaneBase::GetState(void) const {
    return m_state;
}
