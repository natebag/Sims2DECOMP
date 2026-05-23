// 0x8012C988 cXPersonImpl::GetMotiveEffects(void) (8 B)
struct cXPersonImpl { char _pad[0x408]; unsigned m_motiveEffects; unsigned GetMotiveEffects(); };
unsigned cXPersonImpl::GetMotiveEffects() { return m_motiveEffects; }
