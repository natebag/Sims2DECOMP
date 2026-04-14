// 0x80085514 WrapperPaneBase::GetItemSizeY (56B)
struct VTable {
    char pad[144];
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
    int GetItemSizeY(int type, int idx);
};
int WrapperPaneBase::GetItemSizeY(int type, int idx) {
    Item* item = GetItem(type, idx);
    VTable* vt = item->m_vt;
    return vt->m_fn((char*)item + vt->m_adj);
}
