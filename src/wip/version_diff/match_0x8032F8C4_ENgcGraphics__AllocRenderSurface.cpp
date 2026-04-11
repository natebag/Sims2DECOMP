void* alloc_8032F8C4(unsigned long);
void* ctor_8032F8C4(void*);

void* factory_8032F8C4() {
    return ctor_8032F8C4(alloc_8032F8C4(44));
}
