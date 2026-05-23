// 0x80311CC8 EResourceLoaderImpl::AreLoadsPaused(void) (8 B)
struct EResourceLoaderImpl { char _pad[0x3e8]; unsigned m_field; unsigned AreLoadsPaused(); };
unsigned EResourceLoaderImpl::AreLoadsPaused() { return m_field; }
