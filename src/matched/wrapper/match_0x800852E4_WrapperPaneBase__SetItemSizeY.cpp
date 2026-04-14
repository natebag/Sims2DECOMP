// 0x800852E4 WrapperPaneBase::SetItemSizeY (72B)
struct EVec2;
struct VTable {
    char pad[136];
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
    void SetItemSizeY(int type, int idx, float v);
};
void WrapperPaneBase::SetItemSizeY(int type, int idx, float v) {
    Item* item = GetItem(type, idx);
    VTable* vt = item->m_vt;
    vt->m_fn((char*)item + vt->m_adj, v);
}
