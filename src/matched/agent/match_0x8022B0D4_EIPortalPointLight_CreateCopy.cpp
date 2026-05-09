// 0x8022B0D4 EIPortalPointLight::CreateCopy(void) const (32B)
// PRAGMA_STUB: EIPortalPointLight::CreateCopy(void) const
extern void* EIPortalPointLight_CreateCopy_impl(void*, void*);

struct Stub_EIPortalPointLight_CreateCopy {
    void* call(void* a);
};
void* Stub_EIPortalPointLight_CreateCopy::call(void* a) {
    return EIPortalPointLight_CreateCopy_impl(this, a);
}
