struct Inner_MS {
    void ManagedShutdown();
};
struct EFS_MS {
    char pad[0x04];
    Inner_MS m_inner;
    void ManagedShutdown();
};
void EFS_MS::ManagedShutdown() {
    m_inner.ManagedShutdown();
}
