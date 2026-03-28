// EInstance::GetBoundSphere(EBoundSphere &)
// Address: 0x802287F4 | Size: 36 bytes
// this+0x3C is the embedded EBoundSphere, calls copy/assign with (this+0x3C, outRef)

struct EInstance_sub {
    char pad[0x3C];
    char m_boundSphere;  // 0x3C
};

extern void EBoundSphere_assign(void* a, void* b);

void EInstance_GetBoundSphere(EInstance_sub* self, void* out) {
    EBoundSphere_assign(&self->m_boundSphere, out);
}
