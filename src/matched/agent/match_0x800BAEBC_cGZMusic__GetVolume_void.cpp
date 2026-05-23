// 0x800BAEBC cGZMusic::GetVolume(void) (8 B)
struct cGZMusic { char _pad[0x14]; unsigned m_volume; unsigned GetVolume(); };
unsigned cGZMusic::GetVolume() { return m_volume; }
