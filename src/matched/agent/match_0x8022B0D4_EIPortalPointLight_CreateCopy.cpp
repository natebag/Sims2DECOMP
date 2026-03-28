extern void* EIPortalPointLight_CreateCopy_impl(void*, void*);

struct Stub_EIPortalPointLight_CreateCopy {
    void* call(void* a);
};
void* Stub_EIPortalPointLight_CreateCopy::call(void* a) {
    return EIPortalPointLight_CreateCopy_impl(this, a);
}
