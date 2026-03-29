void* alloc_80367FD4(unsigned long);
void* ctor_80367FD4(void*);

void* factory_80367FD4() {
    return ctor_80367FD4(alloc_80367FD4(160));
}
