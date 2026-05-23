// 0x8012CA10 cXPersonImpl::IgnoringObject(void) (8 B)
struct cXPersonImpl { char _pad[0x53c]; unsigned m_ignoringObject; unsigned IgnoringObject(); };
unsigned cXPersonImpl::IgnoringObject() { return m_ignoringObject; }
