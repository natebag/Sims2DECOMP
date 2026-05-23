// 0x8005634C ISimInstance::SetXOb(cXObject (8 B)
struct ISimInstance { char _pad[0x328]; unsigned m_xob; void SetXOb(unsigned); };
void ISimInstance::SetXOb(unsigned xob) { m_xob = xob; }
