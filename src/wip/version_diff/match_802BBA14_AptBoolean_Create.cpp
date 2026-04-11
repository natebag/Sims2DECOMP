typedef unsigned int uint;

struct DOGMA_PoolManager {
    void* Allocate(uint size);
};

struct AptAllocTracker {
    int m_max;
    int m_count;
    void** m_array;
};

struct AptBoolVal {
    uint m_flags;
    char _pad[4];
    void* m_vtable;
    int m_val;
};

extern AptBoolVal* AptBoolean_spFirstFree;
extern DOGMA_PoolManager* spAptPoolManager;
extern AptAllocTracker* spAptAllocTracker;
extern int AptBoolean_vtbl[];

void AptValue_ctor(void*, int);

AptBoolVal* AptBoolean_Create(int val)
{
    AptBoolVal* p = AptBoolean_spFirstFree;
    if (p != 0) {
        uint flags = p->m_flags;
        AptBoolVal* next = (AptBoolVal*)p->m_val;
        AptAllocTracker* t = spAptAllocTracker;
        uint nf = flags | 0x20000000;
        AptBoolean_spFirstFree = next;
        p->m_flags = nf;
        int cnt = t->m_count;
        int mx = t->m_max;
        if (cnt >= mx) {
            p->m_flags = nf & ~0x20000000;
        } else {
            t->m_array[cnt] = (void*)p;
            t->m_count = cnt + 1;
        }
        p->m_val = val;
        return p;
    }
    AptBoolVal* q = (AptBoolVal*)spAptPoolManager->Allocate(16);
    AptValue_ctor(q, 5);
    q->m_val = val;
    q->m_vtable = (void*)AptBoolean_vtbl;
    return q;
}
