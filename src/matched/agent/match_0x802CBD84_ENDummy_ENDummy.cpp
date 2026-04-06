// FLAGS: -msdata=eabi -G 8
// 0x802CBD84 ENDummy::ENDummy (84b)
extern int ENDummy_VTable[];
extern void TArray_Init(void*);

struct ENDummy {
    char byte_0;
    char pad[63];
    int field_64;
    int field_68;
    char array[12];
    int* vtable;
};

ENDummy* ENDummy_ctor(ENDummy* self) {
    self->vtable = ENDummy_VTable;
    TArray_Init(&self->array);
    self->byte_0 = 0;
    self->field_64 = 0;
    self->field_68 = 0;
    return self;
}
