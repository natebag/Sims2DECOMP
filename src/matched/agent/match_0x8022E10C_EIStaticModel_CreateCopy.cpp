extern void* EIStaticModel_CreateCopy_impl(void*, void*);

struct Stub_EIStaticModel_CreateCopy {
    void* call(void* a);
};
void* Stub_EIStaticModel_CreateCopy::call(void* a) {
    return EIStaticModel_CreateCopy_impl(this, a);
}
