// TArray<ENCamera, TArrayERModelAllocator>::Destruct(ENCamera*, int) @ 0x803C47C8 (100B)
// FLAGS: -fno-schedule-insns
// Byte-identical to ENDummy Destruct @ 0x803C4694: same element size 88, vtable pointer at offset 84.
// Loop calls virtual dtor via vtable[8](lha adj) + vtable[12](fn ptr).

struct ENCamera47C8Vtbl {
    void* _0;
    void* _4;
    short m_vbaseOff;
    short _A;
    void (*m_dtor)(void*, int);
};

struct ENCamera47C8 {
    char _0[84];
    ENCamera47C8Vtbl* m_vtable;
};

void TArray_ENCamera_Destruct(ENCamera47C8* ptr, int count) {
    int i = count - 1;
    if (count == 0) return;
    do {
        ENCamera47C8Vtbl* vtbl = ptr->m_vtable;
        ENCamera47C8* saved = ptr;
        ptr = (ENCamera47C8*)((char*)ptr + 88);
        short adj = vtbl->m_vbaseOff;
        void (*fn)(void*, int) = vtbl->m_dtor;
        fn((char*)saved + adj, 2);
    } while (i--);
}
