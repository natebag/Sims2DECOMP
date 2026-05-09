// 0x80041A4C EGlobal::RecalcObjects(void) (48 B)
// PRAGMA_STUB: EGlobal::RecalcObjects(void)
struct Inner { char pad[4]; void* m_world; };
struct EGlobal { char pad[0xC8]; Inner* m_inner; };
extern "C" void recalcWorld(void*);
void EGlobal_RecalcObjects(EGlobal* self) {
    if (self->m_inner) {
        recalcWorld(self->m_inner->m_world);
    }
}
