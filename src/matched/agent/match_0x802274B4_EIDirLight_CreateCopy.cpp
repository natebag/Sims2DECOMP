extern void* EIDirLight_CreateCopy_impl(void*, void*);

struct Stub_EIDirLight_CreateCopy {
    void* call(void* a);
};
void* Stub_EIDirLight_CreateCopy::call(void* a) {
    return EIDirLight_CreateCopy_impl(this, a);
}
