// DlgWrapper::SetBodyText(unsigned wchar_t *)
// Address: 0x8007E84C | Size: 40 bytes

typedef unsigned short wchar_t;

struct TextBaseItem;

struct DlgWrapperInner {
    char pad[0x64];
    TextBaseItem* m_bodyTextItem;
};

struct DlgWrapper {
    char pad[0xAC];
    DlgWrapperInner* m_inner;
};

extern "C" void _ZN12TextBaseItem7SetTextEPw(TextBaseItem* self, wchar_t* text);

void DlgWrapper__SetBodyText(DlgWrapper* self, wchar_t* text) {
    _ZN12TextBaseItem7SetTextEPw(self->m_inner->m_bodyTextItem, text);
}
