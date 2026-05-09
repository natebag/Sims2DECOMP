// EIFloor::operator new(unsigned int) at 0x8004762C (60 bytes)
// Pool-based allocator: pop head from free list, increment counter.

struct PoolNode { PoolNode* next; };
struct AllocPool { PoolNode* head; };

extern AllocPool* _eIFloorAllocPool;

class EIFloor {
public:
    static int m_nAlloced;
    static void* operator new(unsigned int);
};

int EIFloor::m_nAlloced;

void* EIFloor::operator new(unsigned int) {
    AllocPool* pool = _eIFloorAllocPool;
    PoolNode* head;
    if (!pool) goto END;
    head = pool->head;
    if (head) {
        pool->head = head->next;
    }
    if (!head) goto END;
    ++EIFloor::m_nAlloced;
    return head;
END:
    return 0;
}
