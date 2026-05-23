// 0x8007E770 DlgWrapper::GetDialogWidth(void) (8 B)
struct DlgWrapper { char _pad[0xc4]; float m_dialogWidth; float GetDialogWidth(); };
float DlgWrapper::GetDialogWidth() { return m_dialogWidth; }
