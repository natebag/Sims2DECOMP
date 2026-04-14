// 0x80099864 DummyMode::~DummyMode (84B)
typedef unsigned char u8;
extern int DummyMode_vtable[];
void ParentDtor(u8*, int);
void* MainHeap();
void EAHeap_Free(void*, void*);

void DummyMode_dtor(u8* pThis, int flags) {
    *(int**)(pThis + 8) = DummyMode_vtable;
    ParentDtor(pThis, 0);
    if (flags & 1) {
        void* heap = MainHeap();
        EAHeap_Free(heap, pThis);
    }
}
