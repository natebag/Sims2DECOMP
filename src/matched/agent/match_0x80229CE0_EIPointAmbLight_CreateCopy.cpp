extern void* EIPointAmbLight_CreateCopy_impl(void*, void*);

struct Stub_EIPointAmbLight_CreateCopy {
    void* call(void* a);
};
void* Stub_EIPointAmbLight_CreateCopy::call(void* a) {
    return EIPointAmbLight_CreateCopy_impl(this, a);
}
