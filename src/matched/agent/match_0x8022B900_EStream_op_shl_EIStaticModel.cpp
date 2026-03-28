extern void* EStream_op_shl_EIStaticModel_impl(void*, void*);

struct Stub_EStream_op_shl_EIStaticModel {
    void* call(void* a);
};
void* Stub_EStream_op_shl_EIStaticModel::call(void* a) {
    return EStream_op_shl_EIStaticModel_impl(this, a);
}
