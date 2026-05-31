// 0x80086D10 Wrapper::FindPane(WrapperPaneBase*) (48 B)

struct WrapperPaneBase;

struct Wrapper {
    char pad_0000[0x8c];
    WrapperPaneBase** m_begin;
    WrapperPaneBase** m_end;

    WrapperPaneBase* FindPane(WrapperPaneBase* pane);
};

WrapperPaneBase* Wrapper::FindPane(WrapperPaneBase* pane) {
    WrapperPaneBase** end = m_end;
    WrapperPaneBase** p = m_begin;
    while (p != end) {
        if (*p == pane) {
            return *p;
        }
        p++;
    }
    return 0;
}
