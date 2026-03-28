struct EThread_GTN {
    char pad[0x32C];
    char* m_threadName;
    char* GetThreadName();
};
char* EThread_GTN::GetThreadName() {
    return m_threadName;
}
