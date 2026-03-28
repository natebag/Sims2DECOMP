extern void* operator_new_0x8022AF8C(unsigned int size);
extern void* ctor_0x8022AF8C(void* self);

void* New_0x8022AF8C() {
    void* mem = operator_new_0x8022AF8C(0xD8);
    return ctor_0x8022AF8C(mem);
}
