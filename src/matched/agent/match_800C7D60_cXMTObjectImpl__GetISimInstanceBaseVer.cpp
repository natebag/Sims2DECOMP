// 0x800C7D60 cXMTObjectImpl::GetISimInstanceBaseVer(void) (40 B)
// PRAGMA_STUB: cXMTObjectImpl::GetISimInstanceBaseVer(void)
struct Inner { void* m_first; };
struct Outer { Inner* m_inner; };
extern void* GetBaseVer(void*);
void* cXMTObjectImpl_GetISimInstanceBaseVer(Outer* self) {
    return GetBaseVer(self->m_inner->m_first);
}
