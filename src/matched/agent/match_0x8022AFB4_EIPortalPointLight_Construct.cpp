extern void* EIPortalPointLight_Construct_impl(void*, void*);

struct Stub_EIPortalPointLight_Construct {
    void* call(void* a);
};
void* Stub_EIPortalPointLight_Construct::call(void* a) {
    return EIPortalPointLight_Construct_impl(this, a);
}
