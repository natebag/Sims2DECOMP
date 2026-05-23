// 0x80035374 ESim::GetIsChangingOutfit(void) (8 B)
struct ESim { char _pad[0x3d8]; unsigned m_isChangingOutfit; unsigned GetIsChangingOutfit(); };
unsigned ESim::GetIsChangingOutfit() { return m_isChangingOutfit; }
