// 0x802E2964 EApp::GetMenuOwner(void) (8 B)
struct EApp { char _pad[0x46c]; unsigned m_field; unsigned GetMenuOwner(); };
unsigned EApp::GetMenuOwner() { return m_field; }
