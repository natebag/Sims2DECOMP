// 0x803CA074 TArray_L_SndEvtHitPatch__TArrayERSoundEventAllocator_R__Deallocate_void (76b)
extern void Func1_13(int, int);
extern void Func2_13(int, int);
extern void Func3_13(void*);
extern int VTable_13[];

struct Obj_13 {
    int field0;
    int field4;
};

void Dealloc_13(Obj_13* self) {
    Func1_13(self->field0, self->field4);
    Func2_13((int)VTable_13, self->field0);
    Func3_13(self);
}
