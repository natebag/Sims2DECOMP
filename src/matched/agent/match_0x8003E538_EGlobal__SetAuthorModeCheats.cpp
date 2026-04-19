// FLAGS: -fno-schedule-insns
/* EGlobal::SetAuthorModeCheats(void) at 0x8003E538 (40B) */

struct EGlobal_SAMC {
    char _pad[956];  // 0x000-0x3bb
    int m_f3bc;      // 0x3bc
    int m_f3c0;      // 0x3c0
    int _p3c4;       // 0x3c4
    int m_f3c8;      // 0x3c8
    char _p3cc[16];  // 0x3cc-0x3db
    int m_f3dc;      // 0x3dc
    int _p3e0;       // 0x3e0
    int m_f3e4;      // 0x3e4
    int m_f3e8;      // 0x3e8
    int _p3ec;       // 0x3ec
    int m_f3f0;      // 0x3f0
    char _p3f4[16];  // 0x3f4-0x403
    int m_f404;      // 0x404
    void SetAuthorModeCheats();
};

void EGlobal_SAMC::SetAuthorModeCheats() {
    m_f3e4 = 1;
    m_f3bc = 1;
    m_f3c0 = 1;
    m_f3c8 = 1;
    m_f3dc = 1;
    m_f3e8 = 1;
    m_f3f0 = 1;
    m_f404 = 1;
}
