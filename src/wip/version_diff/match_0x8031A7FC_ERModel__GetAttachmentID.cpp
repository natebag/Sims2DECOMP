// VERSION_DIFF: leaf function loop — register init ordering and count reload pattern differs
/* ERModel::GetAttachmentID(unsigned char, signed char &) at 0x8031A7FC (80B) */

struct ERModelGAI {
    char pad[0x138];
    int m_numAttachments;
    char *m_attachments;

    int GetAttachmentID(unsigned char id, signed char *outIdx);
};

int ERModelGAI::GetAttachmentID(unsigned char id, signed char *outIdx) {
    int count = m_numAttachments;
    int offset = 0;
    for (int i = 0; i < count; i++) {
        char *entry = m_attachments + offset;
        if (*(unsigned char *)(entry + 7) == id) {
            *outIdx = (signed char)i;
            return 1;
        }
        offset += 64;
    }
    return 0;
}
