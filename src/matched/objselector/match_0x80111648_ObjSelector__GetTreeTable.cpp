// 0x80111648 ObjSelector::GetTreeTable (88B)

struct TreeTableProviderVtbl {
    char pad[0x158];
    short adj;
    void* func;
};

struct TreeTableProvider {
    TreeTableProviderVtbl* vtable;
};

struct TreeTable;

struct ObjSelector {
    char pad[0x3c];
    TreeTable* m_treeTable;
    char pad2[0x50 - 0x3c - 4];
    TreeTableProvider* m_provider;
    
    TreeTable* GetTreeTable();
};

TreeTable* ObjSelector::GetTreeTable() {
    TreeTable* table = m_treeTable;
    if (table == 0) {
        TreeTableProviderVtbl* vt = m_provider->vtable;
        short adj = vt->adj;
        void* fn = vt->func;
        typedef void (*InitFunc)(void*, void*);
        InitFunc f = (InitFunc)fn;
        f((char*)m_provider + adj, this);
    }
    return m_treeTable;
}
