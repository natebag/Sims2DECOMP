// EIGameInstance::Destruct(EIGameInstance *)
// Address: 0x80227798 | Size: 36 bytes

extern void EIGameInstance_dtor(void* self, int flags);

void EIGameInstance_Destruct(void* self) {
    EIGameInstance_dtor(self, 2);
}
