extern void* EIGameInstance_CreateCopy_impl(void*, void*);

struct Stub_EIGameInstance_CreateCopy {
    void* call(void* a);
};
void* Stub_EIGameInstance_CreateCopy::call(void* a) {
    return EIGameInstance_CreateCopy_impl(this, a);
}
