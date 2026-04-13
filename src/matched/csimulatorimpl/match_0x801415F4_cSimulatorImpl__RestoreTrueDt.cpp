// FLAGS: -fno-elide-constructors
// 0x801415F4 cSimulatorImpl::RestoreTrueDt (24B)

extern char g_defaultDt[];
extern float g_savedDt;

struct cSimulatorImpl {
    char pad[0xA4];
    float m_trueDt;

    void RestoreTrueDt();
};

void cSimulatorImpl::RestoreTrueDt() {
    float old = m_trueDt;
    float def = *(float*)g_defaultDt;
    g_savedDt = old;
    m_trueDt = def;
}
