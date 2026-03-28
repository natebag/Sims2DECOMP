extern void* operator_new_0x802292F4(unsigned int size);
extern void* ctor_0x802292F4(void* self);

void* New_0x802292F4() {
    void* mem = operator_new_0x802292F4(0x7C);
    return ctor_0x802292F4(mem);
}
