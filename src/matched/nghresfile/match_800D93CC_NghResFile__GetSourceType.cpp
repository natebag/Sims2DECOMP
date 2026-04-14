/* NghResFile::GetSourceType(void) const - 0x800D93CC (8 bytes) */

struct NghResFile {
    char m_pad[0x20];
    int m_sourceType;

    int GetSourceType(void) const;
};

int NghResFile::GetSourceType(void) const {
    return m_sourceType;
}
