// 0x80176FC0 UI3D::Update3D() (68B) — linked-list iter

class CUnlockDisplay {
public:
    void Update();
};

class UI3DNode {
public:
    UI3DNode* m_0;
    UI3DNode* m_next;
    char pad[20];
    CUnlockDisplay* m_obj;
};

class UI3D {
public:
    UI3DNode* m_head;
    void Update3D();
};

void UI3D::Update3D() {
    UI3DNode* p = m_head;
    while (p) {
        p->m_obj->Update();
        p = p->m_next;
    }
}
