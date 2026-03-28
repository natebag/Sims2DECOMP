extern void* EILight_Construct_impl(void*, void*);

struct Stub_EILight_Construct {
    void* call(void* a);
};
void* Stub_EILight_Construct::call(void* a) {
    return EILight_Construct_impl(this, a);
}
