// 0x802B4D3C EAStringC::c_str(void) (12 B)
// FLAGS: -fno-schedule-insns
// lwz r3,0x0(r3); addi r3,r3,8; blr
struct EAStringCImpl { char _pad[8]; char m_data; };
struct EAStringC { EAStringCImpl* m_impl; char* c_str() const; };
char* EAStringC::c_str() const { return (char*)m_impl + 8; }
