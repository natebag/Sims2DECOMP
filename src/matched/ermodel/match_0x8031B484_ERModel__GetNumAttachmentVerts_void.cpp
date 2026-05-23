// 0x8031B484 ERModel::GetNumAttachmentVerts(void) (8 B)
struct ERModel { char _pad[0x138]; unsigned m_field; unsigned GetNumAttachmentVerts(); };
unsigned ERModel::GetNumAttachmentVerts() { return m_field; }
