// 0x800A017C BString2::point(void) (12 B)
// FLAGS: -fno-schedule-insns
// lwz r9,0x0(r3); lwz r3,0x0(r9); blr
struct BString2Impl { int m_ptr; };
struct BString2 { BString2Impl* m_impl; int point() const; };
int BString2::point() const { return m_impl->m_ptr; }
