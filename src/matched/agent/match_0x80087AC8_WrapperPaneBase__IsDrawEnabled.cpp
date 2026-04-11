// 0x80087AC8 WrapperPaneBase::IsDrawEnabled (12b)
struct WrapperPaneBase {
    char pad[4];
    int m_flags;
    int IsDrawEnabled();
};

int WrapperPaneBase::IsDrawEnabled() {
    return m_flags & 1;
}
