// NghResFile::PrepareMemCardWrite(char*, unsigned char) - 0x800D43DC (32B)
// Increments halfword counter at +0x184, returns 1 (cmpwi to 1 is leftover dead-compare).

class NghResFile {
public:
    char _pad[0x184];
    unsigned short m_counter;
    int PrepareMemCardWrite(char* a, unsigned char b);
};

int NghResFile::PrepareMemCardWrite(char* a, unsigned char b)
{
    int n = m_counter;
    int result = 1;
    int next = n + 1;
    short ext = (short)next;
    m_counter = (unsigned short)next;
    if (ext == 1) return result;
    return result;
}
