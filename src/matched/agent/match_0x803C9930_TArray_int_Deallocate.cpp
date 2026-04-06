// 0x803C9930 TArray_L_int__TArrayERCharacterAllocator_R__Deallocate_void (76b)
extern void Func1_11(int, int);
extern void Func2_11(int, int);
extern void Func3_11(void*);
extern int VTable_11[];

struct Obj_11 {
    int field0;
    int field4;
};

void Dealloc_11(Obj_11* self) {
    Func1_11(self->field0, self->field4);
    Func2_11((int)VTable_11, self->field0);
    Func3_11(self);
}
