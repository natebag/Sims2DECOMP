// 0x8004079C EGlobal::GetSelectedPerson(int) (16 B)
// FLAGS: -fno-schedule-insns
struct EGlobal { char _pad[0xBC]; unsigned m_selectedPerson[4]; unsigned GetSelectedPerson(int); };
unsigned EGlobal::GetSelectedPerson(int index) { return m_selectedPerson[index]; }
