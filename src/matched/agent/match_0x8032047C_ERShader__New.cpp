void* alloc_8032047C(unsigned long);
void* ctor_8032047C(void*);

void* factory_8032047C() {
    return ctor_8032047C(alloc_8032047C(108));
}
