// 0x803C3810 TArray_L_ESubModelShader__TArrayERModelAllocator_R__Deallocate_void (76b)
extern void Func1_0(int, int);
extern void Func2_0(int, int);
extern void Func3_0(void*);
extern int VTable_0[];

struct Obj_0 {
    int field0;
    int field4;
};

void Dealloc_0(Obj_0* self) {
    Func1_0(self->field0, self->field4);
    Func2_0((int)VTable_0, self->field0);
    Func3_0(self);
}
