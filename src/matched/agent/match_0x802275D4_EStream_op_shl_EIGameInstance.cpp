extern void* EStream_op_shl_EIGameInstance_impl(void*, void*);

struct Stub_EStream_op_shl_EIGameInstance {
    void* call(void* a);
};
void* Stub_EStream_op_shl_EIGameInstance::call(void* a) {
    return EStream_op_shl_EIGameInstance_impl(this, a);
}
