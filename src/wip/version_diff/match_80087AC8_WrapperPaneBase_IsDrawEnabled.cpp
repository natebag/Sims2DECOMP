// 0x80087AC8 (12 bytes)
// WrapperPaneBase::IsDrawEnabled(void)
class WrapperPaneBase {
    int m_flags;
public:
    bool IsDrawEnabled();
};

bool WrapperPaneBase::IsDrawEnabled() {
    return m_flags & 1;
}
