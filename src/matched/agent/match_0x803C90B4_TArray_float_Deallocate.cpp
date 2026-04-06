// 0x803C90B4 TArray_L_float__TArrayERAnimAllocator_R__Deallocate_void (76b)
extern void Func1_9(int, int);
extern void Func2_9(int, int);
extern void Func3_9(void*);
extern int VTable_9[];

struct Obj_9 {
    int field0;
    int field4;
};

void Dealloc_9(Obj_9* self) {
    Func1_9(self->field0, self->field4);
    Func2_9((int)VTable_9, self->field0);
    Func3_9(self);
}
