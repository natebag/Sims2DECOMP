/* SeqResFile::ClearOpenSpecs(void) - 0x8013DA08 - 12 bytes */
/* li r0, 0; stw r0, 0xD0(r3); blr */

class SeqResFile {
public:
    char _pad[0xD0];
    int m_openSpecs;

    void ClearOpenSpecs(void);
};

void SeqResFile::ClearOpenSpecs(void) {
    m_openSpecs = 0;
}
