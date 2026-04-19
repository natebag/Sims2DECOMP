// 0x802B4274 (32B) AptValue::SetAllowDelayedDeletion(bool)
// bool-normalize pattern + rlwimi r0, r9, 26, 5, 5  (bit 5 PPC = x86 bit 26)
struct AptValueFlags {
    unsigned int _b0 : 1;
    unsigned int _b1 : 1;
    unsigned int _b2_b3 : 2;
    unsigned int _b4 : 1;
    unsigned int allowDelayedDel : 1;  // bit 5 PPC = x86 bit 26
    unsigned int _rest : 26;
};
class AptValue { public: AptValueFlags m_flags; void SetAllowDelayedDeletion(bool v); };
void AptValue::SetAllowDelayedDeletion(bool v) { m_flags.allowDelayedDel = v ? 1 : 0; }
