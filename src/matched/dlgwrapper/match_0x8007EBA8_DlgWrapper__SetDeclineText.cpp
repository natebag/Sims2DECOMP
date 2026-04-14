// 0x8007EBA8 DlgWrapper::SetDeclineText(unsigned wchar_t*) (60B)
void DlgWrapper_SetTextInternal(void* item, void* text);
void WrapperPaneBase_UpdateAptButtonWidth(void* self, int btnType);
struct DlgWrapper {
    char pad[0xAC];
    void* m_inner;
    void SetDeclineText(void* text);
};
void DlgWrapper::SetDeclineText(void* text) {
    void* inner = m_inner;
    void* item = ((void**)inner)[0x44/4];
    DlgWrapper_SetTextInternal(item, text);
    WrapperPaneBase_UpdateAptButtonWidth(inner, 1);
}
