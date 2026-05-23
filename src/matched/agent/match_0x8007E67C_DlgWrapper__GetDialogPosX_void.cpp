// 0x8007E67C DlgWrapper::GetDialogPosX(void) (8 B)
struct DlgWrapper { char _pad[0xbc]; float m_dialogPosX; float GetDialogPosX(); };
float DlgWrapper::GetDialogPosX() { return m_dialogPosX; }
