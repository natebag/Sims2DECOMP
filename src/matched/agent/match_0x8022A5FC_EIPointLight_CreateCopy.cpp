extern void* EIPointLight_CreateCopy_impl(void*, void*);

struct Stub_EIPointLight_CreateCopy {
    void* call(void* a);
};
void* Stub_EIPointLight_CreateCopy::call(void* a) {
    return EIPointLight_CreateCopy_impl(this, a);
}
