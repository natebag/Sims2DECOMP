// 0x80226FB8 EIAmbLight::CreateCopy(void) const (32B)
extern void* EIAmbLight_CreateCopy_impl(void*, void*);

struct Stub_EIAmbLight_CreateCopy {
    void* call(void* a);
};
void* Stub_EIAmbLight_CreateCopy::call(void* a) {
    return EIAmbLight_CreateCopy_impl(this, a);
}
