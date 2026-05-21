// 0x80352218 Effects::FreeFastAllocPool(FastAllocPool*) (64B)

struct FAPDispatch {
    char _pad[8];
    short m_off;
    char _pad2[2];
    void (*m_fn)(void*, int);
};

struct FastAllocPool {
    char _pad0[20];
    FAPDispatch* m_dispatch;
};

namespace Effects {
void FreeFastAllocPool(FastAllocPool* pool) {
    if (!pool) return;
    FAPDispatch* vt = pool->m_dispatch;
    short off = vt->m_off;
    void (*fn)(void*, int) = vt->m_fn;
    fn((char*)pool + off, 3);
}
}
