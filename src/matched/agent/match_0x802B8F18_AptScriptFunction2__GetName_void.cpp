// FLAGS: -fno-schedule-insns
// 0x802B8F18 AptScriptFunction2::GetName(void) (12B)
// lwz r9,0x34(r3); lwz r3,0x0(r9); blr
struct AptFunctionInfo { char* m_name; };
struct AptScriptFunction2 { char pad[0x34]; AptFunctionInfo* m_info; const char* GetName() const; };
const char* AptScriptFunction2::GetName() const { return m_info->m_name; }
