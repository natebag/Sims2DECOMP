// 0x803C4270 TArray_L_ESubModel__TArrayERModelAllocator_R__Deallocate_void (76b)
extern void Func1_2(int, int);
extern void Func2_2(int, int);
extern void Func3_2(void*);
extern int VTable_2[];

struct Obj_2 {
    int field0;
    int field4;
};

void Dealloc_2(Obj_2* self) {
    Func1_2(self->field0, self->field4);
    Func2_2((int)VTable_2, self->field0);
    Func3_2(self);
}
