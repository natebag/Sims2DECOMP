struct OSThread_S {
    void Start();
};
struct EThread_S {
    char pad[0x318];
    OSThread_S* m_osThread;
    void Start();
};
void EThread_S::Start() {
    m_osThread->Start();
}
