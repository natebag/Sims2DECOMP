// 0x802D71D0 (80B) ProtectedAllocPool::~ProtectedAllocPool(void)
// Variant L (MI complete-object): vtable@+0x14 + EMutex member dtor at +0x18 + Allocator parent (flag passthrough).

extern char vt_ProtectedAllocPool[];

void EMutex_dtor(void* obj, int flag);
void Allocator_dtor(void* obj, int flag);

struct EMutex {
    char data[1];
};

struct ProtectedAllocPool {
    char pad_0_13[20];
    void* m_vt_at_14;
    EMutex m_mutex;
    void dtor(int flag);
};

void ProtectedAllocPool::dtor(int flag) {
    m_vt_at_14 = vt_ProtectedAllocPool;
    EMutex_dtor(&m_mutex, 2);
    Allocator_dtor(this, flag);
}
