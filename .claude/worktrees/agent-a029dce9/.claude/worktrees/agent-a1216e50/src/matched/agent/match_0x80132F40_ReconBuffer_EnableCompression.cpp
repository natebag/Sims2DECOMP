/* ReconBuffer::EnableCompression(void) - 0x80132F40 - 12 bytes */
/* li r0, 1; stw r0, 0x18(r3); blr */

class ReconBuffer {
public:
    char _pad[0x18];
    int m_compressionEnabled;

    void EnableCompression(void);
};

void ReconBuffer::EnableCompression(void) {
    m_compressionEnabled = 1;
}
