void* alloc_8032F92C(unsigned long);
void* ctor_8032F92C(void*);

void* factory_8032F92C() {
    return ctor_8032F92C(alloc_8032F92C(92));
}
