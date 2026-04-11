/* 0x803125C0 (20 bytes) - EResPrefetch::AcquireBuffer(void *, unsigned int) */
class EResPrefetch {
    char pad[1028];
    int m_status;
    void *m_buf;
    unsigned int m_size;
public:
    void AcquireBuffer(void *buf, unsigned int sz);
};
void EResPrefetch::AcquireBuffer(void *buf, unsigned int sz) {
    m_status = 0;
    m_buf = buf;
    m_size = (unsigned int)buf;
}
