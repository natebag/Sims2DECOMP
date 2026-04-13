// 0x803C3004 TArray<unsigned char*, TArrayDefaultAllocator>::FreeAll (88B)
extern void* MainHeap();
extern void EAHeap_Free(void*, void*);
extern void Dealloc(void*);
struct TArray { void** m_data; int m_size; };
void FreeAll(TArray* self) {
    int count = self->m_size;
    void** data = self->m_data;
    while (count-- != 0) {
        void* heap = MainHeap();
        EAHeap_Free(heap, *data);
        data++;
    }
    Dealloc(self);
}
