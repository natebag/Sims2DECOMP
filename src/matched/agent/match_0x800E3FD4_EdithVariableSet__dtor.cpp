// 0x800E3FD4 (108B) EdithVariableSet::~EdithVariableSet(void)
// Variant L (DialogPane sibling, sizeof(T)=2 variant): vec at +0xc, finish at +0x18, mask & ~1.

void __builtin_delete(void* p);
void __node_alloc_M_deallocate(void* p, unsigned int n);

struct VecBase16 {
    void* m_start;
    void* m_field_4;
    void* m_field_8;
    void* m_finish;
};

struct EdithVariableSet {
    char pad_0_b[12];
    VecBase16 m_vec;
    void dtor(int flag);
};

void EdithVariableSet::dtor(int flag) {
    VecBase16* vec = &m_vec;
    if (vec->m_start != 0) {
        unsigned int bytes = (unsigned int)((char*)vec->m_finish - (char*)vec->m_start) & ~1U;
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
