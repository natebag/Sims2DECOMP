typedef unsigned char u8;

extern int ESims3DHead_vtable[];

void EWindow_dtor(u8*, int);
void* MainHeap();
void EAHeap_Free(void*, void*);

void ESims3DHead_dtor(u8* pThis, int flags) {
    *(int**)(pThis + 0x3B0) = ESims3DHead_vtable;
    EWindow_dtor(pThis, 0);
    if (flags & 1) {
        void* heap = MainHeap();
        EAHeap_Free(heap, pThis);
    }
}
