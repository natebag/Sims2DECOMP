// 0x800D43FC (48B) NghResFile::FinishMemCardWrite(char *, unsigned char)
// Decrement counter; if non-positive, clear SDA state; return 1.

extern int g_ngcSaveState;

class NghResFile {
public:
    char pad[388];
    short m_counter;
    int FinishMemCardWrite(char* path, unsigned char flag);
};

int NghResFile::FinishMemCardWrite(char*, unsigned char) {
    --m_counter;
    if (m_counter > 0) return 1;
    g_ngcSaveState = 0;
    return 1;
}
