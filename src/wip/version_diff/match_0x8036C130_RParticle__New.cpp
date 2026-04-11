void* alloc_8036C130(unsigned long);
void* ctor_8036C130(void*);

void* factory_8036C130() {
    return ctor_8036C130(alloc_8036C130(60));
}
