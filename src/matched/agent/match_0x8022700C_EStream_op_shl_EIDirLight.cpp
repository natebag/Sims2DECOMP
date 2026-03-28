extern void* EStream_op_shl_EIDirLight_impl(void*, void*);

struct Stub_EStream_op_shl_EIDirLight {
    void* call(void* a);
};
void* Stub_EStream_op_shl_EIDirLight::call(void* a) {
    return EStream_op_shl_EIDirLight_impl(this, a);
}
