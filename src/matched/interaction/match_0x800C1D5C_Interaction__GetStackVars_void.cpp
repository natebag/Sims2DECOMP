// 0x800C1D5C Interaction::GetStackVars(void) (8 B)
struct Interaction { char _pad[24]; unsigned m_arr[1]; unsigned* GetStackVars(); };
unsigned* Interaction::GetStackVars() { return m_arr; }
