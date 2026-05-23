// 0x80086840 Wrapper::WrapperStartup(UIObjectBase (8 B)
struct Wrapper { char _pad[0x88]; unsigned m_uiObject; void WrapperStartup(unsigned); };
void Wrapper::WrapperStartup(unsigned obj) { m_uiObject = obj; }
