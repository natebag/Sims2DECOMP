/* 0x8031B478 (12 bytes) - ERModel::ClearAttachmentID(void) */
class ERModel { char pad[309]; signed char m_attachmentID; public: void ClearAttachmentID(); };
void ERModel::ClearAttachmentID() { m_attachmentID = -1; }
