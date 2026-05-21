// 0x800BADAC cGZMusic::Stop(void) (80B)
// ASMPROC_swap_adj: a=li b=li which=0

class cGZSndSys {
public:
    char pad_000[1036];
    void* volatile m_tail;        // 1036
    int   volatile m_f1040;       // 1040
    int   volatile m_f1044;       // 1044
    int   m_f1048;       // 1048
};

extern cGZSndSys* g_sndSys;   // SDA -24468

class cGZMusic {
public:
    char pad_00[8];
    int  m_state;
    int Stop();
};

int cGZMusic::Stop() {
    cGZSndSys* sys = g_sndSys;
    if (sys->m_tail == this) {
        if (m_state != 0) {
            sys->m_tail = 0;
            sys->m_f1044 = 1;
            sys->m_f1040 = 1;
        }
        g_sndSys->m_f1048 = 0;
    }
    m_state = 0;
    return 1;
}
