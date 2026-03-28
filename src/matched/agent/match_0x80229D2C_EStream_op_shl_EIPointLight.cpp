extern void* EStream_op_shl_EIPointLight_impl(void*, void*);

struct Stub_EStream_op_shl_EIPointLight {
    void* call(void* a);
};
void* Stub_EStream_op_shl_EIPointLight::call(void* a) {
    return EStream_op_shl_EIPointLight_impl(this, a);
}
