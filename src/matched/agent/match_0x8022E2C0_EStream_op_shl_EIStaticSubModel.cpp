extern void* EStream_op_shl_EIStaticSubModel_impl(void*, void*);

struct Stub_EStream_op_shl_EIStaticSubModel {
    void* call(void* a);
};
void* Stub_EStream_op_shl_EIStaticSubModel::call(void* a) {
    return EStream_op_shl_EIStaticSubModel_impl(this, a);
}
