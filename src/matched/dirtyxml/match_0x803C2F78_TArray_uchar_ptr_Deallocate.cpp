// 0x803C2F78 TArray<uchar_ptr>::Deallocate (76B)
extern void Destruct(void*, int);
extern void* MainHeap();
extern void EAHeap_Free(void*, void*);
extern void Init(void*);
struct TArray { void* m_data; int m_size; };
void TArray_Deallocate(TArray* self) {
    Destruct(self->m_data, self->m_size);
    void* data = self->m_data;
    void* heap = MainHeap();
    EAHeap_Free(heap, data);
    Init(self);
}
