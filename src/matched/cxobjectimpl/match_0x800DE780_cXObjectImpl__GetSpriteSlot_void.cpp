// 0x800DE780 cXObjectImpl::GetSpriteSlot(void) (8 B)
struct cXObjectImpl { char _pad[0xb0]; unsigned m_field; unsigned GetSpriteSlot(); };
unsigned cXObjectImpl::GetSpriteSlot() { return m_field; }
