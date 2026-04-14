// 0x803C46F8 TArray_L_ENDummy__TArrayERModelAllocator_R__Deallocate_void (76b)
extern void Func1_6(int, int);
extern void Func2_6(int, int);
extern void Func3_6(void*);
extern int VTable_6[];

struct Obj_6 {
    int field0;
    int field4;
};

void Dealloc_6(Obj_6* self) {
    Func1_6(self->field0, self->field4);
    Func2_6((int)VTable_6, self->field0);
    Func3_6(self);
}
