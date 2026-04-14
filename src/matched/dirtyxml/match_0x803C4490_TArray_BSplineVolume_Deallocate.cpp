// 0x803C4490 TArray_L_BSplineVolume__TArrayERModelAllocator_R__Deallocate_void (76b)
extern void Func1_4(int, int);
extern void Func2_4(int, int);
extern void Func3_4(void*);
extern int VTable_4[];

struct Obj_4 {
    int field0;
    int field4;
};

void Dealloc_4(Obj_4* self) {
    Func1_4(self->field0, self->field4);
    Func2_4((int)VTable_4, self->field0);
    Func3_4(self);
}
