// 0x80087B34 (20 bytes)
// WrapperPaneBase::IsStateAccepted(void) const
class WrapperPaneBase {
    int m_state;
public:
    bool IsStateAccepted() const;
};

bool WrapperPaneBase::IsStateAccepted() const {
    return m_state == 1;
}
