// TArray<BSplineVolume, TArrayERModelAllocator>::Destruct(BSplineVolume*, int) @ 0x803C442C (100B)
// FLAGS: -fno-schedule-insns
// Loop calls virtual dtor via vtable[8](lha adj) + vtable[12](fn ptr).
// BSplineVolume element size = 224; vtable pointer at offset 220.

struct BSplineVolumeVtbl {
    void* _0;
    void* _4;
    short m_vbaseOff;
    short _A;
    void (*m_dtor)(void*, int);
};

struct BSplineVolume_D {
    char _0[220];
    BSplineVolumeVtbl* m_vtable;
};

void TArray_BSplineVolume_Destruct(BSplineVolume_D* ptr, int count) {
    int i = count - 1;
    if (count == 0) return;
    do {
        BSplineVolumeVtbl* vtbl = ptr->m_vtable;
        BSplineVolume_D* saved = ptr;
        ptr = (BSplineVolume_D*)((char*)ptr + 224);
        short adj = vtbl->m_vbaseOff;
        void (*fn)(void*, int) = vtbl->m_dtor;
        fn((char*)saved + adj, 2);
    } while (i--);
}
