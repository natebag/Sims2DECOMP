// 0x8007E778 DlgWrapper::GetDialogHeight(void) (8 B)
struct DlgWrapper { char _pad[0xc8]; float m_dialogHeight; float GetDialogHeight(); };
float DlgWrapper::GetDialogHeight() { return m_dialogHeight; }
