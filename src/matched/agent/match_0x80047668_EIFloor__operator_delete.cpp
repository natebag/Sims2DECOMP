// 0x80047668 EIFloor::operator delete(void*) (52B)
// Dead beqlr at 0x20: CR0 from cmpwi r3,0 (ptr != 0) leaves EQ=0, so beqlr never fires.
// GCC emits 12 insns (48B); DOL has 13 (52B) with the dead beqlr injected before lwz r0.
// ASMPROC_inject_before: before="lwz 0,0(11)" lines="beqlr"

extern void* _eIFloorAllocPool;

struct EIFloor {
    static int m_nAlloced;
    static void operator delete(void* ptr);
};

int EIFloor::m_nAlloced;

void EIFloor::operator delete(void* ptr) {
    void** pool = (void**)_eIFloorAllocPool;
    if (!pool) return;
    if (!ptr) return;
    EIFloor::m_nAlloced--;
    *(void**)ptr = *pool;
    *pool = ptr;
}
