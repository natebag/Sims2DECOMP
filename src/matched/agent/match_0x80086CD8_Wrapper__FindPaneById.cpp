// 0x80086CD8 (56B) Wrapper::FindPaneById(int)
struct WrapperPane_FP { int id; };
struct Wrapper_FP {
    char _pad[140];
    WrapperPane_FP **m_140;
    WrapperPane_FP **m_144;
    WrapperPane_FP* FindPaneById(int id);
};
WrapperPane_FP* Wrapper_FP::FindPaneById(int id) {
    for (WrapperPane_FP **p = m_140; p != m_144; p++) {
        if ((*p)->id == id) return *p;
    }
    return 0;
}
