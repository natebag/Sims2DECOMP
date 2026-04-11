// 0x803C8FC8 TArray_L_EAnimNodeDataPos__TArrayERAnimAllocator_R__Deallocate_void (76b)
extern void Func1_8(int, int);
extern void Func2_8(int, int);
extern void Func3_8(void*);
extern int VTable_8[];

struct Obj_8 {
    int field0;
    int field4;
};

void Dealloc_8(Obj_8* self) {
    Func1_8(self->field0, self->field4);
    Func2_8((int)VTable_8, self->field0);
    Func3_8(self);
}
