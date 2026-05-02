// 0x802D8158 (96B) EThread::~EThread(void)
// Variant L: SI deleting-dtor — vtable@+0x338 + conditional Destroy + DeallocateStack + delete branch.

extern char vt_EThread[];

void EThread_Destroy(void* obj);
void EThread_DeallocateStack(void* obj);
void __builtin_delete(void* p);

struct EThread {
    char pad_0_317[792];
    int m_field_318;
    char pad_31c_337[28];
    void* m_vt_at_338;
    void dtor(int flag);
};

void EThread::dtor(int flag) {
    int handle = m_field_318;
    m_vt_at_338 = vt_EThread;
    if (handle != 0) {
        EThread_Destroy(this);
    }
    EThread_DeallocateStack(this);
    if (flag & 1) {
        __builtin_delete(this);
    }
}
