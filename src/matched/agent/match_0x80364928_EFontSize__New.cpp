void* alloc_80364928(unsigned long);
void* ctor_80364928(void*);

void* factory_80364928() {
    return ctor_80364928(alloc_80364928(44));
}
