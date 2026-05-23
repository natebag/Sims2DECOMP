// 0x800EB0BC cXObjectImpl::GetRect(void) (8 B)
struct cXObjectImpl { char _pad[112]; unsigned m_arr[1]; unsigned* GetRect(); };
unsigned* cXObjectImpl::GetRect() { return m_arr; }
