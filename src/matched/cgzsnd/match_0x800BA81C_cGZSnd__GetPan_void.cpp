// 0x800BA81C cGZSnd::GetPan(void) (8 B)
struct cGZSnd { char _pad[0x24]; unsigned m_pan; unsigned GetPan(); };
unsigned cGZSnd::GetPan() { return m_pan; }
