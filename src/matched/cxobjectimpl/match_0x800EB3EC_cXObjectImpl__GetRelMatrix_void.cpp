// 0x800EB3EC cXObjectImpl::GetRelMatrix(void) (8 B)
struct cXObjectImpl { char _pad[0x60]; unsigned m_relMatrix; unsigned GetRelMatrix(); };
unsigned cXObjectImpl::GetRelMatrix() { return m_relMatrix; }
