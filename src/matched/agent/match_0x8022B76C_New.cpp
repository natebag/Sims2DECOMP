extern void* operator_new_0x8022B76C(unsigned int size);
extern void* ctor_0x8022B76C(void* self);

void* New_0x8022B76C() {
    void* mem = operator_new_0x8022B76C(0xE0);
    return ctor_0x8022B76C(mem);
}
