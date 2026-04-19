// 0x800D43FC (48B) NghResFile::FinishMemCardWrite(char *, unsigned char)

struct NghResFile {
    char pad[388];
    unsigned short m_pendingCount;
    int FinishMemCardWrite(char* a, unsigned char b);
};

extern int g_mcwState;

int NghResFile::FinishMemCardWrite(char* a, unsigned char b) {
    short count = (short)(m_pendingCount - 1);
    m_pendingCount = count;
    if (count <= 0) {
        g_mcwState = 0;
        return 1;
    }
    return 1;
}
