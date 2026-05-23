// 0x800879E0 (124B) WrapperPaneBase::~WrapperPaneBase(void)
// Variant L (DialogPane sibling): vtable@+0x5c + Shutdown + STL vec dealloc + delete branch.

extern char vt_WrapperPaneBase[];

struct VecBase {
    void* m_start;
    void* m_field_4;
    void* m_field_8;
    void* m_finish;
};

void WrapperPaneBase_Shutdown(void* obj);
void __builtin_delete(void* p);
void __node_alloc_M_deallocate(void* p, unsigned int n);

struct WrapperPaneBase {
    char pad_0_7[8];
    VecBase m_vec;
    char pad_14_5b[68];
    void* m_vt_at_5c;
    void dtor(int flag);
};

void WrapperPaneBase::dtor(int flag) {
    m_vt_at_5c = vt_WrapperPaneBase;
    WrapperPaneBase_Shutdown(this);
    VecBase* vec = &m_vec;
    if (vec->m_start != 0) {
        unsigned int bytes = (unsigned int)((char*)vec->m_finish - (char*)vec->m_start) & ~3U;
        if (bytes > 128) {
            __builtin_delete(vec->m_start);
        } else {
            __node_alloc_M_deallocate(vec->m_start, bytes);
        }
    }
    if (flag & 1) {
        __builtin_delete(this);
    }
}
