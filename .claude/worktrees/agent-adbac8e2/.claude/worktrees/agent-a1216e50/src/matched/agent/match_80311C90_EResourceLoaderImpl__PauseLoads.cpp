/* 0x80311C90 (12 bytes) - EResourceLoaderImpl::PauseLoads(void) */
class EResourceLoaderImpl { char pad[1000]; int m_paused; public: void PauseLoads(); };
void EResourceLoaderImpl::PauseLoads() { m_paused = 1; }
