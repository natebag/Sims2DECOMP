struct ERModel {
    char _pad[0x134];
    unsigned char m_attachmentColor;
    unsigned char GetAttachmentColor();
};
unsigned char ERModel::GetAttachmentColor() { return m_attachmentColor; }
