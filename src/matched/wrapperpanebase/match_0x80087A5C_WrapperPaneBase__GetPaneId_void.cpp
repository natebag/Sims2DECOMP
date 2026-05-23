// 0x80087A5C WrapperPaneBase::GetPaneId(void) (8 B)
struct WrapperPaneBase { unsigned m_paneId; unsigned GetPaneId(); };
unsigned WrapperPaneBase::GetPaneId() { return m_paneId; }
