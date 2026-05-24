// 0x800A4864 BString2::reserve(void) (12 B)
// FLAGS: -fno-schedule-insns
// lwz r9,0x0(r3); lwz r3,0x8(r9); blr
struct BString2Impl { int m_ptr; int m_length; int m_capacity; };
struct BString2 { BString2Impl* m_impl; int reserve() const; };
int BString2::reserve() const { return m_impl->m_capacity; }
