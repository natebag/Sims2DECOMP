// 0x8031B470 ERModel::GetAttachmentColor(void) (8 B)
struct ERModel { char _pad[0x134]; unsigned char m_field; unsigned char GetAttachmentColor(); };
unsigned char ERModel::GetAttachmentColor() { return m_field; }
