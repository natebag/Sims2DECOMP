// 0x800853FC WrapperPaneBase::GetItemPos(ItemType, int) (56B)

struct WrapperItem;
void* WrapperPaneBase_GetItem(void* self, int type, int index);

struct WrapperItemVtable {
    char pad[0x40];
    short m_posAdj;
    short pad1;
    void* (*m_getPos)(void*);
};

struct WrapperItem {
    char pad[0x1C];
    WrapperItemVtable* m_vtable;
};

struct WrapperPaneBase {
    void* GetItemPos(int type, int index);
};

void* WrapperPaneBase::GetItemPos(int type, int index) {
    WrapperItem* item = (WrapperItem*)WrapperPaneBase_GetItem(this, type, index);
    WrapperItemVtable* vt = item->m_vtable;
    short adj = vt->m_posAdj;
    void* (*fn)(void*) = vt->m_getPos;
    return fn((char*)item + adj);
}
