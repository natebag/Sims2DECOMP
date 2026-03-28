extern void* ERLevel_CreateCopy_impl(void*, void*);

struct Stub_ERLevel_CreateCopy {
    void* call(void* a);
};
void* Stub_ERLevel_CreateCopy::call(void* a) {
    return ERLevel_CreateCopy_impl(this, a);
}
