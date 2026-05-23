// 0x80035338 ESim::GetSimModel(void) (8 B)
struct ESim { char _pad[0x63c]; unsigned m_simModel; unsigned GetSimModel(); };
unsigned ESim::GetSimModel() { return m_simModel; }
