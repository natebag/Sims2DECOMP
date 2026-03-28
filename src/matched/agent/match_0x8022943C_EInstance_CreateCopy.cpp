extern void* EInstance_CreateCopy_impl(void*, void*);

struct Stub_EInstance_CreateCopy {
    void* call(void* a);
};
void* Stub_EInstance_CreateCopy::call(void* a) {
    return EInstance_CreateCopy_impl(this, a);
}
