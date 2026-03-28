extern void* EStream_op_shl_EISpotLight_impl(void*, void*);

struct Stub_EStream_op_shl_EISpotLight {
    void* call(void* a);
};
void* Stub_EStream_op_shl_EISpotLight::call(void* a) {
    return EStream_op_shl_EISpotLight_impl(this, a);
}
