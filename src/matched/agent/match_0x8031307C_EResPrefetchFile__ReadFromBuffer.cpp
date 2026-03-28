/* EResPrefetchFile::ReadFromBuffer(void *, unsigned int) */
/* at 0x8031307C (68 bytes) */

struct EResPrefetchFile {
    char _pad_00[0x30];
    char* m_bufferPos;         /* 0x30 */
    char _pad_34[0x0C];
    unsigned int m_bytesRead;  /* 0x40 */

    unsigned int ReadFromBuffer(void* dst, unsigned int size);
};

unsigned int EResPrefetchFile::ReadFromBuffer(void* dst, unsigned int size) {
    unsigned int i;
    for (i = 0; i < size; i++) {
        char* src = m_bufferPos;
        *(char*)dst = *src;
        m_bufferPos = src + 1;
        dst = (char*)dst + 1;
        m_bytesRead = m_bytesRead + 1;
    }
    return i;
}
