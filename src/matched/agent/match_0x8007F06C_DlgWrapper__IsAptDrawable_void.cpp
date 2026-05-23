// 0x8007F06C DlgWrapper::IsAptDrawable(void) (8 B)
struct DlgWrapper { char _pad[0xb4]; unsigned m_isAptDrawable; unsigned IsAptDrawable(); };
unsigned DlgWrapper::IsAptDrawable() { return m_isAptDrawable; }
