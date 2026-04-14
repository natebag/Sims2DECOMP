struct Inner { void* m_first; };
struct Outer { Inner* m_inner; };
extern void* GetBaseVer(void*);
void* cXMTObjectImpl_GetISimInstanceBaseVer(Outer* self) {
    return GetBaseVer(self->m_inner->m_first);
}
