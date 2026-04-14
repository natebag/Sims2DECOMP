// 0x800851C4 WrapperPaneBase::SetItemPosX (72B)
struct EVec2;
struct VTable {
    char pad[72];
    short m_adj;
    short m_pad;
    void (*m_fn)(void*, float);
};
struct Item {
    char pad[28];
    VTable* m_vt;
};
struct WrapperPaneBase {
    Item* GetItem(int type, int idx);
    void SetItemPosX(int type, int idx, float v);
};
void WrapperPaneBase::SetItemPosX(int type, int idx, float v) {
    Item* item = GetItem(type, idx);
    VTable* vt = item->m_vt;
    vt->m_fn((char*)item + vt->m_adj, v);
}
