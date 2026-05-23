// 0x800BA668 cGZSnd::GetVolume(void) (8 B)
struct cGZSnd { char _pad[0x20]; unsigned m_volume; unsigned GetVolume(); };
unsigned cGZSnd::GetVolume() { return m_volume; }
