// 0x8008517C WrapperPaneBase::SetItemPos (72B)
struct EVec2;
struct VTable {
    char pad[56];
    short m_adj;
    short m_pad;
    void (*m_fn)(void*, EVec2&);
};
struct Item {
    char pad[28];
    VTable* m_vt;
};
struct WrapperPaneBase {
    Item* GetItem(int type, int idx);
    void SetItemPos(int type, int idx, EVec2& v);
};
void WrapperPaneBase::SetItemPos(int type, int idx, EVec2& v) {
    Item* item = GetItem(type, idx);
    VTable* vt = item->m_vt;
    vt->m_fn((char*)item + vt->m_adj, v);
}
