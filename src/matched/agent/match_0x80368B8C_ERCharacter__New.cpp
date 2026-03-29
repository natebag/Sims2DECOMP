void* alloc_80368B8C(unsigned long);
void* ctor_80368B8C(void*);

void* factory_80368B8C() {
    return ctor_80368B8C(alloc_80368B8C(52));
}
