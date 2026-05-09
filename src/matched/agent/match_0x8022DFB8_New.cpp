// 0x8022DFB8 EIStaticModel::New(void) (40 B)
// PRAGMA_STUB: EIStaticModel::New(void)
extern void* operator_new_0x8022DFB8(unsigned int size);
extern void* ctor_0x8022DFB8(void* self);

void* New_0x8022DFB8() {
    void* mem = operator_new_0x8022DFB8(0x320);
    return ctor_0x8022DFB8(mem);
}
