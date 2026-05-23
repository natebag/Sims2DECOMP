// 0x8031B440 ERModel::IsLattice(void) (8 B)
struct ERModel { char _pad[0x34]; unsigned m_field; unsigned IsLattice(); };
unsigned ERModel::IsLattice() { return m_field; }
