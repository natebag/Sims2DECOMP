// 0x801A07F8 CASTarget::IsShuttingdown(void) (8 B)
struct CASTarget { char _pad[0x1630]; unsigned m_field; unsigned IsShuttingdown(); };
unsigned CASTarget::IsShuttingdown() { return m_field; }
