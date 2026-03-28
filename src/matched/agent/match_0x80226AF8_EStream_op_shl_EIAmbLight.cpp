extern void* EStream_op_shl_EIAmbLight_impl(void*, void*);

struct Stub_EStream_op_shl_EIAmbLight {
    void* call(void* a);
};
void* Stub_EStream_op_shl_EIAmbLight::call(void* a) {
    return EStream_op_shl_EIAmbLight_impl(this, a);
}
