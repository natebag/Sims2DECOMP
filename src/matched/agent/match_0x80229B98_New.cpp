extern void* operator_new_0x80229B98(unsigned int size);
extern void* ctor_0x80229B98(void* self);

void* New_0x80229B98() {
    void* mem = operator_new_0x80229B98(0xC4);
    return ctor_0x80229B98(mem);
}
