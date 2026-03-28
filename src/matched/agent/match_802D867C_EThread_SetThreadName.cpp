struct EThread_STN {
    char pad[0x32C];
    char* m_threadName;
    void SetThreadName(char* name);
};
void EThread_STN::SetThreadName(char* name) {
    m_threadName = name;
}
