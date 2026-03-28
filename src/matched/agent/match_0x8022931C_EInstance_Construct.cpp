extern void* EInstance_Construct_impl(void*, void*);

struct Stub_EInstance_Construct {
    void* call(void* a);
};
void* Stub_EInstance_Construct::call(void* a) {
    return EInstance_Construct_impl(this, a);
}
