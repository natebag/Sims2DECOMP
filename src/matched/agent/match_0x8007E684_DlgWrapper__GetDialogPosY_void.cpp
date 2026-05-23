// 0x8007E684 DlgWrapper::GetDialogPosY(void) (8 B)
struct DlgWrapper { char _pad[0xc0]; float m_dialogPosY; float GetDialogPosY(); };
float DlgWrapper::GetDialogPosY() { return m_dialogPosY; }
