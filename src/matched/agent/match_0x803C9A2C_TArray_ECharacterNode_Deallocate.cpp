// 0x803C9A2C TArray_L_ECharacterNode__TArrayERCharacterAllocator_R__Deallocate_void (76b)
extern void Func1_12(int, int);
extern void Func2_12(int, int);
extern void Func3_12(void*);
extern int VTable_12[];

struct Obj_12 {
    int field0;
    int field4;
};

void Dealloc_12(Obj_12* self) {
    Func1_12(self->field0, self->field4);
    Func2_12((int)VTable_12, self->field0);
    Func3_12(self);
}
