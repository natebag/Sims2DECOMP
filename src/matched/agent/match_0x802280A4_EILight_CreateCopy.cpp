extern void* EILight_CreateCopy_impl(void*, void*);

struct Stub_EILight_CreateCopy {
    void* call(void* a);
};
void* Stub_EILight_CreateCopy::call(void* a) {
    return EILight_CreateCopy_impl(this, a);
}
