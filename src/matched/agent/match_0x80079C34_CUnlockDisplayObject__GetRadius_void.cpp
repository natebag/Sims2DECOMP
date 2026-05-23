// 0x80079C34 CUnlockDisplayObject::GetRadius(void) (8 B)
struct CUnlockDisplayObject { char _pad[0x28]; float m_radius; float GetRadius(); };
float CUnlockDisplayObject::GetRadius() { return m_radius; }
