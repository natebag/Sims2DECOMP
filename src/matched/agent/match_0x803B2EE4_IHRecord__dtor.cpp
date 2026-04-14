// FLAGS: -msdata=eabi -G 8
// 0x803B2EE4 IHRecord::~IHRecord (84B)

extern int IHRecord_VTable[];
extern void TArray_Deallocate(void*, int);
extern void __builtin_delete(void*);

struct IHRecord {
    char pad[0x14];
    char array[4];
    int* vtable;
};

void IHRecord_dtor(IHRecord* self, int flags) {
    self->vtable = IHRecord_VTable;
    TArray_Deallocate(&self->array, 2);
    if (flags & 1) {
        __builtin_delete(self);
    }
}
