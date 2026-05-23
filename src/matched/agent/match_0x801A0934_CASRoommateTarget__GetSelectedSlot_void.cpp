// 0x801A0934 CASRoommateTarget::GetSelectedSlot(void) (8 B)
struct CASRoommateTarget { char _pad[0x90]; unsigned m_field; unsigned GetSelectedSlot(); };
unsigned CASRoommateTarget::GetSelectedSlot() { return m_field; }
