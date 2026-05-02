// 0x8015BE68 (116B) ObjectDataObjDefinition::~ObjectDataObjDefinition(void)
// Variant L: vtable@+0 + Reset + STL vec dealloc (no mask) + delete branch.

extern char vt_ObjectDataObjDefinition[];

void ObjectDataObjDefinition_Reset(void* obj);
void __builtin_delete(void* p);
void __node_alloc_M_deallocate(void* p, unsigned int n);

struct ObjectDataObjDefinition {
    void* m_vt_at_0;
    void* m_start;
    char pad_8_f[8];
    void* m_finish;
    void dtor(int flag);
};

void ObjectDataObjDefinition::dtor(int flag) {
    m_vt_at_0 = vt_ObjectDataObjDefinition;
    ObjectDataObjDefinition_Reset(this);
    void* p = m_start;
    unsigned int bytes = (unsigned int)((char*)m_finish - (char*)p);
    if (p != 0) {
        if (bytes > 128) {
            __builtin_delete(p);
        } else {
            __node_alloc_M_deallocate(p, bytes);
        }
    }
    if (flag & 1) {
        __builtin_delete(this);
    }
}
