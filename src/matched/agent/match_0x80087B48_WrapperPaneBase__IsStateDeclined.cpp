// 0x80087B48 WrapperPaneBase::IsStateDeclined (20b)

struct WrapperPaneBase {
    char _pad[52];
    int m_state;
};

int WrapperPaneBase__IsStateDeclined(WrapperPaneBase *self) {
    return self->m_state == 2;
}
