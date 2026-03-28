// 0x80311C90 (12 bytes) - EResourceLoaderImpl::PauseLoads(void)
// li r0, 1; stw r0, 1000(r3); blr

class EResourceLoaderImpl {
    char pad[1000]; // 0x000-0x3E7
    int m_paused; // 0x3E8
public:
    void PauseLoads();
};

void EResourceLoaderImpl::PauseLoads() {
    m_paused = 1;
}
