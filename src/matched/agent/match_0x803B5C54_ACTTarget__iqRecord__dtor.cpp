// FLAGS: -msdata=eabi -G 8
// 0x803B5C54 ACTTarget::iqRecord::~iqRecord (100B)

extern int iqRecord_VTable[];
extern void TArray_Deallocate(void*, int);
extern void Free_nullable(void*);
extern void __builtin_delete(void*);

struct iqRecord {
    char pad[12];
    char array[8];
    void* m_ptr;
    char pad2[4];
    int* vtable;
};

void iqRecord_dtor(iqRecord* self, int flags) {
    self->vtable = iqRecord_VTable;
    void* p = self->m_ptr;
    if (p != 0) {
        Free_nullable(p);
    }
    TArray_Deallocate(&self->array, 2);
    if (flags & 1) {
        __builtin_delete(self);
    }
}
