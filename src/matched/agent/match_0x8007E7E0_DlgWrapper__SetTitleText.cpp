// DlgWrapper::SetTitleText(unsigned wchar_t *)
// Address: 0x8007E7E0 | Size: 40 bytes

typedef unsigned short wchar_t;

struct TextBaseItem;

struct DlgWrapperInner {
    char pad[0x60];
    TextBaseItem* m_titleTextItem;
};

struct DlgWrapper {
    char pad[0xAC];
    DlgWrapperInner* m_inner;
};

extern "C" void _ZN12TextBaseItem7SetTextEPw(TextBaseItem* self, wchar_t* text);

void DlgWrapper__SetTitleText(DlgWrapper* self, wchar_t* text) {
    _ZN12TextBaseItem7SetTextEPw(self->m_inner->m_titleTextItem, text);
}
