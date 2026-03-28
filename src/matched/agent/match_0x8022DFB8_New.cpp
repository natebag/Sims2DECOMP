extern void* operator_new_0x8022DFB8(unsigned int size);
extern void* ctor_0x8022DFB8(void* self);

void* New_0x8022DFB8() {
    void* mem = operator_new_0x8022DFB8(0x320);
    return ctor_0x8022DFB8(mem);
}
