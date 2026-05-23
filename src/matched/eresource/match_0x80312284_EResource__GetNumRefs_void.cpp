// 0x80312284 EResource::GetNumRefs(void) (8 B)
struct EResource { char _pad[0xc]; short m_field; int GetNumRefs(); };
int EResource::GetNumRefs() { return m_field; }
