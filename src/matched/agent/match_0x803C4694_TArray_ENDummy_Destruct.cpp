// TArray<ENDummy, TArrayERModelAllocator>::Destruct(ENDummy*, int) @ 0x803C4694 (100B)
// FLAGS: -fno-schedule-insns
// Loop calls virtual dtor via vtable[8](lha adj) + vtable[12](fn ptr).
// ENDummy element size = 88; vtable pointer at offset 84.

struct ENDummyVtbl {
    void* _0;
    void* _4;
    short m_vbaseOff;
    short _A;
    void (*m_dtor)(void*, int);
};

struct ENDummy_D {
    char _0[84];
    ENDummyVtbl* m_vtable;
};

void TArray_ENDummy_Destruct(ENDummy_D* ptr, int count) {
    int i = count - 1;
    if (count == 0) return;
    do {
        ENDummyVtbl* vtbl = ptr->m_vtable;
        ENDummy_D* saved = ptr;
        ptr = (ENDummy_D*)((char*)ptr + 88);
        short adj = vtbl->m_vbaseOff;
        void (*fn)(void*, int) = vtbl->m_dtor;
        fn((char*)saved + adj, 2);
    } while (i--);
}
