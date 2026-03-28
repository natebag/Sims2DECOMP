extern void* EStream_op_shl_EIPointAmbLight_impl(void*, void*);

struct Stub_EStream_op_shl_EIPointAmbLight {
    void* call(void* a);
};
void* Stub_EStream_op_shl_EIPointAmbLight::call(void* a) {
    return EStream_op_shl_EIPointAmbLight_impl(this, a);
}
