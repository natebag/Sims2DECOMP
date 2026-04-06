// 0x803C45C4 TArray_L_ENLattice__TArrayERModelAllocator_R__Deallocate_void (76b)
extern void Func1_5(int, int);
extern void Func2_5(int, int);
extern void Func3_5(void*);
extern int VTable_5[];

struct Obj_5 {
    int field0;
    int field4;
};

void Dealloc_5(Obj_5* self) {
    Func1_5(self->field0, self->field4);
    Func2_5((int)VTable_5, self->field0);
    Func3_5(self);
}
