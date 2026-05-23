// 0x8007E760 DlgWrapper::GetDialogSizeX(void) (8 B)
struct DlgWrapper { char _pad[0xc4]; float m_dialogSizeX; float GetDialogSizeX(); };
float DlgWrapper::GetDialogSizeX() { return m_dialogSizeX; }
