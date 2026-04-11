void* alloc_80364A90(unsigned long);
void* ctor_80364A90(void*);

void* factory_80364A90() {
    return ctor_80364A90(alloc_80364A90(56));
}
