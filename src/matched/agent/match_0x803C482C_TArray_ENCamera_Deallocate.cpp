// 0x803C482C TArray_L_ENCamera__TArrayERModelAllocator_R__Deallocate_void (76b)
extern void Func1_7(int, int);
extern void Func2_7(int, int);
extern void Func3_7(void*);
extern int VTable_7[];

struct Obj_7 {
    int field0;
    int field4;
};

void Dealloc_7(Obj_7* self) {
    Func1_7(self->field0, self->field4);
    Func2_7((int)VTable_7, self->field0);
    Func3_7(self);
}
