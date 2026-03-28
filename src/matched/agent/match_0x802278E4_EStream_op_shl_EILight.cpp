extern void* EStream_op_shl_EILight_impl(void*, void*);

struct Stub_EStream_op_shl_EILight {
    void* call(void* a);
};
void* Stub_EStream_op_shl_EILight::call(void* a) {
    return EStream_op_shl_EILight_impl(this, a);
}
