extern void* operator_new_0x8022A4B4(unsigned int size);
extern void* ctor_0x8022A4B4(void* self);

void* New_0x8022A4B4() {
    void* mem = operator_new_0x8022A4B4(0xD0);
    return ctor_0x8022A4B4(mem);
}
