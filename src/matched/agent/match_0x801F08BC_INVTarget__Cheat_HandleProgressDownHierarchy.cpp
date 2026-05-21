// 0x801F08BC INVTarget::Cheat_HandleProgressDownHierarchy(char *) (72B)

extern char g_progress_block[16];

class INVTarget {
public:
    char _pad0[312];
    unsigned char m_field312;
    char _pad313[393 - 313];
    unsigned char m_field393;

    void Cheat_HandleProgressDownHierarchy(char* arg);
};

void INVTarget::Cheat_HandleProgressDownHierarchy(char* arg) {
    int state = m_field312;
    if (state == 1) goto path_1;
    if (state > 1) return;
    if (state != 0) return;
    *(short*)arg = *(short*)g_progress_block;
    m_field393 = 0;
    m_field312 = m_field312 + 1;
    return;
path_1:
    *(short*)arg = *(short*)(g_progress_block + 4);
    m_field312 = m_field312 + 1;
}
