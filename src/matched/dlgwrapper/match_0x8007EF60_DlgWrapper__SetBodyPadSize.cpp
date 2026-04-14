// 0x8007EF60 DlgWrapper::SetBodyPadSize(EVec2&) (60B)
// Pattern: binary-copy EVec2 into body[52..59] via pre-loaded int temps
struct EVec2 { float x, y; };

struct WrapperElement {
    char pad[52];
    int m_padX;
    int m_padY;
};

struct WrapperPaneBase {
    char pad[100];
    WrapperElement* m_body;
};

struct DlgWrapper {
    char pad[172];
    WrapperPaneBase* m_base;
    void SetBodyPadSize(EVec2& v);
};
extern void SetTBDirty(void* tb);

void DlgWrapper::SetBodyPadSize(EVec2& v) {
    int xb = *(int*)&v.x;
    int yb = *(int*)&v.y;
    WrapperElement* body = m_base->m_body;
    body->m_padY = yb;
    body->m_padX = xb;
    SetTBDirty((char*)body + 32);
}
