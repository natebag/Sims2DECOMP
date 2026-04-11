void* alloc_80369E78(unsigned long);
void* ctor_80369E78(void*);

void* factory_80369E78() {
    return ctor_80369E78(alloc_80369E78(52));
}
