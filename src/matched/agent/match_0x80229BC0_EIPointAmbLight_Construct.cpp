extern void* EIPointAmbLight_Construct_impl(void*, void*);

struct Stub_EIPointAmbLight_Construct {
    void* call(void* a);
};
void* Stub_EIPointAmbLight_Construct::call(void* a) {
    return EIPointAmbLight_Construct_impl(this, a);
}
