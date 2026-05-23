// 0x80035330 ESim::GetSimHead(void) (8 B)
struct ESim { char _pad[0x628]; unsigned m_simHead; unsigned GetSimHead(); };
unsigned ESim::GetSimHead() { return m_simHead; }
