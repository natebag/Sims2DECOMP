// FLAGS: -msdata=eabi -G 8
// 0x802CBDD8 ENDummy::~ENDummy (84b)
extern int ENDummy_VTable[];
extern void TArray_Deallocate(void*, int);
extern void __builtin_delete(void*);

struct ENDummy {
    char pad[72];
    char array[12];
    int* vtable;
};

void ENDummy_dtor(ENDummy* self, int flags) {
    self->vtable = ENDummy_VTable;
    TArray_Deallocate(&self->array, 2);
    if (flags & 1) {
        __builtin_delete(self);
    }
}
