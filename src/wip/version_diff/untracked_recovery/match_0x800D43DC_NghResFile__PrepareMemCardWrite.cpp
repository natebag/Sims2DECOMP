// 0x800D43DC NghResFile::PrepareMemCardWrite(char *, unsigned char) (32B)

struct NghResFile {
    char pad[0x184];
    unsigned short m_field;
    int PrepareMemCardWrite(char* buf, unsigned char flags);
};

int NghResFile::PrepareMemCardWrite(char* buf, unsigned char flags) {
    short val = (short)m_field;
    m_field = val + 1;
    return 1;
}
