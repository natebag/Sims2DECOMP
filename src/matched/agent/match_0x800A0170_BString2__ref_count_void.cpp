// 0x800A0170 BString2::ref_count(void) (12 B)
// FLAGS: -fno-schedule-insns
// lwz r9,0x0(r3); lwz r3,0xc(r9); blr
struct BString2Impl { int m_ptr; int m_length; int m_capacity; int m_refCount; };
struct BString2 { BString2Impl* m_impl; int ref_count() const; };
int BString2::ref_count() const { return m_impl->m_refCount; }
