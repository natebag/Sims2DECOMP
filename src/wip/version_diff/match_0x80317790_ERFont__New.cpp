void* alloc_80317790(unsigned long);
void* ctor_80317790(void*);

void* factory_80317790() {
    return ctor_80317790(alloc_80317790(108));
}
