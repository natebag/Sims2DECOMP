extern void* operator_new_0x80227F5C(unsigned int size);
extern void* ctor_0x80227F5C(void* self);

void* New_0x80227F5C() {
    void* mem = operator_new_0x80227F5C(0xAC);
    return ctor_0x80227F5C(mem);
}
