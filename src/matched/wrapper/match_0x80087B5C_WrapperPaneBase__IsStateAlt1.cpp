// 0x80087B5C WrapperPaneBase::IsStateAlt1 (20B)
struct WrapperPaneBase {
    char pad[52];
    int m_state;
    int IsStateAlt1() const;
};

int WrapperPaneBase::IsStateAlt1() const {
    return m_state == 3;
}
