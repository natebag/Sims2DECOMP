extern void* EIStaticSubModel_CreateCopy_impl(void*, void*);

struct Stub_EIStaticSubModel_CreateCopy {
    void* call(void* a);
};
void* Stub_EIStaticSubModel_CreateCopy::call(void* a) {
    return EIStaticSubModel_CreateCopy_impl(this, a);
}
