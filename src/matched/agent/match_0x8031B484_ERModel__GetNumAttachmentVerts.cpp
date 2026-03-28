struct ERModel {
    char _pad[0x138];
    int m_numAttachmentVerts;
    int GetNumAttachmentVerts();
};
int ERModel::GetNumAttachmentVerts() { return m_numAttachmentVerts; }
