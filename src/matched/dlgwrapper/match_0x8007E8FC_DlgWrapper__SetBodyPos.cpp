// 0x8007E8FC DlgWrapper::SetBodyPos(EVec2&) (88B)
// Pattern: stack-copy EVec2 + PMF call at slot 56/60 on body
struct EVec2 { float x, y; };
struct VTable {
    char pad[56];
    short m_adj;
    short m_pad;
    void (*m_fn)(void*, EVec2*);
};
struct Item {
    char pad[28];
    VTable* m_vt;
};
struct WrapperPaneBase {
    char pad[100];
    Item* m_body;
};
struct DlgWrapper {
    char pad[172];
    WrapperPaneBase* m_base;
    void SetBodyPos(EVec2& v);
};

void DlgWrapper::SetBodyPos(EVec2& v) {
    EVec2 local;
    local.x = v.x;
    local.y = v.y;
    Item* body = m_base->m_body;
    VTable* vt = body->m_vt;
    vt->m_fn((char*)body + vt->m_adj, &local);
}
