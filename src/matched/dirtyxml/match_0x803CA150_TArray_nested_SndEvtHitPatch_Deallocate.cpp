// 0x803CA150 TArray_L_TArray_L_SndEvtHitPatch__TArrayERSoundEventAllocator_R__TArrayERSoundEventAllocator_R__Deallocate_void (76b)
extern void Func1_14(int, int);
extern void Func2_14(int, int);
extern void Func3_14(void*);
extern int VTable_14[];

struct Obj_14 {
    int field0;
    int field4;
};

void Dealloc_14(Obj_14* self) {
    Func1_14(self->field0, self->field4);
    Func2_14((int)VTable_14, self->field0);
    Func3_14(self);
}
