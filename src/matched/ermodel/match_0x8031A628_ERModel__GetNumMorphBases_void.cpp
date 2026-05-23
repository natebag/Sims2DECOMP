// 0x8031A628 ERModel::GetNumMorphBases(void) (8 B)
struct ERModel { char _pad[0x108]; unsigned m_field; unsigned GetNumMorphBases(); };
unsigned ERModel::GetNumMorphBases() { return m_field; }
