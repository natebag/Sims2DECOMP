// EILight::Destruct(EILight *)
// Address: 0x80227FA4 | Size: 36 bytes

extern void EILight_dtor(void* self, int flags);

void EILight_Destruct(void* self) {
    EILight_dtor(self, 2);
}
