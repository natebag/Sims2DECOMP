// EInstance::Destruct(EInstance *)
// Address: 0x8022933C | Size: 36 bytes

extern void EInstance_dtor(void* self, int flags);

void EInstance_Destruct(void* self) {
    EInstance_dtor(self, 2);
}
