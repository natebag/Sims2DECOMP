// EIPointAmbLight::Destruct(EIPointAmbLight *)
// Address: 0x80229BE0 | Size: 36 bytes

extern void EIPointAmbLight_dtor(void* self, int flags);

void EIPointAmbLight_Destruct(void* self) {
    EIPointAmbLight_dtor(self, 2);
}
