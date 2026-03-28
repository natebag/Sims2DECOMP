extern void* operator_new_0x8022F720(unsigned int size);
extern void* ctor_0x8022F720(void* self);

void* New_0x8022F720() {
    void* mem = operator_new_0x8022F720(0x298);
    return ctor_0x8022F720(mem);
}
