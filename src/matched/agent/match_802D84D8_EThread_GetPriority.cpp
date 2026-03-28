struct OSThread_GP {
    int GetPriority();
};
struct EThread_GP {
    char pad[0x318];
    OSThread_GP* m_osThread;
    int GetPriority();
};
int EThread_GP::GetPriority() {
    return m_osThread->GetPriority();
}
