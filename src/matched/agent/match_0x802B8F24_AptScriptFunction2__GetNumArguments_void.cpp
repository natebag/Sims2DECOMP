// FLAGS: -fno-schedule-insns
// 0x802B8F24 AptScriptFunction2::GetNumArguments(void) (12B)
// lwz r9,0x34(r3); lwz r3,0x4(r9); blr
struct AptFunctionInfo { char* m_name; int m_numArgs; };
struct AptScriptFunction2 { char pad[0x34]; AptFunctionInfo* m_info; int GetNumArguments() const; };
int AptScriptFunction2::GetNumArguments() const { return m_info->m_numArgs; }
