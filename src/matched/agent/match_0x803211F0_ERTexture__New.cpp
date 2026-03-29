void* alloc_803211F0(unsigned long);
void* ctor_803211F0(void*);

void* factory_803211F0() {
    return ctor_803211F0(alloc_803211F0(24));
}
