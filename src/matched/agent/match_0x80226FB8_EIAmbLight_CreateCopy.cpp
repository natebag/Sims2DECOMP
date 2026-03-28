extern void* EIAmbLight_CreateCopy_impl(void*);

struct EIAmbLight {
    void* CreateCopy();
};
void* EIAmbLight::CreateCopy() {
    return EIAmbLight_CreateCopy_impl(this);
}
