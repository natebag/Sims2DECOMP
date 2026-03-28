struct OSThread_SP {
    void SetPriority(int prio);
};
struct EThread_SP {
    char pad[0x318];
    OSThread_SP* m_osThread;
    void SetPriority(int prio);
};
void EThread_SP::SetPriority(int prio) {
    m_osThread->SetPriority(prio);
}
