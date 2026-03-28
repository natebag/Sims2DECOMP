extern void* EISpotLight_CreateCopy_impl(void*, void*);

struct Stub_EISpotLight_CreateCopy {
    void* call(void* a);
};
void* Stub_EISpotLight_CreateCopy::call(void* a) {
    return EISpotLight_CreateCopy_impl(this, a);
}
