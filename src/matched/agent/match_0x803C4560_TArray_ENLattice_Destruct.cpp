// TArray<ENLattice, TArrayERModelAllocator>::Destruct(ENLattice*, int) @ 0x803C4560 (100B)
// FLAGS: -fno-schedule-insns
// Loop calls virtual dtor via vtable[8](lha adj) + vtable[12](fn ptr).
// ENLattice element size = 176; vtable pointer at offset 172.

struct ENLatticeVtbl {
    void* _0;
    void* _4;
    short m_vbaseOff;
    short _A;
    void (*m_dtor)(void*, int);
};

struct ENLattice_D {
    char _0[172];
    ENLatticeVtbl* m_vtable;
};

void TArray_ENLattice_Destruct(ENLattice_D* ptr, int count) {
    int i = count - 1;
    if (count == 0) return;
    do {
        ENLatticeVtbl* vtbl = ptr->m_vtable;
        ENLattice_D* saved = ptr;
        ptr = (ENLattice_D*)((char*)ptr + 176);
        short adj = vtbl->m_vbaseOff;
        void (*fn)(void*, int) = vtbl->m_dtor;
        fn((char*)saved + adj, 2);
    } while (i--);
}
