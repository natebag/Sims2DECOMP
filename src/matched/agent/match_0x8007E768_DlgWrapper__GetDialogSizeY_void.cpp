// 0x8007E768 DlgWrapper::GetDialogSizeY(void) (8 B)
struct DlgWrapper { char _pad[0xc8]; float m_dialogSizeY; float GetDialogSizeY(); };
float DlgWrapper::GetDialogSizeY() { return m_dialogSizeY; }
