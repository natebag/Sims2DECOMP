// 0x800854DC WrapperPaneBase::GetItemSizeX (56B)
struct VTable {
    char pad[128];
    short m_adj;
    short m_pad;
    int (*m_fn)(void*);
};
struct Item {
    char pad[28];
    VTable* m_vt;
};
struct WrapperPaneBase {
    Item* GetItem(int type, int idx);
    int GetItemSizeX(int type, int idx);
};
int WrapperPaneBase::GetItemSizeX(int type, int idx) {
    Item* item = GetItem(type, idx);
    VTable* vt = item->m_vt;
    return vt->m_fn((char*)item + vt->m_adj);
}
