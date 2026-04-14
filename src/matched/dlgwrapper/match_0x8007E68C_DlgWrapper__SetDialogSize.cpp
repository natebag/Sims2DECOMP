// 0x8007E68C DlgWrapper::SetDialogSize(EVec2&) (76B)
struct EVec2 { float x, y; };

struct WrapperElement {
    char pad[44];
    int m_x;
    int m_y;
};

struct WrapperPaneBase {
    char pad[100];
    WrapperElement* m_body;
};

struct DlgWrapper {
    char pad[172];
    WrapperPaneBase* m_base;
    char pad2[20];
    int m_sizeX;
    int m_sizeY;
    void SetDialogSize(EVec2& v);
};
extern void SetTBDirty(void* tb);

void DlgWrapper::SetDialogSize(EVec2& v) {
    int xb = *(int*)&v.x;
    int yb = *(int*)&v.y;
    m_sizeX = xb;
    m_sizeY = yb;
    WrapperElement* body = m_base->m_body;
    int xb2 = *(int*)&v.x;
    int yb2 = *(int*)&v.y;
    body->m_y = yb2;
    body->m_x = xb2;
    SetTBDirty((char*)body + 32);
}
