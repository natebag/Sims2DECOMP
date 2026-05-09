// TArray<EAnimNodeDataPos, TArrayERAnimAllocator>::Destruct(EAnimNodeDataPos*, int) @ 0x803C8F64 (100B)
// FLAGS: -fno-schedule-insns
// Loop calls virtual dtor via vtable[0x30](lha adj) + vtable[0x34](fn ptr).
// EAnimNodeDataPos element size = 36; vtable pointer at offset 0.

struct EAnimNodeDataPosVtbl {
    char _0[0x30];
    short m_vbaseOff;
    short _32;
    void (*m_dtor)(void*, int);
};

struct EAnimNodeDataPos_D {
    EAnimNodeDataPosVtbl* m_vtable;
    char _4[32];
};

void TArray_EAnimNodeDataPos_Destruct(EAnimNodeDataPos_D* ptr, int count) {
    int i = count - 1;
    if (count == 0) return;
    do {
        EAnimNodeDataPosVtbl* vtbl = ptr->m_vtable;
        EAnimNodeDataPos_D* saved = ptr;
        ptr = (EAnimNodeDataPos_D*)((char*)ptr + 36);
        short adj = vtbl->m_vbaseOff;
        void (*fn)(void*, int) = vtbl->m_dtor;
        fn((char*)saved + adj, 2);
    } while (i--);
}
