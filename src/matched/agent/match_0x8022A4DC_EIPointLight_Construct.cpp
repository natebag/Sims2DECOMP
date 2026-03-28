extern void* EIPointLight_Construct_impl(void*, void*);

struct Stub_EIPointLight_Construct {
    void* call(void* a);
};
void* Stub_EIPointLight_Construct::call(void* a) {
    return EIPointLight_Construct_impl(this, a);
}
