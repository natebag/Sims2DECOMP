extern int EResource_vtable[];
extern int EStorable_vtable[];
struct EResourceManager {
    void ResourceDestructing(void*);
};
extern void* MainHeap_void();
struct EAHeap {
    void Free(void*);
};
struct EResource {
    int* m_vtable;
    EResourceManager* m_pManager;
    void _dtor(int in_charge);
};
void EResource::_dtor(int in_charge) {
    m_vtable = EResource_vtable;
    EResourceManager* mgr = m_pManager;
    if (mgr != 0) {
        mgr->ResourceDestructing(this);
    }
    m_vtable = EStorable_vtable;
    if (in_charge & 1) {
        EAHeap* heap = (EAHeap*)MainHeap_void();
        heap->Free(this);
    }
}
