extern void* operator_new_0x8022736C(unsigned int size);
extern void* ctor_0x8022736C(void* self);

void* New_0x8022736C() {
    void* mem = operator_new_0x8022736C(0xB8);
    return ctor_0x8022736C(mem);
}
