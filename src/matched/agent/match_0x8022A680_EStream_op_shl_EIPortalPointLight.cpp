extern void* EStream_op_shl_EIPortalPointLight_impl(void*, void*);

struct Stub_EStream_op_shl_EIPortalPointLight {
    void* call(void* a);
};
void* Stub_EStream_op_shl_EIPortalPointLight::call(void* a) {
    return EStream_op_shl_EIPortalPointLight_impl(this, a);
}
