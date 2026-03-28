extern void* EISpotLight_Construct_impl(void*, void*);

struct Stub_EISpotLight_Construct {
    void* call(void* a);
};
void* Stub_EISpotLight_Construct::call(void* a) {
    return EISpotLight_Construct_impl(this, a);
}
