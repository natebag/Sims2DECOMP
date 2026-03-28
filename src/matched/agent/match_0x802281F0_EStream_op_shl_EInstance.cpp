extern void* EStream_op_shl_EInstance_impl(void*, void*);

struct Stub_EStream_op_shl_EInstance {
    void* call(void* a);
};
void* Stub_EStream_op_shl_EInstance::call(void* a) {
    return EStream_op_shl_EInstance_impl(this, a);
}
