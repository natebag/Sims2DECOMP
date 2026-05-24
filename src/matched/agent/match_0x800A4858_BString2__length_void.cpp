// 0x800A4858 BString2::length(void) (12 B)
// FLAGS: -fno-schedule-insns
// lwz r9,0x0(r3); lwz r3,0x4(r9); blr
struct BString2Impl { int m_ptr; int m_length; };
struct BString2 { BString2Impl* m_impl; int length() const; };
int BString2::length() const { return m_impl->m_length; }
