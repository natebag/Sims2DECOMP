void* alloc_80313C64(unsigned long);
void* ctor_80313C64(void*);

void* factory_80313C64() {
    return ctor_80313C64(alloc_80313C64(24));
}
