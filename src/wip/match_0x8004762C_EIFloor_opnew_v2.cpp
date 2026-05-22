// EIFloor::operator new(unsigned int) at 0x8004762C (60 bytes)

extern void* _eIFloorAllocPool;

struct EIFloor {
    static int m_nAlloced;
    static void* operator new(unsigned int);
};

int EIFloor::m_nAlloced;

void* EIFloor::operator new(unsigned int) {
    void** pool = (void**)_eIFloorAllocPool;
    if (!pool) return 0;
    void* head = *pool;
    if (head) *pool = *(void**)head;
    if (!head) return head;
    ++EIFloor::m_nAlloced;
    return head;
}
