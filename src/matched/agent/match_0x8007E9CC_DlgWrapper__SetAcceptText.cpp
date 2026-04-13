// 0x8007E9CC DlgWrapper::SetAcceptText(unsigned wchar_t*) (60B)
void DlgWrapper_SetTextInternal(void* item, void* text);
void WrapperPaneBase_UpdateAptButtonWidth(void* self, int btnType);
struct DlgWrapper {
    char pad[0xAC];
    void* m_inner;
    void SetAcceptText(void* text);
};
void DlgWrapper::SetAcceptText(void* text) {
    void* inner = m_inner;
    void* item = ((void**)inner)[0x40/4];
    DlgWrapper_SetTextInternal(item, text);
    WrapperPaneBase_UpdateAptButtonWidth(inner, 0);
}
