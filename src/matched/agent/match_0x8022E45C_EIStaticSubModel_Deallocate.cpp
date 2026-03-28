extern void* EIStaticSubModel_Deallocate_impl(void*, void*);

struct Stub_EIStaticSubModel_Deallocate {
    void* call(void* a);
};
void* Stub_EIStaticSubModel_Deallocate::call(void* a) {
    return EIStaticSubModel_Deallocate_impl(this, a);
}
