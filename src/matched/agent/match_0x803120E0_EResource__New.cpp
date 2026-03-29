void* alloc_803120E0(unsigned long);
void* ctor_803120E0(void*);

void* factory_803120E0() {
    return ctor_803120E0(alloc_803120E0(20));
}
