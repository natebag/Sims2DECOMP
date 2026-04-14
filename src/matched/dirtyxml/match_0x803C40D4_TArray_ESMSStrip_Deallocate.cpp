// 0x803C40D4 TArray_L_ESMSStrip__TArrayERModelAllocator_R__Deallocate_void (76b)
extern void Func1_1(int, int);
extern void Func2_1(int, int);
extern void Func3_1(void*);
extern int VTable_1[];

struct Obj_1 {
    int field0;
    int field4;
};

void Dealloc_1(Obj_1* self) {
    Func1_1(self->field0, self->field4);
    Func2_1((int)VTable_1, self->field0);
    Func3_1(self);
}
