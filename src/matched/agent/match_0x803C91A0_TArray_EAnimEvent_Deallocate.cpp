// 0x803C91A0 TArray_L_EAnimEvent__TArrayERAnimAllocator_R__Deallocate_void (76b)
extern void Func1_10(int, int);
extern void Func2_10(int, int);
extern void Func3_10(void*);
extern int VTable_10[];

struct Obj_10 {
    int field0;
    int field4;
};

void Dealloc_10(Obj_10* self) {
    Func1_10(self->field0, self->field4);
    Func2_10((int)VTable_10, self->field0);
    Func3_10(self);
}
