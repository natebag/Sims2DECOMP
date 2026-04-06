// 0x803C435C TArray_L_SimsLightInfo__TArrayERModelAllocator_R__Deallocate_void (76b)
extern void Func1_3(int, int);
extern void Func2_3(int, int);
extern void Func3_3(void*);
extern int VTable_3[];

struct Obj_3 {
    int field0;
    int field4;
};

void Dealloc_3(Obj_3* self) {
    Func1_3(self->field0, self->field4);
    Func2_3((int)VTable_3, self->field0);
    Func3_3(self);
}
