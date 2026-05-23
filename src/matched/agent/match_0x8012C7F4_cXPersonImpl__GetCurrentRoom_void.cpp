// 0x8012C7F4 cXPersonImpl::GetCurrentRoom(void) (8 B)
struct cXPersonImpl { char _pad[0x41c]; unsigned short m_currentRoom; unsigned GetCurrentRoom(); };
unsigned cXPersonImpl::GetCurrentRoom() { return m_currentRoom; }
