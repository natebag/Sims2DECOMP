// 0x801386D4 Room::IsPool(void) (8 B)
struct Room { char _pad[0x94]; unsigned m_isPool; unsigned IsPool(); };
unsigned Room::IsPool() { return m_isPool; }
