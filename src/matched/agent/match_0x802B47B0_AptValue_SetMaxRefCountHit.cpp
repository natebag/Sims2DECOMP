// 0x802B47B0 (32B) AptValue::SetMaxRefCountHit(bool)
// bool-normalize pattern + rlwimi r0, r9, 7, 24, 24  (bit 24 PPC = x86 bit 7)
struct AptValueFlags { unsigned int _b0_b23 : 24; unsigned int maxRefCountHit : 1; unsigned int _rest : 7; };
class AptValue { public: AptValueFlags m_flags; void SetMaxRefCountHit(bool v); };
void AptValue::SetMaxRefCountHit(bool v) { m_flags.maxRefCountHit = v ? 1 : 0; }
