extern void* operator_new(unsigned int size);
extern void* EIGameInstance_ctor(void* self);

void* EIGameInstance_New() {
    void* mem = operator_new(0x7C);
    return EIGameInstance_ctor(mem);
}
