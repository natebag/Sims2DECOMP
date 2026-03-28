extern void* EStream_op_shl_ERLevel_impl(void*, void*);

struct Stub_EStream_op_shl_ERLevel {
    void* call(void* a);
};
void* Stub_EStream_op_shl_ERLevel::call(void* a) {
    return EStream_op_shl_ERLevel_impl(this, a);
}
