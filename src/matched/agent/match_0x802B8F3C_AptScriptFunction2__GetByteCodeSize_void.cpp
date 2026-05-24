// FLAGS: -fno-schedule-insns
// 0x802B8F3C AptScriptFunction2::GetByteCodeSize(void) (12B)
// lwz r9,0x34(r3); lwz r3,0x10(r9); blr
struct AptFunctionInfo { char* m_name; int m_numArgs; char pad[8]; int m_byteCodeSize; };
struct AptScriptFunction2 { char pad[0x34]; AptFunctionInfo* m_info; int GetByteCodeSize() const; };
int AptScriptFunction2::GetByteCodeSize() const { return m_info->m_byteCodeSize; }
