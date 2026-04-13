// 0x800854DC WrapperPaneBase::GetItemSizeX(ItemType, int) (56B)

struct WrapperItem;
void* WrapperPaneBase_GetItem(void* self, int type, int index);

struct WrapperItemVtable {
    char pad[0x80];
    short m_adj;
    short pad1;
    void* (*m_fn)(void*);
};

struct WrapperItem {
    char pad[0x1C];
    WrapperItemVtable* m_vtable;
};

struct WrapperPaneBase {
    void* GetItemSizeX(int type, int index);
};

void* WrapperPaneBase::GetItemSizeX(int type, int index) {
    WrapperItem* item = (WrapperItem*)WrapperPaneBase_GetItem(this, type, index);
    WrapperItemVtable* vt = item->m_vtable;
    short adj = vt->m_adj;
    void* (*fn)(void*) = vt->m_fn;
    return fn((char*)item + adj);
}
