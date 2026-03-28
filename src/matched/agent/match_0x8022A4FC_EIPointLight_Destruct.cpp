// EIPointLight::Destruct(EIPointLight *)
// Address: 0x8022A4FC | Size: 36 bytes

extern void EIPointLight_dtor(void* self, int flags);

void EIPointLight_Destruct(void* self) {
    EIPointLight_dtor(self, 2);
}
