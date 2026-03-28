extern void* EIGameInstance_Construct_impl(void*, void*);

struct Stub_EIGameInstance_Construct {
    void* call(void* a);
};
void* Stub_EIGameInstance_Construct::call(void* a) {
    return EIGameInstance_Construct_impl(this, a);
}
