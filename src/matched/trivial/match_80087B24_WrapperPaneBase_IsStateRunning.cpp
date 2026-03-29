// 0x80087B24 (16 bytes)
// WrapperPaneBase::IsStateRunning(void) const
class WrapperPaneBase {
    int m_state;
public:
    bool IsStateRunning() const;
};

bool WrapperPaneBase::IsStateRunning() const {
    return m_state == 0;
}
