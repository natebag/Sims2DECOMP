// 0x8007ED84 DlgWrapper::SetAlt1Text(unsigned wchar_t*) (60B)
void DlgWrapper_SetTextInternal(void* item, void* text);
void WrapperPaneBase_UpdateAptButtonWidth(void* self, int btnType);
struct DlgWrapper {
    char pad[0xAC];
    void* m_inner;
    void SetAlt1Text(void* text);
};
void DlgWrapper::SetAlt1Text(void* text) {
    void* inner = m_inner;
    void* item = ((void**)inner)[0x48/4];
    DlgWrapper_SetTextInternal(item, text);
    WrapperPaneBase_UpdateAptButtonWidth(inner, 2);
}
